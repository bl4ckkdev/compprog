#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> students(n);
    vector<int> tasks(n);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        students[i] = num;
        tasks[i] = num;
    }

    sort(students.begin(), students.end());
    sort(tasks.begin(), tasks.end(), greater<int>());

    vector<long long> time(n);

    for (int i = 0; i < n; i++) {
        time[i] = ((long long)students[i] * tasks[i]);
    }

    long long timee = 0;
    for (int i = 0; i < n; i++) {
        timee += time[i];
    }

    cout << (timee % 10007) << endl;
}