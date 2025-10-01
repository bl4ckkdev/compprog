#include <bits/stdc++.h>

using namespace std;

struct aa {
    int a, b, c; // creative naming
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        cin.ignore(1);

        int n, m; cin >> n >> m;

        vector<aa> nums(m);

        for (int i = 0; i < m; ++i) {
            cin >> nums[i].a;
            cin >> nums[i].b;
            nums[i].c = i;
        }

        

        sort(begin(nums), end(nums), [](aa& a, aa& b) {
            return a.b<b.b;
        });


        int l = 0, r = 2*n-1;
        int s = 0;

        for (int i = 0; i < 2*n; ++i) {
            s += nums[i].b;
        }

        vector<aa> nums2(2*n);

        for (int i = 0; i < 2*n; i++) {
            nums2[i] = nums[i];
        }

        sort(begin(nums2), end(nums2), [](aa& a, aa& b){
            return a.a<b.a;
        });


        cout << s << endl;
        while (l<r) {
            cout << nums2[l].c+1 << " " << nums2[r].c+1 << endl;
            ++l; --r;
        }

        cout << endl;
    }
}