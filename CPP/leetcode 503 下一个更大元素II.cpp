class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //暴力搜索，第一次写的笨方法，思路简单，耗时较多
//         int len=nums.size();
//         vector<int> res(len,INT_MIN);
//         int maxNumber=INT_MIN;
//         for(int i=0;i<len;i++){
//             if(nums[i]>maxNumber)
//                 maxNumber=nums[i];
//         }
//         for(int i=0;i<len;i++){
//             if(nums[i]==maxNumber){
//                 res[i]=-1;
//                 continue;
//             }
                
//             for(int j=i+1;j<i+len;j++){
//                 if(j>=len) j=0;
//                 if(nums[j]>nums[i]){
//                     res[i]=nums[j];
//                     break;
//                 }
//             }
//         }
//         return res;
        
        //单调栈用法，保持一个栈，栈顶元素最小，遍历nums如果有更小的就将下标入栈
        //有比栈顶元素大的就取出下标，注意可能要循环取出，可能出现一段下标对应的值都小于当前nums[i]的情况
        int n = nums.size();
        //先初始化为-1，对应不存在的情况，不用后面再分类讨论
        vector<int> res(n, -1);
        stack<int> s; // index stack下标栈
        for (int i = 0; i < n * 2; i++) {//最多只遍历两边就足够末尾转一圈，所以n*2即可
            int num = nums[i % n]; //取余造成循环避免越界
            while (!s.empty() && nums[s.top()] < num) {
                res[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }   
        return res;
    }
};