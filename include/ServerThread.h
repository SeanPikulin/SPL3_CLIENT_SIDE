//
// Created by inonk on 13/01/2020.
//

#ifndef SPL3_SERVERTHREAD_H
#define SPL3_SERVERTHREAD_H

#include "../include/connectionHandler.h"
#include "../include/BookClub.h"
#include <vector>

class ServerThread {
public:
	ServerThread(ConnectionHandler *ch, BookClub* bookClub);
	void run();
	std::vector<std::string> split(std::string strToSplit, char delimiter);

private:
	ConnectionHandler *ch;
	BookClub* bookClub;
	const int BOOKNAME_PLACE_BORROW;
	const int BOOKNAME_PLACE_TAKING;
	const int BOOKNAME_PLACE_HAS;
	const int BOOKNAME_PLACE_RETURN;

};


#endif //SPL3_SERVERTHREAD_H
