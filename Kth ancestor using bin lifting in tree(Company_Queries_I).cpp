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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    int n,q;cin>>n>>q;
    int l=ceil(log2(n));
    //l=30;
    vector<vector<ll>> up(n+1,vector<ll>(l+1,0));
    up[1][0]=-1;
    f(i,2,n+1){
        int a;cin>>a;
        up[i][0]=a;
    }
    f(j,1,l+1){
        f(i,1,n+1){
            if(up[i][j-1]<0)up[i][j]=-1;
            else up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    // negative ancestor means no ancestor
    while(q--){
        ll node,k;cin>>node>>k;
        for(ll i=l;i>=0 && node>0;i--){
            if(k&(1LL<<i)){
                node=up[node][i];
            }
        }
        cs(node);
    }
}