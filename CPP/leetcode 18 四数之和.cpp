class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.size()<4) return res;
        sort (nums.begin(),nums.end());//排序
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
// int n=nums.size();
// if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target)break;//排除不可能情况，用来加速
// if (nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target)continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j> i+1 &&nums[j]==nums[j-1]) continue;
// if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target)break;
// if (nums[i]+nums[j]+nums[n-2]+nums[n-1] < target)continue;
                int left=j+1,right=nums.size()-1;
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while (left<right&&nums[left]==nums[left+1]) left++;
                        while(left<right&&nums[right]==nums[right-1])right--;
                        left++;
                        right--;
                    }
                    else if(sum>target) right--;
                    else left++;
                }
            }
        }
        // set<vector<int>> st(res.begin(), res.end());//去重
        // res.assign(st.begin(), st.end());
        return res;

    }
};
