#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool flag=false;
void swap(vector<string> &vecStr, int s, int i) {
    string tmp;
    tmp=vecStr[i];
    vecStr[i]=vecStr[s];
    vecStr[s]=tmp;
}
void fun(vector<string> &vecStr, int n, int k) {
    if (k == n) {
        string last="";
        last=vecStr[vecStr.size()-1];
        if(vecStr[0][0]==last[last.size()-1]){

            flag = true;
            return;
        }
    }
    for (int i = k; i < n; ++i) {
        //k!=0，之前的0-k-1个字符串已经排好序，则判断k-1号字符串与之后的字符串
        if (k > 0) {
            char a=vecStr[k-1][vecStr[k-1].size()-1];
            char b=vecStr[i][0];
            if(a==b){
                swap(vecStr, k, i);
                fun(vecStr, n, k+1);
                swap(vecStr, k, i);
            }
        }
        else if ( k==0 ) {  //k=0，即第一个字符串与所有的字符串判断
            swap(vecStr, k, i);
            fun(vecStr, n, k+1);
            swap(vecStr, k, i);
        }
    }
    return;
}


int main() {
    vector<string> vecStr;
    string tmp;
    while(cin>>tmp)
        vecStr.push_back(tmp);
    int num=vecStr.size();
    fun(vecStr, num, 0);
    if(flag==true)
        cout << "true" << endl;
    else
        cout<<"false"<<endl;

    return 0;
}


