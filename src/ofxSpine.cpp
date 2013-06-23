//
//  ofxSpine.cpp
//  ofxSpineExample
//
//  Created by kikko on 6/21/13.
//
//

#include "ofMain.h"
#include "ofxSpine.h"
#include <spine.h>
#include <spine/extension.h>

void _AtlasPage_createTexture(AtlasPage * self, const char * path){
    
	ofTexture * texture = new ofTexture();
    
	// load image
	ofImage loader;
	loader.setUseTexture(false);
	loader.loadImage(path);
    
	// store width & height
	int imageWidth = loader.getWidth();
	int imageHeight = loader.getHeight();
    
	// allocate texture & copy in data
	texture->allocate(imageWidth, imageHeight, GL_RGBA);
	texture->loadData(loader.getPixels(), imageWidth, imageHeight, GL_RGBA);
    
	// clear temp image
	loader.clear();
    
	self->rendererObject = texture;
	self->width = imageWidth;
	self->height = imageHeight;
}

void _AtlasPage_disposeTexture(AtlasPage * self){
	delete (ofTexture *)self->rendererObject;
}

char * _Util_readFile(const char * path, int * length){
	return _readFile(ofToDataPath(path).c_str(), length);
}
