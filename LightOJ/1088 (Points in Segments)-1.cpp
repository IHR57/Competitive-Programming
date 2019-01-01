#include <iostream>
#include <cstdio>
using namespace std;

int data[100100];

bool isFound(int item, int n)       //return true if we found the item in the array
{
    int lo=0, hi=n-1, mid;

    while(lo<=hi){
        mid=(lo+hi)/2;

        if(data[mid]==item)
            return true;
        else if(data[mid]<item){
            lo=mid+1;
        }
        else
            hi=mid-1;
    }

    return false;
}

int lowerBound(int item, int n)     //return lower bound
{
    int lo=0, hi=n-1, mid, index=-1, flag=0;

    while(lo<=hi){
        mid=(lo+hi)/2;

        if(data[mid]==item){
            index=mid;
            flag=1;
            hi=mid-1;
        }
        else if(data[mid]>item){
            hi=mid-1;
        }
        else
            lo=mid+1;
    }

    return lo;
}

int main()
{
    int n, test, q, a, b, x, y, diff, count, cases=1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);         //n = number of element; q = number of query

        for(int i=0; i<n; i++){
            scanf("%d", &data[i]);      //input the data
        }

        printf("Case %d:\n", cases++);
        for(int i=0; i<q; i++){
            count=0;
            scanf("%d %d", &a, &b);
            x=lowerBound(a, n);
            y=lowerBound(b, n);

            if(isFound(b, n)){
                diff=y-x+1;
                printf("%d\n", diff);
            }
            else if(isFound(a, n) && isFound(b, n)){
                diff=y-x+1;
                printf("%d\n", diff);
            }
            else{
                diff=y-x;
                printf("%d\n", diff);
            }
        }
    }

    return 0;
}
