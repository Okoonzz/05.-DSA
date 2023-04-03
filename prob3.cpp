#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin >> n;
    int cnt = 1;
    int result = 1;
    for(int i = 0; i < n.size(); ++i){
        if(n[i] == n[i+1]){
            cnt++;
        }
        else cnt = 1;
        result = max(cnt, result);
    }
    cout << result;
}
