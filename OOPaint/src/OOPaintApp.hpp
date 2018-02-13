/*
 * OOPaintApp.hpp
 *
 *  Created on: Nov 25, 2015
 *      Author: ivaylo
 */

#ifndef OOPAINTAPP_HPP_
#define OOPAINTAPP_HPP_

#include <memory>
#include "Canvas.hpp"

// FIXME: concrete class, doesn't have abstract base or separate interface
class OOPaintApp {
public:
	OOPaintApp(std::shared_ptr<Canvas> canvas);

	void run();
	
private:
	std::shared_ptr<Canvas> canvas;
};

#endif /* OOPAINTAPP_HPP_ */
