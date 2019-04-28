#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int ext_gcd ( int A, int B, int *X, int *Y ){
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

bool linearDiophantine(int A, int B, int C, int *x, int *y)
{
    int g = __gcd(A, B);
    if(C % g != 0)
        return false;
    int a = A / g, b = B / g, c = C / g;
    ext_gcd(a, b, x, y);
    if(g < 0){
        a *= -1 , b *= 1, c *= -1;
    }
    *x *= c, *y *= c;
    return true;
}

int main()
{
    int x,  y;
    if(linearDiophantine(4, 10, 8, &x, &y)){
        cout<<x<<" "<<y<<endl;
    }
}
