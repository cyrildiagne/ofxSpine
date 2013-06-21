#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    skeleton.setup("spineboy.atlas", "spineboy.json");
    skeleton.setPosition( ofPoint(ofGetWidth()*0.5, ofGetHeight()));
    
	AnimationStateData_setMixByName(skeleton.getStateData(), "walk", "jump", 0.2f);
	AnimationStateData_setMixByName(skeleton.getStateData(), "jump", "walk", 0.4f);
    
	AnimationState_setAnimationByName(skeleton.getState(), "walk", true);
}

//--------------------------------------------------------------
void testApp::update(){
    
    skeleton.update( 1.0f / 60 );
}

//--------------------------------------------------------------
void testApp::draw(){
    
    skeleton.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
	AnimationState_addAnimationByName(skeleton.getState(), "jump", false, 0);
	AnimationState_addAnimationByName(skeleton.getState(), "walk", true, 0);
}