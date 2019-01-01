// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;

    int temp = n - 1;
    int sum = 0;
    while(temp >= 0){
        sum += temp;
        temp -= 2;
    }

    int result = ((n * (n + 1)) / 2) - 2 * sum;

    cout<<result + sum<<endl;

    return 0;
}
