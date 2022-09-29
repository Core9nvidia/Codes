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


vector<int> v[100000],vis(100000,0);
const int maxn=50; // maxn=log2(n);
int level[100000],LCA[100000][maxn+1];


void dfs(int node,int par){
    vis[node]=1;
    LCA[node][0]=par;
    for(auto x:v[node]){
        if(vis[x]==0)dfs(x,node);
    }
}
// https://www.youtube.com/watch?v=w56Qe5wEr2I&list=PL2q4fbVm1Ik64I3VqbVGRfl_OgYzvzt9m&index=5&ab_channel=CodeNCode
// init calculates the parents
// LCA[i][j] calculates the 2^jth parent of node i in log(n) time

// *************************************************************
void init(int n){
    dfs(1,-1);
    f(i,1,maxn+1){
        f(j,1,n+1){
            if(LCA[j][i-1]!=-1){
                int par=LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
            }
        }
    }
}
// *************************************************************




// *************************************************************
// gives lowest commen ancestor in log(n) time   ***************
int getLCA(int a,int b){
    if(level[b]<level[a])swap(a,b);
    int d=level[b]-level[a];

    while(d>0){
        int i=log2(d);
        b=LCA[b][i];
        d-=1<<i;
    }
    if(a==b)return a;

    for(int i=maxn;i>=0;i--){
        if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i]){
            a=LCA[a][i];b=LCA[b][i];
        }
    }return LCA[a][0];
}
// *************************************************************



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    int n;cin>>n;

    // assigning all par =-1 in LCA
    f(i,1,n+1){
        f(j,0,maxn+1){
            LCA[i][j]=-1;
        }
    }

    // taking input (nodes)
    f(i,0,n-1){
        int a,b;cin>>a>>b;
        v[a].pb(b);v[b].pb(a);
    }


    //findinag all parents using init
    init(n);

    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        cs(getLCA(a,b));
    }
}