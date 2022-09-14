#include <stdio.h>
#include <tchar.h>  
#include <iostream>
using namespace std;
typedef int DataType;
#define Node ElemType
#define ERROR NULL

class Node
{
    public:
        int data;
        Node* next;
};

class LinkList
{
    public:
        LinkList();
        ~LinkList();
        void CreateLinkList(int n);
        void TravalLinkList();
        int GetLength();
        bool IsEmpty();
        ElemType * Find(DataType data);
        void InsertElemAtEnd(DataType data);
        void InsertElemAtIndex(DataType data, int n);
        void InsertElemAtHead(DataType data);
        void DeleteElemAtEnd();
        void DeleteAll();
        void DeleteElemAtPoint(DataType data);
        void DeleteElemAtHead();
    private:
        ElemType * head;
};

LinkList::LinkList()
{
    head = new ElemType;
    head->data = 0;
    head->next = NULL;
}

LinkList::~LinkList()
{
    delete head;
}

void LinkList::CreateLinkList(int n)
{
    ElemType *pnew, *ptemp;
    ptemp = head;
    if(n<0)
    {
        cout<<"输入信息有误"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i < n;i++)
    {
        pnew = new ElemType;
        cout<<"请输入第"<<i+1<<"个??"<<endl;
        cin>>pnew->data;
        pnew->next = NULL;
        ptemp->next = pnew;
        ptemp = pnew;
    }
}

void LinkList::TravalLinkList()
{
    if(head == NULL|| head->next == NULL)
    {
        cout<<"该链表为??"<<endl;
    }
    ElemType *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
        cout<<p->data<<endl;
    }
}

int LinkList::GetLength()
{
    int count = 0;
    ElemType *p = head->next;//不包含头节点
    while(p->next!= NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool LinkList::IsEmpty()
{
    if(head->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ElemType *LinkList::Find(DataType data)
{
    ElemType *p = head;
    if(p == NULL)
    {
        cout<<"此链表为??"<<endl;
        return ERROR;
    }
    else
    {
        while(p->next!= NULL)
        {
            if(p->data = data)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
}

void LinkList::InsertElemAtEnd(DataType data)
{
    ElemType *newNode = new ElemType;
    newNode->next = NULL;
    newNode->data = data;
    ElemType *p = head;
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        while(p->next!= NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

void LinkList::InsertElemAtIndex(DataType data,int n)
{
    if(n<1|| n>GetLength())
    {
        cout<<"输入的值有误"<<endl;
    }
    else
    {
        ElemType *ptemp = new ElemType;
        ptemp->data = data;
        ElemType *p = head;
        for(int i = 1;i<n;i++)
        {   
            p = p->next;
        }
        ptemp->next = p->next;
        p->next = ptemp;
        cout<<"插入成功"<<endl;
    }
}

void LinkList::InsertElemAtHead(DataType data)
{
    ElemType * newNode = new ElemType;    //定义一个Node结点指针newNode
    newNode->data = data;
    ElemType * p = head;              //定义指针p指向头结点
    if (head == NULL) {           //当头结点为空时，设置newNode为头结点
        head = newNode;
    }
    newNode->next = p->next;          //将新节点插入到指定位置
    p->next = newNode;
}
 
//在尾部删除元素
void LinkList::DeleteElemAtEnd()
{
    ElemType * p = head;          //创建一个指针指向头结点
    ElemType * ptemp = NULL;      //创建一个占位节点
    if (p->next == NULL) {        //判断链表是否为空
        cout << "单链表空" << endl;
    }
    else
    {
        while (p->next != NULL)   //循环到尾部的前一个
        {
            ptemp = p;            //将ptemp指向尾部的前一个节点
            p = p->next;          //p指向最后一个节点
        }
        delete p;                //删除尾部节点
        p = NULL;
        ptemp->next = NULL;
    }
}
 
//删除所有数据
void LinkList::DeleteAll()
{
    ElemType * p = head->next;
    ElemType * ptemp = new ElemType;
    while (p != NULL)                    //在头结点的下一个节点逐个删除节点
    {
        ptemp = p;
        p = p->next;
        head->next = p;
        ptemp->next = NULL;
        delete ptemp;
    }
    head->next = NULL;                 //头结点的下一个节点指向NULL
}
 
//删除指定的数据
void LinkList::DeleteElemAtPoint(DataType data)
{
    ElemType * ptemp = Find(data);    //查找到指定数据的节点位置
    if (ptemp == head->next) {        //判断是不是头结点的下一个节点，如果是就从头部删了它
        DeleteElemAtHead();
    }
    else
    {
        ElemType * p = head;          //p指向头结点
        while (p->next != ptemp)      //p循环到指定位置的前一个节点
        {
            p = p->next;
        }
        p->next = ptemp->next;         //删除指定位置的节点
        delete ptemp;
        ptemp = NULL;               
    }
 
}
 
//在头部删除节点
void LinkList::DeleteElemAtHead()
{
    ElemType * p = head;
    if (p == NULL || p->next == NULL) {   //判断是否为空表，报异常
        cout << "该链表为空表" << endl;
    }
    else
    {
        ElemType * ptemp = NULL;      //创建一个占位节点
        p = p->next;
        ptemp = p->next;              //将头结点的下下个节点指向占位节点
        delete p;                     //删除头结点的下一个节点
        p = NULL;
        head->next = ptemp;           //头结点的指针更换
    }
}

int main()
{
    LinkList l;
    int i;
    cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
    cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
    cout<<"9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素   0.退出" << endl;
    do
    {
        cout << "请输入要执行的操: ";
        cin >> i;
        switch (i)
        {
        case 1:
            int n;
            cout << "请输入单链表的长: ";
            cin >> n;
            l.CreateLinkList(n);
            break;
        case 2:
            l.TravalLinkList();
            break;
        case 3:
            cout << "该单链表的长度为" << l.GetLength() << endl;
            break;
        case 4:
            if (l.IsEmpty() == 1)
                cout << "该单链表是空" << endl;
            else
            {
                cout << "该单链表不是空表" << endl;
            }
            break;
        case 5:
            DataType data;
            cout << "请输入要获取节点的: ";
            cin >> data;
            cout << "该节点的值为" << l.Find(data)->data<< endl;
            break;
        }
    }while(i!=0);
}