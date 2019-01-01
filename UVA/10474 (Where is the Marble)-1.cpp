#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int data[10005];
int index;

int BinarySearch(int key, int Size)
{
    int lo=0, hi=Size-1, mid;
    index=-1;
    while(lo<=hi){
        mid=(lo+hi)/2;

        if(data[mid]==key){
            index=mid;
            hi=mid-1;       //we need to take leftmost element
        }
        else if(data[mid]>key){
            hi=mid-1;
        }
        else
            lo=mid+1;
    }

    return index;
}

int main()
{
    int marbles, query, value, pos, cases=1;

    while(cin>>marbles>>query){
        if(marbles==0 && query==0)
            break;
        for(int i=0; i<marbles; i++){
            scanf("%d", &data[i]);
        }

        sort(data, data+marbles);       //sorting the data

        printf("CASE# %d:\n", cases++);
        for(int i=0; i<query; i++){
            scanf("%d", &value);
            BinarySearch(value, marbles);
            if(index>=0)
                printf("%d found at %d\n", value, index+1);
            else if(index<0)
                printf("%d not found\n", value);
        }
    }

    return 0;
}
