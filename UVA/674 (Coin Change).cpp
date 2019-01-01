#include <bits//stdc++.h>
using namespace std;

int coin[] = {50, 25, 10, 5, 1};
long long int way[7500];

int main()
{
    int n;

    memset(way, 0, sizeof(way));

    way[0] = 1;

    for(int i = 0; i < 5; i++){
        int c = coin[i];
        for(int j = c; j <= 7500; j++){
            way[j] += way[j - c];
        }
    }

    while(scanf("%d", &n)==1){
        printf("%lld\n", way[n]);
    }

    return 0;
}
