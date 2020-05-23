/*list*/
#include <stack>
#include <vector>


//节点c++写法
struct ListNode{  
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};
/*
//节点c写法
typedef struct ListNode{
    int data;
    struct ListNode* next;
}ListNode;
ListNode* ListNewNode(int val){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = val;
    node->next = NULL;
}*/

// 头插法
ListNode* insertHead(ListNode* pHead, int val){
    ListNode* node = new ListNode(val);
    node->next = pHead;
    pHead = node;
    return pHead;
}

//尾插
ListNode* insertTail(ListNode* pHead, int val){
    ListNode* node = new ListNode(val);
    ListNode* pNext = pHead;
    if(pNext == nullptr)
        pHead = node;
    else
    {
        while(pNext->next)
            pNext = pNext->next;
        pNext->next = node;
    }
    return pHead;
}

//删除
ListNode* deleteNode(ListNode** pHead, int val) {
	if (*pHead == nullptr) {
		return *pHead;
	}
	ListNode* pNext = *pHead;
	ListNode* pPrev = nullptr;
	while (pNext) {
		if (pNext->val == val) {
			if (pNext == *pHead) {
				*pHead = (*pHead)->next;
				break;
			}
			pPrev->next = pNext->next;
			delete pNext;
			break;
		}
		pPrev = pNext;
		pNext = pNext->next;
	}
	return *pHead;
}

//数组初始化链表
ListNode* listArray(int *a, int len) {
	ListNode* head = nullptr;
	for (int i = 0; i < len; ++i) {
		insertTail(&head, a[i]); //必须写head = 因为传入为空更改了不返回
	}
	return head;
}

//删除链表第i个元素
ListNode* deleteByindex(ListNode** pHead, int i){
    if(i < 0 || *pHead == nullptr)
        return *pHead;
    else if(i == 0){
        *pHead = (*pHead)->next;
    }
    ListNode* pNext = *pHead;
    int j = 1;
    while(pNext->next && j != i){
        pNext = pNext->next;
        j++;
    }
    if(pNext->next == nullptr)
        return *pHead;
    pNext->next = pNext->next->next;
    return *pHead;
}

//链表逆序-三指针思路
ListNode* listReverse(ListNode** pHead){
    if(*pHead == nullptr || (*pHead)->next == nullptr)
        return *pHead;
    ListNode* pre = nullptr;
    ListNode* node = *pHead;
    ListNode* next = nullptr;
    while(node){
        next = node->next;  //将node 下一节点保存到next next
        node->next = pre;   //重新指定node 下一节点为前面的
        pre = node;         //将pre 往下走
        node = next;        //将node 往下走
    }
}

//链表逆序-栈思路
ListNode* listReverse2(ListNode* pHead){
    std::stack<ListNode*> stack;
    ListNode* pNode = pHead;
    while(pNode){
        stack.push(pNode);
        pNode = pNode->next;
    }
    ListNode* newHead = nullptr;
    while(!stack.empty()){
        pNode = stack.top();
        if(newHead == nullptr){
            newHead = pNode;
            break;
        }
        newHead->next = pNode;
        newHead = pNode;
    }
    return newHead;
}

//链表逆序-递归
ListNode *listReverseRecursive(ListNode *pHead){
	if (head == NULL || pHead->next == NULL) //链表只有一个元素或者0个元素则直接输出
		return pHead;
	ListNode *newHead = listReverseRecursive(pHead->next);
    // 最后一个节点的前一个结点为例：head->next->next为最后一个节点的下一个
    // 最后节点的下一个 指向当前节点：head，并将下一个节点的下一个置空
	pHead->next->next = pHead;    
	pHead->next = NULL;
	return newHead;
}


//复杂链表复制-链表有两个节点
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
RandomListNode* listCopy(RandomListNode* pHead){
    if(!pHead) return pHead;
    RandomListNode* pNode = pHead;
    //在每个节点后面复制一个节点
    while(pNode){
        RandomListNode* node = new RandomListNode(pNode->label);
        node->next = pNode->next;
        pNode->next = node;
        pNode = node->next;
    }
    //将random指针赋给新复制的节点
    while(pNode = pHead){
        RandomListNode* node = pNode->next;
        if(pNode->random){
            node->random = pNode->ramdom->next;
        }
        pNode = node->next;
    }
    //将节点复制好的分离出来
    //一次为原链表指定下一个、一次为复制链表指定下一个，轮流操作。。。。
    pNode = pHead;
    RandomListNode* pCloneHead = pNode->next;
    RandomListNode* pCloneNode = pCloneHead;
    while(pNode->next){
        pCloneNode = pNode->next;  //将pNode 的下一节点 复制给克隆节点
        pNode->next = pCloneNode->next;  //将篇将克隆节点的下一节点给 原节点的下一节点
        pNode = pCloneNode;        //将克隆节点复制给 原节点
    }
    return pCloneHead;
}

//普通链表复制-递归
ListNode* listCopy2(ListNode *pHead){
    if(pHead == nullptr)
        return nullptr;
    ListNode* newNode = new ListNode(pHead->val);
    newNode->next = ListCopy2(pHead->next);
    return newNode;
}

//合并两个有序链表 < recrusive
ListNode* mergerList(ListNode* pHead1, ListNode* pHead2){
    if(!pHead1)
        return pHead2;
    if(!pHead2)
        return pHead1;
    ListNode* pNode = nullptr;
    if(pHead1->val < pHead2->val){
        pNode = pHead1;
        pNdoe->next = mergerList(pHead1->next, pHead2)
    }
    else{
        pNode = pHead2;
        pNode->next = mergerList(pHead1, pHead2->next);
    }
    return pNode;
}


