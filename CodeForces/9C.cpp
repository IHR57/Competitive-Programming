#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int Power(int a, int b)
{
    int result = 1;
    for(int i = 1; i <= b; i++){
        result *= a;
    }
    return result;
}

int convert(int n)
{
    int sum = 0, p = 0;
    while(n != 0){
        int r = n % 2;
        sum += (r * Power(10, p));
        p++;
        n /= 2;
    }

    return sum;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    vector<int> v;
    for(int i = 1; i <= (1<<9); i++){
        int temp = convert(i);
        v.push_back(temp);
    }

    int result = upper_bound(v.begin(), v.end(), n) - v.begin();

    cout<<result<<endl;

    return 0;
}
