#pragma once
#include <stdio.h>
#include <stdlib.h>
// 二叉树结点结构体
struct BinaryNode {
	char ch;
	struct BinaryNode *lChild;  // 左孩子
	struct BinaryNode *rChild;  // 右孩子
};
// 非递归遍历
struct BinaryNode1 {
	char ch;
	struct BinaryNode1 *lChild;  // 左孩子
	struct BinaryNode1 *rChild;  // 右孩子
	int flag;
};
// 1 遍历
void recursion(struct BinaryNode *root);
// 2 叶子数
void leafNum(struct BinaryNode *root, int *p_num);
// 3 深度
// 左子树与右子树深度相比取大值加1
int layerNum(struct BinaryNode *root);
// 4 拷贝树
struct BinaryNode *copyTree(struct BinaryNode *root);
// 5 释放二叉树
void freeTree(struct BinaryNode * root);
// 6 非递归遍历
void nonRecursion(struct BinaryNode1 *root);

