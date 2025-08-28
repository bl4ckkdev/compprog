#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int t; cin >> t;
    
    while (t--) {
        set<int> bob;
        set<int> alice;
        bool ace = false;
        int n; cin >> n;
        
        for (int i = 1; i <= n; i++) {
            char c; cin >> c;

            if (i == 1 && c == 'B') ace = true;
            
            if (c == 'A') alice.insert(i);
            else bob.insert(i);
        }
        
        while (bob.size() > 0 && alice.size() > 0) {
            int carda;

            if (*(bob.begin()) == 1 && *(alice.rbegin()) == n) {
                carda = *(next(++alice.rbegin()).base());
            } else if (*bob.begin() == n) carda = 1; 
            else {
                carda = *alice.rbegin();
            }

            int cardb;

            if (carda == n && *bob.begin() == 1) {
                cardb = 1;
            } else if (carda == 1 && bob.size()>1) {
                cardb = *(next(++bob.rbegin()).base());
            } else cardb = *(bob.rbegin());


            if (carda == 1 && cardb == n) {
                alice.insert(n);
                bob.erase(prev(bob.end()));
                //cout << "A" << endl;
            } else if (cardb == 1 && carda == n) {
                bob.insert(n);
                alice.erase(prev(alice.end()));
                //cout << "B" << endl;
            } else if (cardb>carda) {
                //cout << "B" << endl;
                bob.insert(carda);
                alice.erase(alice.find(carda));
            } else {
                //cout << "A" << endl;
                alice.insert(cardb);
                bob.erase(bob.find(cardb));
            }


            //cout << carda << " " << cardb << endl;
        }

        //cout << "AA";
        if (bob.size() == 0) cout << "Alice\n";
        else cout << "Bob\n";
    }
}