#include<iostream>
#include<cstring>
#include<vector>

#ifndef BIGINT_H
#define BIGINT_H

class bigint {
	std::vector<int> digits;
	int sz=0;
public:
	// Constructor
	bigint();
	bigint(const std::string &num);
	bigint(const bigint &num);
	bigint(const long long &nm);

	// basic arithmetic operations
	bigint operator+(const bigint &num);
	// bigint operator-(const bigint &num);
	bigint operator*(const bigint &num);
	bigint operator*(const long long &num);
	// bigint operator/(const bigint &num);
	bigint operator%(bigint &nm);

	// comparison operators
	friend bool operator<(const bigint &n1 , const bigint &n2);
	friend bool operator>(const bigint &n1 , const bigint &n2);
	friend bool operator<=(const bigint &n1 , const bigint &n2);
	friend bool operator>=(const bigint &n1 , const bigint &n2);
	friend bool operator==(const bigint &n1 , const bigint &n2);
	friend bool operator!=(const bigint &n1 , const bigint &n2);

	// assignment operator
	bigint& operator=(const bigint &num);
	bigint& operator=(const long long &num);
	// ostream << operator
	friend std::ostream& operator<<(std::ostream &out, const bigint &num);
	// istream >> operator
	friend std::istream& operator>>(std::istream &input, bigint &num);

	// other methods
	friend std::string to_string(const bigint &num);
	operator long long();
};

#endif
