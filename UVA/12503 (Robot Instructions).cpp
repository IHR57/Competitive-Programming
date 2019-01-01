#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test, n, result, value;
    string str[120], s;

    cin>>test;

    while(test--){
        int i=0;
        result=0;
        cin>>n;

        for(int i=1; i<=n; i++){
            cin>>s;

            if(s=="LEFT"){
                str[i]=s;       //storing the instruction
                result--;       //decrementing  the result
            }
            else if(s=="RIGHT"){
                str[i]=s;
                result++;
            }
            else{
                cin>>s;         //input another string does not matter what it is
                cin>>value;     //input a instruction

                if(str[value]=="LEFT"){     //check the instruction and do calculation
                    str[i]=str[value];
                    result--;
                }

                else {
                    str[i]=str[value];
                    result++;
                }
            }
        }
        cout<<result<<endl;
    }

    return 0;
}
