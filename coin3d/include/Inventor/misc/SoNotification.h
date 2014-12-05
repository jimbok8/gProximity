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

#ifndef COIN_SONOTIFICATION_H
#define COIN_SONOTIFICATION_H

#include <Inventor/SbBasic.h>
#include <Inventor/system/inttypes.h>
#include <stdio.h>

class SoBase;


class COIN_DLL_API SoNotRec
{
public:
	enum Type
	{
		CONTAINER,
		PARENT,
		SENSOR,
		FIELD,
		ENGINE,
		INTERP
	};
	
	SoNotRec(SoBase * const notifbase);
	void setType(const SoNotRec::Type type);
	SoBase * getBase(void) const;
	SoNotRec::Type getType(void) const;
	const SoNotRec * getPrevious(void) const;
	void setPrevious(const SoNotRec * const prev);
	void print(FILE * const file) const;
	
private:
	Type type;
	SoBase * base;
	const SoNotRec * prev;
};

class SoEngineOutput;
class SoField;
class SoVRMLInterpOutput;

class COIN_DLL_API SoNotList
{
public:
	SoNotList(void);
	SoNotList(const SoNotList * nl);
	
	void append(SoNotRec * const rec);
	void append(SoNotRec * const rec, SoField * const field);
	void append(SoNotRec * const rec, SoVRMLInterpOutput * const interpout);
	void append(SoNotRec * const rec, SoEngineOutput * const engineout);
	void setLastType(const SoNotRec::Type type);
	SoNotRec * getFirstRec(void) const;
	SoNotRec * getLastRec(void) const;
	SoNotRec * getFirstRecAtNode(void) const;
	SoField * getLastField(void) const;
	SoVRMLInterpOutput * getLastInterpOutput(void) const;
	SoEngineOutput * getLastEngineOutput(void) const;
	uint32_t getTimeStamp(void) const;
	
	void print(FILE * const file = stdout) const;
	
private:
	SoNotRec * head;
	SoNotRec * tail;
	SoNotRec * firstnoderec;
	SoField * lastfield;
	SoEngineOutput * lastengine;
	SoVRMLInterpOutput * lastinterp;
	uint32_t stamp;
};

#endif // !COIN_SONOTIFICATION_H
