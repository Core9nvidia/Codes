#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,q;cin>>n>>m>>q;
    ll INF=1e18;
    ll d[n][n];
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)d[i][j]=INF;d[i][i]=0;}
    for(ll i=0;i<m;i++){
        ll a,b,w;cin>>a>>b>>w;
        a--;b--;
        d[a][b]=min(d[a][b],w);
        d[b][a]=min(d[b][a],w);
    }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                }
            }
        }
        while(q--){
            int a,b;cin>>a>>b;
            a--;b--;
            if(d[a][b]==INF)cout<<"-1\n";
            else cout<<d[a][b]<<endl;
        }
}