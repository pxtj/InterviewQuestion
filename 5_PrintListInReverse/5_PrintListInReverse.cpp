/***************************************************************************
* ������5����β��ͷ��ӡ���� P51
* ��Ŀ������һ�������ͷ��㣬��β��ͷ��ӡ��ÿ������ֵ
* 20140806	
***************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Node* List;
typedef struct Node* PtrNode;



List InsertBehind(List Head, int x);
List InsertFront(List Head, int x);
List CreatList()
{
	PtrNode Head;
	Head = (PtrNode)malloc(sizeof(Node));
	if(Head == NULL) return NULL;
	Head->next = NULL;

	//for(int i = 0; i < 20; i++)
	//	InsertBehind(Head, i + 1);
	//for(int i = 0; i < 20; i++)
	//	InsertFront(Head, i + 1);


	//�Ŷ�Online���룺
	while (1)
	{
		int x = 0;
		cin >> x;
		if( -1 == x) break;
		InsertBehind(Head, x);
	}

	return Head;
}

List InsertBehind(List Head, int x)
{
	if (Head == NULL) return NULL;

	PtrNode newNode = (PtrNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return Head;
	}

	newNode->data = x;
	newNode->next = NULL;

	PtrNode p1 = Head;

	while (p1->next != NULL)
	{
		p1 = p1->next;
	}

	p1->next = newNode;

	return Head;
}

List InsertFront(List Head, int x)
{
	if (Head == NULL)
	{
		return NULL;
	}

	PtrNode newNode = (PtrNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	PtrNode tempNode = Head;
	newNode->data = x;
	if (tempNode->next == NULL)
	{
		newNode->next = NULL;
		tempNode->next = newNode;
	}
	else
	{
		newNode->next = tempNode->next;
		tempNode->next = newNode;
	}

	Head = tempNode;

	return Head;
}


void PrintList(List Head)
{
	if (Head == NULL)
	{
		return ;
	}

	PtrNode p1 = Head;
	p1 = p1->next;
	while(p1 != NULL)
	{
		cout << p1->data << endl; 
		p1 = p1->next;
	}
	//cout << endl;

}


/************************************************************************************
* �Լ��Ľ��
* ���ַ�����1���������еĽ���ֵ�Ӻ���ǰ�ŵ������У�Ȼ���ӡ�������ı�����
*	   2����������ת��Ȼ�����δ�ӡ����ֵ���ı�����
*
* ע���ھŶ�Online�У���ʱ1s�������ַ�����ͨ����4���������������һ����Time Limit Exceed; 
**************************************************************************************/

//1)�������е�Ԫ��Ӻ���ǰ�ӵ������У���ӡ�����е�Ԫ��
//���ı�����
void PrintListInReverse(List Head)
{
	if (Head == NULL)
	{
		return ;
	}
	int numOfNode = 0;
	PtrNode p1 = Head;
	p1 = p1->next;
	while (p1 != NULL)
	{
		numOfNode++;
		p1 = p1->next;
	}

	int* arr = (int*)calloc(numOfNode, sizeof(int));
	if (arr == NULL)
	{
		return ;
	}

	int idx = numOfNode - 1;
	p1 = Head;
	p1 = p1->next;
	while(p1 != NULL)
	{
		arr[idx--] = p1->data;
		p1 = p1->next;
	}

	for (int i = 0; i < numOfNode; i++)
	{
		cout << arr[i] << endl; 
	}
	//cout << endl;

}


