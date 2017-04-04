#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Movie.h"
#include <vector>
#include <algorithm>
using namespace std;

/* Project 3 Binary tree Movie
*   By: Michael Revilla
*/

void test(Movie lhs, Movie rhs) {
	//my stuff
	//string tempL = lhs.getTitle();
	//string tempR = rhs.getTitle();
	//cout << tempL << "-+-" << tempR << endl;


	if (lhs < rhs) {
		cout << lhs << " is less than " << rhs << endl;
	}
	if (lhs == rhs) {
		cout << lhs << " is equal to " << rhs << endl;
	}
	if (lhs > rhs) {
		cout << lhs << " is greater than " << rhs << endl;
	}
}
int findPos(vector<Movie>& list) {

	string keyTitle = "";
	vector<Movie> listTemp;
	vector<Movie> listTempUlrta;
	vector<int> listSpot;
	int yr = 0;

	cin.ignore();
	cout << "Title> ";
	getline(cin, keyTitle);
	cout << "Year> ";
	cin >> yr;

	int j = 0, halfCut = 0;
	bool isFound = false;
	halfCut = ((list.size() / 2));
	listTemp = list;
	while (j <= list.size() - 1) {
		if (listTemp[halfCut].title<keyTitle) {
			listTempUlrta = listTemp;
			listTemp.clear();
			for (int i = halfCut; i < listTempUlrta.size(); i++) {
				listTemp.push_back(listTempUlrta[i]);
			}
			halfCut = ((listTemp.size() / 2));
		}
		else if (listTemp[halfCut].title>keyTitle) {
			listTempUlrta = listTemp;

			listTemp.clear();
			for (int i = 0; i < halfCut; i++) {
				listTemp.push_back(listTempUlrta[i]);
			}
			halfCut = ((listTemp.size() / 2));
		}
		else if (listTemp[halfCut].title == keyTitle) { //if title are same
			if (listTemp[halfCut].year<yr) {
				listTempUlrta = listTemp;
				listTemp.clear();
				for (int i = halfCut; i < listTempUlrta.size(); i++) {
					listTemp.push_back(listTempUlrta[i]);
				}
				halfCut = ((listTemp.size() / 2));
			}
			else if (listTemp[halfCut].year>yr) {
				listTempUlrta = listTemp;
				listTemp.clear();
				for (int i = 0; i < halfCut; i++) {
					listTemp.push_back(listTempUlrta[i]);
				}
				halfCut = ((listTemp.size() / 2));
			}
			else {
				int MyTemp = 0;
				MyTemp = find(list.begin(), list.end(), listTemp[halfCut]) - list.begin();
				return MyTemp;
				isFound = true;
				break;
			}
		}
		j++;
	}
	if (isFound == false) {
		return -1;
	}
}


/*
* testIOoperators tests whether the input and output operators
* for the movie class work and will work together.  It writes a
* file outmovies.txt to hold the movies and to read in a later
* section.
*/
void testIOoperators(vector<Movie> startList) {
	vector<Movie> inputList;
	ofstream outfile;
	ifstream infile;
	/*
	* output all the movies in the vector startList to the
	* outmovies.txt file.
	*/
	outfile.open("outmovies1.txt");
	if (outfile.is_open()) {
		for (auto i : startList) {
			outfile << i;
		}
		outfile.close();
	}

	/*
	*  Open the file for input and try to read in the
	* movies that were written out.
	*/
	infile.open("outmovies1.txt");
	if (infile.is_open()) {
		while (!infile.bad() && !infile.eof()) {
			Movie m;
			infile >> m;
			if (infile.good() && !infile.eof()) {
				inputList.push_back(m);
			}
		}
		infile.close();
	}

	/*
	* check if the two lists are identical or not.  This should be
	* possible with inputList == startList but I can't seem to get
	* that to work with Visual Studio.  Test size and then contents.
	*/
	if (inputList.size() != startList.size()) {
		cerr << "The lists are not equal -- their sizes differ" << endl;
	}
	else {
		for (int current = 0; current < inputList.size(); current++) {
			if (!(inputList[current] == startList[current])) {
				cerr << "The lists are not equal -- element " << current << "differs." << endl;
			}
		}
	}
}

