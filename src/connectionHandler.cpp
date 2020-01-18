#include "../include/connectionHandler.h"

using boost::asio::ip::tcp;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

ConnectionHandler::ConnectionHandler(string host, short port): host_(host), port_(port), io_service_(), socket_(io_service_){}

ConnectionHandler::~ConnectionHandler() {

}

bool ConnectionHandler::connect() {
	std::cout << "Starting connect to "
			  << host_ << ":" << port_ << std::endl;
	try {
		tcp::endpoint endpoint(boost::asio::ip::address::from_string(host_), port_); // the server endpoint
		boost::system::error_code error;
		socket_.connect(endpoint, error);
		if (error)
			throw boost::system::system_error(error);
	}
	catch (std::exception& e) {
		std::cerr << "Connection failed (Error: " << e.what() << ')' << std::endl;
		return false;
	}
	return true;
}

bool ConnectionHandler::getBytes(char bytes[], unsigned int bytesToRead) {
	size_t tmp = 0;
	boost::system::error_code error;
	try {
		while (!error && bytesToRead > tmp ) {
			tmp += socket_.read_some(boost::asio::buffer(bytes+tmp, bytesToRead-tmp), error);
		}
		if(error)
			throw boost::system::system_error(error);
	} catch (std::exception& e) {
		std::cerr << "recv failed (Error: " << e.what() << ')' << std::endl;
		return false;
	}
	return true;
}

bool ConnectionHandler::sendBytes(const char bytes[], int bytesToWrite) {
	int tmp = 0;
	boost::system::error_code error;
	try {
		mutex.lock();
		while (!error && bytesToWrite > tmp) {
			tmp += socket_.write_some(boost::asio::buffer(bytes + tmp, bytesToWrite - tmp), error);
		}
		mutex.unlock();
		if(error)
			throw boost::system::system_error(error);
	} catch (std::exception& e) {
		std::cerr << "recv failed (Error: " << e.what() << ')' << std::endl;
		return false;
	}
	return true;
}

bool ConnectionHandler::getLine(Frame& frame) {
	std::string line = "";
	bool ret = getFrameAscii(line, '\0');
	if (ret) {
//		int len=line.length();
//		line.resize(len-1);
		std::vector<std::string> splitted = split(line, '\n');
		frame.setCommand(splitted[0]);
		int i = 1;
		while (splitted[i] != "") {
			std::vector<string> splitHeader = split(splitted[i], ':');
			frame.addHeader(splitHeader[0], splitHeader[1]);
			i++;
		}
		i++;
		std::string body;
		while (splitted[i] != "\0") {
			body += splitted[i] + '\n';
			i++;
		}
		if (body.length() != 0)
			body.resize(body.length()-1);
		frame.setBody(body);
	}
	return ret;
}

bool ConnectionHandler::sendLine(Frame& frame) {
	string toSend = frame.getCommand() + "\n";
	for (auto& x: frame.getHeaders()) {
		toSend += x.first + ":" + x.second + "\n";
	}
	toSend += '\n';
	if (frame.getBody().length() != 0)
		toSend += frame.getBody() + "\n";
	return sendFrameAscii(toSend, '\0');
}


bool ConnectionHandler::getFrameAscii(std::string& frame, char delimiter) {
	char ch;
	// Stop when we encounter the null character.
	// Notice that the null character is not appended to the frame string.
	try {
		do{
			if(!getBytes(&ch, 1))
			{
				return false;
			}
			if(ch!='\0')
				frame.append(1, ch);
		}while (delimiter != ch);
	} catch (std::exception& e) {
		std::cerr << "recv failed2 (Error: " << e.what() << ')' << std::endl;
		return false;
	}
	return true;
}


bool ConnectionHandler::sendFrameAscii(const std::string& frame, char delimiter) {
	bool result=sendBytes(frame.c_str(),frame.length());
	if(!result) return false;
	return sendBytes(&delimiter,1);
}

// Close down the connection properly.
void ConnectionHandler::close() {
	try{
		socket_.close();
	} catch (...) {
		std::cout << "closing failed: connection already closed" << std::endl;
	}
}

std::vector<std::string> ConnectionHandler::split(std::string strToSplit, char delimiter) {
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