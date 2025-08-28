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
        int l, r, L, R;
        cin >> l >> r >> L >> R;

        int overlap = min(r, R) - max(l, L) + 1;

        if (l == L && r == R)
            overlap--;

        if (overlap > 0)
        {
            overlap++;
            
            if (l == L || r == R) overlap--;
        } else overlap = 1;

        cout << overlap << endl;
    }
}