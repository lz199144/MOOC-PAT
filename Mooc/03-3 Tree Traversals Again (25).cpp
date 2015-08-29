#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

char op[10];
int val,n,iter=0;
bool flag;

struct TreeNode{
	int num;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int num):num(num),left(NULL),right(NULL){}
	~TreeNode();
};

TreeNode* buildTree(){
	if(iter>=n)
		return NULL;
	scanf("%s",op);
	TreeNode *root=NULL;
	if(op[1]=='u'){
		scanf("%d",&val);
		root=new TreeNode(val);
		++iter;
		root->left=buildTree();
		++iter;
		root->right=buildTree();
	}
	return root;
}

void DFS(TreeNode *root){
	if(root==NULL)
		return;
	DFS(root->left);
	DFS(root->right);
	if(flag){
		printf("%d",root->num);
		flag=false;
	}else{
		printf(" %d",root->num);
	}
}

int main(int argc,char *argv[]){
	scanf("%d",&n);
	n=n*2;
	TreeNode *root=buildTree();
	flag=true;
	DFS(root);
	printf("\n");
	return 0;
}