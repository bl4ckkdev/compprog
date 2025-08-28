#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s;
        cin >> n >> s;

        vector<int> nums(n);

        int ones = 0;
        int twos = 0;
        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];

            if (nums[i] == 1)
                ones++;
            if (nums[i] == 2)
                twos++;
            if (nums[i] == 0)
                zeros++;
        }

        vector<int> newnums(n);

        for (int i = 0; i < n; i++)
        {
            if (i < zeros)
                newnums[i] = 0;
            else if (i < zeros + twos)
                newnums[i] = 2;
            else
                newnums[i] = 1;
        }

        // for (auto& a : newnums) cout << a << " ";
        // cout << endl;

        // test 1
        bool cooked = true;
        int sc = twos * 2 + ones;


        if (sc == s) cooked = false;

        if (zeros > 0)
        {
            while (sc < s)
            {
                sc += 2;

                if ((s - (sc)) % 3 == 0)
                {
                    //cout << "yah";
                    cooked = false;
                    break;
                }
                if (sc == s)
                {
                    //cout << "yee";
                    cooked = false;
                    break;
                }
            }
        }

        // test 2
        sc = twos * 2 + ones;
        while (sc < s)
        {
            sc += 3;

            if (s - (sc) % 2 == 0)
            {
                //cout << "aee";
                cooked = false;
                break;
            }
            if (sc == s)
            {
                //cout << "yee";
                cooked = false;
                break;
            }
        }

        if (cooked) {
            for (auto& i : newnums) cout << i << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}