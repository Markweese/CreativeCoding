#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    //sound image is the large image, image rect acts as it's bounding box which helps it maintain aspect ratio and middle of screen orientation
    soundImage.load("Volume.jpg");
    imageRect.setSize(soundImage.getWidth(), soundImage.getHeight());
    
    //loads sounds files, soon use ofDirectory to arrange songs according to states
    NewNoise.load("New Noise.wav");
    TheOcean.load("The Ocean.wav");
    
    
    updateImageRect();
    generateStates();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //this if checks if a pixel is dark blue
//    if(colorAtXY.r < 30){
//        ofLog()<< "that pixel is dark blue";
//    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    soundImage.draw(imageRect.x, imageRect.y, imageRect.getWidth(), imageRect.getHeight());
    
//trying to make polylines abide by same size and aspect ratio as the image
    ofPushMatrix();
    ofTranslate(imageRect.x, imageRect.y);
    ofScale(imageScaleX, imageScaleY);
    ofSetColor(255, 0, 0);
    for(auto &state : states) {
        state.draw();
    }
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::stateClicked(string name) {
    ofLog() << name;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

    //changes the images pixel value locations based on the dimensions of the display window
    if(imageRect.inside(x, y)) {
    
        float sx = soundImage.getWidth() / ofGetWidth();
        float sy = soundImage.getHeight() / ofGetHeight();
        
        colorAtXY = soundImage.getColor((int)(x)*sx, (int)(y)*sy);
        
        //ofLog() << "color is " << colorAtXY;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //if the color is dark blue, melt someones face
    if(colorAtXY.r<30){
        NewNoise.play();
    } else{NewNoise.stop();}
    
    //if the color is white, let them know they are out in the ocean somewhere
    if(colorAtXY.r + colorAtXY.g + colorAtXY.b == 765){
        TheOcean.play();
    } else{TheOcean.stop();}
    
    if(imageRect.inside(x, y)) {
        
        float sx = soundImage.getWidth() / ofGetWidth();
        float sy = soundImage.getHeight() / ofGetHeight();
        
        for(auto &state : states) {
            state.mousePressed(x*sx, y*sy);
        }
    }
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
    //not sure whats going on here, ask Dan
    ofRectangle win = ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
    imageRect.scaleTo(win,
            OF_ASPECT_RATIO_KEEP,
            OF_ALIGN_HORZ_CENTER,
            OF_ALIGN_VERT_CENTER,
            OF_ALIGN_HORZ_CENTER,
            OF_ALIGN_VERT_CENTER);
    imageScaleX = imageRect.width / soundImage.getWidth();
    imageScaleY = imageRect.height / soundImage.getHeight();
}

//--------------------------------------------------------------
void ofApp::generateStates() {
    
    State s;
    
    s.name = "Wyoming";
    s.line.addVertex(535, 334);
    s.line.addVertex(726, 354);
    s.line.addVertex(722, 510);
    s.line.addVertex(515, 491);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Washington";
    s.line.addVertex(163, 78);
    s.line.addVertex(393, 130);
    s.line.addVertex(376, 271);
    s.line.addVertex(272, 247);
    s.line.addVertex(202, 241);
    s.line.addVertex(165, 193);
    s.line.addVertex(152, 100);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Oregon";
    s.line.addVertex(165, 205);
    s.line.addVertex(195, 217);
    s.line.addVertex(202, 239);
    s.line.addVertex(280, 250);
    s.line.addVertex(367, 273);
    s.line.addVertex(319, 428);
    s.line.addVertex(69, 369);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "California";
    s.line.addVertex(58, 376);
    s.line.addVertex(215, 410);
    s.line.addVertex(191, 528);
    s.line.addVertex(326, 747);
    s.line.addVertex(289, 839);
    s.line.addVertex(147, 810);
    s.line.addVertex(56, 632);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Idaho";
    s.line.addVertex(391, 139);
    s.line.addVertex(332, 421);
    s.line.addVertex(515, 452);
    s.line.addVertex(533, 328);
    s.line.addVertex(474, 317);
    s.line.addVertex(428, 145);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Montana";
    s.line.addVertex(424, 117);
    s.line.addVertex(759, 176);
    s.line.addVertex(742, 341);
    s.line.addVertex(485, 328);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Utah";
    s.line.addVertex(404, 447);
    s.line.addVertex(502, 465);
    s.line.addVertex(498, 504);
    s.line.addVertex(550, 515);
    s.line.addVertex(535, 678);
    s.line.addVertex(372, 652);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Nevada";
    s.line.addVertex(219, 408);
    s.line.addVertex(400, 447);
    s.line.addVertex(359, 689);
    s.line.addVertex(335, 691);
    s.line.addVertex(332, 728);
    s.line.addVertex(191, 532);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Arizona";
    s.line.addVertex(365, 654);
    s.line.addVertex(524, 680);
    s.line.addVertex(500, 915);
    s.line.addVertex(404, 906);
    s.line.addVertex(293, 828);
    s.line.addVertex(341, 689);
    s.line.addVertex(361, 689);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Colorado";
    s.line.addVertex(561, 510);
    s.line.addVertex(776, 532);
    s.line.addVertex(770, 697);
    s.line.addVertex(539, 676);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "New Mexico";
    s.line.addVertex(539, 682);
    s.line.addVertex(733, 702);
    s.line.addVertex(722, 910);
    s.line.addVertex(557, 906);
    s.line.addVertex(548, 919);
    s.line.addVertex(511, 915);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Texas";
    s.line.addVertex(748, 741);
    s.line.addVertex(853, 747);
    s.line.addVertex(863, 828);
    s.line.addVertex(1044, 858);
    s.line.addVertex(1064, 1026);
    s.line.addVertex(937, 1115);
    s.line.addVertex(946, 1182);
    s.line.addVertex(844, 1163);
    s.line.addVertex(607, 906);
    s.line.addVertex(742, 919);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Oklahoma";
    s.line.addVertex(770, 704);
    s.line.addVertex(1038, 708);
    s.line.addVertex(1051, 856);
    s.line.addVertex(863, 826);
    s.line.addVertex(859, 734);
    s.line.addVertex(770, 730);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Kansas";
    s.line.addVertex(787, 569);
    s.line.addVertex(1020, 576);
    s.line.addVertex(1020, 697);
    s.line.addVertex(781, 693);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Nebraska";
    s.line.addVertex(744, 432);
    s.line.addVertex(903, 439);
    s.line.addVertex(933, 447);
    s.line.addVertex(966, 458);
    s.line.addVertex(1005, 567);
    s.line.addVertex(792, 565);
    s.line.addVertex(796, 517);
    s.line.addVertex(737, 515);
    s.line.close();
    states.push_back(s);
    s.clear();
}