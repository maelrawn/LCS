#include "bookClass.hpp"

using namespace std;

//I originally messed up the syntax for the contructor initializer list
//and g++ interpreted it as a series of gotos. By fixing it the way the
//compiler told me to, I wound up making a constructor that was incapable
//of making a book object. I spent days trying to fix this!
Book::Book(string title, string author, 
	 	   string date, string excerpt, string publisher,
	  	   int pages, bool complete):
		   title(title), author(author), 
	 	   date(date), excerpt(excerpt), publisher(publisher),
	 	   pages(pages), complete(complete){
	 	   wordCount = pages * 300;
	 	   readingTime = wordCount/240;
	 	   }

Book::Book():
		   title(""), author(""), 
	 	   date(""), excerpt(""), publisher(""),
	 	   wordCount(0), complete(0){
	 	   wordCount = pages * 300;
	 	   readingTime = wordCount/240;
	 	   }

string Book::getTitle(){
	return title;
}

void Book::setTitle(string in){
	title = in;
	return;
}

string Book::getAuthor(){
	return author;
}

void Book::setAuthor(string in){
	author = in;
	return;
}

string Book::getDate(){
	return date;
}

void Book::setDate(string in){
	date = in;
	return;
}

string Book::getExcerpt(){
	return excerpt;
}

void Book::setExcerpt(string in){
	excerpt = in;
	return;
}

string Book::getPublisher(){
	return publisher;
}

void Book::setPublisher(string in){
	publisher = in;
}

int Book::getWordCount(){
	return wordCount;
}

void Book::setPageCount(int in){
	pages = in;
	return;
}

int Book::getPageCount(){
	return pages;
}

int Book::getReadingTime(){
	return readingTime;
}

string Book::isComplete(){
	if(complete)
		return "Yes!";
	return "No...";
}

void Book::setComplete(bool in){
	complete = in;
}

//I wanted to use this to sort the vector but sort(v.begin, v.end, ::sort)
//would have taken too long to get working
bool Book::operator<(Book* rhs){
	if(this->author[0] < rhs->author[0])
		return true;
	else 
		return false;
}

//ios_base::app lets us append to our file instead of overwriting,
//so we can use a member function (otherwise the repeated open/close
//would continuously overwrite one another. I also tried this with a
//ofstream *ostream, but was getting a 'bus error.' Ok, c++.)
void Book::writeToFile(string filename){
	ofstream outFile;
	outFile.open(filename, ios_base::app);
	if(outFile.is_open()){
		outFile << title 	<<"\n"
				<< author 	<<"\n"
				<< date 	<<"\n"
				<< excerpt 	<<"\n"
				<< publisher<<"\n"
				<< pages	<<"\n"
				<< complete <<"\n";
	}
	outFile.flush();
}

//Used to output human-readable times in displayBrowseBook().
//This could be a member function.
string as_dhm(int readingTime){
	int days = 0;
	int hours = 0;
	int minutes = readingTime;
	while(minutes > 60 * 24){
		minutes -= 60 * 24;
		days++;
	}
	while(minutes > 60){
		minutes -= 60;
		hours++;
	}
	string dayss = to_string(days);
	string hourss = to_string(hours);
	string minutess = to_string(minutes);
	return "Days: "+dayss+", Hours: "+hourss+", Minutes: "+minutess;
}

//Reads from our input file
void populateLibrary(vector<Book*> &library, string filename){
	ifstream inFile;
	string tmp;
	vector<string> inV;
	inFile.open(filename);
	while(getline(inFile, tmp)){
		inV.push_back(tmp);
		if(inV.size() == 7){
			library.push_back(new Book( inV.at(0), 
						    			inV.at(1), 
										inV.at(2),
									    inV.at(3),
									    inV.at(4),
								   stoi(inV.at(5)), 
			 		  			   stoi(inV.at(6))));
			inV.clear();
		}
	}
	inFile.close();
}

//Sorts books by author, and sorts books grouped by author by title
void sortByAuthorAndTitle(vector<Book*> &library){
	Book* tmp = new Book();
	for(int j = 0; j < 2; j++){
		for(int i = 0; i < library.size() - 1; i++){
			if(library.at(i)->getAuthor()[0] > library.at(i+1)->getAuthor()[0]){
				tmp = library.at(i+1);
				library.at(i+1) = library.at(i);
				library.at(i) = tmp;
				i = 0;
			}
			if(library.at(i)->getAuthor()[0] == library.at(i+1)->getAuthor()[0]
				&& library.at(i)->getTitle()[0] > library.at(i)->getTitle()[0]){

				tmp = library.at(i+1);
				library.at(i+1) = library.at(i);
				library.at(i) = tmp;
				i = 0;
			}
		}
	}
}