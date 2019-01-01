#include <iostream>
using namespace std;

int main()
{
    int n, first, second, count = 1, Max = -1;

    cin>>n;

    cin>>first;

    if(n == 1){
        Max = 1;
    }
    else
    {
        for(int i = 1; i < n; i++){
            cin>>second;
            if(second >= first){
                count++;
            }
            else{
                count = 1;
            }

            if(count > Max){
                Max = count;
            }

            first = second;
        }
    }

    cout<<Max<<endl;

    return 0;
}
