class Solution {
public:
    int find_par(int i,vector<int>&par){
        if(par[i]==i)return i;
        return par[i]=find_par(par[i],par);
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int r=0;
        for(int i=0;i<n;i++){
            int val=nums[i]+maxDiff;
            auto it=upper_bound(nums.begin(),nums.end(),val);
            if(it!=nums.begin()){
                it--;
                int idx=it-nums.begin();
                if(idx>r){
                for(int j=r+1;j<=idx && n-1;j++){
                    par[j]=i;
                }
                r=idx;
                }
            }
        }
        vector<bool>ans;
        for(auto &q:queries){
            int u=q[0];
            int v=q[1];
            if(find_par(u,par)==find_par(v,par))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};