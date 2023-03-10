#include <bits/stdc++.h>
const int MAX = 1e6;
using namespace std;
using namespace std::chrono;
double arr[MAX];
void heapify( int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify( N, largest);
    }
}
void heapSort( int N)
{
 
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify( N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify( i, 0);
    }
}
int  main(){
    freopen("quick.txt", "r", stdin);
//  freopen("anss.txt", "w", stdout);
    for(int i = 0; i < 10; ++i){
        int size = 0;
        for(int j = 0; j < MAX; ++j){
            cin >> arr[j];
            ++size;
        }
        auto start = high_resolution_clock::now();
            heapSort( size);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << i + 1 << " .Elapsed time: " << duration.count() << " milliseconds" << endl;
    }
}
