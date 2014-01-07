#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
namespace tardis{

HX_DEFINE_DYNAMIC_FUNC0(StackFrame_obj,res,return )

HX_DEFINE_DYNAMIC_FUNC0(StackFrame_obj,run,return )


static ::String sMemberFields[] = {
	HX_CSTRING("res"),
	HX_CSTRING("run"),
	HX_CSTRING("_deferStack"),
	HX_CSTRING("_bds"),
	HX_CSTRING("_goroutine"),
	HX_CSTRING("_functionName"),
	HX_CSTRING("_functionPH"),
	HX_CSTRING("_latestBlock"),
	HX_CSTRING("_latestPH"),
	HX_CSTRING("_incomplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StackFrame_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StackFrame_obj::__mClass,"__mClass");
};

Class StackFrame_obj::__mClass;

void StackFrame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.StackFrame"), hx::TCanCast< StackFrame_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StackFrame_obj::__boot()
{
}

} // end namespace tardis
