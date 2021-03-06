/**
 *	@file
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

#include "OcCommon.h"
#include "OcError.h"
#include "OcBsStreamIn.h"
#include "OcBsDwgDataSection.h"

BEGIN_OCTAVARIUM_NS

OcBsDwgDataSection::OcBsDwgDataSection(int32_t dataSectionFilePosition, int32_t dataSectionSize)
    : m_dataSectionFilePosition(dataSectionFilePosition), m_dataSectionSize(dataSectionSize)
{
    VLOG_FUNC_NAME;
}


OcBsDwgDataSection::~OcBsDwgDataSection(void)
{
    VLOG_FUNC_NAME;
}

OcApp::ErrorStatus OcBsDwgDataSection::ReadDwg(OcBsStreamIn & in)
{
    VLOG_FUNC_NAME;
    VLOG(4) << "OcBsDwgDataSection::ReadDwg entered";

    // do some sanity checks before trying to read the object map
    if(m_dataSectionFilePosition == 0)
    {
        LOG(ERROR) << "Invalid file offset position for Data Section";
        return OcApp::eInvalidDataSectionOffset;
    }

    // set file position to the Object Map offset
    in.Seek(m_dataSectionFilePosition);

    if(in.Error() != OcApp::eOk)
    {
        LOG(ERROR) << "Error setting file position";
        return in.Error();
    }

    int16_t templateStringLength;
    BS_STREAMIN(bitcode::BS, in, templateStringLength, "template string length");

    if(templateStringLength)
    {
        // Spec section 20, Data section: AcDbTemplate
        // Encoded string bytes of the template description, use the
        // drawing's code page to encode the bytes);
        in.ReadRC(m_encodedString, templateStringLength);
        VLOG(4) << "template string (needs codepage encoding)" << m_encodedString;
    }

    uint16_t measurement;
    BS_STREAMIN(bitcode::BS, in, measurement, "measurement system variable");
    return OcApp::eOk;

}

std::string OcBsDwgDataSection::TemplateDescription() const
{
    return m_encodedString;
}

uint16_t OcBsDwgDataSection::Measurement() const
{
    return m_measurment;
}

END_OCTAVARIUM_NS