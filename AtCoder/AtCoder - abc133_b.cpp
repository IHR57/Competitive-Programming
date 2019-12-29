#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int x[30][30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, d;

    cin>>n>>d;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin>>x[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = 0;
            for(int k = 0; k < d; k++){
                sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            int sq = sqrt(sum);
            if(sq * sq == sum){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;


    return 0;
}

