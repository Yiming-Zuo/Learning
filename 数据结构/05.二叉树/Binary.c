#include "Binary.h"
#include "sstack.h"

// 1 遍历
void recursion(struct BinaryNode *root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->ch);  // 先序遍历
	recursion(root->lChild);
//	printf("%c ", root->ch);  // 中序遍历
	recursion(root->rChild);
//	printf("%c ", root->ch);  // 后序遍历
}
// 2 叶子数
void leafNum(struct BinaryNode *root, int *p_num) {
	if (root == NULL) {
		return;
	}
	if (!root->lChild && !root->rChild) {
		(*p_num)++;
	}
	leafNum(root->lChild, p_num);
	leafNum(root->rChild, p_num);
}
// 3 深度
// 左子树与右子树深度相比取大值加1
int layerNum(struct BinaryNode *root) {
	if (root == NULL) {
		return 0;
	}

	int lNum = layerNum(root->lChild);
	int rNum = layerNum(root->rChild);
	int height = lNum > rNum ? lNum+1 : rNum+1;  // 三元表达式

	return height;
}
// 4 拷贝树
struct BinaryNode *copyTree(struct BinaryNode *root) {
	if (root == NULL) {
		return NULL;
	}
	struct BinaryNode *lTree = copyTree(root->lChild);  // 拷贝左子树
	struct BinaryNode *rTree = copyTree(root->rChild);  // 拷贝右子树
	struct BinaryNode *newNode = malloc(sizeof(struct BinaryNode));  // 新结点
	newNode->lChild = lTree;
	newNode->rChild = rTree;
	newNode->ch = root->ch;
	return newNode;
}
// 5 释放二叉树
void freeTree(struct BinaryNode *root)
{
	if (root == NULL)
	{
		return;
	}

	//先释放左子树
	freeTree(root->lChild);

	//再释放右子树
	freeTree(root->rChild);

	//再释放根节点
	printf("%c被释放了\n", root->ch);
	free(root);
}
// 6 非递归遍历
void nonRecursion(struct BinaryNode1 *root) {
	sstack mystack = init_sstack();
	push_sstack(mystack, root);
	while (!isEmpety(mystack)) {
		struct BinaryNode1 *node = top_sstack(mystack);
		pop_sstack(mystack);
		if (node->flag == 1) {
			printf("%c\n", node->ch);
			continue;  // !进入下一次循环
		}
		node->flag = 1;
		if (root->rChild) {
			push_sstack(mystack, node->rChild);
		}
		if (root->lChild) {
			push_sstack(mystack, node->lChild);
		}
		push_sstack(mystack, node);
	}
}