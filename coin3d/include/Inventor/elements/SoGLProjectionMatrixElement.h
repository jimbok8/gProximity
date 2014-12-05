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

#ifndef COIN_SOGLPROJECTIONMATRIXELEMENT_H
#define COIN_SOGLPROJECTIONMATRIXELEMENT_H

#include <Inventor/elements/SoProjectionMatrixElement.h>


class COIN_DLL_API SoGLProjectionMatrixElement : public SoProjectionMatrixElement
{
	typedef SoProjectionMatrixElement inherited;
	
	SO_ELEMENT_HEADER(SoGLProjectionMatrixElement);
public:
	static void initClass(void);
protected:
	virtual ~SoGLProjectionMatrixElement();
	
public:
	virtual void pop(SoState * state,
	                 const SoElement * prevTopElement);
	                 
protected:
	virtual void setElt(const SbMatrix & matrix);
	
private:
	void updategl();
};

#endif // !COIN_SOGLPROJECTIONMATRIXELEMENT_H
