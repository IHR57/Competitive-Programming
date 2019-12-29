//Problem ID: CodeForces - 1141E (Superhero Battle)
//Programmer: IQBAL HOSSAIN     Description: MATH
//Date: 23/05/19
#include <bits/stdc++.h>
#define MAX 200005
#define mp make_pair
using namespace std;

typedef long long ll;

int d[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll H, n;
    cin>>H>>n;

    ll sum = H, cs = 0, Min = 1e18;
    bool flag = false;
    for(int i = 0; i < n; i++){
        cin>>d[i];
        sum += (ll) d[i];
        cs += (ll) d[i];
        if(sum <= 0 && !flag){
            Min = i + 1;
            flag = true;
        }
    }
    if(flag){
        cout<<Min<<endl;
        return 0;
    }

    if(cs >= 0){
        cout<<-1<<endl;
        return 0;
    }

    sum = 0;
    for(int i = 0; i < n; i++){
        sum += (ll) d[i];
        if(d[i] < 0){
            ll x = (H + sum) / abs(cs);
            if((H + sum) + ((x - 1) * cs)  <= 0){
                Min = min(Min, (n * (x - 1) + i + 1));
            }

            else if((H + sum)  + (x * cs)  <= 0){
                Min = min(Min, ((n * x) + i + 1));
            }
            else{
                Min = min(Min, ((n * (x + 1) + i + 1)));
            }
        }
    }

    cout<<Min<<endl;

    return 0;
}