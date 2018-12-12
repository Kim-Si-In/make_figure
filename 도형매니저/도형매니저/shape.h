#ifndef _Shape
#define _Shape

class Shape
{
public:
	Shape() { std::cout << "S»ı¼º" << std::endl; };
	virtual ~Shape() { std::cout << "S¼Ò¸ê" << std::endl; };

	virtual void draw() const = 0;
	virtual void save( std::ostream& ) const = 0;
};

#endif