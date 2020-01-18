//
// Created by inonk on 13/01/2020.
//

#include <algorithm>
#include "../include/BookClub.h"

BookClub::BookClub(): bookOwnerBelongMap(), topicToID(), requestsForBooks(),topicToListOfCurrentBooks(),receiptIdToTypeMessageGenre(), shouldTerminate(false)  {

}

BookClub::~BookClub() {
	bookOwnerBelongMap.clear();
	topicToID.clear();
	requestsForBooks.clear();
	receiptIdToTypeMessageGenre.clear();
	topicToListOfCurrentBooks.clear();
}

void BookClub::addBook(std::string book, std::string owner) {
	std::pair<std::string,bool> ownerBelongs=std::make_pair(owner, true);
	std::lock_guard<std::mutex> lock(mutex);
	bookOwnerBelongMap[book]=ownerBelongs;
}

void BookClub::removeBook(std::string book) {
	std::lock_guard<std::mutex> lock(mutex);
	bookOwnerBelongMap.erase(book);
	}

std::string& BookClub::getOwnerByBook(std::string book) {
    std::lock_guard<std::mutex> lock(mutex);
    return bookOwnerBelongMap[book].first;
}

void BookClub::setBelong(bool ans, std::string bookName) {
    std::lock_guard<std::mutex> lock(mutex);
    bookOwnerBelongMap[bookName].second=ans;
}

bool BookClub::canSendBook(std::string bookname) {
    std::lock_guard<std::mutex> lock(mutex);
    return (bookOwnerBelongMap.find(bookname) != bookOwnerBelongMap.end() && bookOwnerBelongMap[bookname].second);
}

bool BookClub::addSubscription(std::string &topic, int id) {
	std::lock_guard<std::mutex> lock(mutex);
	if (topicToID.find(topic) == topicToID.end()) {
		topicToID[topic] = id;
		return true;
	}
	return false;
}


int BookClub::getIDByTopic(std::string topic) {
	return topicToID[topic];
}

bool BookClub::removeSubscription(std::string &topic) {
	std::lock_guard<std::mutex> lock(mutex);
	if (topicToID.find(topic) != topicToID.end()) {
		topicToID.erase(topic);
		return true;
	}
	return false;
}

void BookClub::addToRequestedBooks(std::string book) {
	std::lock_guard<std::mutex> lock(mutex);
	requestsForBooks.push_back(book);
}

void BookClub::addBookToTopic(std::string bookName, std::string topic) {
	std::lock_guard<std::mutex> lock(mutex);
    topicToListOfCurrentBooks[topic].push_back(bookName);
}

void BookClub::removeBookFromTopic(std::string bookName, std::string topic) {
	std::lock_guard<std::mutex> lock(mutex);
    topicToListOfCurrentBooks[topic].erase(std::find(topicToListOfCurrentBooks[topic].begin(),topicToListOfCurrentBooks[topic].end(),bookName));
}

std::vector<std::string>& BookClub::getStatusBooks(std::string topic) {
	std::lock_guard<std::mutex> lock(mutex);
    return topicToListOfCurrentBooks[topic];
}

const std::string &BookClub::getUsername() const {
	return username;
}

const std::vector<std::string> &BookClub::getRequestsForBooks() const {
	return requestsForBooks;
}

void BookClub::setUsername(const std::string &username) {
	BookClub::username = username;
}

void BookClub::removeRequestedBook(std::string book) {
	std::lock_guard<std::mutex> lock(mutex);
	requestsForBooks.erase(std::find(requestsForBooks.begin(), requestsForBooks.end(), book));
}


void BookClub::addReceiptIdToMessage(int id, std::string message) {
	std::lock_guard<std::mutex> lock(mutex);
    receiptIdToTypeMessageGenre[id]=message;
}

std::string BookClub::getTypeFrameGenreById(int id) {
	std::lock_guard<std::mutex> lock(mutex);
    return receiptIdToTypeMessageGenre[id];
}

bool BookClub::isShouldTerminate() const {
	return shouldTerminate;
}

void BookClub::setShouldTerminate(bool shouldTerminate) {
	BookClub::shouldTerminate = shouldTerminate;
}



