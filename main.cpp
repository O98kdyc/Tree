#include <iostream>
#include "binarytree.h"
#include "linkQueue.h"
#include <sys/time.h> //ͷ�ļ�

struct timeval startTime, endTime; //ʱ�����

using namespace std;

int main()
{
  double diff;
  BinaryTree<char> tree;
  tree.createTree("tree203.txt",'@');
  if (tree.checkComplete()) cout<<"����ȫ������"<<endl;
  if(tree.checkFull()) cout<<"����������"<<endl;
  cout<<"��Ϊ2���ĸ���"<<tree.count2Degree()<<endl;


  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.preorder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"�ǵݹ�ǰ��"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.midorder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"�ǵݹ�����"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.postorder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"�ǵݹ����"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.preOrder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"�ݹ�ǰ��"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.midOrder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"�ݹ�����"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;

  gettimeofday (&startTime, NULL);

  //for(int i=0;i<1000;i++)
  tree.postOrder();

  gettimeofday(&endTime, NULL);
  diff = 1000000 * (endTime.tv_sec - startTime.tv_sec ) + endTime.tv_usec - startTime.tv_usec;
  //cout<<endl<<"�ݹ����"<<diff/1000<<"ms"<<endl;
  cout<<diff<<"ms"<<endl;


  return 0;
}
