class Solution {
public:
    int countCommas(int n) {
        int x=n;
        int d=0;
        while(n>0){
            d++;
            n/=10;
        }
        if(d<=3)return 0;
        cout<<d<<endl;
        int sm=0;
        for(int i=4;i<d;i++){
            sm+=(i/3)*9*pow(10,i-1);
        }
        sm+=1+(x-pow(10,d-1))*((int)(d/3));
        return sm;

    }
};