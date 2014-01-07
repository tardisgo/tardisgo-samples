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
#ifndef INCLUDED_tardis_Go_utf16_DecodeRune
#include <tardis/Go_utf16_DecodeRune.h>
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

Void Go_utf16_DecodeRune_obj::__construct(int gr,Dynamic _bds,int p_r1,int p_r2)
{
HX_STACK_PUSH("Go_utf16_DecodeRune::new","tardis/Go.hx",2206);
{
	HX_STACK_LINE(2227)
	this->_Next = (int)0;
	HX_STACK_LINE(2226)
	this->_t8 = false;
	HX_STACK_LINE(2225)
	this->_t7 = false;
	HX_STACK_LINE(2224)
	this->_t6 = false;
	HX_STACK_LINE(2223)
	this->_t5 = (int)0;
	HX_STACK_LINE(2222)
	this->_t4 = (int)0;
	HX_STACK_LINE(2221)
	this->_t3 = (int)0;
	HX_STACK_LINE(2220)
	this->_t2 = (int)0;
	HX_STACK_LINE(2219)
	this->_t1 = (int)0;
	HX_STACK_LINE(2218)
	this->_t0 = false;
	HX_STACK_LINE(2210)
	super::__construct(gr,(int)462,HX_CSTRING("Go_utf16_DecodeRune"));
	HX_STACK_LINE(2211)
	this->_bds = _bds;
	HX_STACK_LINE(2212)
	this->p_r1 = p_r1;
	HX_STACK_LINE(2213)
	this->p_r2 = p_r2;
	HX_STACK_LINE(2214)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf16_DecodeRune_obj::~Go_utf16_DecodeRune_obj() { }

Dynamic Go_utf16_DecodeRune_obj::__CreateEmpty() { return  new Go_utf16_DecodeRune_obj; }
hx::ObjectPtr< Go_utf16_DecodeRune_obj > Go_utf16_DecodeRune_obj::__new(int gr,Dynamic _bds,int p_r1,int p_r2)
{  hx::ObjectPtr< Go_utf16_DecodeRune_obj > result = new Go_utf16_DecodeRune_obj();
	result->__construct(gr,_bds,p_r1,p_r2);
	return result;}

Dynamic Go_utf16_DecodeRune_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf16_DecodeRune_obj > result = new Go_utf16_DecodeRune_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Go_utf16_DecodeRune_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf16_DecodeRune_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf16_DecodeRune::SubFn4","tardis/Go.hx",2308);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2309)
		bool _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(2310)
		_t8 = (this->p_r1 < (int)56320);
		HX_STACK_LINE(2311)
		this->_Next = (  ((_t8)) ? int((int)4) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_DecodeRune_obj,SubFn4,(void))

Void Go_utf16_DecodeRune_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf16_DecodeRune::SubFn3","tardis/Go.hx",2303);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2304)
		bool _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(2305)
		_t7 = ((int)56320 <= this->p_r2);
		HX_STACK_LINE(2306)
		this->_Next = (  ((_t7)) ? int((int)3) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_DecodeRune_obj,SubFn3,(void))

Void Go_utf16_DecodeRune_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf16_DecodeRune::SubFn2","tardis/Go.hx",2297);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2298)
		bool _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(2299)
		this->_latestPH = (int)463;
		HX_STACK_LINE(2300)
		_t6 = (this->p_r2 < (int)57344);
		HX_STACK_LINE(2301)
		this->_Next = (  ((_t6)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_DecodeRune_obj,SubFn2,(void))

Void Go_utf16_DecodeRune_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf16_DecodeRune::SubFn1","tardis/Go.hx",2285);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2286)
		int _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(2287)
		int _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(2288)
		int _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(2289)
		int _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(2290)
		this->_latestPH = (int)464;
		HX_STACK_LINE(2291)
		_t1 = ::tardis::Force_obj::toInt32((this->p_r1 - (int)55296));
		HX_STACK_LINE(2292)
		_t2 = (int(_t1) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)10))));
		HX_STACK_LINE(2293)
		_t3 = ::tardis::Force_obj::toInt32((this->p_r2 - (int)56320));
		HX_STACK_LINE(2294)
		_t4 = ::tardis::Force_obj::toInt32((int(_t2) | int(_t3)));
		HX_STACK_LINE(2295)
		this->_t5 = ::tardis::Force_obj::toInt32((_t4 + (int)65536));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_DecodeRune_obj,SubFn1,(void))

