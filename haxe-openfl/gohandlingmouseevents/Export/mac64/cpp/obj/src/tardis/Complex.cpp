#include <hxcpp.h>

#ifndef INCLUDED_tardis_Complex
#include <tardis/Complex.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
namespace tardis{

Void Complex_obj::__construct(Float r,Float i)
{
HX_STACK_PUSH("Complex::new","tardis/Go.hx",593);
{
	HX_STACK_LINE(594)
	this->real = r;
	HX_STACK_LINE(595)
	this->imag = i;
}
;
	return null();
}

Complex_obj::~Complex_obj() { }

Dynamic Complex_obj::__CreateEmpty() { return  new Complex_obj; }
hx::ObjectPtr< Complex_obj > Complex_obj::__new(Float r,Float i)
{  hx::ObjectPtr< Complex_obj > result = new Complex_obj();
	result->__construct(r,i);
	return result;}

Dynamic Complex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Complex_obj > result = new Complex_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::tardis::Complex Complex_obj::neg( ::tardis::Complex x){
	HX_STACK_PUSH("Complex::neg","tardis/Go.hx",597);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(597)
	return ::tardis::Complex_obj::__new((0.0 - x->real),(0.0 - x->imag));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Complex_obj,neg,return )

::tardis::Complex Complex_obj::add( ::tardis::Complex x,::tardis::Complex y){
	HX_STACK_PUSH("Complex::add","tardis/Go.hx",600);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(600)
	return ::tardis::Complex_obj::__new((x->real + y->real),(x->imag + y->imag));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Complex_obj,add,return )

::tardis::Complex Complex_obj::sub( ::tardis::Complex x,::tardis::Complex y){
	HX_STACK_PUSH("Complex::sub","tardis/Go.hx",603);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(603)
	return ::tardis::Complex_obj::__new((x->real - y->real),(x->imag - y->imag));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Complex_obj,sub,return )

::tardis::Complex Complex_obj::mul( ::tardis::Complex x,::tardis::Complex y){
	HX_STACK_PUSH("Complex::mul","tardis/Go.hx",606);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(606)
	return ::tardis::Complex_obj::__new(((x->real * y->real) - (x->imag * y->imag)),((x->imag * y->real) + (x->real * y->imag)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Complex_obj,mul,return )

::tardis::Complex Complex_obj::div( ::tardis::Complex x,::tardis::Complex y){
	HX_STACK_PUSH("Complex::div","tardis/Go.hx",609);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(609)
	if (((bool((y->real == 0.0)) && bool((y->imag == 0.0))))){
		HX_STACK_LINE(611)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("complex divide by zero"));
		HX_STACK_LINE(612)
		return ::tardis::Complex_obj::__new(0.0,0.0);
	}
	else{
		HX_STACK_LINE(613)
		return ::tardis::Complex_obj::__new((Float((((x->real * y->real) + (x->imag * y->imag)))) / Float((((y->real * y->real) + (y->imag * y->imag))))),(Float((((x->imag * y->real) - (x->real * y->imag)))) / Float((((y->real * y->real) + (y->imag * y->imag))))));
	}
	HX_STACK_LINE(609)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Complex_obj,div,return )

bool Complex_obj::eq( ::tardis::Complex x,::tardis::Complex y){
	HX_STACK_PUSH("Complex::eq","tardis/Go.hx",619);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(619)
	return (bool((x->real == y->real)) && bool((x->imag == y->imag)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Complex_obj,eq,return )

bool Complex_obj::neq( ::tardis::Complex x,::tardis::Complex y){
	HX_STACK_PUSH("Complex::neq","tardis/Go.hx",622);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(622)
	return (bool((x->real != y->real)) || bool((x->imag != y->imag)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Complex_obj,neq,return )


Complex_obj::Complex_obj()
{
}

void Complex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Complex);
	HX_MARK_MEMBER_NAME(imag,"imag");
	HX_MARK_MEMBER_NAME(real,"real");
	HX_MARK_END_CLASS();
}

void Complex_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(imag,"imag");
	HX_VISIT_MEMBER_NAME(real,"real");
}

Dynamic Complex_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"eq") ) { return eq_dyn(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"neg") ) { return neg_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"sub") ) { return sub_dyn(); }
		if (HX_FIELD_EQ(inName,"mul") ) { return mul_dyn(); }
		if (HX_FIELD_EQ(inName,"div") ) { return div_dyn(); }
		if (HX_FIELD_EQ(inName,"neq") ) { return neq_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"imag") ) { return imag; }
		if (HX_FIELD_EQ(inName,"real") ) { return real; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Complex_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"imag") ) { imag=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"real") ) { real=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Complex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("imag"));
	outFields->push(HX_CSTRING("real"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("neg"),
	HX_CSTRING("add"),
	HX_CSTRING("sub"),
	HX_CSTRING("mul"),
	HX_CSTRING("div"),
	HX_CSTRING("eq"),
	HX_CSTRING("neq"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("imag"),
	HX_CSTRING("real"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Complex_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Complex_obj::__mClass,"__mClass");
};

Class Complex_obj::__mClass;

void Complex_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Complex"), hx::TCanCast< Complex_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Complex_obj::__boot()
{
}

} // end namespace tardis
