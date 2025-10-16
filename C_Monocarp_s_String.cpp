#include <bits/stdc++.h>

using namespace std;

signed main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums;
        nums.push_back(0);
        bool inv = 0;

        string s;
        cin >> s;
        int as = 0, bs = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                as++;
            else
                bs++;
        }

        if (s[0] == 'b')
            inv = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                nums.push_back(i);
            }
        }

        int sz = nums.size();
        if (as > bs)
        {
            int mx1 = 0, mx2 = 0;

            for (int i = inv; i < sz; i += 2)
            {
                int sizeze = 0;

                if (i == sz - 1)
                    sizeze = n - nums[i];
                else
                    sizeze = nums[i + 1] - nums[i];

                if (sizeze > mx1)
                {
                    mx1 = sizeze;
                    mx2 = nums[i];
                }
            }

            vector<pair<int, int>> poses;
            int it = 0;
            for (int i = inv; i < sz; i += 2)
            {
                int sizeze = 0;

                if (i == sz - 1)
                    sizeze = n - nums[i];
                else
                    sizeze = nums[i + 1] - nums[i];

                if (sizeze == mx1)
                {
                    poses.push_back({sizeze, nums[i]});
                    it++;
                }
            }

            int mnnn = 1e9;

            for (int i = 0; i < it; i++) {
                mx1 = poses[i].first;
                mx2 = poses[i].second;
    

            // precaculate all possibilities
            if (mx1 >= as - bs)
                mnnn = min(mnnn, (as - bs == n ? -1 : as - bs));
            else
            {
                int mn = 1e9;
                int ass = as-mx1, bss = bs;
                for (int i = mx2 - 1; i >= 0; i--)
                {
                    if (s[i] == 'a')
                        ass--;
                    else
                        bss--;

                    //cout << ass << " " << bss << "  ";

                    if (ass == bss)
                        mn = min(mn, mx1 + (mx2 - i));
                }

                int mn2 = 1e9;
                ass = as-mx1;
                bss = bs;
                //cout << mx1 << " " << mx2 << "   ";
                for (int i = mx2 + mx1; i < n; i++)
                {
                    if (s[i] == 'a')
                        ass--;
                    else
                        bss--;
                    //cout << ass << " " << bss << "  ";
                    if (ass == bss)
                        mn2 = min(mn2, i-mx2+1);
                }
                
                mn = min(mn, mn2);
                mnnn = min(mnnn, ((mn == 1e9 || mn == n) ? -1 : mn));
            }
        }
        cout << mnnn << endl;
        }
        else if (bs > as)
        {
            int mx1 = 0, mx2 = 0;

            for (int i = !inv; i < sz; i += 2)
            {
                int sizeze = 0;

                if (i == sz - 1)
                    sizeze = n - nums[i];
                else
                    sizeze = nums[i + 1] - nums[i];

                if (sizeze > mx1)
                {
                    mx1 = sizeze;
                    mx2 = nums[i];
                }
            }

            vector<pair<int, int>> poses;
            int it = 0;
            for (int i = !inv; i < sz; i += 2)
            {
                int sizeze = 0;

                if (i == sz - 1)
                    sizeze = n - nums[i];
                else
                    sizeze = nums[i + 1] - nums[i];

                if (sizeze == mx1)
                {
                    poses.push_back({sizeze, nums[i]});
                    it++;
                }
            }
            int mnnn = 1e9;
            for (int i = 0; i < it; i++) {
                mx1 = poses[i].first;
                mx2 = poses[i].second;

    

            // precaculate all possibilities
            if (mx1 >= abs(as - bs))
                mnnn = min(mnnn, (abs(as - bs) == n ? -1 : abs(as - bs)));
            else
            {
                int mn = 1e9;
                int ass = as, bss = bs-mx1;
                for (int i = mx2 - 1; i >= 0; i--)
                {
                    if (s[i] == 'a')
                        ass--;
                    else
                        bss--;

                    if (ass == bss)
                        mn = min(mn, mx1 + (mx2 - i));
                }

                int mn2 = 1e9;
                ass = as;
                bss = bs-mx1;

                for (int i = mx2 + mx1; i < n; i++)
                {
                    if (s[i] == 'a')
                        ass--;
                    else
                        bss--;
                    if (ass == bss)
                        mn2 = min(mn2, i-mx2+1);
                }
                
                mn = min(mn, mn2);
                mnnn = min(mnnn, (mn == 1e9 || mn == n) ? -1 : mn);
            }

        }
        cout << mnnn << endl;
        }
        else
            cout << 0 << "\n";
    }
}