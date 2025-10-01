#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;
 
    while (t--) {

    

    long long n; cin >> n;

    vector<long long> nums(n);

    long long mx = 0, mn = 1e9;
    for (long long i = 0; i < n; i++) {
        cin >> nums[i];

        mx = max(mx, nums[i]);
        mn = min(mn, nums[i]);
    } 

    //cout << mn << " " << mx << " ";
    long long m = (mn+mx)/2, m2 = ceil((mn+mx)/(long double)2);
    long long s = mx;

    bool cookeda = false, cookedb = false, cookedc = 0, cookedd = false;
    for (long long i = 1; i < n; i++) {
        if (abs(nums[i]-m) < abs(nums[i-1]-m)) {
            cookeda = true;
        }

        if (abs(nums[i]-m2) < abs(nums[i-1]-m2)) {
            //cout << " aa";
            //cout << abs(nums[i]-m2) << " " << abs(nums[i-1]-m2) << "  ";
            cookedd = true;
        }

        if (abs(nums[i]-s) < abs(nums[i-1]-s)) {
            cookedb = true;
        }

        if (nums[i]<nums[i-1]) cookedc = true;
    }

    if (!cookeda) cout << m << endl;
    else if (!cookedd) cout << m2 << endl;
    else if (!cookedb) cout << s << endl;
    else if (!cookedc) cout << 0 << endl;
    else cout << -1 << endl;

    }
}