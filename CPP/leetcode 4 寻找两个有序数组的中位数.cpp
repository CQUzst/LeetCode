class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> nums3;
		int p1 = 0;
		int p2 = 0;
		int p3 = 0;
		int length1 = nums1.size();
		int length2 = nums2.size();
		double anwser;
		while (p1 < length1 || p2 < length2)//把nums1和nums2合并排序到nums3中
        {
			if(p1<length1&&p2<length2)
			{
				if (nums1[p1] <= nums2[p2])
				{
					nums3.push_back(nums1[p1]);
					p1++;
					p3++;
				}
				else {
					nums3.push_back(nums2[p2]);
					p2++;
					p3++;
				}
			}
			else if (p1 >= length1)
			{
				nums3.push_back(nums2[p2]);
				p2++;
				p3++;
			}
			else
			{
				nums3.push_back(nums1[p1]);
				p1++;
				p3++;
			}
		}
        //找中位数
		if (nums3.size() % 2 == 0)//偶数
        {
			anwser = nums3[nums3.size() / 2 - 1] + nums3[nums3.size() / 2];
			anwser = anwser / 2;
			return anwser;
		}
		else//奇数
        {
			anwser = nums3[(nums3.size() + 1) / 2 - 1];
			return anwser;
		}
    }
};