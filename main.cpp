/**
 * Started by Najib 3/21/18
 **/

///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>


int main(int argc, char *argv[]) {
  if (argc == 0){ // If argv is empty...
    return 0;
  }
  else {
    std::ifstream infile; // Initialize file to be opened
    std::string filename = "testing_languages/" + argv[0]; // Get the file in the testing_languages folder
    infile.open(filename); // Open the file
    std::vector<std::string>::iterator found;
    std::vector<std::string> excempt = [" ","!","?",".",","] // A list of charcters to excempt from the final string
    if (!infile.fail()){
      char ch;
      while (infile.get(ch)){
        found = (std::find(excempt.begin(),excempt.end(),char) != excempt.end()); // Check if the current character is in the character excempt list
        if (found == excempt.end()) { // If current character is not in the excempt vector...
          sentence += ch; // Add the character to the string
        }
      }
      infile.close(); // Close the file
      std::vector<int> map = freqMap(sentence); // Start the calculations of the language
      for (int i = 0; i < map.size(); i++) { // Iterate through the frequency map
          if (i == map.size()-1) { // If the frequency of the very last trigram...
            std::cout << map[i] << "\n"; // Display it with a new-line character
          }
          else {
            std::cout << map[i] << " "; // Display the current frequency separating each by a space
          }
      }
    }
    else { // If the file cannot be opened...
      std::cerr << "Could not open file: " << filename << std::endl; // Display error message
      exit(EXIT_FAILURE);
    }
  }
