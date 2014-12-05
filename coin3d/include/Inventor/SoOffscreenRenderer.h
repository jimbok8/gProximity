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

#ifndef COIN_SOOFFSCREENRENDERER_H
#define COIN_SOOFFSCREENRENDERER_H

#include <Inventor/SbViewportRegion.h>
#include <Inventor/SbColor.h>
#include <Inventor/lists/SbList.h>
#include <Inventor/SbString.h>
#include <Inventor/SbName.h>

#include <stdio.h>

class SoBase;
class SoGLRenderAction;
class SoNode;
class SoPath;


class COIN_DLL_API SoOffscreenRenderer
{
public:
	enum Components
	{
		LUMINANCE = 1,
		LUMINANCE_TRANSPARENCY = 2,
		RGB = 3,
		RGB_TRANSPARENCY = 4
	};
	
	SoOffscreenRenderer(const SbViewportRegion & viewportregion);
	SoOffscreenRenderer(SoGLRenderAction * action);
	~SoOffscreenRenderer();
	
	static float getScreenPixelsPerInch(void);
	static SbVec2s getMaximumResolution(void);
	void setComponents(const Components components);
	Components getComponents(void) const;
	void setViewportRegion(const SbViewportRegion & region);
	const SbViewportRegion & getViewportRegion(void) const;
	void setBackgroundColor(const SbColor & color);
	const SbColor & getBackgroundColor(void) const;
	void setGLRenderAction(SoGLRenderAction * action);
	SoGLRenderAction * getGLRenderAction(void) const;
	SbBool render(SoNode * scene);
	SbBool render(SoPath * scene);
	unsigned char * getBuffer(void) const;
	
	SbBool writeToRGB(FILE * fp) const;
	SbBool writeToPostScript(FILE * fp) const;
	SbBool writeToPostScript(FILE * fp, const SbVec2f & printsize) const;
	
	SbBool writeToRGB(const char * filename) const;
	SbBool writeToPostScript(const char * filename) const;
	SbBool writeToPostScript(const char * filename, const SbVec2f & printsize) const;
	
	SbBool isWriteSupported(const SbName & filetypeextension) const;
	int getNumWriteFiletypes(void) const;
	void getWriteFiletypeInfo(const int idx,
	                          SbList <SbName> & extlist,
	                          SbString & fullname,
	                          SbString & description);
	SbBool writeToFile(const SbString & filename, const SbName & filetypeextension) const;
	
private:
	SbBool renderFromBase(SoBase * base);
	void convertBuffer(void);
	
	SbViewportRegion viewport;
	SbColor backgroundcolor;
	Components components;
	SoGLRenderAction * renderaction;
	SbBool didallocaction;
	class SoOffscreenInternalData * internaldata;
	unsigned char * buffer;
};


#endif // !COIN_SOOFFSCREENRENDERER_H
