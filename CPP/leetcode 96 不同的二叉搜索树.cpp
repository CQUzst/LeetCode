// class Solution {
// public:
//     int numTrees(int n) {
//        //对一个根来说，唯一二叉树的个数为左子树结点的个数乘以右子树的个数。而根节点可以从1到n 中选择
//         if(n<=1)    
//             return 1;
//         int sum=0;
//         for(int i=1;i<=n;++i)
//             sum+=numTrees(i-1)*numTrees(n-i);
//         return sum;
//     }
// };

// 基于以下原则的构建的BST树具有唯一性：以i为根节点的树，其左子树由[1, i-1]构成， 其右子树由[i+1, n]构成
// 定义 f(i)  为以 [1,i]  能产生的Unique Binary Search Tree的数目，则
// 如果数组为空，毫无疑问，只有一种BST，即空树， f(0)=1  。
// 如果数组仅有一个元素{1}，只有一种BST，单个节点， f(1)=1  。
// 如果数组有两个元素{1,2}， 那么有两种可能
// 看一看3个元素的数组，可以发现BST的取值方式如下：
// f(3) = f(0) ∗ f(2) , when 1 as root
// +f(1) ∗ f(1) , when 2 as root
// +f(2) ∗ f(0) , when 3 as root
// 所以，由此观察，可以得出 f  的递推公式为
// f(i) = f(j − 1) × f(i − j)
class Solution {
public:
    int numTrees(int n) {
        // vector<int> dp(n + 1, 0);
        // dp[0] = 1;
        // dp[1] = 1;
        // for (int i = 2; i <= n; ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         dp[i] += dp[j] * dp[i - j - 1];
        //     }
        // }
        // return dp[n];
        int dp[n+1]={0};
        for(int i=0;i<=n;i++){
            if(i<=1){
                dp[i]=1;
                continue;
            }
            for(int j=1;j<=i;j++)
                dp[i]+=dp[j-1]*dp[i-j];
        }
        return dp[n];
    }
};