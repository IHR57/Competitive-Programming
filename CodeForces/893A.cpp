// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int visited[10], n, value;

    cin>>n;

    visited[1] = visited[2] = visited[3] = 1;
    int flag = 0;

    cin>>value;
    if(value == 1)
        visited[2] = 0;
    else if(value == 2)
        visited[1] = 0;
    else
        flag = 1;

    int temp;
    for(int i = 1; i < n; i++){
        cin>>value;
        if(!visited[value])
            flag = 1;
        for(int j = 1; j <= 3; j++){
            if(visited[j] == 1 && j != value){
                temp = j;
            }
        }
        for(int j = 1; j <= 3; j++){
            if(visited[j] == 0){
                visited[j] = 1;
            }
        }
        visited[temp] = 0;
    }

    if(!flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
