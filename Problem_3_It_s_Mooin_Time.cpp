#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, f;
    cin >> n >> f;

    string s;
    cin >> s;

    map<string, pair<int, vector<string>>> thr;

    string d = "";
    for (int i = 0; i < n - 2; i++)
    {
        string comb = ((d + s[i]) + s[i + 1]) + s[i + 2];
        thr[comb].first++;

        string area = "";

        for (int j = max(i-2, 0); j < min(n, i+5); j++) {
            area += s[j];
        }

        thr[comb].second.push_back(area);
    }

    set<string> setsts;

    for (auto &i : thr)
    {
        string ab = i.first;

        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 26; j++)
            {
                ab[k] = 97 + j;
                bool mino = false;

                if (i.first[k] == ab[k])
                    mino = true;
                if (ab[0] == ab[1] || ab[1] != ab[2])
                    continue;

                if ((thr.count(ab) > 0 && thr[ab].first + 1 - mino >= f) || f == 1 && thr.count(ab) == 0)
                {
                    if (thr[i.first].second.size() == 0)
                    {
                        setsts.insert(ab);
                    }

                    for (string &c : thr[i.first].second)
                    {
                        //cout << c.substr(k, 4+max(k, 1)) << " " << ab << " " << k << endl;
                        if (c.substr(k, 4+min(k, 1)).find(ab) == std::string::npos)
                        {
                            setsts.insert(ab);
                            break;
                        }
                    }
                }
            }
            ab = i.first;
        }
    }

    cout << setsts.size();

    for (auto &i : setsts)
        cout << endl
             << i;
}