#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    string s; cin >> s;

    int m = 0;

    for (int i = n-1; i >= 0; i-=2) {
        if (s[i] == s[i-1]) continue;
        else {
            if ((s[i] == 'H' && s[i-1] == 'G' && m%2==0) || (s[i-1] == 'H' && s[i] == 'G' && m%2==1)) {
                m++;
            }
        }
    }

    cout << m;

    
}