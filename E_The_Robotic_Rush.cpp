#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        vector<int> robots(n), spikes(m);
        vector<pair<int, int>> nearest(n, {-1e9-1,-1e9-1});


        for (int i = 0; i < n; i++) cin >> robots[i];
        for (int i = 0; i < m; i++) cin >> spikes[i];

        sort(begin(robots), end(robots));
        sort(begin(spikes), end(spikes));

        string inst; cin >> inst;

        vector<int> intervall(k+1), intervalr(k+1);
        vector<int> deaths(k);

        for (int i = 0; i < n; i++) {
            auto a = (upper_bound(begin(spikes), end(spikes), robots[i]));
            auto b = (lower_bound(begin(spikes), end(spikes), robots[i]));


            if (a != end(spikes)) nearest[i].second = *a;
            if ((b != end(spikes) || *prev(b) < robots[i]) && b != begin(spikes)) nearest[i].first = *(b-1);

            //cout << nearest[i].first << " " << nearest[i].second << "  ";
        }

        int pos = 0;
        for (int i = 1; i <= k; i++) {
            pos += (inst[i-1]=='R' ? 1 : -1);
            intervalr[i] = max(intervalr[i-1], pos);
            if (pos < 0) intervall[i] = max(abs(intervall[i-1]), abs(pos));
            else intervall[i] = intervall[i-1];
        }

        for (int i = 0; i <= k; i++) {
            //cout << intervall[i] << " " << intervalr[i] << "  ";
        }
        //cout << endl;

        for (int i = 0; i < n; i++) {

            auto r = (lower_bound(begin(intervalr), end(intervalr), nearest[i].second-robots[i]));
            auto l = (lower_bound(begin(intervall), end(intervall), robots[i]-nearest[i].first));

            int miin = 1e9;

            if (r != intervalr.end() && nearest[i].second>=-1e9) {
                //cout << "R: " << (r-begin(intervalr)) << " ";
                miin = r-begin(intervalr)-1;
            }


            if (l != intervall.end() && l >= begin(intervall) && nearest[i].first>=-1e9) {
                //cout << "L: " << (l-begin(intervall)) << " ";
                miin = min(miin, (int)(l-begin(intervall))-1);
            }

            if (miin<deaths.size()) deaths[miin]++;
        }

        vector<int> pref(k+1);

        for (int i = 1; i <= k; i++) {
            pref[i] = pref[i-1] + deaths[i-1];
        }

        for (int i = 0; i < k; i++) {
            cout << n-pref[i+1] << " ";
        }
        cout << endl;

    }
}