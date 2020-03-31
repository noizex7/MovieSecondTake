#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace::std;

class Movie
{
private:
	string* title = nullptr;
	string* director = nullptr;
	int* yearReleased = nullptr;
	int* runningTime = nullptr;
	double* productionCost = nullptr;
	double* firstYearRevenue = nullptr;
public:
	Movie();
	Movie(Movie*);
	~Movie();
	void setTitle(string*);
	void setDirector(string*);
	void setYear(int*);
	void setTime(int*);
	void setCost(double*);
	void setRevenue(double*);
	void setAll(string*, string*, int*, int*, double*, double*);
	string* getTitle();
	string* getDirector();
	int* getYear();
	int* getTime();
	double* getCost();
	double* getRevenue();
	void display();

};

