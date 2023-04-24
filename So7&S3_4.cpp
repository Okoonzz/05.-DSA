#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> tickets(n);
    vector<int> customers(m);
    set<pair<int, int>> sortTed;

    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
        sortTed.insert({tickets[i], i});
    }
     for (int i = 0; i < m; i++) {
        cin >> customers[i];
    }
    for (int i = 0; i < m; i++) {
        auto match = sortTed.lower_bound({customers[i]+1, 0});
        if(match == sortTed.begin()) {
         cout << -1 << '\n';
        }
        else{
         match--;
         cout << match->first << '\n';
         sortTed.erase(match);
        }
    }

    return 0;
}
