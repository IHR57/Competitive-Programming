#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

vector<int> v;
char str[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>val;
        v.push_back(val);
    }

    cin>>str;

    str[n-1] = '0';

    int r = 0, l = 0;
    while(r < n){
        if(str[l] == '0'){
            l++; r++;
        }
        while(r <  n && str[r] == '1'){
            r++;
        }
        sort(v.begin() + l, v.begin() + r + 1);
        l = r;
    }

    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i+1]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}
