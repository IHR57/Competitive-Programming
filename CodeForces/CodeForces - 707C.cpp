//Problem ID: CodeForces - 707C (Pythagorean Triples)
//Programmer: IQBAL HOSSAIN     Description: MATH
//Date: 27/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k, ans;

    cin>>n;

    if(n <= 2){
        cout<<-1<<endl;
        return 0;
    }
    if(n % 2 == 0){
        k = (n - 1) >> 1;
        ans = (k * (((2 * 5) + (k - 1) * 2))) >> 1;
        ans = ans - ((k - 1) << 1);
        cout<<(ans - 2)<<" "<<ans<<endl;
    }
    else{
        k = n >> 1;
        ans = (k * (((2 * 4) + (k - 1) * 4))) >> 1;
        cout<<ans<<" "<<(ans + 1)<<endl;
    }

    return 0;
}
