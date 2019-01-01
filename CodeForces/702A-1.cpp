#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long int data[100005], n;
    int count = 1, Max;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>data[i];
    }

    for(int i = 0; i < n-1; i++){
        if(data[i+1] > data[i]){
            count++;
        }
        if(count >= Max)
            Max = count;
        if(data[i+1] <= data[i]){
            count = 1;
        }
    }

    cout<<Max<<endl;

    return 0;
}
