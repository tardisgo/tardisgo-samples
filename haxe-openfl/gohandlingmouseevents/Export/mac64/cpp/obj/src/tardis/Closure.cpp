#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Closure
#include <tardis/Closure.h>
#endif
#ifndef INCLUDED_tardis_Deep
#include <tardis/Deep.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
namespace tardis{

Void Closure_obj::__construct(Dynamic f,Dynamic b)
{
HX_STACK_PUSH("Closure::new","tardis/Go.hx",400);
{
	HX_STACK_LINE(401)
	if ((::Std_obj::is(f,hx::ClassOf< ::tardis::Closure >()))){
		HX_STACK_LINE(402)
		if ((!(::Reflect_obj::isFunction(f->__Field(HX_CSTRING("fn"),true))))){
			HX_STACK_LINE(402)
			::tardis::Scheduler_obj::panicFromHaxe((HX_CSTRING("invalid function reference passed to make Closure(): ") + ::Std_obj::string(f->__Field(HX_CSTRING("fn"),true))));
		}
		HX_STACK_LINE(403)
		this->fn = f->__Field(HX_CSTRING("fn"),true);
	}
	else{
		HX_STACK_LINE(405)
		if ((!(::Reflect_obj::isFunction(f)))){
			HX_STACK_LINE(405)
			::tardis::Scheduler_obj::panicFromHaxe((HX_CSTRING("invalid function reference passed to make Closure(): ") + ::Std_obj::string(f)));
		}
		HX_STACK_LINE(406)
		this->fn = f;
	}
	HX_STACK_LINE(408)
	if (((this->fn == null()))){
		HX_STACK_LINE(408)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("new Closure() function has become null!"));
	}
	HX_STACK_LINE(409)
	this->bds = b;
}
;
	return null();
}

Closure_obj::~Closure_obj() { }

Dynamic Closure_obj::__CreateEmpty() { return  new Closure_obj; }
hx::ObjectPtr< Closure_obj > Closure_obj::__new(Dynamic f,Dynamic b)
{  hx::ObjectPtr< Closure_obj > result = new Closure_obj();
	result->__construct(f,b);
	return result;}

Dynamic Closure_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Closure_obj > result = new Closure_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic Closure_obj::callFn( Dynamic params){
	HX_STACK_PUSH("Closure::callFn","tardis/Go.hx",423);
	HX_STACK_THIS(this);
	HX_STACK_ARG(params,"params");
	HX_STACK_LINE(424)
	if (((this->fn == null()))){
		HX_STACK_LINE(424)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("attempt to call null function reference in Closure()"));
	}
	HX_STACK_LINE(425)
	if ((!(::Reflect_obj::isFunction(this->fn)))){
		HX_STACK_LINE(425)
		::tardis::Scheduler_obj::panicFromHaxe((HX_CSTRING("invalid function reference in Closure(): ") + ::Std_obj::string(this->fn)));
	}
	HX_STACK_LINE(426)
	return ::Reflect_obj::callMethod(null(),this->fn,params);
}


HX_DEFINE_DYNAMIC_FUNC1(Closure_obj,callFn,return )

Dynamic Closure_obj::methVal( Dynamic t,Dynamic v){
	HX_STACK_PUSH("Closure::methVal","tardis/Go.hx",419);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(420)
	Dynamic tmp = ::tardis::Deep_obj::copy(t);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(421)
	return ::Reflect_obj::callMethod(null(),this->fn,Dynamic( Array_obj<Dynamic>::__new().Add(Dynamic( Array_obj<Dynamic>::__new())).Add(tmp).Add(v)));
}


HX_DEFINE_DYNAMIC_FUNC2(Closure_obj,methVal,return )

::String Closure_obj::toString( ){
	HX_STACK_PUSH("Closure::toString","tardis/Go.hx",411);
	HX_STACK_THIS(this);
	HX_STACK_LINE(412)
	::String ret = ((HX_CSTRING("Closure{") + ::Std_obj::string(this->fn)) + HX_CSTRING(",["));		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(413)
	{
		HX_STACK_LINE(413)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->bds->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(413)
		while(((_g1 < _g))){
			HX_STACK_LINE(413)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(414)
			if (((i != (int)0))){
				HX_STACK_LINE(414)
				hx::AddEq(ret,HX_CSTRING(","));
			}
			HX_STACK_LINE(415)
			hx::AddEq(ret,this->bds->__GetItem(i));
		}
	}
	HX_STACK_LINE(417)
	return (ret + HX_CSTRING("]}"));
}


HX_DEFINE_DYNAMIC_FUNC0(Closure_obj,toString,return )


Closure_obj::Closure_obj()
{
}

void Closure_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Closure);
	HX_MARK_MEMBER_NAME(bds,"bds");
	HX_MARK_MEMBER_NAME(fn,"fn");
	HX_MARK_END_CLASS();
}

void Closure_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bds,"bds");
	HX_VISIT_MEMBER_NAME(fn,"fn");
}

Dynamic Closure_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"fn") ) { return fn; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"bds") ) { return bds; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"callFn") ) { return callFn_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"methVal") ) { return methVal_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Closure_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"fn") ) { fn=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"bds") ) { bds=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Closure_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bds"));
	outFields->push(HX_CSTRING("fn"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("callFn"),
	HX_CSTRING("methVal"),
	HX_CSTRING("toString"),
	HX_CSTRING("bds"),
	HX_CSTRING("fn"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Closure_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Closure_obj::__mClass,"__mClass");
};

Class Closure_obj::__mClass;

void Closure_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Closure"), hx::TCanCast< Closure_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Closure_obj::__boot()
{
}

} // end namespace tardis
