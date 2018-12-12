#include "shape.h"

class ShapeManager {
	int nShape;
	int capacity;
	Shape** shapes;

public:
	explicit ShapeManager(int n);

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void insert(Shape*);
	void draw() const;
	void remove(int, int);
	void save() const;
	void load(std::string );
};