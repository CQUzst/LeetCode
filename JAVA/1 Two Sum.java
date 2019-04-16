class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] result=new int[2];
        for(int i=0;i<nums.length;i++){
            int second=target-nums[i];
            for(int j=i+1;j<nums.length;j++){
                if(nums[j]==second){
                    result[0]=i;
                    result[1]=j;
                    return result;
                }
            }
        }
        return result;
        // Map<Integer, Integer> map = new HashMap<>();
        // for (int i = 0; i < nums.length; i++) {
        //     int complement = target - nums[i];
        //     if (map.containsKey(complement)) {
        //         return new int[] { map.get(complement), i };
        //     }
        //     map.put(nums[i], i);
        // }
        // throw new IllegalArgumentException("No two sum solution");
    }
}
