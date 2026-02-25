#include <bits/stdc++.h>

using namespace std;

void give() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        vector<int> freq(23);

        int peak = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            peak = max(peak, nums[i]);
        }

        bool p = false;
        int mode = 0;

        for (int i = 0; i < n; i++) {
            if (!p) freq[nums[i]-1] = 1;

            if (nums[i] == peak)
            {
                if (i == 0)
                    mode = 1;
                else if (i == n - 1)
                    mode = 2;

                p = true;
            }

            else if (p) {
                freq[23-nums[i]] = 1;
            }
        }


        if (mode == 0) {
         
        string fin = to_string(freq[20]) + to_string(freq[21]) + to_string(freq[22]);
        //cout << fin << " ";
        int cnt = 0;

        if (fin[0] - '0' == 1) {
            cnt += 2;
        } else if (fin[1] - '0' || fin[2] - '0') {
            cnt += 1;
        }

        //cout << 20+cnt << endl;

        

        
        for (int i = 0; i < 23; i++) {
            cout << freq[i];
        }
        /*if (fin[0] - '0' == 1) {
            cout << fin[2] << fin[1];
        } else if (fin[1] - '0' || fin[2] - '0') {
            cout << fin[2];
        }*/

        cout << endl;
    } else if (mode == 1)
        {
            cout << 0;


            for (int i = 11; i < 23; i++) {
                if (23-i == peak) {
                    cout << 1;
                }
                else cout << freq[i];
            }

            cout << endl;
        } else if (mode == 2)
        {
            cout << 1;

            for (int i = 0; i < 12; i++) {
                cout << freq[i];
            }
            
            cout << endl;
        }
    }
}

void take() {
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        vector<int> nums;
        if (s.length()<15) {
            int mode = s[0] - '0';

            if (mode == 1) {

                for (int i = 1; i < 13; i++) {
                    if (s[i] - '0') nums.push_back(i);
                }
            } else {
                for (int i = 1; i < 13; i++) {
                    if (s[i] - '0') nums.push_back(13-i);
                }
            }
        }
        else {

        for (int i = 0; i < 11; i++) {
            if (s[i] - '0' == 1) {
                nums.push_back(i+1);
            }
        }

        if (s[11] - '0' == 1) nums.push_back(12);

        for (int i = 12; i < 23; i++) {
            if (s[i] - '0' == 1) {
                nums.push_back(12-(i-11));
            }
        }

        /*
        if (s.length() == 22) {
            nums.push_back(3);
            if (s[21] - '0' == 1) nums.push_back(2);
            if (s[20] - '0' == 1) nums.push_back(1);

            
        } else if (s.length() == 21) {
            if (s[20] - '0' == 1) nums.push_back(1);
            else nums.push_back(2);
        }*/


    }
            cout << nums.size() << endl;
        for (auto & i : nums) cout << i << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;

    if (m == 1) 
    give();
    else
    take();

    return 0;
}