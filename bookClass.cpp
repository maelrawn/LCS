#include "bookClass.hpp"

using namespace std;

Book::Book(string title, string author, 
	 	   string date, string excerpt,
	  	   int wordCount, bool complete)
		  {title: title; author: author; 
	 	   date: date; excerpt: excerpt;
	 	   wordCount: wordCount; complete: complete;};

Book::Book(){title: ""; author: ""; 
	    	 date: ""; excerpt: "";
	   		 wordCount: NULL; complete: false;};

string Book::getTitle(){
	return title;
}

void Book::setTitle(string in){
	this->title = in;
	return;
}

string Book::getAuthor(){
	return author;
}

void Book::setAuthor(string in){
	this->title = in;
	return;
}

string Book::getDate(){
	return date;
}

void Book::setDate(string in){
	this->date = in;
	return;
}

string Book::getExcerpt(){
	return excerpt;
}

void Book::setExcerpt(string in){
	this->excerpt = in;
	return;
}

int Book::getWordCount(){
	return wordCount;
}

void Book::setWordCount(int in){
	this->wordCount = in;
	return;
}

bool Book::isComplete(){
	return complete;
}

void Book::setComplete(bool in){
	this->complete = in;
}

void Book::writeToFile(ofstream *outFile){
	*outFile<< title 	<<"\n"
			<< author 	<<"\n"
			<< date 	<<"\n"
			<< excerpt 	<<"\n"
			<< wordCount<<"\n"
			<< complete <<"\n";
	outFile->flush();
}
