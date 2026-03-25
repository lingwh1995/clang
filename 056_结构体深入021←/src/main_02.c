#include <stdio.h>

/**
 * 链表节点结构体（
 */
typedef struct node {
    int data;
    struct node *next;
} node, *linked_list;

/**
 * @brief 打印链表
 * @param head 链表头节点指针
 */
void print_linked_list(const linked_list head) {
    if (head == NULL) {
        printf("链表为空\n");
        return;
    }
    /**
     * 1. 不推荐直接用 head，因为会丢失头指针位置
     * 2. 遍历指针的类型，必须和链表头指针的类型完全一致！
     *    推荐 linked_list current = head; 而非 node *current = head;
     */
    linked_list current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    // 静态创建链表节点
    node node_1 = {1, NULL};
    node node_2 = {2, NULL};
    node node_3 = {3, NULL};

    // 构建链表关系
    node_1.next = &node_2;
    node_2.next = &node_3;

    // 链表头指针
    linked_list head = &node_1;

    // 打印输出
    print_linked_list(head);

    return 0;
}