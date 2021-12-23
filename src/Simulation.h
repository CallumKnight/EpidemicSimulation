#pragma once

#include "ofMain.h"
#include "Data.h"

enum HealthStatus {
	susceptible,
	infectious,
	recovered
};

typedef struct host {
	float x;
	float y;
	float destinationX;
	float destinationY;
	HealthStatus status;
} Host;

class Simulation{

	public:
		Simulation();
		~Simulation();
		void setup(float x, float y, float w, float h, int pop);
		void update();
		void draw();
		Data getSnapshot();
	
	private:
		float x;
		float y;
		float w;
		float h;
		Data snapshot;
		std::vector<Host> hosts;
};
