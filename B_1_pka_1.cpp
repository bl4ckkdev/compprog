#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q; cin >> n >> q;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<long long, pair<long long, long long>>> operations(q);

    for (int i = 0; i < q; i++) {
        cin >> operations[i].first >> operations[i].second.first >> operations[i].second.second;
    }

    for (int i = 0; i < q; i++) {
        if (operations[i].first - 1) {
            long long sum = 0;

            for (int j = operations[i].second.first - 1; j < operations[i].second.second; j++) {
                sum += arr[j];
            }
            

            cout << sum << endl;
        } else {
            arr[operations[i].second.first - 1] = operations[i].second.second;
        }
    }
}