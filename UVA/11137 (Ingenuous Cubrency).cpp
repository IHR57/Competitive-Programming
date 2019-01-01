#include <bits//stdc++.h>
using namespace std;

int main()
{
    long long int way[10005];
    int coin[25];
    int n;

    int j = 0;
    for(int i = 1; i <= 21; i++){
        coin[j++] = (i*i*i);
    }

    memset(way, 0, sizeof(way));

    way[0] = 1;

    for(int i = 0; i<21; i++){
        int c = coin[i];
        for(j = c; j <= 10000; j++){
            way[j] = way[j] + way[j - c];
        }
    }

    while(cin>>n){
        cout<<way[n]<<endl;
    }

    return 0;
}
