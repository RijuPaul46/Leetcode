#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        vector<ll >ans(n,0);
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto & x:mp){
            auto& arr=x.second;
           
            if(arr.size()>1){
                int firstidx=arr[0];
                ll left=0;
                ll right=0;
                for(int i=0;i<arr.size();i++){
                    right+=abs(arr[i]-firstidx);
                }
                ans[arr[0]]=left+right;
                for(int i=1;i<arr.size();i++){
                    ll dist=abs(arr[i]-arr[i-1]);
                    left=left+dist*(i);
                    right=right-(arr.size()-i)*dist;
                    ans[arr[i]]=left+right;
                }
            }

        }
        return ans;
    }
};