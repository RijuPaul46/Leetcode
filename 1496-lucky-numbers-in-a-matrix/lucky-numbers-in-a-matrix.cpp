class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        unordered_map<int,int> rowmin;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>lucky_num;
        for(int i=0;i<m;i++){
            int mn_idx=0;
            for(int j=1;j<n;j++){
                if(matrix[i][j]<matrix[i][mn_idx])mn_idx=j;
            }
            rowmin[i]=mn_idx;
        }
        for(int j=0;j<n;j++){
            int mx_idx=0;
            for(int i=1;i<m;i++){
                if(matrix[i][j]>matrix[mx_idx][j])mx_idx=i;
            }
            if(rowmin[mx_idx]==j)lucky_num.push_back(matrix[mx_idx][j]);
        }
        return lucky_num;

    }
};