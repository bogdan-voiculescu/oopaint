#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <SDL2/SDL.h>
#include "Coord2D.hpp"

class Shape {
public:
	Shape(const Coord2D& coordinates);
	virtual ~Shape() = default;

	// Methods inherited by subclasses
	virtual void setColor(const SDL_Color& newColor);
	virtual const SDL_Color& getColor() const;
	virtual void moveBy(const Coord2D& deltaCoords);

	// Pure virtual methods - to be implemented in subclasses
	virtual void draw(SDL_Renderer* renderer) const = 0;
	virtual void resize(double factor) = 0;
	virtual bool containsCoordinates(const Coord2D& coords) const = 0;

protected:
	SDL_Color color;
	Coord2D coordinates;
	Coord2D remainderCoord;
};

#endif /* SHAPE_HPP_ */
