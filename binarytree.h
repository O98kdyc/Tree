#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include<iostream>
#include "linkQueue.h"
#include "seqList.h"
#include <fstream>
#include "seqStack.h"
using namespace std;

template <class Type>
class BinaryTree {
private:
     struct Node {
          Node  *left , *right ; 		// 结点的左、右儿子的地址
          Type data;  			        // 结点的数据信息
   	  Node() : left(NULL), right(NULL) { }
  	  Node(Type item, Node *L = NULL, Node *R =NULL ): data(item), left(L), right(R) {}
	   ~Node() {}
      };

  	Node *root; 		// 二叉树的根结点。

  	struct StNode
  	{
  	    Node *node;
  	    int TimesPop;

  	    StNode(Node *N=NULL):node(N),TimesPop(0){}
  	};
public:
	BinaryTree() : root( NULL) {}  	// 构造空二叉树
	BinaryTree(const Type  & value )
                 { root = new Node(value); }
	~BinaryTree()  { clear(); }
	/*void makeTree(const Type &x, BinaryTree &lt,BinaryTree &rt)
     {
        root = new Node( x, lt,  rt);
        lt = NULL; rt = NULL;
     }*/

    void createTree(Type flag);  	 // 建二叉树
    void createTree(char *filename,Type flag);
    void createTreeFromPreMid(Type *pre,Type *mid);
    Type getRoot() const {return root->data;}
    Type getLeft() const  {return root->left->data;}
    Type getRight() const {return root->right->data;}

    bool isEmpty () const  { return root == NULL; }

   int size() const { return size(root);}
   int height() const { return height(root); }

   void preOrder()  const;
   void preorder() const;
   void midOrder() const;
   void midorder() const;
   void postOrder()  const;
   void postorder() const;
   void levelOrder() const;
   bool checkComplete() const;
   bool checkFull() const;
   int count2Degree() const;
   void Switch();
   void clear()
  { if (root != NULL)
	     clear(root);    //调用私有成员变量
	 root = NULL;
  }
   void delLeft()
  { BinaryTree tmp = root->left;
     root->left = NULL;
     tmp.clear();   	//调用公有的clear ( )操作
  }
   void delRight()
  { BinaryTree tmp = root->right;
      root->right = NULL;
      tmp.clear();	  //调用公有的clear ( )操作
  }
private:
    void clear( Node *t );
    int height( Node *t ) const;
    int size( Node *t ) const;
    void preOrder( Node *t )  const;
    void midOrder( Node *t ) const;
    void postOrder( Node *t )  const;
    void Switch(Node *t);
    void createTreeFromPreMid(Type *pre,Type *mid,Node *t);
 };

template <class Type>
int BinaryTree<Type>::size(Node *t) const  //私有成员函数
 { if (t == NULL) return 0;
   return 1 + size(t->left) + size(t->right);
 }

template <class Type>
int BinaryTree<Type>::height(Node *t) const 	//私有成员函数
{ if (t == NULL) return 0;
  else {  int lt = height(t->left), rt = height(t->right);
	   return 1 + ( (lt > rt) ? lt : rt);
	}
}

template <class Type>
void BinaryTree<Type>::preOrder()  const		 //公有成员函数
 { if (root != NULL)
     {
         /*cout << "\n前序遍历：";*/  preOrder(root);
     }
 }
 template <class Type>
 void BinaryTree<Type>::preOrder(Node *t)  const   //私有成员函数
  { if (t != NULL)
	{  //cout << t->data << ' ';
	    t->data;
  	   preOrder(t->left);
	   preOrder(t->right);
	}
 }
template <class Type>
 void BinaryTree<Type>::midOrder() const 		//公有成员函数
 { if (root != NULL)
     {
	  //cout << "\n中序遍历：";
           midOrder(root);
      }
  }
template <class Type>
void BinaryTree<Type>::midOrder(Node *t) const   //私有成员函数
{ if (t != NULL)
     {  midOrder(t->left);
	//cout << t->data << ' ';
	    t->data;
        midOrder(t->right);
     }
 }
template <class Type>
 void BinaryTree<Type>::postOrder()  const		 //公有成员函数
 { if (root != NULL)
    { //cout << "\n后序遍历：";
      postOrder(root);
    }
 }
template <class Type>
void BinaryTree<Type>::postOrder(Node *t)  const 	//私有成员函数
 { if (t != NULL)
     {  postOrder(t->left);
        postOrder(t->right);
        //cout << t->data << ' ';
        t->data;
     }
 }

template <class Type>
 void BinaryTree<Type>::clear(Node *t) 	 //私有成员函数
{  if (t->left != NULL) clear(t->left);
   if (t->right != NULL) clear(t->right);
   delete t;
 }

