/* 
 * File:   ScreenLayer.h
 * Author: morion
 *
 * Created on 30. März 2014, 20:19
 */

#ifndef SCREENLAYER_H
#define	SCREENLAYER_H
#include <vector>
#include "Character.h"
#include "ScreenItem.h"
#include "Image.h"
class ScreenLayer {
public:
	ScreenLayer();
	ScreenLayer(const ScreenLayer& orig);
	virtual ~ScreenLayer();
	void addCharacter(Character* character);
	void addItem(ScreenItem* item);
private:
	Image background;
	std::vector<Character*> characters;
	std::vector<ScreenItem*> items;	
};

#endif	/* SCREENLAYER_H */

