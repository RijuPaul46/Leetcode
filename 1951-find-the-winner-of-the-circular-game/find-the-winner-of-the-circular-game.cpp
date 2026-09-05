class Solution {
public:
    int w(int n,int k){
        if(n==1)return 0;
        
        return (w(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return 1+w(n,k);
    }
};