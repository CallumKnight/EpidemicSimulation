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
void Plot::draw(float x, float y, float w, float h, Data d){
    
    ofSetColor(255); // White

    // Draw x axis
    ofDrawLine(x, y+h, x+w, y+h);
    ofDrawTriangle(x+w, y+h-(h/100.0), x+w+(w/50.0), y+h, x+w, y+h+(h/100.0));
    ofDrawBitmapString("Time", x+w+(w/20.0), y+h);

    // Draw y-axis
    ofDrawLine(x, y, x, y+h);
    ofDrawTriangle(x-(w/100.0), y, x, y-(h/50.0), x+(w/100.0), y);
    ofDrawBitmapString("Population", x, y-(w/20.0));

    // Add new data point
    data.push_back(d);

    // Draw data points
    float dataPointWidth = w/data.size();
    float dataPointHeight = h/(d.susceptible+d.infectious+d.recovered);

    for(int i = 0; i < data.size(); i++)
    {
        ofSetColor(50, 150, 255); // Blue
        ofDrawRectangle(x+(i*dataPointWidth), y, dataPointWidth, data[i].susceptible*dataPointHeight);
        ofSetColor(0, 255, 0); // Green
        ofDrawRectangle(x+(i*dataPointWidth), y+(data[i].susceptible*dataPointHeight), dataPointWidth, data[i].recovered*dataPointHeight);
        ofSetColor(255, 0, 0); // Red
        ofDrawRectangle(x+(i*dataPointWidth), y+((data[i].susceptible+data[i].recovered)*dataPointHeight), dataPointWidth, data[i].infectious*dataPointHeight);
    }
}
