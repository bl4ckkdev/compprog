#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string l; cin >> l;

        int leftl = -1, rightr = -1;
        for (int i = 0; i < n; i++) {
            char left = (i == 0 ? '0' : l[i-1]);
            
            if (left != l[i]) {
                for (int j = i+1; j < n; j++) {
                    char right = (j == n-1 ? (left == '0' ? '1' : '0') : l[j+1]);
                    //cout << left << " " << right << " " << l[j] << " " << l[i] << endl;
                    if (l[j] != l[i] && right != left) {

                        //cout << l[j] << l[i] << right << left << endl;
                        leftl = i;
                        rightr = j;
                        break;
                    }
                }
                break;
            }
        }

        

        if (leftl != -1 && rightr != -1) {
            //cout << leftl << " " << rightr << endl;
            reverse(l.begin() + leftl, l.begin() + rightr + 1);
            //cout << l << endl;
        }



        int moves = 0;
        char prev = '0';

        for (int i = 0; i < n; i++) {
            if (l[i] != prev) {
                //cout << l[i] << prev << i << " ";
                moves++;
            } 
            prev = l[i];
            moves++;
        }

        //cout << endl << endl;;
        cout << moves << endl;
        //cout << leftl << " " << rightr << " " << moves << endl;;
    }
}