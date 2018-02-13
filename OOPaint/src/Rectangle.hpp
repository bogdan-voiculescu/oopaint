#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <memory>
#include "Shape.hpp"

class Rectangle: public Shape {
public:
	Rectangle(const Coord2D& leftTop, const Coord2D& dimensions);

	void draw(SDL_Renderer* renderer) const override;
	void resize(double factor) override;
	bool containsCoordinates(const Coord2D& coords) const override;

private:
	Coord2D dimensions;
};

#endif /* RECTANGLE_HPP_ */
