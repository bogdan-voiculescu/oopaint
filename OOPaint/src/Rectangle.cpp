#include "Rectangle.hpp"

Rectangle::Rectangle(const Coord2D& leftTop, const Coord2D& dimensions)
: Shape(leftTop), dimensions(dimensions) {
}

void Rectangle::draw(SDL_Renderer* renderer) const {
	SDL_Rect rect = {(int)coordinates.x, (int)coordinates.y, (int)dimensions.x, (int)dimensions.y};

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(renderer, &rect);
}

void Rectangle::resize(double factor) {
	dimensions.x *= factor;
	dimensions.y *= factor;
}

bool Rectangle::containsCoordinates(const Coord2D& coords) const {
	return (coordinates.x <= coords.x) && (coordinates.y <= coords.y)
			&& (coordinates.x + dimensions.x > coords.x) && (coordinates.y + dimensions.y > coords.y);
}

