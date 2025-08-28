#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long  t; cin >> t;

    while (t--) {
        string s, p; cin >> s >> p;

        long long i = 0, j = 0;

        bool cooked = false;

        if (p[0] != s[0] || p[p.length()-1] != s[s.length()-1]) cooked = true;

        if (!cooked)

        while (j < p.length() && i < s.length()) {
            long long js = 0;


            if (p[j] != s[i])  {
                
                cooked = true;
                break;
            }

            while (j < p.length() && (js == 0 || p[j] == (p[j-1]))) {
                js++;
                j++;
            }

            long long ps = 0;

            while (i < s.length() && (ps == 0 || s[i] == s[i-1])) {
                ps++;
                i++;
            }

            //cout << i << " " << j << endl;
            if (js <= 2*ps && js >= ps) {
            }
            else {
                //cout << "CAUGHT " << js << " " << ps << endl;
                cooked = true;
                break;
            }
        }

        
        if (i != s.length() || j != p.length()) cooked = true;

        cout << (cooked ? "NO\n" : "YES\n" );
    }
}