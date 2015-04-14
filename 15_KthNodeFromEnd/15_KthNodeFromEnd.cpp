/************************************************************************/
/* 15:求链表中倒数第K个节点
/* 两个指针，一个先走K步，另一开始走
/* 注意事项：特殊情况的判断
/* 1.链表为空
/* 2.K <= 0
/* 3.节点个数少于K
/*
/* 20140902
/************************************************************************/

#pragma comment(lib, "./debug/Utilities");
#include <iostream>
#include <cstdlib>
#include "../Utilities/List.h" 

using namespace std;

ListNode* GetKthNodeFromEnd(ListNode* pList, int k)
{
	if (pList == NULL || k <= 0)
	{
		return NULL;
	}

	ListNode* ptrNode1 = pList;
	int numOfNode = 0;
	while (ptrNode1 != NULL)
	{
		ptrNode1 = ptrNode1->m_pnext;
		numOfNode++;
	}
	if (numOfNode < k)
	{
		return NULL;
	}

	//或者如下判断是否节点数少于K
	//for (int i = 0; i < k - 1; ++i)
	//{
	//	if (ptrNode1->m_pnext != NULL)
	//	{
	//		ptrNode1 = ptrNode1->m_pnext;
	//	}
	//	else
	//		return NULL;
	//}



	ptrNode1 = pList;
	ListNode* ptrNode2 = pList;
	while (k--)
	{
		ptrNode1 = ptrNode1->m_pnext;
	}
	while (ptrNode1 != NULL)
	{
		ptrNode1 = ptrNode1->m_pnext;
		ptrNode2 = ptrNode2->m_pnext;
	}

	return ptrNode2; 
}


void Test()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);

	ListNode* KthNode = GetKthNodeFromEnd(pNode1, 2);
	cout << KthNode->m_value << endl;

	KthNode = GetKthNodeFromEnd(pNode1, 7);
	if (KthNode == NULL)
	{
		cout << "NULL" << endl;
	}
	else
		cout << KthNode->m_value << endl;

	KthNode = GetKthNodeFromEnd(pNode6->m_pnext, 1);
	if (KthNode == NULL)
	{
		cout << "NULL" << endl;
	}
	else
		cout << KthNode->m_value << endl;


}

int main()
{
	Test();
	return 0;
}
