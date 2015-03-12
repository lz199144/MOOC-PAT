#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student{
	int num;
	int d;
	int c;
	bool operator < (const Student &A) const{
		if (d + c != A.d + A.c)
			return d + c > A.d + A.c;
		else{
			if (d != A.d)
				return d > A.d;
			else
				return num < A.num;
		}
	}
};

int main(){
	int n, l, h,count = 0;
	Student tmp;
	vector<Student> v1, v2, v3, v4;
	scanf("%d%d%d", &n, &l, &h);
	int x, y, z;
	for (int i = 0; i < n; i++){
		scanf("%d%d%d", &x, &y, &z);
		tmp.num = x;
		tmp.d = y;
		tmp.c = z;
		if (y >= l && z >= l){
			count++;
			if (y >= h && z >= h){
				v1.push_back(tmp);
			}
			else if (y >= h && z < h){
				v2.push_back(tmp);
			}
			else if (y < h && z < h && y >= z){
				v3.push_back(tmp);
			}
			else {
				v4.push_back(tmp);
 			}
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	sort(v4.begin(), v4.end());
	cout << count << endl;
	vector<Student>::iterator itr;
	for (itr = v1.begin(); itr != v1.end(); ++itr)
		printf("%d %d %d\n", itr->num, itr->d, itr->c);
	for (itr = v2.begin(); itr != v2.end(); ++itr)
		printf("%d %d %d\n", itr->num, itr->d, itr->c);
	for (itr = v3.begin(); itr != v3.end(); ++itr)
		printf("%d %d %d\n", itr->num, itr->d, itr->c);
	for (itr = v4.begin(); itr != v4.end(); ++itr)
		printf("%d %d %d\n", itr->num, itr->d, itr->c);
	return 0;
}