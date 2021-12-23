#pragma once

#include "ofMain.h"
#include "Data.h"

class Plot{

	public:
		Plot();
		~Plot();
		void setup(float x, float y, float w, float h);
		void update(Data d);
		void draw(/*Data d*/);
	
	private:
		float x;
		float y;
		float w;
		float h;
		std::vector<Data> data;
};
