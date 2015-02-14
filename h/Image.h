#ifndef IMAGE_H
#define	IMAGE_H

#include <string>

#include "Animation.h"

class Animation;
class Image {
public:
	Image(std::string texturePath);
	void addAnimation(Animation* animation);
	//void removeAnimation(const Animation* animation);
private:
	std::vector<Animation*> animations;
	std::string texturePath;
};

#endif	/* IMAGE_H */

