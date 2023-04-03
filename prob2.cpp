#include <bits/stdc++.h>
using namespace std;
int main_1(){
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 1; i < n ; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (n == 2){
        if(arr[1] == 2) cout << 1;
        else cout << 2;
    }
    else{
        for(int j = 2; j < n + 1; ++j){
        if(arr[j] != j){
            cout << j;
            exit(0);
        } 
    }
    }
}


// CÁCH 2



int main_2() {
    long long int n, input, sum = 0;
    cin >> n;

    for (int i = 0 ; i < n - 1 ; i++) {
        cin >> input;
        sum += input;
    }

    cout << ( n * (n + 1) ) / 2 - sum << endl;

    return 0;
}
