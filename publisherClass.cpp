#include "publisherClass.hpp"

Publisher::Publisher(string name){publisherName: name;};

Publisher::Publisher()
	{bookVec: new vector<Book*>;
	 publisherName: "";
	 librarySize: NULL;
	};

Book* Publisher::operator[](size_t index){
	return this->bookVec[index];
}

Book* getBook(string trait);

void addBook(Book* book);

void writeToFile(std::ostream outFile);