#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        string s; cin >> s;

        vector<int> freq(30);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        int even = 0, odd = 0;

        for (int i = 0; i < 30; i++) {
            even += freq[i] / 2;
            odd += freq[i]%2;
        }


        int res = 2*(even/k);
        odd += 2* (even%k);

        if (odd >= k) res++;
        cout << res <<"\n";



        // Introducing the:
        // "What the fuck was I thinking." solution(tm)
        /*
        string sa = "", sb = "";

        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] % 2 == 1) {
                sb += s[i];

                freq[s[i] - 'a']--;
            } 
            else sa += s[i];
        }


        sort(begin(sa), end(sa));

        int ml = 1e9;

        vector<string> c;
        
        int sz = sa.length();

        string w = "";
        int cnt = 0;
        int cntt = 0;
        int seg = 0;
        for (int i = 0; i < sz; i++) {
            cnt++;
            w += sa[i];
            
            if ((((i) % 2) && cnt >= sz/k) || i == sz-1) {
                
                seg++;
                if (ml == w.size()) {
                    cntt = 0;
                } else if (w.size() < ml) {
                    cntt++;
                }
                //cout << w << " " ;
                c.push_back(w);
                ml = min(ml, (int)w.size());
                w = "";
                cnt = 0;
            }
        }
        ml = 1e9;
        sort(begin(c), end(c), [](auto& a, auto& b){
            return a.length()>b.length();
        });


        for (int i = c.size()-1; i >= 0; i--) {
            if (sb.size() == 0) break;

            c[i] += sb[0];
            sb = sb.substr(1, sb.size()-1);
        }

        int csz = c.size();
        int l = 0, r = csz-1;

        if (c.size()>0) {
            int ore = min(c[c.size()-1].size()+1, c[0].size());

            while (l<r) {
                if (c[l].size() % 2 == 1) l++;
                if (c[r].size() % 2 == 1) r--;

                if (c[r].size()>=ore) break;

                c[r] += c[l][c[l].size()-1];
                c[l] = c[l].substr(0, c[l].size()-1);
            }
        }
        
        for (auto& i : c) {
            ml = min(ml, (int)i.length());
            //cout << i << " ";
        } 
        
        if (ml == 1e9) ml = 0;
        //if (sb.size()>=cntt && sb.size()>0) ml++;
        //if (seg < k) ml = 1;
        cout << ml << endl;*/
    }
}