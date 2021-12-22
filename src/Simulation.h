#pragma once

#include "ofMain.h"
#include "Data.h"

class Simulation{

	public:
		Simulation();
		~Simulation();
		void setup(float x, float y, float w, float h, int pop);
		void update();
		void draw();
	
	private:
		float x;
		float y;
		float width;
		float height;
		std::vector<Host> hosts;
};
