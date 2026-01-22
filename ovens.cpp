#include <bits/stdc++.h>

using namespace std;

#include <bitset>
#include <cstddef>

std::bitset<200000> range_bitset(std::size_t l, std::size_t r) {
    std::bitset<200000> b;
    if (l > r) return b;                    // empty
    if (l >= 200000) return b;                   // out of range
    if (r >= 200000) r = 200000 - 1;                  // clamp

    for (std::size_t i = l; i <= r; ++i) b.set(i);
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n);
    vector<int> switches(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> switches[i];
    }


    bitset<200000> a;
    for (int i = 0; i < n; i++) {
        a[i] = nums[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            a ^= range_bitset(i, i+switches[i]);
            cnt++;
        }
    }


    cout << cnt;
}