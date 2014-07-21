#ifndef POSITION_H
#define	POSITION_H

class Position {
public:
	Position();
	Position(const Position& orig);
	virtual ~Position();
	void setX(float);
	void setY(float);
	void setXY(float, float);
	float getX();
	float getY();
private:
	float x, y;
};

#endif	/* POSITION_H */

