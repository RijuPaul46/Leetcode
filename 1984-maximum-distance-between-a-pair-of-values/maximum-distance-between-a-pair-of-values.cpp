class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=-1;
        int ans=0;
        while(i<n1){
            if(j<i){
                auto it=lower_bound(nums2.begin()+i,nums2.end(),nums1[i]);
                if(it!=nums2.end()){
                    j=it-nums2.begin();
                    ans=max(ans,abs(j-i));
                }    
            }
                while(j+1<n2 && nums2[j+1]>=nums1[i])j++;
                if(j>=i)ans=max(ans,abs(j-i));
            i++;
        }
        return ans;
    }
};