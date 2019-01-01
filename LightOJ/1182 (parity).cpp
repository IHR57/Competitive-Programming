#include <iostream>
using namespace std;

int main()
{
    long int test, k, binary[100], temp[100], count, number, remainder, limit, i, cases=1;

    cin>>test;
    //for(int i=1; i<=test; i++){
    while(test--){
        cin>>number;
        int j=0;
        count=0;
        while(number!=0){
            remainder=number%2;
            number=number/2;
            binary[j++]=remainder;
        }
        limit=j;
        for(i=limit-1, k=0; i>=0; i--, k++){
            temp[k]=binary[i];
        }
        for(i=0; i<limit; i++){
            if(temp[i]==1)
                count++;
        }

        if(count%2==0)
            cout<<"Case "<<cases++<<": "<<"even"<<endl;
        else
            cout<<"Case "<<cases++<<": "<<"odd"<<endl;
    }

    return 0;
}
