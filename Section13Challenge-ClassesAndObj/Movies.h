/******************************************************************
 * Section 13 Challenge
 * Movies.h
 *
 * Models a collection of Movie as a std::vector
 *  implement these methods in Movies.cpp
 *
 * ***************************************************************/

#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;
public:
    Movies();           // Constructor
    ~Movies();          // Destructor

    /// <summary>
    ///    add_movie expects the name of the move, rating and watched count.
    ///    It will search the movies vector to see if a movie object already exists
    ///    with the same name.
    ///    If it does then return false since the movie already exists.
    ///    Otherwise, create a movie object from the provided information
    ///    and add that movie object to the movies vector and return true
    /// </summary>
    /// <param name="name">- Movie name</param>
    /// <param name="rating">- Movie rating</param>
    /// <param name="watched">- how many times movie has been seen</param>
    /// <returns></returns>
    bool add_movie(std::string name, std::string rating, int watched);

    /// <summary>
    /// increment_watched expects the name of the move to increment the watched count
    /// It will search the movies vector to see if a movie object already exists
    /// with the same name.
    /// If it does then increment that objects watched by 1 and return true.
    /// Otherwise, return false since then no movies object with the movie name
    /// provided exists to increment
    /// </summary>
    /// <param name="name">- Name of movie seen</param>
    /// <returns>Boolean value to notify is the increment was successfull</returns>
    bool increment_watched(std::string name);


    /// <summary>
    /// display all the movie objects in the movies vector.
    /// For each movie call the movie.display method so the movie
    /// object displays itself
    /// </summary>
    void display() const;
};

#endif // _MOVIES_H_