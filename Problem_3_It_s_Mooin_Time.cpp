#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, f; cin >> n >> f;

    string s; cin >> s;

    map<string, pair<int, vector<string>>> thr;

    string d = "";
    for (int i = 0; i < n-2; i++) {
        string comb = ((d + s[i]) + s[i+1]) + s[i+2];
        thr[comb].first++;
        if (i>1) thr[comb].second.push_back((((d + s[i-2]) + s[i-1]) + s[i]) + s[i+1]);
        else if (i>0) thr[comb].second.push_back(((d + s[i-1]) + s[i]) + s[i+1]);
    }

    set<string> setsts;

    for (auto& i : thr) {
        string ab = i.first;

        for (int j = 0; j < 26; j++) {
            
            ab[0] = 97+j;
            bool mino = false;
            
            if (i.first[0] == ab[0]) mino = true;
            if (ab[0] == ab[1] || ab[1] != ab[2]) continue;

            if ((thr.count(ab)>0 && thr[ab].first+1-mino>=f) || f == 1 && thr.count(ab) == 0) {
                if (thr[i.first].second.size() == 0) {
                    setsts.insert(ab);
                }

                for (string& k : thr[i.first].second) {
                    if (k.find(ab) == std::string::npos) {
                        setsts.insert(ab);
                        break;
                    } 
                }
            } 
        }
    }

    cout << setsts.size() << "\n";

    for (auto& i : setsts) cout << i << endl;
}