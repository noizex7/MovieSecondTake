#include "Movie.h"

Movie::Movie()
{
	title = new string;
	director = new string;
	yearReleased = new int;
	runningTime = new int;
	productionCost = new double;
	firstYearRevenue = new double;

	*title = "No Title";
	*director = "No Director";
	*yearReleased = 1888;
	*runningTime = 0.0;
	*productionCost = 0.0;
	*firstYearRevenue = 0.0;
}

Movie::Movie(Movie* copy)
{
	setAll(copy->getTitle(), copy->getDirector(), copy->getYear(), copy->getTime(), copy->getCost(), copy->getRevenue());
}

Movie::~Movie()
{
	delete title;
	delete director;
	delete yearReleased;
	delete runningTime;
	delete productionCost;
	delete firstYearRevenue;
}

void Movie::setTitle(string* aTitle)
{
	*title = *aTitle;
}

void Movie::setDirector(string* aDirector)
{
	*director = *aDirector;
}

void Movie::setYear(int* aYear)
{
	if (*aYear < 1888)
	{
		*yearReleased = 1888;
	}
	else
	{
		*yearReleased = *aYear;
	}
}

void Movie::setTime(int* aTime)
{
	if (*aTime < 0)
	{
		*runningTime = 0;
	}
	else
	{
		*runningTime = *aTime;
	}
}

void Movie::setCost(double* aCost)
{
	if (*aCost < 0)
	{
		*productionCost = 0;
	}
	else
	{
		*productionCost = *aCost;
	}
}

void Movie::setRevenue(double* aRevenue)
{
	if (*aRevenue < 0)
	{
		*firstYearRevenue = 0;
	}
	else
	{
		*firstYearRevenue = *aRevenue;
	}
}

void Movie::setAll(string* aTitle, string* aDirector, int* aYear, int* aTime, double* aCost, double* aRevenue)
{
	setTitle(aTitle);
	setDirector(aDirector);
	setYear(aYear);
	setTime(aTime);
	setCost(aCost);
	setRevenue(aRevenue);
}

string* Movie::getTitle()
{
	return title;
}

string* Movie::getDirector()
{
	return director;
}

int* Movie::getYear()
{
	return yearReleased;
}

int* Movie::getTime()
{
	return runningTime;
}

double* Movie::getCost()
{
	return productionCost;
}

double* Movie::getRevenue()
{
	return firstYearRevenue;
}

void Movie::display()
{
	cout << setw(30) << *getTitle() << setw(30) << *getDirector() << setw(30) << *getYear() << setw(30)
		<< *getTime() << fixed << setprecision(2) << setw(30) << *getCost() << setw(30) << *getRevenue() << setw(30);
}