Void Go_utf16_DecodeRune_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf16_DecodeRune::SubFn0","tardis/Go.hx",2279);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2280)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(2281)
		this->_latestPH = (int)463;
		HX_STACK_LINE(2282)
		_t0 = ((int)55296 <= this->p_r1);
		HX_STACK_LINE(2283)
		this->_Next = (  ((_t0)) ? int((int)5) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_DecodeRune_obj,SubFn0,(void))

::tardis::StackFrame Go_utf16_DecodeRune_obj::run( ){
	HX_STACK_PUSH("Go_utf16_DecodeRune::run","tardis/Go.hx",2242);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2242)
	while((true)){
		HX_STACK_LINE(2244)
		::tardis::Go_utf16_DecodeRune _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2244)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(2246)
				{
					HX_STACK_LINE(2246)
					this->_latestPH = (int)462;
					HX_STACK_LINE(2246)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(2247)
				{
					HX_STACK_LINE(2247)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(2247)
					this->_latestPH = (int)463;
					HX_STACK_LINE(2247)
					_t0 = ((int)55296 <= this->p_r1);
					HX_STACK_LINE(2247)
					this->_Next = (  ((_t0)) ? int((int)5) : int((int)2) );
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(2250)
				{
					HX_STACK_LINE(2250)
					this->_latestPH = (int)462;
					HX_STACK_LINE(2250)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(2251)
				{
					HX_STACK_LINE(2251)
					int _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(2251)
					int _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(2251)
					int _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(2251)
					int _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(2251)
					this->_latestPH = (int)464;
					HX_STACK_LINE(2251)
					_t1 = ::tardis::Force_obj::toInt32((this->p_r1 - (int)55296));
					HX_STACK_LINE(2251)
					_t2 = (int(_t1) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)10))));
					HX_STACK_LINE(2251)
					_t3 = ::tardis::Force_obj::toInt32((this->p_r2 - (int)56320));
					HX_STACK_LINE(2251)
					_t4 = ::tardis::Force_obj::toInt32((int(_t2) | int(_t3)));
					HX_STACK_LINE(2251)
					this->_t5 = ::tardis::Force_obj::toInt32((_t4 + (int)65536));
				}
				HX_STACK_LINE(2252)
				this->_latestPH = (int)464;
				HX_STACK_LINE(2253)
				this->_res = this->_t5;
				HX_STACK_LINE(2254)
				this->_incomplete = false;
				HX_STACK_LINE(2255)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2256)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(2259)
				{
					HX_STACK_LINE(2259)
					this->_latestPH = (int)464;
					HX_STACK_LINE(2259)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(2260)
				this->_latestPH = (int)466;
				HX_STACK_LINE(2261)
				this->_res = (int)65533;
				HX_STACK_LINE(2262)
				this->_incomplete = false;
				HX_STACK_LINE(2263)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2264)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(2267)
				{
					HX_STACK_LINE(2267)
					this->_latestPH = (int)466;
					HX_STACK_LINE(2267)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(2268)
				{
					HX_STACK_LINE(2268)
					bool _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(2268)
					this->_latestPH = (int)463;
					HX_STACK_LINE(2268)
					_t6 = (this->p_r2 < (int)57344);
					HX_STACK_LINE(2268)
					this->_Next = (  ((_t6)) ? int((int)1) : int((int)2) );
				}
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(2271)
				{
					HX_STACK_LINE(2271)
					this->_latestPH = (int)466;
					HX_STACK_LINE(2271)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(2272)
				{
					HX_STACK_LINE(2272)
					bool _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(2272)
					_t7 = ((int)56320 <= this->p_r2);
					HX_STACK_LINE(2272)
					this->_Next = (  ((_t7)) ? int((int)3) : int((int)2) );
				}
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(2275)
				{
					HX_STACK_LINE(2275)
					this->_latestPH = (int)466;
					HX_STACK_LINE(2275)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(2276)
				{
					HX_STACK_LINE(2276)
					bool _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(2276)
					_t8 = (this->p_r1 < (int)56320);
					HX_STACK_LINE(2276)
					this->_Next = (  ((_t8)) ? int((int)4) : int((int)2) );
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2278)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(2242)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_DecodeRune_obj,run,return )

Dynamic Go_utf16_DecodeRune_obj::res( ){
	HX_STACK_PUSH("Go_utf16_DecodeRune::res","tardis/Go.hx",2217);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2217)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_DecodeRune_obj,res,return )

int Go_utf16_DecodeRune_obj::callFromHaxe( int p_r1,int p_r2){
	HX_STACK_PUSH("Go_utf16_DecodeRune::callFromHaxe","tardis/Go.hx",2228);
	HX_STACK_ARG(p_r1,"p_r1");
	HX_STACK_ARG(p_r2,"p_r2");
	HX_STACK_LINE(2229)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(2229)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(2230)
	::tardis::Go_utf16_DecodeRune _sf = hx::TCast< ::tardis::Go_utf16_DecodeRune >::cast(::tardis::Go_utf16_DecodeRune_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r1,p_r2)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2231)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2231)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(2232)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf16_DecodeRune_obj,callFromHaxe,return )

