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
#ifndef INCLUDED_tardis_Go_utf8_DecodeRune
#include <tardis/Go_utf8_DecodeRune.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_Valid
#include <tardis/Go_utf8_Valid.h>
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
#ifndef INCLUDED_tardis_Slice
#include <tardis/Slice.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif
namespace tardis{

Void Go_utf8_Valid_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_p)
{
HX_STACK_PUSH("Go_utf8_Valid::new","tardis/Go.hx",6393);
{
	HX_STACK_LINE(6417)
	this->_Next = (int)0;
	HX_STACK_LINE(6416)
	this->_Phi = (int)0;
	HX_STACK_LINE(6415)
	this->_t12 = (int)0;
	HX_STACK_LINE(6414)
	this->_t11 = false;
	HX_STACK_LINE(6413)
	this->_t10 = (int)0;
	HX_STACK_LINE(6412)
	this->_t8 = null();
	HX_STACK_LINE(6410)
	this->_t7 = null();
	HX_STACK_LINE(6409)
	this->_t6 = (int)0;
	HX_STACK_LINE(6408)
	this->_t5 = false;
	HX_STACK_LINE(6407)
	this->_t4 = (int)0;
	HX_STACK_LINE(6406)
	this->_t3 = (int)0;
	HX_STACK_LINE(6405)
	this->_t2 = false;
	HX_STACK_LINE(6404)
	this->_t1 = (int)0;
	HX_STACK_LINE(6403)
	this->_t0 = null();
	HX_STACK_LINE(6396)
	super::__construct(gr,(int)928,HX_CSTRING("Go_utf8_Valid"));
	HX_STACK_LINE(6397)
	this->_bds = _bds;
	HX_STACK_LINE(6398)
	this->p_p = p_p;
	HX_STACK_LINE(6399)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_Valid_obj::~Go_utf8_Valid_obj() { }

Dynamic Go_utf8_Valid_obj::__CreateEmpty() { return  new Go_utf8_Valid_obj; }
hx::ObjectPtr< Go_utf8_Valid_obj > Go_utf8_Valid_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_p)
{  hx::ObjectPtr< Go_utf8_Valid_obj > result = new Go_utf8_Valid_obj();
	result->__construct(gr,_bds,p_p);
	return result;}

Dynamic Go_utf8_Valid_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_Valid_obj > result = new Go_utf8_Valid_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_Valid_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_Valid_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_Valid::SubFn6","tardis/Go.hx",6525);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6526)
		this->_t12 = (this->_t3 + this->_t10);
		HX_STACK_LINE(6527)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,SubFn6,(void))

Void Go_utf8_Valid_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_Valid::SubFn5","tardis/Go.hx",6517);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6518)
		bool _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(6520)
		this->_t10 = this->_t8->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(6521)
		this->_latestPH = (int)935;
		HX_STACK_LINE(6522)
		_t11 = (this->_t10 == (int)1);
		HX_STACK_LINE(6523)
		this->_Next = (  ((_t11)) ? int((int)6) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,SubFn5,(void))

Void Go_utf8_Valid_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_Valid::SubFn4","tardis/Go.hx",6513);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6514)
		this->_latestPH = (int)934;
		HX_STACK_LINE(6515)
		this->_t7 = this->p_p->subSlice(this->_t3,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,SubFn4,(void))

Void Go_utf8_Valid_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_Valid::SubFn3","tardis/Go.hx",6509);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6510)
		this->_t6 = (this->_t3 + (int)1);
		HX_STACK_LINE(6511)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,SubFn3,(void))

