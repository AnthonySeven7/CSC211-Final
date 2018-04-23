/**
 * Started by Najib 3/21/18
 **/


///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"
#include <vector>
#include <string>


///////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS GO HERE
///////////////////////////////////////////////////////////////////

std::vector<std::string> trigrams(const std::string language){ // Calculate all of the trigrams in the selected language
  // Input: The selected language
  // Output: An array of all the trigrams in the selected language Ex: ['abc','bcd','cde',...]
  // Initialize Variables
  std::vector<std::string> tri_map; // Vector to hold all trigrams calculated
  std::string trigram = ""; // String to hold each trigram
  for (int i = 0; i < language.length()-3; i++) { // Iterate through each letter in the selected language minus the final two as that will not be a trigram
    trigram += language[i]; // Add the current letter to trigram
    trigram += language[i+1]; // Add the next letter to trigram
    trigram += language[i+2]; // Add the final letter to the trigram
    tri_map.pushback(trigram); // Add trigram to trigram map
    trigram = ""; // Reset trigram
  }
  return tri_map; // Return the map of all trigrams
}

std::vector<int> freqCalc(const std::vector<std::string> tri_map) { // Calculate all the frequencies
  // Input: A map of all the trigrams Ex: ["abc","bcd","cde",...]
  // Output: A vetor of the all the calculated frequencies in the language Ex: [0,1,2,...]
  std::vector<int> freq_map; // An empty vector that will hold all trigram frequencies for the given language
  int frequency = 0; // An integer to get the summation of each trigrams letter
  int letter_freq; // An integer to represent the frequency the individual trigrams
  for (int i= 0; i < tri_map.size(); i ++) { // Iterate through the entire trigram map
    trigram = tri_map[i]; // Call the current trigram
    for (int n = 2; n >= 0; n --) { // Iterate through the entire trigram
      letter_freq = (atoi(trigram[n])); // Convert the letter in the trigram into its ascii value
      if (letter_freq < 91) letter_freq += 32; // If current letter is capital, convert the ascii of the capital letter t the ascii of its lowercase equivalent
      letter_freq = (letter_freq % 97); // Convert the ascii value of the letter to its position in the alphabet
      frequency += (letter_freq*(26^(n))); //Add calculated frequency to the variable frequency
    }
    freq_map.push_back(frequency); // Add the frequency to the frequency map
    frequency = 0; // Reset the variable frequency
  }
  return freq_map; // Return the frequency map
}

std::vector<int> freqMap(const std::string language) {
  std::vector<int> map(308915776); // Initialize empty vector map of each possible frequency of trigram
  tri_map = trigrams(language); // Calculate trigrams
  freq_map = freqCalc(tri_map); // Calculate frequencies
  for (int i = 0; i < freq_map.size(); i ++) { // Iterate through each frequency that was calculated
    map[freq_map[i]] += 1; // Go through the map and add one to any place where the frequency exists on the frequency map
  }
  return map; // Return the map with all of the frequencies
}
