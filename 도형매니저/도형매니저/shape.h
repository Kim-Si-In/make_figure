#ifndef _Shape
#define _Shape

class Shape
{
public:
	Shape() { std::cout << "S����" << std::endl; };
	virtual ~Shape() { std::cout << "S�Ҹ�" << std::endl; };

	virtual void draw() const = 0;
	virtual void save( std::ostream& ) const = 0;
};

#endif