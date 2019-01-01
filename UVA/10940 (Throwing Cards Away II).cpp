#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int value[500005];
    int flag=0, next=2, n, i, j;
    int square[]={2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144};

    value[1]=1;
    value[2]=2;

    for(i=3; i<=500000; i++){
        for(j=0; j<18; j++){
            if(square[j]==(i-1)){
                next=2;
                break;
            }
        }
        value[i]=next;
        next+=2;
    }
    while(cin>>n && n!=0){
        printf("%d\n", value[n]);
    }

    return 0;
}
