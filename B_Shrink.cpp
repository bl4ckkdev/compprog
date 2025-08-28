#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        vector<int> a(n, 1);
        
        int pointer = ceil(n/2);
        int scale = 0;
        for (int i = n; i > 0; i--) {
            if (pointer >= n || pointer < 0) continue;

            a[pointer] = i;

            if (scale>0) scale++;
            else if (scale<0) scale--;

            scale *= -1;
            if (scale == 0) scale = -1;
            //cout << pointer << " ";
            pointer += scale;
        }
        //cout << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}