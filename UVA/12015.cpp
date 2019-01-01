#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, i, Max;

    cin>>test;

    for(int j=1; j<=test; j++){
        char str[12][110];
        int Rank[12];

        for(i=0; i<10; i++){
            cin>>str[i]>>Rank[i];
        }
        Max=Rank[0];
        for(i=0; i<10; i++){
            if(Rank[i]>Max)
                Max=Rank[i];
        }

        cout<<"Case #"<<j<<":"<<endl;
        for(i=0; i<10; i++){
            if(Rank[i]>=Max){
                cout<<str[i]<<endl;
            }
        }
    }

    return 0;
}
