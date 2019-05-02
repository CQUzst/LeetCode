#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k=0;
    while(n--){
        int t;
        cin>>t;
        int num;
        vector<int> vec;
        while(t--){
            cin>>num;
            vec.push_back(num);
        }
        int maxSum = vec[0];
        int sum = 0, left=0, right=0;
        int tmpLeft = 0;
        for(int i = 0; i < vec.size(); i++){
            sum += vec[i];
            if(sum > maxSum){
                maxSum = sum;
                left = tmpLeft;
                right = i;
            }
            if(sum < 0){
                sum = 0;
                tmpLeft = i+1;
            }
        }
        k++;
        cout<<"Case "<<k<<":"<<endl;
        if(n>0)
            cout<<maxSum<<" "<<left+1<<" "<<right+1<<endl<<endl;
        else
            cout<<maxSum<<" "<<left+1<<" "<<right+1<<endl;
    }
    return 0;
}

