class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>even,odd;
        for(auto &x:nums1){
            if(x%2==0)even.push_back(x);
            else odd.push_back(x);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        // let try to make all even
        bool flag=true;
        for(auto &x:nums1){
            if(x%2==1){
                int elm=x-1;
                int idx=upper_bound(odd.begin(),odd.end(),elm)-odd.begin();
                if(idx==0){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)return true;
        // try to make all odd
        flag=true;
        for(auto &x:nums1){
            if(x%2==0){
                int elm=x-1;
                int idx=upper_bound(odd.begin(),odd.end(),elm)-odd.begin();
                if(idx==0){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
};