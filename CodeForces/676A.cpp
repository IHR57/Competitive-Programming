#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, data[200];
    int Min_index, Max_index, Min, Max;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>data[i];
        if(data[i] == 1)
            Min_index = i;
        if(data[i] == n)
            Max_index = i;
    }

    int x = max(abs(Min_index - n), abs(Min_index - 1));
    int y = max(abs(Max_index - n), abs(Max_index - 1));

    cout<<max(x, y)<<endl;

    return 0;
}

