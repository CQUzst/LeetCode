class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> a;
        // for(int i=0;i<nums.size();i++)
        //     for(int j=i+1;j<nums.size();j++)
        //         if(nums[i]+nums[j]==target)
        //         {
        //             a.push_back(i);
        //             a.push_back(j);
        //         }
        // return a;

        // vector<int> res;
        // map<int ,int> subMap;
        // for(int i = 0;i<nums.size();i++)
        //     subMap[nums[i]] = i;
        // for(int i = 0;i<nums.size();i++){
        //     int temp = target -nums[i];
        //     auto it = subMap.find(temp);
        //     if(it != subMap.end()&&it->second>i){//这里it->second>i是为了防止重复输出
        //         res.push_back(it->second);
        //         res.push_back(i);
        //     }
        //     //subMap[nums[i]] = i;//然后再把submap中对应的位置的值置为相应的i值
        // }
        
        vector<int> res;
        map<int ,int> subMap;   
        for(int i = 0;i<nums.size();i++){
            int temp = target -nums[i];
            auto it = subMap.find(temp);
            if(it != subMap.end()){
                res.push_back(it->second);
                res.push_back(i);
            }
            subMap[nums[i]] = i;//或者边比较边添加，把submap中对应的位置的值置为相应的i值
        }
        
        return res;
    }
};