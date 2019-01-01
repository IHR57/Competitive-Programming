#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, i, n, j, sum;

    cin>>test;
    for(j=1; j<=test; j++){
        sum=0;
        char student[150][30];
        int length[150], width[150], height[150];
        cin>>n;
        for(i=0; i<n; i++){
            scanf("%s %d %d %d", &student[i], &length[i], &width[i], &height[i]);
            sum+=(length[i]*width[i]*height[i]);
        }
        double average=(double)sum/n;
        //cout<<average<<endl;
        int low, high, flag=0;
        for(i=0; i<n; i++){
            if((double)(length[i]*width[i]*height[i])>average){
                high=i;
                flag=1;
            }
        }

        for(i=0; i<n; i++){
            if((double)(length[i]*width[i]*height[i])<average){
                low=i;
                flag=1;
            }
        }
        if(flag==1){
            printf("Case %d: %s took chocolate from %s\n", j, student[high], student[low]);
        }
        else
            printf("Case %d: no thief\n", j);

    }

    return 0;
}
