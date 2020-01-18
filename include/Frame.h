//
// Created by inonk on 13/01/2020.
//

#ifndef SPL3_FRAME_H
#define SPL3_FRAME_H


#include <string>
#include <map>
#include <vector>

class Frame {
private:
	std::string command;
	std::map<std::string, std::string> headers;
	std::string body;
public:
	Frame();
	void addHeader(std::string key, std::string value);

	void setCommand(const std::string &command);

	void setHeaders(const std::map<std::string, std::string> &headers);

	void setBody(const std::string &body);

	const std::string &getCommand() const;

	const std::map<std::string, std::string> &getHeaders() const;

	const std::string &getBody() const;

	std::string getValueByKey(std::string key);

	int getReceiptIdFromReceiptMessage();


};


#endif //SPL3_FRAME_H
