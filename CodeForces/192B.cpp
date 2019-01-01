#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 1<<28;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[MAX], visited[MAX] = {0}, n, result;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        int Min = inf;
        for(int j = 0; j < n; j++){
            if(arr[j] < Min){
                Min = arr[j];
            }
        }
        for(int j = 0; j < n; j++){
            if(arr[j] == Min && !visited[j]){
                visited[j] = 1;
                if(j == 0 || j == n - 1){
                    result = arr[j];
                    break;
                }
                else if(visited[j-1] || visited[j+1]){
                    result = arr[j];
                    break;
                }
                else{
                    arr[j] = inf;
                }

            }
        }
    }

    cout<<result<<endl;

    return 0;
}