/*
* A main program to test the routines in our Movies class.
*/
int main(int argCount, char *argValues[]) {
	Movie method;
	Movie m1("Moby Dick", 1938, 110, "BW"), m2("Moby Dick", 1998, 98, "Color"),
		m3, m4("Kill Bill", 1998, 99, "Color"), m5("Test", 1998, 110, "BW"), m6("Moby Dick", 1969, 52, "Color"), mNum;
	vector<Movie> list = { m1, m4,m6, m2, m3, m5 };

	//the following is mine
	string inComm = "";
	int invalCommNum = 0;
	cout << "If you need help tpye 'Help' into the command." << endl;
	std::sort(list.begin(), list.end(), myobject);
	while (inComm != "Exit") {
		cout << "Enter command:";
		cin >> inComm;
		if (inComm == "f") {//lookup
			int X = 0;
			X = findPos(list);
			if (X == -1) {
				cout << "Not Found!" << endl;
			}
			else {
				cout << list[X] << endl;
			}
		}
		else if (inComm == "a") {//add new movie
			mNum = method.newMovieInfo();
			list.push_back(mNum);
			std::sort(list.begin(), list.end(), myobject);
		}
		else if (inComm == "d") {//delete movie
			int X = 0;
			X = findPos(list);
			if (X == -1) {
				cout << "Not Found!" << endl;
			}
			else {
				string checkDel = "";
				cout << "Are you sure you want to delete " << list[X] << endl << "from the database? ('Y' or 'N') Yes and No respectfully!" << endl;
				cin >> checkDel;
				if (checkDel == "Y") {
					int MyTemp = 0;
					MyTemp = find(list.begin(), list.end(), list[X]) - list.begin();
					for (int i = 0; i < list.size(); i++) {
						cout << list[i] << endl;
					}
					cout << "-------------" << X << endl;
					list.erase(list.begin() + (MyTemp));
					for (int i = 0; i < list.size(); i++) {
						cout << list[i] << endl;
					}
				}
				else {
					cout << list[X].title << " will not be delete from the databse!" << endl;
				}

			}

			std::sort(list.begin(), list.end(), myobject);
		}
		else if (inComm == "p") {//list all the movies
			std::sort(list.begin(), list.end(), myobject);
			for (int i = 0; i < list.size(); i++) {
				cout << list[i] << endl;
			}
			cout << "-----------" << endl;
		}
		else if (inComm == "h" || inComm == "?") {//prints out help msg
			cout << "List of commands:" << endl;
			cout << "'f' -- use to find a movie, search by title." << endl;
			cout << "'a' -- use to add a movie." << endl;
			cout << "'d' -- use to delete a movie." << endl;
			cout << "'p' -- use to list out all the movies in order." << endl;
			cout << "'Exit' -- use to exit program." << endl;
		}
		else {// this is for anything else no vaild commands or Exit
			if (inComm == "Exit") {
				//do ending stuff 
			}
			else {
				cout << inComm + " is a invaild commnand, please try again!" << endl;
				invalCommNum++;
				if (invalCommNum >= 10) {
					cout << "If you need help tpye 'h' or '?' into the command." << endl;
					invalCommNum = 0;
				}
			}
		}
	}

	//test(m1, m2);
	//test(m1, m3);
	//test(m1, m4);
	//test(m1, m5);
	//test(m2, m5);
	//test(m3, m5);

	testIOoperators(list); //i comment this out to get tree stuff up 
	return EXIT_SUCCESS;
}


Movie Movie::newMovieInfo() {
	string tempName = "", tempcolor = "";
	int tempyr = 0, tempRuntime = 0;

	cin.ignore();
	cout << "Enter name of movie: ";
	getline(cin, tempName);
	cout << "Enter year of movie: ";
	cin >> tempyr;
	cout << "Enter runTime of movie: ";
	cin >> tempRuntime;
	cin.ignore();
	cout << "Enter Color or BW of movie: ";
	getline(cin, tempcolor);
	Movie mtemp(tempName, tempyr, tempRuntime, tempcolor);
	return mtemp;
}