#include <bits/stdc++.h>
#define MAX 100005
#define EPS 1e-10
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double a, b, c, d;

    cin>>a>>b>>c>>d;

    double fst = a / b;
    double snd = c / d;

    double result = fst / (fst + snd - fst * snd);
    cout<<setprecision(8);

    cout<<result + EPS<<endl;

    return 0;
}
