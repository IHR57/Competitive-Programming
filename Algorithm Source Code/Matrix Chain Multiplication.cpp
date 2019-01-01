#include <bits//stdc++.h>
using namespace std;

int m[50][50];
int s[50][50];

void MatrixChainOrder(int p[], int n)
{
    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j-1; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void OptimalParens(int i, int j)
{
    if(i == j)
        cout<<"A"<<i;
    else{
        cout<<"(";
        OptimalParens(i, s[i][j]);
        OptimalParens(s[i][j]+1, j);
        cout<<")";
    }

}

int main()
{
    int p[100], n;

    cout<<"Enter number of matrix to be multiply: ";
    cin>>n;

    for(int i = 0; i <= n; i++){
        cin>>p[i];
    }

    cout<<endl;

    MatrixChainOrder(p, n);
    OptimalParens(1, n);

    cout<<endl;

    return 0;
}