//链表中是否存在环，输出环的入口
//双指针--快慢指针 相遇就有环
ListNode* findLoopEntry(ListNode* pHead){
    ListNode pMeetingNode = meetingNode(pHead);
    if(pMeetingNode == nullptr) return nullptr;
    ListNode* pNode = pMeetingNode->next;
    int ringLen = 1;
    while(pNode != pMeetingNode){
        ringLen++;
        pNode = pNode->next;
    }
    pNode = pHead;
    ListNode* pEntryNode = pHead;
    //找入口， 一个指针先走节点长度，然后两个指针一起走，直至相遇，为入口节点
    while(ringLen--)  
        pNode = pNode->next;
    while(pNode != pEntryNode){
        pNode = pNode->next;
        pEntryNode = pEntryNode->next;
    }
    return pEntryNode;
}

ListNode* meetingNode(ListNode* pHead){ //相遇节点
    if(!pHead) return pHead;
    ListNode *fast = pHead, *low = pHead; 
    while(fast->next && fast->next->next){ 
        low = low->next;
        fast = fast->next;
        if(low == fast)
            return low;
    }
    return nullptr;
}


//有序单向链表的插入 <
ListNode* insertSortedList(ListNode* pHead, int val){
    ListNode* node = new ListNode(val);
    if(!pHead)
        pHead = node;
    else if(head->next > val){
        node->next = pHead;
        pHead = node;
    }
    else{
        ListNode* pNext = pHead;
        while(!pNext->next && pNext->next->val < val)
            pNext = pNext->next;
        node->next = pNext->next;
        pNext->next = node;
    }
    return pHead;
}


//插入循环链表
ListNode* insertLoopSortedList(ListNode* pHead, int val){
    ListNode* node = new ListNode(val);
    if(!pHead)
        pHead = node;
    ListNode* pCur = pHead;
    ListNode* pNext = pHead->next;
    while(pNext != pHead){
        if(pCur->val <= val && pNext >= val)
            break;
        pCur = pCur->next;
        pNext = pNext->next;
    }
    pCur->next = node;
    node->next = pNext;
    if(pCur == pHead && pCur->val >= val)
        pHead = node;
    return pHead;
}

//输出倒数第k个
//快慢指针一次成型，先走k步
ListNode* theKthToTail(ListNode* pHead, int k){
    if(!pHead) return nullptr;
    ListNode* fast = pHead;
    for(int i = 1; i < k; i++){
        if(fast->next)
            fast = fast->next;
        else
            return nullptr;
    }
    ListNode* low = pHead;
    while(fast->next){
        low = low->next;
        fast = fast->next;
    }
    return low;
}

//从尾到头输出链表
std::vector<int> TailtoHead(ListNode* pHead){
    std::vector<int> res;
    if(!pHead) return res;
    res.push_back(pHead->val);
    std::vector<int> tmp = TailtoHead(pHead->next);
    res.insert(res.begin(), tmp.begin(), tmp.end());
    return res;
}

//两个链表的公共节点
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    int len1 = listLen(pHead1);
    int len2 = listLen(pHead2);
    if(len1 > len2)
        pHead1 = listGoStep(pHead1, len1 - len2);
    else
        pHead2 = listGoStep(pHead2, len2 - len1);
    while(pHead1){
        if(pHead1 == pHead2)
            break;
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
    }
    return pHead1;
    
}

int listLen(ListNode* pHead){
    int num = 0;
    while(pHead){
        pHead= pHead->next;
        num++;
    }
    return num;
}

ListNode* listGoStep(ListNode* pHead, int step){
    while(step--){
        pHead = pHead->next;
    }
    return pHead;
}

//已知一定有交点情况
ListNode* FindFirstCommonNode(ListNode* pHead1, listArray* pHead2){
    ListNode *P1 = pHead1, *p2 = pHead2;
    //目的是保持两个指针后剩余的节点数相等
    while(p1 != p2){
        p1 = (p1 == nullptr ? pHead2 : p1->next);
        p2 = (p2 == nullptr ? pHead1 : p2->next);
    }
    return p1;
}

//删除重复节点-重复节点不保留
ListNode* deleteDuplication(ListNode* pHead){
    if(!pHead || !pHead->next)
        return pHead;
    //如果相等，即往下接着找重复节点
    if(pHead->val == pHead->next->val){
        ListNode* pNode = pHead->next;
        while(pNode && pNode->val == pHead->val)
            pNode = pNode->next;
        return deleteDuplication(pNode);
    }
    else{
        pHead->next = deleteDuplication(pHead->next);
        return pHead;
    }
}

//非递归--虚拟头节点 精髓
ListNode* deleteDuplication(ListNode* pHead){
    if(pHead == nullptr || pHead->next == nullptr)
        return pHead;
    ListNode* pMyHead = new ListNode(0);   //虚拟节点指向头，防止头节点重复
    pMyHead->next = pHead;
    ListNode* pre = pMyHead;
    ListNode* last = pMyHead->next;
    while(last != nullptr)
    {
        if(last->next != nullptr && last->val == last->next->val)
        {
            //找到所有相等节点
            while(last->next != nullptr && last->val == last->next->val)
                last = last->next;
            pre->next = last->next;
            last = last->next;
        }
        else
        {
            pre = pre->next;
            last = last->next;
        }
    }
    return pMyHead->next;
}


