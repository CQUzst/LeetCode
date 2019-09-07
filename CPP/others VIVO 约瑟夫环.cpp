//约瑟夫环是一个数学应用题：
//已知n个人（编号1、2、..n）围坐在一张圆桌周围。
//从编号为1的人开始报数，数到m的那个人出列；他的下一个又从1开始报数，
//数到m的那个人又出列；依次规律重复下去，直到圆桌周围的人全部出列。
//请编写一个程序，给定n、m计算出列人员先后顺序。
#include <iostream>
using namespace std;
struct Listnode
{
    int data;
    Listnode* next;
    Listnode(int a){
        data = a;
        next = nullptr;
    }
};
Listnode* create(int size){//生成1-n的环形链表
    Listnode* head = new Listnode(1);
    Listnode* p = head;
    for (int i = 0; i < size - 1; i++){
        p->next = new Listnode(i + 2);
        p = p->next;
    }
    p->next = head;
    return head;
}
//递归 将上一次处理的结果当做下一次处理的输入,约瑟夫环
Listnode* JosephRing(Listnode* begin, int m){
    if (begin == begin->next){//最后一个值，自身成环，直接输出
        cout << begin->data << endl;
        return begin;
    }
    Listnode* p = begin;
    Listnode* pre=begin;
    for (int i = 0; i < m - 1; i++){//后移m-1位
        pre=p;
        p = p->next;
    }
    cout << p->data <<" ";//输出指定位
    pre->next=p->next;//跳过当前位

    return JosephRing(pre->next, m);
}

int main()
{
    Listnode *head = create(10);
    JosephRing(head, 3);

    return 0;
}
