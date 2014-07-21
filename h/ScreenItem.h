#ifndef ITEM_H
#define	ITEM_H
#include "ScreenObject.h"

class ScreenItem : public ScreenObject {
public:
	ScreenItem();
	ScreenItem(const ScreenItem& orig);
	virtual ~ScreenItem();
private:

};

#endif	/* ITEM_H */

