#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
ll lcm(int a,int b)
{
    return (a*b)/gcd(a,b);

    // Time complexity : O(log(min(a,b)))
    // Auxillary space : O(log(min(a,b)))
    // Logic : this solution is based on the fact that a*b=LCM(a,b)*GCD(a,b)
}
int main()
{
    int n,m;
    cin >> n>>m;
    cout << lcm(n,m) << endl;
    return 0;
}