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
#ifndef INCLUDED_tardis_Go_utf8_RuneLen
#include <tardis/Go_utf8_RuneLen.h>
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

Void Go_utf8_RuneLen_obj::__construct(int gr,Dynamic _bds,int p_r)
{
HX_STACK_PUSH("Go_utf8_RuneLen::new","tardis/Go.hx",7741);
{
	HX_STACK_LINE(7760)
	this->_Next = (int)0;
	HX_STACK_LINE(7759)
	this->_Phi = (int)0;
	HX_STACK_LINE(7758)
	this->_t7 = false;
	HX_STACK_LINE(7757)
	this->_t6 = false;
	HX_STACK_LINE(7756)
	this->_t5 = false;
	HX_STACK_LINE(7755)
	this->_t4 = false;
	HX_STACK_LINE(7754)
	this->_t3 = false;
	HX_STACK_LINE(7753)
	this->_t2 = false;
	HX_STACK_LINE(7752)
	this->_t1 = false;
	HX_STACK_LINE(7751)
	this->_t0 = false;
	HX_STACK_LINE(7744)
	super::__construct(gr,(int)843,HX_CSTRING("Go_utf8_RuneLen"));
	HX_STACK_LINE(7745)
	this->_bds = _bds;
	HX_STACK_LINE(7746)
	this->p_r = p_r;
	HX_STACK_LINE(7747)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_RuneLen_obj::~Go_utf8_RuneLen_obj() { }

Dynamic Go_utf8_RuneLen_obj::__CreateEmpty() { return  new Go_utf8_RuneLen_obj; }
hx::ObjectPtr< Go_utf8_RuneLen_obj > Go_utf8_RuneLen_obj::__new(int gr,Dynamic _bds,int p_r)
{  hx::ObjectPtr< Go_utf8_RuneLen_obj > result = new Go_utf8_RuneLen_obj();
	result->__construct(gr,_bds,p_r);
	return result;}

Dynamic Go_utf8_RuneLen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_RuneLen_obj > result = new Go_utf8_RuneLen_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_RuneLen_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_RuneLen_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn7","tardis/Go.hx",7907);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7908)
		bool _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(7909)
		this->_latestPH = (int)855;
		HX_STACK_LINE(7910)
		_t7 = (this->p_r <= (int)1114111);
		HX_STACK_LINE(7911)
		this->_Next = (  ((_t7)) ? int((int)12) : int((int)14) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn7,(void))

Void Go_utf8_RuneLen_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn6","tardis/Go.hx",7904);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7904)
		this->_Next = (  ((this->_t6)) ? int((int)6) : int((int)9) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn6,(void))

Void Go_utf8_RuneLen_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn5","tardis/Go.hx",7899);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7900)
		this->_latestPH = (int)851;
		HX_STACK_LINE(7901)
		this->_t5 = (this->p_r <= (int)57343);
		HX_STACK_LINE(7902)
		this->_Next = (int)11;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn5,(void))

Void Go_utf8_RuneLen_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn4","tardis/Go.hx",7893);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7894)
		bool _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(7895)
		this->_latestPH = (int)853;
		HX_STACK_LINE(7896)
		_t4 = (this->p_r <= (int)65535);
		HX_STACK_LINE(7897)
		this->_Next = (  ((_t4)) ? int((int)8) : int((int)13) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn4,(void))

Void Go_utf8_RuneLen_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn3","tardis/Go.hx",7887);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7888)
		bool _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(7889)
		this->_latestPH = (int)851;
		HX_STACK_LINE(7890)
		_t3 = ((int)55296 <= this->p_r);
		HX_STACK_LINE(7891)
		this->_Next = (  ((_t3)) ? int((int)10) : int((int)11) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn3,(void))

Void Go_utf8_RuneLen_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn2","tardis/Go.hx",7881);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7882)
		bool _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(7883)
		this->_latestPH = (int)849;
		HX_STACK_LINE(7884)
		_t2 = (this->p_r <= (int)2047);
		HX_STACK_LINE(7885)
		this->_Next = (  ((_t2)) ? int((int)4) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn2,(void))

Void Go_utf8_RuneLen_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn1","tardis/Go.hx",7875);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7876)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(7877)
		this->_latestPH = (int)847;
		HX_STACK_LINE(7878)
		_t1 = (this->p_r <= (int)127);
		HX_STACK_LINE(7879)
		this->_Next = (  ((_t1)) ? int((int)2) : int((int)5) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn1,(void))

Void Go_utf8_RuneLen_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_RuneLen::SubFn0","tardis/Go.hx",7869);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7870)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(7871)
		this->_latestPH = (int)845;
		HX_STACK_LINE(7872)
		_t0 = (this->p_r < (int)0);
		HX_STACK_LINE(7873)
		this->_Next = (  ((_t0)) ? int((int)1) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_RuneLen_obj::run( ){
	HX_STACK_PUSH("Go_utf8_RuneLen::run","tardis/Go.hx",7775);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7775)
	while((true)){
		HX_STACK_LINE(7777)
		::tardis::Go_utf8_RuneLen _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7777)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7779)
				{
					HX_STACK_LINE(7779)
					this->_latestPH = (int)843;
					HX_STACK_LINE(7779)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7780)
				{
					HX_STACK_LINE(7780)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(7780)
					this->_latestPH = (int)845;
					HX_STACK_LINE(7780)
					_t0 = (this->p_r < (int)0);
					HX_STACK_LINE(7780)
					this->_Next = (  ((_t0)) ? int((int)1) : int((int)3) );
				}
				HX_STACK_LINE(7781)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(7783)
				{
					HX_STACK_LINE(7783)
					this->_latestPH = (int)843;
					HX_STACK_LINE(7783)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(7784)
				this->_latestPH = (int)846;
				HX_STACK_LINE(7785)
				this->_res = (int)-1;
				HX_STACK_LINE(7786)
				this->_incomplete = false;
				HX_STACK_LINE(7787)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7788)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(7791)
				{
					HX_STACK_LINE(7791)
					this->_latestPH = (int)846;
					HX_STACK_LINE(7791)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(7792)
				this->_latestPH = (int)848;
				HX_STACK_LINE(7793)
				this->_res = (int)1;
				HX_STACK_LINE(7794)
				this->_incomplete = false;
				HX_STACK_LINE(7795)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7796)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(7799)
				{
					HX_STACK_LINE(7799)
					this->_latestPH = (int)848;
					HX_STACK_LINE(7799)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(7800)
				{
					HX_STACK_LINE(7800)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(7800)
					this->_latestPH = (int)847;
					HX_STACK_LINE(7800)
					_t1 = (this->p_r <= (int)127);
					HX_STACK_LINE(7800)
					this->_Next = (  ((_t1)) ? int((int)2) : int((int)5) );
				}
				HX_STACK_LINE(7801)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(7803)
				{
					HX_STACK_LINE(7803)
					this->_latestPH = (int)848;
					HX_STACK_LINE(7803)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(7804)
				this->_latestPH = (int)850;
				HX_STACK_LINE(7805)
				this->_res = (int)2;
				HX_STACK_LINE(7806)
				this->_incomplete = false;
				HX_STACK_LINE(7807)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7808)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(7811)
				{
					HX_STACK_LINE(7811)
					this->_latestPH = (int)850;
					HX_STACK_LINE(7811)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(7812)
				{
					HX_STACK_LINE(7812)
					bool _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(7812)
					this->_latestPH = (int)849;
					HX_STACK_LINE(7812)
					_t2 = (this->p_r <= (int)2047);
					HX_STACK_LINE(7812)
					this->_Next = (  ((_t2)) ? int((int)4) : int((int)7) );
				}
				HX_STACK_LINE(7813)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(7815)
				{
					HX_STACK_LINE(7815)
					this->_latestPH = (int)850;
					HX_STACK_LINE(7815)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(7816)
				this->_latestPH = (int)852;
				HX_STACK_LINE(7817)
				this->_res = (int)-1;
				HX_STACK_LINE(7818)
				this->_incomplete = false;
				HX_STACK_LINE(7819)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7820)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(7823)
				{
					HX_STACK_LINE(7823)
					this->_latestPH = (int)852;
					HX_STACK_LINE(7823)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(7824)
				{
					HX_STACK_LINE(7824)
					bool _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(7824)
					this->_latestPH = (int)851;
					HX_STACK_LINE(7824)
					_t3 = ((int)55296 <= this->p_r);
					HX_STACK_LINE(7824)
					this->_Next = (  ((_t3)) ? int((int)10) : int((int)11) );
				}
				HX_STACK_LINE(7825)
				this->_Phi = (int)7;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(7827)
				{
					HX_STACK_LINE(7827)
					this->_latestPH = (int)852;
					HX_STACK_LINE(7827)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(7828)
				this->_latestPH = (int)854;
				HX_STACK_LINE(7829)
				this->_res = (int)3;
				HX_STACK_LINE(7830)
				this->_incomplete = false;
				HX_STACK_LINE(7831)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7832)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(7835)
				{
					HX_STACK_LINE(7835)
					this->_latestPH = (int)854;
					HX_STACK_LINE(7835)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(7836)
				{
					HX_STACK_LINE(7836)
					bool _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(7836)
					this->_latestPH = (int)853;
					HX_STACK_LINE(7836)
					_t4 = (this->p_r <= (int)65535);
					HX_STACK_LINE(7836)
					this->_Next = (  ((_t4)) ? int((int)8) : int((int)13) );
				}
				HX_STACK_LINE(7837)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(7839)
				{
					HX_STACK_LINE(7839)
					this->_latestPH = (int)854;
					HX_STACK_LINE(7839)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(7840)
				{
					HX_STACK_LINE(7840)
					this->_latestPH = (int)851;
					HX_STACK_LINE(7840)
					this->_t5 = (this->p_r <= (int)57343);
					HX_STACK_LINE(7840)
					this->_Next = (int)11;
				}
				HX_STACK_LINE(7841)
				this->_Phi = (int)10;
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(7843)
				{
					HX_STACK_LINE(7843)
					this->_latestPH = (int)854;
					HX_STACK_LINE(7843)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(7844)
				this->_latestPH = (int)851;
				HX_STACK_LINE(7845)
				this->_t6 = (  (((this->_Phi == (int)7))) ? bool(false) : bool((  (((this->_Phi == (int)10))) ? bool(this->_t5) : bool(false) )) );
				HX_STACK_LINE(7846)
				this->_Next = (  ((this->_t6)) ? int((int)6) : int((int)9) );
				HX_STACK_LINE(7847)
				this->_Phi = (int)11;
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(7849)
				{
					HX_STACK_LINE(7849)
					this->_latestPH = (int)851;
					HX_STACK_LINE(7849)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(7850)
				this->_latestPH = (int)856;
				HX_STACK_LINE(7851)
				this->_res = (int)4;
				HX_STACK_LINE(7852)
				this->_incomplete = false;
				HX_STACK_LINE(7853)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7854)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(7857)
				{
					HX_STACK_LINE(7857)
					this->_latestPH = (int)856;
					HX_STACK_LINE(7857)
					this->_latestBlock = (int)13;
				}
				HX_STACK_LINE(7858)
				{
					HX_STACK_LINE(7858)
					bool _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(7858)
					this->_latestPH = (int)855;
					HX_STACK_LINE(7858)
					_t7 = (this->p_r <= (int)1114111);
					HX_STACK_LINE(7858)
					this->_Next = (  ((_t7)) ? int((int)12) : int((int)14) );
				}
				HX_STACK_LINE(7859)
				this->_Phi = (int)13;
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(7861)
				{
					HX_STACK_LINE(7861)
					this->_latestPH = (int)856;
					HX_STACK_LINE(7861)
					this->_latestBlock = (int)14;
				}
				HX_STACK_LINE(7862)
				this->_latestPH = (int)858;
				HX_STACK_LINE(7863)
				this->_res = (int)-1;
				HX_STACK_LINE(7864)
				this->_incomplete = false;
				HX_STACK_LINE(7865)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7866)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(7868)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7775)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,run,return )

Dynamic Go_utf8_RuneLen_obj::res( ){
	HX_STACK_PUSH("Go_utf8_RuneLen::res","tardis/Go.hx",7750);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7750)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneLen_obj,res,return )

int Go_utf8_RuneLen_obj::callFromHaxe( int p_r){
	HX_STACK_PUSH("Go_utf8_RuneLen::callFromHaxe","tardis/Go.hx",7761);
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7762)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7762)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7763)
	::tardis::Go_utf8_RuneLen _sf = hx::TCast< ::tardis::Go_utf8_RuneLen >::cast(::tardis::Go_utf8_RuneLen_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7764)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7764)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7765)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_RuneLen_obj,callFromHaxe,return )

