#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<int> nums(n);
    map<int, int> num;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        num[nums[i]] = k-nums[i];
    }

    //for (auto& i : num) cout << i.first << " " << i.second << "  ";

    int a = -1, b = -1;
    for (const auto& i : num) {
        if (num.count(i.second) != 0) {
            if (i.second == i.first && num.count(i.second) <= 1) continue;
            a = i.first;
            b = i.second;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] == a) {
            a = i+1;
            break;
        }
    }
        
    for (int i = 0; i < n; i++) {
        if (nums[i] == b) {
            b = i+1;
            break;
        }
    }

    if (a == -1) cout << "IMPOSSIBLE";
    else cout << a << " " << b;
}