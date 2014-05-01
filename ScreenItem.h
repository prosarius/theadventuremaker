/* 
 * File:   Item.h
 * Author: morion
 *
 * Created on 30. März 2014, 20:15
 */

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

