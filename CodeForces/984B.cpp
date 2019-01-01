// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;

int cell[MAX][MAX];

int fx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int fy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;
    char str[MAX];

    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < m; j++){
            if(str[j] == '.'){
                cell[i][j] = 0;
            }
            else if(str[j] == '*'){
                cell[i][j] = -1;
            }
            else{
                cell[i][j] = str[j] - 48;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cell[i][j] == 0){
                for(int k = 0; k < 8; k++){
                    int tx = i + fx[k];
                    int ty = j + fy[k];
                    if(tx >= 0 && tx < n && ty >= 0 && ty < m){
                        if(cell[tx][ty] == -1){
                            cout<<"NO"<<endl;
                            return 0;
                        }
                    }
                }
            }
            else if(cell[i][j] > 0){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int tx = i + fx[k];
                    int ty = j + fy[k];
                    if(tx >= 0 && tx < n && ty >= 0 && ty < m){
                        if(cell[tx][ty] == -1){
                            cnt++;
                        }
                    }
                }
                if(cnt != cell[i][j]){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
