#include <bits/stdc++.h>
const int MAX = 1e6;
using namespace std;
using namespace std::chrono;
double arr[MAX];
void quickSort(int left, int right) {
    int i = left, j = right;
    double pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort( left, j);
    }
    if (i < right) {
        quickSort(i, right);
    }
}
int main()
{ 
    freopen("quick.txt", "r", stdin);
//  freopen("anss.txt", "w", stdout);
    for(int i = 0; i < 10; ++i){
        int size = 0;
        for(int j = 0; j < MAX; ++j){
            cin >> arr[j];
            ++size;
        }
        auto start = high_resolution_clock::now();
            quickSort(0, size-1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << i + 1 << " .Elapsed time: " << duration.count() << " milliseconds" << endl;
    }
}
