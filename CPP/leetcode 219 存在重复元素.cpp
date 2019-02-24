//存在重复元素II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map<int,int>m;
        // for(int i=0;i<nums.size();i++){
        //     if(i>k)
        //         m[nums[i-k-1]]--;
        //     m[nums[i]]++;
        //     if(m[nums[i]]>1)
        //         return true;
        // }
        // return false;
        
        
        // unordered_map<int,int> record;
        // for(int i=0;i<nums.size(); i++){
        //     if(record.find(nums[i])==record.end())
        //         record[nums[i]] = i;
        //     else if(i-record[nums[i]]<=k)
        //         return true;
        //     else
        //         record[nums[i]] = i;//更新最近的位置
        // }
        // return false;
        
        
        unordered_map<int,int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (i - j > k){
                m.erase(nums[j++]);
            }
            if (m.find(nums[i])!=m.end()){
                return true;
            }
            m.insert({nums[i],i});
        }
        return false;
    }
};

