class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //������ʱ
        // if(s1.size()>s2.size())
        //     return false;
        // sort(s1.begin(),s1.end());
        // for(int j=0;j<=s2.size()-s1.size();j++){
        //     string s3=s2.substr(j,s1.size());
        //     sort(s3.begin(),s3.end());
        //     if(s1==s3)
        //         return true;
        // }
        // return false;
        
//         //�������ڽⷨ
        int n1=s1.size(),n2=s2.size();
        vector<int>c1(26),c2(26);
        for(auto c:s1)
            c1[c-'a']++;
         
        for(int i=0;i<n2;i++)
        {
            if(i>=n1)
                --c2[s2[i-n1]-'a'];//ɾ����߽���ַ�
            c2[s2[i]-'a']++;//�����ұ߽��ַ�
            if(c1==c2)//vector�ǿ��ԱȽϵģ�std�Ѿ�����
                return true;
        }
        return false;
        
        
        // //��ϣ�����˫ָ��
        // //��һ������cnt����ʾ����Ҫƥ���s1�е��ַ��ĸ�������ʼ��Ϊs1�ĳ���
        // int n1 = s1.size(), n2 = s2.size(), cnt = n1, left = 0;
        // vector<int> m(128);
        // for (char c : s1) ++m[c];
        // //����s2�е��ַ���������ַ��ڹ�ϣ���д��ڣ�˵��ƥ�����ˣ�cnt�Լ�1����ϣ���еĴ���ҲӦ���Լ�1
        // for (int right = 0; right < n2; ++right) {
        //     if (m[s2[right]]-- > 0) 
        //         --cnt;
        //     //Ȼ�����cnt��Ϊ0�ˣ�˵��s1���ַ���ƥ�����ˣ������ʱ���ڵĴ�С����Ϊs1�ĳ��ȣ���ô˵���ҵ���s1��ȫ���У�����true
        //     while (cnt == 0) {
        //         if (right - left + 1 == n1) 
        //             return true;
        //         //����˵�����ڹ���������һЩ��s1�е��ַ������ǽ���߽����ƣ�ͬʱ���Ƴ����ַ����ڹ�ϣ���еĴ�������1,cnt����1
        //         else if (++m[s2[left++]] > 0) 
        //             ++cnt;
        //     }
        // }
        // return false;
    }
};