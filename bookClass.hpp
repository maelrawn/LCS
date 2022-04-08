/*

I want the books to have:

Title
Author
Date Published
Genre (can be more than 1)
Excerpt (this will look silly to store, but nice when displayed)
Word Count
Pages (derived from word count)
Reading Time (derived from word count)
Completed? (bool, default 0 so user can set)

Note that all the stuff that needs to be strings 
must be in format const char because ncurses functions
will not display them otherwise. This can be accomplished with
the function .c_str(), an inclusion from <string>. I think that's
all for this class; it's just a really big tuple, more or less.

*/

#ifndef BOOK_H
#define BOOK_H

#include "bookClass.hpp"

using namespace std;

class Book{

private:

	string title;
	string author;
	string date;
	string excerpt;
	string publisher;

	int wordCount;
	int readingTime; //stored in minutes 
	int pages;

	bool complete;

public:

	Book(string title, string author, 
		 string date, string excerpt, string publisher,
  	  	 int pageCount, bool complete);

	Book();

	bool operator<(Book* rhs);

	string getTitle();

	void setTitle(string in);

	string getAuthor();

	void setAuthor(string in);

	string getDate();

	void setDate(string in);

	string getExcerpt();

	void setExcerpt(string in);

	string getPublisher();

	void setPublisher(string in);

	int getPageCount();

	void setPageCount(int in);

	int getWordCount();

	int getReadingTime();

	string isComplete();

	void setComplete(bool in);

	void writeToFile(string filename);

};

#endif

