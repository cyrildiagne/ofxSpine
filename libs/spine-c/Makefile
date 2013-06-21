# super basic makefile to compile spine-c in a macosx static lib (32 & 64 bits)
# by kikko_fr

CC = gcc
ODIR = obj
SDIR = src
LDIR = lib/osx
IDIR = include
INC = -I$(IDIR)

CFLAGS =

libspine32: ARCH = i386
libspine64: ARCH = x86_64

_OBJS = Animation.o AnimationState.o AnimationStateData.o \
		Atlas.o AtlasAttachmentLoader.o Attachment.o \
		AttachmentLoader.o Bone.o BoneData.o \
		Json.o RegionAttachment.o Skeleton.o \
		SkeletonData.o SkeletonJson.o Skin.o \
		Slot.o SlotData.o extension.o
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -arch $(ARCH) $(INC) -o $@ $< $(CFLAGS)

libspine32: $(OBJS)
	libtool -static -arch_only i386 -o $(LDIR)/$@.a $^

libspine64: $(OBJS)
	libtool -static -arch_only x86_64 -o $(LDIR)/$@.a $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT)