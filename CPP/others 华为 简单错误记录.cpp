#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<string,int> a,pair<string,int> b){
    return a.second>b.second;
}
int main(){
    string input,file;
    vector <pair<string,int> >res;
    while(getline(cin,input)){
        if(input.size()==0){
            break;
        }
        unsigned int r=input.rfind('\\');
        file=input.substr(r+1);
        res.push_back(make_pair(file,1));
        for(int i=0;i<res.size()-1;i++){
            if(res[i].first==file){
                res[i].second++;
                res.pop_back();
                break;
            }
        }
    }
    stable_sort(res.begin(),res.end(),compare);
    int idx = 0;
    while (idx<8 && idx<res.size()){
        string check = res[idx].first;
        int t = check.find(' ');
        if (t>16)
            res[idx].first.erase(0, t - 16);
        cout << res[idx].first << ' ' << res[idx].second << endl;
        idx++;
    }
}
