#include <bits/stdc++.h>
const int MAX = 1e6;
using namespace std;
using namespace std::chrono;
double arr[MAX];
int main(){
    freopen("quick.txt", "r", stdin);
//  freopen("anss.txt", "w", stdout);
    for(int i = 0; i < 10; ++i){
        int size = 0;
        for(int j = 0; j < MAX; ++j){
            cin >> arr[j];
            ++size;
        }
        auto start = high_resolution_clock::now();
            sort(arr, arr + size);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << i + 1 << " .Elapsed time: " << duration.count() << " milliseconds" << endl;
    }
}
