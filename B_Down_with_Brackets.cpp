#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;

    while (t--) {
        string a; cin >> a;

        int nest = 0;

        int nestpos = -1;
        for (int i = 1; i < a.length(); i++) {
            if (a[i-1] == '(' && a[i] == '(') {
                if (nestpos == -1) nestpos = i-1;
                int length = 0;
                while (a[i] == '(') {
                    i++;
                }

                nest++;
            } 
        }

        bool outnest = false;
        int as = 0, bs = 0;
        for (int i = nestpos; i < a.length(); i++) {
            if (a[i] == '(') as++;
            if (a[i] == ')') bs++;

            if ((nestpos != 0 || i < a.length()-1) && as == bs) outnest = true;
            //else if (i == a.length()-1 && nestpos == 0) outnest = true;
        }

        

        if ((nest >= 1 && outnest) || (a.size() > 2 && a[1] == ')' && a[a.size()-2] == '(')) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}