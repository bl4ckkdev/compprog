// today i learned that "lower_bound" does not return the first number lowest, but the first number greater or equal to.
// i am not the smartest.

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> n >> t;
 
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefix(n+1);

    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + nums[i];
    }

    //for (auto& i : prefix) cout << i << " ";
    //cout << endl;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        auto j = upper_bound(begin(prefix)+i, end(prefix), t+prefix[i-1]);
        j--;
        //if (j != end(prefix)) cout << i << " " << j-begin(prefix) << "  ";

        if (j != end(prefix) && j >= begin(prefix) && j-begin(prefix)-i+1 > mx) {
            //cout << i << " " << j-begin(prefix)-i << "  ";
            mx = j-begin(prefix)-i+1;
            //cout << *lower_bound(begin(prefix)+i, end(prefix), t+prefix[i]) << "  ";
        } 
    }

    cout << mx;
}