//判断要判断的部分是否对称。
#include <iostream>
using namespace std;
class Solution {
public:
    static bool isPalindrome(int x) {
        double n = x;
        double t = 0;
        if(x<0)
            return false;
        else{
            while(x)
            {
                t = t*10+x%10;
                x/=10;
            }
            return n==t?true:false;
        }
    }
};

int main()
{
    int x = 123454321;
    if(Solution::isPalindrome(x))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}