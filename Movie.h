#ifndef __MOVIE_H__
#define __MOVIE_H__
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Movie {
private:
protected:
public:
	string title;
	int year, runningTime;
	string colorBW;
	Movie(string t = "No Title", int y = 1, int rt = 0, string c = "Color") {
		title = t; year = y; runningTime = rt; colorBW = c;
	}
	/*
	*  A destructor.  Not really necessary but I like to set fields so that
	*  a deleted object is at least noticed if it is referenced.
	*/
	~Movie() {
		title = "No Title"; colorBW = "No Value"; year = 0; runningTime = 0;
	}
	/*
	* Access methods for fields.
	*/
	string getTitle() { return title; }
	int getYear() { return year; }
	Movie newMovieInfo();
	int getRunningTime() { return runningTime; }
	string getColorBW() { return colorBW; }
	bool isColor() { return colorBW == "Color"; }
	bool isBlackAndWhite() { return !isColor(); }
	/*
	* Equal to relational operator
	*/
	bool operator == (Movie rhs) {
		return title == rhs.title && year == rhs.year;
	}
	/*
	* Greater than relational operator
	*/
	bool operator < (Movie rhs) {
		if (title < rhs.title) {
			return true;
		}
		else if (title == rhs.title && year < rhs.year) {
			return true;
		}
		return false;
	}
	/*
	* Less than relational operator.
	*/
	bool operator >(Movie rhs) {
		if (title > rhs.title) {
			return true;
		}
		else if (title == rhs.title && year > rhs.year) {
			return true;
		}
		return false;
	}

	friend istream& operator >> (istream& ins, Movie &m);
};
struct myclass {
	bool operator() (Movie i, Movie j) {
		return (i<j);
	}
} myobject;
/*
*  output operator for the Movie class.  Outputs
*  the values one per line as stated in class.
*  Note:  Color is output as either Color or
*         BW depending on the value from the
*         isColor method.
*/
ostream& operator << (ostream & ostr, Movie m) {
	ostr << m.getTitle() << endl
		<< m.getYear() << endl
		<< m.getRunningTime() << endl;
	if (m.isColor()) {
		ostr << "Color" << endl;
	}
	else {
		ostr << "BW" << endl;
	}
	return ostr;
}
/*
*  input operator for the movies class.  No real
*  error checking is done.  Assumes the information
*  is in the form given in class.
*/
istream& operator >> (istream& ins, Movie &m) {
	string junk;
	getline(ins, m.title);
	ins >> m.year >> m.runningTime;
	getline(ins, junk);
	getline(ins, m.colorBW);
	return ins;
}

#endif