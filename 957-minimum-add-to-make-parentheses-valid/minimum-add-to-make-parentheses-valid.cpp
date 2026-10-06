class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int req=0,score=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')score++;
            else score--;
            if(score<0){
                req++;
                score=0;
            }
        }
        return req+score;
    }
};