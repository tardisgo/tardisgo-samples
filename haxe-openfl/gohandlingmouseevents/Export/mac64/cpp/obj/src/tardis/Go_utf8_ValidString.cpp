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
#ifndef INCLUDED_tardis_Go_utf8_DecodeRuneInString
#include <tardis/Go_utf8_DecodeRuneInString.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_ValidString
#include <tardis/Go_utf8_ValidString.h>
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

Void Go_utf8_ValidString_obj::__construct(int gr,Dynamic _bds,::String p_s)
{
HX_STACK_PUSH("Go_utf8_ValidString::new","tardis/Go.hx",4117);
{
	HX_STACK_LINE(4138)
	this->_Next = (int)0;
	HX_STACK_LINE(4137)
	this->_t10 = false;
	HX_STACK_LINE(4136)
	this->_t9 = (int)0;
	HX_STACK_LINE(4135)
	this->_t7 = null();
	HX_STACK_LINE(4133)
	this->_t6 = HX_CSTRING("");
	HX_STACK_LINE(4132)
	this->_t5 = false;
	HX_STACK_LINE(4131)
	this->_t4 = (int)0;
	HX_STACK_LINE(4130)
	this->_t3 = (int)0;
	HX_STACK_LINE(4129)
	this->_t2 = false;
	HX_STACK_LINE(4128)
	this->_t1 = null();
	HX_STACK_LINE(4127)
	this->_t0 = null();
	HX_STACK_LINE(4120)
	super::__construct(gr,(int)948,HX_CSTRING("Go_utf8_ValidString"));
	HX_STACK_LINE(4121)
	this->_bds = _bds;
	HX_STACK_LINE(4122)
	this->p_s = p_s;
	HX_STACK_LINE(4123)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_ValidString_obj::~Go_utf8_ValidString_obj() { }

Dynamic Go_utf8_ValidString_obj::__CreateEmpty() { return  new Go_utf8_ValidString_obj; }
hx::ObjectPtr< Go_utf8_ValidString_obj > Go_utf8_ValidString_obj::__new(int gr,Dynamic _bds,::String p_s)
{  hx::ObjectPtr< Go_utf8_ValidString_obj > result = new Go_utf8_ValidString_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf8_ValidString_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_ValidString_obj > result = new Go_utf8_ValidString_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_ValidString_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_ValidString_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_ValidString::SubFn4","tardis/Go.hx",4221);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4222)
		bool _t10;		HX_STACK_VAR(_t10,"_t10");
		HX_STACK_LINE(4224)
		this->_t9 = this->_t7->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(4225)
		this->_latestPH = (int)956;
		HX_STACK_LINE(4226)
		_t10 = (this->_t9 == (int)1);
		HX_STACK_LINE(4227)
		this->_Next = (  ((_t10)) ? int((int)5) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidString_obj,SubFn4,(void))

Void Go_utf8_ValidString_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_ValidString::SubFn3","tardis/Go.hx",4217);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4218)
		this->_latestPH = (int)955;
		HX_STACK_LINE(4219)
		this->_t6 = ::tardis::Force_obj::toRawString(this->_goroutine,::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->subSlice(this->_t3,(int)-1));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidString_obj,SubFn3,(void))

Void Go_utf8_ValidString_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_ValidString::SubFn2","tardis/Go.hx",4209);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4210)
		bool _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(4211)
		this->_t3 = this->_t1->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(4212)
		this->_t4 = this->_t1->__Field(HX_CSTRING("r2"),true);
		HX_STACK_LINE(4213)
		this->_latestPH = (int)950;
		HX_STACK_LINE(4214)
		_t5 = (this->_t4 == (int)65533);
		HX_STACK_LINE(4215)
		this->_Next = (  ((_t5)) ? int((int)4) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidString_obj,SubFn2,(void))

Void Go_utf8_ValidString_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_ValidString::SubFn1","tardis/Go.hx",4203);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4204)
		bool _t2;		HX_STACK_VAR(_t2,"_t2");
		struct _Function_1_1{
			inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4205);
				{
					HX_STACK_LINE(4205)
					int _thisK = __this->_t0->__Field(HX_CSTRING("k"),true);		HX_STACK_VAR(_thisK,"_thisK");
					struct _Function_2_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4205);
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
						inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this,int &_thisK){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4205);
							{
								struct _Function_3_1{
									inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this,int &_thisK){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",4205);
										{
											HX_STACK_LINE(4205)
											int _gr = __this->_goroutine;		HX_STACK_VAR(_gr,"_gr");
											::tardis::Slice p_p = __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("subSlice"),true)(_thisK,(int)-1);		HX_STACK_VAR(p_p,"p_p");
											HX_STACK_LINE(4205)
											::tardis::Go_utf8_DecodeRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeRune >::cast(::tardis::Go_utf8_DecodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
											HX_STACK_LINE(4205)
											while((_sf->_incomplete)){
												HX_STACK_LINE(4205)
												if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
													HX_STACK_LINE(4205)
													hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
												}
												else{
													HX_STACK_LINE(4205)
													::tardis::Scheduler_obj::currentGR = _gr;
													HX_STACK_LINE(4205)
													::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
												}
											}
											HX_STACK_LINE(4205)
											return _sf->_res;
										}
										return null();
									}
								};
								HX_STACK_LINE(4205)
								Dynamic _dr = _Function_3_1::Block(__this,_thisK);		HX_STACK_VAR(_dr,"_dr");
								HX_STACK_LINE(4205)
								hx::AddEq(__this->_t0->__FieldRef(HX_CSTRING("k")),_dr->__Field(HX_CSTRING("r1"),true));
								struct _Function_3_2{
									inline static Dynamic Block( Dynamic &_dr,int &_thisK){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",4205);
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
								HX_STACK_LINE(4205)
								return _Function_3_2::Block(_dr,_thisK);
							}
							return null();
						}
					};
					HX_STACK_LINE(4205)
					return (  (((__this->_t0->__Field(HX_CSTRING("k"),true) >= __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("len"),true)()))) ? Dynamic(_Function_2_1::Block()) : Dynamic(_Function_2_2::Block(__this,_thisK)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(4205)
		this->_t1 = _Function_1_1::Block(this);
		HX_STACK_LINE(4206)
		_t2 = this->_t1->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(4207)
		this->_Next = (  ((_t2)) ? int((int)2) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidString_obj,SubFn1,(void))

Void Go_utf8_ValidString_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_ValidString::SubFn0","tardis/Go.hx",4198);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4199)
		this->_latestPH = (int)949;
		struct _Function_1_1{
			inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4200);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("k") , (int)0,false);
					__result->Add(HX_CSTRING("v") , ::tardis::Force_obj::toUTF8slice(__this->_goroutine,__this->p_s),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(4200)
		this->_t0 = _Function_1_1::Block(this);
		HX_STACK_LINE(4201)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidString_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_ValidString_obj::run( ){
	HX_STACK_PUSH("Go_utf8_ValidString::run","tardis/Go.hx",4153);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4153)
	while((true)){
		HX_STACK_LINE(4155)
		::tardis::Go_utf8_ValidString _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(4155)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(4157)
				{
					HX_STACK_LINE(4157)
					this->_latestPH = (int)948;
					HX_STACK_LINE(4157)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(4158)
				{
					HX_STACK_LINE(4158)
					this->_latestPH = (int)949;
					struct _Function_4_1{
						inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4158);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("k") , (int)0,false);
								__result->Add(HX_CSTRING("v") , ::tardis::Force_obj::toUTF8slice(__this->_goroutine,__this->p_s),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(4158)
					this->_t0 = _Function_4_1::Block(this);
					HX_STACK_LINE(4158)
					this->_Next = (int)1;
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(4161)
				{
					HX_STACK_LINE(4161)
					this->_latestPH = (int)948;
					HX_STACK_LINE(4161)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(4162)
				{
					HX_STACK_LINE(4162)
					bool _t2;		HX_STACK_VAR(_t2,"_t2");
					struct _Function_4_1{
						inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4162);
							{
								HX_STACK_LINE(4162)
								int _thisK = __this->_t0->__Field(HX_CSTRING("k"),true);		HX_STACK_VAR(_thisK,"_thisK");
								struct _Function_5_1{
									inline static Dynamic Block( ){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",4162);
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
									inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this,int &_thisK){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",4162);
										{
											struct _Function_6_1{
												inline static Dynamic Block( ::tardis::Go_utf8_ValidString_obj *__this,int &_thisK){
													HX_STACK_PUSH("*::closure","tardis/Go.hx",4162);
													{
														HX_STACK_LINE(4162)
														int _gr = __this->_goroutine;		HX_STACK_VAR(_gr,"_gr");
														::tardis::Slice p_p = __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("subSlice"),true)(_thisK,(int)-1);		HX_STACK_VAR(p_p,"p_p");
														HX_STACK_LINE(4162)
														::tardis::Go_utf8_DecodeRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeRune >::cast(::tardis::Go_utf8_DecodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
														HX_STACK_LINE(4162)
														while((_sf->_incomplete)){
															HX_STACK_LINE(4162)
															if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
																HX_STACK_LINE(4162)
																hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
															}
															else{
																HX_STACK_LINE(4162)
																::tardis::Scheduler_obj::currentGR = _gr;
																HX_STACK_LINE(4162)
																::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
															}
														}
														HX_STACK_LINE(4162)
														return _sf->_res;
													}
													return null();
												}
											};
											HX_STACK_LINE(4162)
											Dynamic _dr = _Function_6_1::Block(__this,_thisK);		HX_STACK_VAR(_dr,"_dr");
											HX_STACK_LINE(4162)
											hx::AddEq(__this->_t0->__FieldRef(HX_CSTRING("k")),_dr->__Field(HX_CSTRING("r1"),true));
											struct _Function_6_2{
												inline static Dynamic Block( Dynamic &_dr,int &_thisK){
													HX_STACK_PUSH("*::closure","tardis/Go.hx",4162);
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
											HX_STACK_LINE(4162)
											return _Function_6_2::Block(_dr,_thisK);
										}
										return null();
									}
								};
								HX_STACK_LINE(4162)
								return (  (((__this->_t0->__Field(HX_CSTRING("k"),true) >= __this->_t0->__Field(HX_CSTRING("v"),true)->__Field(HX_CSTRING("len"),true)()))) ? Dynamic(_Function_5_1::Block()) : Dynamic(_Function_5_2::Block(__this,_thisK)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(4162)
					this->_t1 = _Function_4_1::Block(this);
					HX_STACK_LINE(4162)
					_t2 = this->_t1->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(4162)
					this->_Next = (  ((_t2)) ? int((int)2) : int((int)3) );
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(4165)
				{
					HX_STACK_LINE(4165)
					this->_latestPH = (int)948;
					HX_STACK_LINE(4165)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(4166)
				{
					HX_STACK_LINE(4166)
					bool _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(4166)
					this->_t3 = this->_t1->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(4166)
					this->_t4 = this->_t1->__Field(HX_CSTRING("r2"),true);
					HX_STACK_LINE(4166)
					this->_latestPH = (int)950;
					HX_STACK_LINE(4166)
					_t5 = (this->_t4 == (int)65533);
					HX_STACK_LINE(4166)
					this->_Next = (  ((_t5)) ? int((int)4) : int((int)1) );
				}
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(4169)
				{
					HX_STACK_LINE(4169)
					this->_latestPH = (int)948;
					HX_STACK_LINE(4169)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(4170)
				this->_latestPH = (int)961;
				HX_STACK_LINE(4171)
				this->_res = true;
				HX_STACK_LINE(4172)
				this->_incomplete = false;
				HX_STACK_LINE(4173)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4174)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(4177)
				{
					HX_STACK_LINE(4177)
					this->_latestPH = (int)961;
					HX_STACK_LINE(4177)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(4178)
				{
					HX_STACK_LINE(4178)
					this->_latestPH = (int)955;
					HX_STACK_LINE(4178)
					this->_t6 = ::tardis::Force_obj::toRawString(this->_goroutine,::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->subSlice(this->_t3,(int)-1));
				}
				HX_STACK_LINE(4179)
				this->_latestPH = (int)955;
				HX_STACK_LINE(4180)
				this->_SF1 = ::tardis::Go_utf8_DecodeRuneInString_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t6);
				HX_STACK_LINE(4181)
				this->_Next = (int)-1;
				HX_STACK_LINE(4182)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(4184)
				{
					HX_STACK_LINE(4184)
					this->_latestPH = (int)955;
					HX_STACK_LINE(4184)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(4185)
				this->_t7 = this->_SF1->res();
				HX_STACK_LINE(4187)
				{
					HX_STACK_LINE(4187)
					bool _t10;		HX_STACK_VAR(_t10,"_t10");
					HX_STACK_LINE(4187)
					this->_t9 = this->_t7->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(4187)
					this->_latestPH = (int)956;
					HX_STACK_LINE(4187)
					_t10 = (this->_t9 == (int)1);
					HX_STACK_LINE(4187)
					this->_Next = (  ((_t10)) ? int((int)5) : int((int)1) );
				}
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(4190)
				{
					HX_STACK_LINE(4190)
					this->_latestPH = (int)955;
					HX_STACK_LINE(4190)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(4191)
				this->_latestPH = (int)957;
				HX_STACK_LINE(4192)
				this->_res = false;
				HX_STACK_LINE(4193)
				this->_incomplete = false;
				HX_STACK_LINE(4194)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4195)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(4197)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(4153)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidString_obj,run,return )

Dynamic Go_utf8_ValidString_obj::res( ){
	HX_STACK_PUSH("Go_utf8_ValidString::res","tardis/Go.hx",4126);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4126)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_ValidString_obj,res,return )

bool Go_utf8_ValidString_obj::callFromHaxe( ::String p_s){
	HX_STACK_PUSH("Go_utf8_ValidString::callFromHaxe","tardis/Go.hx",4139);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(4140)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(4140)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(4141)
	::tardis::Go_utf8_ValidString _sf = hx::TCast< ::tardis::Go_utf8_ValidString >::cast(::tardis::Go_utf8_ValidString_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4142)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4142)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(4143)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_ValidString_obj,callFromHaxe,return )

bool Go_utf8_ValidString_obj::callFromRT( int _gr,::String p_s){
	HX_STACK_PUSH("Go_utf8_ValidString::callFromRT","tardis/Go.hx",4145);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(4146)
	::tardis::Go_utf8_ValidString _sf = hx::TCast< ::tardis::Go_utf8_ValidString >::cast(::tardis::Go_utf8_ValidString_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4147)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4147)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(4147)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(4147)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(4147)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(4148)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_ValidString_obj,callFromRT,return )

::tardis::Go_utf8_ValidString Go_utf8_ValidString_obj::call( int gr,Dynamic _bds,::String p_s){
	HX_STACK_PUSH("Go_utf8_ValidString::call","tardis/Go.hx",4151);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(4151)
	return ::tardis::Go_utf8_ValidString_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_ValidString_obj,call,return )


Go_utf8_ValidString_obj::Go_utf8_ValidString_obj()
{
}

void Go_utf8_ValidString_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_ValidString);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t10,"_t10");
	HX_MARK_MEMBER_NAME(_t9,"_t9");
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
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_ValidString_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t10,"_t10");
	HX_VISIT_MEMBER_NAME(_t9,"_t9");
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
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_ValidString_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t9") ) { return _t9; }
		if (HX_FIELD_EQ(inName,"_t7") ) { return _t7; }
		if (HX_FIELD_EQ(inName,"_t6") ) { return _t6; }
		if (HX_FIELD_EQ(inName,"_t5") ) { return _t5; }
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
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
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

Dynamic Go_utf8_ValidString_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_ValidString_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t10"));
	outFields->push(HX_CSTRING("_t9"));
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
	outFields->push(HX_CSTRING("p_s"));
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
	HX_CSTRING("_t10"),
	HX_CSTRING("_t9"),
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
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_ValidString_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_ValidString_obj::__mClass,"__mClass");
};

Class Go_utf8_ValidString_obj::__mClass;

void Go_utf8_ValidString_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_ValidString"), hx::TCanCast< Go_utf8_ValidString_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_ValidString_obj::__boot()
{
}

} // end namespace tardis
