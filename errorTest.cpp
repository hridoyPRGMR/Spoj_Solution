#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
vector<int>primes;

void sieve(){

    vector<bool>check(N,true);
    check[0]=check[1]=false;
    for(int i=2; i*i<=N; i++){
        if(check[i]){
            for(int j=i*i; j<=N; j+=i){
                check[j]=false;
            }
        }
    }
    primes.push_back(2);
    for(int i=3; i<=N; i+=2){
        if(check[i])primes.push_back(i);
    }
}


int main()
{

    sieve();

    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d",1);
        for(int i=0; primes[i]*primes[i]<=n; i++){
            while(n%primes[i]==0){
                printf(" x ");
                printf("%d",primes[i]);
                n/=primes[i];
            }
        }
        if(n>1){
            printf(" x ");
            printf("%d",n);
        }
        printf("\n");
    }
    return 0;
}
