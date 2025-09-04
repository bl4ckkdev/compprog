#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    map<string, int> a = {{"Ox", 1}, {"Tiger", 2}, {"Rabbit", 3}, {"Dragon", 4}, {"Snake", 5}, {"Horse", 6}, {"Goat", 7}, {"Monkey", 8}, {"Rooster", 9}, {"Dog", 10}, {"Pig", 11}, {"Rat", 12}};

    map<string, vector<pair<string, int>>> b;

    for (int i = 0; i < n; i++) {
        string cur;
        string name;
        cin >> name;

        cin >> cur;
        cin >> cur;

        string st;
        cin >> st;
        string year;
        cin >> year;
        cin >> cur;
        cin >> cur;
        string target;
        cin >> target;

        b[name].push_back({target, a[year] * (st == "previous" ? 1 : -1)});
        b[target].push_back({name, a[year] * (st != "previous" ? 1 : -1)});
    }

    for (auto& i : b) {
        //cout << i.first << "  ";
        //for (auto& j : i.second) cout << j.first << " " << j.second << " ";

        //cout << endl;
    }

    queue<pair<string, int>> bfs;

    bfs.push({"Bessie", 0});
    map<string, bool> visited;
    visited["Bessie"] = true;
    int ans = 0;
    while (!bfs.empty()) {
        string name = bfs.front().first;
        int m = bfs.front().second;
        bfs.pop();

        vector<pair<string, int>> v = b[name];
        for (int i = 0; i < v.size(); i++) {
            if (!visited[v[i].first]) {
                visited[v[i].first] = true;
                bfs.push({v[i].first, m+v[i].second});

                if (v[i].first == "Elsie") ans = m+v[i].second;
            }
        }
    }

    cout << abs(ans);
}