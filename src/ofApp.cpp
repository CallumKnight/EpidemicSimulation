#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    plot.setup(ofGetWidth()/9.0, ofGetHeight()/5.0, ofGetWidth()/3.0, 3*ofGetHeight()/5.0);
    simulation.setup(5*ofGetWidth()/9.0, ofGetHeight()/5.0, ofGetWidth()/3.0, 3*ofGetHeight()/5.0, 1000);
}

//--------------------------------------------------------------
void ofApp::update(){

    plot.update(simulation.getSnapshot());
    simulation.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    plot.draw();
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
