#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y; cin >> x >> y;

    int l = 0, r = 0, d = 0, u = 0;
    string s; cin >> s;

    int cx = 0, cy = 0;
    int sz = s.length();
    for (int i = 0; i < sz; i++) {
        if (s[i] == 'U') {
            u++;
            cy++;
        } 
        else if (s[i] == 'D') {
            d++;
            cy--;
        } 
        else if (s[i] == 'L') {
            l++;
            cx--;
        } 
        else {
            r++;
            cx++;
        } 
    }

    bool cooked = false;

    /*if (cy>y) {
        if (d<abs(cy-y)) cooked = true;
    } else if (cy<y) {
        if (u<abs(cy-y)) cooked = true;
    }

    //cout << cx << " " << cy << "  " << x << " " << y << "  ";
    if (cx>x) {
        if (r<abs(cx-x)) {
            cooked = true;
            //cout << "aa";
        } 
    } else if (cx<x) {
        if (l<abs(cx-x)) {
            //cout << "aa";
        } 
    }*/


    if (y>0 && u<y) cooked = true;
    if (y<0 && d<abs(y)) cooked = true;
    if (x>0 && r<x) cooked = true;
    if (x<0 && l<abs(x)) cooked = true;

    cout << (cooked ? "No\n" : "Yes\n");
}