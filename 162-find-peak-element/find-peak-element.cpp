class Solution {
public:
    //concept is if both side is -inf ... then there is atleast
    //one peak inside .... now we can do bs 
    // if left and right is less then it is peak
    //if left is less then there must be a peak in right ...
    // MVT
    using ll=long long;
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        vector<ll>arr;
        arr.push_back(LLONG_MIN);
        for(auto &x:nums){
            arr.push_back(1ll*x);
        }
        arr.push_back(LLONG_MIN);
        int l=1,r=n;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
                ans=mid;
                break;
            }
            else if(arr[mid-1]<arr[mid]){
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans-1;
    }
};