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

#ifndef COIN_SBSTRINGLIST_H
#define COIN_SBSTRINGLIST_H

#include <Inventor/lists/SbList.h>

class SbString;


class SbStringList : public SbList<SbString *>
{
public:
	SbStringList(void) : SbList<SbString *>() { }
	SbStringList(const int sizehint) : SbList<SbString *>(sizehint) { }
	SbStringList(const SbStringList & l) : SbList<SbString *>(l) { }
	
	SbString * get(const int index) const
	{
		return (*this)[index];
	}
	void set(const int index, SbString * const item)
	{
		(*this)[index] = item;
	}
};

#endif // !COIN_SBSTRINGLIST_H
