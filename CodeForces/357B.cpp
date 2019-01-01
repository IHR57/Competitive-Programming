#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int a[MAX][4], arr[MAX];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, value, used[4];

    cin>>n>>m;

    memset(arr, -1, sizeof(arr));


    for(int i = 0; i < m; i++){
        for(int j = 0; j < 3; j++){
            cin>>a[i][j];
        }
    }

    int flag;
    for(int i = 0; i < m; i++){
        memset(used, 0, sizeof(used));
        for(int j = 0; j < 3; j++){
            int value = a[i][j];
            if(arr[value] != -1){
                used[arr[value]] = 1;
            }
        }

        for(int j = 0; j < 3; j++){
            int value = a[i][j];
            if(arr[value] == -1){
                if(!used[1])
                    arr[value] = 1, used[1] = 1;
                else if(!used[2])
                    arr[value] = 2, used[2] = 1;
                else
                    arr[value] = 3, used[3] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
