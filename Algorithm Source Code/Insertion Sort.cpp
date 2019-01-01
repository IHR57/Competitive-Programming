#include <iostream>
#include <cstdio>
using namespace std;

void InsertionSort(int a[], int n)
{
    int i, key;

    for(int j = 2; j <= n; j++){
        i = j-1;
        key = a[j];
        while(i > 0 && a[i] > key){
            a[i+1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

int main()
{
    int n, data[100];

    printf("Enter number of element: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &data[i]);
    }

    InsertionSort(data, n); //calling Insertion Sort function

    printf("After Sorting: ");

    //printing the data after sorting
    for(int i = 1; i <= n; i++){
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
