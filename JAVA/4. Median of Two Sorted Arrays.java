class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int i = 0;
        int j = 0;
        int[] total = new int[len1 + len2];//新建数组，从小到大合并排序
        while (i < len1 && j < len2) {
            if (nums1[i] <= nums2[j]) 
                total[i + j] = nums1[i++];
            else 
                total[i + j] = nums2[j++];
        }
        if (i == len1)
        {
            while (j < len2)
                total[i + j] = nums2[j++];
        } 
        else
        {
            while (i < len1) 
                total[i + j] = nums1[i++];
        }
        int len3 = total.length;
        return len3%2 == 0 ? (total[len3/2] + total[len3/2 - 1])/2.0 : total[(len3 - 1)/2];
    }
}
