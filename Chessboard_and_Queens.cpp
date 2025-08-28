#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int ops = 0;

vector<vector<bool>> blocked(8, vector<bool>(8));

void check(int col, int row, vector<pair<int, int>> q) {
    ops++;
    q.push_back({col, row});

    int qs = q.size();
    bool cooked = false;
    for (int i = 0; i < qs; i++) {

        for (int j = 0; j < qs; j++) {
            if (i == j) continue;

            if (q[i].first == q[j].first || // x
                q[i].second == q[j].second || // y
                abs(q[i].first - q[j].first) == abs(q[i].second - q[j].second)) { // diag

                cooked = true;
                break;
            }
        }

        if (cooked) break;
    }

    if (cooked) return;

    // validity check

    if (row == 7) {
        //for (auto& i : q) cout << i.first << " " << i.second << "  ";
        //cout << endl;

        cnt++;
        return;
    }
    else
    for (int i = 0; i < 8; i++) {
        if (!blocked[row+1][i]) check(i, row+1, q);
    }
}

int main() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char a; cin >> a;

            if (a == '*') blocked[i][j] = true;
        }
    }

    for (int i = 0; i < 8; i++) {
        if (!blocked[0][i]) check(i, 0, vector<pair<int, int>>());
    }

    cout << cnt << " " << ops;
}