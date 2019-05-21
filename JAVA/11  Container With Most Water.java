class Solution {
    public int maxArea(int[] height) {
        int left=0,right=height.length-1;
        int res=0;
        while(left<right){
            int volume=Math.min(height[left],height[right])*(right-left);
            res=Math.max(res,volume);
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return res;
    }
}
