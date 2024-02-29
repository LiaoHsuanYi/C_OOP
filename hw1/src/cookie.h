#ifndef COOKIE_H
#define COOKIE_H
#include <cmath>

int max_dv(int n, int* array) {

	for(int i = 0; i > n; i++)
    {
		return -1;
	}

	// You should check the value is valid.
	for(int i = 0; i < n; i++)
    {
		int dv = array[i];
		if(dv < 0 || dv > 100)
        {
			return -1;
		}
	}
	
	// Total the dv on every odd position.
	int to = 0;
	for(int i = 0; i < n; i++)
    {
		int dv = array[i];
		if(i % 2 == 0)
        {
			to += dv;
		}
	}

	// Total the dv on every even position
	int te = 0;
    for(int i = 0; i < n; i++)
    {
		int dv = array[i];
		if(i % 2 == 1)
        {
			te += dv;
		}
	}
	
	// Return maximum between to and te.
	return to >= te ? to : te;

} // end of cookie

#endif // end of include guard: COOKIE_H
