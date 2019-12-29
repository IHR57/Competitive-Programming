//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 505
using namespace std;

typedef long long ll;

int a[MAX][MAX], b[MAX][MAX], n, m;
int visited[MAX][MAX];

bool check(int x, int y)
{
    int k = y + 1;
    for(int i = x - 1; i >= 0 && k < m; i--){
        if(!visited[i][k] && a[i][k] == b[x][y]){
            visited[x][y] = 1;
            swap(a[i][k], a[x][y]);
            return true;
        }
        k++;
    }

    k = y - 1;
    for(int i = x + 1; i < n && k >= 0; i++){
        if(!visited[i][k] && a[i][k] == b[x][y]){
            visited[x][y] = 1;
            swap(a[i][k], a[x][y]);
            return true;
        }
        k--;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin>>b[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]){
                if(!check(i, j)){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else{
                visited[i][j] = 1;
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
