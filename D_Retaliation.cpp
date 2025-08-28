#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {

        long long n;
        cin >> n;

        vector<long long> nums(n);

        for (long long i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        bool cooked = false;
        long long dist = 0;

        bool sortdirection = false; // left = false, right = true
        for (long long i = 1; i < n; i++)
        {
            dist = nums[i] - nums[i - 1];
            if (nums[i] < nums[i - 1])
            {
                cooked = true;
            }
        }

        if (cooked)
        {
            bool doublecooked = false;
            for (long long i = 1; i < n; i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    doublecooked = true;
                    break;
                }
            }

            if (!doublecooked)
            {
                cooked = false;
                sortdirection = true;
            }
        }

        for (long long i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] != dist)
            {
                cooked = true;
            }
        }

        // cout << (abs(dist)+1) << endl;

        /*bool somewhatcooked = true;
        if (sortdirection) {
            long long cn = nums[n-1];

            int times = 0;
            while (cn >= n) {
                cn -= n;
                times++;

                if ((nums[n-2] - (n-2)*times) % cn == 0) {
                    somewhatcooked = false;
                    break;
                }
            }
        }

        if (!sortdirection) {

            long long cn = nums[0];

            int times = 0;
            while (cn >= n) {
                cn -= n;
                times++;

                if ((nums[1] - 2*times) % cn == 0) {
                    somewhatcooked = false;
                    break;
                }
            }
        }


        if (somewhatcooked) cooked = true;*/

        long long numer = nums[0] - dist;
        long long denom = n + 1;

        if (numer % denom != 0)
        {
            cooked = true;
        }
        else
        {
            long long k2 = numer / denom;

            if (k2 < 0)
            {
                cooked = true;
            }
            else
            {
                long long k1 = dist + k2;

                if (k1 < 0)
                {
                    cooked = true;
                }

                if (nums[0] != k1 + k2 * n)
                {
                    cooked = true;
                }
            }
        }

     cout << (cooked ? "NO" : "YES") << endl;
    }
}