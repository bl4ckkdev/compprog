#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n; cin >> n;

    vector<int> pos(3);
    pos[0] = 0;
    pos[1] = 1;
    pos[2] = 2;

    vector<int> gs(3, 0);

    for (int i = 0; i < n; i++) {
        int a, b, g; cin >> a >> b >> g;

        //cout << pos[a-1] << " " << pos[b-1] << endl;
        swap(pos[a-1], pos[b-1]);

        //if (g == pos[g-1]) {
            gs[pos[g-1]]++;
        //} 
    }

    sort(gs.begin(), gs.end());

    cout << gs[2] << endl;
}