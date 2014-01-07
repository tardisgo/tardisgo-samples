#include <hxcpp.h>

#ifndef INCLUDED_motion__Actuate_TweenTimer
#include <motion/_Actuate/TweenTimer.h>
#endif
namespace motion{
namespace _Actuate{

Void TweenTimer_obj::__construct(Float progress)
{
HX_STACK_PUSH("TweenTimer::new","motion/Actuate.hx",533);
{
	HX_STACK_LINE(533)
	this->progress = progress;
}
;
	return null();
}

TweenTimer_obj::~TweenTimer_obj() { }

Dynamic TweenTimer_obj::__CreateEmpty() { return  new TweenTimer_obj; }
hx::ObjectPtr< TweenTimer_obj > TweenTimer_obj::__new(Float progress)
{  hx::ObjectPtr< TweenTimer_obj > result = new TweenTimer_obj();
	result->__construct(progress);
	return result;}

Dynamic TweenTimer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TweenTimer_obj > result = new TweenTimer_obj();
	result->__construct(inArgs[0]);
	return result;}


TweenTimer_obj::TweenTimer_obj()
{
}

void TweenTimer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TweenTimer);
	HX_MARK_MEMBER_NAME(progress,"progress");
	HX_MARK_END_CLASS();
}

void TweenTimer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(progress,"progress");
}

Dynamic TweenTimer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"progress") ) { return progress; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TweenTimer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"progress") ) { progress=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TweenTimer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("progress"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("progress"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TweenTimer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TweenTimer_obj::__mClass,"__mClass");
};

Class TweenTimer_obj::__mClass;

void TweenTimer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion._Actuate.TweenTimer"), hx::TCanCast< TweenTimer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TweenTimer_obj::__boot()
{
}

} // end namespace motion
} // end namespace _Actuate
