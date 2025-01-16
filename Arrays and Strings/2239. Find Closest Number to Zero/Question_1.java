class Solution {
    public int findClosestNumber(int[] nums) {
        int closest = nums[0];

        for(int i = 1; i< nums.length; i++){
            if((Math.abs(closest) > Math.abs(nums[i]) )||( Math.abs(closest) == Math.abs(nums[i]) && nums[i]>closest)){
                closest = nums[i];
            }
        }
        return closest;
    }
}

public class Question_1 {
    public static void main(String[] args) {
        int[] nums = {-4, -2, 2, 1, -1, 3};
        Solution sol = new Solution();
        System.out.println(sol.findClosestNumber(nums));
        System.exit(0); 
    }
}
