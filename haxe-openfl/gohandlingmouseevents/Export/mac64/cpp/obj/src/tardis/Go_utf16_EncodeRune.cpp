#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Force
#include <tardis/Force.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Go_utf16_EncodeRune
#include <tardis/Go_utf16_EncodeRune.h>
#endif
#ifndef INCLUDED_tardis_Go_utf16_IsSurrogate
#include <tardis/Go_utf16_IsSurrogate.h>
#endif
#ifndef INCLUDED_tardis_Int64
#include <tardis/Int64.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif
namespace tardis{

Void Go_utf16_EncodeRune_obj::__construct(int gr,Dynamic _bds,int p_r)
{
HX_STACK_PUSH("Go_utf16_EncodeRune::new","tardis/Go.hx",7638);
{
	HX_STACK_LINE(7658)
	this->_Next = (int)0;
	HX_STACK_LINE(7657)
	this->_t8 = false;
	HX_STACK_LINE(7656)
	this->_t7 = false;
	HX_STACK_LINE(7654)
	this->_t6 = (int)0;
	HX_STACK_LINE(7653)
	this->_t5 = (int)0;
	HX_STACK_LINE(7652)
	this->_t4 = (int)0;
	HX_STACK_LINE(7651)
	this->_t3 = (int)0;
	HX_STACK_LINE(7650)
	this->_t2 = (int)0;
	HX_STACK_LINE(7649)
	this->_t1 = (int)0;
	HX_STACK_LINE(7648)
	this->_t0 = false;
	HX_STACK_LINE(7641)
	super::__construct(gr,(int)472,HX_CSTRING("Go_utf16_EncodeRune"));
	HX_STACK_LINE(7642)
	this->_bds = _bds;
	HX_STACK_LINE(7643)
	this->p_r = p_r;
	HX_STACK_LINE(7644)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf16_EncodeRune_obj::~Go_utf16_EncodeRune_obj() { }

Dynamic Go_utf16_EncodeRune_obj::__CreateEmpty() { return  new Go_utf16_EncodeRune_obj; }
hx::ObjectPtr< Go_utf16_EncodeRune_obj > Go_utf16_EncodeRune_obj::__new(int gr,Dynamic _bds,int p_r)
{  hx::ObjectPtr< Go_utf16_EncodeRune_obj > result = new Go_utf16_EncodeRune_obj();
	result->__construct(gr,_bds,p_r);
	return result;}

Dynamic Go_utf16_EncodeRune_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf16_EncodeRune_obj > result = new Go_utf16_EncodeRune_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf16_EncodeRune_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf16_EncodeRune_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf16_EncodeRune::SubFn3","tardis/Go.hx",7734);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7735)
		bool _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(7736)
		this->_latestPH = (int)473;
		HX_STACK_LINE(7737)
		_t8 = (this->p_r > (int)1114111);
		HX_STACK_LINE(7738)
		this->_Next = (  ((_t8)) ? int((int)1) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_EncodeRune_obj,SubFn3,(void))

Void Go_utf16_EncodeRune_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf16_EncodeRune::SubFn2","tardis/Go.hx",7731);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7731)
		this->_Next = (  ((this->_t7)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_EncodeRune_obj,SubFn2,(void))

Void Go_utf16_EncodeRune_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf16_EncodeRune::SubFn1","tardis/Go.hx",7719);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7720)
		int _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(7721)
		int _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(7722)
		int _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(7723)
		this->_t1 = ::tardis::Force_obj::toInt32((this->p_r - (int)65536));
		HX_STACK_LINE(7724)
		this->_latestPH = (int)477;
		HX_STACK_LINE(7725)
		_t2 = (int(this->_t1) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)10))));
		HX_STACK_LINE(7726)
		_t3 = ::tardis::Force_obj::toInt32((int(_t2) & int((int)1023)));
		HX_STACK_LINE(7727)
		this->_t4 = ::tardis::Force_obj::toInt32(((int)55296 + _t3));
		HX_STACK_LINE(7728)
		_t5 = ::tardis::Force_obj::toInt32((int(this->_t1) & int((int)1023)));
		HX_STACK_LINE(7729)
		this->_t6 = ::tardis::Force_obj::toInt32(((int)56320 + _t5));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_EncodeRune_obj,SubFn1,(void))

