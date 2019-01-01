#include <iostream>
#define MAX 500005
using namespace std;

int main()
{
    int p, budget, hotel, week, room, i, j;

    while(cin>>p>>budget>>hotel>>week){
        int price, cost, Final=MAX;
        for(i=1; i<=hotel; i++){
            cin>>price;
            for(j=1; j<=week; j++){
                cin>>room;
                if(room>=p){
                    cost=price*p;
                    if(cost<=budget && cost<Final){
                        Final=cost;
                    }
                }
            }
        }
        if(Final==MAX)
            cout<<"stay home"<<endl;
        else
            cout<<Final<<endl;
    }

    return 0;
}
