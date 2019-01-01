#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, temp1 = 4, temp2 = 9;

    cin>>n;

    int first, last;
    if(n % 2 == 0){
        first = temp1;
        last = n - first;
    }
    else{
        first = temp2;
        last = n - temp2;
    }

    cout<<first<<" "<<last<<endl;

    return 0;
}
