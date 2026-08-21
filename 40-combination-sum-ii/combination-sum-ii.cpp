// thought process: dont take same elm at same level ... let say we have already use 3 at lvl 2 .... next time if we encounter 3 at lvl 2 we will simply dont calculate that .... but wait what if i reached to lvl 2 via different condition then i have to take it --- wrong approach 
// first sort it ->send start index for each recursion .... now i have choice to select any element from start to onward .... for loop from start to n-1
// now how to prevent from duplicate ... just dont select same elm at each level thats it 
class Solution {
public:
    vector<vector<int>> ans;
    // int dp[51][101][501];// i am not gonna to explore same elm,taken,tgt again
    void solve(int idx,int tgt,vector<int>&cd,vector<int>&arr){
        int n=cd.size();
        if(tgt==0){
            ans.push_back(arr);
            return ;
        }
        if(idx==n)return;
        // if(dp[idx][tgt]!=-1)return dp[idx][tgt];
        
        for(int i=idx;i<n;i++){
            if(!(i>idx && cd[i]==cd[i-1] && cd[i]<=tgt)){
                arr.push_back(cd[i]);
                solve(i+1,tgt-cd[i],cd,arr);
                arr.pop_back();
            }
            if (cd[i] > tgt)
                break;
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>arr;
        // memset(dp,-1,sizeof(dp));
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,arr);
        // for(auto &a:ans)sort(a.begin(),a.end());
        // sort(ans.begin(),ans.end());
        // ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};