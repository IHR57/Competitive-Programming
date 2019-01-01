// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, h, a, b, k, t;
    int ta, fa, tb, fb;

    cin>>n>>h>>a>>b>>k;

    int ans;
    for(int i = 0; i < k; i++){
        ans = 0;
        cin>>ta>>fa>>tb>>fb;
        if(ta == tb){
            cout<<abs(fa - fb)<<endl;
            continue;
        }
        int m;
        if((fa >= a && fa <= b))
            m = 0, t = fa;
        else{
            int j = abs(fa - a);
            int l = abs(fa - b);
            m = min(j, l);
            if(fa < a) fa += (a - fa);
            else fa -= (fa - b);
        }
        //cout<<m<<endl;
        ans += m;
        ans += abs(ta - tb);
        ans += abs(fa - fb);

        cout<<ans<<endl;
    }

    //cout<<ans<<endl;

    return 0;
}

