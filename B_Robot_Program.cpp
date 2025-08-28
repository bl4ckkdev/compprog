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
        long long n, x, k;
        cin >> n >> x >> k;

        string s;
        cin >> s;

        long long pos = x;
        long long seq = -1;
        // cout << "A" << x << endl;
        for (int i = 0; i < n; i++)
        {
            pos += (s[i] == 'R' ? 1 : -1);

            // cout << s[i] <<pos << endl;
            if (pos == 0)
            {
                seq = i;
                break;
            }
        }

        if (seq == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            long long olds = seq;
            pos = 0;
            seq = 0;

            for (int i = 0; i < n; i++)
            {
                pos += (s[i] == 'R' ? 1 : -1);

                //cout << "A " << s[i] << " " << pos << endl;

                if (pos == 0)
                {
                    seq = i;
                    break;
                }

                if (i == n-1) pos = -1;
            }


            cout << (pos == -1 ? 1 : (1 +(k-olds-1) / (seq+1))) << endl;
        }
    }
}