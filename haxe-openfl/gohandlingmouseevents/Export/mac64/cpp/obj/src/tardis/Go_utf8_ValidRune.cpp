#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_ValidRune
#include <tardis/Go_utf8_ValidRune.h>
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

Void Go_utf8_ValidRune_obj::__construct(int gr,Dynamic _bds,int p_r)
{
HX_STACK_PUSH("Go_utf8_ValidRune::new","tardis/Go.hx",7058);
{
	HX_STACK_LINE(7074)
	this->_Next = (int)0;
	HX_STACK_LINE(7073)
	this->_Phi = (int)0;
	HX_STACK_LINE(7072)
	this->_t4 = false;
	HX_STACK_LINE(7071)
	this->_t3 = false;
	HX_STACK_LINE(7070)
	this->_t2 = false;
	HX_STACK_LINE(7069)
	this->_t1 = false;
	HX_STACK_LINE(7068)
	this->_t0 = false;
	HX_STACK_LINE(7061)
	super::__construct(gr,(int)966,HX_CSTRING("Go_utf8_ValidRune"));
	HX_STACK_LINE(7062)
	this->_bds = _bds;
	HX_STACK_LINE(7063)
	this->p_r = p_r;
	HX_STACK_LINE(7064)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_ValidRune_obj::~Go_utf8_ValidRune_obj() { }

Dynamic Go_utf8_ValidRune_obj::__CreateEmpty() { return  new Go_utf8_ValidRune_obj; }
hx::ObjectPtr< Go_utf8_ValidRune_obj > Go_utf8_ValidRune_obj::__new(int gr,Dynamic _bds,int p_r)
{  hx::ObjectPtr< Go_utf8_ValidRune_obj > result = new Go_utf8_ValidRune_obj();
	result->__construct(gr,_bds,p_r);
	return result;}

Dynamic Go_utf8_ValidRune_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_ValidRune_obj > result = new Go_utf8_ValidRune_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_ValidRune_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_ValidRune_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_ValidRune::SubFn4","tardis/Go.hx",7170);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7170)
		this->_Next = (  ((this->_t4)) ? int((int)2) : int((int)5) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidRune_obj,SubFn4,(void))

Void Go_utf8_ValidRune_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_ValidRune::SubFn3","tardis/Go.hx",7165);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7166)
		this->_latestPH = (int)970;
		HX_STACK_LINE(7167)
		this->_t3 = (this->p_r <= (int)57343);
		HX_STACK_LINE(7168)
		this->_Next = (int)7;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidRune_obj,SubFn3,(void))

Void Go_utf8_ValidRune_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_ValidRune::SubFn2","tardis/Go.hx",7159);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7160)
		bool _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(7161)
		this->_latestPH = (int)972;
		HX_STACK_LINE(7162)
		_t2 = (this->p_r > (int)1114111);
		HX_STACK_LINE(7163)
		this->_Next = (  ((_t2)) ? int((int)4) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidRune_obj,SubFn2,(void))

Void Go_utf8_ValidRune_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_ValidRune::SubFn1","tardis/Go.hx",7153);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7154)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(7155)
		this->_latestPH = (int)970;
		HX_STACK_LINE(7156)
		_t1 = ((int)55296 <= this->p_r);
		HX_STACK_LINE(7157)
		this->_Next = (  ((_t1)) ? int((int)6) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidRune_obj,SubFn1,(void))

Void Go_utf8_ValidRune_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_ValidRune::SubFn0","tardis/Go.hx",7147);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7148)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(7149)
		this->_latestPH = (int)968;
		HX_STACK_LINE(7150)
		_t0 = (this->p_r < (int)0);
		HX_STACK_LINE(7151)
		this->_Next = (  ((_t0)) ? int((int)1) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidRune_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_ValidRune_obj::run( ){
	HX_STACK_PUSH("Go_utf8_ValidRune::run","tardis/Go.hx",7089);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7089)
	while((true)){
		HX_STACK_LINE(7091)
		::tardis::Go_utf8_ValidRune _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7091)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7093)
				{
					HX_STACK_LINE(7093)
					this->_latestPH = (int)966;
					HX_STACK_LINE(7093)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7094)
				{
					HX_STACK_LINE(7094)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(7094)
					this->_latestPH = (int)968;
					HX_STACK_LINE(7094)
					_t0 = (this->p_r < (int)0);
					HX_STACK_LINE(7094)
					this->_Next = (  ((_t0)) ? int((int)1) : int((int)3) );
				}
				HX_STACK_LINE(7095)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(7097)
				{
					HX_STACK_LINE(7097)
					this->_latestPH = (int)966;
					HX_STACK_LINE(7097)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(7098)
				this->_latestPH = (int)969;
				HX_STACK_LINE(7099)
				this->_res = false;
				HX_STACK_LINE(7100)
				this->_incomplete = false;
				HX_STACK_LINE(7101)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7102)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(7105)
				{
					HX_STACK_LINE(7105)
					this->_latestPH = (int)969;
					HX_STACK_LINE(7105)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(7106)
				this->_latestPH = (int)971;
				HX_STACK_LINE(7107)
				this->_res = false;
				HX_STACK_LINE(7108)
				this->_incomplete = false;
				HX_STACK_LINE(7109)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7110)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(7113)
				{
					HX_STACK_LINE(7113)
					this->_latestPH = (int)971;
					HX_STACK_LINE(7113)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(7114)
				{
					HX_STACK_LINE(7114)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(7114)
					this->_latestPH = (int)970;
					HX_STACK_LINE(7114)
					_t1 = ((int)55296 <= this->p_r);
					HX_STACK_LINE(7114)
					this->_Next = (  ((_t1)) ? int((int)6) : int((int)7) );
				}
				HX_STACK_LINE(7115)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(7117)
				{
					HX_STACK_LINE(7117)
					this->_latestPH = (int)971;
					HX_STACK_LINE(7117)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(7118)
				this->_latestPH = (int)973;
				HX_STACK_LINE(7119)
				this->_res = false;
				HX_STACK_LINE(7120)
				this->_incomplete = false;
				HX_STACK_LINE(7121)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7122)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(7125)
				{
					HX_STACK_LINE(7125)
					this->_latestPH = (int)973;
					HX_STACK_LINE(7125)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(7126)
				{
					HX_STACK_LINE(7126)
					bool _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(7126)
					this->_latestPH = (int)972;
					HX_STACK_LINE(7126)
					_t2 = (this->p_r > (int)1114111);
					HX_STACK_LINE(7126)
					this->_Next = (  ((_t2)) ? int((int)4) : int((int)8) );
				}
				HX_STACK_LINE(7127)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(7129)
				{
					HX_STACK_LINE(7129)
					this->_latestPH = (int)973;
					HX_STACK_LINE(7129)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(7130)
				{
					HX_STACK_LINE(7130)
					this->_latestPH = (int)970;
					HX_STACK_LINE(7130)
					this->_t3 = (this->p_r <= (int)57343);
					HX_STACK_LINE(7130)
					this->_Next = (int)7;
				}
				HX_STACK_LINE(7131)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(7133)
				{
					HX_STACK_LINE(7133)
					this->_latestPH = (int)973;
					HX_STACK_LINE(7133)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(7134)
				this->_latestPH = (int)970;
				HX_STACK_LINE(7135)
				this->_t4 = (  (((this->_Phi == (int)3))) ? bool(false) : bool((  (((this->_Phi == (int)6))) ? bool(this->_t3) : bool(false) )) );
				HX_STACK_LINE(7136)
				this->_Next = (  ((this->_t4)) ? int((int)2) : int((int)5) );
				HX_STACK_LINE(7137)
				this->_Phi = (int)7;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(7139)
				{
					HX_STACK_LINE(7139)
					this->_latestPH = (int)970;
					HX_STACK_LINE(7139)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(7140)
				this->_latestPH = (int)975;
				HX_STACK_LINE(7141)
				this->_res = true;
				HX_STACK_LINE(7142)
				this->_incomplete = false;
				HX_STACK_LINE(7143)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7144)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(7146)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7089)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidRune_obj,run,return )

Dynamic Go_utf8_ValidRune_obj::res( ){
	HX_STACK_PUSH("Go_utf8_ValidRune::res","tardis/Go.hx",7067);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7067)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidRune_obj,res,return )

bool Go_utf8_ValidRune_obj::callFromHaxe( int p_r){
	HX_STACK_PUSH("Go_utf8_ValidRune::callFromHaxe","tardis/Go.hx",7075);
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7076)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7076)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7077)
	::tardis::Go_utf8_ValidRune _sf = hx::TCast< ::tardis::Go_utf8_ValidRune >::cast(::tardis::Go_utf8_ValidRune_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7078)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7078)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7079)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_ValidRune_obj,callFromHaxe,return )

