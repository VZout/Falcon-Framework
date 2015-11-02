/*
 * Time.h
 *
 *  Created on: May 29, 2015
 *      Author: bideb
 */

#ifndef FALCON_COMMON_TIME_H_
#define FALCON_COMMON_TIME_H_

namespace FF {
class Time {
private:
public:
	Time();
	virtual ~Time();

	void update();
	double lastTime;
	double fps;
	int nbFrames;
};
}

#endif /* FALCON_COMMON_TIME_H_ */
