#include "Movie.h"

void printMenu();
void menuOptions(Movie*, int*, int*);
void setMovieData(Movie*, int*);
void addMovie(Movie*, int*);
void removeMovie(Movie*, int*);
void displayMovie(Movie*, int*);
void modifyMovie(Movie*);

int main()
{
	int* size = nullptr;
	int* n = nullptr;
	int* choice = nullptr;
	Movie* list = nullptr;

	size = new int;
	*size = 5;

	n = new int;
	*n = 0;

	choice = new int;

	list = new Movie[*size];

	do
	{
		printMenu();
		cin >> *choice;
		menuOptions(list, choice, n);
	} while (*choice != 5);

	delete size;
	delete n;
	delete choice;
	delete[] list;

	return 0;
}

void printMenu()
{
	cout << "Movie Menu:\n"
		<< "1- Add movie\n"
		<< "2- Remove Movie\n"
		<< "3- Modify movie\n"
		<< "4- Display list\n"
		<< "5- Exit\n";
}

void menuOptions(Movie* aList, int* choice, int* n)
{
	switch (*choice)
	{
	case 1:
		addMovie(aList, n);
		break;
	case 2:
		removeMovie(aList, n);
		break;
	case 3:
		modifyMovie(aList);
		break;
	case 4:
		displayMovie(aList, n);
		break;
	case 5:
		cout << "Goodbye!!!\n";
		break;
	default:
		cout << "Invalid input, try again\n";
		break;
	}
}

void setMovieData(Movie* aList, int* n)
{
	string* title = nullptr;
	string* director = nullptr;
	int* yearReleased = nullptr;
	int* runningTime = nullptr;
	double* productionCost = nullptr;
	double* firstYearRevenue = nullptr;

	title = new string;
	director = new string;
	yearReleased = new int;
	runningTime = new int;
	productionCost = new double;
	firstYearRevenue = new double;

	cin.ignore(80, '\n');
	cin.clear();

	cout << "Enter the Title:\n";
	getline(cin, *title);

	cin.clear();

	cout << "Enter the Director's name:\n";
	getline(cin, *director);

	cout << "Enter the year the movie released:\n";
	cin >> *yearReleased;

	cout << "Enter the running time in minutes:\n";
	cin >> *runningTime;

	cout << "Enter the production cost:\n";
	cin >> *productionCost;

	cout << "Enter the first year revenue:\n";
	cin >> *firstYearRevenue;

	aList[*n].setAll(title, director, yearReleased, runningTime, productionCost, firstYearRevenue);

	delete title;
	delete director;
	delete yearReleased;
	delete runningTime;
	delete productionCost;
	delete firstYearRevenue;
}

void addMovie(Movie* aList, int* n)
{
	setMovieData(aList, n);
	(*n)++;
	cout << "\n\n\n";
}

void removeMovie(Movie* aList, int* n)
{
	n--;
	cout << "\n\n\n";
}

void displayMovie(Movie* aList, int* n)
{
	int i;
	cout << setw(30) << "Title" << setw(30) << "Director" << setw(30) << "Release Year" << setw(30) << "Running Time(Minutes)" << setw(30) << "Production Cost" << setw(30)
		<< "First Year Revenue" << setw(30) << "Profit\n";
	for (i = 0; i < *n; i++)
	{
		aList[i].display();
	}

	cout << "\n\n\n\n";
}

void modifyMovie(Movie* aList)
{
	int* i = nullptr;
	i = new int;

	do
	{
		cout << "Enter the number of the movie to modify:\n";
		cin >> *i;
		if (*i <= 5 && *i > 0)
		{
			cout << "Invalid input, try again:\n";
		}
	} while (*i <= 5 && *i > 0);

	(*i)--;

	setMovieData(aList, i);
}
