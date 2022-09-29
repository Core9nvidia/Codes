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
void prn(vector<int> v){f(i,0,v.size())ce(v[i]);cout<<endl;}
void prn(vi v){f(i,0,v.size())ce(v[i]);cout<<endl;}
ll min(ll a,ll b,ll c){return min(a,min(b,c));}
int min(int a,int b,int c){return min(a,min(b,c));}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    f(i,0,n+1)dp[i][0]=i;f(i,0,m+1)dp[0][i]=i;
    f(i,1,n+1){
        f(j,1,m+1){
            if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            }
        }
    }
    cs(dp[n][m]);
}