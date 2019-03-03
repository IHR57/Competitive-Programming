#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int len = (int) str.length();

    int n = 0;
    if(len == 1){
        n = (str[len-1] - 48);
    }
    else if(len >= 2){
        int n1 = (str[len-1] - 48);
        int n2 = (str[len-2] - 48);
        n = n2 * 10 + n1;
    }

    int sum = 1;
    if(n % 4 == 0)
        sum += 2;
    else if(n % 4 == 1 || n % 4 == 3)
        sum += 5;
    else if(n % 4 == 2)
        sum += 8;
    if(n % 2 == 0)
        sum += 1;
    else
        sum += 4;

    cout<<sum % 5<<endl;

    return 0;
}
