//calculating n'th fibonacci number in O(logn) time using matirix expo
/*
    f(n) = f(n-1) + f(n-2);
    |1 1|   |f(n-1)|   |f(n-1) + f(n-2)|   | f(n) |
    |1 0| * |f(n-2)| = |    f(n-1)     | = |f(n-1)|

    | f(n) |   |1 1|^(n-2)    | 1 |
    |f(n-1)| = |1 0|        * | 1 |

Learned from: http://www.progkriya.org/gyan/matrix-expo.html
*/
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

struct matrix{
    int v[5][5];
    int row, col;
};

//mutiplication of two matrix
matrix multiply(matrix a, matrix b)
{
    assert(a.col == b.row);
    matrix r;

    r.row = a.row;
    r.col = b.col;

    for(int i = 0; i < r.row; i++){
        for(int j = 0; j < r.col; j++){
            int sum = 0;
            for(int k = 0; k < a.col; k++){
                sum += a.v[i][k] * b.v[k][j];
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

matrix Power(matrix mat, int p)
{
    if(p == 1)  return mat;
    if(p % 2 == 1)
        return multiply(mat, Power(mat, p-1));
    matrix ret = Power(mat, p / 2);
    ret = multiply(ret, ret);

    return ret;
}

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        matrix mat;
        mat.row = mat.col = 2;

        //initialize the matrix created from linear recurrence
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;

        if(n < 3) {     //base case
            if(n == 0) printf("%d\n", 0);
            if(n == 1) printf("%d\n", 1);
            if(n == 2) printf("%d\n", 1);
        }
        else{
            mat = Power(mat, n - 1);
            int ans = 1 * mat.v[0][0] + 1 * mat.v[0][1];
            printf("%d\n", ans);
        }
    }

    return 0;
}
