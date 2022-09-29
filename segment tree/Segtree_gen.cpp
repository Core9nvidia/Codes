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

const int segtree_size = 1e5;  // limit for array size
int n;  // array size
int t[2 * segtree_size];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    
}