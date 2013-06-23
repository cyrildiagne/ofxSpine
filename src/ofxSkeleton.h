//
//  ofxSkeleton.h
//  ofxSpineExample
//
//  Created by kikko on 6/21/13.
//
//

#ifndef __ofxSpineExample__ofxSkeleton__
#define __ofxSpineExample__ofxSkeleton__

#include <spine.h>
#include "ofMain.h"

class ofxSkeleton {
    
public:
    
    ofxSkeleton();
    virtual ~ofxSkeleton();
    
    void setup(string atlasPath, string jsonPath);
    void update(float deltaTime);
    void draw();
    
    void setPosition(ofPoint p);
    ofPoint getPosition();
    
    Atlas * getAtlas(){
        return atlas;
    }
    AnimationState * getState(){
        return state;
    }
    AnimationStateData * getStateData(){
        return stateData;
    }
    Skeleton * getSkeleton(){
        return skeleton;
    }
    SkeletonData * getSkeletonData(){
        return skeletonData;
    }
    
protected:
    
    void updateMeshData();
    
    ofMesh mesh;
    ofTexture * texture;
    ofVec3f vertices[6];
    ofVec2f texCoords[6];
    ofFloatColor colors[6];
    
    // spine
    Atlas * atlas;
    Skeleton * skeleton;
    SkeletonData * skeletonData;
    AnimationState * state;
    AnimationStateData * stateData;
};

#endif /* defined(__ofxSpineExample__ofxSkeleton__) */
