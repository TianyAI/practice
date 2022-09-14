#include <iostream>
using namespace std;
const int initcap = 10;
template <typename T>
class Sqlist
{
    public:
        Sqlist()
        {
            data = new T[initcap];
            capacity = initcap;
            length = 0;
        }
        Sqlist(const Sqlist<T>& s)
        {
            length = s.length;
            capacity = s.capacity;
            data = new T[capacity];
            for(int i = 0;i<length;i++)
                data[i]=s.data[i];
        }
        ~Sqlist()
        {
            delete [] data;
        }
        void recap(int newcap)
        {
            if(newcap<0)return;
            T* oldcap = data;
            data = new T[newcap];
            capacity = newcap;
            delete [] oldcap;
        }
        void creatList(T a[], int n)
        {
            for(int i = 0;i<n;i++)
            {
                if(length==capacity)
                    recap(length*2);
                data[i] = a[i];
                length++;
            }
        }
        void Add(T e)
        {
            if(length==capacity)
            {
                recap(length*2);
            }
            data[length] = e;
            length++;
        }
        int Getlength()
        {
            return length;
        }
        bool getElem(int i,T& e)
        {
            if(i<0||i>length)
            {
                return false;
            }
            e = data[i];
            return true;
        }
        bool setElem(int i,T e)
        {
            if(i<0||i>length)
            {
                return false;
            }
            data [i] = e;
            return true;
        }
        int GetNo(T e)
        {
            for(int i = 0;i<length;i++)
            {
                if(data[i]==e)
                    return i;
            }
            return -1;
        }
        bool Insert(int i,T e)
        {
            if(i<0||i>length)
                return false;
            if(length==capacity)
                recap(length*2);
            for(int t = length;t>i;t--)
                data[t] = data[t-1];
            data[i] = e;
            length++;
            return true;
        }
        bool Delete(int i)
        {
            if(i<0||i>length)
                return false;
            for(int t = i;t<length-1;t++)
                data[t] = data[t+1];
                
            length--;
            if(capacity>initcap&&length<=capacity/4)
            {
                recap(capacity/2);
            }
        }
        void Display()
        {
            for(int i = 0;i<length;i++)
                cout<<data[i]<<" ";
        }
        T* data;
        int capacity;
        int length;
};