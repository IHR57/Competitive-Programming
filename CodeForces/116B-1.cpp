#include <bits/stdc++.h>
#define MAX 30
using namespace std;

typedef pair<int, int> pii;

//direction array
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int cell[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int row, col;
    pii wolves[MAX*MAX];

    cin>>row>>col;

    int k = 0;

    for(int i = 0; i < row; i++){
        char ch[MAX];
        cin>>ch;
        for(int j = 0; j < col; j++){
            if(ch[j] == 'W'){
                cell[i][j] = 2;
                wolves[k++] = make_pair(i, j);
            }
            else if(ch[j] == 'P')
                cell[i][j] = 1;
            else
                cell[i][j] = -1;
        }
    }

    int count = 0;

    for(int i = 0; i < k; i++){
        //bool flag = false;
        for(int j = 0; j < 4; j++){
            int tx = wolves[i].first + fx[j];
            int ty = wolves[i].second + fy[j];
            if(cell[tx][ty] == 1){
                count++;
                cell[tx][ty] = -1;
                break;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}
