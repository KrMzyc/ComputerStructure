#include <bits/stdc++.h>
#include <vector>
#define MAX_CAP 30
using namespace std;
struct Device            //设备定义
{
    int actCap;         //设备容量
    string data;         //内容
};

struct ChannelMannager      //通道处理机
{
    int interrupt;
};

enum state{NONE,INIT,FINISH};

vector <Device> vd(3);        //设备数组

int MaxCap(vector<string> str)        //寻找最大容量
{
    int res=0;
    for (int i=0; i<str.size(); i++)
        if(str[i].size()>=res) res=str[i].size();
    return res;
}

void printdata(int i, vector<Device> a)          //打印设备内容
{
    cout<<"设备号"<<i<<"内容："<<a[i].data;
}

void delay()
{
    int i;
    int r=rand()%500+500;
    for (i=0; i<r; i++);
}

void run(ChannelMannager cm)       //CPU不同的中断算法
{
    while(true)
    {
        if(cm.interrupt==NONE)
        {
            cout<<"The cpu is doing some thing..."<<endl;
            cout<<"The cpu is doing some thing..."<<endl;
            break;
        }

        if(cm.interrupt==INIT)
        {
            cout<<"CPU is interrupted"<<endl;
            cout<<"This is a I/0 Init instruction,The channalManager is init the device..."<<endl;
            break;
        }

        if(cm.interrupt==FINISH)
        {
            cout<<"CPU is interrupted"<<endl;
            cout<<"This is a I/0 Finish instruction,The channalManager is close the device..."<<endl;
            break;
        }
    }
}

void MemoryToDevice(vector<string> memo, int MaxLen, vector<Device> a, ChannelMannager cm)
{
    cm.interrupt=INIT;
    run(cm);
    for (int i=0; i<MaxLen; i++)
    {
        for (int j=0; j<a.size(); j++)
        {
            if(i<memo[j].size() && i<a[j].actCap) a[j].data+=memo[j][i];
            for (int k=0; k<a.size(); k++)
            {
                cout<<"Device"<<k<<" Content: "<<a[k].data<<endl;
            }
            cout<<endl;
        }

    }

    cm.interrupt=FINISH;
    run(cm);
}




int main()
{
    cout<<"------------Demo the work flow of channel----------- "<<endl;
    vector<string> memory(3);
    memory[0]="Computer";
    memory[1]="Structure";
    memory[2]="Channel";

    ChannelMannager cm;
    cm.interrupt=NONE;
    run(cm);
    for (int i=0; i<vd.size(); i++)
    {
        vd[i].data="";        //设备内容初始化为空
        vd[i].actCap=(rand()%10+50);
    }



    int MaxDevCap= MaxCap(memory);
    delay();
    MemoryToDevice(memory,MaxDevCap,vd,cm);

//    for (int i=0; i<vd.size(); i++)
//        cout<<vd[i].data<<endl;
    return 0;
}