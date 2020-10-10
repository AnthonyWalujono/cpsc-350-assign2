#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "GenGrid.h"
//#include "Game.h"
using namespace std;
/*
string fileName;
int r;
int c;
string row;
string column;
string cellString;
string userAnswer;
char cellChar;
char inputChar;
bool processCont = true;
ifstream inputFile;
ofstream outputFile;
GenGrid :: GenGrid(int row, int column){
  grid = new char*[row];
  for(int i = 0; i < row; i++){
  grid[i] = new char[column];
}

}
GenGrid :: ~GenGrid{
  delete grid;
}
void GenGrid :: buildGrid(int row, int column) {
  do{
    for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
         inputFile.get(cellChar);
         if(cellChar != '\n' && cellChar != '\0'){
           grid[i][j] = cellChar;
         }
         else{
           j--;
         }
      }
      inputFile.get(cellChar);
    }
    break;
  }
  while(inputFile.peek() != EOF);
}
/*void GenGrid :: printGrid(){

}*/
GenGrid :: GenGrid(int row, int column){
  grid = new char*[row];
  for(int i = 0; i < row; i++){
    grid[i] = new char*[column];
  }
}
GenGrid :: ~GenGrid(){
  delete grid;
}
void GenGrid::GenClassicMode(int r, int c, char**grid) {
  ofstream outputFile;
  int neighborCount = 0;
  int deadCells = 0;
  int gridSize = r*c;
  bool notEqual = true;
  bool allDead = false;
  outputFile.open("anthony.txt");
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      outputFile << grid[i][j];
    }
    outputFile << '\n';
  }
  outputFile << "Classic Mode Output:"<< endl;
  do{
  char newGrid[r][c];
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      //for the very left top corner
      if(i == 0 && j == 0){
        if(grid[i + 1][j] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j + 1] != '-'){
          neighborCount++;
        }
      }
      //for top row
      else if(i == 0 && (j > 0 && j < c-1)){
        if(grid[i][j-1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j-1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j + 1] != '-'){
          neighborCount++;
        }
      }
      //top right corner
      else if(i == 0 && j == c-1){
        if(grid[i][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j] != '-'){
          neighborCount++;
        }
      }
      //first column
      else if((i > 0 && i < r-1) && j == 0){
        if(grid[i - 1][j] != '-'){
          neighborCount++;
        }
        if(grid[i - 1][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j] != '-'){
          neighborCount++;
        }
      }
      // all columns that is not first and last
      else if((i > 0 && i < r-1) && (j > 0 && j < c-1)){
        if(grid[i - 1][j] != '-'){
          neighborCount++;
        }
        if(grid[i - 1][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i - 1][j - 1] != '-'){
          neighborCount++;
        }
      }
      //last column
      else if((i > 0 && i < r-1) && j == c-1){
        if(grid[i-1][j] != '-'){
          neighborCount++;
        }
        if(grid[i - 1][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i + 1][j] != '-'){
          neighborCount++;
        }
      }
      //very left bottom corner
      else if(i == r-1 && j == 0){
        if(grid[i - 1][j] != '-'){
          neighborCount++;
        }
        if(grid[i - 1][j + 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j + 1] != '-'){
          neighborCount++;
        }
      }
      //last row
      else if(i == r-1 && (j > 0 && j < c-1)){
        if(grid[i][j-1] != '-'){
          neighborCount++;
        }
        if(grid[i-1][j-1] != '-'){
          neighborCount++;
        }
        if(grid[i-1][j-1] != '-'){
          neighborCount++;
        }
        if(grid[i-1][j] != '-'){
          neighborCount++;
        }
        if(grid[i-1][j+1] != '-'){
          neighborCount++;
        }
        if(grid[i][j+1] != '-'){
          neighborCount++;
        }
      }
      // very right bottom corner
      else if(i == r-1 && j == c-1){
        if(grid[i - 1][j] != '-'){
          neighborCount++;
        }
        if(grid[i - 1][j - 1] != '-'){
          neighborCount++;
        }
        if(grid[i][j - 1] != '-'){
          neighborCount++;
        }
      }
      //Check to determine if section is alive/dead
      if(grid[i][j] != '-'){
        if(neighborCount == 3 || neighborCount == 2){
          newGrid[i][j] = 'X';
        }
        else{
          newGrid[i][j] = '-';
        }
      }
      else{
        if(neighborCount == 3){
          newGrid[i][j] = 'X';
        }
        else{
          newGrid[i][j] = '-';
        }
      }
      outputFile << newGrid[i][j];
      neighborCount = 0;
    }
    outputFile << "\n";
  }
  //compare old and new grid
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(grid[i][j] != newGrid[i][j]){
        notEqual = true;
        i = r;
        j = c;
      }
    }
  }
  //counts dead cells
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(newGrid[i][j] == '-'){
        deadCells++;
      }
    }
  }
  //check if new grid is all dead cells.
  if(deadCells == gridSize){
    allDead = true;
  }
} while(!allDead && notEqual);
}
int main(){
  string fileName;
  int r;
  int c;
  string row;
  string column;
  string cellString;
  string userAnswer;
  char cellChar;
  char inputChar;
  bool processCont = true;
  ifstream inputFile;
  ofstream outputFile;
  string userChoice;
  int userRow;
  int userCol;
  int randRow;
  int randCol;
  double userDec;
  double popDensity;
  string gridChoice;
  GenGrid *genGridPtr = new GenGrid();
  cout << "Do you want to start with random configuration (1) or use a file (2):" << endl;
  cout << "Please enter 1 or 2: " << endl;
  cin >> userChoice;
  //Generate Random configuration
  if (userChoice.compare("1") == 0){
    cout << "Enter a row:" << endl;
    cin >> userRow;
    cout << "Enter a column:" << endl;
    cin >> userCol;
    cout << "Enter a decimal:" << endl;
    cin >> userDec;
    popDensity = (userRow*userCol)*userDec;
    int popDen = int (popDensity);
    //generate grid into an input file
    char randGrid[userRow][userCol];
    for(int i = 0; i < userRow; i++){
      for(int j = 0; j < userCol; j++){
        randGrid[i][j] = '-';
      }
    }
    //generate random population grid
    for(int c = 0; c < popDen; c++){
      do{
        randRow = rand() % userRow;
        randCol = rand() % userCol;
      } while(randGrid[randRow][randCol] == 'X');
      randGrid[randRow][randCol] = 'X';
    }
    //output the random grid
    for(int i = 0; i < userRow; i++){
      for(int j = 0; j < userCol; j++){
        cout << randGrid[i][j];
      }
      cout << "\n";
    }
  }
  //Generate Grid from Input File
  else{
  while(processCont){
    cout << "Please enter a file name." << endl;
    cin >> fileName;
    inputFile.open(fileName);
    //Check if the file exists
    if(inputFile.fail()) {
      cout << "File not Does not exists \n";
      exit (1);
    }
    //outputFile.open("anthony.txt");
    getline(inputFile, row);
    getline(inputFile, column);
    r = stoi(row);
    c = stoi(column);
    char grid[r][c];
    int gridSize;
    gridSize = r*c;
    //Filling the grid character by character on input file
    do{
      for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
           inputFile.get(cellChar);
           if(cellChar != '\n' && cellChar != '\0'){
             grid[i][j] = cellChar;
           }
           else{
             j--;
           }
        }
        inputFile.get(cellChar);
      }
      break;
    }  while(inputFile.peek() != EOF);
    //display grid from input file
    /*
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        outputFile << grid[i][j];
      }
      outputFile << '\n';
    }*/
    //char newGrid[r][c];
    // Prompt user for boundary mode.
    //bool notEqual = true;
    //bool allDead = false;
    cout << "Which mode do you want to use: Classic (1), Doughnut (2), Mirror (3)?" << endl;
    cin >> gridChoice;
    if(gridChoice.compare("1") == 0){
      genGridPtr->GenClassicMode(r, c, grid);
    }
    //Generate Classic Mode - move to a new class later
    /*
    outputFile << "Classic Mode:"<< endl;
    int neighborCount = 0;
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        //for the very left top corner
        if(i == 0 && j == 0){
          if(grid[i + 1][j] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j + 1] != '-'){
            neighborCount++;
          }
        }
        //for top row
        else if(i == 0 && (j > 0 && j < c-1)){
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j + 1] != '-'){
            neighborCount++;
          }
        }
        //top right corner
        else if(i == 0 && j == c-1){
          if(grid[i][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j] != '-'){
            neighborCount++;
          }
        }
        //first column
        else if((i > 0 && i < r-1) && j == 0){
          if(grid[i - 1][j] != '-'){
            neighborCount++;
          }
          if(grid[i - 1][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j] != '-'){
            neighborCount++;
          }
        }
        // all columns that is not first and last
        else if((i > 0 && i < r-1) && (j > 0 && j < c-1)){
          if(grid[i - 1][j] != '-'){
            neighborCount++;
          }
          if(grid[i - 1][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i - 1][j - 1] != '-'){
            neighborCount++;
          }
        }
        //last column
        else if((i > 0 && i < r-1) && j == c-1){
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i - 1][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i + 1][j] != '-'){
            neighborCount++;
          }
        }
        //very left bottom corner
        else if(i == r-1 && j == 0){
          if(grid[i - 1][j] != '-'){
            neighborCount++;
          }
          if(grid[i - 1][j + 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j + 1] != '-'){
            neighborCount++;
          }
        }
        //last row
        else if(i == r-1 && (j > 0 && j < c-1)){
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }

        }
        // very right bottom corner
        else if(i == r-1 && j == c-1){
          if(grid[i - 1][j] != '-'){
            neighborCount++;
          }
          if(grid[i - 1][j - 1] != '-'){
            neighborCount++;
          }
          if(grid[i][j - 1] != '-'){
            neighborCount++;
          }
        }
        //Check to determine if section is alive/dead
        if(grid[i][j] != '-'){
          if(neighborCount == 3 || neighborCount == 2){
            newGrid[i][j] = 'X';
          }
          else{
            newGrid[i][j] = '-';
          }
        }
        else{
          if(neighborCount == 3){
            newGrid[i][j] = 'X';
          }
          else{
            newGrid[i][j] = '-';
          }
        }
        outputFile << newGrid[i][j];
        neighborCount = 0;
      }
      outputFile << "\n";
    }
  }
  //Inplement Doughnut Mode Option
  else if(gridChoice.compare("2") == 0){
    int neighborCount = 0;
    outputFile << "Doughnut Mode:"<< endl;
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        //top left corner
        if(i == 0 && j == 0){
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j] != '-'){
            neighborCount++;
          }
          if(grid[i][c-1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][c-1] != '-'){
            neighborCount++;
          }
          if(grid[r-1][c-1] != '-'){
            neighborCount++;
          }
          if(grid[r-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[r-1][j] != '-'){
            neighborCount++;
          }
        }
          //top row of Grid
          else if(i == 0 && (j > 0 && j < c-1)){
            if(grid[r-1][j-1] != '-'){
              neighborCount++;
            }
            if(grid[i][j-1] != '-'){
              neighborCount++;
            }
            if(grid[i+1][j-1] != '-'){
              neighborCount++;
            }
            if(grid[i+1][j] != '-'){
              neighborCount++;
            }
            if(grid[i+1][j+1] != '-'){
              neighborCount++;
            }
            if(grid[i][j+1] != '-'){
              neighborCount++;
            }
            if(grid[r-1][j+1] != '-'){
              neighborCount++;
            }
            if(grid[r-1][j] != '-'){
              neighborCount++;
            }
          }
          //top right corner
          else if(i == 0 && j == c-1){
            if(grid[i][j-1] != '-'){
              neighborCount++;
            }
            if(grid[i+1][j-1] != '-'){
              neighborCount++;
            }
            if(grid[i+1][j] != '-'){
              neighborCount++;
            }
            if(grid[i+1][0] != '-'){
              neighborCount++;
            }
            if(grid[i][0] != '-'){
              neighborCount++;
            }
            if(grid[r-1][0] != '-'){
              neighborCount++;
            }
            if(grid[r-1][j] != '-'){
              neighborCount++;
            }
            if(grid[r-1][j-1] != '-'){
              neighborCount++;
            }
          }
        //left column
        else if((i > 0 && i < r-1) && j == 0){
          if(grid[i+1][j] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][c-1] != '-'){
            neighborCount++;
          }
          if(grid[i][c-1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][c-1] != '-'){
            neighborCount++;
          }
        }
        //rows that do not touch end of grid
        else if((i > 0 && i < r-1) && (j > 0 && j < c-1)){
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
        }
        //right column
        else if((i > 0 && i < r-1) && j == c-1){
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][0] != '-'){
            neighborCount++;
          }
          if(grid[i][0] != '-'){
            neighborCount++;
          }
          if(grid[i+1][0] != '-'){
            neighborCount++;
          }
        }
        //bottom left corner
        else if(i == r-1 && j == 0){
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][c-1] != '-'){
            neighborCount++;
          }
          if(grid[i][c-1] != '-'){
            neighborCount++;
          }
          if(grid[0][c-1] != '-'){
            neighborCount++;
          }
          if(grid[0][j] != '-'){
            neighborCount++;
          }
          if(grid[0][j+1] != '-'){
            neighborCount++;
          }
        }
        //bottom row
        else if(i == r-1 && (j > 0 && j < c-1)){
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[0][j-1] != '-'){
            neighborCount++;
          }
          if(grid[0][j] != '-'){
            neighborCount++;
          }
          if(grid[0][j+1] != '-'){
            neighborCount++;
          }
        }
        //bottom right corner
        else if(i == r-1 && j == c-1){
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[0][j-1] != '-'){
            neighborCount++;
          }
          if(grid[0][j] != '-'){
            neighborCount++;
          }
          if(grid[0][0] != '-'){
            neighborCount++;
          }
          if(grid[i][0] != '-'){
            neighborCount++;
          }
          if(grid[i-1][0] != '-'){
            neighborCount++;
          }
        }
        if(grid[i][j] != '-'){
          if(neighborCount == 3 || neighborCount == 2){
            newGrid[i][j] = 'X';
          }
          else{
            newGrid[i][j] = '-';
          }
        }
        else{
          if(neighborCount == 3){
            newGrid[i][j] = 'X';
          }
          else{
            newGrid[i][j] = '-';
          }
        }
        outputFile << newGrid[i][j];
        neighborCount = 0;
      }
      outputFile << "\n";
    }
  }
  //Implementing Mirror Mode Option
  else{
    int neighborCount = 0;
    outputFile << "Mirror Mode: " << endl;
    //char newGrid[r][c];
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        //top left corner
        if(i == 0 && j == 0){
          if(grid[i][j] != '-'){
            neighborCount += 3;
          }
          if(grid[i][j+1] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j] != '-'){
            neighborCount += 2;
          }
        }
        //top row
        else if(i == 0 && (j > 0 && j < c-1)){
          if(grid[i][j] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount += 2;
          }
          if(grid[i][j+1] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j+1] != '-'){
            neighborCount++;
          }
        }
        //top right corner
        else if(i == 0 && j == c-1){
          if(grid[i][j] != '-'){
            neighborCount += 3;
          }
          if(grid[i][j-1] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j-1] != '-'){
            neighborCount++;
          }
        }
        //first column
        else if((i > 0 && i < r-1) && j == 0){
          if(grid[i][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
        }
        //no corners
        else if((i > 0 && i < r-1) && (j > 0 && j < c-1)){
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j] != '-'){
            neighborCount++;
          }
          if(grid[i+1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
        }
        //right column
        else if((i > 0 && i < r-1) && j == c-1){
          if(grid[i][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j] != '-'){
            neighborCount += 2;
          }
          if(grid[i+1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
        }
        //left bottom corner
        else if(i == r-1 && j == 0){
          if(grid[i][j] != '-'){
            neighborCount += 3;
          }
          if(grid[i][j+1] != '-'){
            neighborCount += 2;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount += 2;
          }
        }
        //bottom row
        else if(i == r-1 && (j > 0 && j < c-1)){
          if(grid[i][j] != '-'){
            neighborCount++;
          }
          if(grid[i][j-1] != '-'){
            neighborCount += 2;
          }
          if(grid[i][j+1] != '-'){
            neighborCount += 2;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j] != '-'){
            neighborCount++;
          }
          if(grid[i-1][j+1] != '-'){
            neighborCount++;
          }
        }
        //right bottom corner
        else if(i == r-1 && j == c-1){
          if(grid[i][j] != '-'){
            neighborCount += 3;
          }
          if(grid[i][j-1] != '-'){
            neighborCount += 2;
          }
          if(grid[i-1][j] != '-'){
            neighborCount += 2;
          }
          if(grid[i-1][j-1] != '-'){
            neighborCount++;
          }
        }
        if(grid[i][j] != '-'){
          if(neighborCount == 3 || neighborCount == 2){
            newGrid[i][j] = 'X';
          }
          else{
            newGrid[i][j] = '-';
          }
        }
        else{
          if(neighborCount == 3){
            newGrid[i][j] = 'X';
          }
          else{
            newGrid[i][j] = '-';
          }
        }
        outputFile << newGrid[i][j];
        neighborCount = 0;
      }
      outputFile << "\n";
    }
  }
  //compare previous grid with the new grid
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(grid[i][j] != newGrid[i][j]){
        notEqual = true;
        i = r;
        j = c;
      }
    }
  }
  //Put this process inside of each of the mode choices
  int deadCells = 0;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(newGrid[i][j] == '-'){
        deadCells++;
      }
    }
  }
  if(deadCells == gridSize){
    allDead = true;
  }
while(!allDead && notEqual);
*/
    processCont = false;
  }
}
  inputFile.close();
  outputFile.close();
  return 0;
}
