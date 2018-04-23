/**
 * Started by Najib 3/21/18
 **/

///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"


int main(int argc, char *argv[]) {
  if (argc == 0){
    return 0;
  } else {
    std::string filename = "testing_languages/" + argv[1];
    std::ifstream infile(filename);
    char ch;
    if (!infile.fail()){
      while (infile.get(ch)){

      }
      infile.close();
  }
}
