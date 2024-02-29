#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include <algorithm>
#include "alcohol.h"
#include "order.h"
using namespace std;


void sort_alcohol_by_content(vector<Alcohol*> &alcohol)
{
    sort(alcohol.begin(), alcohol.end(),
    [](Alcohol *a, Alcohol *b) { 
    if(a -> get_alcohol_content() == b -> get_alcohol_content())
    {
        return a -> get_name() < b -> get_name();
    }
    return a -> get_alcohol_content() < b -> get_alcohol_content();
    });
}

void sort_alcohol_by_name(vector<Alcohol*> &alcohol)
{
    sort(alcohol.begin(), alcohol.end(),
        [](Alcohol *a, Alcohol *b) { 
            return a -> get_name() < b -> get_name();
        });
}

Alcohol* get_greatest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    sort_alcohol_by_content(alcohol);
    reverse(begin(alcohol), end(alcohol));
    return alcohol[0];
}
Alcohol* get_smallest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    sort_alcohol_by_content(alcohol);
    return alcohol[0];
}


#endif