int Go_utf8_RuneLen_obj::callFromRT( int _gr,int p_r){
	HX_STACK_PUSH("Go_utf8_RuneLen::callFromRT","tardis/Go.hx",7767);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7768)
	::tardis::Go_utf8_RuneLen _sf = hx::TCast< ::tardis::Go_utf8_RuneLen >::cast(::tardis::Go_utf8_RuneLen_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7769)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7769)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7769)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7769)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7769)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7770)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_RuneLen_obj,callFromRT,return )

::tardis::Go_utf8_RuneLen Go_utf8_RuneLen_obj::call( int gr,Dynamic _bds,int p_r){
	HX_STACK_PUSH("Go_utf8_RuneLen::call","tardis/Go.hx",7773);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7773)
	return ::tardis::Go_utf8_RuneLen_obj::__new(gr,_bds,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_RuneLen_obj,call,return )


Go_utf8_RuneLen_obj::Go_utf8_RuneLen_obj()
{
}

void Go_utf8_RuneLen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_RuneLen);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t7,"_t7");
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

void Go_utf8_RuneLen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t7,"_t7");
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

Dynamic Go_utf8_RuneLen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
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
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn7") ) { return SubFn7_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn6") ) { return SubFn6_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn5") ) { return SubFn5_dyn(); }
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

Dynamic Go_utf8_RuneLen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_RuneLen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t7"));
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
	HX_CSTRING("SubFn7"),
	HX_CSTRING("SubFn6"),
	HX_CSTRING("SubFn5"),
	HX_CSTRING("SubFn4"),
	HX_CSTRING("SubFn3"),
	HX_CSTRING("SubFn2"),
	HX_CSTRING("SubFn1"),
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_Phi"),
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
	HX_CSTRING("p_r"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_RuneLen_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_RuneLen_obj::__mClass,"__mClass");
};

Class Go_utf8_RuneLen_obj::__mClass;

void Go_utf8_RuneLen_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_RuneLen"), hx::TCanCast< Go_utf8_RuneLen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_RuneLen_obj::__boot()
{
}

} // end namespace tardis
