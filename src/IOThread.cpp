//
// Created by inonk on 12/01/2020.
//

#include "../include/IOThread.h"

using namespace std;

IOThread::IOThread(ConnectionHandler* ch, BookClub* bookClub): ch(ch), bookClub(bookClub){

}

void IOThread::run() {
	int subscriptionIndexer = 0;
	int receiptIndexer = 0;
	while (!bookClub->isShouldTerminate()) {

		string line;
		cin >> line;
		while (line != "bye" & bookClub->isShouldTerminate()) {
			std::cout << "please type 'bye':" << std::endl;
			getline(std::cin, line);
			std::cin >> line;
		}
		if (line == "bye")
			break;
		Frame message;
		if (line == "login") {
			message.setCommand("CONNECT");
			message.addHeader("accept-version", "1.2");
			std::cin >> line;
			message.addHeader("host", "stomp.cs.bgu.ac.il");
			std::cin >> line;
			message.addHeader("login", line);
			bookClub->setUsername(line);
			std::cin >> line;
			message.addHeader("passcode", line);
		}
		else if (line == "join") {
			message.setCommand("SUBSCRIBE");
			cin >> line;
			message.addHeader("destination", line);
			message.addHeader("id", std::to_string(subscriptionIndexer) + "");
			if(bookClub->addSubscription(line, subscriptionIndexer)) {
				subscriptionIndexer++;
				message.addHeader("receipt", std::to_string(receiptIndexer));
				bookClub->addReceiptIdToMessage(receiptIndexer, "SUBSCRIBE " + line);//new receipt
				receiptIndexer++;
			}
		}
		else if (line == "exit") {
			message.setCommand("UNSUBSCRIBE");
			cin >> line;
			int subscriptionID = bookClub->getIDByTopic(line);
			if(bookClub->removeSubscription(line)) {
				message.addHeader("destination", line);
				message.addHeader("id", std::to_string(subscriptionID));
				message.addHeader("receipt", std::to_string(receiptIndexer));
				bookClub->addReceiptIdToMessage(receiptIndexer, "UNSUBSCRIBE " + line);//new receipt
				receiptIndexer++;
			}

		}
		else if (line == "add") {
			message.setCommand("SEND");
			cin >> line;
			message.addHeader("destination", line);
			string topic=line;
			getline(cin, line);
			message.setBody(bookClub->getUsername()+ " has added the book " + line.substr(1));
			bookClub->addBook(line.substr(1),bookClub->getUsername());
			bookClub->addBookToTopic(line.substr(1),topic);
		}
		else if (line == "borrow") {
			message.setCommand("SEND");
			cin >> line;
			message.addHeader("destination", line);
			getline(cin, line);
			message.setBody(bookClub->getUsername() + " wish to borrow " + line.substr(1));
			bookClub->addToRequestedBooks(line.substr(1));
		}
		else if (line == "return") {
			message.setCommand("SEND");
			cin >> line;
			message.addHeader("destination", line);
			string topic=line;
			getline(cin, line);
			if (bookClub->canSendBook(line.substr(1))) {
				message.setBody("Returning " + line.substr(1) + " to " +bookClub->getOwnerByBook(line.substr(1)));
				bookClub->removeBook(line.substr(1));
				bookClub->removeBookFromTopic(line.substr(1),topic);
			} else
				continue;
		}

		else if (line == "status") {
			message.setCommand("SEND");
			cin >> line;
			message.addHeader("destination", line);
			message.setBody("book status");
		}

		else if(line=="logout"){
			message.setCommand("DISCONNECT");
			message.addHeader("receipt", std::to_string(receiptIndexer));
            bookClub->addReceiptIdToMessage(receiptIndexer,"DISCONNECT");//new receipt
			receiptIndexer++;
		}
		if (!ch->sendLine(message)) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}

		if(line=="logout")
			break;
	}
}
