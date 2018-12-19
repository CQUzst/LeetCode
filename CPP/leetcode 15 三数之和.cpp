class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>res;
        int n=nums.size();
        sort (nums.begin(),nums.end());//排序
        for(int i=0;i<n-2;i++) {
            if(nums[i]>0) break;//当遍历到正数的时候就break
            if(i>0&&nums[i]==nums[i-1]) continue;//重复就跳过.相同的数字不会两次
            int target=0-nums[i];//对于遍历到的数，用0减去这个fix的数得到一个target，然后再找到两个数之和等于target
            int left=i+1,right=n-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==target)
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left]==nums[left+1]) ++left;
                    while(left<right&&nums[right-1]==nums[right]) --right;
                    ++left;
                    --right;
                }
                else if(nums[left]+nums[right]<target) ++left;
                else --right;
            }
        }
    return res;
    }
};