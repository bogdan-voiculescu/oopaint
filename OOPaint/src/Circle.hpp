#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include <memory>
#include "Shape.hpp"

class Circle: public Shape
{
public:
	Circle(const Coord2D& center, double radius);

	void draw(SDL_Renderer* renderer) const override;
	void resize(double factor) override;
	bool containsCoordinates(const Coord2D& coords) const override;

private:
	double radius;
};

#endif /* CIRCLE_H_ */
