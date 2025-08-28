#include <bits/stdc++.h>
using namespace std;

vector<pair<string, string>> c;

vector<string> cows = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
vector<string> corseq;

void check(vector<string> s, int j) {
    if (j == cows.size()) {
        //for (auto& i : s) cout << i << " ";
        //cout << endl;

        bool cookad = true;

        for (int i = 0; i < c.size(); i++) {
            for (int k = 0; k < cows.size(); k++) {
                cookad = false;
                
                if (c[i].first == s[k]) {
                    cookad = true;
                    if (k>0 && s[k-1] == c[i].second) {
                        cookad = false;
                    } 
                    if (k<cows.size()-1 && s[k+1] == c[i].second) cookad = false;
                }

                if (cookad) break;
            }
            if (cookad) break;
        }

        if (!cookad) {
            if (corseq.size() > 0) {
                bool b = 1;
                bool t = 0;

                for (int i = 0; i < 8; i++) {
                    if (s[i] == "Belinda" && corseq[i] == "Bella") {
                        b = 0;
                        t = 1;
                        break;
                    }
                    else if (corseq[i] == "Belinda" && s[i] == "Bella") {
                        b = 1;
                        t = 1;
                        break;
                    } else
                    for (int k = 0; k < 3; k++) {
                        if (s[i][k] < corseq[i][k]) {
                            b = 0;
                            t = 1;
                            break;
                        } else if (s[i][k]>corseq[i][k]) {
                            b = 1;
                            t = 1;
                            break;
                        }
                    }
                    if (t) break;
                }

                if (!b) corseq = s;

            } else corseq = s;
        }

        return;
    }

    for (int i = 0; i < cows.size(); i++) {
        bool cooked = 0;
        for (int k = 0; k < s.size(); k++) {
            if (cows[i] == s[k]) {
                cooked = true;
                break;
            }
        }

        if (cooked) continue;

        vector<string> s2 = s;

        s2.push_back(cows[i]);

        check(s2, j+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n; cin >> n;

    c = vector<pair<string, string>>(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
        
        cin.ignore(23);
        cin >> c[i].second;
    }

    check(vector<string>(0), 0);

    for (auto& i : corseq) {
        cout << i << endl;
    }
}