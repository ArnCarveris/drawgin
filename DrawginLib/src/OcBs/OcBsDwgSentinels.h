/**
 *	@file
 *  @brief Defines OcBsDwgSentinels class
 *
 *  Used to encode the "sentinel" sections of drawing files
 */

/****************************************************************************
**
** This file is part of DrawGin library. A C++ framework to read and
** write .dwg files formats.
**
** Copyright (C) 2011, 2012, 2013 Paul Kohut.
** All rights reserved.
** Author: Paul Kohut (pkohut2@gmail.com)
**
** DrawGin library is free software; you can redistribute it and/or
** modify it under the terms of either:
**
**   * the GNU Lesser General Public License as published by the Free
**     Software Foundation; either version 3 of the License, or (at your
**     option) any later version.
**
**   * the GNU General Public License as published by the free
**     Software Foundation; either version 2 of the License, or (at your
**     option) any later version.
**
** or both in parallel, as here.
**
** DrawGin library is distributed in the hope that it will be useful,
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

#ifndef OcBsDwgSentinels_h__
#define OcBsDwgSentinels_h__

BEGIN_OCTAVARIUM_NS

extern const byte_t sentinelR13_R2000[];

extern const byte_t sentinelImageDataStart[];
extern const byte_t sentinelImageDataEnd[];

extern const byte_t sentinelHeaderVarsStart[];
extern const byte_t sentinelHeaderVarsEnd[];

extern const byte_t sentinelClassesSectionStart[];
extern const byte_t sentinelClassesSectionEnd[];

extern const byte_t sentinelSecondFileHeaderBegin[];
extern const byte_t sentinelSecondFileHeaderEnd[];

bool CompareSentinels(const byte_t * pSentinel1, const byte_t * pSentinel2);
bool CompareSentinels(const byte_t * pSentinel1, const bitcode::RC * pSentinel2);

END_OCTAVARIUM_NS

#endif // OcBsDwgSentinels_h__
