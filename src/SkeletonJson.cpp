#include "SkeletonJson.h"
#include "AtlasAttachmentLoader.h"

namespace spine {

SkeletonJson::SkeletonJson (BaseAttachmentLoader *attachmentLoader) :
				BaseSkeletonJson(attachmentLoader) {
	flipY = true;
}

SkeletonJson::SkeletonJson (Atlas *atlas) :
				BaseSkeletonJson(new AtlasAttachmentLoader(atlas)) {
	flipY = true;
}

} /* namespace spine */
