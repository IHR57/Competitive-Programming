#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n, b[MAX][MAX], c[MAX][MAX];

    cin>>m>>n;

    for(int i = 0; i < m; i++){
        for(int j =  0; j < n; j++){
            cin>>b[i][j];
            c[i][j] = b[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j] == 0){
                for(int k = 0; k < n; k++){
                    c[i][k] = 0;
                }
                for(int k = 0; k < m; k++){
                    c[k][j] = 0;
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            if(b[i][j] == 1){
                for(int k = 0; k < n; k++){
                    if(c[i][k] == 1)
                        cnt++;
                }
                for(int k = 0; k < m; k++){
                    if(c[k][j] == 1)
                        cnt++;
                }
                if(cnt < 1){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"YES"<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
