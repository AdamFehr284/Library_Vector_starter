#include <iostream>
#include <fstream>
#include "../includes_usr/fileIO.h"
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	ifstream file;
	file.open(filename);

	//if file did not open
	if(!file.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	//assumes file is open
	else {


		//if file is at end of line
		if(file.eof()){
			return NO_BOOKS_IN_LIBRARY;
		}

		//whole book need to come up with a way to turn it into a book struct
		string line;

		while(!file.eof()){
			getline(file, line);

		}
	}

	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	ofstream myOutputfile;
	myOutputfile.open(filename);
	if(!myOutputfile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	if(books.size() == 0){
		return NO_PATRONS_IN_LIBRARY;
	}
	string bookString;

	string bookName;
	string authorName;
	book_checkout_state status;
	int id;
	int patronLoanedTo;

	for(int i = 0; i<books.size(); i++){
		bookName = books[i].title;
		authorName = books[i].author;
		status = books[i].state;
		id = books[i].book_id;
		patronLoanedTo = books[i].loaned_to_patron_id;
		bookString = id + "," + bookName+ "," + authorName + "," + status + "," + patronLoanedTo;
		myOutputfile << bookString+ "\n";
	}

	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	ifstream file;
	file.open(filename);

	//if file did not open
	if(!file.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	//assumes file is open
	else {


		//if file is at end of line
		if(file.eof()){
			return NO_PATRONS_IN_LIBRARY;
		}

		//whole book need to come up with a way to turn it into a Patron struct
		string line;

		while(!file.eof()){
			getline(file, line);

		}
	}

	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	ofstream myOutputfile;
	myOutputfile.open(filename);
	if(!myOutputfile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	if(patrons.size() == 0){
		return NO_PATRONS_IN_LIBRARY;
	}
	string patronString;
	int booksChecked;
	int id;
	string patronName;
	for(int i = 0; i<patrons.size(); i++){
		patronName = patrons[i].name;
		id = patrons[i].patron_id;
		booksChecked = patrons[i].number_books_checked_out;
		patronString = id + "," + patronName + "," + booksChecked;
		myOutputfile << patronString+ "\n";
	}

	return SUCCESS;
}
