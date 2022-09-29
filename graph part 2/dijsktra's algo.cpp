#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// 7355277531
// 8155
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
       int n,m;cin>>n>>m;
       vector<ll> dis(n+1,1e18),vis(n+1,0);vector<pair<int,int>> v[n+5];
       for(int i=0;i<m;i++){
           int a,b,w;cin>>a>>b>>w;v[a].push_back({b,w});
           
       }
       priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> q;
       q.push({0,1});dis[1]=0;
       while(!q.empty()){
           auto cur=q.top();q.pop();
           if(vis[cur.second])continue;
           vis[cur.second]=1;
           for(auto x:v[cur.second]){
               if(dis[x.first]>dis[cur.second]+x.second){
                   if(!vis[cur.second])q.push({dis[cur.second]+x.second,x.first});
                   dis[x.first]=dis[cur.second]+x.second;
               }
               
           }
       }
       
       for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<endl;
    
}

























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

vector<pair<int,int>> v[1000];



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    int n,m;cin>>n>>m;
    f(i,0,m){
        int a,b,w;cin>>a>>b>>w;
        v[a].pb({b,w});
        v[b].pb({a,w}); // if graph is undirected 
    }

    // min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> dis(n+1,1e9);
    q.push({0,1});
    dis[1]=0;

    while(!q.empty()){
        int curr= q.top().S;
        int curr_d=q.top().F;
        q.pop();
        for(auto x:v[curr]){
            if(x.S+curr_d< dis[x.F]){
                dis[x.F]=x.S+curr;
                q.push({dis[x.F],x.F});

            }
        }
    }

    // distance of each node from first
    f(i,1,n+1)ce(dis[i]);cout<<endl;
}