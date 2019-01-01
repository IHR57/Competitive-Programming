#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

const int MAX = 105;
const int INF = 1 << 28;
int matrix[MAX][MAX];

void floydWarshall()
{
    for(int k = 1; k < MAX; k++){
        for(int i = 1; i < MAX; i++){
            for(int j = 1; j < MAX; j++){
                if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

int main()
{
    int a, b, c, d, cases = 1;

    while(cin>>a>>b){

        if(a == 0 && b == 0)
            break;
        for(int i = 1; i < MAX; i++){
            for(int j = 1; j < MAX; j++){
                if(i == j)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = INF;
            }
        }

        matrix[a][b] = 1;
        while(cin>>c>>d){
            if(c == 0 && d == 0)
                break;
            matrix[c][d] = 1;
        }

        floydWarshall();

        int sum = 0, count = 0;

        for(int i = 1; i < MAX; i++){
            for(int j = 1; j < MAX; j++){
                if(matrix[i][j] && matrix[i][j] != INF){
                    sum += matrix[i][j];
                    count++;
                }
            }
        }

        double result = (double) sum / count;

        cout<<"Case "<<cases++<<": "<<"average length between pages = ";
        cout<<setiosflags(ios::fixed)<<setprecision(3);
        cout<<result<<" clicks"<<endl;
    }

    return 0;
}
