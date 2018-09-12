#include <string>
#include <iostream>

class Movie {
	std::string title;
	int year;
	double rating;

public:
	Movie();
	Movie(std::string _title, int _year, double _rating);

	std::string getTitle();
	int getYear();
	double getRating();

	void setTitle(std::string _title);
	void setYear(int _year);
	void setRating(double _rating);

};
