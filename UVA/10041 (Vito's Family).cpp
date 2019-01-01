#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

void InsertionSort(int a[], int n)
{
    int key, temp;

    for(int i=1; i<n; i++){
        key=a[i];
        temp=i;
        while(temp>0 && key<a[temp-1]){
            a[temp]=a[temp-1];
            temp=temp-1;
        }
        a[temp]=key;
    }
}

int main()
{
    int relative, street[30010], test, mid, sum;

    cin>>test;

    while(test--){
        cin>>relative;

        sum=0;
        for(int i=0; i<30010; i++){
            street[i]=0;
        }

        for(int i=0; i<relative; i++){
            cin>>street[i];
        }

        InsertionSort(street, relative);    //sorting the street numbers

        //for(int i=0; i<relative; i++){
          //  cout<<street[i]<<" ";
        //}
        //cout<<endl;

        mid=relative/2;

        for(int i=0; i<relative; i++){
            sum+=abs(street[mid]-street[i]);        //subtract all street numbers from mid
        }

        cout<<sum<<endl;

    }

    return 0;
}
