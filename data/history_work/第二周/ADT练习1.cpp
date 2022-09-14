#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
class Point
{
    public:
        Point(int x1, int y1)
        {
            x = x1;
            y = y1;
        }
        ~Point(){}
        void setX(Point &p, int x1)
        {
            p.x = x1;
        }
        void setY(Point &p, int y1)
        {
            p.y = y1;
        }

        int getX(Point &p)
        {
            return p.x;
        }
        int getY(Point &p)
        {
            return p.y;
        }
        void distance(const Point &p)
        {
            int x1 = p.x-x;
            int y1 = p.y-y;
            y1 *= y1;
            x1 *= x1;
            int d = y1+x1;
            cout<<"两点间的距离为："<<sqrt(d)<<endl;
        }
        string& toString()
        {
            static string str;
            stringstream sstr;
            sstr<<"("<<x<<","<<y<<")";
            str = sstr.str();
            return str;
        }
    private:
        int x;
        int y;

};

int main()
{
    Point p1(5,4);
    Point p2(3,9);
    p1.distance(p2);
    cout<<"p2的值为："<<p2.toString();
    return 0;
}