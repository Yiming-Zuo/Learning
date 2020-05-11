#include "Binary.h"

void Recursion_func() {
	struct BinaryNode nodeA = { 'A', NULL, NULL};
		struct BinaryNode nodeB = { 'B', NULL, NULL};
		struct BinaryNode nodeC = { 'C', NULL, NULL};
		struct BinaryNode nodeD = { 'D', NULL, NULL};
		struct BinaryNode nodeE = { 'E', NULL, NULL};
		struct BinaryNode nodeF = { 'F', NULL, NULL};
		struct BinaryNode nodeG = { 'G', NULL, NULL};
		struct BinaryNode nodeH = { 'H', NULL, NULL};
		
		nodeA.lChild = &nodeB;
		nodeA.rChild = &nodeF;

		nodeB.rChild = &nodeC;

		nodeC.lChild = &nodeD;
		nodeC.rChild = &nodeE;

		nodeF.rChild = &nodeG;

		nodeG.lChild = &nodeH;
		
		recursion(&nodeA);
		
		int num = 0;
		leafNum(&nodeA, &num);
		printf("%d\n", num);
		
		int height = layerNum(&nodeA);
		printf("%d\n", height);
		
		struct BinaryNode *newTree = copyTree(&nodeA);
		recursion(newTree);
		freeTree(newTree);
}

void nonRecursion_func() {
	struct BinaryNode1 nodeA = { 'A', NULL, NULL, 0};
	struct BinaryNode1 nodeB = { 'B', NULL, NULL, 0};
	struct BinaryNode1 nodeC = { 'C', NULL, NULL, 0};
	struct BinaryNode1 nodeD = { 'D', NULL, NULL, 0};
	struct BinaryNode1 nodeE = { 'E', NULL, NULL, 0};
	struct BinaryNode1 nodeF = { 'F', NULL, NULL, 0};
	struct BinaryNode1 nodeG = { 'G', NULL, NULL, 0};
	struct BinaryNode1 nodeH = { 'H', NULL, NULL, 0};
	
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;
	nonRecursion(&nodeA);
}

int main(int argc, char *argv[]) {
//	Recursion_func();
	nonRecursion_func();
	
	return 0;
}