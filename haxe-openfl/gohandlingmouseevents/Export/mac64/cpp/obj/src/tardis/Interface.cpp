#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Deep
#include <tardis/Deep.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
#endif
#ifndef INCLUDED_tardis_Pointer
#include <tardis/Pointer.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_TypeInfo
#include <tardis/TypeInfo.h>
#endif
namespace tardis{

Void Interface_obj::__construct(int t,Dynamic v)
{
HX_STACK_PUSH("Interface::new","tardis/Go.hx",434);
{
	HX_STACK_LINE(435)
	this->typ = t;
	HX_STACK_LINE(436)
	this->val = ::tardis::Deep_obj::copy(v);
}
;
	return null();
}

Interface_obj::~Interface_obj() { }

Dynamic Interface_obj::__CreateEmpty() { return  new Interface_obj; }
hx::ObjectPtr< Interface_obj > Interface_obj::__new(int t,Dynamic v)
{  hx::ObjectPtr< Interface_obj > result = new Interface_obj();
	result->__construct(t,v);
	return result;}

Dynamic Interface_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Interface_obj > result = new Interface_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String Interface_obj::toString( ){
	HX_STACK_PUSH("Interface::toString","tardis/Go.hx",438);
	HX_STACK_THIS(this);
	HX_STACK_LINE(438)
	if (((this->val == null()))){
		HX_STACK_LINE(440)
		return ((HX_CSTRING("Interface{null:") + ::tardis::TypeInfo_obj::getName(this->typ)) + HX_CSTRING("}"));
	}
	else{
		HX_STACK_LINE(442)
		return ((((HX_CSTRING("Interface{") + ::Std_obj::string(this->val)) + HX_CSTRING(":")) + ::tardis::TypeInfo_obj::getName(this->typ)) + HX_CSTRING("}"));
	}
	HX_STACK_LINE(438)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Interface_obj,toString,return )

::tardis::Interface Interface_obj::change( int t,::tardis::Interface i){
	HX_STACK_PUSH("Interface::change","tardis/Go.hx",444);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(i,"i");
	HX_STACK_LINE(444)
	if (((i == null()))){
		HX_STACK_LINE(446)
		if ((::tardis::TypeInfo_obj::isConcrete(t))){
			HX_STACK_LINE(447)
			return ::tardis::Interface_obj::__new(t,::tardis::TypeInfo_obj::zeroValue(t));
		}
		else{
			HX_STACK_LINE(449)
			::tardis::Scheduler_obj::panicFromHaxe((HX_CSTRING("can't change the Interface of a nil value to Interface type: ") + ::tardis::TypeInfo_obj::getName(t)));
			HX_STACK_LINE(450)
			return ::tardis::Interface_obj::__new(t,::tardis::TypeInfo_obj::zeroValue(t));
		}
	}
	else{
		HX_STACK_LINE(453)
		if ((::Std_obj::is(i,hx::ClassOf< ::tardis::Interface >()))){
			HX_STACK_LINE(454)
			if ((::tardis::TypeInfo_obj::isConcrete(t))){
				HX_STACK_LINE(455)
				return ::tardis::Interface_obj::__new(t,::tardis::Deep_obj::copy(i->val));
			}
			else{
				HX_STACK_LINE(457)
				return ::tardis::Interface_obj::__new(i->typ,::tardis::Deep_obj::copy(i->val));
			}
		}
		else{
			HX_STACK_LINE(459)
			::tardis::Scheduler_obj::panicFromHaxe((((HX_CSTRING("Can't change the Interface of a non-Interface type:") + ::Std_obj::string(i)) + HX_CSTRING(" to: ")) + ::tardis::TypeInfo_obj::getName(t)));
			HX_STACK_LINE(460)
			return ::tardis::Interface_obj::__new(t,::tardis::TypeInfo_obj::zeroValue(t));
		}
	}
	HX_STACK_LINE(444)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Interface_obj,change,return )

bool Interface_obj::isEqual( ::tardis::Interface a,::tardis::Interface b){
	HX_STACK_PUSH("Interface::isEqual","tardis/Go.hx",463);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(464)
	if (((a == null()))){
		HX_STACK_LINE(465)
		if (((b == null()))){
			HX_STACK_LINE(465)
			return true;
		}
		else{
			HX_STACK_LINE(466)
			return false;
		}
	}
	HX_STACK_LINE(467)
	if (((b == null()))){
		HX_STACK_LINE(468)
		return false;
	}
	HX_STACK_LINE(469)
	if ((!(((bool((bool(::tardis::TypeInfo_obj::isIdentical(a->typ,b->typ)) || bool(::tardis::TypeInfo_obj::isAssignableTo(a->typ,b->typ)))) || bool(::tardis::TypeInfo_obj::isAssignableTo(b->typ,a->typ))))))){
		HX_STACK_LINE(470)
		return false;
	}
	else{
		HX_STACK_LINE(472)
		if (((a->val == b->val))){
			HX_STACK_LINE(473)
			return true;
		}
		else{
			HX_STACK_LINE(475)
			if (((bool(::Std_obj::is(a->val,hx::ClassOf< ::tardis::Pointer >())) && bool(::Std_obj::is(b->val,hx::ClassOf< ::tardis::Pointer >()))))){
				HX_STACK_LINE(476)
				return (a->val->__Field(HX_CSTRING("load"),true)() == b->val->__Field(HX_CSTRING("load"),true)());
			}
			else{
				HX_STACK_LINE(478)
				return false;
			}
		}
	}
	HX_STACK_LINE(469)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Interface_obj,isEqual,return )

Dynamic Interface_obj::_assert( int assTyp,::tardis::Interface ifce){
	HX_STACK_PUSH("Interface::assert","tardis/Go.hx",487);
	HX_STACK_ARG(assTyp,"assTyp");
	HX_STACK_ARG(ifce,"ifce");
	HX_STACK_LINE(488)
	if (((ifce == null()))){
		HX_STACK_LINE(489)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Interface.assert null Interface"));
	}
	HX_STACK_LINE(490)
	if ((!(((bool(::tardis::TypeInfo_obj::isAssignableTo(ifce->typ,assTyp)) || bool(::tardis::TypeInfo_obj::isIdentical(assTyp,ifce->typ))))))){
		HX_STACK_LINE(491)
		::tardis::Scheduler_obj::panicFromHaxe((((HX_CSTRING("type assert failed: expected ") + ::tardis::TypeInfo_obj::getName(assTyp)) + HX_CSTRING(", got ")) + ::tardis::TypeInfo_obj::getName(ifce->typ)));
	}
	HX_STACK_LINE(492)
	if ((::tardis::TypeInfo_obj::isConcrete(assTyp))){
		HX_STACK_LINE(493)
		return ::tardis::Deep_obj::copy(ifce->val);
	}
	else{
		HX_STACK_LINE(495)
		return ::tardis::Interface_obj::__new(ifce->typ,ifce->val);
	}
	HX_STACK_LINE(492)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Interface_obj,_assert,return )

Dynamic Interface_obj::assertOk( int assTyp,::tardis::Interface ifce){
	HX_STACK_PUSH("Interface::assertOk","tardis/Go.hx",497);
	HX_STACK_ARG(assTyp,"assTyp");
	HX_STACK_ARG(ifce,"ifce");
	HX_STACK_LINE(498)
	if (((ifce == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( int &assTyp){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",499);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("r0") , ::tardis::TypeInfo_obj::zeroValue(assTyp),false);
					__result->Add(HX_CSTRING("r1") , false,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(499)
		return _Function_2_1::Block(assTyp);
	}
	HX_STACK_LINE(500)
	if ((!(((bool(::tardis::TypeInfo_obj::isAssignableTo(ifce->typ,assTyp)) || bool(::tardis::TypeInfo_obj::isIdentical(assTyp,ifce->typ))))))){
		struct _Function_2_1{
			inline static Dynamic Block( int &assTyp){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",501);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("r0") , ::tardis::TypeInfo_obj::zeroValue(assTyp),false);
					__result->Add(HX_CSTRING("r1") , false,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(501)
		return _Function_2_1::Block(assTyp);
	}
	HX_STACK_LINE(502)
	if ((::tardis::TypeInfo_obj::isConcrete(assTyp))){
		struct _Function_2_1{
			inline static Dynamic Block( ::tardis::Interface &ifce){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",503);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("r0") , ::tardis::Deep_obj::copy(ifce->val),false);
					__result->Add(HX_CSTRING("r1") , true,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(503)
		return _Function_2_1::Block(ifce);
	}
	else{
		struct _Function_2_1{
			inline static Dynamic Block( ::tardis::Interface &ifce){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",505);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("r0") , ::tardis::Interface_obj::__new(ifce->typ,ifce->val),false);
					__result->Add(HX_CSTRING("r1") , true,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(505)
		return _Function_2_1::Block(ifce);
	}
	HX_STACK_LINE(502)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Interface_obj,assertOk,return )

Dynamic Interface_obj::invoke( ::tardis::Interface ifce,::String meth,Dynamic args){
	HX_STACK_PUSH("Interface::invoke","tardis/Go.hx",507);
	HX_STACK_ARG(ifce,"ifce");
	HX_STACK_ARG(meth,"meth");
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(508)
	if (((ifce == null()))){
		HX_STACK_LINE(509)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Interface.invoke null Interface"));
	}
	HX_STACK_LINE(511)
	if ((!(::Std_obj::is(ifce,hx::ClassOf< ::tardis::Interface >())))){
		HX_STACK_LINE(512)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Interface.invoke on non-Interface value"));
	}
	HX_STACK_LINE(514)
	Dynamic fn = ::tardis::TypeInfo_obj::method(ifce->typ,meth);		HX_STACK_VAR(fn,"fn");
	HX_STACK_LINE(517)
	return ::Reflect_obj::callMethod(null(),fn,args);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Interface_obj,invoke,return )


Interface_obj::Interface_obj()
{
}

void Interface_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Interface);
	HX_MARK_MEMBER_NAME(val,"val");
	HX_MARK_MEMBER_NAME(typ,"typ");
	HX_MARK_END_CLASS();
}

void Interface_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(val,"val");
	HX_VISIT_MEMBER_NAME(typ,"typ");
}

Dynamic Interface_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"val") ) { return val; }
		if (HX_FIELD_EQ(inName,"typ") ) { return typ; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"change") ) { return change_dyn(); }
		if (HX_FIELD_EQ(inName,"assert") ) { return _assert_dyn(); }
		if (HX_FIELD_EQ(inName,"invoke") ) { return invoke_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isEqual") ) { return isEqual_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"assertOk") ) { return assertOk_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Interface_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"val") ) { val=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"typ") ) { typ=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Interface_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("val"));
	outFields->push(HX_CSTRING("typ"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("change"),
	HX_CSTRING("isEqual"),
	HX_CSTRING("assert"),
	HX_CSTRING("assertOk"),
	HX_CSTRING("invoke"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("val"),
	HX_CSTRING("typ"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Interface_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Interface_obj::__mClass,"__mClass");
};

Class Interface_obj::__mClass;

void Interface_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Interface"), hx::TCanCast< Interface_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Interface_obj::__boot()
{
}

} // end namespace tardis
