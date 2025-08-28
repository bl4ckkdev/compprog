#include <bits/stdc++.h>

using namespace std;

string f;
set<char> uniq;
vector<string> res;

void gen(string a, int n, vector<int> freq) {
    if (n == f.length()) res.push_back(a);
    else {
        for (auto& i : uniq) {
            vector<int> friq = freq;
            if (friq[i - 'a'] > 0) {
                friq[i - 'a']--;
                gen(a+i, n+1, friq);
            }
        }
    }
}

int main() {
    cin >> f;

    vector<int> freq(100);

    for (auto& i : f) uniq.insert(i);
    for (auto& i : f) freq[i - 'a']++;

    gen("", 0, freq);

    cout << res.size() << endl;

    for (auto& i : res) cout << i << endl;

    return 0;
}