Void Go_utf16_EncodeRune_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf16_EncodeRune::SubFn0","tardis/Go.hx",7714);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7715)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(7716)
		_t0 = (this->p_r < (int)65536);
		HX_STACK_LINE(7717)
		this->_Next = (  ((_t0)) ? int((int)1) : int((int)4) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_EncodeRune_obj,SubFn0,(void))

::tardis::StackFrame Go_utf16_EncodeRune_obj::run( ){
	HX_STACK_PUSH("Go_utf16_EncodeRune::run","tardis/Go.hx",7673);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7673)
	while((true)){
		HX_STACK_LINE(7675)
		::tardis::Go_utf16_EncodeRune _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7675)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7677)
				{
					HX_STACK_LINE(7677)
					this->_latestPH = (int)472;
					HX_STACK_LINE(7677)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7678)
				{
					HX_STACK_LINE(7678)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(7678)
					_t0 = (this->p_r < (int)65536);
					HX_STACK_LINE(7678)
					this->_Next = (  ((_t0)) ? int((int)1) : int((int)4) );
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(7681)
				{
					HX_STACK_LINE(7681)
					this->_latestPH = (int)472;
					HX_STACK_LINE(7681)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(7682)
				this->_latestPH = (int)474;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",7683);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)65533,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(7683)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(7684)
				this->_incomplete = false;
				HX_STACK_LINE(7685)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7686)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(7689)
				{
					HX_STACK_LINE(7689)
					this->_latestPH = (int)474;
					HX_STACK_LINE(7689)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(7690)
				{
					HX_STACK_LINE(7690)
					int _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(7690)
					int _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(7690)
					int _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(7690)
					this->_t1 = ::tardis::Force_obj::toInt32((this->p_r - (int)65536));
					HX_STACK_LINE(7690)
					this->_latestPH = (int)477;
					HX_STACK_LINE(7690)
					_t2 = (int(this->_t1) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)10))));
					HX_STACK_LINE(7690)
					_t3 = ::tardis::Force_obj::toInt32((int(_t2) & int((int)1023)));
					HX_STACK_LINE(7690)
					this->_t4 = ::tardis::Force_obj::toInt32(((int)55296 + _t3));
					HX_STACK_LINE(7690)
					_t5 = ::tardis::Force_obj::toInt32((int(this->_t1) & int((int)1023)));
					HX_STACK_LINE(7690)
					this->_t6 = ::tardis::Force_obj::toInt32(((int)56320 + _t5));
				}
				HX_STACK_LINE(7691)
				this->_latestPH = (int)477;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::Go_utf16_EncodeRune_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",7692);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t4,false);
							__result->Add(HX_CSTRING("r1") , __this->_t6,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(7692)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(7693)
				this->_incomplete = false;
				HX_STACK_LINE(7694)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7695)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(7698)
				{
					HX_STACK_LINE(7698)
					this->_latestPH = (int)477;
					HX_STACK_LINE(7698)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(7699)
				this->_latestPH = (int)473;
				HX_STACK_LINE(7700)
				this->_SF1 = ::tardis::Go_utf16_IsSurrogate_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_r);
				HX_STACK_LINE(7701)
				this->_Next = (int)-1;
				HX_STACK_LINE(7702)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(7704)
				{
					HX_STACK_LINE(7704)
					this->_latestPH = (int)473;
					HX_STACK_LINE(7704)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(7705)
				this->_t7 = this->_SF1->res();
				HX_STACK_LINE(7707)
				this->_Next = (  ((this->_t7)) ? int((int)1) : int((int)2) );
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(7710)
				{
					HX_STACK_LINE(7710)
					this->_latestPH = (int)473;
					HX_STACK_LINE(7710)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(7711)
				{
					HX_STACK_LINE(7711)
					bool _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(7711)
					this->_latestPH = (int)473;
					HX_STACK_LINE(7711)
					_t8 = (this->p_r > (int)1114111);
					HX_STACK_LINE(7711)
					this->_Next = (  ((_t8)) ? int((int)1) : int((int)3) );
				}
			}
			;break;
			default: {
				HX_STACK_LINE(7713)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7673)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_EncodeRune_obj,run,return )

