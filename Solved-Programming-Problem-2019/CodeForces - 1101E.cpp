//Problem ID: CodeForces - 1101E (Polycarp's new Job)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 09/02/19
#include <bits/stdc++.h>
#define MAX 500005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y, q;
    char ch;

    cin>>q;

    int maxX = -1, maxY = -1;
    for(int i = 0; i < q; i++){
        cin>>ch>>x>>y;
        if(ch == '+'){
            if(x > y)
                swap(x, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
        else if(ch == '?'){
            if(x > y)
                swap(x, y);
            if(x >= maxX && y >= maxY){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
