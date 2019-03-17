//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l[MAX], r[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>l[i]>>r[i];
    }
    int k;
    cin>>k;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(k <= r[i]){
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
