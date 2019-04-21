//Problem ID: CodeForces - 1036B (Diagonal Walking v.2)
//Programmer: IQBAL HOSSAIN     Description: MATH
//Date: 15/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k;
    int q;

    cin>>q;

    while(q--){
        cin>>n>>m>>k;

        if(k < max(n, m)){
            cout<<-1<<endl;
            continue;
        }

        ll t = max(n, m);

        if((n + m) % 2 != 0){
            cout<<k-1<<endl;
        }
        else{
            if(k % 2 == t % 2){
                cout<<k<<endl;
            }
            else{
                cout<<k-2<<endl;
            }
        }

    }

    return 0;
}
