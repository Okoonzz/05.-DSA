#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, x;
    cin >> n;
    map<long long, long long> m4p;
    for(int i = 0; i < n; i++){
        cin >> x;
        m4p[x]++;
    }
    cout << m4p.size();
}
