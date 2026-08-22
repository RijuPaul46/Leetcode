class Solution {
public:
    bool checkDivisibility(int n) {
        int sm=0;
        int prdt=1;
        int num=n;
        while(n>0){
            int digit=n%10;
            sm+=digit;
            prdt*=digit;
            n/=10;
        }
        return (num%(sm+prdt)==0);
    }
};