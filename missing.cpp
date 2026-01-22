#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> missing;
    int m; cin >> m;
    cout << "? 1" << flush;
    int b; cin >> b;
    

    cout << "? " << b << flush;
    int l; cin >> l;

    int prev = 1;

    
    for (int i = 2; i < m; i++) {
        cout << "? " << i << flush;
        int num; cin >> num;

        if (num-prev>1) {
            for (int i = prev+1; i < num; i++) {
                missing.insert(i);
            }
        }
        prev = num;
    }

    for (int i = prev+1; i < l; i++) {
        missing.insert(i);
    }


    for (auto& i : missing) cout << i << "  ";

    cout << "! " << missing.size() << " ";

    for (int i = 0; i < l; i++) {
        if (missing.count(i+1)) cout << i+1 << " ";
    }

    cout << flush;
    
}