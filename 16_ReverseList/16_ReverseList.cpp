/************************************************************************/
/* 16:反转链表
/* 注意事项：
/* 1.输入的链表为空
/* 2.输入的链表只有一个节点
/* 3.输入的链表有多个节点
/* 20140902
/************************************************************************/

#pragma comment(lib, "./debug/Utilities");
#include <iostream>
#include <cstdlib>
#include "../Utilities/List.h"

using namespace std;

ListNode* ReverseList(ListNode* pList)
{
	if (pList == NULL)
	{
		return NULL;
	}

	if (pList->m_pnext == NULL)
	{
		return pList;
	}

	ListNode* p1 = pList;
	ListNode* p2 = pList->m_pnext;
	ListNode* p3 = NULL;
	
	while (p2 != NULL)
	{
		p3 = p2->m_pnext;
		p2->m_pnext = p1;
		p1 = p2;
		p2 = p3;
	}

	pList->m_pnext = NULL;
	pList = p1;
	return pList;
}


void Test()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	cout << "Before Reverse: " << endl;
	PrintList(pNode1);

	pNode1 = ReverseList(pNode1);
	cout << "after reverse: " << endl;
	PrintList(pNode1);

	ListNode* reNode1 = ReverseList(NULL);
	cout << "after reverse: " << endl;
	PrintList(reNode1);

	ListNode* pNode6 = CreateListNode(6);
	ListNode* reNode = ReverseList(pNode6);
	cout << "after reverse: " << endl;
	PrintList(reNode);

}

int main()
{
	Test();
	return 0;
}