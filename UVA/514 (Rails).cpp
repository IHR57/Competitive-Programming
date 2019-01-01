#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, current, coach, target[1005];

    while(1){
        cin>>n;
        if(n==0)
            break;
        while(1){
            cin>>target[0];

            if(target[0]==0){
                cout<<endl;     //if first element is zero then print a new line and break;
                break;
            }

            for(int i=1; i<n; i++){
                cin>>target[i];
            }

            stack<int>station;      //creating a stack
            coach=1, current=0;

            while(coach<=n){
                station.push(coach);        //push coach
                while(!station.empty() && station.top()==target[current]){
                    station.pop();
                    current++;
                    if(current>=n)
                        break;
                }
                coach++;
            }
            if(station.empty())     //if station is empty
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }

    return 0;
}
