#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> children(n);
    for(int i = 0; i < n; ++i) cin >> children[i];
    sort(children.begin(), children.end());
    int i = 0, cnt = 0;
    int j = n - 1;
    while(i <= j){
        if(children[i] + children[j] > x){
            j--;
            cnt++;
        }
        else{
            i++;
            j--;
            cnt++;
        }
    }
    cout << cnt;
}
