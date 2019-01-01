#include <iostream>
using namespace std;

int main()
{
    int *days, n, parties, test, averageDay, count, i, j;

    cin>>test;

    while(test--){
        count=0;
        cin>>n>>parties;
        days=new int[n];

        for(i=0; i<parties; i++){
            cin>>averageDay;
            for(j=averageDay-1; j<n; j+=averageDay){
                days[j]=1;
            }
        }

        for(i=5; i<n; i+=7){
            days[i]=0;
            days[i+1]=0;
        }
        for(i=0; i<n; i++){
            if(days[i]==1)
                count++;
        }
        cout<<count<<endl;
    }

    delete []days;

    return 0;
}
