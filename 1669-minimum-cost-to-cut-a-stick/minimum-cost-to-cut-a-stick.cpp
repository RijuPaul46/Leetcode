class Solution {
public:
    int dp[102][102];
    int solve(int si,int ei,vector<int>&cuts,int n){
        if(si>=ei)return 0;
        auto &ref=dp[si][ei];
        if(ref!=-1)return ref;
        int m=cuts.size();
        int r=cuts[ei];
        int l=cuts[si];
        int cost=INT_MAX;
        for(int i=si+1;i<ei;i++){           
            int cst=(r-l)+solve(si,i,cuts,n)+solve(i,ei,cuts,n);
            cost=min(cost,cst);  
        }
        return ref=cost==INT_MAX?0:cost;
    }
    int minCost(int n, vector<int>& cuts) {
        
        vector<int> arr;
        arr.push_back(0);
        sort(cuts.begin(),cuts.end());
        for(auto &x:cuts)arr.push_back(x);
        arr.push_back(n);
        int m=arr.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(0,m-1,arr,n);
    }
};