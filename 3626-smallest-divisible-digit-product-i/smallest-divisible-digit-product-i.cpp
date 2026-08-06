class Solution {
public:
    int prdt_digit(int n){
        int prdt=1;
        while(n>0){
            int digit=n%10;
            prdt*=digit;
            n/=10;
        }
        return prdt;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            int prdt=prdt_digit(i);
            if(prdt%t==0)return i;
        }
        return -1;
    }
};