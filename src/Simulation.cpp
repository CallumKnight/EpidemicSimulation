#include "Simulation.h"

//--------------------------------------------------------------
Simulation::Simulation(){

}

//--------------------------------------------------------------
Simulation::~Simulation(){

}

//--------------------------------------------------------------
void Simulation::setup(float x, float y, float w, float h, int pop){

    // Set simulation parameters
    this->x = x;
    this->y = y;
    width = w;
    height = h;

    // Randomly distribute the hosts within the simulation area
    for(int i = 0; i < pop; i++)
    {
        Host host;
        host.x = rand() % static_cast<int>(width-1) + 1;
        host.y = rand() % static_cast<int>(height-1) + 1;
        host.status = susceptible;

        // Set first host to be infectious
        if(i == 0)
        {
            host.status = infectious;
        }

        hosts.push_back(host);
    }

}

//--------------------------------------------------------------
void Simulation::update(){

}

//--------------------------------------------------------------
void Simulation::draw(){
    
    // Draw simulation zone
    ofSetColor(255);
    ofNoFill();
    ofDrawRectangle(x, y, width, height);

    // Draw hosts
    for(Host host : hosts)
    {
        switch(host.status)
        {
            case susceptible:
                ofSetColor(50, 150, 255); // Blue
                ofDrawCircle(x+host.x, y+host.y, 1.0);
                break;

            case infectious:
                ofSetColor(255, 0, 0); // Red
                ofDrawCircle(x+host.x, y+host.y, 1.0);
                break;

            case recovered:
                ofSetColor(0, 255, 0); // Green
                ofDrawCircle(x+host.x, y+host.y, 1.0);
                break;

            default:
                break;
        }
    }
}
