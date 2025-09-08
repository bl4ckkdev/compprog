#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n; cin >> n;

    map<string, vector<string>> states;
    map<string, string> aa;

    for (int i = 0; i < n; i++) {
        string city, state; cin >> city >> state;

        states[state].push_back(city);
    } 

    int pairs = 0;

    for (auto& i : states) {
        vector<string>& st = i.second;

        for (int j = 0; j < st.size(); j++) {
            vector<string>& str = states[st[j].substr(0, 2)];
            for (int k = 0; k < str.size(); k++) {
                

                if (str[k].substr(0, 2) == i.first && i.first != st[j].substr(0, 2)) {
                    //cout << st[j] << " " << i.first << " " << str[k] << endl;
                    pairs++;
                } 
            }
        }
    }

    cout << pairs/2;
}