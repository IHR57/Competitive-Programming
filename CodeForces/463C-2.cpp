#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

typedef long long ll;

ll grid[MAX][MAX], ld[MAX][MAX], rd[MAX][MAX], result[MAX][MAX];
int x1, Y1, x2, y2, x, y;
ll Max = -1, Max1 = -1, Max2 = -1;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    ll value;

    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        value = 0;
        k = 0;
        for(int j = i; j >= 0; j--){
            value += grid[k][j];
            k++;
        }
        k = 0;
        for(int j = i; j >= 0; j--){
            ld[k][j] = value;
            k++;
        }
    }
    for(int i = n - 1; i >= 1; i--){
        k = n-1, value = 0;
        for(int j = i; (n - j) >= 1; j++){
            value += grid[k][j];
            k--;
        }
        k = n-1;
        for(int j = i; (n - j) >= 1; j++){
            ld[k][j] = value;
            k--;
        }
    }

    for(int i = n-1; i >= 0; i--){
        value = 0, k = 0;
        for(int j = i; j < n; j++){
            value += grid[k][j];
            k++;
        }
        k = 0;
        for(int j = i; j < n; j++){
            rd[k][j] = value;
            k++;
        }
    }
    for(int i = 1; i < n; i++){
        value = 0, k =0;
        for(int j = i; j < n; j++){
            value += grid[j][k];
            k++;
        }
        k = 0;
        for(int j = i; j < n; j++){
            rd[j][k] = value;
            k++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i][j] = ld[i][j] + rd[i][j] - grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int dist = i + j;
            if(dist % 2 == 0){
                if(result[i][j] > Max1){
                    Max1 = result[i][j];
                    x1 = i; Y1 = j;
                }
            }
            else{
                if(result[i][j] > Max2){
                    Max2 = result[i][j];
                    x2 = i; y2 = j;
                }
            }
        }
    }

    int idx;
    ll temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int dist = i + j;
            if(dist % 2 == 0){
                temp = result[i][j] + Max2;
                if(temp > Max){
                    Max = temp;
                    x = i; y = j;
                    idx = dist;
                }
            }
            else{
                temp = result[i][j] + Max1;
                if(temp > Max){
                    Max = temp;
                    x = i; y = j;
                    idx = dist;
                }
            }
        }
    }

    cout<<Max<<endl;
    cout<<x + 1<<" "<<y + 1<<" ";
    if(idx % 2 == 0){
        cout<<x2 + 1<<" "<<y2 + 1<<endl;
    }
    else{
        cout<<x1 + 1<<" "<<Y1 + 1<<endl;
    }

    return 0;
}
