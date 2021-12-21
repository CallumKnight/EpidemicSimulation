#include "Plot.h"

//--------------------------------------------------------------
Plot::Plot(){
    
}

//--------------------------------------------------------------
Plot::~Plot(){
    
}

//--------------------------------------------------------------
void Plot::setup(){

}

//--------------------------------------------------------------
void Plot::update(){

}

//--------------------------------------------------------------
void Plot::draw(float x, float y, float w, float h){
    
    // ofDrawRectangle(x, y, w, h);

    // Draw x axis
    ofDrawLine(x, y + h, x + w, y + h);
    ofDrawTriangle(x + w, y + h - (0.5*(h/30.0)), x + w + (w/30.0), y + h, x + w, y + h + (0.5*(h/30.0)));

    // Draw y-axis
    ofDrawLine(x, y, x, y + h);
    ofDrawTriangle(x - (0.5*(w/30.0)), y, x, y - (h/30.0), x + (0.5*(w/30.0)), y);
}
