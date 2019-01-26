class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        //快慢指针
        int pos=0;
        for(size_t i=0;i<nums.size();i++)
            if(nums[i]!=0)
                nums[pos++]=nums[i];
        while(pos<nums.size()) 
            nums[pos++]=0;

        //更快
        //遍历i，非零就把它往前面的零交换，原地交换 i++，j++
        //nums[j]会一直加，直到出现零就不加了
       //  for(int i=0,j=0;i<nums.size();i++){
       //     if(nums[i]){
       //         swap(nums[i],nums[j++]);
       //     }
       // }
    }
};