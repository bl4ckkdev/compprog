#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    //vector<int> dp(1e9+1, 1e9+1);
    //int dpstate = 0;
    while (t--) {
        int n; cin >> n;

        //vector<int64_t> nums = {1, 3, 6, 10, 15};
        

        //dp[0] = 0;

        //for (int64_t i = dpstate; i <= n; i++) {
        //    for (int64_t j = 0; j < 5; j++) {
        //        //cout << dp[i]+1 << " ";
        //        if (i + nums[j] <= n) dp[i+nums[j]] = min(dp[i]+1, dp[i+nums[j]]);
        //    }
//
        //    dpstate++;
        //}

        //cout << endl;

        int steps = 1e9;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 4; k++) {
                    for (int c = 0; c <= 2; c++) {
                        if ((n - (i + 3*j + 6*k + c*10)) % 15 == 0 && (n - (i + 3*j + 6*k + c*10)) >= 0) {
                            int st = steps;
                            steps = min(steps, i+j+k+c + (n - i - 3*j - 6*k - c*10)/15);

                            //if (st != steps) cout << "y" << i << " " << j << " " << k << " " << c << " " << (n - (i + 3*j + 6*k + c*10)) << endl;
                        }
                    }
                }
            }
        }

        cout << steps << endl;
    }
}