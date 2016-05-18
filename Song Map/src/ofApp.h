#pragma once

#include "ofMain.h"

struct State;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        // this get's called when a state was clicked
        void stateClicked(string name);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void updateImageRect();
        void generateStates();
    
        ofImage soundImage;
        float imageScaleX;
        float imageScaleY;
        ofRectangle imageRect;
        ofSoundPlayer NewNoise;
        ofSoundPlayer TheOcean;
        ofPolyline line;
        ofColor colorAtXY;
        ofFbo fbo;
    
        vector<State> states;
    
};

struct State {
    
    void clear() {
        name = "";
        line.clear();
    }
    
    void draw() {
        line.draw();
    }
    
    void mousePressed(int x, int y) {
        if(line.inside(x, y)) {
            ofApp *app = (ofApp *)ofGetAppPtr();
            app->stateClicked(name);
        }
    }
    
    string name;
    ofPolyline line;
};
