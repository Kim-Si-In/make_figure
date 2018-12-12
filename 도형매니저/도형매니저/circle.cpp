#include <iostream>
#include "circle.h"

Circle::Circle() : center(), rad(0) { std::cout << "C����"<<std::endl; }

Circle::Circle(const Point& c, int r) : center(c), rad(r) { std::cout << "C����" << std::endl; }

Circle::Circle(const Circle& other) :  center(other.center), rad(other.rad) { std::cout << "C����" << std::endl; }

Circle::~Circle() { std::cout << "C�Ҹ�" << std::endl; }

void Circle::draw() const
{
	std::cout << "�� - �߽���(" << center.x << "," << center.y << ") ������ " << rad << std::endl;
}

void Circle::save(std::ostream& out) const
{
	out << "3 " << center.x << " " << center.y << " " << rad << " ";
}