#pragma once

#include "ofMain.h"
#include "Data.h"

class Plot{

	public:
		Plot();
		~Plot();
		void setup();
		void update();
		void draw(float x, float y, float w, float h, Data d);
	
	private:
		std::vector<Data> data;
};
