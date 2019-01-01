#include <iostream>
using namespace std;

int data[120];       //global array declaration

void Merge(int low, int mid, int high);

void MergeSort(int low, int high)
{
    int mid;

    if(low == high)
        return;

    mid = (low + high) / 2;

    //Divide into sub Problems
    MergeSort(low, mid);
    MergeSort(mid+1, high);

    //Combine the solutions
    Merge(low, mid, high);
}

void Merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[120];

    while(i <= mid && j <= high){
        if(data[i] <= data[j]){
            temp[k] = data[i];
            i++;
        }
        else{
            temp[k] = data[j];
            j++;
        }
        k++;
    }

    if(i > mid){
        for(int l = j; l <= high; l++){
            temp[k] = data[l];
            k++;
        }
    }
    else{
        for(int l = i; l <= mid; l++){
            temp[k] =data[l];
            k++;
        }
    }

    for(int l = low; l <= high; l++){
        data[l] = temp[l];      //copying the value into data[]
    }
}

int main()
{
    int n;

    //cin>>n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>data[i];
    }

    MergeSort(1, n);        //calling Merge sort function


    cout<<"After Sorting: "<<endl;
    for(int i = 1; i <= n; i++){
        cout<<data[i]<<" ";
    }

    cout<<endl;

    return 0;
}
