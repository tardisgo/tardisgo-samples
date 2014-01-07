#include <hxcpp.h>

#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_TypeInfo
#include <tardis/TypeInfo.h>
#endif
namespace tardis{

Void TypeInfo_obj::__construct()
{
	return null();
}

TypeInfo_obj::~TypeInfo_obj() { }

Dynamic TypeInfo_obj::__CreateEmpty() { return  new TypeInfo_obj; }
hx::ObjectPtr< TypeInfo_obj > TypeInfo_obj::__new()
{  hx::ObjectPtr< TypeInfo_obj > result = new TypeInfo_obj();
	result->__construct();
	return result;}

Dynamic TypeInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TypeInfo_obj > result = new TypeInfo_obj();
	result->__construct();
	return result;}

::String TypeInfo_obj::getName( int id){
	HX_STACK_PUSH("TypeInfo::getName","tardis/Go.hx",8533);
	HX_STACK_ARG(id,"id");
	HX_STACK_LINE(8533)
	switch( (int)(id)){
		case (int)0: {
			HX_STACK_LINE(8535)
			return HX_CSTRING("string");
		}
		;break;
		default: {
			HX_STACK_LINE(8536)
			return HX_CSTRING("UNKNOWN");
		}
	}
	HX_STACK_LINE(8533)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TypeInfo_obj,getName,return )

::String TypeInfo_obj::typeString( ::tardis::Interface i){
	HX_STACK_PUSH("TypeInfo::typeString","tardis/Go.hx",8537);
	HX_STACK_ARG(i,"i");
	HX_STACK_LINE(8537)
	return ::tardis::TypeInfo_obj::getName(i->typ);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TypeInfo_obj,typeString,return )

int TypeInfo_obj::getId( ::String name){
	HX_STACK_PUSH("TypeInfo::getId","tardis/Go.hx",8540);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(8540)
	::String _switch_1 = (name);
	if (  ( _switch_1==HX_CSTRING("string"))){
		HX_STACK_LINE(8542)
		return (int)0;
	}
	else  {
		HX_STACK_LINE(8543)
		return (int)-1;
	}
;
;
	HX_STACK_LINE(8540)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TypeInfo_obj,getId,return )

bool TypeInfo_obj::isAssignableTo( int v,int t){
	HX_STACK_PUSH("TypeInfo::isAssignableTo","tardis/Go.hx",8544);
	HX_STACK_ARG(v,"v");
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(8545)
	if (((v == t))){
		HX_STACK_LINE(8545)
		return true;
	}
	HX_STACK_LINE(8546)
	switch( (int)(v)){
		case (int)0: {
			HX_STACK_LINE(8547)
			return false;
		}
		;break;
		default: {
			HX_STACK_LINE(8549)
			return false;
		}
	}
	HX_STACK_LINE(8546)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(TypeInfo_obj,isAssignableTo,return )

bool TypeInfo_obj::isIdentical( int v,int t){
	HX_STACK_PUSH("TypeInfo::isIdentical","tardis/Go.hx",8550);
	HX_STACK_ARG(v,"v");
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(8551)
	if (((v == t))){
		HX_STACK_LINE(8551)
		return true;
	}
	HX_STACK_LINE(8552)
	switch( (int)(v)){
		case (int)0: {
			HX_STACK_LINE(8553)
			return false;
		}
		;break;
		default: {
			HX_STACK_LINE(8555)
			return false;
		}
	}
	HX_STACK_LINE(8552)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(TypeInfo_obj,isIdentical,return )

bool TypeInfo_obj::isConcrete( int t){
	HX_STACK_PUSH("TypeInfo::isConcrete","tardis/Go.hx",8556);
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(8556)
	switch( (int)(t)){
		case (int)0: {
			HX_STACK_LINE(8558)
			return true;
		}
		;break;
		default: {
			HX_STACK_LINE(8559)
			return false;
		}
	}
	HX_STACK_LINE(8556)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TypeInfo_obj,isConcrete,return )

Dynamic TypeInfo_obj::zeroValue( int t){
	HX_STACK_PUSH("TypeInfo::zeroValue","tardis/Go.hx",8560);
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(8560)
	switch( (int)(t)){
		case (int)0: {
			HX_STACK_LINE(8562)
			return HX_CSTRING("");
		}
		;break;
		default: {
			HX_STACK_LINE(8563)
			return null();
		}
	}
	HX_STACK_LINE(8560)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TypeInfo_obj,zeroValue,return )

Dynamic TypeInfo_obj::method( int t,::String m){
	HX_STACK_PUSH("TypeInfo::method","tardis/Go.hx",8564);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(m,"m");
	HX_STACK_LINE(8567)
	::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("no method found!"));
	HX_STACK_LINE(8567)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(TypeInfo_obj,method,return )


TypeInfo_obj::TypeInfo_obj()
{
}

void TypeInfo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TypeInfo);
	HX_MARK_END_CLASS();
}

void TypeInfo_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic TypeInfo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"getId") ) { return getId_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"method") ) { return method_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getName") ) { return getName_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"zeroValue") ) { return zeroValue_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"typeString") ) { return typeString_dyn(); }
		if (HX_FIELD_EQ(inName,"isConcrete") ) { return isConcrete_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isIdentical") ) { return isIdentical_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isAssignableTo") ) { return isAssignableTo_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TypeInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TypeInfo_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getName"),
	HX_CSTRING("typeString"),
	HX_CSTRING("getId"),
	HX_CSTRING("isAssignableTo"),
	HX_CSTRING("isIdentical"),
	HX_CSTRING("isConcrete"),
	HX_CSTRING("zeroValue"),
	HX_CSTRING("method"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TypeInfo_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TypeInfo_obj::__mClass,"__mClass");
};

Class TypeInfo_obj::__mClass;

void TypeInfo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.TypeInfo"), hx::TCanCast< TypeInfo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TypeInfo_obj::__boot()
{
}

} // end namespace tardis
