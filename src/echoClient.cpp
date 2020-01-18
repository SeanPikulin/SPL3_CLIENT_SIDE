#include <stdlib.h>
#include "../include/IOThread.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {

	Frame message;
	std::string line;
	BookClub* bookClub = new BookClub();

	ConnectionHandler* connectionHandler;

	std::cin >> line;
	while (line != "login") {
		std::cout << "please login" << std::endl;
		getline(std::cin, line);
		std::cin >> line;
	}
	message.setCommand("CONNECT");
	message.addHeader("accept-version", "1.2");
	std::cin >> line;
    std::string host = line.substr(0, line.find(":"));
	message.addHeader("host", host);
	int port = std::stoi(line.substr(line.find(":") + 1));
	connectionHandler = new ConnectionHandler(host, port);
	std::cin >> line;
	message.addHeader("login", line);
	bookClub->setUsername(line);
	std::cin >> line;
	message.addHeader("passcode", line);

	if (!connectionHandler->connect()) {
		std::cerr << "Cannot connect to server at " << host << ":" << port << std::endl;
		return 1;
	}

	if (!connectionHandler->sendLine(message)) {
		std::cout << "Disconnected. Exiting...\n" << std::endl;
		bookClub->setShouldTerminate(false);
	}

	IOThread ioThread(connectionHandler, bookClub);
	std::thread thIO(&IOThread::run, &ioThread);
	ServerThread serverThread(connectionHandler, bookClub);
	std::thread thServer(&ServerThread::run, &serverThread);

	thIO.join();
	thServer.join();

	delete connectionHandler;
	delete bookClub;

	return 0;
}