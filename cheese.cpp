#include <bits/stdc++.h>

using namespace std;
bool seet(int st, int val, map<int, int>& isOdd, vector<long long>& opposites, vector<long long>& sames) {
    isOdd[st] = val;

    for (int i = 0; i < opposites.size(); i++) {
        if (isOdd.count(opposites[i]) && isOdd[opposites[i]] == isOdd[st]) {
            return false;
        }

        seet(opposites[i], 1-val, isOdd, opposites[opposites[i]], sames[opposites[i]]);
    }

    for (int i = 0; i < sames.size(); i++) {
        if (isOdd.count(sames[i]) && isOdd[sames[i]] != isOdd[st]) {
            return false;
        }

        seet(sames[i], 1-val, isOdd, opposites[sames[i]], sames[sames[i]]);

        isOdd[sames[i]] = val;
    }

    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m; cin >> n >> m;

    vector<pair<pair<long long, long long>, pair<long long, long long>>> ex(m);

    for (long long i = 0; i < m; i++) {
        cin >> ex[i].first.first >> ex[i].first.second >> ex[i].second.first >> ex[i].second.second;
    }

    map<pair<long long, long long>, long long> diff;
    map<long long, vector<long long>> opposites;
    map<long long, long long> sames;

    map<int, int> isOdd;

    for (long long i = 0; i < m; i++) {
        bool gnhsio = true;

        long long difference = ex[i].second.first;

        if (isOdd.count(ex[i].first.first)) {
            if (difference % 2) {
                if (isOdd.count(ex[i].first.second) && isOdd[ex[i].first.second] == 1-isOdd[ex[i].first.first]) {
                    gnhsio = false;
                    cout << 0 << endl;
                    continue;
                }
                isOdd[ex[i].first.second] = 1-isOdd[ex[i].first.first];
            }
            else {
                if (isOdd.count(ex[i].first.second) && isOdd[ex[i].first.second] != isOdd[ex[i].first.first]) {
                    gnhsio = false;
                    cout << 0 << endl;
                    continue;
                }
                isOdd[ex[i].first.second] = isOdd[ex[i].first.first];
            }
        } else if (isOdd.count(ex[i].first.second)) {
            if (difference % 2) {
                if (isOdd.count(ex[i].first.first) && isOdd[ex[i].first.first] == 1-isOdd[ex[i].first.second]) {
                    gnhsio = false;
                    cout << 0 << endl;
                    continue;
                }
                isOdd[ex[i].first.first] = 1-isOdd[ex[i].first.second];
            }
            else {
                if (isOdd.count(ex[i].first.first) && isOdd[ex[i].first.first] != isOdd[ex[i].first.second]) {
                    gnhsio = false;
                    cout << 0 << endl;
                    continue;
                }

                if (!seet(ex[i].first.first, isOdd[ex[i].first.second], isOdd, opposites[ex[i].first.first], sames[ex[i].first.first])) {
                    gnhsio = false;
                    cout << 0 << endl;
                    continue;
                }
            } 
        } else if (difference % 2) {
            opposites[ex[i].first.second].push_back(ex[i].first.first);
            opposites[ex[i].first.first].push_back(ex[i].first.second);
        } else {
            sames[ex[i].first.second].push_back(ex[i].first.first);
            sames[ex[i].first.first].push_back(ex[i].first.second);
        }
        
        cout << 1 << endl;
    }
}