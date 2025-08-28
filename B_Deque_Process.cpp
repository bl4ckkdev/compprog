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
        int n;
        cin >> n;
        deque<int> q;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            q.push_back(num);
        }

        int num = -1;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && i % 2 == 0)
            {
                if (q.front() >= q.back())
                {
                    num = q.front();

                    cout << "L";
                    q.pop_front();
                }
                else
                {
                    cout << "R";
                    num = q.back();
                    q.pop_back();
                }
            }
            else if (i > 0 && i % 2 == 1)
            {
                if (q.front() <= q.back())
                {
                    num = q.front();

                    cout << "L";
                    q.pop_front();
                }
                else
                {
                    cout << "R";
                    num = q.back();
                    q.pop_back();
                }
            }
            else
            {
                if (q.front() >= q.back())
                {
                    num = q.front();

                    cout << "L";

                    q.pop_front();
                }
                else
                {
                    num = q.back();

                    cout << "R";
                    q.pop_back();
                }
            }
        }

        cout << endl;
    }
}