#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Pointer
#include <tardis/Pointer.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_haxegoruntime_init
#include <tardis/_Go/Go_haxegoruntime_init.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_main_init
#include <tardis/_Go/Go_main_init.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_main_main
#include <tardis/_Go/Go_main_main.h>
#endif
namespace tardis{

Void Go_obj::__construct()
{
	return null();
}

Go_obj::~Go_obj() { }

Dynamic Go_obj::__CreateEmpty() { return  new Go_obj; }
hx::ObjectPtr< Go_obj > Go_obj::__new()
{  hx::ObjectPtr< Go_obj > result = new Go_obj();
	result->__construct();
	return result;}

Dynamic Go_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_obj > result = new Go_obj();
	result->__construct();
	return result;}

::String Go_obj::Platform( ){
	HX_STACK_PUSH("Go::Platform","tardis/Go.hx",8471);
	HX_STACK_LINE(8471)
	return HX_CSTRING("cpp");
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_obj,Platform,return )

int Go_obj::main_MOUSE_DOWN;

int Go_obj::main_MOUSE_UP;

int Go_obj::main_MOUSE_MOVE;

int Go_obj::utf8_RuneSelf;

int Go_obj::utf8_RuneError;

int Go_obj::utf8_MaxRune;

int Go_obj::utf8_UTFMax;

::tardis::Pointer Go_obj::haxegoruntime_init_36_guard;

::tardis::Pointer Go_obj::haxegoruntime_ZiLen;

::tardis::Pointer Go_obj::main_init_36_guard;

::tardis::Pointer Go_obj::main_mouseEvents;

::tardis::Pointer Go_obj::utf16_init_36_guard;

::tardis::Pointer Go_obj::utf8_init_36_guard;

::tardis::Pointer Go_obj::hxutil_init_36_guard;

bool Go_obj::doneInit;

