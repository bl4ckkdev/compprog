#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char a; cin >> a;
            g[i][j] = (int)a;
        }
    }


    //cout << n;
    for (int i = 0; i < n; i++) {
        //cout << "a";
        if (g[i][i] != g[i][n-i-1]) {
            //cout << g[i][i] << " " << g[i][n-i-1];
            cout << "NO";
            return 0;
        } //else cout << g[i][i] << " " << g[i][n-i-1] << endl;
    }

    int as = g[0][0];
    int ns = g[0][1];
    

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n; j++) {
            //cout << g[i][j] << endl;
            
            if (i == j || n-j-1 == i ) {
                if (g[i][j] != as) {
                    cout << "NO";
                    return 0;
                } 
            } else if (g[i][j] != ns) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << (as != ns ? "YES" : "NO");
    return 0;
}