#include <bits/stdc++.h>

using namespace std;

set<char> ind;
set<string> team;

void checkstring(string& str) {
    set<char> st;

    for (int i = 0; i < str.length(); i++) {
        st.insert(str[i]);
    }

    if (st.size()==2) {
        team.insert("" + *st.begin() + *next(st.begin()));
    }
    if (st.size()==1) {
        ind.insert(*st.begin());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    string a, b, c; cin >> a >> b >> c;
    string dl = "", dr = "", ua ="", ub = "", uc = "";

    dl = ((dl + a[0]) + b[1]) + c[2];
    dr = ((dr + a[2]) + b[1]) + c[0];

    ua = ((ua + a[0]) + b[0]) + c[0];
    ub += ((ub + a[1]) + b[1]) + c[1];
    uc += ((uc + a[2]) += b[2]) += c[2];

    checkstring(dl);
    checkstring(dr);
    checkstring(a);
    checkstring(b);
    checkstring(c);
    checkstring(ua);
    checkstring(ub);
    checkstring(uc);

    cout << ind.size() << endl << team.size();
}