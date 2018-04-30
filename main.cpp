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
  std::vector<double> sumList = comp(argc,argv);
  if (!sumList.empty()) {
    int index = maxCalc(sumList);
    std::cout <<  argv[index+1] << std::endl;
  }
}
