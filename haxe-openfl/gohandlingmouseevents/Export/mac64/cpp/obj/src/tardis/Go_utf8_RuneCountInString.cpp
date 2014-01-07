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
#ifndef INCLUDED_tardis_Go_utf8_RuneCountInString
#include <tardis/Go_utf8_RuneCountInString.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
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

Void Go_utf8_RuneCountInString_obj::__construct(int gr,Dynamic _bds,::String p_s)
{
HX_STACK_PUSH("Go_utf8_RuneCountInString::new","tardis/Go.hx",3685);
{
	HX_STACK_LINE(3701)
	this->_Next = (int)0;
	HX_STACK_LINE(3700)
	this->_Phi = (int)0;
	HX_STACK_LINE(3699)
	this->_t4 = (int)0;
	HX_STACK_LINE(3698)
	this->_t3 = false;
	HX_STACK_LINE(3697)
	this->_t2 = null();
	HX_STACK_LINE(3696)
	this->_t1 = (int)0;
	HX_STACK_LINE(3695)
	this->_t0 = null();
	HX_STACK_LINE(3688)
	super::__construct(gr,(int)915,HX_CSTRING("Go_utf8_RuneCountInString"));
	HX_STACK_LINE(3689)
	this->_bds = _bds;
	HX_STACK_LINE(3690)
	this->p_s = p_s;
	HX_STACK_LINE(3691)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_RuneCountInString_obj::~Go_utf8_RuneCountInString_obj() { }

Dynamic Go_utf8_RuneCountInString_obj::__CreateEmpty() { return  new Go_utf8_RuneCountInString_obj; }
hx::ObjectPtr< Go_utf8_RuneCountInString_obj > Go_utf8_RuneCountInString_obj::__new(int gr,Dynamic _bds,::String p_s)
{  hx::ObjectPtr< Go_utf8_RuneCountInString_obj > result = new Go_utf8_RuneCountInString_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf8_RuneCountInString_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_RuneCountInString_obj > result = new Go_utf8_RuneCountInString_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_RuneCountInString_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_RuneCountInString_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCountInString::SubFn2","tardis/Go.hx",3753);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3754)
		this->_t4 = (this->_t1 + (int)1);
		HX_STACK_LINE(3755)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCountInString_obj,SubFn2,(void))

Void Go_utf8_RuneCountInString_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCountInString::SubFn1","tardis/Go.hx",3746);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3747)
		Dynamic _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(3748)
		bool _t3;		HX_STACK_VAR(_t3,"_t3");
		struct _Function_1_1{
			inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3749);
				{
					HX_STACK_LINE(3749)
					int _thisK = __this->_t0->__Field(HX_CSTRING("k"),true);		HX_STACK_VAR(_thisK,"_thisK");
					struct _Function_2_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3749);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("r0") , false,false);
								__result->Add(HX_CSTRING("r1") , (int)0,false);
								__result->Add(HX_CSTRING("r2") , (int)0,false);
								return __result;
							}
							return null();
						}
					};
					struct _Function_2_2{
						inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this,int &_thisK){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3749);
							{
								struct _Function_3_1{
									inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this,int &_thisK){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",3749);
										{
											HX_STACK_LINE(3749)
											int _gr = __this->_goroutine;		HX_STACK_VAR(_gr,"_gr");
											::tardis::Slice p_p = __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("subSlice"),true)(_thisK,(int)-1);		HX_STACK_VAR(p_p,"p_p");
											HX_STACK_LINE(3749)
											::tardis::Go_utf8_DecodeRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeRune >::cast(::tardis::Go_utf8_DecodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
											HX_STACK_LINE(3749)
											while((_sf->_incomplete)){
												HX_STACK_LINE(3749)
												if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
													HX_STACK_LINE(3749)
													hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
												}
												else{
													HX_STACK_LINE(3749)
													::tardis::Scheduler_obj::currentGR = _gr;
													HX_STACK_LINE(3749)
													::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
												}
											}
											HX_STACK_LINE(3749)
											return _sf->_res;
										}
										return null();
									}
								};
								HX_STACK_LINE(3749)
								Dynamic _dr = _Function_3_1::Block(__this,_thisK);		HX_STACK_VAR(_dr,"_dr");
								HX_STACK_LINE(3749)
								hx::AddEq(__this->_t0->__FieldRef(HX_CSTRING("k")),_dr->__Field(HX_CSTRING("r1"),true));
								struct _Function_3_2{
									inline static Dynamic Block( Dynamic &_dr,int &_thisK){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",3749);
										{
											hx::Anon __result = hx::Anon_obj::Create();
											__result->Add(HX_CSTRING("r0") , true,false);
											__result->Add(HX_CSTRING("r1") , hx::TCast< Int >::cast(_thisK),false);
											__result->Add(HX_CSTRING("r2") , hx::TCast< Int >::cast(_dr->__Field(HX_CSTRING("r0"),true)),false);
											return __result;
										}
										return null();
									}
								};
								HX_STACK_LINE(3749)
								return _Function_3_2::Block(_dr,_thisK);
							}
							return null();
						}
					};
					HX_STACK_LINE(3749)
					return (  (((__this->_t0->__Field(HX_CSTRING("k"),true) >= __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("len"),true)()))) ? Dynamic(_Function_2_1::Block()) : Dynamic(_Function_2_2::Block(__this,_thisK)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(3749)
		_t2 = _Function_1_1::Block(this);
		HX_STACK_LINE(3750)
		_t3 = _t2->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(3751)
		this->_Next = (  ((_t3)) ? int((int)2) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCountInString_obj,SubFn1,(void))

Void Go_utf8_RuneCountInString_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCountInString::SubFn0","tardis/Go.hx",3741);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3742)
		this->_latestPH = (int)916;
		struct _Function_1_1{
			inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3743);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("k") , (int)0,false);
					__result->Add(HX_CSTRING("v") , ::tardis::Force_obj::toUTF8slice(__this->_goroutine,__this->p_s),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(3743)
		this->_t0 = _Function_1_1::Block(this);
		HX_STACK_LINE(3744)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCountInString_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_RuneCountInString_obj::run( ){
	HX_STACK_PUSH("Go_utf8_RuneCountInString::run","tardis/Go.hx",3716);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3716)
	while((true)){
		HX_STACK_LINE(3718)
		::tardis::Go_utf8_RuneCountInString _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3718)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3720)
				{
					HX_STACK_LINE(3720)
					this->_latestPH = (int)915;
					HX_STACK_LINE(3720)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3721)
				{
					HX_STACK_LINE(3721)
					this->_latestPH = (int)916;
					struct _Function_4_1{
						inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3721);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("k") , (int)0,false);
								__result->Add(HX_CSTRING("v") , ::tardis::Force_obj::toUTF8slice(__this->_goroutine,__this->p_s),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(3721)
					this->_t0 = _Function_4_1::Block(this);
					HX_STACK_LINE(3721)
					this->_Next = (int)1;
				}
				HX_STACK_LINE(3722)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(3724)
				{
					HX_STACK_LINE(3724)
					this->_latestPH = (int)915;
					HX_STACK_LINE(3724)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(3725)
				this->_t1 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)2))) ? int(this->_t4) : int((int)0) )) );
				HX_STACK_LINE(3726)
				{
					HX_STACK_LINE(3726)
					Dynamic _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(3726)
					bool _t3;		HX_STACK_VAR(_t3,"_t3");
					struct _Function_4_1{
						inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3726);
							{
								HX_STACK_LINE(3726)
								int _thisK = __this->_t0->__Field(HX_CSTRING("k"),true);		HX_STACK_VAR(_thisK,"_thisK");
								struct _Function_5_1{
									inline static Dynamic Block( ){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",3726);
										{
											hx::Anon __result = hx::Anon_obj::Create();
											__result->Add(HX_CSTRING("r0") , false,false);
											__result->Add(HX_CSTRING("r1") , (int)0,false);
											__result->Add(HX_CSTRING("r2") , (int)0,false);
											return __result;
										}
										return null();
									}
								};
								struct _Function_5_2{
									inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this,int &_thisK){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",3726);
										{
											struct _Function_6_1{
												inline static Dynamic Block( ::tardis::Go_utf8_RuneCountInString_obj *__this,int &_thisK){
													HX_STACK_PUSH("*::closure","tardis/Go.hx",3726);
													{
														HX_STACK_LINE(3726)
														int _gr = __this->_goroutine;		HX_STACK_VAR(_gr,"_gr");
														::tardis::Slice p_p = __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("subSlice"),true)(_thisK,(int)-1);		HX_STACK_VAR(p_p,"p_p");
														HX_STACK_LINE(3726)
														::tardis::Go_utf8_DecodeRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeRune >::cast(::tardis::Go_utf8_DecodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
														HX_STACK_LINE(3726)
														while((_sf->_incomplete)){
															HX_STACK_LINE(3726)
															if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
																HX_STACK_LINE(3726)
																hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
															}
															else{
																HX_STACK_LINE(3726)
																::tardis::Scheduler_obj::currentGR = _gr;
																HX_STACK_LINE(3726)
																::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
															}
														}
														HX_STACK_LINE(3726)
														return _sf->_res;
													}
													return null();
												}
											};
											HX_STACK_LINE(3726)
											Dynamic _dr = _Function_6_1::Block(__this,_thisK);		HX_STACK_VAR(_dr,"_dr");
											HX_STACK_LINE(3726)
											hx::AddEq(__this->_t0->__FieldRef(HX_CSTRING("k")),_dr->__Field(HX_CSTRING("r1"),true));
											struct _Function_6_2{
												inline static Dynamic Block( Dynamic &_dr,int &_thisK){
													HX_STACK_PUSH("*::closure","tardis/Go.hx",3726);
													{
														hx::Anon __result = hx::Anon_obj::Create();
														__result->Add(HX_CSTRING("r0") , true,false);
														__result->Add(HX_CSTRING("r1") , hx::TCast< Int >::cast(_thisK),false);
														__result->Add(HX_CSTRING("r2") , hx::TCast< Int >::cast(_dr->__Field(HX_CSTRING("r0"),true)),false);
														return __result;
													}
													return null();
												}
											};
											HX_STACK_LINE(3726)
											return _Function_6_2::Block(_dr,_thisK);
										}
										return null();
									}
								};
								HX_STACK_LINE(3726)
								return (  (((__this->_t0->__Field(HX_CSTRING("k"),true) >= __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("len"),true)()))) ? Dynamic(_Function_5_1::Block()) : Dynamic(_Function_5_2::Block(__this,_thisK)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(3726)
					_t2 = _Function_4_1::Block(this);
					HX_STACK_LINE(3726)
					_t3 = _t2->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(3726)
					this->_Next = (  ((_t3)) ? int((int)2) : int((int)3) );
				}
				HX_STACK_LINE(3727)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(3729)
				{
					HX_STACK_LINE(3729)
					this->_latestPH = (int)915;
					HX_STACK_LINE(3729)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(3730)
				{
					HX_STACK_LINE(3730)
					this->_t4 = (this->_t1 + (int)1);
					HX_STACK_LINE(3730)
					this->_Next = (int)1;
				}
				HX_STACK_LINE(3731)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(3733)
				{
					HX_STACK_LINE(3733)
					this->_latestPH = (int)915;
					HX_STACK_LINE(3733)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(3734)
				this->_latestPH = (int)919;
				HX_STACK_LINE(3735)
				this->_res = this->_t1;
				HX_STACK_LINE(3736)
				this->_incomplete = false;
				HX_STACK_LINE(3737)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3738)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3740)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3716)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCountInString_obj,run,return )

