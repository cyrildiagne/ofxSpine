#include <iostream>
#include "RegionAttachment.h"
#include "Atlas.h"
#include "Skeleton.h"
#include <spine/Bone.h>
#include <spine/Slot.h>

namespace spine {

RegionAttachment::RegionAttachment (AtlasRegion *region) {
	texture = region->page->texture; // BOZO - Resolve attachment as late as possible?
	int u = region->x;
	int u2 = u + region->width;
	int v = region->y;
	int v2 = v + region->height;
	if (region->rotate) {
        
		texCoords[0].x = u2;
		texCoords[0].y = v2;
		texCoords[1].x = u;
		texCoords[1].y = v2;
		texCoords[2].x = u;
		texCoords[2].y = v;
        
		texCoords[3].x = u2;
		texCoords[3].y = v;
		texCoords[4].x = u2;
		texCoords[4].y = v2;
		texCoords[5].x = u;
		texCoords[5].y = v;
        
	} else {
        
		texCoords[0].x = u;
		texCoords[0].y = v2;
		texCoords[1].x = u;
		texCoords[1].y = v;
		texCoords[2].x = u2;
		texCoords[2].y = v;
    
		texCoords[3].x = u2;
        texCoords[3].y = v2;
        texCoords[4].x = u;
        texCoords[4].y = v2;
        texCoords[5].x = u2;
        texCoords[5].y = v;
	}
}

void RegionAttachment::draw (Slot *slot) {
	Skeleton* skeleton = (Skeleton*)slot->skeleton;
    
	float r = skeleton->r * slot->r * 255;
	float g = skeleton->g * slot->g * 255;
	float b = skeleton->b * slot->b * 255;
	float a = skeleton->a * slot->a * 255;
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

	updateOffset(); // BOZO - Move to resolve()?
	updateWorldVertices(slot->bone);

	skeleton->texture = texture;
	skeleton->mesh.addVertices(vertices, 6);
	skeleton->mesh.addTexCoords(texCoords, 6);
	skeleton->mesh.addColors(colors, 6);
}

void RegionAttachment::updateWorldVertices (spine::Bone *bone) {
	float x = bone->worldX;
	float y = bone->worldY;
	float m00 = bone->m00;
	float m01 = bone->m01;
	float m10 = bone->m10;
	float m11 = bone->m11;
	vertices[0].x = offset[0] * m00 + offset[1] * m01 + x;
	vertices[0].y = offset[0] * m10 + offset[1] * m11 + y;
	vertices[1].x = offset[2] * m00 + offset[3] * m01 + x;
	vertices[1].y = offset[2] * m10 + offset[3] * m11 + y;
	vertices[2].x = offset[4] * m00 + offset[5] * m01 + x;
	vertices[2].y = offset[4] * m10 + offset[5] * m11 + y;
	vertices[3].x = offset[6] * m00 + offset[7] * m01 + x;
	vertices[3].y = offset[6] * m10 + offset[7] * m11 + y;
    
	vertices[4].x = offset[0] * m00 + offset[1] * m01 + x;
	vertices[4].y = offset[0] * m10 + offset[1] * m11 + y;
    
	vertices[5].x = offset[4] * m00 + offset[5] * m01 + x;
	vertices[5].y = offset[4] * m10 + offset[5] * m11 + y;
}

} /* namespace spine */
