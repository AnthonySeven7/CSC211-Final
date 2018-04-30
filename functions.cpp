/**
 * Started by Najib 3/21/18
 **/


///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"
#include <stdlib.h>
#include <cmath>



///////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS GO HERE
///////////////////////////////////////////////////////////////////

double calculations(std::vector<int> map1,std::vector<int> map2) {
  bigint numerator = 0;
  bigint denominator1 = 0;
  bigint denominator2 = 0;
  bigint denominator = 0;
  for (size_t i = 0; i < (map1.size()-1); i++) {
    numerator += (bigint)map1[i] * (bigint)map2[i];
    denominator1 += pow(map1[i],2);
    denominator2 += pow(map2[i],2);
  }
  denominator = (denominator1 * denominator2);
  numerator = numerator*numerator;
  std::string temp1 = numerator.to_string();
  std::string temp2 = denominator.to_string();
  double d1 = std::stod(temp1);
  double d2 = std::stod(temp2);
  double answer = d1/d2;
  answer = sqrt(answer);
  std::cout << "answer: " << answer << std::endl;
  return answer;
}

std::string fileopen(char *filename_var) {
  std::ifstream infile; // Initialize file to be opened
  std::string filename = (((std::string)filename_var)); // Get the file in the testing_languages folder
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
  return sentence;
}

std::vector<double> comp(int argc, char *argv[]){
  std::vector<double> compare;
  if (argc == 0){ // If argv is empty...
    return compare;
  }
  else {
    std::string sentence;
    sentence = fileopen(argv[argc-1]); // Open the file to compare everything to
    std::vector<int> map1 = trigrams(sentence); // Start the calculations of the language
    if (argc == 1) {
      for (int i = 0; i < ((int)map1.size()); i++) { // Iterate through the frequency map
        if (i == ((int)map1.size())-1) { // If the frequency of the very last trigram...
          std::cout << map1[i] << std::endl; // Display it with a new-line character
        }
        else {
          std::cout << map1[i] << " "; // Display the current frequency separating each by a space
        }
      }
    }
    if (argc > 1) { // User wants to compare
      for (int i = 1; i < argc-1; i++) { // Iterate through each test language
        sentence = fileopen(argv[i]); // Open the file to compare everything to
        std::vector<int> map2 = trigrams(sentence); // Start the calculations of the language
        double answer = calculations(map1,map2);
        compare.push_back(answer);
        std::cout << compare[i-1] << std::endl;
      }
      return compare;
    }
  }
  return compare;
}

int maxCalc(std::vector<double> setList) {
  std::cout << "maxCalc" << std::endl;
  double max = setList[0];
  int index = 0;
  for (int n = 0; n <= (int)setList.size()-1;n ++) {
    if (max < setList[n]) {
      max = setList[n];
      index = n;
      std::cout << setList[n] << std::endl;
    }
  }
  return index;
}

int freqCalc(std::string trigram) { // Calculate all the frequencies
  // Input: A map of all the trigrams Ex: ["abc","bcd","cde",...]
  // Output: A vetor of the all the calculated frequencies in the language Ex: [0,1,2,...]
  int frequency = 0; // An integer to get the summation of each trigrams letter
  int num = 2;
  for (int n = 0; n < 3; n ++) { // Iterate through the entire trigram
    frequency += (((int)(trigram[n]%97))*(pow(26,num))); //Add calculated frequency to the variable frequency
    num --;
  }
  return frequency;
}

std::vector<int> trigrams(const std::string language){ // Calculate all of the trigrams in the selected language
  // Input: The selected language
  // Output: An array of all the trigrams in the selected language Ex: ['abc','bcd','cde',...]
  // Initialize Variables
  std::vector<int> map(17575,0); // Initialize empty vector map of each possible frequency of trigram
  std::string trigram = ""; // String to hold each trigram
  int freq;
  for (int i = 0; i < ((int)language.size())-2; i++) { // Iterate through each letter in the selected language minus the final two as that will not be a trigram
    trigram += language[i]; // Add the current letter to trigram
    trigram += language[i+1]; // Add the next letter to trigram
    trigram += language[i+2]; // Add the final letter to the trigram
    freq = freqCalc(trigram);
    map[freq] += 1;
    trigram = ""; // Reset trigram
  }
  return map; // Return the map with all of the frequencies
}
