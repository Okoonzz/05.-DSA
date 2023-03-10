#include <bits/stdc++.h>
const int MAX = 1e6;
using namespace std;
double ran(){
  double r =  (double) (rand()) /  (float) (rand() + 0.1 );
  return r;
}
void increase(){
  double tmp = 0;
  for (int i = 0; i < MAX; i++){
    tmp += ran();
    cout << tmp << " ";
  }
  cout << endl;
}
void decrease(){
  double tmp = 0;
  for (int i = 0; i < MAX; i++){
    tmp -= ran();
    cout << tmp << " ";
  }
  cout << endl;
}
int main(){
  freopen("quick.txt", "w", stdout);
  srand((unsigned) time(NULL));
  increase();
  decrease();
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < MAX; j++){
      cout << ran() << " ";
    }
  cout << endl; 
  }
}
