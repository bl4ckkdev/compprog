#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        multiset<int> nums;
        vector<int> fakenums(n);

        for (int i = 1; i <= n; i++) {
            nums.insert(i);
        }

        long long peak = 1;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            

            fakenums[i] = num;

            if (num > peak) peak = num;
        }

        sort(fakenums.begin(), fakenums.end());

        bool ff = false;
        for (int i = 0; i < n; i++) {
            long long num = fakenums[i];
            bool found = false;
            
                cout << num;
                cout <<"A";
            while (num > 1) {
                
                if (nums.count(num) == 0) {
                    num /= 2;
                    found = false;
                    
                }
                else {
                    //cout << num << "A" << endl;
                    
                   // auto j = nums.find(num);
                    //if (j == nums.end()) j = nums.find(num+1);
                    
                    //if (j != nums.end()) {
                        //cout << "J IN ACTION!" << endl;
                    nums.erase(num);
                    //}
                    //if (nums.count(num) >= 1) {
                    //    int cnt = nums.count(num)-1;
                    //    nums.erase(num);
                    //    while (cnt--) nums.insert(num);
                    //} 
                    //else if (nums.count(num+1) >= 1) {
                    //    int cnt = nums.count(num+1)-1;
                    //    nums.erase(num+1);
                    //    while (cnt--) nums.insert(num+1);
                    //} 
                    found = true;
                    break;
                } 
            }

            if (!found) {
                ff = true;
                cout << "NO" << endl;
                break;
            } 
        }

        if (!ff) cout << "YES" << endl;
    }
}