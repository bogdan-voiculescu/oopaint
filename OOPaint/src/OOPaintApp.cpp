/*
 * OOPaintApp.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: ivaylo
 */
#include <memory>
#include "OOPaintApp.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

OOPaintApp::OOPaintApp(std::shared_ptr<Canvas> canvas)
: canvas(canvas) {
}

void OOPaintApp::run() {
	// Event loop
	std::shared_ptr<Shape> currentShape;
	while (true) {
		SDL_Event event;

		if (SDL_WaitEvent(&event))
		{
			/*
			 * Look for input events and take corresponding actions
			 * 
			 * FIXME: this is a BAD, nasty switch-case which will be beaten 
			 * by OOP design patterns
			 */
			switch (event.type) {
				case  SDL_QUIT:
					return;

				case SDL_MOUSEBUTTONDOWN:
					switch(event.button.button) {
						case SDL_BUTTON_LEFT:
							if (nullptr != currentShape) {
								// We have a new shape, add it to Canvas
								canvas->add(currentShape);
								currentShape = 0;
							}
							else {
								// We are in "Move" mode - pick a shape, if any
								currentShape = canvas->getShapeAt(Coord2D(event.button.x, event.button.y));
							}
							break;

						case SDL_BUTTON_RIGHT:
							if (0 == currentShape) {	// Delete works only when not moving an object
								auto shapeToRemove = canvas->getShapeAt(Coord2D(event.button.x, event.button.y));
								if (nullptr != shapeToRemove) {
									canvas->remove(shapeToRemove);
								}
							}
							break;
					}
					break;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case 'c':
							if (nullptr == currentShape) {
								int x, y;
								SDL_GetMouseState(&x, &y);

								currentShape = std::make_shared<Circle>(Coord2D(x, y), 50);		// FIXME: hardcoded
								currentShape->setColor({0xff, 0xff, 0xff, 0xff});	// FIXME: hardcoded
								canvas->add(currentShape);
							}
						    break;

						case 'r':
							if (nullptr == currentShape) {
								int x, y;
								SDL_GetMouseState(&x, &y);

								currentShape = std::make_shared<Rectangle>(Coord2D(x, y), Coord2D(100, 50));		// FIXME: hardcoded
								currentShape->setColor({0xff, 0xff, 0xff, 0xff});	// FIXME: hardcoded, duplicated
								canvas->add(currentShape);
							}
							break;

						case SDLK_ESCAPE:	// ESC
							if (nullptr != currentShape) {
								canvas->remove(currentShape);
								currentShape.reset();
							}
							break;

						default:
							;
					}
					break;

				case SDL_MOUSEMOTION:
					if (nullptr != currentShape) {
						// SDL_Keymod keymods = SDL_GetModState(); // If we need modifier keys info
						currentShape->moveBy(Coord2D(event.motion.xrel, event.motion.yrel));
					}
					break;
				
				case SDL_MOUSEWHEEL:
					if (nullptr != currentShape) {
						double factor = 1;
						if (event.wheel.y > 0) {
							factor = 1.1;
						}
						
						if (event.wheel.y < 0) {
							factor = 0.9;
						}

						currentShape->resize(factor);
					}
					break;
			}

			// Show the result
			canvas->update();
		}
	}
}
