//思路：先计数空格数，从后往前替换
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count=0;
        for(int i=0;i<length;i++){
            if(str[i]==' ')
                count++;
        }
        for(int i=length-1;i>=0;i--){
            if(str[i]!=' ')//不是空格就往后移动多空格*2的位置
            {
                str[i+2*count]=str[i];
            }
            else{
                count--;
                str[i+2*count]='%';
                str[i+2*count+1]='2';
                str[i+2*count+2]='0';
            }
        }
	}
};
