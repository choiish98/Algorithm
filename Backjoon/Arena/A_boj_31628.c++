#include <iostream>
#define GRID 10

using namespace std;

int main() {
  string grid[GRID][GRID];
  bool flag = false; 

  for (int i = 0; i < GRID; i++) 
    for (int j = 0; j < GRID; j++) 
      cin >> grid[i][j];
  
  for (int i = 0; i < GRID; i++) {
    bool flag1 = true;
    bool flag2 = true;
    
    for (int j = 1; j < GRID; j++) {
      if (grid[i][0] != grid[i][j]) 
        flag1 = false;

      if (grid[0][i] != grid[j][i]) 
        flag2 = false;
    }
    
    if (flag1 || flag2) {
      flag = true;
      break;
    }
  }

  if (flag)
    cout << "1" << endl;
  else
    cout << "0" << endl;
  
  return 0;
}
