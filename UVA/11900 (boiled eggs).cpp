#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int test, p, q, n, p_count, count, k=1, weight, sum;

    cin>>test;

    while(test--){
        cin>>n>>p>>q;
        p_count=1;
        count=0;
        sum=0;
        for(int i=1; i<=n; i++){
            cin>>weight;
            sum+=weight;
            if(sum<=q && p_count<=p){
                count++;
                p_count++;
            }
        }
        //cout<<"Case "<<k++<<": "<<count<<endl;
        printf("Case %d: %d\n", k++, count);
    }

    return 0;
}
