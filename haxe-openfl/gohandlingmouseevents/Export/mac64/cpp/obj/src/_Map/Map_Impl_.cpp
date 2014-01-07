#include <hxcpp.h>

#ifndef INCLUDED__Map_Map_Impl_
#include <_Map/Map_Impl_.h>
#endif
namespace _Map{

Void Map_Impl__obj::__construct()
{
	return null();
}

Map_Impl__obj::~Map_Impl__obj() { }

Dynamic Map_Impl__obj::__CreateEmpty() { return  new Map_Impl__obj; }
hx::ObjectPtr< Map_Impl__obj > Map_Impl__obj::__new()
{  hx::ObjectPtr< Map_Impl__obj > result = new Map_Impl__obj();
	result->__construct();
	return result;}

Dynamic Map_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Map_Impl__obj > result = new Map_Impl__obj();
	result->__construct();
	return result;}


Map_Impl__obj::Map_Impl__obj()
{
}

void Map_Impl__obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Map_Impl_);
	HX_MARK_END_CLASS();
}

void Map_Impl__obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Map_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Map_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Map_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Map_Impl__obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Map_Impl__obj::__mClass,"__mClass");
};

Class Map_Impl__obj::__mClass;

void Map_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("_Map.Map_Impl_"), hx::TCanCast< Map_Impl__obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Map_Impl__obj::__boot()
{
}

} // end namespace _Map
