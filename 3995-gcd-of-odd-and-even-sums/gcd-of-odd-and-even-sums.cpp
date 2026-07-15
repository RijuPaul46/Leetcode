class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int x=2*n;
        int total=x*(x+1)/2;
        int even=n*(n+1);
        int odd=total-even;
        return gcd(even,odd);
        
    }
};