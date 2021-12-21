#pragma once

#include "ofMain.h"

class Simulation{

	public:
		Simulation();
		~Simulation();
		void setup();
		void update();
		void draw(float x, float y, float w, float h);
};
