class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
            return string("0");
        bool flag= (numerator<0)^(denominator<0);//异或处理，异或则为负
        long a= abs((long)numerator),b = abs((long)denominator);
        
        string res,str;
        if(flag) res+='-';
        
        res+=to_string(a/b);//先加整数部分
        long t = a%b;
        long i;
        
        if(t==0)return res;//可以整除直接返回整数结果
        res+='.';//有小数先加上个小数
        
        vector<long> v;
        //v里保存每次的余数，有重复说明无限循环了，如果t=0说明除尽了
        while(t!=0&&find(v.begin(),v.end(),t)==v.end())
        {
            v.push_back(t);
            str+=t*10/b+'0';//按照除法规则，往后借1位接着除
            t = t*10%b;//t更新为余数
            
        }
        i = find(v.begin(),v.end(),t)-v.begin();//找到重复项在小数里的位置
        if(t!=0){
            str.insert(str.begin()+i,'(');
            str+=')';
        }
        
        return res+str;
    }
};
