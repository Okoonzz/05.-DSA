#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for(int i = 0; i < n; ++i){
        int st, ed;
        cin >> st >> ed;
        events.push_back({st, 1});
        events.push_back({ed, -1});
    }
    sort(events.begin(), events.end());
    int total = 0;
    int result = 0;
    for(int i = 0; i < events.size(); ++i){
        total += events[i].second;
        result = max(total, result);
    }
    cout << result;
}
