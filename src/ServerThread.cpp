//
// Created by inonk on 13/01/2020.
//

#include "../include/ServerThread.h"


ServerThread::ServerThread(ConnectionHandler *ch, BookClub* bookClub): ch(ch), bookClub(bookClub),BOOKNAME_PLACE_BORROW(4),BOOKNAME_PLACE_TAKING(1) ,BOOKNAME_PLACE_HAS(2),BOOKNAME_PLACE_RETURN(1){}

void ServerThread::run() {
	while (!bookClub->isShouldTerminate()) {
        Frame answer;
        if (!ch->getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        if (answer.getCommand() == "CONNECTED") {
            std::cout << "Login successful" << std::endl;
        }

            //if the user got a message from the server
        else if (answer.getCommand() == "MESSAGE") {
            std::string topic = answer.getValueByKey("destination");
            //add
            if (answer.getBody().find("has added", 0) != std::string::npos) { // add message
                std::cout << answer.getBody() << std::endl;
            }
                //borrow
            else if (answer.getBody().find("wish to borrow") != std::string::npos) {
                std::vector<std::string> splitted = split(answer.getBody(), ' ');
                std::string bookname;
                for (int i = BOOKNAME_PLACE_BORROW; i < splitted.size(); i++) {
                    bookname += splitted[i] + ' ';
                }
                bookname = bookname.substr(0, bookname.length() - 1);
                //the book exists in the client's inventory
                if (bookClub->canSendBook(bookname)) {
                    Frame sendFrame;
                    sendFrame.setCommand("SEND");
                    sendFrame.addHeader("destination", topic);
                    sendFrame.setBody(bookClub->getUsername() + " has " + bookname);
                    if (!ch->sendLine(sendFrame)) {
                        std::cout << "Disconnected. Exiting...\n" << std::endl;
                        break;
                    }
                }

            }
                //message about having books
            else if (answer.getBody().find("has") != std::string::npos) {
                std::vector<std::string> splitted = split(answer.getBody(), ' ');
                std::string bookName;
                for (int i = BOOKNAME_PLACE_HAS; i < splitted.size(); i++) {
                    bookName += splitted[i] + ' ';
                }
                bookName = bookName.substr(0, bookName.length() - 1);
                std::vector<std::string> books = bookClub->getRequestsForBooks();
                if (std::find(books.begin(), books.end(), bookName) != books.end()) {
                    bookClub->removeRequestedBook(bookName);
                    Frame takingFrame;
                    takingFrame.setCommand("SEND");
                    takingFrame.addHeader("destination", topic);
                    takingFrame.setBody("Taking " + bookName + " from " + splitted[0]);
                    bookClub->addBook(bookName, splitted[0]);
                    bookClub->addBookToTopic(bookName, topic);
                    if (!ch->sendLine(takingFrame)) {
                        std::cout << "Disconnected. Exiting...\n" << std::endl;
                        break;
                    }
                }
            } else if (answer.getBody().find("Taking") != std::string::npos) {
                std::vector<std::string> splitted = split(answer.getBody(), ' ');
                std::string bookName;
                int userNamePlace;
                for (int i = BOOKNAME_PLACE_TAKING; i < splitted.size(); i++) {
                    if (splitted[i] == "from") {
                        userNamePlace = i + 1;
                        break;
                    }
                    bookName += splitted[i] + ' ';
                }
                bookName = bookName.substr(0, bookName.length() - 1);

                if (bookClub->getUsername() == splitted[userNamePlace]) {
                    bookClub->setBelong(false, bookName);
                    bookClub->removeBookFromTopic(bookName, topic);
                }
            } else if (answer.getBody().find("Returning") != std::string::npos) {
                std::vector<std::string> splitted = split(answer.getBody(), ' ');
                std::string bookName;
                int userNamePlace;
                for (int i = BOOKNAME_PLACE_RETURN; i < splitted.size(); i++) {
                    if (splitted[i] == "to") {
                        userNamePlace = i + 1;
                        break;
                    }
                    bookName += splitted[i] + ' ';
                }
                bookName = bookName.substr(0, bookName.length() - 1);
                if (bookClub->getUsername() == splitted[userNamePlace]) {
					bookClub->setBelong(true, bookName);
					bookClub->addBookToTopic(bookName, answer.getValueByKey("destination"));
                }
            }
                //got status message
            else if (answer.getBody().find("status") != std::string::npos) {
                //need to check that it's not null either
                std::vector<std::string> statusOfBooks = bookClub->getStatusBooks(topic);
                if (statusOfBooks.size() != 0) {
                    Frame statusFrame;
                    statusFrame.setCommand("SEND");
                    statusFrame.addHeader("destination", topic);
                    std::string statusFrameBody = bookClub->getUsername() + ':';
                    //going through all the books from the topic that the user has
                    for (int i = 0; i < statusOfBooks.size(); i++) {
                        statusFrameBody += statusOfBooks[i] + ',';
                    }
                    statusFrameBody = statusFrameBody.substr(0, statusFrameBody.length() - 1);//removed the last comma
                    statusFrame.setBody(statusFrameBody);
					if (!ch->sendLine(statusFrame)) {
						std::cout << "Disconnected. Exiting...\n" << std::endl;
						break;
					}
                }
            }
            else if (answer.getBody().find(":") != std::string::npos) {
            	std::cout << answer.getBody() << std::endl;
            }
        }

        else if (answer.getCommand() == "RECEIPT") {
            int receiptId=answer.getReceiptIdFromReceiptMessage();
            std::string typeOfMessageGenre=bookClub->getTypeFrameGenreById(receiptId);
            if(typeOfMessageGenre=="DISCONNECT") {
				bookClub->setShouldTerminate(true);
				ch->close();
				break;
			}
            std::vector<std::string> splitted = split(typeOfMessageGenre, ' ');
            std::string typeOfMessage=splitted[0];
            std::string genre=splitted[1];
            if(typeOfMessage=="SUBSCRIBE")
                std::cout << "Joined club "+genre << std::endl;
            else if(typeOfMessage=="UNSUBSCRIBE")
                std::cout << "Exited club "+genre << std::endl;
        }
        else if(answer.getCommand()=="ERROR"){
        	if (answer.getHeaders().find("receipt") != answer.getHeaders().end()) {
        		std::cout << "receipt id: " + answer.getValueByKey("receipt");
        	}
        	std::cout << answer.getValueByKey("message") << std::endl;
        	std::cout << answer.getBody() << std::endl;
			bookClub->setShouldTerminate(true);
        	ch->close();

			break;
        }
    }
}

std::vector<std::string> ServerThread::split(std::string strToSplit, char delimiter) {
	std::vector<std::string> result;
	std::string currentStr = "";
	for (int i = 0; i < strToSplit.length(); ++i) {
		if (strToSplit[i] == delimiter) {
			result.push_back(currentStr);
			currentStr = "";
		}
		else {
			currentStr += strToSplit[i];
		}
	}
	result.push_back(currentStr);
	return result;
}