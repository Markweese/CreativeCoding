//Created by Mark Brewer
//4/26/2016

#include "ofApp.h"
#include "ofxCsv.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    //ofSetBackgroundAuto(false);
    
    ofEnableAlphaBlending();
    
    // allocate and clear the fbo
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo.begin();
    //ofClear(0);
        ofClearAlpha();
    fbo.end();

    currentDataset = 0;
    loadDataset("Petroleum.csv");
    loadDataset("Plastic.csv");
    loadDataset("Electronic.csv");
    
    tradeGroups.load("TradeGroups.jpg");
    cog.load("cog.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    // format:
    // col 0 - country name
    // col 1 - trade value
    ofxCsv *csv = datasets[currentDataset];
    for(int i = 0; i < csv->getNumRows(); ++i) {
        ofxCsvRow &row = csv->getRow(i);
        
        string name = row.getString(0);
        
        //loads data to circle size vis
        if(name == "SouthAm") {
            
            float tradeValue = row.getFloat(1);
            
            if (datasetNames[currentDataset] == "Petroleum"){
                SaCircleSize = ofMap(tradeValue, 60, 65000000000, 5, 15);
                SaHardValue = "  South America\n" "$ 2.1 Billion";
            } else if (datasetNames[currentDataset] == "Electronic"){
                SaCircleSize = ofMap(tradeValue, 1000000000, 25000000000, 5, 15);
                SaHardValue = "  South America\n""$ 2.7 Billion";
            } else if (datasetNames[currentDataset] == "Plastic"){
                SaCircleSize = ofMap(tradeValue, 1000000000, 12000000000, 5, 15);
                SaHardValue = "  South America\n""$ 333 Million";
            }
            
       }
        
        //loads data to circle size vis
        if(name == "Canada") {
            
            float tradeValue = row.getFloat(1);
            
            if (datasetNames[currentDataset] == "Petroleum"){
                CanCircleSize = ofMap(tradeValue, 60, 65000000000, 5, 15);
                CanHardValue = "  Canada\n" "50 Billion";
            } else if (datasetNames[currentDataset] == "Electronic"){
                CanCircleSize = ofMap(tradeValue, 1000000000, 25000000000, 5, 15);
                CanHardValue = "  Canada\n" "$ 12 Billion";
            } else if (datasetNames[currentDataset] == "Plastic"){
                CanCircleSize = ofMap(tradeValue, 1000000000, 12000000000, 5, 15);
                CanHardValue = "  Canada\n" "$ 100 Billion";
            }
            
        }
        
        //loads data to circle size vis
        if(name == "Mexico") {
            
            float tradeValue = row.getFloat(1);
            
            if (datasetNames[currentDataset] == "Petroleum"){
                MexCircleSize = ofMap(tradeValue, 60, 65000000000, 5, 15);
                MexHardValue = "  Mexico\n""11.3 Billion";
            } else if (datasetNames[currentDataset] == "Electronic"){
                MexCircleSize = ofMap(tradeValue, 1000000000, 25000000000, 5, 15);
                MexHardValue = "  Mexico\n""$ 23 Billion";
            } else if (datasetNames[currentDataset] == "Plastic"){
                MexCircleSize = ofMap(tradeValue, 1000000000, 12000000000, 5, 15);
                MexHardValue = "  Mexico\n""$ 6.2 Billion";
            }
            
            
        }
        
        //loads data to circle size vis
        if(name == "EU") {
            
            float tradeValue = row.getFloat(1);
            
            if (datasetNames[currentDataset] == "Petroleum"){
                EuCircleSize = ofMap(tradeValue, 60, 65000000000, 2, 15);
                EUhardValue = "  Europe\n""$ 61";
            } else if (datasetNames[currentDataset] == "Electronic"){
                EuCircleSize = ofMap(tradeValue, 1000000000, 25000000000, 5, 15);
                EUhardValue = "  Europe\n""$ 9 Billion";
            } else if (datasetNames[currentDataset] == "Plastic"){
                EuCircleSize = ofMap(tradeValue, 1000000000, 12000000000, 5, 15);
                EUhardValue = "  Europe\n""$ 4.3 Billion";
            }
            
        }
        
        //loads data to circle size vis
        if(name == "Asia") {
            
            float tradeValue = row.getFloat(1);
            
            if (datasetNames[currentDataset] == "Electronic"){
                AsCircleSize = ofMap(tradeValue, 1000000000, 25000000000, 5, 15);
                AsHardValue = "  Asia\n""$ 14 Billion";
            } else if (datasetNames[currentDataset] == "Plastic"){
                AsCircleSize = ofMap(tradeValue, 1000000000, 12000000000, 5, 15);
                AsHardValue = "  Asia\n""$ 2.6 Billion";
            }
            
            
        }
        
        //loads data to circle size vis
        if(name == "India") {
            
            float tradeValue = row.getFloat(1);
            
            if (datasetNames[currentDataset] == "Electronic"){
                InCircleSize = ofMap(tradeValue, 1000000000, 25000000000, 5, 15);
                InHardValue = "  India\n""$ 1.5 Billion";
            } else if (datasetNames[currentDataset] == "Plastic"){
                InCircleSize = ofMap(tradeValue, 1000000000, 12000000000, 5, 15);
                InHardValue = "  India\n""$ 570 Million";
            }
            
        }
        
        //loads data to circle size vis
        if(name == "Scand") {
            
            float tradeValue = row.getFloat(1);
            
            if (datasetNames[currentDataset] == "Petroleum"){
                ScanCircleSize = ofMap(tradeValue, 60, 65000000000, 5, 15);
                ScanHardValue = "  Scandinavia\n""$ 500 Million";
            } else if (datasetNames[currentDataset] == "Electronic"){
                ScanCircleSize = ofMap(tradeValue, 1000000000, 25000000000, 5, 15);
                ScanHardValue = "  Scandinavia\n""$ 850 Million";
            } else if (datasetNames[currentDataset] == "Plastic"){
                ScanCircleSize = ofMap(tradeValue, 1000000000, 12000000000, 5, 15);
                ScanHardValue = "  Scandinavia\n""$ 350 Million";
            }
            
        }
    }
    
    

    
    //Europe circle updates
    EUdistX = USendX - EUbeginX;
    EUdistY = USendY - EUbeginY;
    
    pct += step;
    
    if (pct < 1.0) {
        EUx = EUbeginX + (pct * EUdistX);
        EUy = EUbeginY + (pow(pct, exponent) * EUdistY);
    }
    
    
    //Asia circle updates
    ASdistX = USendX - ASbeginX;
    ASdistY = USendY - ASbeginY;
    
    pct += step;
    
    if (pct < 1.0) {
        ASx = ASbeginX + (pct * ASdistX);
        ASy = ASbeginY + (pow(pct, exponent) * ASdistY);
    }
    
    
    //South America circle updates
    SAdistX = USendX - SAbeginX;
    SAdistY = USendY - SAbeginY;
    
    pct += step;
    
    if (pct < 1.0) {
        SAx = SAbeginX + (pct * SAdistX);
        SAy = SAbeginY + (pow(pct, exponent) * SAdistY);
    }
    
    
    //Scandinavia circle updates
    ScandistX = USendX - ScanBeginX;
    ScandistY = USendY - ScanBeginY;
    
    pct += step;
    
    if (pct < 1.0) {
        Scanx = ScanBeginX + (pct * ScandistX);
        Scany = ScanBeginY + (pow(pct, exponent) * ScandistY);
    }
    
    
    //Canada circle updates
    CandistX = USendX - CanBeginX;
    CandistY = USendY - CanBeginY;
    
    pct += step;
    
    if (pct < 1.0) {
        Canx = CanBeginX + (pct * CandistX);
        Cany = CanBeginY + (pow(pct, exponent) * CandistY);
    }
    
    
    //India circle updates
    IndistX = USendX - InBeginX;
    IndistY = USendY - InBeginY;
    
    pct += step;
    
    if (pct < 1.0) {
        Inx = InBeginX + (pct * IndistX);
        Iny = InBeginY + (pow(pct, exponent) * IndistY);
    }
    
    
    //Mexico circle updates
    MexdistX = USendX - MexBeginX;
    MexdistY = USendY - MexBeginY;
    
    pct += step;
    
    if (pct < 1.0) {
        Mexx = MexBeginX + (pct * MexdistX);
        Mexy = MexBeginY + (pow(pct, exponent) * MexdistY);
    }
    
    
    if (pct > 1.0) {
        
        pct = 0.0;
        
        exponent = ofRandom(.3, 2);
        
        
    }
    
    //placed these down here because the if statement was not working in context with other idia/Asia statements
    
    if (datasetNames[currentDataset] == "Petroleum"){
        InCircleSize = 0;
        InHardValue = "  India";
    }
    
    if (datasetNames[currentDataset] == "Petroleum"){
        AsCircleSize = 0;
        AsHardValue = "  Asia";
    }
    
    
    rotation = rotation + 1;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //tradeGroups.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofPushMatrix();
    ofTranslate(USendX-15, USendY-15);
    ofRotate(rotation);
    cog.draw(-25, -25, 50, 50);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(USendX+15, USendY+15);
    ofRotate(-rotation);
    cog.draw(-15, -15, 30, 30);
    ofPopMatrix();
    
   
    ofSetColor(0, 130, 245);
    ofDrawBitmapString("UNITED       STATES", USendX-90, USendY-5);
    
    //fbo.begin();
        //Europe trade lines
        ofSetColor(35, 108, 222);
        ofDrawCircle(EUx, EUy, EuCircleSize);
        ofDrawBitmapString(EUhardValue, EUbeginX-50, EUbeginY);
    
    
        //Asia trade lines
        ofSetColor(160, 60, 55);
        ofDrawCircle(ASx, ASy, AsCircleSize);
        ofDrawBitmapString(AsHardValue, ASbeginX-50, ASbeginY);
    
        
        
        //South America trade lines
        ofSetColor(58, 167, 79);
        ofDrawCircle(SAx, SAy, SaCircleSize);
        ofDrawBitmapString(SaHardValue, SAbeginX-50, SAbeginY);
    
        
        
        //Scandinavian trade lines
        ofSetColor(254, 197, 0);
        ofDrawCircle(Scanx, Scany, ScanCircleSize);
        ofDrawBitmapString(ScanHardValue, ScanBeginX-50, ScanBeginY);
    
        
        
        //Canada trade lines
        ofSetColor(254, 64, 90);
        ofDrawCircle(Canx, Cany, CanCircleSize);
        ofDrawBitmapString(CanHardValue, CanBeginX-30, CanBeginY);
    
        
        
        //India trade lines
        ofSetColor(255, 135, 25);
        ofDrawCircle(Inx, Iny, InCircleSize);
        ofDrawBitmapString(InHardValue, InBeginX-50, InBeginY);
    
        
        //Mexico trade lines
        ofSetColor(1,88,54);
        ofDrawCircle(Mexx, Mexy, MexCircleSize);
        ofDrawBitmapString(MexHardValue, MexBeginX-50, MexBeginY);
    //fbo.end();
    

    ofSetColor(200, 200, 250);
    //fbo.draw(0,0);
    
    //interface
    ofDrawBitmapStringHighlight(ofToString(currentDataset) + ": " + datasetNames[currentDataset], 10, 24);
    ofDrawBitmapStringHighlight("Use Left and Right Arrow \n""Keys to Toggle Different\n""U.S Commodity Imports", 10, 60);
    
}


//arrow key commands
void ofApp::keyPressed(int key) {
    
    if(key == OF_KEY_LEFT) {
        prevDataset();
    }
    else if(key == OF_KEY_RIGHT) {
        nextDataset();
    }
}

void ofApp::loadDataset(string file) {
    
    // strip the extension: "Plastics.csv" -> "Plastics"
    string name = ofFilePath::removeExt(file);
    
    // try loading
    ofxCsv *csv = new ofxCsv();
    if(csv->load(file)) {
        // loaded successfully
        datasets.push_back(csv);
        datasetNames.push_back(name);
    }
}

//Resets to the front/back of dataset array if you go outside of the range
void ofApp::prevDataset() {
    currentDataset--;
    if(currentDataset < 0) {
        currentDataset = datasets.size()-1;
    }
}

void ofApp::nextDataset() {
    currentDataset++;
    if(currentDataset >= datasets.size()) {
        currentDataset = 0;
    }
}











