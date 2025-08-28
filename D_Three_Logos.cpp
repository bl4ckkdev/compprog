#include <bits/stdc++.h>

using namespace std;

bool d = false;

void check(vector<int> a, vector<int> b, vector<int> c, int idx) {
    if (idx == 3) {
        if (d) return;

        if (a[0] == b[0] && b[0] == c[0] && a[1] + b[1] + c[1] == a[0]) {
            d = true;
            cout << a[0] << endl;

            for (int i = 0; i < a[1]; i++) {
                for (int j = 0; j < a[0]; j++) {
                    cout << "A";
                }
                cout << endl;
            }

            

            for (int i = 0; i < b[1]; i++) {
                for (int j = 0; j < b[0]; j++) {
                    cout << "B";
                }
                cout << endl;
            }

            

            for (int i = 0; i < c[1]; i++) {
                for (int j = 0; j < c[0]; j++) {
                    cout << "C";
                }
                cout << endl;
            }
        }

        if (a[0] == b[0] + c[0] && a[1] + b[1] == a[0] && b[1] == c[1]) {
            d = true;
            cout << a[0] << endl;

            for (int i = 0; i < a[1]; i++) {
                for (int j = 0; j < a[0]; j++) {
                    cout << "A";
                }
                cout << endl;
            }

            for (int i = 0; i < b[1]; i++) {
                for (int j = 0; j < b[0]; j++) {
                    cout << "B";
                }
                for (int j = 0; j < c[0]; j++) {
                    cout << "C";
                }
                cout << endl;
            }
        }

        if (b[0] == a[0] + c[0] && b[1] + c[1] == b[0] && a[1] == c[1]) {
            d = true;
            cout << b[0] << endl;

            for (int i = 0; i < b[1]; i++) {
                for (int j = 0; j < b[0]; j++) {
                    cout << "B";
                }
                cout << endl;
            }

            for (int i = 0; i < a[1]; i++) {
                for (int j = 0; j < a[0]; j++) {
                    cout << "A";
                }
                for (int j = 0; j < c[0]; j++) {
                    cout << "C";
                }
                cout << endl;
            }
        }

        if (c[0] == b[0] + a[0] && c[1] + b[1] == c[0] && a[1] == b[1]) {
            d = true;
            cout << c[0] << endl;

            for (int i = 0; i < c[1]; i++) {
                for (int j = 0; j < c[0]; j++) {
                    cout << "C";
                }
                cout << endl;
            }

            for (int i = 0; i < a[1]; i++) {
                for (int j = 0; j < a[0]; j++) {
                    cout << "A";
                }
                for (int j = 0; j < b[0]; j++) {
                    cout << "B";
                }
                cout << endl;
            }
        }
    }

    if (idx == 0) {
        check(a, b, c, idx+1);
        swap(a[0], a[1]);  
        check(a, b, c, idx+1);
    } else if (idx == 1) {
        check(a, b, c, idx+1);
        swap(b[0], b[1]);  
        check(a, b, c, idx+1);
    } else if (idx == 2) {
        check(a, b, c, idx+1);
        swap(c[0], c[1]);  
        check(a, b, c, idx+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(2), b(2), c(2);

    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];

    check(a, b, c, 0);

    if (!d) cout << -1;
}