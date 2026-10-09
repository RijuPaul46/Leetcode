#define db double
class Solution {
public:
    int minInsertions(string s) {
        db score=0;
        int need=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(score<0){
                    db val=abs(score);
                    db add=floor(val)+2*((val-floor(val))>0);
                    need+=add;
                    score=0;
                }
                if((score-floor(score))==0.5){
                    need+=1;
                    score=floor(score);
                }
                score+=1.0;
            }
            else{
                score-=0.5;
            }
        }
        if(score<0)
        need+=floor(abs(score))+2*((abs(score)-floor(abs(score))>0));
        else need+=2*score;
        return (int)need;
    }
};