class Solution {
public:
    void sortColors(vector<int>& nums) {  
        //sort(nums.begin(),nums.end());
               
        //// 记录每个颜色出现的次数，慢
        // int counts[3] = { 0 }; 
        // for (int i = 0; i < nums.size(); i++)
        //     counts[nums[i]]++;
        // for (int i = 0, index = 0; i < 3; i++)
        //     for (int j = 0; j < counts[i]; j++)
        //         nums[index++] = i;
        
        //双指针，一遍扫描，更快
        int left=0,i=0,right=nums.size()-1;
        while(i<=right){
            if (nums[i]==0){
                swap(nums[left],nums[i]);
                ++left,++i;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[right]);
                --right;
            }
            else if(nums[i]==1) ++i;
        }
    }
};