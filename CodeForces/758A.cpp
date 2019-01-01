#include <bits//stdc++.h>
using namespace std;

int main()
{
    int n, data[120], Max;

    Max = INT_MIN;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
        if(data[i] > Max)
            Max = data[i];
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += (Max - data[i]);
    }

    cout<<sum<<endl;

    return 0;
}
