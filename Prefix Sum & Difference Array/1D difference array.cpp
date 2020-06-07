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

/** Problem: You're given an array with n elements. And you'll given q query. In each
query you'll given 1<=l<=r<=n and x. You've to increase all element from index l to r
by x.
After all query, you've to print the array.

Solution:
->  We've to build difference array firstly where d[i] = a[i]-a[i-1].
->  When we have to increase l to r index by x then we'll do:
    d[l] += x;  d[r+1] -= x;
->  After all query we'll restore array from difference array sequentially.
    For i=1 to n
    a[i] = d[i]+a[i-1].
**/

ll ara[100005],d[100005];

void Solve(int t)
{
    ll i,j,k,n,q,l,r,x,ans;
    scln(n);
    for(i=1 ; i<=n ; i++){
        scln(ara[i]);
        d[i] = ara[i] - ara[i-1];
    }
    scln(q);
    for(i=1 ; i<=q ; i++){
        cin>>l>>r>>x;
        d[l] += x;
        d[r+1] -= x;
    }
    for(i=1 ; i<=n ; i++){
        ara[i] = d[i]+ara[i-1];
        cout<<ara[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}


