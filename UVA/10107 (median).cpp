#include <iostream>
#include <cstdlib>
using namespace std;

typedef long int lint;

void insertion_sort(lint value[], lint n)
{
    lint number, hole;
    for(lint i=1; i<n; i++){
        number=value[i];
        hole=i;
        while(hole>0 && value[hole-1]>number){
            value[hole]=value[hole-1];
            hole--;
        }
        value[hole]=number;
    }

}

int main()
{
    lint a[10050], i, mid, j;
    i=0;
    while(cin>>a[i] && !cin.eof()){
        insertion_sort(a, i+1);
        i++;
        if(i%2!=0){
            mid=(i+1)/2;
            cout<<a[mid-1]<<endl;
        }
        else if(i%2==0){
            mid=i/2;
            j=(a[mid]+a[mid-1])/2;
            cout<<j<<endl;
        }
    }

    return 0;
}
