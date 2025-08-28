#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<pair<int, int>> segments(n);

    for (int i = 0; i < n; i++) {
        int num, num2; cin >> num >> num2;
        segments[i].first = num;
        segments[i].second = num2;
    }

    vector<pair<int, int>> drives(m);

    for (int i = 0; i < m; i++) {
        int num, num2; cin >> num >> num2;
        drives[i].first = num;
        drives[i].second = num2;

    }

    int limits[100];

    int segmentind = 0;
    int drivesind = 0;
    int max = -1;
    int changeseg = 0;
    int changedrive = 0;
    for (int i = 0; i < 100; i++) {
        if (i > segments[segmentind].first+changeseg) {
            segmentind++;
            changeseg = i;
        } 
        if (i > drives[drivesind].first + changedrive) {
            drivesind++;
            changedrive = i;
        }

        if (drives[drivesind].second > segments[segmentind].second) {
            if (drives[drivesind].second - segments[segmentind].second > max)
                max = drives[drivesind].second - segments[segmentind].second;
        }
    }

    cout << max;
}