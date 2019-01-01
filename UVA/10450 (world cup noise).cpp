#include <iostream>
using namespace std;

int main()
{
    long long int number, array[52], test;
    int i, j=1;

    array[1]=2;
    array[2]=3;

    for(i=3; i<52; i++){
        array[i]=array[i-2]+array[i-1];
    }

    cin>>test;
    while(test--){
        cin>>number;
        cout<<"Scenario #"<<j++<<":"<<endl<<array[number]<<endl<<endl;
    }

    return 0;

}
