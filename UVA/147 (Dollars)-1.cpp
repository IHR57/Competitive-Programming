#include <bits//stdc++.h>
using namespace std;

int main()
{
    int coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    long long int way[30005];
    float n;
    int value;

    memset(way, 0, sizeof(way));
    way[0] = 1;

    for(int i = 0; i < 11; i++){
        for(int j = coin[i]; j <= 30001; j++){
            way[j] = way[j] + way[j - coin[i]];
        }
    }

    while(scanf("%f", &n)==1){
        if(n == 0.00)
            break;
        value = (int)((n + 0.0001)* 100);
        printf("%6.2f%17lld\n", n, way[value]);
    }

    return 0;
}
