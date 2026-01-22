#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k; cin >> t >> k;

    while (t--) {
        int n; cin >> n;

        string s; cin >> s;
        string ne = "";
        int cnt = 0;

        for (int i = 0; i < s.length(); i+=3) {
            if (s[i] == 'C') ne+='1';
            else if (s[i] == 'O') ne+='1';
            else if (s[i] == 'W') ne+='3';
        }

        if (ne.length()%2 == 1) {
            cout << "-1\n";
            continue;
        }
        
        bool o = 0, t = 0, tr = 0;
        for (int i = 0; i < ne.length(); i++) {
            if (ne[i] == '1') o = 1;
            if (ne[i] == '2') t = 1;
            if (ne[i] == '3') tr = 1;

        }

        int ab = (o + t + tr);

        ne = regex_replace(ne, regex("3131"), "44");
        ne = regex_replace(ne, regex("1212"), "55");
        ne = regex_replace(ne, regex("1313"), "66");

        string nene = ne;

        int s1 = -1, s2 = -1;
        

        while (ne.length()>0) {
            int st = -1;
            int stcnt = cnt;
            for (int i = 1; i < ne.length(); i++) {
                if (ne[i] == ne[i-1] && st == -1) {
                    st = i-1;
                    if (s1 != -1) s2 = i;
                    s1 = i;
                } 
                else if (ne[i] != ne[i-1] && st != -1) {
                    
                    if ((i-st) % 2 == 1) {
                        ne.erase(st, i-st-1);
                        i--;
                        cnt++;                      
                    } else {
                        
                        ne.erase(st, i-st);
                        cnt++;
                    }

                }
            }
            
            if (st != -1 && cnt == stcnt) {
                ne.erase(st, (ne.length()-st) % 2 == 1 ? ne.length()-st-1 : ne.length()-st);
                cnt++;
            }

            if (st == -1) break;
        }

        int aa = (ne.length() == 0 ? cnt : 4);
        cout << min(ab, (ne.length() == 0 ? cnt : 4)) << endl;
        
        if (ab<aa) {
            if (o && t) {
                for (int i = 0; i < nene.length(); i++) {
                    if (nene[i] == '1') cout << "1 1 1 ";
                    if (nene[i] == '1') cout << "2 2 2 ";
                }
            }
            else if (o && tr) {
                for (int i = 0; i < nene.length(); i++) {
                    if (nene[i] == '1') cout << "1 1 1 ";
                    if (nene[i] == '3') cout << "2 2 2 ";
                }
            }
            else if (t && tr) {
                for (int i = 0; i < nene.length(); i++) {
                    if (nene[i] == '1') cout << "1 1 1 ";
                    if (nene[i] == '3') cout << "2 2 2 ";
                }
            }
            else if (t && tr && t) {
                for (int i = 0; i < nene.length(); i++) {
                    if (nene[i] == '1') cout << "1 1 1 ";
                    if (nene[i] == '1') cout << "2 2 2 ";
                    if (nene[i] == '3') cout << "3 3 3 ";
                }
            }
            else {
                for (int i = 0; i < nene.length(); i++) {
                    cout << "1 1 1 ";
                }
            }
        } else {
            if (s2 == -1) {
                for (int i = 0; i < 3*n; i++) {
                    cout << "1 ";
                }
            }
            else for (int i = 0; i < n; i++) {
                if (i<s2) cout << "1 1 1 ";
                else cout << "2 2 2 ";
            }
        }

        cout << endl;
        

        /*while (ne.length()>0) {
            int st = -1;
            int stcnt = cnt;
            for (int i = 1; i < ne.length(); i++) {
                if (ne[i] == ne[i-1] && st == -1) st = i-1;
                else if (ne[i] != ne[i-1] && st != -1) {
                    ne.erase(st, i-st+1);
                    cnt++;
                    cnt++;
                }
            }

            if (st != -1 && cnt == stcnt) {
                ne.erase(st, ne.length()-st);
                cnt++;
            }

            if (st == -1) break;
        }*/
        //cnt += ne.length();
    }
}