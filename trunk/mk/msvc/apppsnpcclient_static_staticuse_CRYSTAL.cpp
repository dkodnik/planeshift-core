// This file is automatically generated.
#include "cssysdef.h"
#include "csutil/scf.h"

// Put static linking stuff into own section.
// The idea is that this allows the section to be swapped out but not
// swapped in again b/c something else in it was needed.
#if !defined(CS_DEBUG) && defined(CS_COMPILER_MSVC)
#pragma const_seg(".CSmetai")
#pragma comment(linker, "/section:.CSmetai,r")
#pragma code_seg(".CSmeta")
#pragma comment(linker, "/section:.CSmeta,er")
#pragma comment(linker, "/merge:.CSmetai=.CSmeta")
#endif
struct _static_use_CRYSTAL { _static_use_CRYSTAL (); };
_static_use_CRYSTAL::_static_use_CRYSTAL () {}
SCF_USE_STATIC_PLUGIN(bindoc)
SCF_USE_STATIC_PLUGIN(csddsimg)
SCF_USE_STATIC_PLUGIN(csfont)
SCF_USE_STATIC_PLUGIN(csopcode)
SCF_USE_STATIC_PLUGIN(csparser)
SCF_USE_STATIC_PLUGIN(cspngimg)
SCF_USE_STATIC_PLUGIN(cssynldr)
SCF_USE_STATIC_PLUGIN(cstgaimg)
SCF_USE_STATIC_PLUGIN(dsplex)
SCF_USE_STATIC_PLUGIN(dynavis)
SCF_USE_STATIC_PLUGIN(emit)
SCF_USE_STATIC_PLUGIN(emitldr)
SCF_USE_STATIC_PLUGIN(engine)
SCF_USE_STATIC_PLUGIN(engseq)
SCF_USE_STATIC_PLUGIN(fontplex)
SCF_USE_STATIC_PLUGIN(freefnt2)
SCF_USE_STATIC_PLUGIN(frustvis)
SCF_USE_STATIC_PLUGIN(genmesh)
SCF_USE_STATIC_PLUGIN(gl3d)
SCF_USE_STATIC_PLUGIN(glshader_fixed)
SCF_USE_STATIC_PLUGIN(gmeshanim)
SCF_USE_STATIC_PLUGIN(gmeshldr)
SCF_USE_STATIC_PLUGIN(imgplex)
SCF_USE_STATIC_PLUGIN(null2d)
SCF_USE_STATIC_PLUGIN(null3d)
SCF_USE_STATIC_PLUGIN(nullmesh)
SCF_USE_STATIC_PLUGIN(nullmeshldr)
SCF_USE_STATIC_PLUGIN(particles)
SCF_USE_STATIC_PLUGIN(particlesldr)
SCF_USE_STATIC_PLUGIN(ptanimimg)
SCF_USE_STATIC_PLUGIN(rendloop_loader)
SCF_USE_STATIC_PLUGIN(rendstep_std)
SCF_USE_STATIC_PLUGIN(reporter)
SCF_USE_STATIC_PLUGIN(sequence)
SCF_USE_STATIC_PLUGIN(shadermgr)
SCF_USE_STATIC_PLUGIN(shaderweaver)
SCF_USE_STATIC_PLUGIN(sndmanager)
SCF_USE_STATIC_PLUGIN(simpleformer)
SCF_USE_STATIC_PLUGIN(simpleformerldr)
SCF_USE_STATIC_PLUGIN(spr2d)
SCF_USE_STATIC_PLUGIN(spr3d)
SCF_USE_STATIC_PLUGIN(spr3dbin)
SCF_USE_STATIC_PLUGIN(spr3dldr)
SCF_USE_STATIC_PLUGIN(sprcal3d)
SCF_USE_STATIC_PLUGIN(sprcal3dldr)
SCF_USE_STATIC_PLUGIN(stdrep)
SCF_USE_STATIC_PLUGIN(vfs)
SCF_USE_STATIC_PLUGIN(xmlread)
SCF_USE_STATIC_PLUGIN(xmlshader)

