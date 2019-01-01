#include <iostream>
using namespace std;
typedef long long int lint;

int main()
{
    lint n, result, value;

    while(cin>>n && n!=0){
        int count=0;
        if(n<0)
            n*=-1;
        result=-1;
        for(lint i=2; i*i<=n && n!=1; i++){
            while(n%i==0){
                n/=i;
                result=i;
            }
            if(result==i){
                count++;
            }
        }
        if(n>1 && result!=-1)
            result=n;
        else if(count==1)
            result=-1;
        cout<<result<<endl;
    }

    return 0;
}
