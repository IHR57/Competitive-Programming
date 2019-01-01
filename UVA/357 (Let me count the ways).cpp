#include <bits//stdc++.h>
using namespace std;

typedef long long int lint;

int coin[] = {50, 25, 10, 5, 1};
lint way[30005];

int main()
{
    lint n;          // n <= 7489

    memset(way, 0, sizeof(way));

    way[0] = 1;     //we can make 0 in one way without taking any coin

    //pre-calculating all number from 1 to 7500
    for(int i = 0; i < 5; i++){
        int c = coin[i];
        for(int j = c; j <= 30000; j++){
            way[j] += way[j - c];       //update number of coin
        }
    }

    while(scanf("%lld", &n)==1){
        if(way[n] == 1){
            printf("There is only 1 way to produce %lld cents change.\n", n);
        }
        else
            printf("There are %lld ways to produce %lld cents change.\n", way[n], n);
    }

    return 0;
}
