#ifndef SPINE_REGIONATTACHMENT_H_
#define SPINE_REGIONATTACHMENT_H_

#include <spine/BaseRegionAttachment.h>
#include "ofMain.h"

namespace spine {

class Bone;
class AtlasRegion;

class RegionAttachment: public BaseRegionAttachment {
public:
	ofVec3f vertices[6];
    ofVec2f texCoords[6];
    ofFloatColor colors[6];
	ofTexture *texture;

	RegionAttachment (AtlasRegion *region);

	virtual void updateWorldVertices (Bone *bone);
	virtual void draw (Slot *slot);
};

} /* namespace spine */
#endif /* SPINE_REGIONATTACHMENT_H_ */
