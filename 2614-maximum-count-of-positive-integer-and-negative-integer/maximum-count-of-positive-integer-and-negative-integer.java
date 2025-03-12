class Solution {
    public int maximumCount(int[] nums) {
        int nc=0,pc=0;
        for(int i = 0; i <nums.length;i++ ){
            if(nums[i] < 0) {
                nc++;
            }
            else if( nums[i]>0) {
                pc++;
            }
        }
        return Math.max(nc,pc);
    }
}