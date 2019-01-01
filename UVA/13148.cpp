#include <iostream>
using namespace std;

int main()
{
    int n;
    int special[]={1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809,
                    7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};

    while(cin>>n && n!=0){
        int flag = 0;
        for(int i=0; i<21; i++){
            if(special[i]==n){
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<"Special"<<endl;
        else
            cout<<"Ordinary"<<endl;
    }

    return 0;
}
