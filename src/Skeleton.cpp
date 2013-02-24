#include <iostream>
#include "Skeleton.h"
#include <spine/SkeletonData.h>
#include <spine/Slot.h>
#include <spine/Attachment.h>

namespace spine {

Skeleton::Skeleton (SkeletonData *skeletonData) :
				BaseSkeleton(skeletonData),
				mesh(/*Quads, skeletonData->bones.size() * 4*/),
				texture(0) {
                    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
}

void Skeleton::draw() {
	//const_cast<Skeleton*>(this)->vertexArray.clear();
    
    mesh.clearVertices();
    mesh.clearTexCoords();
    mesh.clearColors();
    
	for (int i = 0, n = slots.size(); i < n; i++)
		if (slots[i]->attachment) slots[i]->attachment->draw(slots[i]);
    
    texture->bind();
	mesh.draw();
    texture->unbind();
}

} /* namespace spine */
