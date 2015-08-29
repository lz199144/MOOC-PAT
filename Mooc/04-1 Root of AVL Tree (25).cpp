#include <cstdio>
#include <iostream>

using namespace std;

struct TreeNode
{
  int data;
  TreeNode* left;
  TreeNode* right;
  int height;
  TreeNode(int v):data(v),left(NULL),right(NULL),height(0){}
};
int GetHeight(TreeNode* T)
{
  if(T==NULL)
    return -1;
  return T->height;
}
TreeNode* Rotation_LL(TreeNode* A)
{
  TreeNode *B=A->left;
  A->left=B->right;
  B->right=A;
  A->height=max(GetHeight(A->left),GetHeight(A->right))+1;
  B->height=max(GetHeight(B->left),GetHeight(B->right))+1;
  return B;
}
TreeNode* Rotation_RR(TreeNode* A)
{
  TreeNode *B=A->right;
  A->right=B->left;
  B->left=A;
  A->height=max(GetHeight(A->left),GetHeight(A->right))+1;
  B->height=max(GetHeight(B->left),GetHeight(B->right))+1;
  return B;
}
TreeNode* Rotation_LR(TreeNode* A)
{
  A->left=Rotation_RR(A->left);
  return Rotation_LL(A);
}
TreeNode* Rotation_RL(TreeNode* A)
{
  A->right=Rotation_LL(A->right);
  return Rotation_RR(A);
}
bool isBalanced(TreeNode* A)
{
  return abs(GetHeight(A->left)-GetHeight(A->right))<2;
}
TreeNode* insert_Node(int data,TreeNode* T)
{
  if(T!=NULL)  
    {  
        if(data>T->data)
        {  
      T->right = insert_Node(data,T->right);  
      if(!isBalanced(T))  
            {  
                if(data>T->right->data)
                    T = Rotation_RR(T);  
                else 
                    T = Rotation_RL(T);   
            }  
        }else
        {  
            T->left = insert_Node(data,T->left);  
            if(!isBalanced(T))  
            {  
                if(data>T->left->data)
                    T=Rotation_LR(T);  
                else 
                    T=Rotation_LL(T);  
            }  
        }  
    }else  
        T = new TreeNode(data);  
    T->height = max(GetHeight(T->left),GetHeight(T->right)) + 1;  
    return T;  
}

int main()
{
  TreeNode *root=NULL;
  int n;
  cin>>n;
  int data;
  for(int i=0;i<n;i++)
  {
    cin>>data;
    root=insert_Node(data,root);
  }
  cout<<root->data<<endl;
  return 0;
}