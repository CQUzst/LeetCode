class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        int sum = 0;
        //为了保证优先级大的比相邻的且优先级小的要糖果多。所以我们分两次处理
        //第一次处理递增序列
        for (int i = 1; i < ratings.size(); i++){
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        //第二次处理递减序列，也就是反向递增序列，兼顾保留顺向递增的candy数，所以取max即可 
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        }
        for (int i = 0; i < candies.size(); i++)
            sum += candies[i];
        return sum;
    }
};