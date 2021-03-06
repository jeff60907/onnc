//===- Pipe.cpp -----------------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include <onnc/Support/Pipe.h>
#include <onnc/Config/Config.h>

// Include the truly platform-specific parts. 
#if defined(ONNC_ON_UNIX)
#include "Unix/Pipe.inc"
#endif
#if defined(ONNC_ON_WIN32)
#include "Windows/Pipe.inc"
#endif
#if defined(ONNC_ON_DRAGON)
#include "Dragon/Pipe.inc"
#endif
