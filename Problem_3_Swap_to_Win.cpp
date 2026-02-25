#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        string s; cin >> s;

        vector<string> strings(n);
        vector<vector<int>> orpos(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            cin >> strings[i];

            for (int j = 0; j < m; j++) {
                orpos[i][j] = j;
            }
        }

        unordered_map<char, int> tfreq;
        for (int i = 0; i < m; i++) {
            if (s[i] != strings[0][i]) tfreq[s[i]]++;
        }


        
        vector<string> list;

        vector<bool> b(n);
        for (int i = 0; i < m; i++) {
            if (s[i] != strings[0][i] && tfreq[strings[0][i]]>0) {
                for (int j = 0; j < m; j++) {
                    if (i == j) continue;
                    if (s[j] == strings[0][i]) {
                        tfreq[strings[0][i]]--;
                        swap(strings[0][j], strings[0][i]);
                        b[j] = true;

                        list.push_back("1 1 " + to_string(i+1) + " " + to_string(j+1));
                        //cout << "1 1 " << i << " " << j << "  " << endl;
                    }
                }
            }
        }

        

        unordered_map<char, vector<pair<int, int>>> freq;

        vector<bool> isthere(100);

        for (int i = 0; i < m; i++) {
            isthere[s[i]-'0'] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isthere[strings[i][j]-'0']) {
                    freq[strings[i][j]].push_back({i, j});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (s[i] == strings[0][i]) continue;

            
            pair<int, int> a = *begin(freq[s[i]]);

            //cout << orpos[a.first][a.second] << " " << i << endl;

            freq[s[i]].erase(begin(freq[s[i]]));
            
            swap(strings[a.first][orpos[a.first][a.second]], strings[a.first][i]);
            

            list.push_back(string("1 ") + to_string(a.first+1) + string(" ") + to_string(orpos[a.first][a.second]+1) + " " + to_string(i+1));
            swap(orpos[a.first][a.second], orpos[a.first][i]);
            list.push_back(string("2 1 ") + to_string(a.first+1) + string(" ") + to_string(i+1));

            //cout << a.first << " " << a.second << strings[0][i];
            //cout << " " << strings[a.first] << endl;

            swap(strings[0][i], strings[a.first][i]);
        }

        //cout << strings[0] << " ";

        cout << list.size() << endl;
        for (auto& i : list) cout << i << "\n";

        //cout << strings[0] << endl;
    }
}