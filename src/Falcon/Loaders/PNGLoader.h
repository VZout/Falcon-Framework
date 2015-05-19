/*
 * PNGLoader.h
 *
 *  Created on: May 19, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef FALCON_COMMON_PNGLOADER_H_
#define FALCON_COMMON_PNGLOADER_H_

#include <string>
#include "TextureData.h"

namespace FF {
class PNGLoader {
public:
	static TextureData loadPNG(const char* fileName);
};
}

#endif /* FALCON_COMMON_PNGLOADER_H_ */
