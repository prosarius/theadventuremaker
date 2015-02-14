#ifndef SCREENITEM_H
#define	SCREENITEM_H

#include <vector>
#include <string>

#include "ScreenObject.h"
#include "Animation.h"

using namespace std;
class Animation;
class ScreenItem : public ScreenObject {
public:
	using ScreenObject::ScreenObject;
};

#endif	/* SCREENITEM_H */

