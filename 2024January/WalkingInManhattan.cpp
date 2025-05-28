#include <iostream>
#include <vector>
using namespace std;


struct Road {
  char dir; 
  int coord; 
};


struct Cow {
  int x, y; 
  int t; 
};

int main() {
  
  int N, Q;
  cin >> N >> Q;

  
  vector<Road> roads(N);
  vector<Cow> cows(Q);

  
  for (int i = 0; i < N; i++) {
    cin >> roads[i].dir >> roads[i].coord;
  }

  
  for (int i = 0; i < Q; i++) {
    cin >> cows[i].x >> cows[i].y >> cows[i].t;
  }

  
  for (int i = 0; i < Q; i++) {
    
    int x = cows[i].x;
    int y = cows[i].y;
    int t = cows[i].t;
    char dir = 'E'; 
    for (int j = 0; j < N; j++) {
      if (roads[j].dir == 'V' && roads[j].coord == x) {
        dir = 'N';
        break;
      }
    }

    
    for (int k = 0; k < t; k++) {
      
      for (int j = 0; j < N; j++) {
        
        if (roads[j].dir == 'H' && roads[j].coord == y && (k + 1) % 2 == 0) {
          dir = 'E';
          break;
        }
        
        else if (roads[j].dir == 'V' && roads[j].coord == x && (k + 1) % 2 == 1) {
          dir = 'N';
          break;
        }
      }
      if (dir == 'E') {
        x++;
      }
      
      else if (dir == 'N') {
        y++;
      }

      
      
    }

    
    cout << x << " " << y << endl;
  }

  return 0;
}