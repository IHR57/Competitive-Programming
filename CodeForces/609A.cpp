#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n, data[110], capacity;

    cin>>n>>capacity;

    for(int i = 0; i < n; i ++){
        cin>>data[i];
    }

    sort(data, data+n);

    int sum = 0, count = 0;

    for(int i = n-1; i >= 0; i--){
        sum += data[i];
        count++;
        if(sum >= capacity){
            break;
        }
    }

    cout<<count<<endl;

    return 0;
}
