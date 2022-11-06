/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

/**
 * This function reverses a given linked list and returns it.
 * @param list A pointer to the list that needs to be reversed.
 * @return A pointer to new reversed list.
 */
List<pair<int, string>>* reverse(List<pair<int, string>>* list) {
  int size = list->getSize();
  List<pair<int, string>>* reversed = new LinkedList<pair<int,string>>();
  for (int i=0; i<size; i++) {
    pair<int, string> first_element = list->removeFirst();
    reversed->insertFirst(first_element);
  }
  return reversed;
}


// Initiation point of the ASCIImation program.
int main(int argc, char** argv) {
  // Checks the validity of the command-line and functions as required!
  if (argc == 2) {
    string filename = argv[1];

    // Loads the movie into a list with movie_data pointer.
    List<pair<int, string>>* movie_data = loadMovie(filename);

    // Plays the ASCIImation in the given order.
    playMovie(movie_data);
    
    // Calls the deconstructor for the movie_data list, clears memory.
    delete movie_data;
    
    return 0;
  } if (argc == 3) {
    string command = argv[1];
    if (command == "--reverse") { // Checks the validity of additional command.
      string filename = argv[2];

      // Loads the movie into a list with movie_data pointer.
      List<pair<int, string>>* movie_data = loadMovie(filename);

      // Reverses the movie data into a list with pointer reverse_data.
      List<pair<int, string>>* reverse_data = reverse(movie_data);

      // Plays the ASCIImation in reverse order.
      playMovie(reverse_data);

      /* 
      ** Calls the deconstructor for the movie_data & reverse_data lists 
      ** to clear the memory.
      */
      delete movie_data;
      delete reverse_data;

      return 0;
    } else {
      throw runtime_error("Invalid command!");
    }
  } else {
    throw runtime_error("Invalid number of command-line arguments!");
  }
}
