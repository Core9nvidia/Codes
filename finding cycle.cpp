 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> v[100011],vis(100011,0),s;
int done=1;
void dfs(int node,int par){
    //cout<<node<<" "<<par<<"\n";
    //if(!done)return;
    vis[node]=1;
    s.push_back(node);
    for(auto x:v[node]){
        if(!done)return;
        if(vis[x]==0){
            dfs(x,node);
        }else if( vis[x]==1 && x!=par){
                done=0;
                vector<int> t;
                int pos=s.size()-1;
                while(pos>=0 && s[pos]!=x){
                    t.push_back(s[pos]);
                    pos--;
                }
                t.push_back(x);t.push_back(node);
                cout<<t.size()<<endl;
                for(auto y:t){
                    cout<<y<<" ";
                }cout<<endl;
                return;
            
        }
    }
    s.pop_back();
}
 
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0 && done){
            dfs(i,-1);
        }
    }
    if(done){
        cout<<"IMPOSSIBLE\n";
    }
}