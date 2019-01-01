// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    char str[200];

    cin>>str;

    int l, r;
    char c1, c2;

    for(int i = 0; i < m; i++){
        cin>>l>>r>>c1>>c2;
        l--, r--;

        for(int j = l; j <= r; j++){
            if(str[j] == c1)
                str[j] = c2;
        }
    }

    cout<<str<<endl;

    return 0;
}
