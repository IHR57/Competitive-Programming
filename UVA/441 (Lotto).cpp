#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int k, Set[50], flag=0;

    while(cin>>k && k!=0){
        for(int i=0; i<k; i++){
            cin>>Set[i];
        }

        if(flag)    cout<<endl;
        flag=1;

        for(int a=0; a<k-5; a++){
            for(int b=a+1; b<k-4; b++){
                for(int c=b+1; c<k-3; c++){
                    for(int d=c+1; d<k-2; d++){
                        for(int e=d+1; e<k-1; e++){
                            for(int f=e+1; f<k; f++){
                                printf("%d %d %d %d %d %d\n", Set[a], Set[b], Set[c], Set[d], Set[e], Set[f]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
