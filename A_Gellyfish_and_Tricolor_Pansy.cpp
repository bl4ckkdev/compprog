#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int g, f, gk, fk; cin >> g >> f >> gk >> fk;

        g++;
        gk++;

        bool win = false;
    
        int leastf = min(f, fk);
        int leastg = min(g, gk);

        if (leastg <= leastf) cout << "Flower" << endl;
        else cout << "Gellyfish" << endl;


        //cout << win << endl;
    }
}