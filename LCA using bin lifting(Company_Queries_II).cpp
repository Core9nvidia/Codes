#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define endl '\n' 
#define ce(ele) cout<<ele<<' '
#define CASE(t) int t; cin>>t; while(t--)
#define sor(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define vi vector<ll>
#define pb push_back
#define cs(ele) cout<<ele<<'\n'
const ll mod=1e9 +7;const ll M1=998244353;

int timer,l;
vector<int> tin,tout;
vector<vector<int>> up;
void dfs(int node,int par,vector<vector<int>> &v,vector<int> &vis){
    tin[node]=++timer;
    vis[node]=1;
    up[node][0]=par;
    for(int i=1;i<=l;i++)up[node][i]=up[up[node][i-1]][i-1];
    for(auto x:v[node])if(!vis[x])dfs(x,node,v,vis);
    tout[node]=++timer;
}
bool is_ancestor(int u,int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u,int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i=l;i>=0;i--){
        if(!is_ancestor(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    int n,q;cin>>n>>q;
    vector<vector<int>> ad(n+1);
    f(i,2,n+1){
        int a;cin>>a;
        ad[a].pb(i);
    }
    timer=0;l=ceil(log2(n));
    tin=vector<int>(n+1);tout=tin;
    up=vector<vector<int>> (n+1,vector<int>(l+1,0));
    vector<int> vis(n+1,0);
    dfs(1,1,ad,vis);
    while(q--){
        int a,b;cin>>a>>b;
        cs(lca(a,b));
    }

}