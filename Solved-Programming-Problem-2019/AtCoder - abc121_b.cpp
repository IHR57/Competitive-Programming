#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int arr[50][50];
int b[50];

int main()
{
    int n, m, c;

    cin>>n>>m>>c;

    for(int i = 0; i < m; i++)
        cin>>b[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }


    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < m; j++){
            sum += (arr[i][j] * b[j]);
        }
        sum += c;
        if(sum > 0)
            cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
