#include <hxcpp.h>

#ifndef INCLUDED_motion_easing_Expo
#include <motion/easing/Expo.h>
#endif
#ifndef INCLUDED_motion_easing_ExpoEaseIn
#include <motion/easing/ExpoEaseIn.h>
#endif
#ifndef INCLUDED_motion_easing_ExpoEaseInOut
#include <motion/easing/ExpoEaseInOut.h>
#endif
#ifndef INCLUDED_motion_easing_ExpoEaseOut
#include <motion/easing/ExpoEaseOut.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace easing{

Void Expo_obj::__construct()
{
	return null();
}

Expo_obj::~Expo_obj() { }

Dynamic Expo_obj::__CreateEmpty() { return  new Expo_obj; }
hx::ObjectPtr< Expo_obj > Expo_obj::__new()
{  hx::ObjectPtr< Expo_obj > result = new Expo_obj();
	result->__construct();
	return result;}

Dynamic Expo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Expo_obj > result = new Expo_obj();
	result->__construct();
	return result;}

::motion::easing::IEasing Expo_obj::get_easeIn( ){
	HX_STACK_PUSH("Expo::get_easeIn","motion/easing/Expo.hx",19);
	HX_STACK_LINE(19)
	return ::motion::easing::ExpoEaseIn_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Expo_obj,get_easeIn,return )

::motion::easing::IEasing Expo_obj::get_easeInOut( ){
	HX_STACK_PUSH("Expo::get_easeInOut","motion/easing/Expo.hx",26);
	HX_STACK_LINE(26)
	return ::motion::easing::ExpoEaseInOut_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Expo_obj,get_easeInOut,return )

::motion::easing::IEasing Expo_obj::get_easeOut( ){
	HX_STACK_PUSH("Expo::get_easeOut","motion/easing/Expo.hx",33);
	HX_STACK_LINE(33)
	return ::motion::easing::ExpoEaseOut_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Expo_obj,get_easeOut,return )


Expo_obj::Expo_obj()
{
}

void Expo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Expo);
	HX_MARK_END_CLASS();
}

void Expo_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Expo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { return get_easeIn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { return get_easeOut(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { return get_easeInOut(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_easeIn") ) { return get_easeIn_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_easeOut") ) { return get_easeOut_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_easeInOut") ) { return get_easeInOut_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Expo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Expo_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("get_easeIn"),
	HX_CSTRING("get_easeInOut"),
	HX_CSTRING("get_easeOut"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Expo_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Expo_obj::__mClass,"__mClass");
};

Class Expo_obj::__mClass;

void Expo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.easing.Expo"), hx::TCanCast< Expo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Expo_obj::__boot()
{
}

} // end namespace motion
} // end namespace easing
