//Problem ID: CodeForces - 1111B (Average Superhero Gang Power)
//Programmer: IQBAL HOSSAIN     Description: MATH
//Date: 09/02/19
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

typedef long long ll;

int arr[MAX];
double cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k, m;

    cin>>n>>k>>m;

    cs[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    sort(arr + 1, arr + n + 1);

    for(int i = 1; i <= n; i++){
        cs[i] = cs[i-1] + (double) arr[i];
    }

    double Max = 0.0;

    for(int i = 0; i <= min(n - 1, m); i++){
        double  rem = (double) n - i;
        double temp = (cs[n] - cs[i]) + min((double) (m - i), (rem * k));
        double avg = temp / rem;
        if(avg > Max)
            Max = avg;
    }

    cout<<setiosflags(ios::fixed)<<setprecision(10);
    cout<<Max<<endl;

    return 0;
}
