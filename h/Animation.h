#ifndef ANIMATION_H
#define	ANIMATION_H
#include <string>

class Animation {
public:
	Animation(std::string path);
	Animation(const Animation& orig);
	virtual ~Animation();
private:
	std::string path;

};

#endif	/* ANIMATION_H */

