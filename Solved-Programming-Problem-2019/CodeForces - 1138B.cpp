#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

vector<int> v[4];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    string s, t;

    cin>>n;
    cin>>s>>t;

    for(int i = 0; i < n; i++){
        if(s[i] == '0' && t[i] == '0')
            v[0].push_back(i + 1);
        else if(s[i] == '0' && t[i] == '1')
            v[1].push_back(i + 1);
        else if(s[i] == '1' && t[i] == '0')
            v[2].push_back(i + 1);
        else
            v[3].push_back(i + 1);
    }

    int na = v[0].size(), nb = v[1].size(), nc = v[2].size(), nd = v[3].size();

    int a, b, c, d, flag = 0;
    for(int i = 0; i <= nc; i++){
        for(int j = 0; j <= nd; j++){
            c = i, d = j;
            b = nb + nd - c - 2 * d;
            a = (n / 2) - b - c - d;
            if(b >= 0 && b <= nb && a >= 0 && a <= na){
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag){
        cout<<-1<<endl;
    }
    else{
        for(int i = 0; i < a; i++)
            cout<<v[0][i]<<" ";
        for(int i = 0; i < b; i++)
            cout<<v[1][i]<<" ";
        for(int i = 0; i < c; i++)
            cout<<v[2][i]<<" ";
        for(int i = 0; i < d; i++)
            cout<<v[3][i]<<" ";
    }
    cout<<endl;

    return 0;
}