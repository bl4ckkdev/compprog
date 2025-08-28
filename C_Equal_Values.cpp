#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long tc; cin >> tc;

    while (tc--) {
        long long n; cin >> n;

        vector<long long> nums(n);

        for (long long i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<long long> left(n);
        vector<long long> right(n);

        for (long long i = 0; i < n; i++) {
            left[i] = i*nums[i];
        }

        for (long long i = 0; i < n; i++) {
            right[i] = (n-1-i)*nums[i];
        }

        vector<pair<long long, long long>> simi;
        for (long long i = 1; i < n; i++) {
            if (nums[i-1] == nums[i]) {
                simi.push_back(make_pair(i-1, i));
                long long pair = simi.size()-1;
                i++;
                while (i < n && nums[i-1] == nums[i]) {
                    simi[pair].second = i;
                    i++;
                }
            }
        }  



        long long min = -1;

        for (long long i = 0; i < simi.size(); i++) {
            long long calc = simi[i].first*nums[simi[i].first] + (n-1-simi[i].second)*nums[simi[i].second];
            if (min == -1 || calc<min) min = calc; 
        }

        for (long long i = 0; i < n; i++) {
            if (min == -1 || left[i] + right[i] < min) {
                min = left[i] + right[i];
            }
        }

        cout << min << endl;
    }
}