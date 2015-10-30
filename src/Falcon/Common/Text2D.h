/*
 * Text2D.h
 *
 *  Created on: Sep 23, 2015
 *      Author: bideb
 */

#ifndef FALCON_COMMON_TEXT2D_H_
#define FALCON_COMMON_TEXT2D_H_

void initText2D(const char * texturePath);
void printText2D(const char * text, int x, int y, int size);
void cleanupText2D();

#endif /* FALCON_COMMON_TEXT2D_H_ */
