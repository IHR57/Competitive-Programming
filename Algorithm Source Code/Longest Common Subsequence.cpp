#include <bits//stdc++.h>
using namespace std;

char X[100], Y[100];
int c[100][100], b[100][100];
int m, n;

int LCSlength()
{
    m = strlen(X);
    n = strlen(Y);

    for(int i = 1; i <= m; i++){
        c[i][0] = 0;
    }

    for(int i = 0; i <= n; i++){
        c[0][i] = 0;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 2;        //from north
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 3;    //from west
            }
        }
    }

    return c[m][n];
}

void printLCS(int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 1){
        printLCS(i-1, j-1);
        cout<<X[i-1];
    }
    else if(b[i][j] == 2){
        printLCS(i-1, j);
    }
    else
        printLCS(i, j-1);

}

int main()
{
    cout<<"Enter first string: ";
    cin>>X;

    cout<<"Enter second string: ";
    cin>>Y;

    cout<<"LCS Length: "<<LCSlength()<<endl;
    printLCS(m, n);
    cout<<endl;

    return 0;
}
