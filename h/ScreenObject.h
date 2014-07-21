#ifndef SCREENOBJECT_H
#define	SCREENOBJECT_H
#include <vector>
#include "Animation.h"

class ScreenObject {
	std::vector<Animation> animations;
	int posX, posY;
public:
	ScreenObject();
	ScreenObject(const ScreenObject& orig);
	virtual ~ScreenObject();
	void addAnimation(Animation animation);
private:

};

#endif	/* SCREENOBJECT_H */

