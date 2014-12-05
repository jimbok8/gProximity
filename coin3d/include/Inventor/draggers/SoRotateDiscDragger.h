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

#ifndef COIN_SOROTATEDISCDRAGGER_H
#define COIN_SOROTATEDISCDRAGGER_H

#include <Inventor/draggers/SoDragger.h>
#include <Inventor/fields/SoSFRotation.h>

class SoSensor;
class SoFieldSensor;
class SbPlaneProjector;


class COIN_DLL_API SoRotateDiscDragger : public SoDragger
{
	typedef SoDragger inherited;
	
	SO_KIT_HEADER(SoRotateDiscDragger);
	
	SO_KIT_CATALOG_ENTRY_HEADER(feedback);
	SO_KIT_CATALOG_ENTRY_HEADER(feedbackActive);
	SO_KIT_CATALOG_ENTRY_HEADER(feedbackSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(rotator);
	SO_KIT_CATALOG_ENTRY_HEADER(rotatorActive);
	SO_KIT_CATALOG_ENTRY_HEADER(rotatorSwitch);
	
	
public:
	static void initClass(void);
	SoRotateDiscDragger(void);
	
	SoSFRotation rotation;
	
protected:
	~SoRotateDiscDragger();
	virtual SbBool setUpConnections(SbBool onoff, SbBool doitalways = FALSE);
	
	static void startCB(void * f, SoDragger * d);
	static void motionCB(void * f, SoDragger * d);
	static void doneCB(void * f, SoDragger * d);
	static void fieldSensorCB(void * f, SoSensor * s);
	static void valueChangedCB(void * f, SoDragger * d);
	
	void dragStart(void);
	void drag(void);
	void dragFinish(void);
	
	SoFieldSensor * fieldSensor;
	SbPlaneProjector * planeProj;
};

#endif // !COIN_SOROTATEDISCDRAGGER_H
