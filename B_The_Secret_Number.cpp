#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        unsigned long long int a; cin >> a;
        string n = to_string(a);

        vector<unsigned long long int> valids;
        for (int i = 1; i <= n.length(); i++) {
            if ((unsigned long long int)a / (unsigned long long int)((unsigned long long int)pow(10, i)+1) * 
            (unsigned long long int)((unsigned long long int)pow(10, i)+1) == a) 
                valids.push_back((unsigned long long int)a / (unsigned long long int)((unsigned long long int)pow(10, i)+1));
            //else cout << a / ((unsigned long long int)pow(10, i)+1) << " ";
        }

        sort(valids.begin(), valids.end());

        cout << valids.size();
        cout << endl;
        if (valids.size()>0) {
            for (int i = 0; i < valids.size(); i++) {
                cout << valids[i] << " ";
            }
            cout << endl;
        }
    }
}