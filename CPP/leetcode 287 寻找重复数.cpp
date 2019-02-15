class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int array[nums.size()]={0};
        // for(int i=0;i<nums.size();++i){
        //     array[nums[i]]=0;
        // }
        // for(int i=0;i<nums.size();++i){
        //     array[nums[i]]++;
        // }
        // for(int i=0;i<nums.size();++i){
        //     if(array[nums[i]]>=2)
        //         return nums[i];
        // }
        // return 0;
        
        // 基本思想是将数组抽象为一条线和一个圆环，因为1～nn 之间有n＋1个数，所以一定有重复数字出现
        //所以重复的数字即是圆环与线的交汇点。然后设置两个指针，一个快指针一次走两步，一个慢指针一次走一步。
        //当两个指针第一次相遇时，令快指针回到原点（0）且也变成一次走一步，慢指针则继续前进，再次回合时即是线与圆环的交汇点。
        //粉色点表示相遇点，那么快指针走过a+b+c+b,慢指针走过a+b. 又2(a+b)=a+b+c+b,所以c=a.

        int slow = 0, fast = 0, t = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(true){
            slow = nums[slow];
            t = nums[t];
            if(slow == t) break;
        }
        return slow;
    }
};
