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
        int temp, fa, fb, xa, xb;
        cin >> temp >> fa >> fb >> xa >> xb;
        int count = 0;
        bool enda = false, endb = false;
        while (!enda || !endb)
        {

            if (!enda && (xa < xb || xb == -1))
            {
                if (temp >= fa)
                {
                    count += temp - fa + 1;
                    temp = fa;
                    temp -= xa;
                }
                else
                {
                    xa = -1;
                    enda = true;
                }
            }
            else
            {
                if (!endb && temp >= fb)
                {
                    count += temp - fb + 1;
                    temp = fb;
                    temp -= xb;
                }
                else
                {
                    xb = -1;
                    endb = true;
                }
            }
        }

        cout << count << endl;
        // ceil((100-17)/2) + ceil((16-5)/3)

        if (xa < xb)
        {
            int part1 = ceil((temp - fa) / xa);
            temp = fa - ((temp - fa)%xa == 0 ? xa : (temp - fa)%xa);
            int part2 = ceil((temp - fb) / (double)xb);

            cout << ((part1 > 0 ? part1 : 0) + (part2 > 0 ? part2 : 0)) << endl;
        }
        else
        {
            int part1 = ceil((temp - fb) / xb) + 1;
            temp = fb - ((temp - fb)%xb == 0 ? xb : (temp - fb)%xb);
            int part2 = ceil((temp - fa + 1) / (double)xa);
            cout << ((part1 > 0 ? part1 : 0) + (part2 > 0 ? part2 : 0)) << endl;
        }
    }
}