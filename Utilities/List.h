/************************************************************************/
/* dll: list.h
/************************************************************************/

struct ListNode
{
	int m_value;
	struct ListNode* m_pnext;
};

#ifndef LIST_H_
#define LIST_H_
#define INTERVIEW_EXPORT
#ifdef INTERVIEW_EXPORT
#define API_DECLSPEC __declspec(dllexport)
#else
#define API_DECLSPEC __declspec(dllimport)
#endif 

API_DECLSPEC ListNode* CreateListNode(int value);
API_DECLSPEC void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
API_DECLSPEC void PrintListNode(ListNode* pNode);
API_DECLSPEC void PrintList(ListNode* pListNode);
API_DECLSPEC void DestroyList(ListNode* pListNode);
API_DECLSPEC void AddToTail(ListNode* pListNode, int value);
API_DECLSPEC void RemoveNode(ListNode** pListNode, int value);


#endif