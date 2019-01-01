#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    long long int n, x, d, sum, count = 0;
    char ch;

    cin>>n>>x;

    sum = x;

    for(int i = 1; i <= n; i++){
        cin>>ch>>d;
        if(ch == '+'){
            sum = sum + d;
        }
        else if(ch == '-'){
            if((sum - d) < 0){
                sum = sum;
                count++;
            }
            else
                sum = sum - d;
        }
    }

    cout<<sum<<" "<<count<<endl;

    return 0;
}
