class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int,int>> arr(n);
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int d=nums[i]-nums[j];
                arr[i][d]=max(arr[i][d],max(1,arr[j][d])+1);
                mx=max(mx,arr[i][d]);
            }
        }
        return mx;
    }
};