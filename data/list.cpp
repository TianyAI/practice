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
        cout<<"������Ϣ����"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i < n;i++)
    {
        pnew = new ElemType;
        cout<<"�������"<<i+1<<"��??"<<endl;
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
        cout<<"������Ϊ??"<<endl;
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
    ElemType *p = head->next;//������ͷ�ڵ�
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
        cout<<"������Ϊ??"<<endl;
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
        cout<<"�����ֵ����"<<endl;
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
        cout<<"����ɹ�"<<endl;
    }
}

void LinkList::InsertElemAtHead(DataType data)
{
    ElemType * newNode = new ElemType;    //����һ��Node���ָ��newNode
    newNode->data = data;
    ElemType * p = head;              //����ָ��pָ��ͷ���
    if (head == NULL) {           //��ͷ���Ϊ��ʱ������newNodeΪͷ���
        head = newNode;
    }
    newNode->next = p->next;          //���½ڵ���뵽ָ��λ��
    p->next = newNode;
}
 
//��β��ɾ��Ԫ��
void LinkList::DeleteElemAtEnd()
{
    ElemType * p = head;          //����һ��ָ��ָ��ͷ���
    ElemType * ptemp = NULL;      //����һ��ռλ�ڵ�
    if (p->next == NULL) {        //�ж������Ƿ�Ϊ��
        cout << "�������" << endl;
    }
    else
    {
        while (p->next != NULL)   //ѭ����β����ǰһ��
        {
            ptemp = p;            //��ptempָ��β����ǰһ���ڵ�
            p = p->next;          //pָ�����һ���ڵ�
        }
        delete p;                //ɾ��β���ڵ�
        p = NULL;
        ptemp->next = NULL;
    }
}
 
//ɾ����������
void LinkList::DeleteAll()
{
    ElemType * p = head->next;
    ElemType * ptemp = new ElemType;
    while (p != NULL)                    //��ͷ������һ���ڵ����ɾ���ڵ�
    {
        ptemp = p;
        p = p->next;
        head->next = p;
        ptemp->next = NULL;
        delete ptemp;
    }
    head->next = NULL;                 //ͷ������һ���ڵ�ָ��NULL
}
 
//ɾ��ָ��������
void LinkList::DeleteElemAtPoint(DataType data)
{
    ElemType * ptemp = Find(data);    //���ҵ�ָ�����ݵĽڵ�λ��
    if (ptemp == head->next) {        //�ж��ǲ���ͷ������һ���ڵ㣬����Ǿʹ�ͷ��ɾ����
        DeleteElemAtHead();
    }
    else
    {
        ElemType * p = head;          //pָ��ͷ���
        while (p->next != ptemp)      //pѭ����ָ��λ�õ�ǰһ���ڵ�
        {
            p = p->next;
        }
        p->next = ptemp->next;         //ɾ��ָ��λ�õĽڵ�
        delete ptemp;
        ptemp = NULL;               
    }
 
}
 
//��ͷ��ɾ���ڵ�
void LinkList::DeleteElemAtHead()
{
    ElemType * p = head;
    if (p == NULL || p->next == NULL) {   //�ж��Ƿ�Ϊ�ձ����쳣
        cout << "������Ϊ�ձ�" << endl;
    }
    else
    {
        ElemType * ptemp = NULL;      //����һ��ռλ�ڵ�
        p = p->next;
        ptemp = p->next;              //��ͷ�������¸��ڵ�ָ��ռλ�ڵ�
        delete p;                     //ɾ��ͷ������һ���ڵ�
        p = NULL;
        head->next = ptemp;           //ͷ����ָ�����
    }
}

int main()
{
    LinkList l;
    int i;
    cout << "1.����������   2.����������   3.��ȡ������ĳ���   4.�жϵ������Ƿ�Ϊ��   5.��ȡ�ڵ�\n";
    cout << "6.��β������ָ��Ԫ��   7.��ָ��λ�ò���ָ��Ԫ��   8.��ͷ������ָ��Ԫ��\n";
    cout<<"9.��β��ɾ��Ԫ��   10.ɾ������Ԫ��   11.ɾ��ָ��Ԫ��   12.��ͷ��ɾ��Ԫ��   0.�˳�" << endl;
    do
    {
        cout << "������Ҫִ�еĲ�: ";
        cin >> i;
        switch (i)
        {
        case 1:
            int n;
            cout << "�����뵥����ĳ�: ";
            cin >> n;
            l.CreateLinkList(n);
            break;
        case 2:
            l.TravalLinkList();
            break;
        case 3:
            cout << "�õ�����ĳ���Ϊ" << l.GetLength() << endl;
            break;
        case 4:
            if (l.IsEmpty() == 1)
                cout << "�õ������ǿ�" << endl;
            else
            {
                cout << "�õ������ǿձ�" << endl;
            }
            break;
        case 5:
            DataType data;
            cout << "������Ҫ��ȡ�ڵ��: ";
            cin >> data;
            cout << "�ýڵ��ֵΪ" << l.Find(data)->data<< endl;
            break;
        }
    }while(i!=0);
}