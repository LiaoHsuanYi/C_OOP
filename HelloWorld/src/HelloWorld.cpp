#include <iostream>
#include "HelloWorld.h"
#include "MathVector.h"
#include "length.h"

using namespace std;


static int tmp = 0;

void SetValue(int &&input) // avoid copy of rvalue
{
    cout << "&&" << endl;
    tmp = input;
}
void SetValue(const int &input) //avoid copy of lvalue
{
    cout << "&" << endl;
    tmp = input;
}
int GetValue()
{
    return tmp;
}
/*int &Value(int input)
{
    if (tmp != input)
    {
        tmp = input;
    }
    return tmp;
}*/
int &Value()
{
    return tmp;
}
int main()
{
    std::cout << Print() << "\n";
    double arr1[2] = {1, 2};
    double arr2[3] = {3, 4, 5};
    MathVector v1(2, arr1);
    MathVector v2(3, arr2);
    //try, catch
    //double result = dot(v1,v2);

    // lvalue, rvalue;
    int i = 10; // copy constructor
    // lvalue -> identity + move in(memory)
    int j;
    j = 10; // copy assignment
    // 10 = j; <- not working
    // return by reference -> lvalue & rvalue
    j = Value();
    Value() = 10;
    //pass by reference -> no copied
    // & -> lvalue reference
    SetValue(i);
    SetValue(10); // effect of const = 10 -> const int tmp -> input
                  // && -> rvalue reference
    //try removing const from operator = for the effect of const
    //MathVector m, z, w;
    //m = z + w;

    return 0;
}




