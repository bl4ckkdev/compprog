#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    map<string, int> a = {{"Ox", 1}, {"Tiger", 2}, {"Rabbit", 3}, {"Dragon", 4}, {"Snake", 5}, {"Horse", 6}, {"Goat", 7}, {"Monkey", 8}, {"Rooster", 9}, {"Dog", 10}, {"Pig", 11}, {"Rat", 12}};

    map<string, vector<pair<string, int>>> b;

    map<string, int> years;
    years["Bessie"] = 1;
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

        years[name] = a[year];

        b[name].push_back({target, a[year] * (st == "previous" ? 1 : -1)});
        b[target].push_back({name, a[year] * (st != "previous" ? 1 : -1)});
    }

    for (auto& i : b) {
        //cout << i.first << "  ";
        //for (auto& j : i.second) cout << j.first << " " << j.second << " ";

        //cout << endl;
    }


    for (auto& i : b) {
        //cout << i.first << ": ";
        //for (auto& j : i.second) cout << j.first << " " << j.second  << "  ";
    }
    

    queue<pair<string, int>> bfs;

    bfs.push({"Bessie", {0}});
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
                int diff;

                //cout << v[i].second << "b ";
                if (v[i].second<0) {
                    if (abs(v[i].second)>years[name]) {
                        diff = -(12+years[name]+v[i].second);
                        //cout << diff << " ";
                    } else if (abs(v[i].second)==years[name]) {
                        //cout << "aa";
                        diff = -12;
                    } else {
                        diff = abs(v[i].second)-years[name];

                        //cout << diff << "c ";
                    }
                } else {
                    if (v[i].second>years[name]) {
                        diff = v[i].second-years[name];
                    } else if (abs(v[i].second)==years[name]) {
                        //cout << "bb";
                        diff = 12;
                    } else {
                        diff = 12+v[i].second-years[name];
                    }
                }

                //cout << name << " " << v[i].first << " ";
                //cout << diff << " ";
                bfs.push({v[i].first, m+diff});

                if (v[i].first == "Elsie") ans = m+diff;
            }
        }
    }

    cout << abs(ans);
}