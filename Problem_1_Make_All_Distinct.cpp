#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        vector<long long> nums(n);

        map<long long, long long> freqmap;
    
        for (long long i = 0; i < n; i++) {
            cin >> nums[i];

            freqmap[nums[i]]++;

        }

        long long moves = 0;
        /*for (long long i = 0; i < 1000; i++) {

            freq[nums[i]+k+500] += max(0, freq[nums[i]+500]-1);

            moves += max(0, freq[nums[i]+1000]-1);
            freq[nums[i]+500] = min(1, freq[nums[i]]+500);
        }*/

        
        auto a = begin(freqmap);
        if (k<0) a = prev(end(freqmap));

        while (a != freqmap.end()) {
            //cout << (*a).first << " " << (*a).second << " ";

            moves += max(0LL, (*a).second-1);

            if (max(0LL, (*a).second-1)>0)
            freqmap[(*a).first+k] += max(0LL, (*a).second-1LL);

            freqmap[(*a).first] = min(1LL, (*a).second);
            

            if (k>0) a = next(a);
            else a = prev(a);
        }

        cout << moves << endl;
        
    }
}