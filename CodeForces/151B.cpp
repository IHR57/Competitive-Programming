#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    string frinds[MAX], str;
    int counter[MAX][10] = {0};

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>k>>frinds[i];
        for(int j = 0; j < k; j++){
            cin>>str;
            if(str[0] == str[1] && str[0] == str[3] && str[0] == str[4] && str[0] == str[6] && str[0] == str[7]){
                counter[i][0]++;
            }
            else if(str[0] > str[1] && str[1] > str[3] && str[3] > str[4] && str[4] > str[6] && str[6] > str[7]){
                counter[i][1]++;
            }
            else{
                counter[i][2]++;
            }
        }
    }

    int Max0 = 0, Max1 = 0, Max2 = 0;
    for(int i = 0; i < n; i++){
        Max0 = max(Max0, counter[i][0]);
        Max1 = max(Max1, counter[i][1]);
        Max2 = max(Max2, counter[i][2]);
    }
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i = 0; i < n; i++){
        if(counter[i][0] == Max0)   c1++;
        if(counter[i][1] == Max1)   c2++;
        if(counter[i][2] == Max2)   c3++;
    }

    cout<<"If you want to call a taxi, you should call: ";
    int k1 = 0;
    for(int i = 0; i < n; i++){
        if(counter[i][0] == Max0 && k1 < c1 - 1){
            cout<<frinds[i]<<", ";
            k1++;
        }
        else if(counter[i][0] == Max0 && k1 == c1 - 1)
            cout<<frinds[i]<<".";
    }

    cout<<endl;
    cout<<"If you want to order a pizza, you should call: ";

    k1 = 0;
    for(int i = 0; i < n; i++){
        if(counter[i][1] == Max1 && k1 < c2 - 1){
            cout<<frinds[i]<<", ";
            k1++;
        }
        else if(counter[i][1] == Max1 && k1 == c2 - 1)
            cout<<frinds[i]<<".";
    }

    cout<<endl;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    k1 = 0;
    for(int i = 0; i < n; i++){
        if(counter[i][2] == Max2 && k1 < c3 - 1){
            cout<<frinds[i]<<", ";
            k1++;
        }
        else if(counter[i][2] == Max2 && k1 == c3 - 1){
            cout<<frinds[i]<<".";
        }
    }

    cout<<endl;

    return 0;
}
