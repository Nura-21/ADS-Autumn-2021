#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int cntNotPrimes(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!isPrime(i))
            cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << cntNotPrimes(n);
    return 0;
}