#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED__Map_Map_Impl_
#include <_Map/Map_Impl_.h>
#endif
#ifndef INCLUDED_tardis_Closure
#include <tardis/Closure.h>
#endif
#ifndef INCLUDED_tardis_Deep
#include <tardis/Deep.h>
#endif
#ifndef INCLUDED_tardis_Pointer
#include <tardis/Pointer.h>
#endif
namespace tardis{

Void Deep_obj::__construct()
{
	return null();
}

Deep_obj::~Deep_obj() { }

Dynamic Deep_obj::__CreateEmpty() { return  new Deep_obj; }
hx::ObjectPtr< Deep_obj > Deep_obj::__new()
{  hx::ObjectPtr< Deep_obj > result = new Deep_obj();
	result->__construct();
	return result;}

Dynamic Deep_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Deep_obj > result = new Deep_obj();
	result->__construct();
	return result;}

Dynamic Deep_obj::copy( Dynamic v){
	HX_STACK_PUSH("Deep::copy","tardis/Go.hx",12);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(12)
	if ((!(::Reflect_obj::isObject(v)))){
		HX_STACK_LINE(13)
		return v;
	}
	else{
		HX_STACK_LINE(16)
		if ((::Std_obj::is(v,hx::ClassOf< ::String >()))){
			HX_STACK_LINE(16)
			return v;
		}
		else{
			HX_STACK_LINE(19)
			if ((::Std_obj::is(v,hx::ClassOf< ::tardis::Pointer >()))){
				HX_STACK_LINE(19)
				return ::tardis::Pointer_obj::copy(v);
			}
			else{
				HX_STACK_LINE(22)
				if ((::Std_obj::is(v,hx::ClassOf< ::tardis::Closure >()))){
					HX_STACK_LINE(22)
					return v;
				}
				else{
					HX_STACK_LINE(28)
					if ((::Std_obj::is(v,hx::ClassOf< Array<int> >()))){
						HX_STACK_LINE(29)
						Dynamic result = ::Type_obj::createInstance(::Type_obj::getClass(v),Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(result,"result");
						HX_STACK_LINE(30)
						{
							HX_STACK_LINE(31)
							int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
							int _g = v->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(31)
							while(((_g1 < _g))){
								HX_STACK_LINE(31)
								int ii = (_g1)++;		HX_STACK_VAR(ii,"ii");
								HX_STACK_LINE(32)
								result->__Field(HX_CSTRING("push"),true)(::tardis::Deep_obj::copy(v->__GetItem(ii)));
							}
						}
						HX_STACK_LINE(35)
						return result;
					}
					else{
						HX_STACK_LINE(59)
						if ((::Std_obj::is(v,hx::ClassOf< ::_Map::Map_Impl_ >()))){
							HX_STACK_LINE(60)
							Dynamic result = ::Type_obj::createInstance(::Type_obj::getClass(v),Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(result,"result");
							HX_STACK_LINE(61)
							{
								HX_STACK_LINE(62)
								Dynamic keys = v->__Field(HX_CSTRING("keys"),true)();		HX_STACK_VAR(keys,"keys");
								HX_STACK_LINE(63)
								for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(keys);  __it->hasNext(); ){
									Dynamic key = __it->next();
									result->__Field(HX_CSTRING("set"),true)(key,::tardis::Deep_obj::copy(v->__Field(HX_CSTRING("get"),true)(key)));
								}
							}
							HX_STACK_LINE(67)
							return result;
						}
						else{
							HX_STACK_LINE(69)
							if ((::Std_obj::is(v,hx::ClassOf< ::List >()))){
								HX_STACK_LINE(71)
								Dynamic result = ::Type_obj::createInstance(::Type_obj::getClass(v),Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(result,"result");
								HX_STACK_LINE(72)
								{
									HX_STACK_LINE(73)
									Dynamic iter = v->__Field(HX_CSTRING("iterator"),true)();		HX_STACK_VAR(iter,"iter");
									HX_STACK_LINE(74)
									for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(iter);  __it->hasNext(); ){
										Dynamic ii = __it->next();
										result->__Field(HX_CSTRING("add"),true)(ii);
									}
								}
								HX_STACK_LINE(78)
								return result;
							}
							else{
								HX_STACK_LINE(80)
								if (((::Type_obj::getClass(v) == null()))){
									struct _Function_9_1{
										inline static Dynamic Block( ){
											HX_STACK_PUSH("*::closure","tardis/Go.hx",81);
											{
												hx::Anon __result = hx::Anon_obj::Create();
												return __result;
											}
											return null();
										}
									};
									HX_STACK_LINE(81)
									Dynamic obj = _Function_9_1::Block();		HX_STACK_VAR(obj,"obj");
									HX_STACK_LINE(82)
									{
										HX_STACK_LINE(82)
										int _g = (int)0;		HX_STACK_VAR(_g,"_g");
										Array< ::String > _g1 = ::Reflect_obj::fields(v);		HX_STACK_VAR(_g1,"_g1");
										HX_STACK_LINE(82)
										while(((_g < _g1->length))){
											HX_STACK_LINE(82)
											::String ff = _g1->__get(_g);		HX_STACK_VAR(ff,"ff");
											HX_STACK_LINE(82)
											++(_g);
											HX_STACK_LINE(83)
											if (((obj != null()))){
												HX_STACK_LINE(83)
												obj->__SetField(ff,::tardis::Deep_obj::copy(::Reflect_obj::field(v,ff)),false);
											}
										}
									}
									HX_STACK_LINE(85)
									return obj;
								}
								else{
									HX_STACK_LINE(88)
									Dynamic obj = ::Type_obj::createEmptyInstance(::Type_obj::getClass(v));		HX_STACK_VAR(obj,"obj");
									HX_STACK_LINE(89)
									{
										HX_STACK_LINE(89)
										int _g = (int)0;		HX_STACK_VAR(_g,"_g");
										Array< ::String > _g1 = ::Reflect_obj::fields(v);		HX_STACK_VAR(_g1,"_g1");
										HX_STACK_LINE(89)
										while(((_g < _g1->length))){
											HX_STACK_LINE(89)
											::String ff = _g1->__get(_g);		HX_STACK_VAR(ff,"ff");
											HX_STACK_LINE(89)
											++(_g);
											HX_STACK_LINE(90)
											if (((obj != null()))){
												HX_STACK_LINE(90)
												obj->__SetField(ff,::tardis::Deep_obj::copy(::Reflect_obj::field(v,ff)),false);
											}
										}
									}
									HX_STACK_LINE(92)
									return obj;
								}
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(12)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Deep_obj,copy,return )


Deep_obj::Deep_obj()
{
}

void Deep_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Deep);
	HX_MARK_END_CLASS();
}

void Deep_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Deep_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Deep_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Deep_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("copy"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Deep_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Deep_obj::__mClass,"__mClass");
};

Class Deep_obj::__mClass;

void Deep_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Deep"), hx::TCanCast< Deep_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Deep_obj::__boot()
{
}

} // end namespace tardis
