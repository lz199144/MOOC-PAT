#include<cstdio>
#include<cstdlib>
using namespace std;
int arr[100][2];
int list[100] = { 0 };
int result[100] = { -1 };
int count = 0;
struct TreeNode//���ڵ�
{
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
};

typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;

Tree Build(int x, Tree &t)//�������齨��
{
  
  if (x == -1)
  {
    t  = NULL;
  }
  else
  {
    t = (Tree)malloc(sizeof(TreeNode));
    t->data = x;
    Build(arr[x][0], t->left);
    Build(arr[x][1], t->right);
  }
  return t;
}

struct QueueNode//���нڵ�
{
  Tree data;
  struct QueueNode* next;
};

typedef struct QueueNode* Queue;

void push(Tree d, Queue q)//���
{
  while (q->next != NULL)
  {
    q = q->next;
  }
  Queue qt = (Queue)malloc(sizeof(struct QueueNode));
  qt->data = d;
  q->next = qt;
  qt->next = NULL;
}

void pop(Queue q)//����
{
  Queue first = q->next;
  q->next = first->next;
  free(first);
}

Tree top(Queue q)//�鿴���е�һ��Ԫ��
{
  return q->next->data;
}

void view(Tree bt)//������� �������Ҷ��Ӷ���NULL�Ĵ�ӡ
{
  QueueNode qt;
  Queue q = &qt;
  q->next = NULL;
  Tree t;
  if (!bt)
    return;
  push(bt, q);
  while (q->next != NULL)
  {
    t = top(q);
    pop(q);
    if (t->left == NULL&&t->right == NULL)
    {
      result[count] = t->data;
      count++;
    }
    if (t->left)
      push(t->left, q);
    if (t->right)
      push(t->right, q);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++)//������������������ ��������-1��ʾ
  {
    char str1[3], str2[3];
    int l, r;
    scanf("%s%s", str1, str2);
    if (l = atoi(str1))
    {
      arr[i][0] = l;
      list[l]++;
    }
    else if (str1[0] == '0')
    {
      l = 0;
      arr[i][0] = l;
      list[l]++;
    }
    else
    {
      arr[i][0] = -1;
    }
    if (r = atoi(str2))
    {
      arr[i][1] = r;
      list[r]++;
    }
    else if (str2[0] == '0')
    {
      r = 0;
      arr[i][1] = r;
      list[r]++;
    }
    else
    {
      arr[i][1] = -1;
    }
  }
  for (i = 0; i < n; i++)//û�г��ֵ����ּ�Ϊ���ڵ�
  {
    if (list[i] == 0)
      break;
  }
  struct TreeNode t;
  Tree bt;
  bt = Build(i, bt);
  view(bt);
  for (i = 0; i < count; i++)
  {
    if (i == count - 1)
      printf("%d\n", result[i]);
    else
      printf("%d ", result[i]);
  }
}