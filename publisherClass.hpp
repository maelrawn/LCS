/*

I want the publishers to have:

a set of books belonging to them, probably as vector<Book*>,
the ability to search for books by attribute, 
and I want them to be displayed alphabetically. This 
probably implies some sorting. I think I like a bubble sort, and
I want to implement it myself. I'd have to implement some
bool Book::operator<(this, Book rhs) (pointer?) to do so.
So, this class will get a lot of functions to operate on collections
of books, but not much data on its own.

*/


#ifndef PUBL_H
#define PUBL_H

#include "bookClass.hpp"

using namespace std;

class Publisher{

private:

	vector<Book> bookVec;

	string publisherName; 
		//oh my god why do public and publisher share their first 5 letters
	int librarySize;

public:

	Publisher(string name);

	Publisher();

	// Book* operator[](size_t index);

	Book* getBook(string trait);

	void addBook(Book* book);

	void writeToFile(std::ostream outFile);

};
#include "publisherClass.cpp"

#endif