Void Go_utf8_Valid_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_Valid::SubFn2","tardis/Go.hx",6501);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6502)
		int _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(6503)
		bool _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(6504)
		this->_latestPH = (int)930;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_Valid_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6505);
				{
					HX_STACK_LINE(6505)
					::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6505)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(6505)
		_t4 = _Function_1_1::Block(this);
		HX_STACK_LINE(6506)
		_t5 = (this->_t3 < _t4);
		HX_STACK_LINE(6507)
		this->_Next = (  ((_t5)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,SubFn2,(void))

Void Go_utf8_Valid_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_Valid::SubFn1","tardis/Go.hx",6490);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6491)
		::tardis::Pointer _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(6492)
		int _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(6493)
		bool _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(6494)
		this->_latestPH = (int)931;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_Valid_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6495);
				{
					HX_STACK_LINE(6495)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(6495)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(6495)
		if (((bool((this->_t3 < (int)0)) || bool((this->_t3 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(6495)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(6496)
		_t0 = this->p_p->addr(this->_t3);
		HX_STACK_LINE(6497)
		_t1 = (int(_t0->ref()) | int((int)0));
		HX_STACK_LINE(6498)
		_t2 = (::tardis::Force_obj::uintCompare(_t1,(int)128) < (int)0);
		HX_STACK_LINE(6499)
		this->_Next = (  ((_t2)) ? int((int)4) : int((int)5) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,SubFn1,(void))

Void Go_utf8_Valid_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_Valid::SubFn0","tardis/Go.hx",6487);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6487)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_Valid_obj::run( ){
	HX_STACK_PUSH("Go_utf8_Valid::run","tardis/Go.hx",6432);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6432)
	while((true)){
		HX_STACK_LINE(6434)
		::tardis::Go_utf8_Valid _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(6434)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(6436)
				{
					HX_STACK_LINE(6436)
					this->_latestPH = (int)928;
					HX_STACK_LINE(6436)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(6437)
				this->_Next = (int)3;
				HX_STACK_LINE(6438)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(6440)
				{
					HX_STACK_LINE(6440)
					this->_latestPH = (int)928;
					HX_STACK_LINE(6440)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(6441)
				{
					HX_STACK_LINE(6441)
					::tardis::Pointer _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(6441)
					int _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(6441)
					bool _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(6441)
					this->_latestPH = (int)931;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_Valid_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6441);
							{
								HX_STACK_LINE(6441)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(6441)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(6441)
					if (((bool((this->_t3 < (int)0)) || bool((this->_t3 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(6441)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(6441)
					_t0 = this->p_p->addr(this->_t3);
					HX_STACK_LINE(6441)
					_t1 = (int(_t0->ref()) | int((int)0));
					HX_STACK_LINE(6441)
					_t2 = (::tardis::Force_obj::uintCompare(_t1,(int)128) < (int)0);
					HX_STACK_LINE(6441)
					this->_Next = (  ((_t2)) ? int((int)4) : int((int)5) );
				}
				HX_STACK_LINE(6442)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(6444)
				{
					HX_STACK_LINE(6444)
					this->_latestPH = (int)928;
					HX_STACK_LINE(6444)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(6445)
				this->_latestPH = (int)944;
				HX_STACK_LINE(6446)
				this->_res = true;
				HX_STACK_LINE(6447)
				this->_incomplete = false;
				HX_STACK_LINE(6448)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6449)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(6452)
				{
					HX_STACK_LINE(6452)
					this->_latestPH = (int)944;
					HX_STACK_LINE(6452)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(6453)
				this->_latestPH = (int)929;
				HX_STACK_LINE(6454)
				this->_t3 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)4))) ? int(this->_t6) : int((  (((this->_Phi == (int)7))) ? int(this->_t12) : int((int)0) )) )) );
				HX_STACK_LINE(6455)
				{
					HX_STACK_LINE(6455)
					int _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(6455)
					bool _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(6455)
					this->_latestPH = (int)930;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_Valid_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6455);
							{
								HX_STACK_LINE(6455)
								::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6455)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(6455)
					_t4 = _Function_4_1::Block(this);
					HX_STACK_LINE(6455)
					_t5 = (this->_t3 < _t4);
					HX_STACK_LINE(6455)
					this->_Next = (  ((_t5)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(6456)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(6458)
				{
					HX_STACK_LINE(6458)
					this->_latestPH = (int)929;
					HX_STACK_LINE(6458)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(6459)
				{
					HX_STACK_LINE(6459)
					this->_t6 = (this->_t3 + (int)1);
					HX_STACK_LINE(6459)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(6460)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(6462)
				{
					HX_STACK_LINE(6462)
					this->_latestPH = (int)929;
					HX_STACK_LINE(6462)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(6463)
				{
					HX_STACK_LINE(6463)
					this->_latestPH = (int)934;
					HX_STACK_LINE(6463)
					this->_t7 = this->p_p->subSlice(this->_t3,(int)-1);
				}
				HX_STACK_LINE(6464)
				this->_latestPH = (int)934;
				HX_STACK_LINE(6465)
				this->_SF1 = ::tardis::Go_utf8_DecodeRune_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t7);
				HX_STACK_LINE(6466)
				this->_Next = (int)-1;
				HX_STACK_LINE(6467)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(6469)
				{
					HX_STACK_LINE(6469)
					this->_latestPH = (int)934;
					HX_STACK_LINE(6469)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(6470)
				this->_t8 = this->_SF1->res();
				HX_STACK_LINE(6472)
				{
					HX_STACK_LINE(6472)
					bool _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(6472)
					this->_t10 = this->_t8->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(6472)
					this->_latestPH = (int)935;
					HX_STACK_LINE(6472)
					_t11 = (this->_t10 == (int)1);
					HX_STACK_LINE(6472)
					this->_Next = (  ((_t11)) ? int((int)6) : int((int)7) );
				}
				HX_STACK_LINE(6473)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(6475)
				{
					HX_STACK_LINE(6475)
					this->_latestPH = (int)934;
					HX_STACK_LINE(6475)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(6476)
				this->_latestPH = (int)939;
				HX_STACK_LINE(6477)
				this->_res = false;
				HX_STACK_LINE(6478)
				this->_incomplete = false;
				HX_STACK_LINE(6479)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6480)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(6483)
				{
					HX_STACK_LINE(6483)
					this->_latestPH = (int)939;
					HX_STACK_LINE(6483)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(6484)
				{
					HX_STACK_LINE(6484)
					this->_t12 = (this->_t3 + this->_t10);
					HX_STACK_LINE(6484)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(6485)
				this->_Phi = (int)7;
			}
			;break;
			default: {
				HX_STACK_LINE(6486)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(6432)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,run,return )

Dynamic Go_utf8_Valid_obj::res( ){
	HX_STACK_PUSH("Go_utf8_Valid::res","tardis/Go.hx",6402);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6402)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_Valid_obj,res,return )

bool Go_utf8_Valid_obj::callFromHaxe( ::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_Valid::callFromHaxe","tardis/Go.hx",6418);
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(6419)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(6419)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(6420)
	::tardis::Go_utf8_Valid _sf = hx::TCast< ::tardis::Go_utf8_Valid >::cast(::tardis::Go_utf8_Valid_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(6421)
	while((_sf->_incomplete)){
		HX_STACK_LINE(6421)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(6422)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_Valid_obj,callFromHaxe,return )

bool Go_utf8_Valid_obj::callFromRT( int _gr,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_Valid::callFromRT","tardis/Go.hx",6424);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(6425)
	::tardis::Go_utf8_Valid _sf = hx::TCast< ::tardis::Go_utf8_Valid >::cast(::tardis::Go_utf8_Valid_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(6426)
	while((_sf->_incomplete)){
		HX_STACK_LINE(6426)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(6426)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(6426)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(6426)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(6427)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_Valid_obj,callFromRT,return )

::tardis::Go_utf8_Valid Go_utf8_Valid_obj::call( int gr,Dynamic _bds,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_Valid::call","tardis/Go.hx",6430);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(6430)
	return ::tardis::Go_utf8_Valid_obj::__new(gr,_bds,p_p);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_Valid_obj,call,return )


Go_utf8_Valid_obj::Go_utf8_Valid_obj()
{
}

void Go_utf8_Valid_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_Valid);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t12,"_t12");
	HX_MARK_MEMBER_NAME(_t11,"_t11");
	HX_MARK_MEMBER_NAME(_t10,"_t10");
	HX_MARK_MEMBER_NAME(_t8,"_t8");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_t7,"_t7");
	HX_MARK_MEMBER_NAME(_t6,"_t6");
	HX_MARK_MEMBER_NAME(_t5,"_t5");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_p,"p_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_Valid_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t12,"_t12");
	HX_VISIT_MEMBER_NAME(_t11,"_t11");
	HX_VISIT_MEMBER_NAME(_t10,"_t10");
	HX_VISIT_MEMBER_NAME(_t8,"_t8");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_t7,"_t7");
	HX_VISIT_MEMBER_NAME(_t6,"_t6");
	HX_VISIT_MEMBER_NAME(_t5,"_t5");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_p,"p_p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_Valid_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_p") ) { return p_p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t12") ) { return _t12; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
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

Dynamic Go_utf8_Valid_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_p") ) { p_p=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_Valid_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t12"));
	outFields->push(HX_CSTRING("_t11"));
	outFields->push(HX_CSTRING("_t10"));
	outFields->push(HX_CSTRING("_t8"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_t7"));
	outFields->push(HX_CSTRING("_t6"));
	outFields->push(HX_CSTRING("_t5"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
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
	HX_CSTRING("_t12"),
	HX_CSTRING("_t11"),
	HX_CSTRING("_t10"),
	HX_CSTRING("_t8"),
	HX_CSTRING("_SF1"),
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
	HX_CSTRING("p_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_Valid_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_Valid_obj::__mClass,"__mClass");
};

Class Go_utf8_Valid_obj::__mClass;

void Go_utf8_Valid_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_Valid"), hx::TCanCast< Go_utf8_Valid_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_Valid_obj::__boot()
{
}

} // end namespace tardis
