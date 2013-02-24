#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    try {
		ifstream atlasFile( ofToDataPath("spineboy.atlas").c_str() );
		Atlas *atlas = new Atlas(atlasFile);
        
		SkeletonJson skeletonJson(atlas);
        
		ifstream skeletonFile( ofToDataPath("spineboy-skeleton.json").c_str() );
		SkeletonData *skeletonData = skeletonJson.readSkeletonData(skeletonFile);
        
		ifstream animationFile( ofToDataPath("spineboy-walk.json").c_str() );
		animation = skeletonJson.readAnimation(animationFile, skeletonData);
        
		skeleton = new Skeleton(skeletonData);
		skeleton->flipX = false;
		skeleton->flipY = false;
		skeleton->setToBindPose();
		skeleton->getRootBone()->x = 200;
		skeleton->getRootBone()->y = 420;
		skeleton->updateWorldTransform();
        
	} catch (exception &ex) {
		cout << "ERROR : " << ex.what() << endl << flush;
	}
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    animation->apply(skeleton, ofGetElapsedTimef(), true);
    skeleton->updateWorldTransform();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    skeleton->draw();
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}