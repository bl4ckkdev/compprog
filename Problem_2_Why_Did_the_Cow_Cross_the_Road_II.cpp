#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 52;

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    vector<char> chars(n);

    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    vector<pair<int, int>> ch(26);
    vector<bool> v(26);

    for (int i = 0; i < n; i++) {
        int idx = chars[i]-'A';

        if (v[idx]) {
            ch[idx].second = i;
        } else {
            v[idx] = true;
            ch[idx].first = i;
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (ch[i].first < ch[j].first && ch[i].second < ch[j].second && ch[i].second > ch[j].first) {
                count++;

                //cout << i << " " << j << "  ";
            }
        }
    }



    cout << count;
}