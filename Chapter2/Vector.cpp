#include "Vector.h"
#include <iostream>
#include<algorithm>
using namespace std;

Vector::Vector(int capacity) {
	data = new int[capacity];
	this->capacity = capacity;
}
Vector::Vector(const Vector& vec) {
	capacity = vec.capacity;
	size = vec.size;
	data = new int[vec.size];
	for (int i = 0; i < vec.capacity; i++)
	{
		data[i] = vec.data[i];
	}
}
//Vector& Vector:: operator=(const Vector& vec){
//	capacity = vec.capacity;
//	size = vec.size;
//	if (data) {
//		delete[] data;
//	}
//	if (vec.data)
//	{
//		data = new int[vec.capacity];
//		for (int i = 0; i < size; i++)
//		{
//			data[i] = vec.data[i];
//		}
//	}
//	else
//		data = nullptr;
//	return *this;
//}
Vector::~Vector() {
	if (data)
		delete[] data;
	data = NULL;
}
int Vector::getCapacity()const {
	return capacity;
}
int Vector::getSize()const {
	return size;
}
void Vector::clear() {
	for (int i = 0; i < size; i++)
	{
		data[i] = NULL;
	}
	size = 0;
}
void Vector::delLast() {
	if (size > 0) 
		data[--size] = NULL;
	else 
		cout << "ERROR: Vector is empty!!" << endl;
}
void Vector::insert(int val) {
	if (capacity >= size) {
		size *= 2;
		int* newData = new int[size];
		for (int i = 0; i < size / 2; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	data[size++] = val;
}
void Vector::print() {
	cout << "capacity: " << capacity << " size: " << size << " values: ";
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

std::ostream& operator<<(std::ostream& l, const Vector& vec) {
	for (size_t i = 0; i < vec.getSize(); i++)
	{
		l << vec.data[i] << " ";
	}
	l << "\n";
	return l;
}
bool operator==(const Vector& vec1, const Vector& vec2){
	if (vec1.size != vec2.size || vec1.capacity != vec2.capacity) {
		return false;
	}
	for (int i = 0; i < vec1.size; i++)
	{
		if (vec1.data[i] != vec2.data[i])
			return false;
	}
	return true;
}
bool operator!=(const Vector& vec1, const Vector& vec2) {
	return !(vec1 == vec2);
}

int& Vector::operator[](int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	else {
		cout << "ERROR" << endl;
		return data[0];
	}
}
int operator*(const Vector& vec1, const Vector& vec2) {
	int count = 0;
	if (vec1.capacity >= vec2.capacity) {
		for (int i = 0; i < vec2.size; i++)
		{
			count+=vec1.data[i] *= vec2.data[i];
		}
	}
	else
	{
		for (int i = 0; i < vec1.size; i++)
		{
			count += vec1.data[i] *= vec2.data[i];
		}
	}
	return count;
}


Vector operator*(const Vector& vec, int scalar) {
	Vector result(vec);  
	for (int i = 0; i < vec.size; ++i) {
		result.data[i] *= scalar;
	}
	return result;
}

Vector operator*(int scalar, const Vector& vec) {
	Vector result(vec);  
	for (int i = 0; i < vec.size; ++i) {
		result.data[i] *= scalar;
	}
	return result;
}
Vector& Vector::operator*=(int scalar) {
	for (int i = 0; i < size;i++) {
		data[i] *= scalar;
	}
	return *this;
}
Vector Vector::operator++(int demo)
{
	Vector temp = *this;
	for (int i = 0; i < this->size; i++)
	{
		this->data[i]++;
	}
	return temp;
}
Vector& Vector::operator++()
{
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] += 1;
	}
	return *this;
}
Vector Vector::operator--(int demo)
{
	Vector temp = *this;
	for (int i = 0; i < this->size; i++)
		this->data[i] -= 1;
	return temp;
}
Vector& Vector::operator--()
{

	for (int i = 0; i < this->size; i++)
	{
		this->data[i] -= 1;
	}
	return *this;
}
int Vector::operator~()const {
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += static_cast<double> (data[i] * data[i]);
	}
	return sqrt(sum);
}
bool operator<(const Vector& vec1, const Vector& vec2) {
	return ~vec1 < ~vec2;
}
bool operator<=(const Vector& vec1, const Vector& vec2) {
	return ~vec1 <= ~vec2;
}
bool operator>(const Vector& vec1, const Vector& vec2) {
	return ~vec1 > ~vec2;
}
bool operator>= (const Vector& vec1, const Vector& vec2) {
	return ~vec1 >= ~vec2;
}