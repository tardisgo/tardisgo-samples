#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_motion_easing_ExpoEaseOut
#include <motion/easing/ExpoEaseOut.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace easing{

Void ExpoEaseOut_obj::__construct()
{
HX_STACK_PUSH("ExpoEaseOut::new","motion/easing/Expo.hx",114);
{
}
;
	return null();
}

ExpoEaseOut_obj::~ExpoEaseOut_obj() { }

Dynamic ExpoEaseOut_obj::__CreateEmpty() { return  new ExpoEaseOut_obj; }
hx::ObjectPtr< ExpoEaseOut_obj > ExpoEaseOut_obj::__new()
{  hx::ObjectPtr< ExpoEaseOut_obj > result = new ExpoEaseOut_obj();
	result->__construct();
	return result;}

Dynamic ExpoEaseOut_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ExpoEaseOut_obj > result = new ExpoEaseOut_obj();
	result->__construct();
	return result;}

hx::Object *ExpoEaseOut_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::motion::easing::IEasing_obj)) return operator ::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float ExpoEaseOut_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_PUSH("ExpoEaseOut::ease","motion/easing/Expo.hx",128);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(128)
	return (  (((t == d))) ? Float((b + c)) : Float(((c * (((int)1 - ::Math_obj::pow((int)2,(Float(((int)-10 * t)) / Float(d)))))) + b)) );
}


HX_DEFINE_DYNAMIC_FUNC4(ExpoEaseOut_obj,ease,return )

Float ExpoEaseOut_obj::calculate( Float k){
	HX_STACK_PUSH("ExpoEaseOut::calculate","motion/easing/Expo.hx",121);
	HX_STACK_THIS(this);
	HX_STACK_ARG(k,"k");
	HX_STACK_LINE(121)
	return (  (((k == (int)1))) ? Float((int)1) : Float(((int)1 - ::Math_obj::pow((int)2,((int)-10 * k)))) );
}


HX_DEFINE_DYNAMIC_FUNC1(ExpoEaseOut_obj,calculate,return )


ExpoEaseOut_obj::ExpoEaseOut_obj()
{
}

void ExpoEaseOut_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ExpoEaseOut);
	HX_MARK_END_CLASS();
}

void ExpoEaseOut_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic ExpoEaseOut_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"ease") ) { return ease_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"calculate") ) { return calculate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ExpoEaseOut_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ExpoEaseOut_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("ease"),
	HX_CSTRING("calculate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ExpoEaseOut_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ExpoEaseOut_obj::__mClass,"__mClass");
};

Class ExpoEaseOut_obj::__mClass;

void ExpoEaseOut_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.easing.ExpoEaseOut"), hx::TCanCast< ExpoEaseOut_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ExpoEaseOut_obj::__boot()
{
}

} // end namespace motion
} // end namespace easing
