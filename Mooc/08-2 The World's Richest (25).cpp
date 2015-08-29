#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

//此代码使用前，需删除下面两行+后面的system("PAUSE")
ifstream fin("in.txt");
#define cin fin

struct Person{
	char name[9];
	int age;
	int worth;
}*p;

bool resCmp(const Person& a,const Person& b){
	if(a.worth == b.worth){
		if(a.age == b.age){
			if(strcmp(a.name,b.name)>0)
				return false;
			else 
				return true;
		}else{
			return a.age < b.age;
		}
	}else{
		return a.worth > b.worth;
	}
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	//cin>>n>>k;
	p = new Person[n];
	int i,j,z;
	for(i=0;i<n;i++){
		scanf("%s %d %d",p[i].name,&p[i].age,&p[i].worth);
		//cin>>p[i].name>>p[i].age>>p[i].worth;
	}
	sort(p,p+n,resCmp);
	int ageCount[201]={0};
	int *filter = new int[n];
	int filter_num = 0;
	for(i=0;i<n;i++){
		if(++ageCount[p[i].age] < 101){
			filter[filter_num++] = i;
		}
	}
	int count;
	int m,amin,amax;
	bool flag;
	int unfilter;
	for(i=0;i<k;i++){
		scanf("%d %d %d",&m,&amin,&amax);
		//cin>>m>>amin>>amax;
		count = 0;
		flag = true;
		printf("Case #%d:\n",i+1);
		for(j=0;j<filter_num;j++){
			unfilter = filter[j];
			if(p[unfilter].age >= amin && p[unfilter].age<= amax){
				printf("%s %d %d\n",p[unfilter].name,p[unfilter].age,p[unfilter].worth);
				flag = false;
				count ++;
				if(count >= m){break;}
			}
		}
		if(flag)printf("None\n");
	}
	system( "PAUSE");
	return 0;
}