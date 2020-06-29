#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define all(a)                  (a.begin()),(a.end())
#define UNIQUE(X)               (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)          (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define mp                      make_pair
#define db                      double
#define EPS                     10E-10
#define ff                      first
#define ss                      second
#define sqr(x)                  (x)*(x)
#define vi                      vector<int>
#define vl                      vector<ll>
#define vii                     vector<vector<int> >
#define vll                     vector<vector<ll> >
#define DBG                     pf("HI\n")
#define MOD                     1000000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                2147483690
#define longlimit               9223372036854775800
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

#define sz 15000000
int SF[sz+5];        /** Here we store smallest factor for each number **/
void FuN()
{
    for( int i = 2 ; i * i <= sz ; i ++ ){
        if( !SF[i] ){
            for( int j = i ; j <= sz ; j += i ){
                if( !SF[j] ) SF[j] = i ;
            }
        }
    }
    for( int i = 2 ; i <= sz ; i ++ ) if( !SF[i] ) SF[i] = i ;
}
vector<int>Factor;
int ara[300005];
int Factorfre[15000005];

void getFactor(int n)
{
    Factor.clear();
    while(n != 1)
    {
        Factor.push_back(SF[n]);
        n/=SF[n];
    }
    UNIQUE(Factor);
    for(auto x:Factor)
        Factorfre[x]++;
}


void Solve(int t)
{
    int i,j,k,n,gc,first,fg=1;
    scin(n);
    for(i=1 ; i<=n ; i++){
        scin(ara[i]);
        if(i == 1){
            gc = ara[i];
            first = ara[i];
        }
        else
            gc = gcd(gc , ara[i]);
        if(ara[i] != first)
            fg = 0;
    }
    if(fg){
        cout<<"-1\n";
        return;
    }
    for(i=1 ; i<=n ; i++){
        ara[i] /= gc;
        getFactor(ara[i]);
    }
    int mx = 0;
    for(i=2 ; i<=15000000 ; i++)
        mx = max(mx , Factorfre[i]);
    cout<<n-mx<<endl;
}

int main()
{
    FuN();
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}


