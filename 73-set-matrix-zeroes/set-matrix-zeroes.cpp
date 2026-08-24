class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool first_row=false,first_col=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x=matrix[i][j];
                
                if(x==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    if(i==0)first_row=true;
                    if(j==0)first_col=true;
                }
            }
        }
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<n;j++)matrix[i][j]=0;
            }
        }
            if(first_col)
            for(int i=0;i<m;i++)matrix[i][0]=0;
            if(first_row)
            for(int j=0;j<n;j++)matrix[0][j]=0;
        

    }
};