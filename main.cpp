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
#include <vector>


int main(int argc, char *argv[]) {
  if (argc == 0){ // If argv is empty...
    return 0;
  }
  else {
    std::ifstream infile; // Initialize file to be opened
    std::string filename = (((std::string)"testing_languages/") + argv[1]); // Get the file in the testing_languages folder
    std::string sentence;
    infile.open(filename); // Open the file
    if (!infile.fail()){
      char ch;
      while (infile.get(ch)){
        if ((int)ch >= 97 && (int)ch <= 122) {
        sentence += ch; // Add the character to the string
        }
        else if ((int)ch >= 65 && (int)ch <= 90) {
          ch += 32;
          sentence += ch;
        }
      }
      infile.close(); // Close the file
      }
    else { // If the file cannot be opened...
      std::cerr << "Could not open file: " << filename << std::endl; // Display error message
      exit(EXIT_FAILURE);
    }
    std::vector<int> map = trigrams(sentence); // Start the calculations of the language
      for (int i = 0; i < ((int)map.size()); i++) { // Iterate through the frequency map
          if (i == ((int)map.size())-1) { // If the frequency of the very last trigram...
            std::cout << map[i] << std::endl; // Display it with a new-line character
          }
          else {
              std::cout << map[i] << " "; // Display the current frequency separating each by a space
          }
      }
  }
  return 0;
}
