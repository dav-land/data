#include "Movie.hpp"
using namespace std;

void dispMovie(Movie a);

int main(){
	Movie m1;
	Movie m2("The Incredibles 2", 2018, 5.0);
	Movie m3;

	m1.setTitle("The Grinch");
	m1.setYear(1260);
	m1.setRating(3.2);
	
	m3.setTitle("none");

	dispMovie(m1);
	dispMovie(m2);
	dispMovie(m3);

	return 0;
}

void dispMovie(Movie a){
	cout << a.getTitle() << " (" << a.getYear() << ") Rating: " << a.getRating() << endl;
}
