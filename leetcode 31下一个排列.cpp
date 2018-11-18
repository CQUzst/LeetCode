class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //从末尾往前看，数字逐渐变大,如果有变小的，说明可以用后面的比该数字大的数去交换，然后把后面的数字逆转即可
        int i=0,j=0;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i+1]>nums[i]){//相邻俩数先比较一下，如果右边比左边大，说明此时的i是可以被交换的，进入交换流程
                for(j=nums.size()-1;j>i;j--){
                    if(nums[j]>nums[i])break;//从末尾往前看第一个比nums[i]位置大的值，保存此时的i，j
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());//然后把后面的数字逆转即可
                return;
            }
        }
        reverse(nums.begin(), nums.end());//如果最大，直接逆转成最小
    }
};