bool Go_utf8_ValidRune_obj::callFromRT( int _gr,int p_r){
	HX_STACK_PUSH("Go_utf8_ValidRune::callFromRT","tardis/Go.hx",7081);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7082)
	::tardis::Go_utf8_ValidRune _sf = hx::TCast< ::tardis::Go_utf8_ValidRune >::cast(::tardis::Go_utf8_ValidRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7083)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7083)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7083)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7083)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7083)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7084)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_ValidRune_obj,callFromRT,return )

::tardis::Go_utf8_ValidRune Go_utf8_ValidRune_obj::call( int gr,Dynamic _bds,int p_r){
	HX_STACK_PUSH("Go_utf8_ValidRune::call","tardis/Go.hx",7087);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7087)
	return ::tardis::Go_utf8_ValidRune_obj::__new(gr,_bds,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_ValidRune_obj,call,return )


Go_utf8_ValidRune_obj::Go_utf8_ValidRune_obj()
{
}

void Go_utf8_ValidRune_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_ValidRune);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
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

void Go_utf8_ValidRune_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_r,"p_r");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_ValidRune_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
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
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
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

Dynamic Go_utf8_ValidRune_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_ValidRune_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
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
	HX_CSTRING("SubFn4"),
	HX_CSTRING("SubFn3"),
	HX_CSTRING("SubFn2"),
	HX_CSTRING("SubFn1"),
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_Phi"),
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
	HX_MARK_MEMBER_NAME(Go_utf8_ValidRune_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_ValidRune_obj::__mClass,"__mClass");
};

Class Go_utf8_ValidRune_obj::__mClass;

void Go_utf8_ValidRune_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_ValidRune"), hx::TCanCast< Go_utf8_ValidRune_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_ValidRune_obj::__boot()
{
}

} // end namespace tardis
