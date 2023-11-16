#include <bits/stdc++.h>
using namespace std;

const int mx = 1000000 ;
int divisor[mx+10] ;
vector<bool>check(mx,true);

void sieve()
{
    for(int i=1; i<=mx; i++)
    {
        for(int j=i; j<=mx; j+=i)divisor[j]++;
    }

    check[0]=check[1]=false;
    for(int i=2; i*i<=mx; i++)
    {
        if(check[i]){
            for(int j=i*i; j<=mx; j+=i){
                check[j]=false;
            }
        }
    }
}

bool isProductOfPrimes(int num) {
    if (num <= 3) return false;
    int sqrtN = sqrt(num);
    for (int i = 2; i <= sqrtN; ++i) {
        if (num % i == 0 && check[i] && check[num/i] && i != num / i) {
            return true;
        }
    }
    return false;
}

int main()
{

    sieve();
    int cnt=0;

    for(int i=1; i<=mx; i++)
    {
        int x = divisor[i];
        if(isProductOfPrimes(x) and (++cnt%9==0)){
            cout<<i<<endl;
        }
    }

    return 0;
}
