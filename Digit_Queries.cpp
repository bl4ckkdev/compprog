#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    //long long iter = 158888888888888857-100;
    while (t--) {
        //if (iter > 158888888888888857+100) break;
        //iter++;
        long long k; cin >> k;

        //cout << k << " ";

        long long tk = k;
        //cout << tk<<"_";
        string t = "8";
        string resstr = "";
        long long res = 0;

        //cout << tk << " ";
        for (long long i = 1; i <= 18; i++) {
            long long aa = 9;
            
            if (i>1) {
                t += "9";
                aa = stoll(t);
            } 
            if (tk-i+1>aa*i) {
                //tk-=i;
                //cout << aa*i+i << " ";
                //cout << aa*i-i << " ";
                tk-=aa*(i)+i;
                //cout << "-"<<aa<<"-";
            }
            else if (tk-i+1<=aa*i) {
                if (i>1) {
                    //cout << "_" << tk << "_" << i << "_";
                    //cout << "a" << (long long)(tk/i) + (long long)pow(10LL, i-1) << " ";

                    res = to_string((long long)(tk/i) + (long long)pow(10LL, i-1))[tk%(i)]- '0';
                    //cout << "|" << i << "," << tk << "|";
                    resstr = to_string((long long)(tk/i) + (long long)pow(10LL, i-1));
                } 
                else {
                    res = k;
                    resstr = to_string((long)k);
                }

                //cout << i << " ";
                break;
            }
        }

        cout << res << endl;
    }
}