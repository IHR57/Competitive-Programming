// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int row, col;
char str[200];
int number[20], used[20];
int grid[60][60];
int sx, sy, ex, ey;
int counter = 0;

void permutation(int pos, int n)
{
    if(pos == n){
        int len = strlen(str);
        int tx = sx, ty = sy;
        //cout<<number[0]<<" "<<number[1]<<" "<<number[2]<<" "<<number[3]<<endl;
        for(int i = 0; i < len; i++){
            int temp = str[i] - 48;
            if(temp == number[0]){
                tx = tx + 1, ty = ty;
            }
            else if(temp == number[1]){
                tx = tx, ty = ty - 1;
            }
            else if(temp == number[2]){
                tx = tx, ty = ty + 1;
            }
            else if(temp == number[3]){
                tx = tx - 1, ty = ty;
            }

            if(tx >= 0 && tx < row && ty >= 0 && ty < col && grid[tx][ty] != -1){
                if(tx == ex && ty == ey){
                    counter++;
                    break;
                }
            }
            else{
                break;
            }
        }
        return;
    }

    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = 1;
            number[pos] = i;
            permutation(pos + 1, n);
            used[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char st[200];

    cin>>row>>col;

    for(int i = 0; i < row; i++){
        cin>>st;
        for(int j = 0; j < col; j++){
            if(st[j] == 'S'){
                sx = i, sy = j;
                grid[i][j] = 0;
            }
            else if(st[j] == 'E'){
                ex = i, ey = j;
                grid[i][j] = 0;
            }
            else if(st[j] == '#'){
                grid[i][j] = -1;
            }
            else
                grid[i][j] = 0;
        }
    }

    cin>>str;
    permutation(0, 4);

    cout<<counter<<endl;

    return 0;
}
