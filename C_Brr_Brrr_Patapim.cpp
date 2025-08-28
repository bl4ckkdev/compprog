#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        //cout << n << endl;
        vector<int> nums(2*n, -1);

        for (int i = 0; i < n; i++) {
            cin >> nums[i+1];
        }

        for (int i = 1; i < n; i++) {
            
            for (int j = 0; j < n; j++) {
                int s;
                if (j == n-1) cin >> nums[n+i];
                else cin >> s;
            }
        }

        vector<int> numss(2*n);

        for (int i = 0; i < 2*n; i++) {
            numss[i] = nums[i];
        }
        sort(numss.begin(), numss.end());

        
        int missingnum = -1;


        int min = numss[1], max = numss[1];
        for (int i = 2; i < 2*n; i++) {
            if (numss[i] != numss[i-1]+1) missingnum = numss[i]-1;

            if (numss[i] < min) min = numss[i];
            if (numss[i] > max) max = numss[i];
        }

        //cout << max << endl;

        if (missingnum == -1) {
            if (min != 1) missingnum = 1;
            if (max != 2*n) missingnum = 2*n;
        }

        nums[0] = missingnum;
        for (int i = 0; i < 2*n; i++) {
            cout << nums[i] << " ";
        }



        cout << endl;
    }
}