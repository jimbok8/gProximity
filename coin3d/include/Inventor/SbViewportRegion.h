/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2002 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

#ifndef COIN_SBVIEWPORTREGION_H
#define COIN_SBVIEWPORTREGION_H

#include <stdio.h>
#include <Inventor/SbVec2s.h>
#include <Inventor/SbVec2f.h>

class COIN_DLL_API SbViewportRegion
{
public:
	SbViewportRegion(void);
	SbViewportRegion(short width, short height);
	SbViewportRegion(SbVec2s winSize);
	SbViewportRegion(const SbViewportRegion & vpReg);
	
	void setWindowSize(short width, short height);
	void setWindowSize(SbVec2s winSize);
	void setViewport(float left, float bottom,
	                 float width, float height);
	void setViewport(SbVec2f origin, SbVec2f size);
	void setViewportPixels(short left, short bottom,
	                       short width, short height);
	void setViewportPixels(SbVec2s origin, SbVec2s size);
	const SbVec2s & getWindowSize(void) const;
	const SbVec2f & getViewportOrigin(void) const;
	const SbVec2s & getViewportOriginPixels(void) const;
	const SbVec2f & getViewportSize(void) const;
	const SbVec2s & getViewportSizePixels(void) const;
	float getViewportAspectRatio(void) const;
	void scaleWidth(float ratio);
	void scaleHeight(float ratio);
	void setPixelsPerInch(float ppi);
	float getPixelsPerInch(void) const;
	float getPixelsPerPoint(void) const;
	friend COIN_DLL_API int operator ==(const SbViewportRegion & reg1,
	                                    const SbViewportRegion & reg2);
	                                    
	void print(FILE * file) const;
	
private:
	SbVec2s winsize;
	SbVec2f vporigin;
	SbVec2f vpsize;
	SbVec2s vporigin_s;
	SbVec2s vpsize_s;
	float pixperinch;
};

COIN_DLL_API int operator ==(const SbViewportRegion & reg1, const SbViewportRegion & reg2);

#endif // !COIN_SBVIEWPORTREGION_H
