#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
const int N = 1001;
int main()
{
    int space ;//功能部件数
    int inum ;//需要流水处理的指令数目
    int length ;//存储不同时间段各个功能部件内指令值
    char map[N][N];//时空图

    cout << "-------Demo the pipline for float point add.------" << endl;
    cout << "-------Here, we display all the content in the pipeline------" << endl;
    cout << "请输入功能部件数目： " << endl;
    cin >> space;
    cout << "请输入需要流水处理的指令数目" << endl;
    cin >> inum;

    int cnt = 1;
    char flag = 'n';
    length = inum + space -1;

    for(int i=0; i<space; i++)
    {
        int k;
        for(k=0; k<(space-i-1)*3; k++)
            map[i][k] = ' ';
        --k;
        for(int j=0; j<inum; j++)
        {
            map[i][++k+j] = (char)(65+i);
            map[i][++k+j] = j+1+'0';
        }
    }

    while(cnt <=length && flag == 'n')
    {
        //output the cnt-th slice
        for(int i=0; i<space; i++)
        {
            for(int j=0; j<cnt*3; j++)
                cout << map[i][j];
            cout << endl;
        }

        cout << "Input next time slices"<<cnt<< "(y/n)" << endl;  //如果想要看到完整的流水线过程请一直按’n‘
        cnt++;
        cin >> flag;
        cout << endl;
    }

    cout << "The task has been finished" << endl;
    cout << endl;
    cout << "The Though Put of the pipeline is " << inum/(length*1.0) << "Δt" << endl;
    cout << "The Speedup is of the pipeline is " << (inum*space)/(length*1.0) << endl;
    cout << "The Efficiency of the pipeline is " << (inum*space)/(space*length*1.0) << endl;

    getch();
    return 0;
}
