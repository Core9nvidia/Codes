#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    char c[]={'A','B','C','D'};
    int n=4;
    int tot=1<<n;
    f(i,0,tot){
        f(j,0,n){
            int t=1<<j;
            if(t & i){
                ce(c[j]);
            }
        }cout<<endl;
    }
    // it has generated all possible subsets
    // time complexity O((2^n)*n)
}