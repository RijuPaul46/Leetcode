class Solution {
public:
    // it is surrounded by -1 so there must be a peak inside MVT 
    // if right >curr there must be a peak in right side ...because 
    // let say that peak is in the same row ... then we got it 
    // if it is not in same row .. then there must be some elm 
    // which is bigger than that .. and it will be obviously in right side 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l/2);
            // find max elm idx of that column
            int mx=0;
            for(int i=1;i<m;i++){
                if(mat[i][mid]>mat[mx][mid])mx=i;
            }
            int right=-1,left=-1;
            int curr=mat[mx][mid];
            if(mid+1<n)right=mat[mx][mid+1];
            if(mid-1>=0)left=mat[mx][mid-1];
            if(curr>right && curr>left)return vector<int>{mx,mid};
            else if(curr<right){
                l=mid+1;
            }
            else h=mid-1;
        }
        return vector<int>{-1,-1};
    }
};