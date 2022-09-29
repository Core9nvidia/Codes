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

// Rank[i] stores the size of ith set.
// height may increase with number of elements in tree
// so smaller tree is joined to larger one

// ******* here path compression is also used in find  function

int par[100001],Rank[100001];


int find(int n){
    vector<int> v;
    while(par[n]>0){
        v.pb(n);
        n=par[n];
    }
    f(i,0,v.size()){
        par[v[i]]=n;
    }
    
    return n;
}

void un(int a,int b){
    if(Rank[a]>Rank[b]){
        par[b]=a;
        Rank[a]+=Rank[b];
    }else{
        par[a]=b;
        Rank[b]+=Rank[a];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    int n,m;cin>>n>>m;
    
    f(i,0,n+1)par[i]=-1,Rank[i]=1;
    f(i,0,m){
        int a,b;cin>>a>>b;
        a=find(a);b=find(b);
        if(a!=b)un(a,b);
    }

}