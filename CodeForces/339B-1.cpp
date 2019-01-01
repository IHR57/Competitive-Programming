#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 200010
using namespace std;

int main()
{
    int n, m, destination[MAX];

    destination[0] = 1;

    cin>>n>>m;

    for(int i = 1; i <= m; i++){
        cin>>destination[i];
    }

    long long int sum = 0;
    for(int i = 0; i < m; i++){
        if(destination[i] <= destination[i+1])
            sum += destination[i+1] - destination[i];
        else{
            sum += ((n - destination[i]) + destination[i + 1]);
        }
    }

    cout<<sum<<endl;

    return 0;
}
