#include "bookClass.hpp"

using namespace std;

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
	title = in;
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

void Book::writeToFile(string filename){
	ofstream outFile;
	outFile.open(filename);
	if(outFile.is_open()){
		outFile << title 	<<"\n"
				<< author 	<<"\n"
				<< date 	<<"\n"
				<< excerpt 	<<"\n"
				<< wordCount<<"\n"
				<< complete <<"\n"
				<< publisher<<"\n";
	}
	outFile.flush();
}

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

void searchLibrary(vector<Book*> &library, string flag){

}