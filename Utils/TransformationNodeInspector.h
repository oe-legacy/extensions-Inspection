// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_TRANSFORMATION_NODE_INSPECTOR_H_
#define _OE_TRANSFORMATION_NODE_INSPECTOR_H_

#include <Utils/IInspector.h>

#include <Scene/TransformationNode.h>

namespace OpenEngine {
namespace Utils {

    ValueList Inspect(Scene::TransformationNode* node);

} // NS Utils
} // NS OpenEngine

#endif // _OE_TRANSFORMATION_NODE_INSPECTOR_H_
