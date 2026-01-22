#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; cin >> n >> k;

    vector<long long> nums(k+1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> nums[i];
    }

    int offset = 0;

    long long as = 0, bs = 0;


    for (int i = 1; i <= k; i++) {
        long long r = nums[i]-nums[i-1]-1;

        //cout << offset << " " << nums[i] << endl;

        if ((offset%2+nums[i]%2)%2 == 0) {
            as++;

            as += ceil(r/(long double)2);
            bs += r/2;
        } else {

            bs++;
            bs += ceil(r/(long double)2);
            as += r/2;
        }

        offset++;

        if (i != k) continue;
        r = n-nums[i];


        if ((offset%2+(n+1)%2)%2 == 0) {

            as += ceil(r/(long double)2);
            bs += r/2;
        } else {

            bs += ceil(r/(long double)2);
            as += r/2;
        }
    }

    cout << as << " " << bs;

}