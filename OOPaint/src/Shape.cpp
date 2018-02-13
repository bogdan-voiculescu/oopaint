#include "Shape.hpp"

Shape::Shape(const Coord2D& coordinates)
: coordinates(coordinates) {
}

void Shape::setColor(const SDL_Color& newColor) {
	color = newColor;
}

const SDL_Color& Shape::getColor() const {
	return color;
}

void Shape::moveBy(const Coord2D& deltaCoords) {
	coordinates += deltaCoords;
}
