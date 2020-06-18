﻿#include <iostream>
#include <string>

using namespace std;

typedef int elemtype;
typedef struct LNode
{
    elemtype data;
    struct LNode* next;
}LNode;

LNode* listHI(LNode* L);  //头插法，倒序
LNode* listTI(LNode* L);  //尾插法，逆序
LNode* GetElem(LNode* L, int i);  //获取第i个元素的值（返回指针）
LNode* LocateElem(LNode* L, elemtype e);  //获取元素值为e的指针
void insert(LNode* L, int i,elemtype e); //在L链表的第i个位置插入一个元素值为e的结点
void del(LNode* L, int i);
void info(LNode* L);  //输出链表元素和长度
int main()
{
    int x = 4;

    /*
    LNode* p1 = NULL; //在函数内初始化对象，这里初始化了一个对象p1. 为什么必须NULL?
    p1 = listHI(p1);   //调用listHI函数，生成链表并将得到链表的头结点地址赋给p1。注意，光listHI(p)没用，只是return给p了，然而要赋给函数里的p，才有意义。函数里的p本质上是一个指针，指向头结点的。
    cout << p1->next->data << endl;
    cout << p1->next->next->data << endl;
    cout << LocateElem(p1, x)->data << endl;
    cout << GetElem(p1,x)->data << endl;
    */
    
    LNode* p2 = NULL;
    p2 = listTI(p2);
 //   cout << p2->next->data << endl;
 //   cout << p2->next->next->data << endl;
 //   cout << LocateElem(p2, x)->data << endl; 
 //   cout << GetElem(p2, x)->data << endl;
 //   insert(p2, 3, 555);
    del(p2, 3);
   info(p2);
    return 0;
}

LNode* listHI(LNode* L)
{
    LNode* s;int x;
    L = new LNode;
    L->next = NULL;  //L是头结点
    cin >> x;
    while (x != 9999)
    {
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

LNode* listTI(LNode* L)   //L是头结点
{
    LNode* s;int x;
    LNode* r = new LNode;
    L = r;
    cin >> x;
    while (x != 9999)
    {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
    return L;
}

LNode* GetElem(LNode* L, int i)
{

    LNode* p = L;  //注意必须新命名一个指针，因为若使用L=L->next; 会导致头结点发生移动。由于L是头指针（指向的是头结点），故L->next是真正意义上的首元结点。
    if (i < 0)
        return NULL;
    else if (i == 0)   //i等于0，返回的是头结点。
        return L;  
    else
        for (int j = 1;j <= i && p->next != NULL;j++)
        {
            p = p->next;
        }
    return p;
}

LNode* LocateElem(LNode* L, elemtype e)
{
    LNode* p = L->next;  //注意必须新命名一个指针，因为若使用L=L->next; 会导致头结点发生移动。
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

void insert(LNode* L, int i, elemtype e)
{
    LNode *p=GetElem(L, i-1);
    LNode *s=new LNode;
    s->data = e;
    s->next = p->next;
    p->next=s;
}

void del(LNode* L, int i)
{
    LNode* p = GetElem(L, i - 1);
    p->next=p->next->next;
}

void info(LNode* L)
{
    int cnt = 0;
    LNode* p = L;
    while (p->next!=NULL)
    {
        p = p->next;
        cnt++;
        cout << p->data<<" ";
   }
    cout << endl;
    cout << "length is " << cnt << endl;
}