#include <iostream>
using namespace std;

int main()
{
    int cases, problem, i, j, k=1, computer1, computer2;

    cin>>cases;

    while(cases--){
        cin>>problem;
        for(i=0; i<=10; i++){
            for(j=0; j<=10; j++){
                if(i+j==problem){
                    computer1=i;
                    computer2=j;
                    continue;
                }
            }
        }
        cout<<computer1<<" "<<computer2<<endl;
    }

    return 0;
}
