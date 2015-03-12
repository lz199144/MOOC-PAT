#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>

using namespace std;

// 用PAIR来代替pair<char, string>
typedef pair<char, string> PAIR;

// cmp函数决定是从小到大排，还是从大到小排
// 还有按什么内容排，这里是按编码的长度排序
int cmp(const PAIR& x, const PAIR& y)
{
    return x.second.size() < y.second.size();
}

int main()
{
    int num;
    cin >> num;
    char *c = new char[num];
    int *f = new int[num];
    map<char, int> myMap;
    // 使用优先级队列模拟“堆”
    priority_queue<int,vector<int>,greater<int>> pq;
    // 输入结点及出现次数
    for (int i = 0; i<num; i++)
    {
        cin >> c[i] >> f[i];
        myMap[c[i]] = f[i];
        // 向队列中添加元素
        pq.push(f[i]);
    }
    // 计算WPL的值
    int myWpl = 0;
    while (!pq.empty())
    {
        int myTop = pq.top();
        pq.pop();
        if (!pq.empty())
        {
            int myTop2 = pq.top();
            pq.pop();
            pq.push(myTop + myTop2);
            int m = myTop + myTop2;
            myWpl += m;
        }
    }
    // 输入测试数据
    int checkNum;
    cin >> checkNum;
    for (int i = 0; i<checkNum; i++)
    {
        int wpl = 0;
        char ch;
        string s;
        // vector的定义
        vector<PAIR> checkVec;
        for (int j = 0; j<num; j++)
        {
            cin >> ch >> s;
            // 向vector中添加元素
            checkVec.push_back(make_pair(ch, s));
            wpl += s.size() * myMap[ch];
        }
        // 按照编码的长度排序
        sort(checkVec.begin(), checkVec.end(), cmp);
        if (wpl != myWpl)
        {
            cout << "No" << endl;
            continue;
        }
        else
        {
            bool flag = true;

            for (int i = 0; i<num; i++)
            {
                string tmp = checkVec[i].second;
                for (int j = i + 1; j<num; j++)
                {
                    if (checkVec[j].second.substr(0, tmp.size()) == tmp)
                        flag = false;
                }
            }

            if (flag == true)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}