#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

string str[MAX];
int visited[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    map<string, int> mp;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>str[i];
    }

    int idx = 0;
    for(int i = n - 1; i >= 0; i--){
        if(mp.find(str[i]) == mp.end()){
            mp[str[i]] = idx++;
        }
        if(!visited[mp[str[i]]]){
            visited[mp[str[i]]] = 1;
            cout<<str[i]<<endl;
        }
    }

    return 0;
}
