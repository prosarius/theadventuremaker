/* 
 * File:   ScreenLayer.h
 * Author: morion
 *
 * Created on 30. März 2014, 20:19
 */

#ifndef SCREENLAYER_H
#define	SCREENLAYER_H
#include <vector>

class ScreenLayer {
public:
	ScreenLayer();
	ScreenLayer(const ScreenLayer& orig);
	virtual ~ScreenLayer();
	void addCharacter(Character* character);
	void addItem(ScreenItem* item);
private:
	Image background;
	vector<Character*> characters;
	vector<ScreenItem*> items;	
};

#endif	/* SCREENLAYER_H */

