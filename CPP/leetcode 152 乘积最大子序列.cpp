class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         int res=nums[0];
//         for(int i=0;i<nums.size();i++){
//             res=max(res,nums[i]);
//         }
//         for(int i=0;i<nums.size()-1;i++){
//             int multy=nums[i];
//             for(int j=i+1;j<nums.size();j++){
//                 multy=multy*nums[j];
//                 res=max(res,multy);
//             }
//         }

//         return res;
        
        if (nums.size() == 1 ) return nums[0];
        int len = nums.size();
        vector<int> dp_max(len,0),dp_min(len,0);
        int max_value = INT_MIN;
        for (int i=0; i<len; i++){
            if (i == 0){
                //dp_max[i]表示当前最大乘积，min最小
                dp_max[i] = nums[i];
                dp_min[i] = nums[i];
            }
            else{
                //动态规划，之前的最大值*当前值，dp_min[i]表示最小值，避免负值影响
                dp_max[i] = max(dp_max[i-1]*nums[i],max(dp_min[i-1]*nums[i],nums[i]));
                dp_min[i] = min(dp_max[i-1]*nums[i],min(dp_min[i-1]*nums[i],nums[i]));
            }
            max_value = max(max_value,dp_max[i]);
        }
        return max_value;
    }
};
