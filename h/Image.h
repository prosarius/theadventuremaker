#ifndef IMAGE_H
#define	IMAGE_H
#include <string>
#include "Animation.h"

class Animation;
class Image {
public:
	Image(std::string path);
	void addAnimation(Animation* animation);
	//void removeAnimation(const Animation* animation);
private:
	std::vector<Animation*> animations;
	std::string path;
};

#endif	/* IMAGE_H */

