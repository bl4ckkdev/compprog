#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);

        int low = 1e9;
        int max = -1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] != -1) {
                if (a[i] < low) low = a[i];
            }
            
            if (a[i] > max) max = a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] != -1) {
                if (b[i] < low) low = b[i];
            }
            if (b[i] > max) max = b[i];
            
        }


        bool possible = true;

        int target = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != -1 && b[i] != -1) {
                if (target == -1) target = a[i] + b[i];
                else if (a[i] + b[i] != target) possible = false;
            }
            else if (a[i] != -1) {
                if (a[i] + k < target) possible = false;
            } else if (b[i] != -1) {
                if (b[i] + k < target) possible = false;
            }
        }

        if (target != -1 && target > 2*k) possible = false;
        if (target != -1 && max > target) possible = false;

        if (possible) {
            if (target == -1) {
                cout << k-max+low+1 << endl;
            } else {
                cout << 1 << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
}