#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<pair<vector<int>, int>> cards(n, make_pair(vector<int>(m), 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                cards[i].first[j] = a;
                cards[i].second = i+1;
            }
        }

        for (int i = 0; i < n; i++) {
            sort(cards[i].first.begin(), cards[i].first.end());
        }

        sort(cards.begin(), cards.end(), [](auto& a, auto& b){
            return a.first[0]<b.first[0];
        });


        bool nah = false;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (cards[j].first[i] != cards[j-1].first[i]+1) nah = true;

                //cout << cards[j][i] << " ";
            }
        }

        if (nah) cout << "-1" << endl;
        else {
            for (int i = 0; i < n; i++) {
                cout << cards[i].second << " ";
            }
            cout << endl;
        }
    }
}