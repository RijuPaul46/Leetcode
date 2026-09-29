#define db double
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        // let assume the whole array ..
        // divide it into two halves ... left half size sz=(m+n+1)/2
        // let x number of elm from nums1 in first half
        // then y=sz-x from nums2
        // now check if this is valid partition or not 
        // valid if all elm in left <all elm in right 
        // nums1[x-1]<= nums2[y] && nums2[y-1]<=nums1[x] 
        // if valid partition then find median according to even odd
        // question is how to decide how many elem from nums1 ??
        // how binary search will help ?? 
        // for bs monotonocity is required ... but there only x
        // is valid .... x+1 are not valid partition .. so why bs ?
        // if m+n is odd ... then 
        int sz=(m+n+1)/2;
        int l=max(0,sz-n),h=min(sz,m);
        int ans=-1;
        while(l<=h){
            int x=l+(h-l)/2;
            int l1=INT_MIN,r1=INT_MAX;
            int y=sz-x;
            int l2=INT_MIN,r2=INT_MAX;
            if(x>0)l1=nums1[x-1];
            if(x<m)r1=nums1[x];
            if(y>0)l2=nums2[y-1];
            if(y<n)r2=nums2[y];
            if(l1<=r2 && l2<=r1){
                ans=x;
                break;
            }
            else if(l1>r2){
                h=x-1;
            }
            else {
                l=x+1;
            }
        }
        int x=ans;
        int l1=INT_MIN,r1=INT_MAX;
            int y=sz-x;
            int l2=INT_MIN,r2=INT_MAX;
            if(x>0)l1=nums1[x-1];
            if(x<m)r1=nums1[x];
            if(y>0)l2=nums2[y-1];
            if(y<n)r2=nums2[y];
        if((m+n)%2==1){
            // cout<<"odd"<<endl;
            db ans= (db)max(l1,l2);
            return ans;
        }
        return( (db)max(l1,l2)+(db)min(r1,r2) )/(db)2;
    }
};