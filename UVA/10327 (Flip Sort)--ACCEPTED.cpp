#include <iostream>
using namespace std;

int main()
{
    int *p, n, i, j, exchange=0, temp;

    while(cin>>n)
    {
        exchange=0
;        p=new int[n];
        for(i=0; i<n; i++){
            cin>>p[i];
        }

        for(i=0; i<n; i++){
            for(j=0; j<n-1; j++){
                if(p[j]>p[j+1]){
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                    exchange+=1;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<exchange<<endl;
    }
    delete [] p;

    return 0;
}
