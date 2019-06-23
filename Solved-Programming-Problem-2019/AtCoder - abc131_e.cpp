#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;

int adjMat[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            adjMat[i][j] = 1;
        }
    }
    int MX = (n - 1) * (n - 2);
    MX /= 2;

    if(k > MX){
        cout<<-1<<endl;
        return 0;
    }

    int cnt = (n * (n - 1)) / 2 - k;
    cout<<cnt<<endl;

    for(int i = 2; i <= n; i++){
        cout<<1<<" "<<i<<endl;
        cnt--;
    }

    for(int i = 2; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(cnt <= 0){
                return 0;
            }
            else{
                cout<<i<<" "<<j<<endl;
                cnt--;
            }
        }
    }

    return 0;
}
