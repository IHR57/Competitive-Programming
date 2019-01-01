#include <iostream>
using namespace std;

int main()
{
    int data[1005], test, sum, n, count;

    cin>>test;

    while(test--){
        sum=0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>data[i];
        }

        for(int i=1; i<n; i++){
                count=0;
            for(int j=i-1; j>=0; j--){
                if(data[j]<=data[i]){
                    count++;
                }
            }
            sum+=count;
        }

        cout<<sum<<endl;
    }

    return 0;
}
