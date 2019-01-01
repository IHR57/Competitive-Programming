#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[30];
    int i, j, n, input[50], output[50], k, final_value[50];

    while(cin.getline(str, sizeof(str)))
    {
        //int len=strlen(str);
        for(i=0, j=0; str[i]; i++){
            switch(str[i])
            {
            case 'B':
            case 'F':
            case 'P':
            case 'V':
                n=1; input[j++]=n; break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
                n=2; input[j++]=n; break;
            case 'D':
            case 'T':
                n=3; input[j++]=n; break;
            case 'L':
                n=4; input[j++]=n; break;
            case 'M':
            case 'N':
                n=5; input[j++]=n; break;
            case 'R':
                n=6; input[j++]=n;; break;
            default:
                n=0; input[j++]=n; break;
            }
        }
        input[j]=0;
        for(i=0, k=0; i<j; i++){
            if(input[i]!=input[i+1])
                output[k++]=input[i];
        }
        //for(i=0; i<k; i++)
          // cout<<output[i];
        //cout<<endl;
        int m=0;
        for(i=0; i<k; i++){
            if(output[i]!=0)
                final_value[m++]=output[i];
        }
        for(i=0; i<m; i++){
            cout<<final_value[i];
        }
        cout<<endl;
    }

    return 0;
}
