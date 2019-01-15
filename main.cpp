#include <iostream>
#include "binarytree.h"
#include "linkQueue.h"
#include <sys/time.h> //头文件

struct timeval startTime, endTime; //时间变量

using namespace std;

int main()
{
  double diff;
  BinaryTree<char> tree;
  tree.createTree("tree203.txt",'@');
  if (tree.checkComplete()) cout<<"是完全二叉树"<<endl;
  if(tree.checkFull()) cout<<"是满二叉树"<<endl;
  cout<<"度为2结点的个数"<<tree.count2Degree()<<endl;


  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.preorder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"非递归前序"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.midorder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"非递归中序"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.postorder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"非递归后序"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.preOrder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"递归前序"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.midOrder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"递归中序"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.postOrder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"递归后序"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;


  return 0;
}
