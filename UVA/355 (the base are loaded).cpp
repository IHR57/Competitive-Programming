#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long int lint;

bool isZero;

lint Power(int n, int m)
{
    lint result = 1;

    for(int i = 1; i <= m; i++)
        result *= n;

    return result;
}
lint convertBase10(char* str, int base)
{
    int len=strlen(str)-1;
    int i, n;
    lint number=0;
    for(i=0; str[i]; i++){
        switch(str[i])
        {
            case 'a':
			case 'A': n = 10; break;
			case 'b':
			case 'B': n = 11; break;
			case 'c':
			case 'C': n = 12; break;
			case 'd':
			case 'D': n = 13; break;
			case 'e':
			case 'E': n = 14; break;
			case 'f':
			case 'F': n = 15; break;
			default: n = str[i]-48;
        }
        number=number + (n * Power(base, len));;
        --len;
    }
    return number;
}

void revStr(char* str)
{
    char temp[100];
    int len=strlen(str)-1;
    int i;

    for(i=0; str[i]; i++){
        temp[i]=str[len-i];
    }
    temp[i]='\0';
    strcpy(str, temp);
}
char* convertBaseOther(lint number, int base)
{
    char *str, c;
    lint temp;
    int i=0;

    str=new char[100];
    if(number == 0){
        isZero = true;
    }

    while(number!=0){
        temp=number%base;
        number=number/base;
        switch(temp)
        {
        case 10:
            c='A'; break;
        case 11:
            c='B'; break;
        case 12:
            c='C'; break;
        case 13:
            c='D'; break;
        case 14:
            c='E'; break;
        case 15:
            c='F'; break;
        default:
            c=temp+48;
        }
        str[i++]=c;
    }
    str[i++]='\0';
    revStr(str);
    return str;
}

int main()
{
    char input[100], output[100];
    int bFrom, bTo, i, n;
    lint number;

    while(cin>>bFrom>>bTo>>input){
        int check_base=0;
        isZero = false;
        for(i=0; input[i]; i++){
            switch(input[i])
            {
                case 'a':
                case 'A':
                    n=10; break;
                case 'b':
                case 'B':
                    n=11; break;
                case 'c':
                case 'C':
                    n=12; break;
                case 'd':
                case 'D':
                    n=13; break;
                case 'e':
                case 'E':
                    n=14; break;
                case 'f':
                case 'F':
                    n=15; break;
                default:
                    n=input[i]-48;
            }
            if(n>=bFrom)
                check_base=1;
        }
        if(check_base==1){
            cout<<input<<" is an illegal base "<<bFrom<<" number"<<endl;
            continue;
        }

        number=convertBase10(input, bFrom);
        //cout<<number<<endl;
        strcpy(output, convertBaseOther(number, bTo));

        if(isZero)
            cout<<input<< " base "<<bFrom<<" = "<<0<<" base "<<bTo<<endl;
        else{
            cout<<input<< " base "<<bFrom<<" = "<<output<<" base "<<bTo<<endl;
        }
    }

    return 0;
}
