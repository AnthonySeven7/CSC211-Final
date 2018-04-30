/**
 * Started by Najib 3/21/18
 **/

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "bigint/bigint.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

///////////////////////////////////////////////////////////////////
// FUNCTION HEADERS GO HERE
///////////////////////////////////////////////////////////////////
std::string fileopen(char *filename_var);
double calculations(std::vector<int> map1,std::vector<int> map2);
std::vector<double> comp(int argc, char *argv[]);
std::vector<int> trigrams(const std::string language);
int freqCalc(const std::string trigram);
int maxCalc(std::vector<double> setList);
#endif
