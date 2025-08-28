#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    int max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int distance = x[i] - x[j];
            int distancey = y[i] - y[j];

            int sqr = distance*distance + distancey*distancey;

            if (sqr > max) max = sqr;
        }
    }

    cout << max;
}