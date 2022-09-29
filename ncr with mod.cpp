#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl '\n' 
#define ce(ele) cout<<ele<<' '
#define CASE(t) int t; cin>>t; while(t--)
#define sor(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define vi vector<ll>
#define cs(ele) cout<<ele<<'\n'
const ll Mod=1e9 +7;const ll M1=998244353;
ll mod(ll n){return ((n%Mod)+Mod)%Mod;}
ll power(ll x,ll y){ll res=1;x=x;while(y>0){if(y&1)res=mod(res*x);x=mod(x*x);y=mod(y>>1);}return mod(res);}
 unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long ncr(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
       CASE(t){
           int n,m,k;cin>>n>>m>>k;vector<int> v(n);
           f(i,0,n)cin>>v[i];
           sor(v);
           if(n<m){
               cs(0);continue;
           }//f(i,0,n)ce(v[i]);
           vector<pair<int,int>> vp;
           int cnt=1;
           f(i,1,n){
               if(v[i-1]==v[i])cnt++;
               else{
                   vp.pb({v[i-1],cnt});
                   cnt=1;
               }
           }
           vp.pb({v[n-1],cnt});
           ll res=0;n=vp.size();
           f(i,0,n){
               ll cnt=0;
               f(j,i,n){
                   if(vp[j].F-vp[i].F<=k)cnt+=vp[j].S;
               }res=mod(res+ncr(cnt,m,Mod)-ncr(cnt-vp[i].S,m,Mod));
           }
           cs(res);
       }
       
}