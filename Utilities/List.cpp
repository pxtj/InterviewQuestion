/************************************************************************/
/* List.cpp
/************************************************************************/
#include "stdafx.h"


#include <iostream>
#include <cstdlib>
#include <exception>
#include <cassert>
#include "List.h"

using namespace std;

ListNode* CreateListNode(int value)
{
	ListNode* pListNode = new ListNode();
	pListNode->m_value = value;
	pListNode->m_pnext = NULL;
	return pListNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	assert(pCurrent != NULL);
	pCurrent->m_pnext = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == NULL)
	{
		cout << "the node is NULL" << endl;
	}
	else
	{
		cout << "The key of node is: " << pNode->m_value << endl;
	}
}

void PrintList(ListNode* pListNode)
{
	if (pListNode == NULL)
	{
		cout << "List is NULL." << endl;
		return ;
	}
	cout << endl << "Print list: " ;

	while (pListNode != NULL)
	{
		cout << pListNode->m_value << " ";
		pListNode = pListNode->m_pnext;
	}
	cout << endl;
	cout << "PrintList ends" << endl;
}

void DestroyList(ListNode* pListNode)
{
	if (NULL == pListNode)
	{
		return ;
	}

	ListNode* pNode = pListNode;
	while (pNode != NULL)
	{
		pListNode = pListNode->m_pnext;
		delete pNode;
		pNode = pListNode;
	}
}

void AddToTail(ListNode* pListNode, int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_value = value;
	pNode->m_pnext = NULL;
	if (pListNode == NULL)
	{
		pListNode = pNode;
		return;
	}

	ListNode* pNodeTemp = pListNode;
	while (pNodeTemp->m_pnext != NULL)
	{
		pNodeTemp = pNodeTemp->m_pnext;
	}
	pNodeTemp->m_pnext = pNode;
	
	return ;
}

void RemoveNode(ListNode** pListNode, int value)
{
	if (pListNode == NULL || *pListNode == NULL)
	{
		return ;
	}

	ListNode* pToBeDelete = NULL;
	if ((*pListNode)->m_value == value)
	{
		pToBeDelete = *pListNode;
		*pListNode = (*pListNode)->m_pnext;
	}
	else
	{
		ListNode* pNode = *pListNode;
		while (pNode->m_pnext != NULL && pNode->m_pnext->m_value != value)
		{
			pNode = pNode->m_pnext;
		}
		if (pNode->m_pnext != NULL && pNode->m_pnext->m_value == value)
		{
			pToBeDelete = pNode->m_pnext;
			pNode->m_pnext = pNode->m_pnext->m_pnext;
		}
	}

	if (pToBeDelete != NULL)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
	}
}

