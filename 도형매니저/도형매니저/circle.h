#include "point.h"
#include "shape.h"

class Circle : public Shape
{
	Point center;
	int rad;

public:
	Circle();
	Circle(const Point&, int);
	Circle(const Circle&);
	~Circle();

	virtual void draw() const override;
	virtual void save(std::ostream&) const override;
};