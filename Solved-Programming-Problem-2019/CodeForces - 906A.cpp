//Problem ID: CodeForces - 906A (Shockers)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 06/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int visited[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    char ch;
    int n, cnt = 0, ans = 0;

    cin>>n;

    int flag = 0;
    for(int j = 0; j < n; j++){
        cin>>ch>>str;
        int len = str.size();
        if(!flag && ch == '!'){
            cnt++;
            if(cnt >= 2){
                vector<int> mark(30, 0);
                for(int i = 0; i < len; i++){
                    if(visited[str[i]-'a'] == 1)
                        mark[str[i]-'a'] = 1;
                }
                for(int i = 0; i < 26; i++){
                    if(!mark[i])
                        visited[i] = -1;
                }
            }
            else{
                for(int i = 0; i < len; i++){
                    if(visited[str[i]-'a'] != -1)
                        visited[str[i]-'a'] = 1;
                }
            }
        }
        else if(!flag && ch == '.'){
            for(int i = 0; i < len; i++){
                visited[str[i]-'a'] = -1;
            }
        }
        else if(!flag && ch == '?'){
            visited[str[0]-'a'] = -1;
        }
        int k = 0, m = 0;
        if(!flag){
            for(int i = 0; i < 26; i++){
                if(visited[i] == 1)
                    k++;
                else if(visited[i] == -1)
                    m++;
            }
        }
        if(flag && (ch == '!' || ch == '?'))
            ans++;
        if((k == 1 || m == 25) && !flag){
            flag = 1;
            //cout<<i+1<<endl;
        }
    }

    if(!ans){
        cout<<ans<<endl;
    }
    else
        cout<<ans - 1<<endl;

    return 0;
}
