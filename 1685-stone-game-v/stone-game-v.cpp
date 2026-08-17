class Solution {
public:
    // lil bit greedy .. is always want to partition so that 
    // discarded one is the smallest possible 
    int dp[501][501];
    int solve(int l,int r,vector<int>&arr,vector<int>&pre){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        for(int i=l;i<r;i++){
            int left=pre[i];
            if(l-1>=0)left-=pre[l-1];
            int right=pre[r]-pre[i];
            
            if(left<right){
                ans=max(ans,left+solve(l,i,arr,pre));
            }
            else if(left==right){
                ans=max(ans,left+max(solve(l,i,arr,pre),solve(i+1,r,arr,pre)));
            }
            else{
                ans=max(ans,right+solve(i+1,r,arr,pre));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& sv) {
        int n=sv.size();
        vector<int>pre(n);
        pre[0]=sv[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+sv[i];
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,sv,pre);
        
    }
};