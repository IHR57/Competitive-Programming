#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int n, data[100005];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>data[i];
    }

    sort(data, data+n);

    int count = 0;

    for(int i = 1; i < n-1; i++){
        if(data[i] > data[0] && data[i] < data[n-1]){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}
