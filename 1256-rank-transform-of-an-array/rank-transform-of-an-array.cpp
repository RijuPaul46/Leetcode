class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)return {};
        unordered_map<int,unordered_set<int>> mp;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=arr[i];
            mp[arr[i]].insert(i);
        }
        sort(arr.begin(),arr.end());
        int rank=1;
        int x=arr[0];
        for(auto &idx:mp[x])ans[idx]=1;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                rank++;
            }
            int elm=arr[i];
            for(auto &idx:mp[elm])ans[idx]=rank;
        }
        return ans;
    }
};