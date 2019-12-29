//Problem ID: CodeForces 344C (Rational Resistance)
//Programmer: IQBAL HOSSAIN     Description: Euclidean Algorithm
//Date: 01/01/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, result;

	cin>>a>>b;

    result = 0;
    while(true){
        if(a == 1 || b == 1){
            result += max(a, b);
            break;
        }
        if(a > b){
            result += (a/b);
            a -= (b * (a/b));
        }
        else if(b > a){
            result += (b/a);
            b -= (a * (b/a));
        }
    }

	cout<<result<<endl;

	return 0;
}
