class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // sort(nums.begin(),nums.end());
        // int len=nums.size();
        // int result=INT_MAX;
        // int left,right,closeValue;
        // for(int i=0;i<len-2;i++){
        //     left=i+1;
        //     right=len-1;
        //     while(left<right){
        //         closeValue = nums[i] + nums[left] + nums[right];
        //         if(target==closeValue) return closeValue;
        //         else if(closeValue<target) left++;
        //         else  right--;
        //         if(result==INT_MAX||abs(closeValue-target)<abs(result-target))
        //            result=closeValue;
        //      }
        // }
        // return result;

        int res=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target) return sum;
                else if(sum>target) right--;
                else left++;
                if(res==INT_MAX||abs(sum-target)<abs(res-target))
                    res=sum;
            }
        }
        return res;
    }
};