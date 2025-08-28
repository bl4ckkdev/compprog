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
        string s;
        cin >> s;

        int sz = s.size();
        bitset<5000> f(s);

        int o = -1;
        int z = -1;

        for (int i = sz - 1; i >= 0; i--)
        {
            if (f[i] == 1)
            {
                o = i;
                break;
            }
        }

        if (o != -1)
        for (int i = o-1; i >= 0; i--)
        {
            if (f[i] == 0)
            {
                z = i;
                break;
            }
        }

        //cout << z << endl;

        if (o != -1 && z != -1)
        {
            //cout << "d\n";
            cout << 1 << " " << sz << " " << (sz-o) << " " << (sz-(o-z)) << endl;
        }
        else if (z != -1) {
            //cout << "y\n";
            cout << 1 << " " << sz << " " << 1 << " " << sz << endl;
        } else if (o != 1) {
            //cout << "yeah\n";
            cout << 1 << " " << sz << " " << sz << " " << sz << endl;
        }
    }

    return 0;
}