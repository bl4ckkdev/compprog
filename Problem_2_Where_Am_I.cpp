#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n; cin >> n;

    string s; cin >> s;

    map<string, int> occ;

    for (int i = 0; i < n; i++) {
        string str = "";
        for (int j = i; j < n; j++) {
            str += s[j];
            
            //cout << str << " ";
            occ[str]++;
        }
    }

    

    //for (auto& i : occ) cout << i.first << " " << i.second << endl;

    int m = 0;
    for (const auto& i : occ) {
        if (i.second > 1) m = max(m, (int)i.first.length());
    }

    cout << m+1;
}