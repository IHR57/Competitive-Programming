#include <bits//stdc++.h>
using namespace std;

int main()
{
    long long int n, value[100005], Min = INT_MAX, sum = 0, odd = 0;

    cin>>n;

    int j = 0, k = 0;
    for(int i = 0; i < n; i++){
        cin>>value[i];
        if(value[i] % 2 != 0){
            odd++;
        }
    }

    if(odd % 2 == 0){
        for(int i = 0; i < n; i++){
            sum += value[i];
        }
    }

    else if(odd % 2 != 0){
        for(int i = 0; i < n; i++){
            if(value[i] % 2 != 0 && value[i] <= Min){
                Min = value[i];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            sum += value[i];
        }

        sum = sum - Min;
    }

    cout<<sum<<endl;
}
