#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //left eye
    ofFill();
    ofSetColor(255, 0, 0);
    
    ofCircle(250, 70, 60);
    
    ofSetColor(10, 255, 220);
    
    ofCircle(250,80,50);
    
    ofSetColor(0);
    
    //right eye
    ofCircle(250, 80, 10);
    
    ofSetColor(255, 0, 0);
    
    ofCircle(700, 70, 60);
    
    ofFill();
    ofSetColor(10, 255, 220);
    
    ofCircle(700,80,50);
    
    ofSetColor(0);
    
    ofCircle(700, 80, 10);
    
    //left tooth
    ofSetColor(255);
    ofTriangle(200, 200, 250, 160, 230, 470);
    ofTriangle(700, 180, 750, 190, 725, 470);
    
    //bottom of jaw
    ofSetColor(255, 0, 0);
    ofBeginShape();
    ofEnableSmoothing();
    ofVertex(50, 300);
    ofVertex(350, 600);
    ofVertex(600, 600);
    ofVertex(900, 300);
    
    ofVertex(600, 650);
    ofVertex(350,650);
    ofVertex(50, 300);
    ofEndShape();

    //top of jaw
    ofBeginShape();
    ofEnableSmoothing();
    ofVertex(50, 300);
    ofVertex(350, 130);
    ofVertex(600, 130);
    ofVertex(900, 300);
    
    ofVertex(600, 80);
    ofVertex(350, 80);
    ofVertex(50, 300);
    ofEndShape();
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
