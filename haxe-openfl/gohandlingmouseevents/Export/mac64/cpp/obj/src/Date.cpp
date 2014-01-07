#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Date_obj::__construct(int year,int month,int day,int hour,int min,int sec)
{
HX_STACK_PUSH("Date::new","/usr/lib/haxe/std/cpp/_std/Date.hx",26);
{
	HX_STACK_LINE(26)
	this->mSeconds = ::__hxcpp_new_date(year,month,day,hour,min,sec);
}
;
	return null();
}

Date_obj::~Date_obj() { }

Dynamic Date_obj::__CreateEmpty() { return  new Date_obj; }
hx::ObjectPtr< Date_obj > Date_obj::__new(int year,int month,int day,int hour,int min,int sec)
{  hx::ObjectPtr< Date_obj > result = new Date_obj();
	result->__construct(year,month,day,hour,min,sec);
	return result;}

Dynamic Date_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Date_obj > result = new Date_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::Date Date_obj::fromString( ::String s){
	HX_STACK_PUSH("Date::fromString","/usr/lib/haxe/std/cpp/_std/Date.hx",60);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(61)
	switch( (int)(s.length)){
		case (int)8: {
			HX_STACK_LINE(63)
			Array< ::String > k = s.split(HX_CSTRING(":"));		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(64)
			::Date d = ::Date_obj::__new((int)0,(int)0,(int)0,::Std_obj::parseInt(k->__get((int)0)),::Std_obj::parseInt(k->__get((int)1)),::Std_obj::parseInt(k->__get((int)2)));		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(65)
			return d;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(67)
			Array< ::String > k = s.split(HX_CSTRING("-"));		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(68)
			return ::Date_obj::__new(::Std_obj::parseInt(k->__get((int)0)),(::Std_obj::parseInt(k->__get((int)1)) - (int)1),::Std_obj::parseInt(k->__get((int)2)),(int)0,(int)0,(int)0);
		}
		;break;
		case (int)19: {
			HX_STACK_LINE(70)
			Array< ::String > k = s.split(HX_CSTRING(" "));		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(71)
			Array< ::String > y = k->__get((int)0).split(HX_CSTRING("-"));		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(72)
			Array< ::String > t = k->__get((int)1).split(HX_CSTRING(":"));		HX_STACK_VAR(t,"t");
			HX_STACK_LINE(73)
			return ::Date_obj::__new(::Std_obj::parseInt(y->__get((int)0)),(::Std_obj::parseInt(y->__get((int)1)) - (int)1),::Std_obj::parseInt(y->__get((int)2)),::Std_obj::parseInt(t->__get((int)0)),::Std_obj::parseInt(t->__get((int)1)),::Std_obj::parseInt(t->__get((int)2)));
		}
		;break;
		default: {
			HX_STACK_LINE(75)
			hx::Throw ((HX_CSTRING("Invalid date format : ") + s));
		}
	}
	HX_STACK_LINE(78)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Date_obj,fromString,return )


Date_obj::Date_obj()
{
}

void Date_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Date);
	HX_MARK_MEMBER_NAME(mSeconds,"mSeconds");
	HX_MARK_END_CLASS();
}

void Date_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mSeconds,"mSeconds");
}

Dynamic Date_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mSeconds") ) { return mSeconds; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Date_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mSeconds") ) { mSeconds=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Date_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mSeconds"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromString"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mSeconds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Date_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Date_obj::__mClass,"__mClass");
};

Class Date_obj::__mClass;

void Date_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Date"), hx::TCanCast< Date_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Date_obj::__boot()
{
}

