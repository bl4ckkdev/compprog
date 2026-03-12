#include <bits/stdc++.h>

using namespace std;

int reactions(int N, std::vector<int> D, std::vector<long long> T) {
    int n = N;
    vector<int> d = D; vector<long long> t = T;

    vector<int> negs;

    negs.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (d[i]<0) negs.push_back(i);
    }

    if (negs.size() == N+1) {
        set<pair<int, int>> need;

        vector<int> suffix(n+1);
        vector<int> prefix(n+1);

        for (int i = n-1; i >= 0; i--) {
            suffix[i] = suffix[i+1] + d[i];
        }

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + d[i-1];
        }

        for (int i = 0; i < n; i++) {
            need.insert({t[i] - prefix[i+1], i});
        } 

        int counter = 0;
        //for (auto& i : need) cout << i.first << " " << i.second << "  ";
        int maxcounter = 0;
        int got = 0;
        bool hascurr = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0) got -= d[i-1];
            if (i > 0 && need.count({t[i-1], i-1})) need.erase({t[i-1], i-1});
            
            if (removes.count(i-1)) need.erase()

            counter -= hascurr;

            //cout << (*begin(need)).first << " ";

            //cout << "A";
            //for (auto& i : need) cout << i.first << " " << i.second << " " << prefix[i.second+2] << endl;
            //cout << endl;
            hascurr = 0;

            set<pair<int,int>> removes;

            while ((*begin(need)).first <= got) {
                //cout << i << " " << (*begin(need)).first << " " << (*begin(need)).second << " " << prefix[(*begin(need)).second +2] << " " << prefix[i+1] << endl; 
                

                if ((*begin(need)).second == i) removes.insert(*begin(need));
                need.erase(*begin(need));

                //cout << "NOT: ";
                //cout << i << " " << (*begin(need)).first << " " << (*begin(need)).second << " " << prefix[(*begin(need)).second +2] << " " << prefix[i+1] << endl; 
               
                counter++;
                if (need.size()<1) break;
            }

            cout << counter << " ";
            
            if (need.size()<1) break;
        }

        return maxcounter;
    }
    else if (negs.size() <= 21) {
        long long mxr = 0;
        for (int i = 0; i < negs.size(); i++) {
            long long temp = 0, reactions = 0;

            int startidx = negs[i]+1;

            for (int j = startidx; j < n; j++) {
                temp += D[j];

                if (temp >= T[j]) reactions++;
            }

            mxr = max(mxr, reactions);
        }

        return mxr;     
    }
    else if (n <= 2000) {
        long long mxr = 0;
        for (int i = 0; i < n; i++) {
            long long temp = 0, reactions = 0;

            for (int j = i; j < n; j++) {
                temp += D[j];

                
                if (temp >= T[j]) reactions++;
            }

            mxr = max(mxr, reactions);
        }

        return mxr;
    }

    return -1;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> d(n); vector<long long> t(n);

    for (int i = 0; i < n; i++) cin >> d[i] >> t[i];

    cout << reactions(n, d, t);
}