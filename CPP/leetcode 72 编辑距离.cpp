#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int cols=word1.size()+1;
        int rows=word2.size()+1;
        int dp[rows][cols];

        //initialize
        for(int i=1;i<rows;i++)
            for(int j=1;j<cols;j++)
                dp[i][j]=0;
        for(int i=0;i<cols;i++)
            dp[0][i]=i;
        for(int j=0;j<rows;j++)
            dp[j][0]=j;

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){

                if(word1[j-1]==word2[i-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
            }
        }
//        for(int i=1;i<=rows;i++){
//            for(int j=1;j<=cols;j++){
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        return dp[rows-1][cols-1];
    }
};
int main(){
    string s1="intention";
    string s2="execution";
    Solution s;
    int res=s.minDistance(s1,s2);
    cout<<res<<endl;
}
