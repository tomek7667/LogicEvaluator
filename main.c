// Author: tomek7667

#include <stdio.h>    
#include <stdlib.h> 
#include <iostream>

long long poww (long long x, long long n) {
	long long r = 1;
	for (long long i = 0; i < n; i++) r *= x;
	return r;
}

bool nott(bool a) {
	return !a;
}

bool orr(bool a, bool b) {
	return a + b != 0; 
}

bool norr(bool a, bool b) {
	return a + b == 0;
}

bool andd(bool a, bool b) {
	return a + b == 2;
}

bool nandd(bool a, bool b) {
	return a + b != 2;
}

bool xorr(bool a, bool b) {
	return orr(nott(orr(nott(a), andd(a, b))), nott(orr(nott(b), andd(a, b))));
}

bool xnorr(bool a, bool b) {
	return nott(orr(nott(orr(nott(a), andd(a, b))), nott(orr(nott(b), andd(a, b)))));
}

long long perform(long long a, long long b, bool (*f)(bool, bool)) {
	long long r = 0;
	long long h = a > b ? a : b;
	long long s = a <= b ? a : b;
	for (long long i = 0; h > 0; i++) {
		s = s <= 0 ? 0 : s;
		r += ((long long)f((bool)(s % 2), (bool)(h % 2))) * poww(2, i);
		s /= 2;
		h /= 2;
	}
	return r;
}

int main() {
	// Example:
	std::cout << perform(314, 273, xorr);
}