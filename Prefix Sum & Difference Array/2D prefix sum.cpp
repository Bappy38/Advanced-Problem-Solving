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

/** Problem: You're given a 2D grid. And given upper left co-ordinate & lower right
co-ordinate of a rectangle. Find out the sum of that sub-rectangle.

Solution: PrefSum[i][j] means sub-rectangle sum of (1,1) to (i,j).

PrefSum[x][y] = PrefSum[x-1][y] + PrefSum[x][y-1] + mat[x][y] - PrefSum[x-1][y-1];

SubRectangleSum[{x1,y1} to {x2,y2}] = PrefixSum[x2][y2]-PrefixSum[x1-1][y2]-PrefixSum[x2][y1-1]+PrefixSum[x1-1][y1-1]
**/

ll mat[1005][1005],prefsum[1005][1005];

void Solve(int t)
{
    ll i,j,k,n,m,x1,y1,x2,y2,ans,q;
    scln2(n , m);
    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=m ; j++){
            scln(mat[i][j]);
            prefsum[i][j] = prefsum[i-1][j] + prefsum[i][j-1] + mat[i][j] - prefsum[i-1][j-1];
        }
    }
    scln(q);
    for(i=1 ; i<=q ; i++){
        scln2(x1 , y1);
        scln2(x2 , y2);
        ans = prefsum[x2][y2] - prefsum[x2][y1-1] - prefsum[x1-1][y2] + prefsum[x1-1][y1-1];
        cout<<ans<<endl;
    }
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



