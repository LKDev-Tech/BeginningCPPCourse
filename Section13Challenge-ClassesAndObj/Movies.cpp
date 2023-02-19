/******************************************************************
 * Section 13 Challenge
 * Movies.h
 *
 * Models a collection of Movies as a std::vector
 *
 * ***************************************************************/
#include <iostream>
#include <algorithm>
#include "Movies.h"

 // Movies no-args constructor
Movies::Movies() { }

 // Movies destructor
Movies::~Movies() { }


bool Movies::add_movie(std::string name, std::string rating, int watched) {
    std::vector<Movie>::iterator movieFound = find_if(movies.begin(), movies.end(), [name](const Movie& obj) {return obj.get_name() == name; });
    if (movieFound != movies.end() || (*movieFound).get_name() == name) return false;
    else {
        movies.push_back(Movie(name, rating, watched));
        return true;
    }
}

bool Movies::increment_watched(std::string name) {
    std::vector<Movie>::iterator movieFound = find_if(movies.begin(), movies.end(), [name](const Movie& obj) {return obj.get_name() == name; });
    if (movieFound != movies.end() || (*movieFound).get_name() == name) {
        (*movieFound).increment_watched();
        return true;
    }
    else return false;
}

void Movies::display() const {
    if (movies.size() > 0) {
        std::cout << "==========================================" << std::endl;
        for (Movie movie : movies)
            movie.display();
        std::cout << "==========================================" << std::endl;
    }
    else std::cout << "Sorry, no movies to display." << std::endl;
}