#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum, diff; cin >> sum >> diff;
    
    //vector<pair<int, int>> pairs;

    //for (int i = 1; i <= 3; i++) {
      //  for (int j = 4; j <= 6; j++) {
    //        if (i+j >= sum) sums.insert(i+j);
    //    }
    //}

    double count = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i+j >= sum) count++;
            else if (abs(i - j) >= diff) {
                count++;
            }
        }
    }

    cout << setprecision(15) << (count/36) << endl;
}