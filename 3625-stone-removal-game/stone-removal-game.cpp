class Solution {
public:
    bool canAliceWin(int n) {
        //x2+x-2*n<=0 
        // check if x is even or odd then answer O(1)
        int turn=0;
        int x=10;
        while(n>=0){
            if(n<x){
                return turn;
            }
            n-=x;
            x--;
            turn=turn^1;
        }
        return 1;
    }
};