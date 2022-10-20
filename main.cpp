#include <iostream>
#include <iomanip>

using namespace std;

// declare functions
void printMatrix(double grades[60][8], int nRows, int nCols);
void printLabels(string title);
void assignAvgGrd(double grades[60][8], int nRows);
void assignWgtGrd(double grades[60][8], int nRows);

int main() {
  const int nRows = 60;
  const int nCols = 8;
  string title;
  
  double grades[60][8] = { {1, 100, 100, 100, 100},
                           {2, 100, 0, 100, 0},
                           {3, 82, 94, 73, 86},
                           {4, 64, 74, 84, 94},
                           {5, 94, 84, 74, 64} };

  /*  for (int row = 5; row < nRows; row++){
        for (int col = 1; col < 5; col++){
          int temp;
          cin >> temp;
          grades[row][0] = (row + 1);
          grades[row][col] = temp;
        }
      }  */ 

  for (int row = 0; row < nRows; row++){
    int smallest = grades[row][1];
    for(int col = 1; col < 5; col++){
      if (grades[row][col] <= smallest)
         smallest = grades[row][col];
      grades[row][7] = smallest;
    }
  }

  
  assignAvgGrd(grades, nRows);
  assignWgtGrd(grades, nRows);
  printLabels(title);
  printMatrix(grades, nRows, nCols); 
}

/************** FUNCTIONS **************/
void printMatrix(double grades[60][8], int nRows, int nCols){
    int row, col;
    for (row = 0; row < nRows; row++)
    {
        for(col = 0; col < nCols; col++)
            cout << setw(8) << grades[row][col] << " ";

        cout << endl;    
    }
}

void printLabels(string title){
  for (int n = 1; n <= 8; n++){
    if (n == 1)
      title = "StuNum";
    else if (n == 2)
      title = "Test 1";
    else if (n == 3)
      title = "Test 2";
    else if (n == 4)
      title = "Test 3";
    else if (n == 5)
      title = "Test 4";
    else if (n == 6)
      title = "Avg Grd";
    else if (n == 7)
      title = "Wgt Grd";
    else if (n == 8)
      title = "AvgTop3";
    cout << setw(8) << title << " ";
  }
  cout << endl;
}

void assignAvgGrd(double grades[60][8], int nRows){
    for (int row = 0; row < nRows; row++){
      double sum = 0;
      double avg = 0;
      for (int col = 1; col < 5; col++)
        sum = sum + grades[row][col];
      avg = sum / 4;
      grades[row][5] = avg;
    }
}

void assignWgtGrd(double grades[60][8], int nRows){
    for (int row = 0; row < nRows; row++){
      double WgtGrd = 0;
        WgtGrd = ( (.2 * grades[row][1]) + (.3 * grades[row][2]) + (.3 * grades[row][3]) + (.2 * grades[row][4]));
      grades[row][6] = WgtGrd;
    }
}

void assignAvgTop3(){
    
}