/****************************************************************************
**
** This file is part of DrawGin library. A C++ framework to read and
** write .dwg files formats.
**
** Copyright (C) 2011 Paul Kohut.
** All rights reserved.
** Author: Paul Kohut (pkohut2@gmail.com)
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 3 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** DrawGin project hosted at: http://code.google.com/p/drawgin/
**
** Authors:
**      pk          Paul Kohut <pkohut2@gmail.com>
**
****************************************************************************/

#ifndef OcBsDwgObjectMap_h__
#define OcBsDwgObjectMap_h__

#include "DwgInArchive.h"

BEGIN_OCTAVARIUM_NS

class OcDbDatabase;

class OcBsDwgObjectMap
{
public:
    OcBsDwgObjectMap(int32_t objMapFilePos, int32_t objMapSize);
    virtual ~OcBsDwgObjectMap(void);

    OcApp::ErrorStatus DecodeObjects(DwgInArchive& ar, OcDbDatabase *& pDb);

private:
    friend DwgInArchive& operator>>(DwgInArchive& ar, OcBsDwgObjectMap & imgData);
    OcApp::ErrorStatus DecodeData(DwgInArchive& ar);

    std::vector<OcBsDwgObjectMapItem> m_objMapItems;

    int32_t m_objMapFilePos;
    int32_t m_objMapSize;
};


END_OCTAVARIUM_NS

#endif // OcBsObjectMap_h__

