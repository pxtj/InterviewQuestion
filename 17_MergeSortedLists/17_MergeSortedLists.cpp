/************************************************************************/
/* 17:合并两个排序的链表
/* 
/* 20140902
/************************************************************************/

#pragma comment(lib, "./debug/Utilities");
#include <iostream>
#include <cstdlib>
#include "../Utilities/List.h"
using namespace std;

ListNode* MergerSortedLists(ListNode* pList1, ListNode* pList2)
{
	if (pList1 == NULL && pList2 == NULL)
	{
		return NULL;
	}
	if (pList1 == NULL && pList2 != NULL)
	{
		return pList2;
	}
	if (pList1 != NULL && pList2 == NULL)
	{
		return pList1;
	}

	ListNode* p1 = pList1;
	ListNode* p2 = pList2;
	ListNode* pList3 = NULL;

	ListNode* pHead = NULL;
	if (p1->m_value <= p2->m_value)
	{
		pHead = p1;
	}
	else
		pHead = p2;

	while (p1 != NULL && p2 != NULL)
	{
		ListNode* pTemp = NULL;
		if (p1->m_value <= p2->m_value)
		{
			pTemp = p1;
			p1 = p1->m_pnext;
		}
		else
		{
			pTemp = p2;
			p2 = p2->m_pnext;
		}

		if(pList3 != NULL) 
			pList3->m_pnext = pTemp;
		pList3 = pTemp;
	}
	while (p1 != NULL)
	{
		if(pList3 != NULL) 
			pList3->m_pnext = p1;
		pList3 = p1;
		p1 = p1->m_pnext;
	}
	while (p2 != NULL)
	{
		if(pList3 != NULL) 
			pList3->m_pnext = p2;
		pList3 = p2;
		p2 = p2->m_pnext;
	}

	return pHead;
}


//递归方法：书上给的递归方法
ListNode* MergerSortedListsByRecursive(ListNode* pList1, ListNode* pList2)
{
	if (pList1 == NULL)
	{
		return pList2;
	}
	if (pList2 == NULL)
	{
		return pList1;
	}

	ListNode* pMergedListHead = NULL;
	if (pList1->m_value <= pList2->m_value)
	{
		pMergedListHead = pList1;
		pMergedListHead->m_pnext = MergerSortedListsByRecursive(pList1->m_pnext, pList2);
	}
	else
	{
		pMergedListHead = pList2;
		pMergedListHead->m_pnext = MergerSortedListsByRecursive(pList1, pList2->m_pnext);
	}

	return pMergedListHead;
}


// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
    ConnectListNodes(pNode5, pNode7);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    //ListNode* pMergedHead = MergerSortedLists(pNode1, pNode2);
    //PrintList(pMergedHead);

    //不能同时运行
    ListNode* pMergeHead2 = MergerSortedListsByRecursive(pNode1, pNode2);
    PrintList(pMergeHead2);

    //DestroyList(pMergedHead);
    DestroyList(pMergeHead2);
}

int main()
{
	Test1();
	return 0;
}