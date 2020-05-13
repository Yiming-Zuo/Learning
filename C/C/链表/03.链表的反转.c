#include <stdio.h>
#include <stdlib.h>

struct LinkNode {
	int num;
	struct LinkNode *next;
};

struct LinkNode *initLL(void) {
	struct LinkNode *p_header = malloc(sizeof(struct LinkNode));
	struct LinkNode *p_cur = p_header;
	int num = 0;
	while (1) {
		printf("请输入数值：\n");
		scanf("%d", &num);
		if (num == -1) {
			break;
		}
		struct LinkNode *p = malloc(sizeof(struct LinkNode)); 
		p->num = num;
		p->next = NULL;
		p_cur->next = p;
		p_cur = p;
	}
	return p_header;
}

int printLL(struct LinkNode *p_header) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_cur = p_header->next;
	while (p_cur != NULL) {
		printf("%d ", p_cur->num);
		p_cur = p_cur->next;
	}
	printf("\n");
	return 0;
}

int destoryLL(struct LinkNode *p_header) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_cur = p_header;
	while (p_cur != NULL) {
		struct LinkNode *tmp = p_cur->next;
		free(p_cur);
		p_cur = tmp;
	}
	printf("释放完成\n");
	return 0;
}
// 反转
int reLL(struct LinkNode *p_header) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_pre = p_header->next;
	struct LinkNode *p_cur = p_pre->next;
	struct LinkNode *p_next = p_cur->next;
	p_pre->next = NULL;  // 将第二个结点的next设为NULL
	while (p_cur != NULL) {  // cur==NULL时 pre是最后一个结点
		p_next = p_cur->next;  // 保存下一个结点地址
		p_cur->next = p_pre;
		p_pre = p_cur;
		p_cur = p_next;
	}
	p_header->next = p_pre;  // 将头结点与最后一个结点相连
	return 0;
}


int main(int argc, char *argv[]) {
	struct LinkNode *p_header = initLL();
	reLL(p_header);
	printLL(p_header);
	destoryLL(p_header);
	return 0;
}