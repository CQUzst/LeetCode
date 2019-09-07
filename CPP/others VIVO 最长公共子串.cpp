#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define maxSize 100
int dp[maxSize][maxSize]={0};

int maxSubLength(string s1,string s2)
{
    //方便操作
    int maxLength=-1,start=0;
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(maxLength<dp[i][j]){
                    maxLength=dp[i][j];
                    start=i;
                }
            }
            else
                dp[i][j]=0;
        }
    }
    string res=s1.substr(start-maxLength+1,maxLength);
    cout<<res<<endl;
    return maxLength;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<maxSubLength(s1,s2)<<endl;

    return 0;
}
