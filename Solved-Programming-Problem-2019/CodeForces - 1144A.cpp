//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int visited[50];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    int n;

    cin>>n;

    while(n--){
        cin>>str;
        int len = str.size();

        int Min = 1000000;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < len; i++){
            int idx = str[i] - 'a';
            if(idx < Min)
                Min = idx;
            visited[idx]++;
        }
        int cnt = 0;
        for(int i = Min; i < min(Min + len, 26); i++){
            if(visited[i] == 1){
                cnt++;
            }
        }
        if(cnt == len){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
