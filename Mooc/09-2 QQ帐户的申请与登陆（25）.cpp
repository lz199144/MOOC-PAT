#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	map<long int, string>mapQQ;		//创建一个map容器
	char choose;					//需要进行的操作
	long int qq_number;				
	string qq_password;
	map<long int, string>::iterator iter;   //前向迭代器
	for (int i = 0; i < N; i++){
		cin >> choose >> qq_number >> qq_password;			//输入
		iter = mapQQ.find(qq_number);				//对qq_number进行查找
		if (choose == 'N'){		
			if (iter != mapQQ.end()){
				cout << "ERROR: Exist\n";			//容器中已有这个号码
			}
			else{
				mapQQ[qq_number] = qq_password;		//创建这个号码
				cout << "New: OK\n";
			}
		}
		else if (choose == 'L'){
			if (iter != mapQQ.end()){
				string s = mapQQ[qq_number];		
				if (s==qq_password){				//判断qq与密码是否匹配
					cout << "Login: OK\n";
				}
				else{
					cout << "ERROR: Wrong PW\n";
				}				
			}
			else{
				cout << "ERROR: Not Exist\n";		//没找到，不存在
			}
		}
	}

	return 0;
}
