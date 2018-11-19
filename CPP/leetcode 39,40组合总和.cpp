#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> res;
//        vector<int> item;//一个组合
//        sort(candidates.begin(),candidates.end());
//        backTrack(candidates,0,target,item,res);//数组，起始位，目标值，一个组合，结果
//        return res;
//    }
//    void backTrack(vector<int> candidates,int start,int target,vector<int> &item,vector<vector<int>> &res){
//        if(target<0)
//            return;
//        if(target==0){
//            res.push_back(item);
//            return;
//        }
//        for(size_t i=start;i<candidates.size();i++){//循环里会增加start，可以起到去重作用
//            item.push_back(candidates[i]);
//            backTrack(candidates,i,target-candidates[i],item,res);
//            item.pop_back();
//        }
//    }
//};
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>temp;
        int sum=0;
        int index=0;
        backtrack(candidates,target,res,temp,index,sum);
        return res;
    }
    void backtrack(vector<int>& candidates, int target,
                   vector<vector<int>>&res,vector<int>&temp,int index,int sum){
        if(target<sum) return;
        if(target==sum) {
            res.push_back(temp);
            return;
        }

        //每个元素不能无限制地取，注意i+1，在递归的时候将参数改成从后一个元素开始递归
        for(int i=index;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            backtrack(candidates,target,res,temp,i+1,sum+candidates[i]);
            temp.pop_back();
            while(candidates[i]==candidates[i+1]) i++;
            /*将第一个1放入之后回溯会得到所有包含这个1的情况，
            就不再需要将后面的1再放入数组中再回溯了，从而去除了重复的情况
            比如数组为[1,1,1,1,2]，目标是3，那么将第一个1放入list后回溯，
            变成[1,1,1,2]，目标是2，会得到两个数组[1,1][2],再加上第一个1，就是[1,1,1][1,2]，
            这包含了所有的含有1的情况，不需再考虑后面的1了，从而避免重复数组。*/
        }
    };
    int main(){
        Solution so;
        int target=8;
        int a[]={10,1,2,7,6,1,5};
        vector<int> vec(a,a+7);
        so.combinationSum2(vec,target);
        return 0;
    }
