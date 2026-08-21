class Solution {
public:
    vector<vector<int>> ans;
    void solve(int tgt,vector<int>&cd,vector<int>&arr,int idx){
        if(tgt<0)return ;
        if(tgt==0){ans.push_back(arr);return;}
        int n=cd.size();
        for(int i=idx;i<n;i++){
            arr.push_back(cd[i]);
            solve(tgt-cd[i],cd,arr,i);
            arr.pop_back();
        }
        return ;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>arr;
        sort(candidates.begin(),candidates.end());
        solve(target,candidates,arr,0);
        // for(auto &v:ans)sort(v.begin(),v.end());
        // ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};