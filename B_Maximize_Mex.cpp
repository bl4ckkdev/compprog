#include <bits/stdc++.h>

using namespace std;

long long mex(vector<long long> const &A)
{
    set<long long> b(A.begin(), A.end());

    long long result = 0;
    while (b.count(result))
        ++result;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        long long n, x;
        cin >> n >> x;

        vector<long long> nums(n);
        vector<long long> freq(2*n+10, 0);

        for (long long i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i]<=2*n)freq[nums[i]]++;
        }

        for (long long i = 0; i < n-x; i++) {
            if (freq[i]>1) {
                freq[i+x] += freq[i]-1;
                freq[i] = 1;
            } 
        }

        
        long long mx = 0;
        for (long long i = 0; i <= n; i++) {
            if (freq[i] == 0) {
                mx = i;
                break;
            }
        }
        //cout << endl;


        // for (auto& i : nums) cout << i << " ";
        
        cout << mx << endl;

        /*for (long long i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] > 1) {
                gaps.push_back({nums[i-1], nums[i]-nums[i-1]-1});
            }
        }

        gaps.push_back({nums[n-1], dup});

        for (long long i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) {
                for (long long j = 0; j < gaps.size(); j++) {
                    if (nums[i] <= gaps[j].first && (gaps[j].first+1-nums[i]) % x < gaps[j].second) {
                        //cout << nums[i] << " ";
                        nums[i] = gaps[j].first + ((gaps[j].first+1)%x);

                        if (gaps[j].second == 1) {
                            gaps.erase(gaps.begin()+j);
                        }
                        else if (nums[i]>gaps[j].first+1) {
                            gaps.push_back({nums[i], gaps[j].second - (nums[i] - gaps[j].first)});
                            sort(gaps.begin(), gaps.end());
                            gaps[j].second = nums[i] - gaps[j].first - 1;
                        } else {
                            gaps[j].first = nums[i];
                            gaps[j].second--;
                        }
                        break;
                    }
                }
            }
        }

        long long mx = mex(nums);

        cout << mx << endl;*/
    }
}