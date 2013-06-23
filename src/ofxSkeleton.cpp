//
//  ofxSkeleton.cpp
//  ofxSpineExample
//
//  Created by kikko on 6/21/13.
//
//

#include "ofxSkeleton.h"


ofxSkeleton::ofxSkeleton(){
    
}

ofxSkeleton::~ofxSkeleton(){
    
	SkeletonData_dispose(skeletonData);
	Atlas_dispose(atlas);
    
	AnimationState_dispose(state);
	Skeleton_dispose(skeleton);
}

void ofxSkeleton::setup(string atlasPath, string jsonPath){
    
	Bone_setYDown(true);
    
	atlas = Atlas_readAtlasFile(atlasPath.c_str());
    
	SkeletonJson * json = SkeletonJson_create(atlas);
	skeletonData = SkeletonJson_readSkeletonDataFile(json, jsonPath.c_str());
	SkeletonJson_dispose(json);
    
	skeleton = Skeleton_create(skeletonData);
	skeleton->flipX = false;
	skeleton->flipY = false;
	Skeleton_setToSetupPose(skeleton);
    
	stateData = AnimationStateData_create(skeletonData);
    
	state = AnimationState_create(stateData);
}

void ofxSkeleton::setPosition(ofPoint p){
	skeleton->root->x = p.x;
	skeleton->root->y = p.y;
	Skeleton_updateWorldTransform(skeleton);
}

ofPoint ofxSkeleton::getPosition(){
	return ofPoint(skeleton->root->x, skeleton->root->y);
}

void ofxSkeleton::update(float deltaTime){
    
	float timeScale = 1.0f;
    
	Skeleton_update(skeleton, deltaTime);
	AnimationState_update(state, deltaTime * timeScale);
	AnimationState_apply(state, skeleton);
	Skeleton_updateWorldTransform(skeleton);
}

void ofxSkeleton::draw(){
    
	updateMeshData();
    
	texture->bind();
	mesh.draw();
	texture->unbind();
}

void ofxSkeleton::updateMeshData(){
    
	mesh.clearVertices();
	mesh.clearTexCoords();
	mesh.clearColors();
    
	float vertexPositions[8];
    
	for(int i = 0; i < skeleton->slotCount; ++i){
        
		Slot * slot = skeleton->slots[i];
        
		Attachment * attachment = slot->attachment;
        
		if(!attachment || attachment->type != ATTACHMENT_REGION){
			continue;
		}
        
		RegionAttachment * regionAttachment = (RegionAttachment *)attachment;
        
		RegionAttachment_computeVertices(regionAttachment, slot->skeleton->x, slot->skeleton->y, slot->bone, vertexPositions);
        
		int r = skeleton->r * slot->r * 255;
		int g = skeleton->g * slot->g * 255;
		int b = skeleton->b * slot->b * 255;
		int a = skeleton->a * slot->a * 255;
        
		colors[0].r = r;
		colors[0].g = g;
		colors[0].b = b;
		colors[0].a = a;
		colors[1].r = r;
		colors[1].g = g;
		colors[1].b = b;
		colors[1].a = a;
		colors[2].r = r;
		colors[2].g = g;
		colors[2].b = b;
		colors[2].a = a;
		colors[3].r = r;
		colors[3].g = g;
		colors[3].b = b;
		colors[3].a = a;
		colors[4].r = r;
		colors[4].g = g;
		colors[4].b = b;
		colors[4].a = a;
		colors[5].r = r;
		colors[5].g = g;
		colors[5].b = b;
		colors[5].a = a;
        
		vertices[0].x = vertexPositions[VERTEX_X1];
		vertices[0].y = vertexPositions[VERTEX_Y1];
		vertices[1].x = vertexPositions[VERTEX_X2];
		vertices[1].y = vertexPositions[VERTEX_Y2];
		vertices[2].x = vertexPositions[VERTEX_X3];
		vertices[2].y = vertexPositions[VERTEX_Y3];
        
		vertices[3].x = vertexPositions[VERTEX_X4];
		vertices[3].y = vertexPositions[VERTEX_Y4];
		vertices[4].x = vertexPositions[VERTEX_X1];
		vertices[4].y = vertexPositions[VERTEX_Y1];
		vertices[5].x = vertexPositions[VERTEX_X3];
		vertices[5].y = vertexPositions[VERTEX_Y3];
        
		// kikko : here we update the global texture object for each region, not quite optimal
		texture = (ofTexture *)((AtlasRegion *)regionAttachment->rendererObject)->page->rendererObject;
        
		ofPoint size = ofPoint(texture->getWidth(), texture->getWidth());
        
		texCoords[0].x = regionAttachment->uvs[VERTEX_X1] * size.x;
		texCoords[0].y = regionAttachment->uvs[VERTEX_Y1] * size.y;
		texCoords[1].x = regionAttachment->uvs[VERTEX_X2] * size.x;
		texCoords[1].y = regionAttachment->uvs[VERTEX_Y2] * size.y;
		texCoords[2].x = regionAttachment->uvs[VERTEX_X3] * size.x;
		texCoords[2].y = regionAttachment->uvs[VERTEX_Y3] * size.y;
        
		texCoords[3].x = regionAttachment->uvs[VERTEX_X4] * size.x;
		texCoords[3].y = regionAttachment->uvs[VERTEX_Y4] * size.y;
		texCoords[4].x = regionAttachment->uvs[VERTEX_X1] * size.x;
		texCoords[4].y = regionAttachment->uvs[VERTEX_Y1] * size.y;
		texCoords[5].x = regionAttachment->uvs[VERTEX_X3] * size.x;
		texCoords[5].y = regionAttachment->uvs[VERTEX_Y3] * size.y;
        
		mesh.addVertices(vertices, 6);
		mesh.addTexCoords(texCoords, 6);
		mesh.addColors(colors, 6);
	}
}