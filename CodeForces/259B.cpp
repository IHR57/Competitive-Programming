#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c, d, e, f, g, h, i;
    int rs1, rs2, rs3, cs1, cs2, cs3, ds1, ds2, j, k;

    cin>>a>>b>>c;
    cin>>d>>e>>f;
    cin>>g>>h>>i;

    rs1 = b + c, rs2 = d + f, rs3 = g + h;
    cs1 = d + g, cs2 = b + h, cs3 = c + f;
    ds1 = 0, ds2 = c + g;

    for(int i = 1; i <= 100000; i++){
        int sum = rs1 + i;
        j = sum - rs2;
        k = sum - rs3;
        ds1 = i + j + k;

        if(j >= 0 && k >= 0 && rs1 + i == rs2 + j && rs1 + i == rs3 + k && rs1 + i == cs1 + i && rs1 + i == cs2 + j && rs1 + i == cs3 + k && rs1 + i == ds2 + j && rs1 + i == ds1){
            cout<<i<<" "<<b<<" "<<c<<endl;
            cout<<d<<" "<<j<<" "<<f<<endl;
            cout<<g<<" "<<h<<" "<<k<<endl;
            break;
        }
    }

    return 0;
}
