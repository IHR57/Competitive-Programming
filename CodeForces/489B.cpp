#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    int boys[MAX], girls[MAX], visited[MAX] = {0};

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>boys[i];
    }

    cin>>m;

    for(int i = 0; i < m; i++){
        cin>>girls[i];
    }

    sort(boys, boys + n);
    sort(girls, girls + m);

    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(abs(boys[i] - girls[j]) <= 1 && !visited[j]){
                visited[j] = 1;
                cnt++;
                break;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
