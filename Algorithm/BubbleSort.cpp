#include <stdio.h>
#include <iostream>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void display(int a[], int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void BubbleSort(int a[], int n, int i)
{
    int j;
    bool exchange;
    if(i==n-1)
    {
        return;
    }
    else
    {
        exchange = false;
        for(j = n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j-1], a[j]);
                exchange = true;
            }
        }
        if(exchange = false)
        {
            return;
        }
        else{
            BubbleSort(a,n,i+1);
        }
    }
}

int main()
{
    int i = 0;
    int n = 10;
    int a[10] = {3,4,1,6,9,2,10,5,8,7};
    cout<<"排序之前的数组";
    display(a,n);
    BubbleSort(a, n, i);
    display(a,n);

    return 0;
}