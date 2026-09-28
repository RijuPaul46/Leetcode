class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int score=0;
        for(auto &c:s){
            if(c=='(')score++;
            if(c==')')score--;
            ans=max(ans,score);
        }
        return ans;
    }
};