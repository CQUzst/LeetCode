
//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==val){
        //         nums.erase(nums.begin()+i);
        //         i--;
        //     }
        // }
        // return nums.size();
        
          /*
            双指针法
            遍历每一个值，每当不等于val时，改变nums[temp]的数值
            最后返回temp ，即为不等于val的个数
        */
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[temp]=nums[i];
                temp++;
            }
        }
        return temp;
    }
};


//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
//         if(nums.size()==0)
//             return 0;
//         int length=1;
//         for(int i=0;i<nums.size()-1;i++)
//             {
//                 if(nums[i+1]!=nums[i])
//                 {
//                     nums[length]=nums[i+1];
//                     length++;
//                 }
                    
//             }
//         return length;

        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
};



// 删除排序数组中的重复项 II
//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+2;j<nums.size();j++){
                if(nums[j]==nums[i]){
                    nums.erase(nums.begin()+j);
                    j--;
                }
                else break;
            }
        }
        return nums.size();;
    }
};
