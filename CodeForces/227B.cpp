#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 100005
using namespace std;

int main()
{
    int vmark[MAX], pmark[MAX], n, queryNo, query;
    long long Vasya = 0, Petya = 0;

    cin>>n;

    int x;
    for(int i = 1, j = n; i <= n; i++, j --){
        cin>>x;
        vmark[x] = i;        //mark the position of the number
        pmark[x] = j;
    }

    cin>>queryNo;

    for(int i = 0; i < queryNo; i++){
        cin>>query;
        Vasya += vmark[query];
        Petya += pmark[query];
    }

    cout<<Vasya<<" "<<Petya<<endl;

    return 0;
}
