// overhead

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
        int h = 0;
        int l;
        cin >> l;

        int overhead = 0;

        vector<bool> canOverhead(l);
        vector<pair<int, int>> lr(l);
        vector<int> d(l);

        for (int i = 0; i < l; i++)
        {
            int num;
            cin >> num;
            d[i] = num;
        }

        for (int i = 0; i < l; i++)
        {
            int l, r;
            cin >> l >> r;

            lr[i] = make_pair(l, r);
        }

        bool nf = false;
        for (int i = 0; i < l; i++)
        {
            if (d[i] != -1)
            {
                h += d[i];

                canOverhead[i] = false;

                if (h < lr[i].first)
                {
                    if (h + overhead < lr[i].first)
                    {
                        nf = true;
                        break;
                    }
                    else
                    {
                        overhead -= (lr[i].first - h);
                        h = lr[i].first;
                        
                    }
                }
                if (h > lr[i].second)
                {
                    nf = true;
                    break;
                }
            }
            else
            {
                bool hash = false;
                if (lr[i].first > h)
                {
                    if (lr[i].first > h + 1)
                    {
                        if (lr[i].first > h + overhead)
                        {
                            nf = true;
                            break;
                        }
                        else
                        {
                            
                            d[i] = 1;
                            int a = overhead;
                            overhead -= (lr[i].first - h);
                            int diff = a - overhead;
                            h = lr[i].first;
                            
                            

                            
                            
                            int j = i-1;

                            
                            while (j > 0 && diff > 0)
                            {  
                                if (d[j] == -1)
                                {
                                    
                                    if (canOverhead[j])
                                    {
                                        d[j] = 1;
                                        diff--;
                                    }
                                    else
                                    {
                                        nf = true;
                                        break;
                                    }
                                }
                                j--;
                            }
                            if (nf) break;
                        }
                    }

                    d[i] = 1;
                    h++;
                    hash = true;
                }

                if (lr[i].second < (hash ? h : h + 1))
                {
                    d[i] = 0;
                    canOverhead[i] = false;
                }
                else {
                    overhead++;
                    canOverhead[i] = true;
                }
                    

                if (lr[i].second < h)
                {
                    nf = true;
                    break;
                }
            }
        }

        if (nf) cout << "-1";
        else for (int i = 0; i < l; i++) {
            cout << (d[i] == -1 ? 0 : d[i]) << " ";
        }
        cout << endl;
    }
}