Dynamic Go_utf8_RuneCountInString_obj::res( ){
	HX_STACK_PUSH("Go_utf8_RuneCountInString::res","tardis/Go.hx",3694);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3694)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCountInString_obj,res,return )

int Go_utf8_RuneCountInString_obj::callFromHaxe( ::String p_s){
	HX_STACK_PUSH("Go_utf8_RuneCountInString::callFromHaxe","tardis/Go.hx",3702);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(3703)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3703)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3704)
	::tardis::Go_utf8_RuneCountInString _sf = hx::TCast< ::tardis::Go_utf8_RuneCountInString >::cast(::tardis::Go_utf8_RuneCountInString_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3705)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3705)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3706)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_RuneCountInString_obj,callFromHaxe,return )

int Go_utf8_RuneCountInString_obj::callFromRT( int _gr,::String p_s){
	HX_STACK_PUSH("Go_utf8_RuneCountInString::callFromRT","tardis/Go.hx",3708);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(3709)
	::tardis::Go_utf8_RuneCountInString _sf = hx::TCast< ::tardis::Go_utf8_RuneCountInString >::cast(::tardis::Go_utf8_RuneCountInString_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3710)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3710)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3710)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3710)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3710)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3711)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_RuneCountInString_obj,callFromRT,return )

::tardis::Go_utf8_RuneCountInString Go_utf8_RuneCountInString_obj::call( int gr,Dynamic _bds,::String p_s){
	HX_STACK_PUSH("Go_utf8_RuneCountInString::call","tardis/Go.hx",3714);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(3714)
	return ::tardis::Go_utf8_RuneCountInString_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_RuneCountInString_obj,call,return )


Go_utf8_RuneCountInString_obj::Go_utf8_RuneCountInString_obj()
{
}

void Go_utf8_RuneCountInString_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_RuneCountInString);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_RuneCountInString_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_RuneCountInString_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_s") ) { return p_s; }
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

Dynamic Go_utf8_RuneCountInString_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::String >(); return inValue; }
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

void Go_utf8_RuneCountInString_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
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
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_RuneCountInString_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_RuneCountInString_obj::__mClass,"__mClass");
};

Class Go_utf8_RuneCountInString_obj::__mClass;

void Go_utf8_RuneCountInString_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_RuneCountInString"), hx::TCanCast< Go_utf8_RuneCountInString_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_RuneCountInString_obj::__boot()
{
}

} // end namespace tardis
