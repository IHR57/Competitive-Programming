#include <iostream>
using namespace std;

int main()
{
    int T, N, *speed, i, max, j=1;

    cin>>T;

    while(T--){
        cin>>N;
        speed=new int[N];
        for(i=0; i<N; i++){
            cin>>speed[i];
        }
        max=speed[0];
        for(i=0; i<N; i++){
            if(speed[i]>max)
                max=speed[i];
        }
        cout<<"Case "<<j<<": "<<max<<endl;
        j++;
    }
    delete []speed;

    return 0;
}
