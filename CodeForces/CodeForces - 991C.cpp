//BISMILLAHIR RAHMANIR RAHIM
//Problem ID: CodeForces - 991C (Candies)
//Programmer: IQBAL HOSSAIN     Description: Binary Search
//Date: 23/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;

    cin>>n;

    ll k = 0, low = 1, high = n - 1, mid, cnt, ans;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        ll temp = n;
        cnt = 0;
        while(temp >= 10){
            cnt += min(mid, temp);
            temp -= min(mid, temp);
            temp -= (temp / 10);
        }
        ll t = temp + cnt;
        if(t >= (n + 1) / 2){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<low<<endl;

    return 0;
}
