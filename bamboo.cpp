#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;

    set<long long> nums;

    for (long long i = 0; i < n; i++) {
        long long num; cin >> num;
        nums.insert(num);
    }

    cout << nums.size() << endl;

}