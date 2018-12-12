#include "point.h"
#include "shape.h"

class Triangle : public Shape
{
	Point p1, p2, p3;
public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	virtual void draw() const override;
	virtual void save( std::ostream& ) const override;
};
