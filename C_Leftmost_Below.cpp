#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n; cin >> n;

        vector<long long> nums(n);

        for (long long i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long num = nums[0];
        long long low = nums[0];
        long long maxim = nums[0];
        long long cap = nums[0]*2-1;


        bool down = false;
        bool cooked = false;
        for (long long i = 1; i < n; i++) {
            if (nums[i] > 2*low-1) {
                cooked = true;
                break;
            }
            /*if (!down) {
                if (nums[i] > cap) {
                    cooked = true;
                    break;
                }
                else if (nums[i] < num) {
                    down = true;
                    //continue;
                }
            }
            if (down) {
                if (nums[i] > low*2-1) {
                    cooked = true;
                    break;
                }
                /*if (nums[i] > nums[i-1]) {
                    cooked = true;
                    break;
                }*/
            low = min(nums[i], low);
            maxim = max(nums[i], maxim);
        }

        //if (nums[n-1] != low) cooked = true;
        //if (nums[0] + low < maxim) cooked = true;

        cout << (cooked ? "NO" : "YES") << endl;


    }
}