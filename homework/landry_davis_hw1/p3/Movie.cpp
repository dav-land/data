#include "Movie.hpp"
using namespace std;

Movie::Movie(){
	title = "unknown";
	year = 2016;
	rating = 0.0;
}
Movie::Movie(string _title , int _year, double _rating){
	title = _title;
	year = _year;
	rating = _rating;
}

string Movie::getTitle(){
	return title;
}
int Movie::getYear(){
	return year;
}
double Movie::getRating(){
	return rating;
}

void Movie::setTitle(string _title){
	title = _title;
}
void Movie::setYear(int _year){
	year = _year;
}
void Movie::setRating(double _rating){
	rating = _rating;
}
