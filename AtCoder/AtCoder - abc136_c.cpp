#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, h[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>h[i];
    }

    h[0]--;
    for(int i = 1; i < n; i++){
        if(h[i] > h[i-1])
            h[i]--;
        if(h[i] < h[i-1]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;

    return 0;
}