Dynamic Go_utf16_EncodeRune_obj::res( ){
	HX_STACK_PUSH("Go_utf16_EncodeRune::res","tardis/Go.hx",7647);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7647)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_EncodeRune_obj,res,return )

Dynamic Go_utf16_EncodeRune_obj::callFromHaxe( int p_r){
	HX_STACK_PUSH("Go_utf16_EncodeRune::callFromHaxe","tardis/Go.hx",7659);
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7660)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7660)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7661)
	::tardis::Go_utf16_EncodeRune _sf = hx::TCast< ::tardis::Go_utf16_EncodeRune >::cast(::tardis::Go_utf16_EncodeRune_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7662)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7662)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7663)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf16_EncodeRune_obj,callFromHaxe,return )

Dynamic Go_utf16_EncodeRune_obj::callFromRT( int _gr,int p_r){
	HX_STACK_PUSH("Go_utf16_EncodeRune::callFromRT","tardis/Go.hx",7665);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7666)
	::tardis::Go_utf16_EncodeRune _sf = hx::TCast< ::tardis::Go_utf16_EncodeRune >::cast(::tardis::Go_utf16_EncodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7667)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7667)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7667)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7667)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7667)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7668)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf16_EncodeRune_obj,callFromRT,return )

::tardis::Go_utf16_EncodeRune Go_utf16_EncodeRune_obj::call( int gr,Dynamic _bds,int p_r){
	HX_STACK_PUSH("Go_utf16_EncodeRune::call","tardis/Go.hx",7671);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7671)
	return ::tardis::Go_utf16_EncodeRune_obj::__new(gr,_bds,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf16_EncodeRune_obj,call,return )


Go_utf16_EncodeRune_obj::Go_utf16_EncodeRune_obj()
{
}

void Go_utf16_EncodeRune_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf16_EncodeRune);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t8,"_t8");
	HX_MARK_MEMBER_NAME(_t7,"_t7");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_t6,"_t6");
	HX_MARK_MEMBER_NAME(_t5,"_t5");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_r,"p_r");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf16_EncodeRune_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t8,"_t8");
	HX_VISIT_MEMBER_NAME(_t7,"_t7");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_t6,"_t6");
	HX_VISIT_MEMBER_NAME(_t5,"_t5");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_r,"p_r");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf16_EncodeRune_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t8") ) { return _t8; }
		if (HX_FIELD_EQ(inName,"_t7") ) { return _t7; }
		if (HX_FIELD_EQ(inName,"_t6") ) { return _t6; }
		if (HX_FIELD_EQ(inName,"_t5") ) { return _t5; }
		if (HX_FIELD_EQ(inName,"_t4") ) { return _t4; }
		if (HX_FIELD_EQ(inName,"_t3") ) { return _t3; }
		if (HX_FIELD_EQ(inName,"_t2") ) { return _t2; }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_r") ) { return p_r; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn3") ) { return SubFn3_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn2") ) { return SubFn2_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn1") ) { return SubFn1_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn0") ) { return SubFn0_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_utf16_EncodeRune_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf16_EncodeRune_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t8"));
	outFields->push(HX_CSTRING("_t7"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_t6"));
	outFields->push(HX_CSTRING("_t5"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_r"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn3"),
	HX_CSTRING("SubFn2"),
	HX_CSTRING("SubFn1"),
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_t8"),
	HX_CSTRING("_t7"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("_t6"),
	HX_CSTRING("_t5"),
	HX_CSTRING("_t4"),
	HX_CSTRING("_t3"),
	HX_CSTRING("_t2"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_r"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf16_EncodeRune_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf16_EncodeRune_obj::__mClass,"__mClass");
};

Class Go_utf16_EncodeRune_obj::__mClass;

void Go_utf16_EncodeRune_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf16_EncodeRune"), hx::TCanCast< Go_utf16_EncodeRune_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf16_EncodeRune_obj::__boot()
{
}

} // end namespace tardis
