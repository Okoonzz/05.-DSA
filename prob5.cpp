#include <bits/stdc++.h>
using namespace std;
void Permutations(long long n){
    if (n == 1){
        cout << 1;
        exit(0);
    }
    else if(n <= 3){
        cout << "NO SOLUTION";
        exit(0);
    } 
 
    else if(n == 4){
        cout << "2 4 1 3";
        exit(0);
    } 

    else{
        int even = 2;
        while(even <= n){
            cout << even << " ";
            even += 2;
        }
        int odd = 1;
        while(odd <= n){
            cout << odd << " ";
            odd += 2;
        }
    } 
}

int main(){
    long long n;
    cin >> n;
    Permutations(n);
}
