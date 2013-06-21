#pragma once

#include "ofMain.h"
#include "ofxSpine.h"

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    
    ofxSkeleton skeleton;
};
