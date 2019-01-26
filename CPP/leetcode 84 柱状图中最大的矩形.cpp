class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        // int result = 0;
        // stack<int> s;
        // heights.push_back(0);
        // int i = 0;
        // while(i < heights.size()) {
        //     if (s.empty() || heights[i] > heights[s.top()])//维持一个递增堆栈，如果当前元素大于栈顶元素，则入栈
        //         s.push(i++);
        //     else //否则：记录最高高度，弹出，记录当前最高高度*当前坐标到最高高度距离，更新最大面积
        //     {
        //         int tmp = s.top();
        //         s.pop();
        //         result = max(result,heights[tmp] * (s.empty() ? i : i - s.top() - 1));
        //     }
        // }
        // return result;
        
        int res = 0, n = heights.size();
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && heights[i] <= heights[i + 1])//比左边大的都跳过，升序跳过，降序开始计算面积
                continue;
            int minH = heights[i];
            for (int j = i; j >= 0; --j) //从当前位置往前，找到一个最小高度，将之间的距离乘以最小高度就是当前举行面积
            {
                minH = min(minH, heights[j]);
                int area = (i - j + 1) * minH;
                res = max(res, area);
            }
        }
        return res;
    }
};
