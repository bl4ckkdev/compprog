#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        string sa = s;
        sort(sa.begin(), sa.end());

        int index = -1;
        int num = -1;
        int indexThatChanges = -1;

        for (int i = 0; i < s.length(); i++) {
            if (sa[i] != s[i]) {
                num = sa[i] - '0';
                indexThatChanges = i;
                break;
            }
        }

        if (num != -1) {
            for (int i = 0; i < s.length(); i++) {
                if ( s[i] - '0' == num) {
                    index = i;
                    break;
                }
            }

            

            for (int i = 0; i < indexThatChanges; i++) {
                cout << s[i] - '0';
            }

            
            cout << num;
            
            for (int i = indexThatChanges; i < index; i++) {
                cout << min(s[i] - '0' +1, 9);
            }

            for (int i = index+1; i < s.length(); i++) {
                cout << s[i];
            }

            cout << endl;
        } else cout << s << endl;
    }
}