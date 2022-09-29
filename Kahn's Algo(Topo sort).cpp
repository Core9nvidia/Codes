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
const ll mod=1e9 +7;
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n,m;
    vector<vector<int>> adj(n+1);
    f(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
    }

    vector<int> in_degree(n+1,0),toposort;
    f(i,1,n+1){
        for(auto x:adj[i]){
            in_degree[x]++;
        }
    }
    queue<int> q;
    f(i,1,n+1){
        if(in_degree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int cur_node=q.front();q.pop();
        toposort.push_back(cur_node);
        for(auto x:adj[cur_node]){
            in_degree[x]--;
            if(in_degree[x]==0)q.push(x);
        }
    }
    if(toposort.size()!=n){
        cout<<"Cycle detected\n";
    }
}