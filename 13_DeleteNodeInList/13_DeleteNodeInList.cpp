// DeleteNodeInList.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

//#include "stdafx.h"
//�����¾䣬����Utilities.lib��Utilities.dll����������Ŀ�µ�debug��
#pragma comment(lib,"./debug/Utilities")
#include <iostream>
#include <cstdlib>
#include "../Utilities/List.h"

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // Ҫɾ���Ľ�㲻��β���
    if(pToBeDeleted->m_pnext != NULL)
    {
        ListNode* pNext = pToBeDeleted->m_pnext;
        pToBeDeleted->m_value = pNext->m_value;
        pToBeDeleted->m_pnext = pNext->m_pnext;
 
        delete pNext;
        pNext = NULL;
    }
    // ����ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    // �������ж����㣬ɾ��β���
    else
    {
        ListNode* pNode = *pListHead;
        while(pNode->m_pnext != pToBeDeleted)
        {
            pNode = pNode->m_pnext;            
        }
 
        pNode->m_pnext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

// ====================���Դ���====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
void Test1()
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

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
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

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void Test3()
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

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// ����Ϊ��
void Test5()
{
    Test(NULL, NULL);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
