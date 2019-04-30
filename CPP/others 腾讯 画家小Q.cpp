//画家小Q
//【题目描述】画家小 Q 又开始他的艺术创作。小 Q 拿出了一块有 NxM 像素格的画板, 画板初始状态是空白
//的,用’X’表示。
//小 Q 有他独特的绘画技巧,每次小 Q 会选择一条斜线, 如果斜线的方向形如’/’,即斜率为 1,小 Q 会选择这
//条斜线中的一段格子,都涂画为蓝色,用’B’表示;如果对角线的方向形如’\’,即斜率为-1,小 Q 会选择这条
//斜线中的一段格子,都涂画为黄色,用’Y’表示。
//如果一个格子既被蓝色涂画过又被黄色涂画过,那么这个格子就会变成绿色,用’G’表示。
//小 Q 已经有想画出的作品的样子, 请你帮他计算一下他最少需要多少次操作完成这幅画。
//输入描述：
//每个输入包含一个测试用例。
//每个测试用例的第一行包含两个正整数 N 和 M(1 <= N, M <= 50), 表示画板的长宽。
//接下来的 N 行包含 N 个长度为 M 的字符串, 其中包含字符’B’,’Y’,’G’,’X’,分别表示蓝色,黄色,绿色,空
//白。整个表示小 Q 要完成的作品。
//输出描述：
//输出一个正整数, 表示小 Q 最少需要多少次操作完成绘画。
//输入示例：
//4 4
//YXXB
//XYGX
//XBYY
//BXXY
//输出示例：
//3

//解题思路:
//从(0,0)位置开始遍历

//    如果遍历到(i,j)位置为B——>则继续向左下方(i+1,j-1)和右上方(i-1,j+1)
//    遍历时，遇到将B置为X，遇到G置为（消除B）置为Y
//    count++;
//    如果遍历到(i,j)位置为Y——>则继续向左上方(i-1,j-1)和右下方(i+1,j+1)
//    遍历时，遇到将Y置为X，遇到G置为（消除Y）置为B
//    count++;
//    如果遍历到(i,j)位置为G——>则分别执行1,2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs_B(vector<vector<char> >&paint,int i,int j){
    if(i>=0&&i<paint.size()&&j>=0&&j<paint[0].size()&&(paint[i][j]=='B'||paint[i][j]=='G')){
        if(paint[i][j]=='B')
            paint[i][j]='X';
        else if(paint[i][j]=='G')
            paint[i][j]='Y';
        dfs_B(paint,i+1,j-1);
        dfs_B(paint,i-1,j+1);
    }
    return;
}
void dfs_Y(vector<vector<char> >&paint,int i,int j){
    if(i>=0&&i<paint.size()&&j>=0&&j<paint[0].size()&&(paint[i][j]=='Y'||paint[i][j]=='G')){
        if(paint[i][j]=='Y')
            paint[i][j]='X';
        else if(paint[i][j]=='G')
            paint[i][j]='B';
        dfs_Y(paint,i+1,j+1);
        dfs_Y(paint,i-1,j-1);
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> >paint;
    char c;
    for(int i=0;i<n;i++){
        vector<char> row;
        for(int j=0;j<m;j++){
            cin>>c;
            row.push_back(c);
        }
        paint.push_back(row);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(paint[i][j]=='B'){
                dfs_B(paint,i,j);
                count++;
            }
            else if(paint[i][j]=='Y'){
                dfs_Y(paint,i,j);
                count++;
            }
            else if(paint[i][j]=='G'){
                dfs_B(paint,i,j);
                count++;
                dfs_Y(paint,i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
