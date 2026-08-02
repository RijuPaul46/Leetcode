class Solution {
public:
    pair<int,int> dp[501][501][3];
    pair<int,int> solve(vector<int>&piles,int turn,int i,int j){
        if(i>j)return {0,0};
        auto &ref=dp[i][j][turn];
        if(ref!=make_pair(-1,-1))return ref;
         auto [lefta,leftb]=solve(piles,1,i+1,j);
        auto [righta,rightb]=solve(piles,1,i,j-1);
        if(turn==1){
            if(lefta>leftb){
                return ref={lefta+piles[i],leftb};
            }
            else return ref={righta+piles[j],rightb};
        }
       
            if(leftb>lefta){
                return ref={lefta,leftb+piles[i]};
            }
         return ref={righta,rightb+piles[j]};
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=1;k<=2;k++){
                    dp[i][j][k]={-1,-1};
                }
            }
        }
        auto [alice,bob]=solve(piles,1,0,piles.size()-1);
        return alice>bob;
    }
};