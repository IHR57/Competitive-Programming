#include <bits//stdc++.h>
using namespace std;

struct Item
{
    int value, weight;

    Item(int a, int b)      //constructor
    {
        value = a;
        weight = b;
    }
};

bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int w, Item arr[], int n)
{
    sort(arr, arr+n, compare);

    for(int i = 0; i < n; i++){
        cout<<arr[i].value<<" "<<arr[i].weight<<" : "
        <<((double)arr[i].value / arr[i].weight)<<endl;
    }

    int currentWeight = 0;
    double result = 0.0;

    for(int i = 0; i < n; i++){
        if(currentWeight + arr[i].weight <= w){
            currentWeight += arr[i].weight;
            result += arr[i].value;
        }
        else{
            int remain = w - currentWeight;
            result += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }

    return result;
}

int main()
{
    int W = 50;

    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Maximum value we can obtain = "<<fractionalKnapsack(W, arr, n)<<endl;

    return 0;
}
