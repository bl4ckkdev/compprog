#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n; cin >> n;

    map<string, int> values;

    values["Bessie"] = 0;
    values["Maggie"] = 0;
    values["Elsie"] = 0;
    values["Henrietta"] = 0;
    values["Gertie"] = 0;
    values["Daisy"] = 0;
    values["Annabelle"] = 0;


    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int val; cin >> val;

        values[s] += val;
    }

    int mn = 1e9+1;
    for (auto& i : values) {
        mn = min(mn, i.second);
    }

    int smn = 1e9+1;

    string name = "aa";


    for (auto& i : values) {
        if (i.second>mn) {
            if (i.second<smn) name = i.first;

            smn = min(smn, i.second);
        } 
    }


    bool cooked = true;

    int v = -1;
    for (auto& i : values) {
        if (v != -1 && v != i.second) {
            cooked = false;
            break;
        } 

        v = i.second;
    }
    
    for (auto& i : values) {
        if (i.second==smn && i.first != name) {
            cooked = true;
            break;
        } 
    }

    if (name == "aa") cooked = true;

    cout << (cooked ? "Tie" : name) << endl;
}