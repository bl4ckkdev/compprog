#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        int pos = -1;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] != '0'){

                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "0" << endl;
        } else {
            int count = 0;
            for (int i = pos-1; i >= 0; i--) {
                if (s[i] != '0') count++;
                
            }

            //cout << count << " AA " << pos << endl;
            cout << s.length()-1-pos + count << endl;
        }
    }
}