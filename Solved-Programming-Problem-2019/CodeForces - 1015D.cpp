//Problem ID: CodeForces - 1015D (Walking Between Houses)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 22/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k, s;

    cin>>n>>k>>s;

    ll temp = s / (n - 1);
    if(s % (n - 1) != 0)
        temp++;
    if(temp > k || k > s){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    ll curr = 1;
    while(k > 0){
        ll temp = min(n - 1, s - (k - 1));
        if(curr - temp > 0)
            curr = curr - temp;
        else
            curr = curr + temp;
        cout<<curr<<" ";
        s -= temp;
        k -= 1;
    }
    cout<<endl;

    return 0;
}
