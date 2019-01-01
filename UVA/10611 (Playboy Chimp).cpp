#include <iostream>
#include <cstdio>
using namespace std;

int data[50050];

int BinarySearch(int item, int n, int *l, int *h)
{
    int low=0, high=n-1, mid;

    while(low<=high){
        mid=(low+high)/2;
        if(data[mid]==item)
            return mid;
        else if(data[mid]<item)
            low=mid+1;
        else
            high=mid-1;
    }

    //if no item match low becomes higher, high becomes lower
    *l=high;
    *h=low;
    return -1;
}

int main()
{
    int n, l, h, temp, item, result, i=-1, q;

    cin>>n;

    cin>>data[++i];

    for(int j=1; j<n; j++){
        cin>>temp;
        if(temp==data[i]){      //if current and previous element are same
            continue;           //we don't need to take same element
        }
        data[++i]=temp;
    }

    n=i+1;

    cin>>q;

    for(int i=1; i<=q; i++){
        cin>>item;

        if(item<data[0]){
            cout<<"X "<<data[0]<<endl;
            continue;
        }
        else if(item==data[0]){
            cout<<"X "<<data[1]<<endl;
            continue;
        }
        else if(item>data[n-1]){
            cout<<data[n-1]<<" X"<<endl;
            continue;
        }
        else if(item==data[n-1]){
            cout<<data[n-2]<<" X"<<endl;
            continue;
        }

        result=BinarySearch(item, n, &l, &h);   //passing by reference

        if(result==-1){
            cout<<data[l]<<" "<<data[h]<<endl;  //if no item match
        }
        else
            cout<<data[result-1]<<" "<<data[result+1]<<endl;
    }

    return 0;
}
