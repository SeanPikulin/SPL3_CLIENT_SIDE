//
// Created by inonk on 12/01/2020.
//

#ifndef SPL3_IOTHREAD_H
#define SPL3_IOTHREAD_H


#include <string>
#include "../include/ServerThread.h"

class IOThread {
public:
	IOThread(ConnectionHandler *ch, BookClub* bookClub);
	void run();

    virtual ~IOThread();


private:
	ConnectionHandler *ch;
	BookClub* bookClub;
	std::thread thServer;
};


#endif //SPL3_IOTHREAD_H
