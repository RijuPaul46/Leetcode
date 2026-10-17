class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr=nums;
        sort(arr.begin(),arr.end(),[&](int a,int b){
            int da=digitsum(a);
            int db=digitsum(b);
            if(da<db)return true;
            if(db<da)return false;
            return a<b;
        });
        unordered_map<int,int>pos;
        int cnt=0;
        for(int i=0;i<n;i++){
            // cout<<arr[i]<<endl;
            pos[arr[i]]=i;
        }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i] && arr[i]!=nums[i]){
                int cycle=0;
                int idx=i;
                while(!visited[idx]){
                    visited[idx]=1;
                    cycle++;
                    idx=pos[nums[idx]];
                }
                cnt+=cycle-1;
            }
        }
        return cnt;

    }
};