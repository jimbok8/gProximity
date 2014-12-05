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

#ifndef COIN_SOBLINKER_H
#define COIN_SOBLINKER_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoSwitch.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoSFBool.h>

class SoSensor;
class SoOneShotSensor;
class SoTimeCounter;

class COIN_DLL_API SoBlinker : public SoSwitch
{
	typedef SoSwitch inherited;
	
	SO_NODE_HEADER(SoBlinker);
	
public:
	static void initClass(void);
	SoBlinker(void);
	
	SoSFFloat speed;
	SoSFBool on;
	
	virtual void getBoundingBox(SoGetBoundingBoxAction * action);
	virtual void write(SoWriteAction * action);
	
protected:
	virtual ~SoBlinker();
	virtual void notify(SoNotList * nl);
	
private:
	virtual SoNode * copy(SbBool copyconnections = FALSE) const;
	void deconnectInternalEngine(void);
	void reconnectInternalEngine(void);
	
	SoTimeCounter * counter;
};

#endif // !COIN_SOBLINKER_H
