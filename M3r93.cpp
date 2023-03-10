#include <bits/stdc++.h>
const int MAX = 1e6;
using namespace std;
using namespace std::chrono;
double arr[MAX];
void merge( int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new double[subArrayOne],
         *rightArray = new double[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];
  
    auto indexOfSubArrayOne
        = 0, 
        indexOfSubArrayTwo
        = 0; 
    int indexOfMergedArray
        = left;
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int const begin, int const end)
{
    if (begin >= end)
        return; 
    auto mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}
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
            mergeSort( 0, size - 1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << i + 1 << " .Elapsed time: " << duration.count() << " milliseconds" << endl;
    }
}
