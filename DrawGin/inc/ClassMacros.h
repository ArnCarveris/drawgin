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

#ifndef ClassMacros_h__
#define ClassMacros_h__

#if OC_DEBUG_LIVING_OBJECTS && !defined(NDEBUG)
#include <set>
#endif

#define OC_DECLARE_BASE_CLASS(c) \
    public: \
    virtual const wchar_t * ClassName(void) { return L ## #c; }

#define OC_DECLARE_BASE_RX_CLASS(c) \
    OC_DECLARE_BASE_CLASS(c) \
    static OcApClassFactory<c, c> m_factory;

#define OC_DECLARE_CLASS(c, b) \
    OC_DECLARE_BASE_CLASS(c) \
    public: \
    virtual const wchar_t * BaseClassName(void) { return L ## #b; }
    

#define OC_DECLARE_RX_CLASS(c, b) \
    OC_DECLARE_CLASS(c, b) \
    static OcApClassFactory<c, b> m_factory;


#define OC_DEFINE_BASE_CLASS(b)

#define OC_DEFINE_CLASS(c, b) \
    OC_DEFINE_BASE_CLASS(c)


#define OC_DEFINE_RX_CLASS(c, b) \
    OcApClassFactory<c, b> c::m_factory(L ## # c);


#ifndef NDEBUG
#define INIT_OBJECT_NAME_FOR_DEBUG() \
    m_sObjectName = ClassName()
#else
#define INIT_OBJECT_NAME_FOR_DEBUG()
#endif


//#define OcPtr boost::intrusive_ptr
template<typename T>
struct OcPtr {
    typedef boost::intrusive_ptr<T> value_type;
};


#endif // ClassMacros_h__
