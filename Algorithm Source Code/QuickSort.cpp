#include <iostream>
#include <cstdio>
using namespace std;

int Partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;

    for(int j = p; j <= r - 1; j++)
    {
        if(a[j] <= x){
            i = i+1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);

    return i+1;
}

void QuickSort(int a[], int p, int r)
{
    int q;

    if(p < r)
    {
        q = Partition(a, p, r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}

int main()
{
    int data[100], n;

    printf("Enter number of element: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &data[i]);
    }

    QuickSort(data, 1, n);      //calling quick sort

    for(int i = 1; i <= n; i++){
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;

}
