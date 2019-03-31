//Problem ID: CodeForces - 724B (Batch Sort)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 27/03/19
#include <bits/stdc++.h>
#define MAX 25
using namespace std;

int mat[MAX][MAX], tmat[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, flag[25];

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            for(int x = 0; x < n; x++){
                for(int y = 0; y < m; y++){
                    tmat[x][y] = mat[x][y];
                }
            }
            for(int x = 0; x < n; x++){
                tmat[x][i] = mat[x][j];
                tmat[x][j] = mat[x][i];
            }

            memset(flag, 0, sizeof(flag));

            for(int k = 0; k < n; k++){
                for(int x = 0; x < m; x++){
                    for(int y = x; y < m; y++){
                        swap(tmat[k][x], tmat[k][y]);
                        bool f = true;
                        for(int z = 0; z < m; z++){
                            if(tmat[k][z] != z + 1){
                                swap(tmat[k][x], tmat[k][y]);
                                f = false;
                                break;
                            }
                        }
                        if(f){
                            flag[k] = 1;
                            break;
                        }
                    }
                    if(flag[k])
                        break;
                }
            }
            bool isItOk = true;
            for(int k = 0; k < n; k++){
                if(flag[k] == 0){
                    isItOk = false;
                    break;
                }
            }
            if(isItOk){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}
