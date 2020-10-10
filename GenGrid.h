#include <iostream>
using namespace std;
class GenGrid{
public:
  GenGrid(); //default constructor
  GenGrid(int row, int column); //overload constructor
  ~GenGrid(); //destructor
  void buildGrid(int row, int column);
  void GenClassicMode(int row, int column, char**grid);
  //void printGrid();
  int r;
  int c;
  double dec;
  double popDensity;
private:
  char** grid; //pointer
};