Void Go_obj::init( ){
{
		HX_STACK_PUSH("Go::init","tardis/Go.hx",8507);
		HX_STACK_LINE(8508)
		::tardis::Go_obj::doneInit = true;
		HX_STACK_LINE(8509)
		int gr = ::tardis::Scheduler_obj::makeGoroutine();		HX_STACK_VAR(gr,"gr");
		HX_STACK_LINE(8510)
		if (((gr != (int)0))){
			HX_STACK_LINE(8510)
			hx::Throw (HX_CSTRING("non-zero goroutine number in init"));
		}
		HX_STACK_LINE(8511)
		::tardis::_Go::Go_haxegoruntime_init _sfgr = hx::TCast< ::tardis::_Go::Go_haxegoruntime_init >::cast(::tardis::_Go::Go_haxegoruntime_init_obj::__new(gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sfgr,"_sfgr");
		HX_STACK_LINE(8512)
		while((_sfgr->_incomplete)){
			HX_STACK_LINE(8512)
			::tardis::Scheduler_obj::runAll();
		}
		HX_STACK_LINE(8513)
		::tardis::_Go::Go_main_init _sf = hx::TCast< ::tardis::_Go::Go_main_init >::cast(::tardis::_Go::Go_main_init_obj::__new(gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(8514)
		while((_sf->_incomplete)){
			HX_STACK_LINE(8514)
			::tardis::Scheduler_obj::runAll();
		}
		HX_STACK_LINE(8515)
		::tardis::Scheduler_obj::doneInit = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_obj,init,(void))

Void Go_obj::main( ){
{
		HX_STACK_PUSH("Go::main","tardis/Go.hx",8518);
		HX_STACK_LINE(8519)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(8519)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(8519)
		::tardis::_Go::Go_main_main _sf = hx::TCast< ::tardis::_Go::Go_main_main >::cast(::tardis::_Go::Go_main_main_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(8519)
		while((_sf->_incomplete)){
			HX_STACK_LINE(8519)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_obj,main,(void))

::String Go_obj::CPos( int pos){
	HX_STACK_PUSH("Go::CPos","tardis/Go.hx",8521);
	HX_STACK_ARG(pos,"pos");
	HX_STACK_LINE(8522)
	::String prefix = HX_CSTRING("");		HX_STACK_VAR(prefix,"prefix");
	HX_STACK_LINE(8523)
	if (((pos == (int)0))){
		HX_STACK_LINE(8523)
		return HX_CSTRING("(pogo.NoPosHash)");
	}
	HX_STACK_LINE(8524)
	if (((pos < (int)0))){
		HX_STACK_LINE(8524)
		pos = -(pos);
		HX_STACK_LINE(8524)
		prefix = HX_CSTRING("near ");
	}
	HX_STACK_LINE(8525)
	if (((pos > (int)976))){
		HX_STACK_LINE(8525)
		return ((prefix + HX_CSTRING("/Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:")) + ::Std_obj::string((pos - (int)976)));
	}
	else{
		HX_STACK_LINE(8526)
		if (((pos > (int)533))){
			HX_STACK_LINE(8526)
			return ((prefix + HX_CSTRING("/usr/local/go/src/pkg/unicode/utf8/utf8.go:")) + ::Std_obj::string((pos - (int)533)));
		}
		else{
			HX_STACK_LINE(8527)
			if (((pos > (int)425))){
				HX_STACK_LINE(8527)
				return ((prefix + HX_CSTRING("/usr/local/go/src/pkg/unicode/utf16/utf16.go:")) + ::Std_obj::string((pos - (int)425)));
			}
			else{
				HX_STACK_LINE(8528)
				if (((pos > (int)45))){
					HX_STACK_LINE(8528)
					return ((prefix + HX_CSTRING("goruntime.go:")) + ::Std_obj::string((pos - (int)45)));
				}
				else{
					HX_STACK_LINE(8529)
					if (((pos > (int)0))){
						HX_STACK_LINE(8529)
						return ((prefix + HX_CSTRING("main.go:")) + ::Std_obj::string(pos));
					}
					else{
						HX_STACK_LINE(8530)
						return ((HX_CSTRING("(invalid pogo.PosHash:") + ::Std_obj::string(pos)) + HX_CSTRING(")"));
					}
				}
			}
		}
	}
	HX_STACK_LINE(8525)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_obj,CPos,return )


Go_obj::Go_obj()
{
}

void Go_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go);
	HX_MARK_END_CLASS();
}

void Go_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Go_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"CPos") ) { return CPos_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Platform") ) { return Platform_dyn(); }
		if (HX_FIELD_EQ(inName,"doneInit") ) { return doneInit; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"utf8_UTFMax") ) { return utf8_UTFMax; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"utf8_MaxRune") ) { return utf8_MaxRune; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"main_MOUSE_UP") ) { return main_MOUSE_UP; }
		if (HX_FIELD_EQ(inName,"utf8_RuneSelf") ) { return utf8_RuneSelf; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"utf8_RuneError") ) { return utf8_RuneError; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"main_MOUSE_DOWN") ) { return main_MOUSE_DOWN; }
		if (HX_FIELD_EQ(inName,"main_MOUSE_MOVE") ) { return main_MOUSE_MOVE; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"main_mouseEvents") ) { return main_mouseEvents; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"main_init_36_guard") ) { return main_init_36_guard; }
		if (HX_FIELD_EQ(inName,"utf8_init_36_guard") ) { return utf8_init_36_guard; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"haxegoruntime_ZiLen") ) { return haxegoruntime_ZiLen; }
		if (HX_FIELD_EQ(inName,"utf16_init_36_guard") ) { return utf16_init_36_guard; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"hxutil_init_36_guard") ) { return hxutil_init_36_guard; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"haxegoruntime_init_36_guard") ) { return haxegoruntime_init_36_guard; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"doneInit") ) { doneInit=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"utf8_UTFMax") ) { utf8_UTFMax=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"utf8_MaxRune") ) { utf8_MaxRune=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"main_MOUSE_UP") ) { main_MOUSE_UP=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"utf8_RuneSelf") ) { utf8_RuneSelf=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"utf8_RuneError") ) { utf8_RuneError=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"main_MOUSE_DOWN") ) { main_MOUSE_DOWN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"main_MOUSE_MOVE") ) { main_MOUSE_MOVE=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"main_mouseEvents") ) { main_mouseEvents=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"main_init_36_guard") ) { main_init_36_guard=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"utf8_init_36_guard") ) { utf8_init_36_guard=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"haxegoruntime_ZiLen") ) { haxegoruntime_ZiLen=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"utf16_init_36_guard") ) { utf16_init_36_guard=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"hxutil_init_36_guard") ) { hxutil_init_36_guard=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"haxegoruntime_init_36_guard") ) { haxegoruntime_init_36_guard=inValue.Cast< ::tardis::Pointer >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Platform"),
	HX_CSTRING("main_MOUSE_DOWN"),
	HX_CSTRING("main_MOUSE_UP"),
	HX_CSTRING("main_MOUSE_MOVE"),
	HX_CSTRING("utf8_RuneSelf"),
	HX_CSTRING("utf8_RuneError"),
	HX_CSTRING("utf8_MaxRune"),
	HX_CSTRING("utf8_UTFMax"),
	HX_CSTRING("haxegoruntime_init_36_guard"),
	HX_CSTRING("haxegoruntime_ZiLen"),
	HX_CSTRING("main_init_36_guard"),
	HX_CSTRING("main_mouseEvents"),
	HX_CSTRING("utf16_init_36_guard"),
	HX_CSTRING("utf8_init_36_guard"),
	HX_CSTRING("hxutil_init_36_guard"),
	HX_CSTRING("doneInit"),
	HX_CSTRING("init"),
	HX_CSTRING("main"),
	HX_CSTRING("CPos"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Go_obj::main_MOUSE_DOWN,"main_MOUSE_DOWN");
	HX_MARK_MEMBER_NAME(Go_obj::main_MOUSE_UP,"main_MOUSE_UP");
	HX_MARK_MEMBER_NAME(Go_obj::main_MOUSE_MOVE,"main_MOUSE_MOVE");
	HX_MARK_MEMBER_NAME(Go_obj::utf8_RuneSelf,"utf8_RuneSelf");
	HX_MARK_MEMBER_NAME(Go_obj::utf8_RuneError,"utf8_RuneError");
	HX_MARK_MEMBER_NAME(Go_obj::utf8_MaxRune,"utf8_MaxRune");
	HX_MARK_MEMBER_NAME(Go_obj::utf8_UTFMax,"utf8_UTFMax");
	HX_MARK_MEMBER_NAME(Go_obj::haxegoruntime_init_36_guard,"haxegoruntime_init_36_guard");
	HX_MARK_MEMBER_NAME(Go_obj::haxegoruntime_ZiLen,"haxegoruntime_ZiLen");
	HX_MARK_MEMBER_NAME(Go_obj::main_init_36_guard,"main_init_36_guard");
	HX_MARK_MEMBER_NAME(Go_obj::main_mouseEvents,"main_mouseEvents");
	HX_MARK_MEMBER_NAME(Go_obj::utf16_init_36_guard,"utf16_init_36_guard");
	HX_MARK_MEMBER_NAME(Go_obj::utf8_init_36_guard,"utf8_init_36_guard");
	HX_MARK_MEMBER_NAME(Go_obj::hxutil_init_36_guard,"hxutil_init_36_guard");
	HX_MARK_MEMBER_NAME(Go_obj::doneInit,"doneInit");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Go_obj::main_MOUSE_DOWN,"main_MOUSE_DOWN");
	HX_VISIT_MEMBER_NAME(Go_obj::main_MOUSE_UP,"main_MOUSE_UP");
	HX_VISIT_MEMBER_NAME(Go_obj::main_MOUSE_MOVE,"main_MOUSE_MOVE");
	HX_VISIT_MEMBER_NAME(Go_obj::utf8_RuneSelf,"utf8_RuneSelf");
	HX_VISIT_MEMBER_NAME(Go_obj::utf8_RuneError,"utf8_RuneError");
	HX_VISIT_MEMBER_NAME(Go_obj::utf8_MaxRune,"utf8_MaxRune");
	HX_VISIT_MEMBER_NAME(Go_obj::utf8_UTFMax,"utf8_UTFMax");
	HX_VISIT_MEMBER_NAME(Go_obj::haxegoruntime_init_36_guard,"haxegoruntime_init_36_guard");
	HX_VISIT_MEMBER_NAME(Go_obj::haxegoruntime_ZiLen,"haxegoruntime_ZiLen");
	HX_VISIT_MEMBER_NAME(Go_obj::main_init_36_guard,"main_init_36_guard");
	HX_VISIT_MEMBER_NAME(Go_obj::main_mouseEvents,"main_mouseEvents");
	HX_VISIT_MEMBER_NAME(Go_obj::utf16_init_36_guard,"utf16_init_36_guard");
	HX_VISIT_MEMBER_NAME(Go_obj::utf8_init_36_guard,"utf8_init_36_guard");
	HX_VISIT_MEMBER_NAME(Go_obj::hxutil_init_36_guard,"hxutil_init_36_guard");
	HX_VISIT_MEMBER_NAME(Go_obj::doneInit,"doneInit");
};

Class Go_obj::__mClass;

void Go_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go"), hx::TCanCast< Go_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_obj::__boot()
{
	main_MOUSE_DOWN= (int)2;
	main_MOUSE_UP= (int)1;
	main_MOUSE_MOVE= (int)3;
	utf8_RuneSelf= (int)128;
	utf8_RuneError= (int)65533;
	utf8_MaxRune= (int)1114111;
	utf8_UTFMax= (int)4;
	haxegoruntime_init_36_guard= ::tardis::Pointer_obj::__new(false);
	haxegoruntime_ZiLen= ::tardis::Pointer_obj::__new((int)0);
	main_init_36_guard= ::tardis::Pointer_obj::__new(false);
	main_mouseEvents= ::tardis::Pointer_obj::__new(null());
	utf16_init_36_guard= ::tardis::Pointer_obj::__new(false);
	utf8_init_36_guard= ::tardis::Pointer_obj::__new(false);
	hxutil_init_36_guard= ::tardis::Pointer_obj::__new(false);
	doneInit= false;
}

} // end namespace tardis
