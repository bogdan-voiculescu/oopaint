#ifndef CANVAS_HPP_
#define CANVAS_HPP_

#include <string>
#include <list>
#include <memory>
#include "Shape.hpp"
#include "SDL2/SDL.h"

// FIXME: concrete class, doesn't have abstract base or separate interface
class Canvas {
public:
	Canvas(const std::string& title, int width, int height, const SDL_Color& color);
	~Canvas();

	void setTitle(const std::string& name);
	void clear(void);

	void add(std::shared_ptr<Shape> shape);
	void remove(std::shared_ptr<Shape> shape);
	std::shared_ptr<Shape> getShapeAt(const Coord2D& coord);
	void update();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::string name;
	SDL_Color backgroundColor;
	std::list<std::shared_ptr<Shape>> shapes;
};

#endif /* CANVAS_HPP_ */
