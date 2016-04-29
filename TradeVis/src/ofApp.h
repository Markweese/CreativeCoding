//Created by Mark Brewer
//4/26/2016
#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "ofxCsv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        //void mousePressed(int x, int y, int button);
        void keyPressed(int key);
    
   
        ofImage tradeGroups;
        ofxSVG svg;
        ofxCsv csv;
        ofFbo fbo;
        float circleSize;
    
     
    
    // load a dataset from a file,
    // uses the filename without extension as the reference name
    void loadDataset(string file);
    
    // go to the prev dataset
    void prevDataset();
    
    // go to the next dataset
    void nextDataset();
    
    
    //Visualization based on circles moving on curves
    
    //EU variables
    //EU coordiantes
    float EUbeginX = ofGetWidth()/1.2;  // Initial x-coordinate
    float EUbeginY = ofGetHeight()/2.63;  // Initial y-coordinate

    
    //lets us know if we're at the destination pt
    float EUdistX;          // X-axis distance to move
    float EUdistY;          // Y-axis distance to move
    
    //Europe circle values
    float EUx = 0.0;        // Current x-coordinate
    float EUy = 0.0;        // Current y-coordinate
    
    //data mapped circle size/text string
    float EuCircleSize = 0;
    string EUhardValue;
    
    
    //Asia variables
    //Asia coordiantes
    float ASbeginX = 180;
    float ASbeginY = 320;
    
    //lets us know if we're at the destination pt
    float ASdistX;          // X-axis distance to move
    float ASdistY;          // Y-axis distance to move
    
    //Asia circle values
    float ASx = 0.0;        // Current x-coordinate
    float ASy = 0.0;        // Current y-coordinate
    
    //data mapped circle size
    float AsCircleSize = 0;
    string AsHardValue;
    
    
    
    //SA variables
    //SA coordinates
    float SAbeginX = ofGetWidth()/1.65;
    float SAbeginY = ofGetHeight()/1.5;
    
    //lets us know if we're at the destination pt
    float SAdistX;          // X-axis distance to move
    float SAdistY;          // Y-axis distance to move
    
    //SA circle values
    float SAx = 0.0;        // Current x-coordinate
    float SAy = 0.0;        // Current y-coordinate
    
    //data mapped circleSize
    float SaCircleSize = 0;
    string SaHardValue;
    
    
    //Scand variables
    //Scandinavia coordiantes
    float ScanBeginX = ofGetWidth()/1.197;
    float ScanBeginY = ofGetHeight()/3.5;
    
    //lets us know if we're at the destination pt
    float ScandistX;          // X-axis distance to move
    float ScandistY;          // Y-axis distance to move
    
    //scan circle values
    float Scanx = 0.0;        // Current x-coordinate
    float Scany = 0.0;        // Current y-coordinate
    
    //data mapped circleSize
    float ScanCircleSize = 0;
    string ScanHardValue;
    
    
    //canda variables
    //Canada coordiantes
    float CanBeginX = ofGetWidth()/2.2;
    float CanBeginY = ofGetHeight()/5;
    
    //lets us know if we're at the destination pt
    float CandistX;
    float CandistY;
    
    //Can circle values
    float Canx = 0.0;
    float Cany = 0.0;
    
    //data mapped circle size
    float CanCircleSize = 0;
    string CanHardValue;
    
    
    //India variables
    //India coordiantes
    float InBeginX = 90;
    float InBeginY = 400;
    
    //lets us know if we're at the destination pt
    float IndistX;
    float IndistY;
    
    //India circle values
    float Inx = 0.0;
    float Iny = 0.0;
    
    //data mapped circleSize
    float InCircleSize = 0;
    string InHardValue;
    
    
    //Mexico variables
    //Mexico coordinates
    float MexBeginX = ofGetWidth()/2.2;
    float MexBeginY = ofGetHeight()/2;
    
    //lets us know if we're at the destination pt
    float MexdistX;
    float MexdistY;
    
    //Mexico circle values
    float Mexx = 0.0;
    float Mexy = 0.0;
    
    
    //data mapped circleSize
    float MexCircleSize = 0;
    string MexHardValue;
    
    
    
    //Universal variables
    float step = 0.001;    // Size of each step along path
    float pct = 0.0;      // Percentage traveled (0.0 to 1.0)
    
    //dictates the shape of the curve
    float exponent = ofRandom(.3, 2);   // Determines the curve
    
    //US coordiantes-> this is constant
    float USendX = ofGetWidth()/2;   // Final x-coordinate
    float USendY = ofGetHeight()/2.65;   // Final y-coordinate
    
    
    
    // index to the current data set
    int currentDataset;
    

    
    vector<ofxCsv*> datasets;
    vector<string> datasetNames;
};











