//小Q的机器人
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//收益只与完成的任务x、y有关，且x、y越大，获得的收益越大，所以要优先完成x更大的任务，若x相等，则要优先完成y大的任务。
//为保证上述完成要求，我们可以将任务的x按从大到小排序，若x相同，根据y从大到小排序，排序完成后，再给任务分配机器。
//当有多台机器符合x条件，选择y满足条件的最小的wi

//先按时间从大到小排序，再按难度从大到小排序
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second>b.second;
}

int main(){
    int n,m;//n台机器，m个任务
    cin>>n>>m;
    int machineNum=n,taskNum=m;
    vector<pair<int,int> >machine;
    int zi,wi;//zi工作时间，wi机器等级
    while(n--){
        cin>>zi>>wi;
        machine.push_back(make_pair(zi,wi));
    }
    vector<pair<int,int> >task;
    int xi,yi;//xi任务时间，yi任务等级
    while(m--){
        cin>>xi>>yi;
        task.push_back(make_pair(xi,yi));
    }
    //将任务和机器按时间长短从大到小排序
    sort(task.begin(),task.end(),cmp);
    sort(machine.begin(),machine.end(),cmp);

    long long gain=0;
    int count=0;
    int mark[101]={0};//每个等级对应有多少个机器

    int j = 0;//第j个机器，机器已经排序，按时间从大到小，难度从大到小
    for(int i = 0; i < taskNum; i++){
        //每台机器只能用一次，所以分配下一个任务时，j从上一个任务之后开始考虑，j不用归0
        //由于任务是按从到大小排列的，因此满足上一任务要求的机器一定满足下一任务要求
        while(j<machineNum&&machine[j].first >= task[i].first){
            mark[machine[j].second]++;//表示满足该任务时长下，符合等级要求的可用的机器数+1
            j++;
        }
        for(int k = task[i].second; k <= 100; k++)//从符合等级要求的等级最低的机器开始分配
        {
            if(mark[k]>0)
            {
                mark[k]--;
                count++;
                gain +=(200 * task[i].first + 3 * task[i].second);
                break;
            }
        }
    }
    cout<<count<<" ";
    cout<<gain<<endl;
    return 0;
}
