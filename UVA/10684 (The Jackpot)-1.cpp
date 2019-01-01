#include <bits//stdc++.h>
using namespace std;

int main()
{
    int data[10005], n;

    while(cin>>n && n!=0){
        for(int i=0; i<n; i++){
            cin>>data[i];
        }

        int sum = 0, ans = 0;

        for(int i=0; i<n; i++){
            sum+=data[i];
            ans = max(sum, ans);
            if(sum<0)
                sum = 0;
        }

        if(ans>0)
            cout<<"The maximum winning streak is "<<ans<<"."<<endl;
        else
            cout<<"Losing streak."<<endl;
    }

    return 0;
}
