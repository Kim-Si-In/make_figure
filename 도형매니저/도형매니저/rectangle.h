#include "point.h"
#include "shape.h"

class Rectangle : public Shape
{
	Point p1, p2;

public:
	Rectangle();
	Rectangle(const Point&, const Point&);
	Rectangle(const Rectangle&);
	~Rectangle();

	virtual void draw() const override;
	virtual void save(std::ostream&) const override;
};