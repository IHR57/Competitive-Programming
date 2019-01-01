#include <iostream>
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

int FindClosestSum(int a[], int n, int value)
{
    int sum, result;
    int Min = abs(value - (a[0]+a[1]));

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            sum=abs(value - (a[i]+a[j]));
            if(sum<=Min){
                Min=sum;
                result=a[i]+a[j];
            }
        }
    }

    return result;      //return sum of two element for which closest sum occurs
}

int main()
{
    int n, data[1005], query, value, result, cases=1;

    while(cin>>n && n!=0){
        for(int i=0; i<n; i++){
            cin>>data[i];
        }

        InsertionSort(data, n);     //sorting the element

        cin>>query;

        cout<<"Case "<<cases++<<":"<<endl;
        for(int i=0; i<query; i++){
            cin>>value;
            result = FindClosestSum(data, n, value);
            cout<<"Closest sum to "<<value<<" is "<<result<<"."<<endl;
        }
    }

    return 0;
}
