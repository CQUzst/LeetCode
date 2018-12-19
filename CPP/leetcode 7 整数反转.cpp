class Solution {
public:
    int reverse(int x)
    {
        
        long result = 0;
        if(x>0)
        {
            while (x>0)  
            {  
                result = result*10 + x%10;  
                x/=10;
            } 
            if (result > INT_MAX)//溢出检查
            {    
                return 0;  
            } 
            else
                return result;

        }
        else if(x==0)
            return result;
        else
        {
            while (x<0)  
            {  
                result = result*10 + x%10;  
                x/=10;
            } 
            if (result < INT_MIN)//溢出检查
            {    
                return 0;  
            } 
            else
                return result;


        }

    }
};