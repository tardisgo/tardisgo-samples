#include <hxcpp.h>

#ifndef INCLUDED_tardis_Pointer
#include <tardis/Pointer.h>
#endif
#ifndef INCLUDED_tardis_UnsafePointer
#include <tardis/UnsafePointer.h>
#endif
namespace tardis{

Void UnsafePointer_obj::__construct(Dynamic x)
{
HX_STACK_PUSH("UnsafePointer::new","tardis/Go.hx",280);
{
	HX_STACK_LINE(280)
	super::__construct(x);
}
;
	return null();
}

UnsafePointer_obj::~UnsafePointer_obj() { }

Dynamic UnsafePointer_obj::__CreateEmpty() { return  new UnsafePointer_obj; }
hx::ObjectPtr< UnsafePointer_obj > UnsafePointer_obj::__new(Dynamic x)
{  hx::ObjectPtr< UnsafePointer_obj > result = new UnsafePointer_obj();
	result->__construct(x);
	return result;}

Dynamic UnsafePointer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UnsafePointer_obj > result = new UnsafePointer_obj();
	result->__construct(inArgs[0]);
	return result;}


UnsafePointer_obj::UnsafePointer_obj()
{
}

void UnsafePointer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UnsafePointer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void UnsafePointer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic UnsafePointer_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic UnsafePointer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void UnsafePointer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UnsafePointer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UnsafePointer_obj::__mClass,"__mClass");
};

Class UnsafePointer_obj::__mClass;

void UnsafePointer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.UnsafePointer"), hx::TCanCast< UnsafePointer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void UnsafePointer_obj::__boot()
{
}

} // end namespace tardis
