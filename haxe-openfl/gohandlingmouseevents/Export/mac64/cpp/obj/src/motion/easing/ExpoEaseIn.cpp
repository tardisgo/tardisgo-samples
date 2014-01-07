#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_motion_easing_ExpoEaseIn
#include <motion/easing/ExpoEaseIn.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace easing{

Void ExpoEaseIn_obj::__construct()
{
HX_STACK_PUSH("ExpoEaseIn::new","motion/easing/Expo.hx",46);
{
}
;
	return null();
}

ExpoEaseIn_obj::~ExpoEaseIn_obj() { }

Dynamic ExpoEaseIn_obj::__CreateEmpty() { return  new ExpoEaseIn_obj; }
hx::ObjectPtr< ExpoEaseIn_obj > ExpoEaseIn_obj::__new()
{  hx::ObjectPtr< ExpoEaseIn_obj > result = new ExpoEaseIn_obj();
	result->__construct();
	return result;}

Dynamic ExpoEaseIn_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ExpoEaseIn_obj > result = new ExpoEaseIn_obj();
	result->__construct();
	return result;}

hx::Object *ExpoEaseIn_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::motion::easing::IEasing_obj)) return operator ::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float ExpoEaseIn_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_PUSH("ExpoEaseIn::ease","motion/easing/Expo.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(60)
	return (  (((t == (int)0))) ? Float(b) : Float(((c * ::Math_obj::pow((int)2,((int)10 * (((Float(t) / Float(d)) - (int)1))))) + b)) );
}


HX_DEFINE_DYNAMIC_FUNC4(ExpoEaseIn_obj,ease,return )

Float ExpoEaseIn_obj::calculate( Float k){
	HX_STACK_PUSH("ExpoEaseIn::calculate","motion/easing/Expo.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_ARG(k,"k");
	HX_STACK_LINE(53)
	return (  (((k == (int)0))) ? Float((int)0) : Float(::Math_obj::pow((int)2,((int)10 * ((k - (int)1))))) );
}


HX_DEFINE_DYNAMIC_FUNC1(ExpoEaseIn_obj,calculate,return )


ExpoEaseIn_obj::ExpoEaseIn_obj()
{
}

void ExpoEaseIn_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ExpoEaseIn);
	HX_MARK_END_CLASS();
}

void ExpoEaseIn_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic ExpoEaseIn_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic ExpoEaseIn_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ExpoEaseIn_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(ExpoEaseIn_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ExpoEaseIn_obj::__mClass,"__mClass");
};

Class ExpoEaseIn_obj::__mClass;

void ExpoEaseIn_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.easing.ExpoEaseIn"), hx::TCanCast< ExpoEaseIn_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ExpoEaseIn_obj::__boot()
{
}

} // end namespace motion
} // end namespace easing
