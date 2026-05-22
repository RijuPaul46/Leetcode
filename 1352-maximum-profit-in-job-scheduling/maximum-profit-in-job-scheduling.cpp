class Solution {
    int solve(int idx,vector<int> &dp,vector<vector<int>> &arr){
        int n=arr.size();
        if(idx==n)return 0;
        // check whether already endPoint<=ep is calculated or not
        if(dp[idx]!=-1)return dp[idx];
        int skip=solve(idx+1,dp,arr);
        auto it=lower_bound(arr.begin(),arr.end(),vector<int>{arr[idx][1],0,0});
        int take=arr[idx][2];
        if(it!=arr.end()){
            take+=solve(it-arr.begin(),dp,arr);
        }
        return dp[idx]=max(skip,take);
    }
    public:
        int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pt) {
        int n=st.size();
        vector<vector<int>> arr(n,vector<int>(3));
        for(int i=0;i<n;i++){
            arr[i][0]=st[i];
            arr[i][1]=et[i];
            arr[i][2]=pt[i];
        }
        sort(arr.begin(),arr.end());
        vector<int> dp(n,-1);
        
        int mx=solve(0,dp,arr);
        
        return mx;
    }
};