#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[10000][25];
    int lowest[10001], highest[10001], query, price, test, Size, count, index;

    cin>>test;

    while(test--){
        cin>>Size;
        for(int i=0; i<Size; i++){
            cin>>str[i]>>lowest[i]>>highest[i];
        }

        cin>>query;

        for(int i=0; i<query; i++){
            count=0;
            cin>>price;
            for(int j=0; j<Size; j++){
                if(price>=lowest[j] && price<=highest[j]){
                    count++;
                    if(count==1)
                        index=j;
                }
            }
            if(count==1){
                cout<<str[index]<<endl;
            }
            else if(count>1 || count<1)
                cout<<"UNDETERMINED"<<endl;
        }
        if(test)
            cout<<endl;
    }

    return 0;
}
