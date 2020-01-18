//
// Created by inonk on 13/01/2020.
//

#include "../include/Frame.h"

Frame::Frame(): command(""), headers(), body("") {

}

void Frame::addHeader(std::string key, std::string value) {
	headers[key] = value;
}

void Frame::setCommand(const std::string &command) {
	Frame::command = command;
}

void Frame::setHeaders(const std::map<std::string, std::string> &headers) {
	Frame::headers = headers;
}

void Frame::setBody(const std::string &body) {
	Frame::body = body;
}

const std::string &Frame::getCommand() const {
	return command;
}

const std::map<std::string, std::string> &Frame::getHeaders() const {
	return headers;
}

const std::string &Frame::getBody() const {
	return body;
}

std::string Frame::getValueByKey(std::string key) {
	return headers[key];
}

int Frame::getReceiptIdFromReceiptMessage() {
    std::string receiptIdHeader=headers["receipt-id"];
    receiptIdHeader=receiptIdHeader.substr(receiptIdHeader.find(':')+1,receiptIdHeader.length());
    int receiptId=std::stoi(receiptIdHeader);
    return receiptId;
}
