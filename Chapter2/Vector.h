#pragma once
#include<iostream>
class Vector {

	int* data;
	int capacity;
	int size;
public:
	//Level A
	Vector(int capacity = 2);
	Vector(const Vector& vec);
	~Vector();
	int getCapacity()const;
	int getSize()const;
	void clear();
	void delLast();
	void insert(int);
	void print();
	//Level B:

	friend std::ostream& operator<<(std::ostream& l, const Vector& vec);
	friend bool operator==(const Vector& vec1,const Vector& vec2);
	friend bool operator!=(const Vector& vec1, const Vector& vec2);
	int& operator[](int);
	friend int operator*(const Vector& vec1, const Vector& vec2);
	friend Vector operator*(int scalar, const Vector& vec);
	friend Vector operator*(const Vector& vec,int scalar);
	Vector& operator*=(int scalar);

	Vector operator++(int demo);
	Vector operator--(int demo);
	Vector& operator++();
	Vector& operator--();
	int operator~()const;
	friend bool operator<(const Vector& vec1, const Vector& vec2);
	friend bool operator<=(const Vector& vec1, const Vector& vec2);
	friend bool operator>(const Vector& vec1, const Vector& vec2);
	friend bool operator>=(const Vector& vec1, const Vector& vec2);

};
