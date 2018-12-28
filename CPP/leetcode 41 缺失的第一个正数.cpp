class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res=1;
        //将每个数放在它正确的位置，前提是该数是正数，并且该数小于等于序列长度，并且该数对应的正确位置上的那个数不是它，交换到对应位置上
        //注意：交换完第一个位置还是判断第一位置是否正确，所以用while
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
                
        }
        return nums.size()+1;
    }
};