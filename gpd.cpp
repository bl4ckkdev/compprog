#include <bits/stdc++.h>

using namespace std;

vector<long long> primes;

vector<long long> eratosthenesmalakia(long long n)
{
    vector<long long> factorization;
    for (long long d : primes)
    {
        if (d * d > n)
            break;
        while (n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);

    return factorization;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int en = t;

    long long peak = 0;
    vector<long long> numbers;

    while (t--)
    {
        long long n;
        cin >> n;

        numbers.push_back(n);
        peak = max(peak, n);
    }

    int n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    
    vector<long long> div = eratosthenesmalakia(peak);

    cout << div.size() << " ";

    for (int i = 0; i < en; i++)
    {

        if (numbers[i] % 2 == 0)
        {
            cout << 1 << endl;
            continue;
        }

        // cout << div.size() << endl;

        /*for (int j = 0; j < div.size(); j++) {
            if ((numbers[i] / div[j]) * div[j] == numbers[i]) {
                long long smaller = min(numbers[i] / div[j], div[j]);

                cout << smaller << endl;

                break;
            }
        }*/
    }
}