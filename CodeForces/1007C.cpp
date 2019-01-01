// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[MAX], b[MAX], n, counter[MAX] = {0};

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b, b + n, a[i]) - b;
        //cout<<a[i]<<" ";
        counter[a[i]]++;
    }
    //cout<<endl;

    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
    sort(b, b + n);


    int rem = 0, ans = 0;
    for(int i = 0; i < n; i++){
        int c = lower_bound(b, b + n, b[i]) - b;
        c -= ans;
        if(c){
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}

