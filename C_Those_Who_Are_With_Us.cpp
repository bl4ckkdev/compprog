#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;*/



        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] > max) max = matrix[i][j];
            }
        }

        int col = -1;
        int row = -1;

        bool lockcol = false, lockrow = false;
        int output = max-1;

        
        bool cooked = false;

        vector<int> rows(n);
        vector<int> cols(m);

        int maxes = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == max) maxes++;
            }
        }

        //if (m>=2 && n>2) cout << "COLUMN" << matrix[2][0] << "   ";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[j][i] == max) cols[i]++;
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                    if (matrix[j][i] == max) rows[j]++;
            }
        }


        int intermax = 0;
        bool br = false;

        //cout << n << " " << m << "   ";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == max) {
                    if (rows[i] + cols[j] - 1 >= maxes) {
                        cout << max-1 << endl;
                        br = true;
                        break;
                    }
                }
                else if (rows[i] + cols[j] >= maxes) {

                    cout << max-1 << endl;
                    br = true;
                    break;
                }
            }
            if (br) break;
        }

        if (!br) {
            //cout << "ULTRA MODE" << maxes << endl;

            //cout << rows.size() << "   ";
            /*for (auto& i : cols) cout << i << " ";
            cout << endl;
            for (auto& i : rows) cout << i << " ";
            cout << endl;*/

            cout << max << endl;//<<endl;
        } 

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == max && (col == -1 || row == -1)) {
                    col = i;
                    row = j;
                } else if (matrix[i][j] == max) {
                    //cout << "AA " << i << " " << col << " " << j << " " << row << endl;
                    if (i != col && row != j) {
                        output++;
                        cooked = true;
                        break;
                    } else if (!lockrow && i != col && row == j) {
                        lockrow = true;
                    } else if (!lockcol && i == col && row != j) {
                        lockcol = true;
                    } else {
                        output++;
                        cooked = true;
                        break;
                    }
                }
            }

            if (cooked) break;
        }*/

        //cout << output << endl;
    }
}