class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) 
            return false;
        int left = 0, right = nums.size() - 1;
        while (left <= right) //二分法
        {
            int mid = left+(right - left) / 2;
            if (nums[mid] == target) 
                return true;
            else if (nums[mid] < nums[right])//右半边单调递增
            {
                if (nums[mid] < target && nums[right] >= target) //如果target在右边范围内
                    left = mid + 1;
                else //target
                    right = mid - 1;
            } 
            else if (nums[mid] > nums[right])//左半边单调递增
            {
                if (nums[left] <= target && nums[mid] > target) //如果target在左边范围内
                    right = mid - 1;
                else 
                    left = mid + 1;
            } 
            else //nums[mid]==nums[right]且nums[mid]!=target的情况，将右边界缩小
                --right;
        }
        return false;
    }
};
