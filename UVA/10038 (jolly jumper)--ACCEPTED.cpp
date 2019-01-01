#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

void sort(int array[], int n)   //selection sort
{
    int number=n-1;

    for(int i=0; i<number-1; i++){
        for(int j=i+1; j<number; j++){
            if(array[i]>array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }

}
int main()
{
    int n, i, j, k, diff, value[3005], first, second, count;

    while(cin>>n){
        cin>>first;
        k=0;
        count=0;
        for(i=2; i<=n; i++){
            cin>>second;
            diff=abs(first-second);
            value[k]=diff;  //assign the difference into array
            first=second;
            k++;
        }
        sort(value, n);
        //for(i=0; i<n-1; i++){
          //  cout<<value[i]<<" ";
        //}
        for(i=0, k=1; i<n-1; i++, k++){
            if(value[i]==k)
                count++;
        }
        if(count==n-1)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }

    return 0;
}
