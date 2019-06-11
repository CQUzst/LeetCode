#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Point {
    int x;
    int y;
    Point(int a, int b) :x(a), y(b) {}
};

bool cmp(Point x1, Point x2) {
    return x1.x > x2.x;
}

vector<Point> maxPoint(vector<Point>& nums) {
    int size = nums.size();
    vector<Point> res;
    sort(nums.begin(), nums.end(), cmp);//按x从大到小排序
    res.push_back(nums[0]);
    int tempY = nums[0].y;//从图上右边往左数，x减小，要满足条件，下一个maxPoint的y必要大于tmpY
    for (int i = 1; i < size; i++) {
        if (nums[i].y > tempY) {
            res.push_back(nums[i]);
            tempY = nums[i].y;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<Point> nums(n, Point(0, 0));
    vector<Point> res;

    for (int i = 0; i < n; i++) {
        // 注： 这里使用cin 输入会导致超时，只能通过80%例子
        scanf("%d %d\n", &nums[i].x, &nums[i].y);
    }

    res = maxPoint(nums);

    for (int i = res.size() - 1; i >= 0; i--) {
      printf("%d %d\n",res[i].x,res[i].y);
    }

    return 0;
}
