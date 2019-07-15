/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p;
    p = head;
    int a = 0;//用于记录进位
    for(;l1&&l2; l1 = l1->next,l2 = l2->next){//计算长度想同的那一段
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next; 
        p->val = (l1->val + l2->val + a) % 10;
        a = (l1->val + l2->val + a) / 10;//进位后所得的数
    }
    l1 = l1 ? l1 : l2;//选出剩余的另一段
    for(; l1; l1 = l1->next){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next; 
        p->val = (l1->val + a) % 10;
		a = (l1->val + a) / 10;
    }
    if(a){//如果a非0 即还可再进位 ，再分配一节点即可
       p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next;  
        p->val = a;
    }
    p->next = NULL;
    p = head;
    head = head->next;
    free(p);
    return head;
}



