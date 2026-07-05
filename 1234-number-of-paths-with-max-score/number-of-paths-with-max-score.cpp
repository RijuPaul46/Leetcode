#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<pair<ll,ll>>> mat(n,vector<pair<ll,ll>>(n));
        mat[n-1][n-1]={0,1};
        for(int i=n-2;i>=0;i--){
            if(board[n-1][i]=='X'){
                mat[n-1][i]={INT_MIN,0};
            }
            else{
                mat[n-1][i]={mat[n-1][i+1].first+(board[n-1][i]-'0'),mat[n-1][i+1].second};
            }
            if(board[i][n-1]=='X'){
                mat[i][n-1]={INT_MIN,0};
            }
            else{
                mat[i][n-1]={mat[i+1][n-1].first+(board[i][n-1]-'0'),mat[i+1][n-1].second};
            }

        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(board[i][j]!='X'){
                ll sm1=mat[i][j+1].first;
                ll sm2=mat[i+1][j].first;
                ll sm3=mat[i+1][j+1].first;
                ll mx=max(sm1,max(sm2,sm3));
                ll cnt=0;
                if(sm1==mx){
                    cnt=(cnt+mat[i][j+1].second)%m;
                }
                if(sm2==mx){
                    cnt=(cnt+mat[i+1][j].second)%m;
                }
                if(sm3==mx){
                    cnt=(cnt+mat[i+1][j+1].second)%m;
                }
                mat[i][j].first=mx;
                if(!(i==0 && j==0))mat[i][j].first+=(board[i][j]-'0');
                mat[i][j].second=cnt;}
                else{
                   mat[i][j].first=INT_MIN;
                   mat[i][j].second=0; 
                }
            }
        }
        vector<int>ans(2,0);
        if(mat[0][0].first<0)return ans;
        ans[0]=(int)mat[0][0].first;
        ans[1]=(int)mat[0][0].second;
        return ans;
    }
};