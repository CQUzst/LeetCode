class Solution {
public:
    string addBinary(string a, string b)
    {
//         //第一次写的，分类一一讨论
//         int len1=a.size();
//         int len2=b.size();
//         int len=max(len1,len2);

//         string c;
//         c.resize(len);
//         if(len1<len)
//         {
//             reverse(a.begin(),a.end());
//             for(int k=0;k<len-len1;k++)
//                 a=a+'0';
//             reverse(a.begin(),a.end());
//         }
//         if(len2<len)
//         {
//             reverse(b.begin(),b.end());
//             for(int k=0;k<len-len2;k++)
//                 b=b+'0';
//             reverse(b.begin(),b.end());
//         }
//         bool add=0;
//         for(int i=len-1;i>=0;i--)
//         {
//             if(a[i]=='1'&&b[i]=='1')
//             {
//                 if(add)
//                 {
//                     c[i]='1';
//                     add=1;
//                 }
//                 else
//                 {
//                     c[i]='0';
//                     add=1;
//                 }

//             }
//             else if((a[i]=='1'&&b[i]=='0')||(a[i]=='0'&&b[i]=='1'))
//             {
//                 if(add)
//                 {
//                     c[i]='0';
//                     add=1;
//                 }
//                 else
//                 {
//                     c[i]='1';
//                     add=0;
//                 }
//             }
//             else if((a[i]=='0'&&b[i]=='0'))
//             {
//                 if(add)
//                 {
//                     c[i]='1';
//                     add=0;
//                 }
//                 else
//                     c[i]='0';
//             }
//         }
//         if(add)
//         {
//             reverse(c.begin(),c.end());
//             c=c+'1';
//             reverse(c.begin(),c.end());
//         }
//         return c;
            
            
        string result;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry > 0)//从后往前加，i<0时候valueA就为0
        {
            int valueA = i < 0 ? 0 : a[i--] - '0';
            int valueB = j < 0 ? 0 : b[j--] - '0';
            int sum = valueA + valueB + carry;
            result.insert(result.begin(), (sum % 2) + '0');//往头部插入sum和
            carry = sum / 2;//进位
        }
        return result;
    }
};