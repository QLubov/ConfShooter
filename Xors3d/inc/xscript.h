/**************************************************************************
 *                                                                        *
 * xScript official header for C\C++. CopyRight 2009-2010 XorsTeam        *
 * WWW: http://www.xors3d.com                                             *
 * E-Mail: support@xors3d.com                                             *
 *                                                                        *
 * Xors3D headers  is distributed in the hope that it will be useful, but *
 * WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility *
 * to anyone for the  consequences of using  it or for  whether it serves *
 * any particular purpose or works at all, unless he says so in writing.  *
 *                                                                        *
 **************************************************************************/
#ifndef _XSCRIPT_H_
#define _XSCRIPT_H_

// functions declaration & call types
#define XSDECL extern "C" __declspec(dllexport)
#define XSCALL _stdcall 

// types defines
typedef int Script;

XSDECL Script		XSCALL xLoadScript(const char * fileName);
XSDECL bool			XSCALL xExecuteScript(Script script, const char * entryPoint = "int main()");
XSDECL void			XSCALL xDeleteScript(Script script);
XSDECL void			XSCALL xSetIntegerVariable(Script script, const char * varName, int value);
XSDECL int			XSCALL xGetIntegerVariable(Script script, const char * varName);
XSDECL void			XSCALL xSetFloatVariable(Script script, const char * varName, float value);
XSDECL float		XSCALL xGetFloatVariable(Script script, const char * varName);
XSDECL void			XSCALL xSetStringVariable(Script script, const char *  varName, const char * value);
XSDECL const char *	XSCALL xGetStringVariable(Script script, const char * varName);
XSDECL void			XSCALL xRegisterFunction(const char * decl, void * funcAddr);
XSDECL void			XSCALL xSetIntegerArg(int index, int value);
XSDECL void			XSCALL xSetFloatArg(int index, float value);
XSDECL void			XSCALL xSetStringArg(int index, const char * value);
XSDECL int			XSCALL xGetIntegerReturn();
XSDECL float		XSCALL xGetFloatReturn();
XSDECL const char *	XSCALL xGetStringReturn();
XSDECL Script		XSCALL xCreateScript(void * data, int length);

#endif