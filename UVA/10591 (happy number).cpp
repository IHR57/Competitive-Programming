#include <iostream>
#include <cstdio>
using namespace std;

long array[10000];
int main()
{
    long int number, sum, value, item, j;
    int flag, i, k, remainder, cases;

    cin>>cases;

    for(i=1; i<=cases; i++){
        cin>>number;
        value=number;
        flag=100;
        k=0;
        while(flag!=1 && flag!=0){
            sum=0;
            while(number!=0){
                remainder=number%10;
                sum+=remainder*remainder;
                number=number/10;
            }
            number=sum;
            if(sum==1)
                flag=1;
            else{
                array[++k]=sum;
                for(j=k-1; j>0; --j){
                    if(sum==array[j]){
                        flag=0;
                        break;
                    }
                }
            }
        }
        if(flag)
            cout<<"Case #"<<i<<": "<<value<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<i<<": "<<value<<" is an Unhappy number."<<endl;
    }

    return 0;
}
