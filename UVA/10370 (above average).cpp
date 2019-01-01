#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int test, n, i, *number, average, count;
    long int sum;
    double percentage;

    cin>>test;

    while(test--){
        sum=0; count=0;
        cin>>n;
        number=new int[n];
        for(i=0; i<n; i++){
            cin>>number[i];
        }
        for(i=0; i<n; i++){
            sum=sum+number[i];
        }
        average=sum/n;

        for(i=0; i<n; i++){
            if(number[i]>average)
                count++;
        }
        percentage=(double)(count*100.0)/n;

        cout<<setiosflags(ios::fixed)<<setprecision(3)<<percentage<<"%"<<endl;
    }
    delete []number;
}
