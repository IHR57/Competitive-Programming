#include <stdio.h>
#include <string.h>
#include <math.h>
int flag;
int isPrime(int n)
{
    int i;
    int j=sqrt(n);
    for(i=2; i<=j; i++){
        if(n%i==0)
            flag=1;
    }
}

int main()
{
    int i, n, sum, check_prime;
    char word[100];

    while(scanf("%s", word)==1){
        sum=0;
        flag=0;
        for(i=0; word[i]; i++){
            switch(word[i])
            {
            case 'a': n=1; break;
            case 'b': n=2; break;
            case 'c': n=3; break;
            case 'd': n=4; break;
            case 'e': n=5; break;
            case 'f': n=6; break;
            case 'g': n=7; break;
            case 'h': n=8; break;
            case 'i': n=9; break;
            case 'j': n=10; break;
            case 'k': n=11; break;
            case 'l': n=12; break;
            case 'm': n=13; break;
            case 'n': n=14; break;
            case 'o': n=15; break;
            case 'p': n=16; break;
            case 'q': n=17; break;
            case 'r': n=18; break;
            case 's': n=19; break;
            case 't': n=20; break;
            case 'u': n=21; break;
            case 'v': n=22; break;
            case 'w': n=23; break;
            case 'x': n=24; break;
            case 'y': n=25; break;
            case 'z': n=26; break;
            case 'A': n=27; break;
            case 'B': n=28; break;
            case 'C': n=29; break;
            case 'D': n=30; break;
            case 'E': n=31; break;
            case 'F': n=32; break;
            case 'G': n=33; break;
            case 'H': n=34; break;
            case 'I': n=35; break;
            case 'J': n=36; break;
            case 'K': n=37; break;
            case 'L': n=38; break;
            case 'M': n=39; break;
            case 'N': n=40; break;
            case 'O': n=41; break;
            case 'P': n=42; break;
            case 'Q': n=43; break;
            case 'R': n=44; break;
            case 'S': n=45; break;
            case 'T': n=46; break;
            case 'U': n=47; break;
            case 'V': n=48; break;
            case 'W': n=49; break;
            case 'X': n=50; break;
            case 'Y': n=51; break;
            case 'Z': n=52; break;
            }
            sum+=n;
        }
        check_prime=isPrime(sum);
        if(flag==0)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }

    return 0;
}
