#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    snapshot.susceptible = 1000;
    snapshot.recovered = 0;
    snapshot.infectious = 0;

    simulation.setup(5*ofGetWidth()/9.0, ofGetHeight()/5.0, ofGetWidth()/3.0, 3*ofGetHeight()/5.0, 1000);
}

//--------------------------------------------------------------
void ofApp::update(){

    snapshot.susceptible -= 5;
    snapshot.recovered += 1;
    snapshot.infectious += 4;

    if(snapshot.susceptible <= 0)
    {
        snapshot.susceptible = 1000;
        snapshot.recovered = 0;
        snapshot.infectious = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    plot.draw(ofGetWidth()/9.0, ofGetHeight()/5.0, ofGetWidth()/3.0, 3*ofGetHeight()/5.0, snapshot);
    simulation.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
