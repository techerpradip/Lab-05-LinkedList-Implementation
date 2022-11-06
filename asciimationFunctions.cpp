/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

// Loads an ASCIImation file, returning a list of frames.
List<pair<int, string>>* loadMovie(string filename) {
  ifstream ascfile;
  ascfile.open(filename);
  string sframe_length;
  string frame_contents;
  string data;
  
  if(!ascfile.is_open()) { // Checks the validity of the given filename.
    throw runtime_error("file " + filename + "failed to open ");
  }

  getline(ascfile, sframe_length);

  // Creates a pointer to a new dynamic linked-list of frames.
  List<pair<int,string>>* framesLinkedList = new LinkedList<pair<int,string>>();

  while (!ascfile.eof()) { // Checks the end of the file.
    int count = 0;
    int frame_length = stoi(sframe_length);
    
    //add data of one frame (frame's contents) into a string.
    while (count < 13){
      getline(ascfile, data);
      frame_contents += data + "\n";
      count += 1;
    }

    // creates a pair object with frame's length and frame's contents.
    pair<int,string> f1(frame_length, frame_contents);

    // Adds the frame-pair at the end of the frame LinkedList.
    framesLinkedList->insertLast(f1);

    getline(ascfile, sframe_length);
    frame_contents = ""; // Clears the frame_contents to store new frame data.
  } 

  // Returns a pointer to the list that contains the data.
  return framesLinkedList; 
}


// Plays an ASCIImation from the provided list.
void playMovie(List<pair<int, string>>* list) {
  system("clear"); // Clears the terminal after we call our commands.

  while (list->getSize() != 0) {

    // gets the first frame pair of the ASCIImation.
    pair<int, string> frame_pair = list->removeFirst();

    string movie_frame = frame_pair.second; // an specific frame.
    int frame_time = frame_pair.first; // time of that specific frame.

    cout << movie_frame << endl; // prints the frame in the terminal.
    usleep((1000000/15)*frame_time); // freezes the terminal for given time.
    system("clear"); // clears the terminal for next frame to be played.
  }
}