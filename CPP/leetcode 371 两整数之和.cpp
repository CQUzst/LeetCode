class Solution {
public:
    int getSum(int a, int b) {
        //计算机底层是通过 “异或” 和 “与” 两个位运算来实现的，“异或” 是不带进位的结果， “与” 是进位
        //递归
        if(b == 0)//不进位就跳出
             return a;
        int sum = a ^ b; //相加但不进位
        int carry = (a & b) << 1; //进位但不相加，将该进位的左移进位
        return getSum(sum, carry); //递归
    }
};
