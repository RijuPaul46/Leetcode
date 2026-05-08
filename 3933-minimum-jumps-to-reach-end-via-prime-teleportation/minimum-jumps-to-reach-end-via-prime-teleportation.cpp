
class Solution {
public:
     int MAX=-1;
    vector<bool> isPrime;
     void seive(vector<int>& nums,unordered_map<int,vector<int>> &arr,unordered_map<int,vector<int>> &canJump,int n){
        for(int i=2;i<=MAX;i++){
            if(isPrime[i]){
                for(int j=2*i;j<=MAX;j+=i){
                    isPrime[j]=false;
                    if(arr.count(i)){
                        if(arr.count(j)){
                        for(auto & x: arr[j]){
                            if(x>=0 && x<n)canJump[i].push_back(x);
                        }
                        }
                        
                    }
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> arr;
        for(int i=0;i<n;i++){
            MAX=max(MAX,nums[i]);
            arr[nums[i]].push_back(i);
        }
        isPrime.resize(MAX+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        unordered_map<int,vector<int>> canJump;
       
        
        seive(nums,arr,canJump,n);
         for(auto & x:arr){
            if(isPrime[x.first]){
            for(auto & y:x.second){
                canJump[x.first].push_back(y);
            }
            }
        }
        queue<int> q;
        
        q.push(0);
        int cnt=0;
        vector<bool>visited(n,false);
        visited[0]=true;
        while(!q.empty()){
            int sz=q.size();
            bool found=false;
            for(int i=0;i<sz;i++){
            int idx=q.front();
            if(idx==n-1){found=true;break;}
            q.pop();
            int last=idx-1;
            int next=idx+1;
            if(last>=0 && last<n && !visited[last] ){visited[last]=true;q.push(last);}
            if(next>=0 && next<n && !visited[next]){visited[next]=true;q.push(next);}
            for(auto &x: canJump[nums[idx]]){
                if(x>=0 && x<n && !visited[x]&& x!=idx){visited[x]=true;q.push(x);}
            }
            canJump[nums[idx]].clear();
            }
            if(found)break;
            cnt++;
        }
        return cnt;

    }
};