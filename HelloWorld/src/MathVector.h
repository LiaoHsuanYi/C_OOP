#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

class MathVector
{
private:
    int _dim;
    double *_arr; //uncertain size array
    std::vector<double> _arrV;
    
public:
    //constructor
    MathVector(); //default constructor
    void init(int dim, double *arr); 
    //MathVector(int dim, double *arr); 
    //MathVector(int dim, int *arr);
    MathVector(int dim, void *arr);
    MathVector(const MathVector &input) : MathVector(input._dim, input._arr){}; // copy constructor, & = pass by reference (do not copy)
    MathVector(MathVector &&input) noexcept; //move constructor
    ~MathVector(); //destructor
    MathVector &operator=(const MathVector &input);  //copy assignment, assignment operator overloading
    MathVector &operator=(MathVector &&input); //move assignment, transferring a temporary object to an existing object. 
    MathVector operator+(const MathVector &input) const;   //operator overloading
    MathVector operator-(const MathVector &input) const;   //operator overloading
    MathVector operator/(const MathVector &input) const;   //operator overloading
    MathVector operator/(int input) const;
    bool operator>(const MathVector &input);
    bool operator<(const MathVector &input);
    friend std::ostream &operator<<(std::ostream &output, const MathVector &m) //TBD
    {
        std::string tmp = "";
        std::stringstream ss;
        for (int i = 0; i < m._dim; i++)
        {
            output << m._arr[i] << ",";
        }
        output << ss.str();
        tmp = ss.str();
        return output;
    }
    friend std::istream &operator>>(std::istream &input, MathVector &m) //TBD
    {
        input >> m._dim;
        double *tmp = new double[m._dim];
        for (int i = 0; i < m._dim; i++)
        {
            input >> tmp[i];
        }
        // TBD -> check dim -> delete _arr + new _arr -> put tmp into _arr
        return input;
    }
    // MathVector m, n;
    // cout << m;
    // cin >> m;
    // n = m / 10;
    std::string toString();
    
    //getter
    int getDim() const;
    double getIndex(int i) const;
    double length() const;
    
    //double dot(MathVector v1){}
    void multiply(double a);
};

#endif