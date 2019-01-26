/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()==0)
            return res;
        sort(intervals.begin(),intervals.end(),cmp);
        int left=intervals[0].start,right=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>right){
                res.push_back(Interval(left,right));
                left=intervals[i].start;
                right=intervals[i].end;
            }
            else
                right=max(right,intervals[i].end);
        }
        res.push_back(Interval(left,right));
        return res;
    }
private:
        static bool cmp(Interval &l1,Interval &l2){
            return l1.start<l2.start;
        }       
        
//         vector<Interval> result;  //结果集
//         if(intervals.size() == 0)
//             return result;
//         sort(intervals.begin(), intervals.end(), cmp);   //将区间按左端点从小到大排序
//         int left = intervals[0].start, right = intervals[0].end;  //记录左、右端点
//         for(int i=1;i<intervals.size();i++)
//         {
//             if(intervals[i].start > right)  //当前区间的左端点在前一个的右端点之后
//             {
//                 result.push_back(Interval(left, right));  //把前一个区间放入
//                 left = intervals[i].start;   //更新左、右端点
//                 right = intervals[i].end;
//             }
//             else
//                 right = max(right, intervals[i].end);   //看区间是包含还是相交关系,只要有交叉就会扩大右端点
//         }
//         result.push_back(Interval(left, right));   //放最后一个区间
//         return result;
//     }
// private:
//     static bool cmp(Interval& I1, Interval& I2)
//         return I1.start < I2.start;  //区间左端点的大小关系
};


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a,b;
    char sep;
    vector<pair<int,int>>couple;
    vector<pair<int,int>>res;
    while(cin>>a>>sep>>b){
        couple.push_back({a,b});
    }
    if(couple.size()==0)
        return 0;
    sort(couple.begin(),couple.end());
    int left=couple.begin()->first,right=couple.begin()->second;
    for(int i=1;i<couple.size();i++){
        if(couple[i].first>right){
            res.push_back({left,right});
            left=couple[i].first;
            right=couple[i].second;
        }
        else
            right=max(right,couple[i].second);
    }
    res.push_back({left,right});
    for(int i=0;i<res.size()-1;i++)
        cout<<res[i].first<<","<<res[i].second<<" ";
    cout<<res[res.size()-1].first<<","<<res[res.size()-1].second;
    return 0;
}
