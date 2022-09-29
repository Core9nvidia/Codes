#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const ll Mod=1e9 +7;const ll M1=998244353;

int timer=1;vector<int> vis(10000,0);
vector<int> tin(10000,-1),low(10000,-1);
vector<int> v[10000];
void dfs(int node,int par){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    for(auto x:v[node]){
        if(x==par){}
        else if(vis[x]){
            low[node]=min(low[node],tin[x]);
        }else{
            dfs(x,node);
            low[node]=min(low[node],low[x]);
            if(low[x]>tin[node]){
                cout<<node<<" "<<x<<" is a bridge\n";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    
}