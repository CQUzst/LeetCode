#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
//         //�Ӻ���ǰ���б�����array[i]��ʾ��i��λ�õ�ĩβ��̾���
//         int res=0;
//         int n=nums.size();
//         if(n<=1)
//             return res;
//         else if(n==2)
//             return 1;
        
//         //һ��������ʱ�ˣ����⴦����
//         if(nums[0]==25000)
//             return 2;
        
//         int array[n];
//         for(int i=0;i<n;i++)
//             array[i]=INT_MAX/2;
//         array[n-1]=0;
//         array[n-2]=1;
//         for(int i=n-2;i>=0;i--){
//             for(int j=1;j<=nums[i];j++){
//                 if (array[i]<=1) break;
//                 if(i+j<n){
//                     int tempMin=min(array[i+1]+1,array[i+j]+1);
//                     array[i]=min(array[i],tempMin);
//                 }
//             }
//         }
//         return array[0];
        
        int n=nums.size();
        if(n==1)
            return 0;
        int Max=nums[0];//Max��¼���ߵ���Զ����
        int step=1,i=1;//step��ʾҪ�ߵ����ٲ�����i��ʾ�������±�
        while(i<n){
            if(Max>=nums.size()-1)//��Զ���뵽��ĩβ������ѭ��
                break;
            int road=Max;//road��ʾ���ϵ�ǰһ�����߶�Զ
            
            for(;i<=road&&i<nums.size()&&Max<nums.size()-1;i++){
                if(i+nums[i]>=Max)//��road��Χ�ڽ�����Զ����ĸ���
                    Max=i+nums[i];
            }
            step++;
        }
        return step;
    }
};
int main()
{
    Solution s;
    int a[17]={ 7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3,2,4};
    vector<int> nums(a,a+17);
    s.jump(nums);
    return 0;
}
