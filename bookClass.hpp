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
must be in format const char* because ncurses functions
will not display them otherwise. This can be accomplished with
the function .c_str(), an inclusion from <string>. I think that's
all for this class; it's just a really big tuple, more or less.

*/

#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book{

private:

	string title;
	string author;
	string date;
	string excerpt;

	int wordCount;
	int ReadingTime; //stored in seconds and converted before display
	int pages;

	bool complete;

public:

	Book(string title, string author, 
		 string date, string excerpt,
  	  	 int wordCount, bool complete);

	Book();

	Book* operator<(Book* rhs);

	string getTitle();

	void setTitle(string in);

	string getAuthor();

	void setAuthor(string in);

	string getDate();

	void setDate(string in);

	string getExcerpt();

	void setExcerpt(string in);

	int getWordCount();

	void setWordCount(int in);

	bool isComplete();

	void setComplete(bool in);

	void writeToFile(std::ostream outFile){

	}

};

#endif
