#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//做一次从from到to的字符交换
void ReverseString(string &str,int from,int to) {
    while (from < to) {
        char c = str.at(from);
        str.at(from) = str.at(to);
        str.at(to) = c;
        from++;
        to--;
    }
}

//字符串str左移m位
void LeftRotationStr(string &str, int m) {
    int n = str.length();
    m %= n;
    ReverseString(str,0, m - 1);
    ReverseString(str, m, n - 1);
    ReverseString(str, 0, n - 1);
}
int main()
{
    vector<string> vec;
    string s;
    while(getline(cin,s))
    {
        if(s.size()==0)
            break;
        vec.push_back(s);
    }
    int n=vec.size();
    int a[n];
    vector<string> res;
    for(int i=0;i<n;i++)
    {
        int legal=1;
        for(int j=0;j<vec[i].size();j++)
        {
            if((vec[i][j]>='0'&&vec[i][j]<='9')
                    ||(vec[i][j]>='a'&&vec[i][j]<='z')
                    ||(vec[i][j]>='A'&&vec[i][j]<='Z')
                    ||vec[i][j]==' ')
            {
                continue;
            }
            else
                legal=0;
        }
        a[i]=legal;
    }
    vector<string> tmpRes;
    for(int i=0;i<n;i++)
    {
        vec[i].erase(vec[i].find_last_not_of(" ") + 1);
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            tmpRes.push_back(vec[i]);
        }
    }
    for(int i=0;i<tmpRes.size();i++)
    {
        bool jump=false;
        for(int j=0;j<res.size();j++)
        {
            if(res[j]==tmpRes[i])//重复不加入
                jump=true;
        }
        if(!jump)
            res.push_back(tmpRes[i]);
    }



    for(int i=0;i<res.size();i++)//第一次输出
    {
        res[i].erase(res[i].find_last_not_of(" ") + 1);
        cout<<res[i]<<" ";
    }
    cout<<endl;

    vector<string> others;
    for(int i=0;i<n;i++)//非法的输出
    {
        if(a[i]==0)
        {
            string s1=vec[i];
            s1.erase(s1.find_last_not_of(" ") + 1);
            others.push_back(s1);
        }
    }

    for(int i=0;i<others.size();i++)
    {
        cout<<others[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<res.size();i++)//左移10次
    {
        LeftRotationStr(res[i], 10);
    }
    for(int i=0;i<res.size();i++)//左移10次
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)//左移10次
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}


