#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int counter;
int primes[34000];

void sieve(int a, int b)
{
    counter=0;
    int i, j, d;
    d=b-a+1;

    bool *flag=new bool[d];

    for(i=0; i<d; i++){
        flag[i]=true;
    }

    for(i=(a%2!=0); i<d; i+=2)
        flag[i]=false;
    //sieve by prime factor starting from 3 till sqrt(b);

    for(i=3; i<=sqrt(b); i+=2){
        if(i>a && !flag[i-a])
            continue;
        j=a/i*i;
        if(j<a)
            j+=i;
        if(j==i)
            j+=i;

        j-=a;
        for(; j<d; j+=i)
            flag[j]=false;
    }

    if(a<=1)
        flag[1-a]=false;
    if(a<=2)
        flag[2-a]=true;

    int k=0;
    for(i=0; i<d; i++){
        if(flag[i])
            primes[counter++]=(a+i);
            //cout<<(a+i)<<" ";
    }
}

int main()
{
    int x, y, diff[32005];

    while(cin>>x>>y){
        if(x==0 && y==0)
            break;

        if(x>y){
            int temp=y;
            y=x;
            x=temp;
        }

        sieve(x, y);
        int i, j, value, index;

        for(i=1, j=0; i<counter; i++, j++){
            diff[j]=(primes[i]-primes[i-1]);
        }
        int len=j;

        i=0;
        int count=2;        //set count = 2;
        for(; i<len-1; ){
            if(diff[i]==diff[i+1]){
                    index=i;            //we need this index later for printing uni-distance prime
                while(diff[i]==diff[i+1]){
                    count++;
                    i++;
                }
            }
            else
                i++;
            if(count>=3){       //if count greater than 3 than print
                for(j=index; j<count+index; j++){
                    cout<<primes[j]<<" ";
                }
                cout<<endl;
            }
            count=2;        //set count equal 2
        }
    }

    return 0;
}

