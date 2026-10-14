class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>(num*9))return "";
        string ans(num,'0');
        for(int i=0;i<num;i++){
            if(sum>0){
                int digit=min(sum,9);
                ans[i]=(digit+'0');
                sum-=digit;
            }
            else break;
        }
        return ans;
    }
};