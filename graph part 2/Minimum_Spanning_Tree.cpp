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

//   *******************************
//
//      struct edge could be replaced by pair<int,pair<int,int>>
//      Krushkal's Algo-----
//                          sort edges in increasing order of weight and check whether these edges are connected or not
//                          (i.e. we can reach from one node to another) 
//                          if not , connect them and add weight to sum
//
//   *******************************

struct edge{
    int a;int b;int w;
};

edge ar[100001];
int p[10001];



bool comp(edge a,edge b){
    if(a.w<b.w)return true;
    return false;
}

int find(int n){
    vector<int> v;
    while(p[n]>0){
        v.pb(n);
        n=p[n];
    }
    f(i,0,v.size()){
        p[v[i]]=n;
    }
    
    return n;
}

void merge(int a,int b){
    p[a]+=p[b];
    p[b]=a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    int n,m;cin>>n>>m;
    int sum=0;
    f(i,0,n+1)p[i]=-1;
    f(i,0,m){
        int a,b,w;
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }
    sort(ar,ar+m,comp);

    f(i,0,m){
        int a=find(ar[i].a);
        int b=find(ar[i].b);
        if(a!=b){
            sum+=ar[i].w;
            merge(a,b);
        }
    }
    cs(sum);
}