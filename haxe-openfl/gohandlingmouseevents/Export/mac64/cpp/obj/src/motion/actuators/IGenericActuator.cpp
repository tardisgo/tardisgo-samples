#include <hxcpp.h>

#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace actuators{

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,snapping,return )

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,smartRotation,return )

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,reverse,return )

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,repeat,return )

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,reflect,return )

HX_DEFINE_DYNAMIC_FUNC2(IGenericActuator_obj,onUpdate,return )

HX_DEFINE_DYNAMIC_FUNC2(IGenericActuator_obj,onRepeat,return )

HX_DEFINE_DYNAMIC_FUNC2(IGenericActuator_obj,onComplete,return )

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,ease,return )

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,delay,return )

HX_DEFINE_DYNAMIC_FUNC1(IGenericActuator_obj,autoVisible,return )


static ::String sMemberFields[] = {
	HX_CSTRING("snapping"),
	HX_CSTRING("smartRotation"),
	HX_CSTRING("reverse"),
	HX_CSTRING("repeat"),
	HX_CSTRING("reflect"),
	HX_CSTRING("onUpdate"),
	HX_CSTRING("onRepeat"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("ease"),
	HX_CSTRING("delay"),
	HX_CSTRING("autoVisible"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IGenericActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IGenericActuator_obj::__mClass,"__mClass");
};

Class IGenericActuator_obj::__mClass;

void IGenericActuator_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.actuators.IGenericActuator"), hx::TCanCast< IGenericActuator_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IGenericActuator_obj::__boot()
{
}

} // end namespace motion
} // end namespace actuators
