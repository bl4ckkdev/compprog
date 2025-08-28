#include <bits/stdc++.h>

using namespace std;

struct Cow {
    int l, r, t;
};

struct Cond {
    int l, r, p, m;
};

int N, M, MIN = 1e9+1;

vector<Cow> cows;

void search(vector<Cond> c, int i, int r) {
    if (i == M) {
        //cout << c.size() << endl;
        //cout << "!";
        vector<int> st(101);

        for (int j = 0; j < c.size(); j++) {
            for (int k = c[j].l; k <= c[j].r; k++) {
                st[k] += c[j].p;
            }
        }

        bool valid = 1;

        for (int j = 0; j < N; j++) {
            for (int k = cows[j].l; k <= cows[j].r; k++) {
                //cout << k << " ";
                if (st[k] < cows[j].t) {
                    //cout << st[k] << " " << cows[j].l << " " << cows[j].r << " " << cows[j].t << "\n"; 
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                
                break;
            } 
        }

        int co = 0;
        for (int j = 0; j < c.size(); j++) {
               co += c[j].m;
                //cout << c[j].l << " " << c[j].r << "  ";
        
        }

        if (valid) {
            //cout << endl;

            MIN = min(MIN, co);
        }

        //cout << endl;
        return;
    }

    search(c, i+1, r);

    vector<Cond> d;
    for (int j = 0; j < c.size(); j++) {
        if (j != i-r) d.push_back(c[j]);
    }

    search(d, i+1, r+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    N = n;
    M = m;

    cows = vector<Cow>(n);
    vector<Cond> conds(m);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].l >> cows[i].r >> cows[i].t;
    }

    for (int i = 0; i < m; i++) {
        cin >> conds[i].l >> conds[i].r >> conds[i].p >> conds[i].m;
    }

    search(conds, 0, 0);

    cout << MIN;
}