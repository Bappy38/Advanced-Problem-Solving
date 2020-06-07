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

/** Problem: You're given a matrix with n row & m column. You have to apply some update
operation in that matrix. In each operation you'll given upper left & lower right
co-ordinate of that matrix & an integer val. You have to increase all element on that
sub-rectangle by val.
After applying all the update operation, print the matrix.
Solution:
->  We have to build 2D difference array of the matrix where d[i][j] = a[i][j] + a[i-1][j-1] - a[i][j-1] - a[i-1][j]
->  In each update operation for sub-rectangle (x1,y1) to (x2,y2) by val we have to change difference array like below:
    d[x1][y1] += val;
    d[x1][y2+1] -= val;
    d[x2+1][y1] -= val;
    d[x2+1][y2+1] += val;
->  After all update operation, we've to restore the original array.
    a[i][j] = d[i][j] + a[i][j-1] + a[i-1][j] - a[i-1][j-1]
**/

int a[1005][1005],d[1005][1005];

void Solve(int t)
{
    ll i,j,k,n,m,x1,y1,x2,y2,val,q;
    scln2(n , m);
    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=m ; j++){
            scln(a[i][j]);
            d[i][j] = a[i][j] + a[i-1][j-1] - a[i][j-1] - a[i-1][j];
        }
    }
    scln(q);
    for(i=1 ; i<=q ; i++){
        cin>>x1>>y1>>x2>>y2>>val;
        d[x1][y1] += val;
        d[x1][y2+1] -= val;
        d[x2+1][y1] -= val;
        d[x2+1][y2+1] += val;
    }
    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=m ; j++){
            a[i][j] = d[i][j] + a[i][j-1] + a[i-1][j] - a[i-1][j-1];
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
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
/**
4 4
1 3 5 2
4 6 7 1
9 2 5 2
4 6 8 10
3
1 1 2 2 2
2 2 3 3 1
3 3 4 3 3
**/

