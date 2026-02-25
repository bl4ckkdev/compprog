#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long n, m; cin >> n >> m;

        vector<long long> nums(n);
        map<long long, long long> occ;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            occ[nums[i]]++;
        }

        long long mx = 0;
        int cnt = 0;
        //cout << t << " -------\n"; 

        for (auto& i : occ) {
            if (cnt != 0) {
                auto previ = *prev(occ.lower_bound(i.first));

                
                for (int j = 0; j < i.second; j++) {
                    
                    long long score = min(i.first*(j+1), (m/i.first)*i.first);
                    long long rem = min((m-score)/previ.first, previ.second)*previ.first;

                    if (i.first-previ.first>1) rem = 0;
                    
                    mx = max(score+rem, mx);
                    //if (mx == 234)cout << "1b" << " " << score << " " << rem << endl;
                }

                //if (mx == 234) cout << "1a " << previ.first << " " << previ.second << endl;
            }

            
                for (int j = 0; j < i.second; j++) {
                    long long score = min(i.first*(j+1), (m/i.first)*i.first);
                    
                    mx = max(score, mx);

                    //if (mx == 234) cout << "2b" << " " << score << " " << rem << endl;
                }

            if (cnt != occ.size()-1) {
                auto nexti = *occ.upper_bound(i.first);
                
                for (int j = 0; j < i.second; j++) {
                    long long score = min(i.first*(j+1), (m/i.first)*i.first);
                    long long rem = min((m-score)/nexti.first, nexti.second)*nexti.first;

                    if (nexti.first-i.first>1) rem = 0;
                    
                    mx = max(score+rem, mx);

                    //if (mx == 234) cout << "2b" << " " << score << " " << rem << endl;
                }
                //if (mx == 234) cout << "2a " << nexti.first << " " << nexti.second << endl;
            }

            cnt++;
        }

        cout << mx << endl;
    }
}