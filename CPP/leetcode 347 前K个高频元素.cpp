class Solution {
private:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //先用map产生映射，0(n),然后放入vector中
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            auto it=m.find(nums[i]);
            if(it==m.end()){
                m.insert(make_pair(nums[i],1));
            }else{
                m[nums[i]]++;
            }
        }
        vector<pair<int,int> > vec;
        for(auto it=m.begin();it!=m.end();it++){
            vec.push_back({it->first,it->second});
        }
        //将vector降序排列，输出即可
        sort(vec.begin(),vec.end(),cmp);
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(vec[i].first);
        }
        return res;
    }

};
