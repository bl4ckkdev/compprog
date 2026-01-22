#include <bits/stdc++.h>

using namespace std;

void give() {
    int m, t; cin >> m >> t;

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

        for (int i = 0; i < n; i++) {
            if (!p) freq[nums[i]-1] = 1;

            if (nums[i]==peak) p = true;

            else if (p) {
                freq[23-nums[i]] = 1;
            }
        }


        string fin = to_string(freq[20]) + to_string(freq[21]) + to_string(freq[22]);
        int cnt = 0;

        if (fin[0] - '0' == 1) {
            cnt += 2;
        } else if (fin[1] - '0' || fin[2] - '0') {
            cnt += 1;
        }

        //cout << 20+cnt << endl;

        
        for (int i = 0; i < 20; i++) {
            cout << freq[i];
        }
        if (fin[0] - '0' == 1) {
            cout << fin[2] << fin[1];
        } else if (fin[1] - '0' || fin[2] - '0') {
            cout << fin[2];
        }

        cout << endl;
    }
}

void take() {
    int m, t; cin >> m >> t;

    while (t--) {
        string s; cin >> s;

        vector<int> nums;

        for (int i = 0; i < 11; i++) {
            if (s[i] - '0' == 1) {
                nums.push_back(i+1);
            }
        }

        if (s[11] - '0' == 1) nums.push_back(12);

        for (int i = 12; i < 20; i++) {
            if (s[i] - '0' == 1) {
                nums.push_back(12-(i-11));
            }
        }

        if (s.length() == 22) {
            nums.push_back(3);
            if (s[21] - '0' == 1) nums.push_back(2);
            if (s[20] - '0' == 1) nums.push_back(1);

            
        } else if (s.length() == 21) {
            if (s[20] - '0' == 1) nums.push_back(1);
            else nums.push_back(2);
        }

        cout << nums.size() << endl;
        for (auto & i : nums) cout << i << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    give();
    cout << "\n--------\n\n";
    take();

    return 0;
}