//observations: if alice play the last move .. it will make it uneven and it will win...odd number of ?
// if ?==even Bob will be the last ... Now question is can it make sum equal by adding from 0-9 ?? 
// problem ... in each move both play optimally ... but what is optimal there ??? 
// have to use dp ?? alice will try to make difference of both halves higher ....
// case 1  alice have both choice .. chose from first or last half then it can choose the half with higer value and add 9 to it .... if ? only in higher half(still same )..... now if ? only in lower half ... it will add 0 to it 
// bob will do the opposite.... he want to make them equal .... add ..... now question is : local optimal is also global optimal ???  does all this move is optimal ??? 
class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int lsum=0,rsum=0,lc=0,rc=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?')lc++;
                else lsum+=(num[i]-'0');
            }
            else{
               if(num[i]=='?')rc++;
                else rsum+=(num[i]-'0'); 
            }
        }
        if((lc+rc)%2==1)return true;
        if(lc>=rc){
            lc=lc-rc;
            if(lsum>rsum)return true;
            int diff=rsum-lsum;
            int alice=lc/2;
            if(diff==9*alice)return false;
            return true;
        }
        rc=rc-lc;
            if(rsum>lsum)return true;
            int diff=lsum-rsum;
            int alice=rc/2;
            if(diff==9*alice)return false;
            return true;
        

    }
};