class Solution {
public:
    int solve(vector<long long int> &sum, vector<int> &v, int i,int k){
        long long int s=0,rec=0,lo=0,hi=i,ans=0,mid=0;
        while(lo<=hi){
            mid=(hi-lo)/2+lo;
            if(mid==0){
                s=sum[i]+k;
            }else{
                s=sum[i]-sum[mid-1]+k;
            }rec=v[i]*(i-mid+1);
            if(s>=rec){
                ans=i-mid+1;
                hi=mid-1;
            }else lo=mid+1;
        }return int(ans);
    }
    int maxFrequency(vector<int>& v, int k) {
        long long int n=v.size();sort(v.begin(),v.end());
        vector<long long int> sum(n);
        sum[0]=v[0];
        for(int i=1;i<n;i++)sum[i]=sum[i-1]+v[i];
        int mx=1;
        for(int i=0;i<n;i++){
            mx=max(mx,solve(sum,v,i,k));
        }return mx;
    }
};