template <class Type>
void BinaryTree<Type>::createTree(Type flag)
{
  linkQueue<Node *> que;
  Node *tmp;
  Type x, ldata, rdata;

  //创建树，输入flag表示空
  cout << "\n输入根结点：";
  cin >> x;
  root = new Node(x);
  que.enQueue(root);
  while (!que.isEmpty()) {
	tmp = que.deQueue();
	cout << "\n输入" << tmp->data
            << "的两个儿子(" << flag
            << "表示空结点)：";
    cin >> ldata >> rdata;
	if (ldata != flag)
        que.enQueue(tmp->left = new Node(ldata));
	if (rdata != flag)
       que.enQueue(tmp->right = new Node(rdata));
}
cout << "create completed!\n";
}
template <class Type>
void BinaryTree<Type>::createTreeFromPreMid(Type *pre,Type *mid,Node *t)
{
   int len;
   for(len=0;pre[len]!='\0';){len+=1;}

   //cout<<len<<" ";
   Type v1[len],v2[len];

   for(int i=0;i<len;++i) {v1[i]=pre[i];/*cout<<v1[i];*/}
   v1[len]='\0';
   //cout<<v1<<" ";
   for(int i=0;i<len;++i) {v2[i]=mid[i];/*cout<<v2[i];*/}
   v2[len]='\0';
   //cout<<v2<<" ";

   //t=new Node(v1[0]);
   //cout<<t->data<<" ";
   if(len==0) return;

   int pos;
   for(pos=0;v2[pos]!=v1[0];++pos){};
   //cout<<pos<<endl;

   Type v3[pos],v4[pos];
   for(int i=0;i<pos;i++) v3[i]=v2[i];
   v3[pos]='\0';
   for(int i=0;i<pos;i++) v4[i]=v1[i+1];
   v4[pos]='\0';
   t->left=new Node(v4[0]);
   createTreeFromPreMid(v4,v3,t->left);
   Type v5[len-pos],v6[len-pos];
   for(int i=pos;i<len;i++) v5[i-pos]=mid[i+1];
   for(int i=pos;i<len;i++) v6[i-pos]=pre[i+1];
   t->right=new Node(v6[0]);
   createTreeFromPreMid(v6,v5,t->right);
}
template <class Type>
void BinaryTree<Type>::createTree(char *filename,Type flag)
{
   ifstream fin(filename);
   linkQueue <Node*> que;
   Node *tmp;
   Type x, ldata, rdata;
   if(!fin) {cout<<"cannot open input file\n";return;}
   fin>>x;
   root = new Node(x);
   que.enQueue(root);
   while (!que.isEmpty())
    {
	tmp = que.deQueue();
    fin >> ldata >> rdata;
	if (ldata != flag)
        que.enQueue(tmp->left = new Node(ldata));
	if (rdata != flag)
       que.enQueue(tmp->right = new Node(rdata));
    }
}

template <class Type>
void BinaryTree<Type>::createTreeFromPreMid(Type *pre,Type *mid)
{
    root=new Node(pre[0]);
    createTreeFromPreMid(pre,mid,root);
}
template<class Type>
void BinaryTree<Type>::levelOrder () const
{
    linkQueue<Node*> que;
    Node *tmp;
    cout<<"\n层次遍历:";
    que.enQueue(root);
    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        cout<<tmp->data<<' ';
        if(tmp->left) que.enQueue(tmp->left);
        if(tmp->right) que.enQueue(tmp->right);
    }
}
template<class Type>
bool BinaryTree<Type>::checkComplete() const
{
    int m=0;
    linkQueue<Node*> que;
    Node *tmp;
    que.enQueue(root);
    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        if(m==1&&(tmp->left||tmp->right)) return false;
        if(tmp->left) que.enQueue(tmp->left);
            else m=1;
        if(tmp->right) que.enQueue(tmp->right);
            else m=1;
    }
    return true;
}
template<class Type>
bool BinaryTree<Type>::checkFull() const
{
    int s=1;
    for(int i=0;i<height(root);i++) s*=2;
    if(size(root)==(s-1)) return true;
    else return false;
}
template<class Type>
int BinaryTree<Type>::count2Degree() const
{
    int count=0;
    linkQueue<Node*> que;
    Node *tmp;
    que.enQueue(root);
    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        if(tmp->left&&tmp->right) count+=1;
        if(tmp->left) que.enQueue(tmp->left);
        if(tmp->right) que.enQueue(tmp->right);
    }
    return count;
}
template<class Type>
void BinaryTree<Type>::Switch()
{
    Switch(root);
}
template<class Type>
void BinaryTree<Type>::Switch(Node *t)
{
    if(t==NULL) return;
    Node *tmp=t->left;
    t->left=t->right;
    t->right=tmp;
    Switch(t->left);
    Switch(t->right);
}

template<class Type>
void BinaryTree<Type>::preorder()const
{
    //cout<<"\n前序遍历:"<<endl;
    seqStack<Node*> s;
    Node *current;
    s.push(root);
    while(!s.isEmpty())
    {
        current = s.pop();
        //cout << current->data<<' ';
        current->data;
        if(current->right != NULL) s.push(current->right);
        if(current->left != NULL) s.push(current->left);
    }
}

template<class Type>
void BinaryTree<Type>::midorder()const
{
    seqStack<StNode> s;
    StNode current(root);
    //cout<<"\n中序遍历:"<<endl;
    s.push(current);
    while(!s.isEmpty())
    {
        current = s.pop();
        if(++current.TimesPop == 2)         //第二次出栈，可以被访问
        {
            //cout<<  current.node -> data  <<' ';
            current.node->data;
        }
        else                                //第一次出栈，不能访问，重新入栈
        {
            if(current.node -> right  !=  NULL)
                s.push(StNode(current.node -> right));
            s.push(current);
            if(current.node -> left  !=  NULL)
                s.push(StNode(current.node -> left));
        }
    }
}

template<class Type>
void BinaryTree<Type>::postorder()const
{
    //cout<<"\n后序遍历:"<<endl;

    seqStack<StNode> s;
    StNode current(root);

    s.push(current);
    while(!s.isEmpty())
    {
        current = s.pop();
        if(++current.TimesPop == 2)         //第二次出栈，可以被访问
        {
            //cout<<  current.node -> data  <<' ';
            current.node->data;
        }
        else
        {
            s.push(current);
            if(current.node ->right  !=  NULL)
                s.push(StNode(current.node -> right));
            if(current.node -> left  !=  NULL)
                s.push(StNode(current.node -> left));
        }
    }
}

#endif // BINARYTREE_H_INCLUDED
