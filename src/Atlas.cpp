#include "Atlas.h"

namespace spine {

Atlas::Atlas (std::ifstream &file) {
	load(file);
}

Atlas::Atlas (std::istream &input) {
	load(input);
}

Atlas::Atlas (const std::string &text) {
	load(text);
}

Atlas::Atlas (const char *begin, const char *end) {
	load(begin, end);
}

BaseAtlasPage* Atlas::newAtlasPage (std::string name) {
	
    AtlasPage *page = new AtlasPage();
    
    page->texture = new ofTexture();
    
    // load image
    ofImage loader;
    loader.setUseTexture(false);
    loader.loadImage(name);
    
    // store width & height
    int imageWidth = loader.getWidth();
    int imageHeight = loader.getHeight();
    
    // allocate texture & copy in data
    page->texture->allocate(imageWidth, imageHeight, GL_RGBA);
    page->texture->loadData(loader.getPixels(), imageWidth, imageHeight, GL_RGBA);
    
    // clear temp image
    loader.clear();
    
	return page;
}

BaseAtlasRegion* Atlas::newAtlasRegion (BaseAtlasPage* page) {
	AtlasRegion *region = new AtlasRegion();
	region->page = reinterpret_cast<AtlasPage*>(page);
	return region;
}

AtlasRegion* Atlas::findRegion (const std::string &name) {
	return reinterpret_cast<AtlasRegion*>(BaseAtlas::findRegion(name));
}

} /* namespace spine */
