#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdexcept>
#include <cassert>

#include "Canvas.hpp"
#include "Coord2D.hpp"

Canvas::Canvas(const std::string& title, int width, int height, const SDL_Color& color)
: backgroundColor(color) {
	// Init graphics library
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw std::runtime_error("SDL_Init(SDL_INIT_VIDEO) failed!");
	}

	// Canvas window
	window = SDL_CreateWindow(
			name.c_str(),				// Title
			SDL_WINDOWPOS_CENTERED,		// x position of the window
			SDL_WINDOWPOS_CENTERED,		// y position of the window
			width,						// window width
			height,						// window height
			SDL_WINDOW_SHOWN);			// window flags

	if (0 == window) {
		throw std::runtime_error("SDL_CreateWindow() failed!");
	}

	// Canvas graphics context
	renderer = SDL_CreateRenderer(
			window,						// The window we want to draw into
			-1,							// Index of rendering driver, -1 = "select first supported"
			SDL_RENDERER_SOFTWARE);		// Renderer flags

	if (0 == renderer) {
		throw std::runtime_error("SDL_CreateRenderer() failed!");
	}

	setTitle(title);
	clear();
}

Canvas::~Canvas() {
	// Destroy graphics context, etc.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// Shutdown graphics library
	SDL_Quit();	// FIXME: what happens if 2 canvas object exist, and one is deleted?
}

void Canvas::setTitle(const std::string& name) {
	this->name = name;
	SDL_SetWindowTitle(window, name.c_str());
}

void Canvas::clear(void) {
	SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
	SDL_RenderClear(renderer);
}

void Canvas::update() {
	clear();

	// Draw all objects to Renderer (but not shown on the window yet)
	for (auto shape : shapes) {
		shape->draw(renderer);
	}

	// Send rendered contents to the window (shows graphics on the screen)
	SDL_RenderPresent(renderer);
}

void Canvas::add(std::shared_ptr<Shape> shape) {
	if (shape == nullptr) {
		throw std::logic_error("Trying to add null Shape!");
	}
	shapes.push_back(shape);
}

void Canvas::remove(std::shared_ptr<Shape> shape) {
	shapes.remove(shape);
}

std::shared_ptr<Shape> Canvas::getShapeAt(const Coord2D& coord) {
	for (auto shape : shapes) {
		assert(shape != nullptr);	// This should never happen, see add() check
		if (shape->containsCoordinates(coord)) {
			return shape;
		}
	}

	return nullptr;
}

