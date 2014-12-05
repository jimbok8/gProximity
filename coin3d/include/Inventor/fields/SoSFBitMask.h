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

#ifndef COIN_SOSFBITMASK_H
#define COIN_SOSFBITMASK_H

#include <Inventor/fields/SoSFEnum.h>


class COIN_DLL_API SoSFBitMask : public SoSFEnum
{
	typedef SoSFEnum inherited;
	
	SO_SFIELD_DERIVED_HEADER(SoSFBitMask, int, int);
	
public:
	static void initClass(void);
	
	// FIXME: there's a bug in Doxygen (at least with version 1.2.9)
	// which causes the following statement to be regarded as a member
	// variable. Remove this workaround when the bug has been
	// fixed. 20011125 mortene.
#ifndef DOXYGEN_SKIP_THIS
	friend class SoMFBitMask; // For readValue() & writeValue().
#endif // DOXYGEN_SKIP_THIS
};

#endif // !COIN_SOSFBITMASK_H
