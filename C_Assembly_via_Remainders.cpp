#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long tc; cin >> tc;

    while (tc--) {
        long long l; cin >> l;
        vector<long long> nums(l);
        vector<long long> f(l);
        for (long long i = 0; i < l-1; i++) {
            long long num; cin >> num;
            nums[i] = num;
        }

        f[0] = nums[0]*2;
        f[1] = nums[0]*3;


        for (long long i = 2; i < l; i++) {
            f[i] = f[i-1] + nums[i-1];

            if (f[i] % f[i-1] != nums[i-1]) {
                if (f[i-1] - nums[i-1] <= 0) {
                    while (f[i-1] - nums[i-1] <= 0 && f[i] % f[i-1] != nums[i-1]) {

                        //lcout << "A"<< f[i-1];

                        f[i-1] += f[i-2];
                    }

                    f[i] = f[i-1] + nums[i-1];
                }
                else 
                f[i] = f[i-1] - nums[i-1];

            } 
        }

        for (long long i = 0; i < l; i++) {
            cout << f[i] << " ";
        }

        cout << endl;
    }

    return 0;
}