/************************************************************************
* 由前序遍历和中序遍历重建二叉树
* 20140821
************************************************************************/


#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Node
{
	int chValue;
	struct Node* pLeft;
	struct Node* pRight;
}Node;

typedef struct Node* pNode;
typedef struct Node* BinaryTreeNode;

bool validInput = true;

BinaryTreeNode ConstructBinaryTree(int* startPerOrder, int* endPerOrder, int* startInOrder, int* endInOrder);
BinaryTreeNode RebuildBinaryTree(int* perOrder, int* inOrder, int length)
{
	if (perOrder == NULL || inOrder == NULL || length <= 0)
	{
		return NULL;
	}

	BinaryTreeNode BinaryTree = NULL;
	BinaryTree = ConstructBinaryTree(perOrder, perOrder + length - 1, 
		inOrder, inOrder + length - 1);

	return BinaryTree;
}


BinaryTreeNode ConstructBinaryTree(int* startPerOrder, int* endPerOrder, int* startInOrder, int* endInOrder)
{
	if (startPerOrder == NULL || endPerOrder == NULL || startInOrder == NULL || endInOrder == NULL)
	{
		return NULL;
	}

	pNode rootNode = (pNode)malloc(sizeof(Node)); 
	rootNode->chValue = startPerOrder[0];
	rootNode->pLeft = rootNode->pRight = NULL;

	if (startPerOrder == endPerOrder)
	{
		if (startInOrder == endInOrder && *startPerOrder == *startInOrder)
		{
			return rootNode;
		}
		else
		{
			validInput = false;
			return NULL;
		}
	}

	int* rootInOrder = startInOrder;
	while (*rootInOrder != rootNode->chValue && rootInOrder <= endInOrder)
	{
		++rootInOrder;
	}

	if (rootInOrder == endPerOrder && *rootInOrder != rootNode->chValue)
	{
		validInput = false;
		return NULL;
	}

	int leftLength = rootInOrder - startInOrder;

	if (leftLength > 0)
	{
		rootNode->pLeft = ConstructBinaryTree(startPerOrder + 1, startPerOrder + leftLength, 
			startInOrder, rootInOrder - 1);
	}
	if (leftLength < endPerOrder - startPerOrder)
	{
		rootNode->pRight = ConstructBinaryTree(startPerOrder + leftLength + 1, endPerOrder,
			rootInOrder + 1, endInOrder);
	}


	return rootNode;

}


void PrintBehindTree(BinaryTreeNode Tree)
{
	if (Tree == NULL)
	{
		return;
	}
	PrintBehindTree(Tree->pLeft);
	PrintBehindTree(Tree->pRight); 
	cout << Tree->chValue << " "; 

	return ;
}


void Test()
{

	int number = 0;
	cout << "number: ";
	while (cin >> number)
	{
		int* perOrder= (int*)calloc(number, sizeof(int));
		int* inOrder= (int*)calloc(number, sizeof(int));
		cout << "perOrder: ";
		for (int i = 0; i < number; i++)
		{
			scanf("%d", &perOrder[i]);
		}
		cout << endl << "InOrder: ";
		for (int i = 0; i < number; i++)
		{
			scanf("%d", &inOrder[i]);
		}

		pNode Tree = RebuildBinaryTree(perOrder, inOrder, number);

		cout << "PostOrder: ";
		if (validInput)
		{
			PrintBehindTree(Tree);
		}
		else
		{
			cout << "No" ;
		}
		cout << endl;

		free(perOrder);
		free(inOrder);
		perOrder = inOrder = NULL;
	}


}


int main()
{
	Test();

	return 0;
}


