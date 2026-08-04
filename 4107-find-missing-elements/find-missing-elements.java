class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> ls= new LinkedList<>();
        int n=nums.length;
        int min=nums[0];
        int max=nums[0];
        for(int i=1;i<n;i++){
            min=Math.min(min,nums[i]);
            max=Math.max(max,nums[i]);
        }
        int range=max-min+1;
        boolean track[]=new boolean[range];
        for(int i=0;i<n;i++){
            track[nums[i]-min]=true;
        }
        for(int i=0;i<range;i++){
            if(!track[i])ls.add(i+min);
        }
        return ls;
        
    }
}