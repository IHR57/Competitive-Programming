#include <iostream>
using namespace std;

typedef long long int lint;

int main()
{
    lint Size, day, sum, i, value;

    while(cin>>Size>>day){
        sum=0;
        for(i=Size; i<=day; i++){
            sum+=i;
            if(sum>=day){
                value=i;
                break;
            }
        }
        cout<<value<<endl;
    }

    return 0;
}