//2)��������ת��������������ֵ���ı�����
List ListReverse(List Head)
{
	if (Head == NULL || Head->next == NULL)
	{
		return NULL;
	}
	PtrNode p1, p2, p3;
	p1 = Head->next; //ȥ��ͷ���
	p2 = p1->next;
	p1->next = NULL;
	while(p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	PtrNode pHead = (PtrNode)malloc(sizeof(Node)); //���ͷ���
	if (pHead == NULL)
	{
		Head = p1;
	}
	else
	{
		pHead->next = p1;
		Head = pHead;
	}

	return Head;
}

void printListInRverseByInverseList(List Head)
{
	PtrNode head = ListReverse(Head);
	PrintList(head);
}

/****************************************************************************************
* 1) 2)����Ϊ�Լ�д�ķ���
*****************************************************************************************/

/****************************************************************************************
* ��ָoffer�����Ĵ𰸣�
* ���ַ�����3���������Ϊ��ǰ����Ҫ��Ӻ���ǰ��ӡ�����ϡ�����ȳ�����ԭ�򣬿�����ջ�ṹʵ�֣�
*	   4���ݹ������ִ�����ݹ��������ڲ�ݹ�����У���������һ��ջ�ṹ�������õݹ���
*	      ʵ�֣�
*
* ע���ھŶ�Online�У���ʱ1s�������ַ�����ͨ����4���������������һ����Time Limit Exceed; 
**************************************************************************************/

//3)��ջ�ṹ��ʵ�֣���������ʵ��ջ
typedef struct Stack
{
	int capacity;
	int size;
	int topOfStack;
	int* elementArr;
}Stack;
typedef struct Stack* PtrStack;

void Push(PtrStack Stack, int x)
{
	if (Stack->size >= Stack->capacity)
	{
		return ;
	}

	Stack->size++;
	Stack->elementArr[++Stack->topOfStack] = x;
}

int Pop(PtrStack Stack)
{
	if (Stack->size <= 0 || Stack->topOfStack < 0)
	{
		return -9999;
	}

	Stack->size--;
	return Stack->elementArr[Stack->topOfStack--];
}


void InitialStack(PtrStack stack, int length)
{
	stack->capacity = length;
	stack->size = 0;
	stack->topOfStack = -1;
	stack->elementArr = (int*)calloc(length, sizeof(int));
	if (stack->elementArr == NULL)
	{
		//printf("stack->element calloc failed!\n");
	}
}

void PrintListInReverseByStack(List Head)
{
	if (Head == NULL)
	{
		return ;
	}
	int length = 0;
	List p1 = Head;
	p1 = p1->next;
	while (p1 != NULL)
	{
		length++;
		p1 = p1->next;		
	}

	PtrStack stackForList = (PtrStack)malloc(sizeof(Stack));
	if (stackForList == NULL)
	{
		//cout << "stackList malloc failed!" << endl;
		return ;
	}
	InitialStack(stackForList, length);

	p1 = Head;
	p1 = p1->next;
	while(p1 != NULL)
	{
		Push(stackForList, p1->data);
		p1 = p1->next;
	}

	while(length--)
	{
		int data = Pop(stackForList);
		if (data == -9999)
		{
			break;
		}
		cout << data <<endl;
	}

}

//4)ͨ���ݹ�����ӡ
void PrintListInReverseByRecursively(List pHead)
{
	if (pHead != NULL)
	{
		if (pHead->next != NULL)
		{
			PrintListInReverseByRecursively(pHead->next);
		}
		cout << pHead->data << endl;
	}
}

/****************************************************************************************
* 3) 4)����Ϊ�������ϸ�����˼·��д�ĳ���
*****************************************************************************************/






void Test()
{
	List head = CreatList();
	//cout << "�����������ݣ�" << endl;
	//PrintList(head);

	//cout << "�Ӻ���ǰ��ӡ��" << endl;
	//1)���ֵ��¼�������У�Ȼ���ٴ�ӡ����
	//PrintListInReverse(head);

	//2)ͨ����������Ȼ���ٴ�ӡ
	//printListInRverseByInverseList(head);

	//3)ͨ��ջ�ṹʵ�֣�����ջ���ٳ�ջ��ӡ
	//PrintListInReverseByStack(head);

	//4)ͨ���ݹ�����ӡ
	PrintListInReverseByRecursively(head->next);
}


int main()
{
	Test();

	return 0;
}



















