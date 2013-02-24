#pragma once

#include "ofMain.h"

#include "ofxSpine.h"

using namespace spine;

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void mouseDragged(int x, int y, int button);
    
    Skeleton* skeleton;
    Animation* animation;
};
