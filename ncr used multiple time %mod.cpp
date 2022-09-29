#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl '\n' 
#define ce(ele) cout<<ele<<' '
#define CASE(t) int t; cin>>t; while(t--)
#define sor(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define vi vector<ll>
#define cs(ele) cout<<ele<<'\n'
const int N = 300500;
const int mod = 1000000007;
ll fact[N];
ll invFact[N];

ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

ll ncr(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
       
       CASE(t){
           int n,m,k;cin>>n>>m>>k;vector<int> v(n);
           f(i,0,n)cin>>v[i];
           sor(v);
           ll res=0;
           f(i,0,n){
               ll cnt=0;
               ll r=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
               res=(res+ncr(r-i-1,m-1))%mod;
           }
           cs(res);
       }
       
}