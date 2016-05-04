#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber myVideoGrabber;
    ofTexture myTexture;
    ofTexture newTexture;
    
    unsigned char* invertedVideoData;
    unsigned char* newInvertedVideoData;
    int camWidth;
    int camHeight;
};
