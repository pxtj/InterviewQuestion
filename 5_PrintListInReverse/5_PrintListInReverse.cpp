/***************************************************************************
* 面试题5：从尾到头打印链表 P51
* 题目：输入一个链表的头结点，从尾到头打印出每个结点的值
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


	//九度Online输入：
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
* 自己的解答：
* 两种方法：1）把链表中的结点的值从后往前放到数组中，然后打印链表，不改变链表；
*	   2）将链表逆转，然后依次打印结点的值，改变链表；
*
* 注：在九度Online中，限时1s，此两种方法都通过了4个测试用例，最后一个都Time Limit Exceed; 
**************************************************************************************/

//1)把链表中的元算从后往前从到数组中，打印数组中的元素
//不改变链表
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


//2)把链表逆转，在依次输出结点值，改变链表
List ListReverse(List Head)
{
	if (Head == NULL || Head->next == NULL)
	{
		return NULL;
	}
	PtrNode p1, p2, p3;
	p1 = Head->next; //去掉头结点
	p2 = p1->next;
	p1->next = NULL;
	while(p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	PtrNode pHead = (PtrNode)malloc(sizeof(Node)); //添加头结点
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
* 1) 2)以上为自己写的方法
*****************************************************************************************/

/****************************************************************************************
* 剑指offer给出的答案：
* 两种方法：3）链表遍历为从前往后，要求从后往前打印，符合“后进先出”的原则，可以用栈结构实现；
*	   4）递归操作在执行外层递归又引发内层递归的运行，本质上是一个栈结构，可以用递归来
*	      实现；
*
* 注：在九度Online中，限时1s，此两种方法都通过了4个测试用例，最后一个都Time Limit Exceed; 
**************************************************************************************/

//3)用栈结构来实现，用数组来实现栈
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

//4)通过递归来打印
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
* 3) 4)以上为根据书上给出的思路，写的程序
*****************************************************************************************/






void Test()
{
	List head = CreatList();
	//cout << "输出输入的数据：" << endl;
	//PrintList(head);

	//cout << "从后往前打印：" << endl;
	//1)结点值记录到数组中，然后再打印数组
	//PrintListInReverse(head);

	//2)通过逆置链表，然后再打印
	//printListInRverseByInverseList(head);

	//3)通过栈结构实现，先入栈，再出栈打印
	//PrintListInReverseByStack(head);

	//4)通过递归来打印
	PrintListInReverseByRecursively(head->next);
}


int main()
{
	Test();

	return 0;
}



















