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

	static void update();
};
	static double lastTime;
	static double fps;
	static int nbFrames;
}

#endif /* FALCON_COMMON_TIME_H_ */
