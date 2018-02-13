#include <cmath>
#include "Coord2D.hpp"

Coord2D::Coord2D(const double x, const double y)
: x(x), y(y) {
}

double Coord2D::distanceTo(const Coord2D& coord) const {
	return sqrt((x - coord.x) * (x - coord.x) + (y - coord.y) *  (y - coord.y));
}

Coord2D& Coord2D::operator+=(const Coord2D& deltaCoords) {
	*this = *this + deltaCoords;

	return *this;
}

// FIXME: not all related operators are overloaded
Coord2D Coord2D::operator+(const Coord2D& deltaCoords) const {
	return Coord2D(x + deltaCoords.x, y + deltaCoords.y);
}

// FIXME: should be defined in terms of others, i.e. operator+ and unary-
Coord2D Coord2D::operator-(const Coord2D& deltaCoords) const {
	return Coord2D(x - deltaCoords.x, y - deltaCoords.y);
}
