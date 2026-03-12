#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<set<int>> adj(n);
    map<int, int> roads;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;

        adj[x-1].insert(i);

        roads[i] = y-1;
    }

    int t; cin >> t;

    vector<int> arr(t);

    for (int i = 0; i < t; i++) {
        cin >> arr[i];

        arr[i]--;
    }

    int q; cin >> q;

    vector<pair<int, pair<int, pair<int, int>>>> qu(q);

    for (int i = 0; i < q; i++) {
        cin >> qu[i].first;

        if (qu[i].first - 1) {
            cin >> qu[i].second.first;
            cin >> qu[i].second.second.first;

            qu[i].second.first--; //i
            qu[i].second.second.first--; //K
            
            qu[i].second.second.second = -1;
        } else {
            cin >> qu[i].second.first;
            cin >> qu[i].second.second.first;
            cin >> qu[i].second.second.second;

            qu[i].second.first--; //L
            qu[i].second.second.first--; //R
            qu[i].second.second.second--; //S
        }
    }

    if (q == 1) {
        int start = qu[0].second.second.second;

        int cur = start;
        int l = qu[0].second.first;
        int r = qu[0].second.second.first;

        for (int i = l; i <= r; i++) {
            int road = arr[i];

            if (adj[cur].count(road)) cur = roads[road];
        }

        cout << cur+1;
    } else if (n == 2) {
        //set<int> nadj;
        int zc = 0, oc = 0; // roads that go to 0 count, and roads that go to 1 count

        /*for (auto& i : adj) {
            if (roads[i] == 0 && adj[1].count(i)) {
                nadj.insert(0);
                zc++;
            } 
            else if (roads[i] == 1 && adj[0].count(i)) {
                nadj.insert(1);
                oc++;
            } 
            else nadj.insert(2);
        }*/

        map<int, int> qq;

        for (int i = 0; i < t; i++) {
            //cout << i << " " << roads[arr[i]] << " " << adj[1].count(arr[i]) << "  ";
            if (roads[arr[i]] == 0 && adj[1].count(arr[i])) {
                //cout << i << "a ";

                qq[i] = 0;
                arr[i] = 0;
            } 
            else if (roads[arr[i]] == 1 && adj[0].count(arr[i])) {
                qq[i] = 1;
                arr[i] = 1;
            } 
            else arr[i] = -1;
        }
        //cout << endl;
        //for (auto& i : arr) cout << i << " ";
        
        /*cout << endl;
        for (auto& i : roads) cout << i.first << " " << i.second << "  ";
        cout << endl;
        for (auto& i : adj[0]) cout << i << " ";
        cout << endl;
        for (auto& i : adj[1]) cout << i << " ";
        cout << endl;
        for (auto& i : arr) cout << i << " ";*/

        

        for (int i = 0; i < q; i++) {
            if (qu[i].first == 1) {
                int start = qu[i].second.second.second;

                int cur = start;
                int l = qu[i].second.first;
                int r = qu[i].second.second.first;

                //for (int i = l; i <=r; i++) cout << arr[i] << " ";
                //cout << endl;

                int ans = arr[r]+1;

                if (ans<=0) {
                    if (qq.size()>0 && qq.upper_bound(r) != begin(qq)) {
                        auto xs = *prev(qq.upper_bound(r));
                        //cout << xs.first << " " << xs.second << " ";
                        if (xs.first>=l) cout << xs.second+1 << endl;
                        else cout << qu[i].second.second.second+1 << endl;
                    }
                    else cout << qu[i].second.second.second+1 << endl;

                } else cout << ans << endl;
            } else {
                int idx = qu[i].second.first;
                int K = qu[i].second.second.first;

                //cout << idx << " " << K << " ";

                if (roads[K] == 0 && adj[1].count(K)) {
                    /*for (int i = idx+1; i < t; i++) {
                        if (arr[i]>=0) break;
                        else arr[i] = -idx-1;
                    }*/

                    qq[idx] = 0;
                    arr[idx] = 0;
                } 
                else if (roads[K] == 1 && adj[0].count(K)) {
                    /*for (int i = idx+1; i < t; i++) {
                        cout << "a";
                        if (arr[i]>=0) break;
                        else arr[i] = -idx-1;
                    }*/

                    qq[idx] = 1;
                    arr[idx] = 1;
                } 
                else {
                    arr[idx] = -1;
                    if (arr[idx] == -1) qq.erase(idx);
                }
            }
        }
    }
}