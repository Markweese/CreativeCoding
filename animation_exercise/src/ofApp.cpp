#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    y = 0;
    
    angle = 0;
    
    bottomRowY = 700;
    
    ofBackground(10, 180, 200);
    
    ofSetBackgroundAuto(false);
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(y > 700){
        
        y = 0;
    }
    
    if(bottomRowY < 0){
        
        bottomRowY = 700;
    }
    
    xpos = 0 + sin(angle)*1000;
    xpos2 = 1000 - sin(angle)*1000;
    angle = angle +.025;
    
    
    
    y = y + ofRandom(1,5);
    
    bottomRowY = bottomRowY - ofRandom(1, 5);
    
    
  


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    for (int j = 0; j < 1200; j += 20 ) {
        
        ofSetColor(10, 250, 210);
        ofDrawCircle(xpos, j, 10);
        
    }
    
    for (int j = 0; j < 1200; j += 20 ) {
        
        ofSetColor(250, 10, 210);
        ofDrawCircle(xpos2, j, 10);
        
    }
    
    
    
    for (int i = 0; i < 1200; i += 10) {
        
        //ofSetColor(255);
        //ofDrawCircle(i, y, 12);
        
        ofSetColor(10, ofRandom(200, 210), ofRandom(210, 240));
        ofDrawCircle(i, y, 5);
        
        
    }
    
    for(int i = 0; i < 1200; i += 10) {
        
        ofSetColor(ofRandom(210,240), ofRandom(190, 210), 10);
        ofDrawCircle(i, bottomRowY, 5);
    }
    
    
    

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
