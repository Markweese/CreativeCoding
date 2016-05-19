#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
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
    
//draws polylines that abide by same size and aspect ratio as the image
    ofPushMatrix();
    ofTranslate(imageRect.x, imageRect.y);
    ofScale(imageScaleX, imageScaleY);
    for(auto &state : states) {
        state.draw();
    }
    ofPopMatrix();
    

    soundImage.draw(imageRect.x, imageRect.y, imageRect.getWidth(), imageRect.getHeight());
    
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
    
    s.name = "South Dakota";
    s.line.addVertex(755, 304);
    s.line.addVertex(966, 315);
    s.line.addVertex(974, 458);
    s.line.addVertex(890, 434);
    s.line.addVertex(746, 428);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "North Dakota";
    s.line.addVertex(768, 173);
    s.line.addVertex(953, 184);
    s.line.addVertex(970, 310);
    s.line.addVertex(755, 304);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Louisianna";
    s.line.addVertex(1055, 871);
    s.line.addVertex(1157, 869);
    s.line.addVertex(1168, 902);
    s.line.addVertex(1153, 945);
    s.line.addVertex(1199, 947);
    s.line.addVertex(1216, 943);
    s.line.addVertex(1247, 1032);
    s.line.addVertex(1173, 1032);
    s.line.addVertex(1066, 1010);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Arkansas";
    s.line.addVertex(1046, 715);
    s.line.addVertex(1216, 715);
    s.line.addVertex(1168, 854);
    s.line.addVertex(1053, 863);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Missouri";
    s.line.addVertex(1014, 530);
    s.line.addVertex(1140, 530);
    s.line.addVertex(1233, 667);
    s.line.addVertex(1203, 719);
    s.line.addVertex(1101, 700);
    s.line.addVertex(1035, 702);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Iowa";
    s.line.addVertex(977, 397);
    s.line.addVertex(1144, 393);
    s.line.addVertex(1173, 456);
    s.line.addVertex(1175, 465);
    s.line.addVertex(1142, 521);
    s.line.addVertex(1001, 521);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Minnesota";
    s.line.addVertex(951, 141);
    s.line.addVertex(1179, 204);
    s.line.addVertex(1105, 273);
    s.line.addVertex(1099, 339);
    s.line.addVertex(1144, 393);
    s.line.addVertex(981, 393);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Wisconsin";
    s.line.addVertex(1109, 269);
    s.line.addVertex(1155, 245);
    s.line.addVertex(1273, 304);
    s.line.addVertex(1257, 421);
    s.line.addVertex(1155, 426);
    s.line.addVertex(1125, 350);
    s.line.addVertex(1103, 332);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Illinois";
    s.line.addVertex(1175, 430);
    s.line.addVertex(1173, 476);
    s.line.addVertex(1164, 478);
    s.line.addVertex(1146, 532);
    s.line.addVertex(1225, 654);
    s.line.addVertex(1249, 654);
    s.line.addVertex(1279, 582);
    s.line.addVertex(1264, 426);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Mississippi";
    s.line.addVertex(1196, 776);
    s.line.addVertex(1270, 771);
    s.line.addVertex(1277, 965);
    s.line.addVertex(1223, 969);
    s.line.addVertex(1218, 941);
    s.line.addVertex(1155, 941);
    s.line.addVertex(1177, 891);
    s.line.addVertex(1166, 856);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Alabama";
    s.line.addVertex(1279, 773);
    s.line.addVertex(1373, 769);
    s.line.addVertex(1412, 932);
    s.line.addVertex(1329, 939);
    s.line.addVertex(1331, 978);
    s.line.addVertex(1281, 973);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Georgia";
    s.line.addVertex(1377, 763);
    s.line.addVertex(1460, 756);
    s.line.addVertex(1553, 863);
    s.line.addVertex(1547, 921);
    s.line.addVertex(1523, 923);
    s.line.addVertex(1519, 932);
    s.line.addVertex(1416, 934);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Florida";
    s.line.addVertex(1340, 936);
    s.line.addVertex(1423, 934);
    s.line.addVertex(1527, 923);
    s.line.addVertex(1549, 923);
    s.line.addVertex(1656, 1137);
    s.line.addVertex(1577, 1143);
    s.line.addVertex(1440, 995);
    s.line.addVertex(1340, 973);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Tenessee";
    s.line.addVertex(1233, 704);
    s.line.addVertex(1491, 680);
    s.line.addVertex(1412, 758);
    s.line.addVertex(1214, 773);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Kentucky";
    s.line.addVertex(1236, 702);
    s.line.addVertex(1438, 680);
    s.line.addVertex(1471, 630);
    s.line.addVertex(1434, 580);
    s.line.addVertex(1371, 576);
    s.line.addVertex(1327, 626);
    s.line.addVertex(1273, 632);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Indiana";
    s.line.addVertex(1279, 460);
    s.line.addVertex(1364, 452);
    s.line.addVertex(1377, 567);
    s.line.addVertex(1329, 621);
    s.line.addVertex(1275, 621);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Michigan";
    s.line.addVertex(1303, 454);
    s.line.addVertex(1316, 276);
    s.line.addVertex(1401, 293);
    s.line.addVertex(1442, 393);
    s.line.addVertex(1425, 447);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Ohio";
    s.line.addVertex(1375, 452);
    s.line.addVertex(1499, 426);
    s.line.addVertex(1514, 478);
    s.line.addVertex(1503, 530);
    s.line.addVertex(1466, 584);
    s.line.addVertex(1386, 563);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "South Carolina";
    s.line.addVertex(1468, 745);
    s.line.addVertex(1505, 733);
    s.line.addVertex(1577, 739);
    s.line.addVertex(1623, 767);
    s.line.addVertex(1610, 804);
    s.line.addVertex(1560, 856);
    s.line.addVertex(1466, 767);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "North Carolina";
    s.line.addVertex(1512, 667);
    s.line.addVertex(1745, 623);
    s.line.addVertex(1664, 767);
    s.line.addVertex(1625, 763);
    s.line.addVertex(1584, 734);
    s.line.addVertex(1553, 736);
    s.line.addVertex(1503, 730);
    s.line.addVertex(1475, 745);
    s.line.addVertex(1425, 743);
    s.line.close();
    states.push_back(s);
    s.clear();

    s.name = "Virginia";
    s.line.addVertex(1453, 673);
    s.line.addVertex(1706, 626);
    s.line.addVertex(1664, 550);
    s.line.addVertex(1621, 526);
    s.line.addVertex(1597, 526);
    s.line.addVertex(1573, 567);
    s.line.addVertex(1560, 569);
    s.line.addVertex(1547, 617);
    s.line.addVertex(1490, 621);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "West Virginia";
    s.line.addVertex(1464, 580);
    s.line.addVertex(1521, 478);
    s.line.addVertex(1534, 510);
    s.line.addVertex(1603, 504);
    s.line.addVertex(1619, 523);
    s.line.addVertex(1597, 523);
    s.line.addVertex(1575, 565);
    s.line.addVertex(1562, 567);
    s.line.addVertex(1547, 619);
    s.line.addVertex(1488, 623);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Maryland";
    s.line.addVertex(1553, 491);
    s.line.addVertex(1675, 469);
    s.line.addVertex(1710, 521);
    s.line.addVertex(1699, 547);
    s.line.addVertex(1634, 534);
    s.line.addVertex(1599, 504);
    s.line.addVertex(1558, 510);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Pennsylvania";
    s.line.addVertex(1505, 397);
    s.line.addVertex(1660, 371);
    s.line.addVertex(1686, 391);
    s.line.addVertex(1677, 423);
    s.line.addVertex(1695, 441);
    s.line.addVertex(1677, 467);
    s.line.addVertex(1525, 491);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "New Jersey";
    s.line.addVertex(1690, 395);
    s.line.addVertex(1725, 402);
    s.line.addVertex(1727, 447);
    s.line.addVertex(1712, 491);
    s.line.addVertex(1680, 467);
    s.line.addVertex(1701, 443);
    s.line.addVertex(1684, 423);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "New York";
    s.line.addVertex(1521, 323);
    s.line.addVertex(1623, 239);
    s.line.addVertex(1688, 233);
    s.line.addVertex(1727, 384);
    s.line.addVertex(1706, 395);
    s.line.addVertex(1649, 367);
    s.line.addVertex(1534, 386);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Vermont";
    s.line.addVertex(1693, 226);
    s.line.addVertex(1719, 319);
    s.line.addVertex(1747, 319);
    s.line.addVertex(1754, 210);
    s.line.close();
    states.push_back(s);
    s.clear();

    s.name = "New Hampshire";
    s.line.addVertex(1751, 204);
    s.line.addVertex(1751, 321);
    s.line.addVertex(1825, 306);
    s.line.addVertex(1771, 195);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Maine";
    s.line.addVertex(1771, 184);
    s.line.addVertex(1815, 289);
    s.line.addVertex(1906, 178);
    s.line.addVertex(1841, 84);
    s.line.addVertex(1793, 89);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Massachusettes";
    s.line.addVertex(1725, 326);
    s.line.addVertex(1808, 308);
    s.line.addVertex(1852, 356);
    s.line.addVertex(1804, 373);
    s.line.addVertex(1782, 360);
    s.line.addVertex(1730, 371);
    s.line.close();
    states.push_back(s);
    s.clear();
    
    s.name = "Connecticut";
    s.line.addVertex(1727, 378);
    s.line.addVertex(1791, 365);
    s.line.addVertex(1808, 384);
    s.line.addVertex(1730, 430);
    s.line.close();
    states.push_back(s);
    s.clear();







   
    
    
}