//
// Created by inonk on 13/01/2020.
//

#ifndef SPL3_BOOKCLUB_H
#define SPL3_BOOKCLUB_H


#include <map>
#include <vector>
#include <mutex>


class BookClub {
private:
	std::map<std::string,std::pair<std::string,bool >> bookOwnerBelongMap;
	std::map<std::string, int> topicToID;
	std::vector<std::string> requestsForBooks;
	std::map<int,std::string> receiptIdToTypeMessageGenre;
	std::map<std::string,std::vector<std::string>> topicToListOfCurrentBooks;
	std::string username;
	bool shouldTerminate;
	std::mutex mutex;
public:
	BookClub();
	~BookClub();
	bool addSubscription(std::string& topic, int id);
	int getIDByTopic(std::string topic);
	bool removeSubscription(std::string& topic);
	void addBook(std::string book, std::string owner);
	void removeBook(std::string book);
	std::string& getOwnerByBook(std::string book);
	void addToRequestedBooks(std::string book);
	void setBelong(bool,std::string);
	bool canSendBook(std::string);
	void addBookToTopic(std::string bookName,std::string topic);
	void removeBookFromTopic(std::string bookName,std::string topic);
	std::vector<std::string>& getStatusBooks(std::string topic);
	const std::string &getUsername() const;
	void addReceiptIdToMessage(int id,std::string);
	std::string getTypeFrameGenreById(int id);

	bool isShouldTerminate() const;

	void setShouldTerminate(bool shouldTerminate);

	void setUsername(const std::string &username);

	const std::vector<std::string> &getRequestsForBooks() const;

	void removeRequestedBook(std::string book);

};


#endif //SPL3_BOOKCLUB_H
