/**
 * Started by Najib 3/21/18
 **/


///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"
#include <stdlib.h>
#include <math.h>



///////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS GO HERE
///////////////////////////////////////////////////////////////////

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
