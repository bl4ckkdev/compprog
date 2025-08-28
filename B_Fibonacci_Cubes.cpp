#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> f(20);

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i < f.size(); i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        n += 1;
        vector<int> h(m), w(m), l(m);


        for (int i = 0; i < m; i++)
        {
            cin >> w[i] >> l[i] >> h[i];
        }

        //for (int i = 0; i <= n; i++) {
        //    cout << f[i+1];
        //}

        for (int i = 0; i < m; i++) {
            if ((w[i] >= f[n] && l[i] >= f[n] && h[i] >= f[n]) && (h[i] >= f[n] + f[n-1] || w[i] >= f[n] + f[n-1] || l[i] >= f[n] + f[n-1])) {
                cout << "1";// << endl;
            } else {
                cout << "0";// << endl << w[i] << " " << l[i] << " " << h[i] << " " << f[n] << endl;
            } 
        }
        

        cout << endl;
    }
}