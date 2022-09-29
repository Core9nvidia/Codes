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
struct segtree{
    ll size;
    vi sums;
    void init(ll n){
        size=1;
        while(size<n)size*=2;
        sums.assign(2*size,0LL);
    }
    void build(vector<int> &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        int m=(rx+lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            sums[x]=v;return;
        }
        int m=(rx+lx)/2;
        if(i<m)set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i,int v){set(i,v,0,0,size);}
    int mn(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx)return Mod;
        if(lx>=l && rx<=r)return sums[x];
        int m=(rx+lx)/2;
        ll s1=mn(l,r,2*x+1,lx,m);
        ll s2=mn(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }
    int mn(int l,int r){
        return mn(l,r,0,0,size);
    }

    /*ll sum(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx)return 0;
        if(lx>=l && rx<=r)return sums[x];
        int m=(rx+lx)/2;
        ll s1=sum(l,r,2*x+1,lx,m);
        ll s2=sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    ll sum(int l,int r){
        return sum(l,r,0,0,size);
    }*/
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
       int n,m;cin>>n>>m;
       segtree st;
       st.init(n);
       vector<int> v(n);
       f(i,0,n){
           cin>>v[i];
       }
       st.build(v);
       while(m--){
           int op;cin>>op;
           if(op==1){
               int i,x;cin>>i>>x;
               st.set(i,x);
           }
           else{
               int l,r;cin>>l>>r;
               cs(st.mn(l,r));
           }
       }
       
}