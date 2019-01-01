#include <iostream>
#include <math.h>
using namespace std;

typedef long int lint;

void sieve(lint a, lint b)
{
    lint i, j, d;
    lint primes[100005];
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
            primes[k++]=(a+i);
            //cout<<(a+i)<<" ";
    }
    lint len=k, min_index, max_index, D_min, D_max, Min, Max;

    if(len==1){
        cout<<"There are no adjacent primes."<<endl;
    }
    else{
        Min=primes[1]-primes[0];  min_index=0;
        Max=primes[1]-primes[0];  max_index=0;
        for(i=1; i<k-1; i++){
            D_min=primes[i+1]-primes[i];
            if(D_min<Min){
                Min=D_min;
                min_index=i;
            }
            D_max=primes[i+1]-primes[i];
            if(D_max>Max){
                Max=D_max;
                max_index=i;
            }
        }
        cout<<primes[min_index]<<","<<primes[min_index+1]<<" are closest, ";
        cout<<primes[max_index]<<","<<primes[max_index+1]<<" are most distant."<<endl;
    }
}

int main()
{
    lint x, y;

    while(cin>>x>>y){
        sieve(x, y);
    }

    return 0;
}

