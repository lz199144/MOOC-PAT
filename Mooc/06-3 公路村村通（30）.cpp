#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1000+50
#define MAXV 3000+50
using namespace std;
struct edge{
    int from, to, weight;
};
edge arr[MAXV];
int n, m;
bool cmp(const edge &a, const edge &b){
    return a.weight < b.weight;
}
int fa[MAXN];
int find(int x){
    if(fa[x] == x){
        return x;
    }
    else{
        return fa[x] = find(fa[x]);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &arr[i].from, &arr[i].to, &arr[i].weight);
    }
    sort(arr, arr+m, cmp);
    for(int i = 1; i <= n; ++i){
        fa[i] = i;
    }
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < m; ++i){
        edge tmp = arr[i];
        int a = find(tmp.from);
        int b = find(tmp.to);
        if(a != b){
            res += tmp.weight;
            fa[a] = b;
            cnt++;
        }
    }
    if(cnt < n-1){
        printf("-1\n");
    }
    else{
        printf("%d\n", res);
    }
    return 0;
}
