#include <bits/stdc++.h>

using namespace std;

int main() {
    string res; cin >> res;

    vector<int> ires(res.length());
    vector<int> nums(0);
    vector<int> maxes(res.length());
    
    int max = 0;
    


    for (int i = 0; i < res.length(); i++) {
        ires[i] = res[i] - '0';
    }

    

    for (int j = 0; j < res.length(); j++) {
        int mx = 0;
        int maxidx = 0;

        for (int i = j; i < res.length(); i++) {
            if (ires[i] >= mx) {
                mx = ires[i];
                maxidx = i;
            }
        }

        maxes[j] = maxidx;
    }

    int moves = 0;
    
    for (int i = 0; i < ires.size(); i++) {
        if (ires[i] == ires[maxes[i]]) {
            
            //cout << ires[i];
            moves += ires[i];

            for (int j = 0; j < nums.size(); j++) {
                nums[j] = (nums[j] == 9 ? 0 : nums[j] + 1);
            }
        } else {
            nums.push_back(10+ires[i] - ires[maxes[i]]);

            //cout << 10+ires[i] - ires[maxes[i]];
            moves += 10+ires[i] - ires[maxes[i]];

            
        }

        //if (i != ires.size()-1) moves++;
    }

    cout << nums.size() << endl;

    for (int i = 0; i < nums.size(); i++) {
        
    }

    cout << moves;

    return 0;
}