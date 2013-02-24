#ifndef SPINE_SKELETON_H_
#define SPINE_SKELETON_H_

#include "ofMain.h"
#include <spine/BaseSkeleton.h>

namespace spine {

class Skeleton: public BaseSkeleton {
public:
	//sf::VertexArray vertexArray;
	//sf::Texture *texture; // BOZO - This is ugly. Support multiple textures?

    ofMesh mesh;
    ofTexture* texture;
    
	Skeleton (SkeletonData *skeletonData);

	void draw();
};

} /* namespace spine */
#endif /* SPINE_SKELETON_H_ */
