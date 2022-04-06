#include "publisherClass.hpp"

Publisher::Publisher(string name, vector<Book*> *catalog)
	{publisherName: name;
	 bookVec: catalog;
	 librarySize: bookVec->size();
	}	

Publisher::Publisher(string name)
	{publisherName: name;
	 bookVec: new vector<Book*>;
	 librarySize: NULL;
	};

Publisher::Publisher()
	{bookVec: new vector<Book*>;
	 publisherName: "";
	 librarySize: NULL;
	};

Book* Publisher::operator[](size_t index){
	return this->bookVec->at(index);
}

Book* Publisher::getBookAt(int idx){
	return this->bookVec->at(idx);
}

Book* Publisher::getBook(string trait){}

void Publisher::addBook(Book* book){
	this->bookVec->push_back(book);
}

void Publisher::writeToFile(string fileName){
	ofstream *outFile;
	outFile->open(fileName); 
	for(int i = 0; i < this->bookVec->size(); i++){
		bookVec->at(i)->writeToFile(outFile);
		*outFile<<publisherName<<"\n";
		outFile->flush();
	}
	outFile->close();
}

void Publisher::readFromFile(string fileName){
	ifstream inFile; 
	string tmp;
	vector<string> inV;
	cout<<"failing after vector dec\n";
	inFile.open(fileName);
	cout<<"file opened in member function";
	while(getline(inFile, tmp)){
		if(tmp == publisherName){
			addBook(new Book(   inV.at(0), 
								inV.at(1), 
								inV.at(2),
							    inV.at(3),
						   stoi(inV.at(4)), 
     		  					inV.at(5)[0]));
			inV.clear();
		}
		else
			inV.push_back(tmp);
	}
	inFile.close();
}

