#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    soundImage.load("Volume.jpg");
    imageRect.setSize(soundImage.getWidth(), soundImage.getHeight());
    
    updateImageRect();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(colorAtXY.r < 30){
        ofLog()<< "that pixel is dark blue";
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    soundImage.draw(imageRect.x, imageRect.y, imageRect.getWidth(), imageRect.getHeight());
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

    if(imageRect.inside(x, y)) {
    
        float sx = soundImage.getWidth() / ofGetWidth();
        float sy = soundImage.getHeight() / ofGetHeight();
        //ofLog() << sx << " " << sy;
        
        colorAtXY = soundImage.getColor((int)(x)*sx, (int)(y)*sy);
        
        ofLog() << "color is " << colorAtXY;
    }
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
    updateImageRect();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::updateImageRect() {
    ofRectangle win = ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
    imageRect.scaleTo(win,
            OF_ASPECT_RATIO_KEEP,
            OF_ALIGN_HORZ_CENTER,
            OF_ALIGN_VERT_CENTER,
            OF_ALIGN_HORZ_CENTER,
            OF_ALIGN_VERT_CENTER);
}
