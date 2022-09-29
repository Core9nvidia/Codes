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
ll ncr(int n, int r)
{
    if(n<r || n<0 || r<0)return 0;
    else if(n==r)return 1;
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = __gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd 
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
    return p;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
       CASE(t){
           int n;cin>>n;vector<int> v(n);
           f(i,0,n)cin>>v[i];
           sor(v);
           //f(i,0,n)ce(v[i]);
           if(n<3){
               cs(0);continue;
           }
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
               res+=ncr(vp[i].S,3);
               if(i<n-1){
                   if(vp[i+1].F<=vp[i].F+2){
                       res+=vp[i+1].S*ncr(vp[i].S,2);
                       res+=vp[i].S*ncr(vp[i+1].S,2);
                   }
               }
               if(i<n-2){
                   if(vp[i+2].F-vp[i].F<=2){
                       res+=vp[i].S*vp[i+1].S*vp[i+2].S;
                       res+=vp[i].S*ncr(vp[i+2].S,2);
                       res+=vp[i+2].S*ncr(vp[i].S,2);
                   }
               }
           }
           cs(res);
       }
       
}