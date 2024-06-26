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

/** Problem: Given a 3D grid. And given two corner point of a cube. Find out the sum of that cube.
Solution: PrefixSum[i][j][k] means sum of cube (1,1,1) to (i,j,k).

PrefixSum[x][y][z] = mat[x][y][z] + PrefixSum[x-1][y][z] + PrefixSum[x][y-1][z] + PrefixSum[x][y][z-1] - PrefixSum[x-1][y-1][z] - PrefixSum[x][y-1][z-1] - PrefixSum[x-1][y][z-1] + PrefixSum[x-1][y-1][z-1]

CubeSum[(x1,y1,z1) to (x2,y2,z2)] = PrefixSum[x2][y2][z2] - PrefixSum[x1-1][y2][z2] - PrefixSum[x2][y1-1][z2] - PrefixSum[x2][y2][z1-1] + PrefixSum[x1-1][y1-1][z2] + PrefixSum[x2][y1-1][z1-1] + PrefixSum[x1-1][y2][z1-1] - PrefixSum[x1-1][y1-1][z1-1]
**/

ll mat[105][105][105],PrefixSum[105][105][105];

void Solve(int t)
{
    ll i,j,k,length,width,height,x1,y1,z1,x2,y2,z2,ans,q;
    cin>>length>>width>>height;
    for(i=1 ; i<=length ; i++){
        for(j=1 ; j<=width ; j++){
            for(k=1 ; k<=height ; k++){
                cin>>mat[i][j][k];
                PrefixSum[i][j][k] = mat[i][j][k] + PrefixSum[i-1][j][k] + PrefixSum[i][j-1][k] + PrefixSum[i][j][k-1] - PrefixSum[i-1][j-1][k] - PrefixSum[i][j-1][k-1] - PrefixSum[i-1][j][k-1] + PrefixSum[i-1][j-1][k-1];
            }
        }
    }
    scln(q);
    for(i=1 ; i<=q ; i++){
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        ans = PrefixSum[x2][y2][z2] - PrefixSum[x1-1][y2][z2] - PrefixSum[x2][y1-1][z2] - PrefixSum[x2][y2][z1-1] + PrefixSum[x1-1][y1-1][z2] + PrefixSum[x2][y1-1][z1-1] + PrefixSum[x1-1][y2][z1-1] - PrefixSum[x1-1][y1-1][z1-1];
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

