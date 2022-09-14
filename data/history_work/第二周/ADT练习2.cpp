#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Rational
{
    public:
        Rational(){}
        Rational(int n, int d)
        {
            numer = n;
            denom = d;
        }
        ~Rational(){}
        Rational& And(const Rational &r)
        {   
            static Rational r1;
            if(denom==r.denom)
            {
                r1.numer = numer+r.numer;
                r1.denom = denom;
            }
            else
            {
                r1.denom = denom*r.denom;
                r1.numer = numer*r.denom +r.numer*denom;
            }
            return r1;
        }
        Rational& Subtract(const Rational &r)
        {
            static Rational r2;
            if(denom==r.denom)
            {
                if(numer>r.numer)
                {
                    r2.numer = numer-r.numer;
                }
                else
                {
                    r2.numer = r.numer-numer;
                }
                r2.denom = denom;
            }
            else
            {
                r2.denom = denom*r.denom;
                if(numer>r.numer)
                {
                    r2.numer = numer*r.denom-r.numer*denom;
                }
                else
                {
                    r2.numer = r.numer*denom-numer*r.denom;
                }
                
            }
            return r2;
        }
        Rational& Multiply(const Rational &r)
        {
            static Rational r3;
            r3.numer = numer*r.numer;
            r3.denom = denom*r.denom;
            return r3;
        }
        Rational& Except(const Rational &r)
        {
            static Rational r3;
            r3.numer = numer*r.denom;
            r3.denom = denom*r.numer;
            return r3;
        }
        bool Issame(Rational r1)
        {
            if(numer/denom==r1.numer/r1.denom)
            {
                return true;
            }
            return false;
        }
        string& toString()
        {
            static string str;
            stringstream sstr;
            sstr<<numer<<"/"<<denom;
            str = sstr.str();
            return str;
        }

    private:
        int numer;
        int denom;
};


int main()
{
    string str1;
    Rational r1(1,2);
    Rational r2(2,4);
    Rational r3 = r1.Except(r2);
    str1 = r3.toString();
    cout<<str1<<endl;
    if(r1.Issame(r2))
    {
        cout<<"They are same."<<endl;
    }

    return 1;
}