class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int volume=min(height[left],height[right])*(right-left);
            res=max(res,volume);
            if(height[left]>height[right]) right--;
            else left++;
        }
        return res;
    }
};