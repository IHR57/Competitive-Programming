#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, visited[110] = {0};
    int x, y;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>x;
        for(int i = 0; i < x; i++){
            cin>>y;
            visited[y] = 1;
        }
    }

    int flag = 1;

    for(int i = 1; i <= m; i++){
        if(visited[i] == 0){
            flag = 0;
            break;
        }
    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
