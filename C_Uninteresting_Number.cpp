#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string b; cin >> b;
        int n = b.length();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = b[i] - '0';
        }

        int pot = 0;

        int twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) twos++;
            else if (nums[i] == 3) threes++;

            pot += nums[i];
        }

        bool YAHH = false; 

        //cout << threes << endl;
        
        while (!YAHH && pot % 9 != 0 && (twos > 0 || threes > 0)) {
            if ((pot+2) % 9 != 0) {
                if (twos == 1) {
                    pot += 2;
                    twos--;
                } 
                if ((pot+4) % 9 != 0) {
                    if (threes < 1 && twos > 1) {
                        pot += 4;
                        twos -= 2;
                    } 

                    if ((threes>= 1 || twos >= 3) && (pot+6) % 9 != 0) {
                        if (threes >= 1) threes--;
                        else twos -= 3;

                        pot += 6;
                    } else if (threes>=1 || twos>=3) {
                        YAHH = true;
                        break;
                    }
                } else if (twos>=2) {
                    YAHH = true;
                    break;
                } 
            }
            else if (twos>=1) {
                YAHH = true;
                break;
            } 
        }
        //cout << pot << endl;
        
        if (pot % 9 == 0) YAHH = true;

        cout << (YAHH ? "YES" : "NO") << endl;
    }
}