int Go_utf16_DecodeRune_obj::callFromRT( int _gr,int p_r1,int p_r2){
	HX_STACK_PUSH("Go_utf16_DecodeRune::callFromRT","tardis/Go.hx",2234);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r1,"p_r1");
	HX_STACK_ARG(p_r2,"p_r2");
	HX_STACK_LINE(2235)
	::tardis::Go_utf16_DecodeRune _sf = hx::TCast< ::tardis::Go_utf16_DecodeRune >::cast(::tardis::Go_utf16_DecodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r1,p_r2)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2236)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2236)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(2236)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(2236)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(2236)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(2237)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf16_DecodeRune_obj,callFromRT,return )

::tardis::Go_utf16_DecodeRune Go_utf16_DecodeRune_obj::call( int gr,Dynamic _bds,int p_r1,int p_r2){
	HX_STACK_PUSH("Go_utf16_DecodeRune::call","tardis/Go.hx",2240);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r1,"p_r1");
	HX_STACK_ARG(p_r2,"p_r2");
	HX_STACK_LINE(2240)
	return ::tardis::Go_utf16_DecodeRune_obj::__new(gr,_bds,p_r1,p_r2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Go_utf16_DecodeRune_obj,call,return )


Go_utf16_DecodeRune_obj::Go_utf16_DecodeRune_obj()
{
}

void Go_utf16_DecodeRune_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf16_DecodeRune);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t8,"_t8");
	HX_MARK_MEMBER_NAME(_t7,"_t7");
	HX_MARK_MEMBER_NAME(_t6,"_t6");
	HX_MARK_MEMBER_NAME(_t5,"_t5");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_r2,"p_r2");
	HX_MARK_MEMBER_NAME(p_r1,"p_r1");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf16_DecodeRune_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t8,"_t8");
	HX_VISIT_MEMBER_NAME(_t7,"_t7");
	HX_VISIT_MEMBER_NAME(_t6,"_t6");
	HX_VISIT_MEMBER_NAME(_t5,"_t5");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_r2,"p_r2");
	HX_VISIT_MEMBER_NAME(p_r1,"p_r1");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf16_DecodeRune_obj::__Field(const ::String &inName,bool inCallProp)
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
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		if (HX_FIELD_EQ(inName,"p_r2") ) { return p_r2; }
		if (HX_FIELD_EQ(inName,"p_r1") ) { return p_r1; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn4") ) { return SubFn4_dyn(); }
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

Dynamic Go_utf16_DecodeRune_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r2") ) { p_r2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r1") ) { p_r1=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf16_DecodeRune_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t8"));
	outFields->push(HX_CSTRING("_t7"));
	outFields->push(HX_CSTRING("_t6"));
	outFields->push(HX_CSTRING("_t5"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_r2"));
	outFields->push(HX_CSTRING("p_r1"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn4"),
	HX_CSTRING("SubFn3"),
	HX_CSTRING("SubFn2"),
	HX_CSTRING("SubFn1"),
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_t8"),
	HX_CSTRING("_t7"),
	HX_CSTRING("_t6"),
	HX_CSTRING("_t5"),
	HX_CSTRING("_t4"),
	HX_CSTRING("_t3"),
	HX_CSTRING("_t2"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_r2"),
	HX_CSTRING("p_r1"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf16_DecodeRune_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf16_DecodeRune_obj::__mClass,"__mClass");
};

Class Go_utf16_DecodeRune_obj::__mClass;

void Go_utf16_DecodeRune_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf16_DecodeRune"), hx::TCanCast< Go_utf16_DecodeRune_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf16_DecodeRune_obj::__boot()
{
}

} // end namespace tardis
