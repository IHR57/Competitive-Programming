///UVA Problem: 11764
///Programmer: IQBAL HOSSAIN

#include <iostream>
using namespace std;

int main()
{
    int T, N, a[50], i, j, HighCount, LowCount;

    cin>>T;

    for(i=1; i<=T; i++){
        cin>>N;
        HighCount=0, LowCount=0; //initializing the value
        for(j=1; j<=N; j++){
            cin>>a[j]; //read the value
        }
        for(j=1; j<N; j++){
            if(a[j+1]>a[j]){  //comparing
                HighCount++;  //if yes, increasing the HighCount
            }
            else if(a[j+1]<a[j])
                LowCount++;
        }
        cout<<"Case "<<i<<": "<<HighCount<<" "<<LowCount<<endl;
    }

    return 0;
}
