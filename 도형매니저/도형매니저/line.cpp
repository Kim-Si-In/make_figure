#include <iostream>
#include "line.h"

Line::Line() : p1(), p2() {};

Line::Line(const Point& a, const Point& b) :p1(a), p2(b) { };

Line::Line(const Line& other) : p1(other.p1), p2(other.p2) {};

Line::~Line() {}

void Line::draw() const
{
	std::cout << "Á÷¼± - (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << ")" << std::endl;
}

void Line::save(std::ostream& out) const
{
	out << "4 " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " ";
}