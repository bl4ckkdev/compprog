#include <bits/stdc++.h>

using namespace std;

signed main()
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

        sort(nums.begin(), nums.end());

        long long divisor = nums[0];

        vector<long long> gcd;
        

        for (long long i = 1; i < n; i++)
        {
            if (nums[i] % divisor == 0)
                gcd.push_back(nums[i]);
        }


        bool nah = false;
        long long final_gcd = -1;
        if (gcd.size() > 0)
        {
            
            final_gcd = gcd[0];

            if (gcd.size() > 1)
                final_gcd = __gcd(gcd[0], gcd[1]);
            

            
            for (long long i = 0; i < gcd.size(); i++)
            {
                if (__gcd(final_gcd, gcd[i]) != final_gcd)
                    nah = true;

                // cout << __gcd(final_gcd, gcd[i]) << endl;
            }
        } else nah = true;

        
        if (final_gcd != divisor)
            nah = true;
        if (nah)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}