#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c; cin >> a >> b >> c;

    int res = a+b+c;

    res = max(res, a*b+c);
    res = max(res, a+b*c);
    res = max(res, (a+b)*c);
    res = max(res, a*(b+c));
    res = max(res, a*b*c);

    cout << res << endl;
}