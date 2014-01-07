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
#ifndef INCLUDED_tardis_Go_utf8_DecodeLastRune
#include <tardis/Go_utf8_DecodeLastRune.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_DecodeRune
#include <tardis/Go_utf8_DecodeRune.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_RuneStart
#include <tardis/Go_utf8_RuneStart.h>
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

Void Go_utf8_DecodeLastRune_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_p)
{
HX_STACK_PUSH("Go_utf8_DecodeLastRune::new","tardis/Go.hx",7365);
{
	HX_STACK_LINE(7403)
	this->_Next = (int)0;
	HX_STACK_LINE(7402)
	this->_Phi = (int)0;
	HX_STACK_LINE(7401)
	this->_t24 = false;
	HX_STACK_LINE(7400)
	this->_t23 = (int)0;
	HX_STACK_LINE(7399)
	this->_t22 = (int)0;
	HX_STACK_LINE(7398)
	this->_t21 = (int)0;
	HX_STACK_LINE(7397)
	this->_t20 = null();
	HX_STACK_LINE(7395)
	this->_t19 = null();
	HX_STACK_LINE(7394)
	this->_t18 = (int)0;
	HX_STACK_LINE(7393)
	this->_t17 = (int)0;
	HX_STACK_LINE(7392)
	this->_t16 = false;
	HX_STACK_LINE(7391)
	this->_t15 = (int)0;
	HX_STACK_LINE(7390)
	this->_t14 = false;
	HX_STACK_LINE(7389)
	this->_t13 = false;
	HX_STACK_LINE(7387)
	this->_t12 = (int)0;
	HX_STACK_LINE(7386)
	this->_t11 = null();
	HX_STACK_LINE(7385)
	this->_t10 = (int)0;
	HX_STACK_LINE(7384)
	this->_t9 = (int)0;
	HX_STACK_LINE(7383)
	this->_t8 = false;
	HX_STACK_LINE(7382)
	this->_t7 = (int)0;
	HX_STACK_LINE(7381)
	this->_t6 = false;
	HX_STACK_LINE(7380)
	this->_t5 = (int)0;
	HX_STACK_LINE(7379)
	this->_t4 = (int)0;
	HX_STACK_LINE(7378)
	this->_t3 = null();
	HX_STACK_LINE(7377)
	this->_t2 = (int)0;
	HX_STACK_LINE(7376)
	this->_t1 = false;
	HX_STACK_LINE(7375)
	this->_t0 = (int)0;
	HX_STACK_LINE(7368)
	super::__construct(gr,(int)772,HX_CSTRING("Go_utf8_DecodeLastRune"));
	HX_STACK_LINE(7369)
	this->_bds = _bds;
	HX_STACK_LINE(7370)
	this->p_p = p_p;
	HX_STACK_LINE(7371)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_DecodeLastRune_obj::~Go_utf8_DecodeLastRune_obj() { }

Dynamic Go_utf8_DecodeLastRune_obj::__CreateEmpty() { return  new Go_utf8_DecodeLastRune_obj; }
hx::ObjectPtr< Go_utf8_DecodeLastRune_obj > Go_utf8_DecodeLastRune_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_p)
{  hx::ObjectPtr< Go_utf8_DecodeLastRune_obj > result = new Go_utf8_DecodeLastRune_obj();
	result->__construct(gr,_bds,p_p);
	return result;}

Dynamic Go_utf8_DecodeLastRune_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_DecodeLastRune_obj > result = new Go_utf8_DecodeLastRune_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_DecodeLastRune_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_DecodeLastRune_obj::SubFn12( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn12","tardis/Go.hx",7592);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7593)
		int _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(7594)
		bool _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(7595)
		this->_t21 = this->_t20->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(7596)
		this->_t22 = this->_t20->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(7597)
		this->_latestPH = (int)798;
		HX_STACK_LINE(7598)
		_t23 = (this->_t18 + this->_t22);
		HX_STACK_LINE(7599)
		_t24 = (_t23 != this->_t0);
		HX_STACK_LINE(7600)
		this->_Next = (  ((_t24)) ? int((int)13) : int((int)14) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn12,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn11( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn11","tardis/Go.hx",7588);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7589)
		this->_latestPH = (int)797;
		HX_STACK_LINE(7590)
		this->_t19 = this->p_p->subSlice(this->_t18,this->_t0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn11,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn10( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn10","tardis/Go.hx",7585);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7585)
		this->_Next = (int)12;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn10,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn9","tardis/Go.hx",7581);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7582)
		this->_t17 = (this->_t15 - (int)1);
		HX_STACK_LINE(7583)
		this->_Next = (int)9;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn9,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn8","tardis/Go.hx",7575);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7576)
		bool _t16;		HX_STACK_VAR(_t16,"_t16");
		HX_STACK_LINE(7577)
		this->_latestPH = (int)789;
		HX_STACK_LINE(7578)
		_t16 = (this->_t15 >= this->_t9);
		HX_STACK_LINE(7579)
		this->_Next = (  ((_t16)) ? int((int)7) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn8,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn7","tardis/Go.hx",7569);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7570)
		bool _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(7571)
		this->_latestPH = (int)794;
		HX_STACK_LINE(7572)
		_t14 = (this->_t15 < (int)0);
		HX_STACK_LINE(7573)
		this->_Next = (  ((_t14)) ? int((int)11) : int((int)12) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn7,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn6","tardis/Go.hx",7566);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7566)
		this->_Next = (  ((this->_t13)) ? int((int)8) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn6,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn5","tardis/Go.hx",7559);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7560)
		::tardis::Pointer _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(7561)
		this->_latestPH = (int)790;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",7562);
				{
					HX_STACK_LINE(7562)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(7562)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(7562)
		if (((bool((this->_t15 < (int)0)) || bool((this->_t15 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(7562)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(7563)
		_t11 = this->p_p->addr(this->_t15);
		HX_STACK_LINE(7564)
		this->_t12 = (int(_t11->ref()) | int((int)0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn5,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn4","tardis/Go.hx",7555);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7556)
		this->_t10 = (this->_t2 - (int)1);
		HX_STACK_LINE(7557)
		this->_Next = (int)9;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn4,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn3","tardis/Go.hx",7552);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7552)
		this->_Next = (int)6;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn3,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn2","tardis/Go.hx",7544);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7545)
		bool _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(7546)
		this->_latestPH = (int)785;
		HX_STACK_LINE(7547)
		this->_t7 = (this->_t0 - (int)4);
		HX_STACK_LINE(7548)
		this->_latestPH = (int)786;
		HX_STACK_LINE(7549)
		_t8 = (this->_t7 < (int)0);
		HX_STACK_LINE(7550)
		this->_Next = (  ((_t8)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn2,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn1","tardis/Go.hx",7529);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7530)
		::tardis::Pointer _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(7531)
		int _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(7532)
		bool _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(7533)
		this->_latestPH = (int)777;
		HX_STACK_LINE(7534)
		this->_t2 = (this->_t0 - (int)1);
		HX_STACK_LINE(7535)
		this->_latestPH = (int)778;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",7536);
				{
					HX_STACK_LINE(7536)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(7536)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(7536)
		if (((bool((this->_t2 < (int)0)) || bool((this->_t2 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(7536)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(7537)
		_t3 = this->p_p->addr(this->_t2);
		HX_STACK_LINE(7538)
		_t4 = (int(_t3->ref()) | int((int)0));
		HX_STACK_LINE(7539)
		this->_t5 = _t4;
		HX_STACK_LINE(7540)
		this->_latestPH = (int)779;
		HX_STACK_LINE(7541)
		_t6 = (this->_t5 < (int)128);
		HX_STACK_LINE(7542)
		this->_Next = (  ((_t6)) ? int((int)3) : int((int)4) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn1,(void))

Void Go_utf8_DecodeLastRune_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRune::SubFn0","tardis/Go.hx",7521);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7522)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(7523)
		this->_latestPH = (int)773;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",7524);
				{
					HX_STACK_LINE(7524)
					::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(7524)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(7524)
		this->_t0 = _Function_1_1::Block(this);
		HX_STACK_LINE(7525)
		this->_latestPH = (int)774;
		HX_STACK_LINE(7526)
		_t1 = (this->_t0 == (int)0);
		HX_STACK_LINE(7527)
		this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_DecodeLastRune_obj::run( ){
	HX_STACK_PUSH("Go_utf8_DecodeLastRune::run","tardis/Go.hx",7418);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7418)
	while((true)){
		HX_STACK_LINE(7420)
		::tardis::Go_utf8_DecodeLastRune _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7420)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7422)
				{
					HX_STACK_LINE(7422)
					this->_latestPH = (int)772;
					HX_STACK_LINE(7422)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7423)
				{
					HX_STACK_LINE(7423)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(7423)
					this->_latestPH = (int)773;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",7423);
							{
								HX_STACK_LINE(7423)
								::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(7423)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(7423)
					this->_t0 = _Function_4_1::Block(this);
					HX_STACK_LINE(7423)
					this->_latestPH = (int)774;
					HX_STACK_LINE(7423)
					_t1 = (this->_t0 == (int)0);
					HX_STACK_LINE(7423)
					this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(7424)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(7426)
				{
					HX_STACK_LINE(7426)
					this->_latestPH = (int)772;
					HX_STACK_LINE(7426)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(7427)
				this->_latestPH = (int)775;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",7428);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)0,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(7428)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(7429)
				this->_incomplete = false;
				HX_STACK_LINE(7430)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7431)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(7434)
				{
					HX_STACK_LINE(7434)
					this->_latestPH = (int)775;
					HX_STACK_LINE(7434)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(7435)
				{
					HX_STACK_LINE(7435)
					::tardis::Pointer _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(7435)
					int _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(7435)
					bool _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(7435)
					this->_latestPH = (int)777;
					HX_STACK_LINE(7435)
					this->_t2 = (this->_t0 - (int)1);
					HX_STACK_LINE(7435)
					this->_latestPH = (int)778;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",7435);
							{
								HX_STACK_LINE(7435)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(7435)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(7435)
					if (((bool((this->_t2 < (int)0)) || bool((this->_t2 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(7435)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(7435)
					_t3 = this->p_p->addr(this->_t2);
					HX_STACK_LINE(7435)
					_t4 = (int(_t3->ref()) | int((int)0));
					HX_STACK_LINE(7435)
					this->_t5 = _t4;
					HX_STACK_LINE(7435)
					this->_latestPH = (int)779;
					HX_STACK_LINE(7435)
					_t6 = (this->_t5 < (int)128);
					HX_STACK_LINE(7435)
					this->_Next = (  ((_t6)) ? int((int)3) : int((int)4) );
				}
				HX_STACK_LINE(7436)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(7438)
				{
					HX_STACK_LINE(7438)
					this->_latestPH = (int)775;
					HX_STACK_LINE(7438)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(7439)
				this->_latestPH = (int)780;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",7440);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t5,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(7440)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(7441)
				this->_incomplete = false;
				HX_STACK_LINE(7442)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7443)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(7446)
				{
					HX_STACK_LINE(7446)
					this->_latestPH = (int)780;
					HX_STACK_LINE(7446)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(7447)
				{
					HX_STACK_LINE(7447)
					bool _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(7447)
					this->_latestPH = (int)785;
					HX_STACK_LINE(7447)
					this->_t7 = (this->_t0 - (int)4);
					HX_STACK_LINE(7447)
					this->_latestPH = (int)786;
					HX_STACK_LINE(7447)
					_t8 = (this->_t7 < (int)0);
					HX_STACK_LINE(7447)
					this->_Next = (  ((_t8)) ? int((int)5) : int((int)6) );
				}
				HX_STACK_LINE(7448)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(7450)
				{
					HX_STACK_LINE(7450)
					this->_latestPH = (int)780;
					HX_STACK_LINE(7450)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(7451)
				this->_Next = (int)6;
				HX_STACK_LINE(7452)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(7454)
				{
					HX_STACK_LINE(7454)
					this->_latestPH = (int)780;
					HX_STACK_LINE(7454)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(7455)
				this->_latestPH = (int)785;
				HX_STACK_LINE(7456)
				this->_t9 = (  (((this->_Phi == (int)4))) ? int(this->_t7) : int((  (((this->_Phi == (int)5))) ? int((int)0) : int((int)0) )) );
				HX_STACK_LINE(7457)
				{
					HX_STACK_LINE(7457)
					this->_t10 = (this->_t2 - (int)1);
					HX_STACK_LINE(7457)
					this->_Next = (int)9;
				}
				HX_STACK_LINE(7458)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(7460)
				{
					HX_STACK_LINE(7460)
					this->_latestPH = (int)785;
					HX_STACK_LINE(7460)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(7461)
				{
					HX_STACK_LINE(7461)
					::tardis::Pointer _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(7461)
					this->_latestPH = (int)790;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",7461);
							{
								HX_STACK_LINE(7461)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(7461)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(7461)
					if (((bool((this->_t15 < (int)0)) || bool((this->_t15 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(7461)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(7461)
					_t11 = this->p_p->addr(this->_t15);
					HX_STACK_LINE(7461)
					this->_t12 = (int(_t11->ref()) | int((int)0));
				}
				HX_STACK_LINE(7462)
				this->_latestPH = (int)790;
				HX_STACK_LINE(7463)
				this->_SF1 = ::tardis::Go_utf8_RuneStart_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t12);
				HX_STACK_LINE(7464)
				this->_Next = (int)-1;
				HX_STACK_LINE(7465)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(7467)
				{
					HX_STACK_LINE(7467)
					this->_latestPH = (int)790;
					HX_STACK_LINE(7467)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(7468)
				this->_t13 = this->_SF1->res();
				HX_STACK_LINE(7470)
				this->_Next = (  ((this->_t13)) ? int((int)8) : int((int)10) );
				HX_STACK_LINE(7471)
				this->_Phi = (int)7;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(7473)
				{
					HX_STACK_LINE(7473)
					this->_latestPH = (int)790;
					HX_STACK_LINE(7473)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(7474)
				{
					HX_STACK_LINE(7474)
					bool _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(7474)
					this->_latestPH = (int)794;
					HX_STACK_LINE(7474)
					_t14 = (this->_t15 < (int)0);
					HX_STACK_LINE(7474)
					this->_Next = (  ((_t14)) ? int((int)11) : int((int)12) );
				}
				HX_STACK_LINE(7475)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(7477)
				{
					HX_STACK_LINE(7477)
					this->_latestPH = (int)790;
					HX_STACK_LINE(7477)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(7478)
				this->_latestPH = (int)777;
				HX_STACK_LINE(7479)
				this->_t15 = (  (((this->_Phi == (int)6))) ? int(this->_t10) : int((  (((this->_Phi == (int)10))) ? int(this->_t17) : int((int)0) )) );
				HX_STACK_LINE(7480)
				{
					HX_STACK_LINE(7480)
					bool _t16;		HX_STACK_VAR(_t16,"_t16");
					HX_STACK_LINE(7480)
					this->_latestPH = (int)789;
					HX_STACK_LINE(7480)
					_t16 = (this->_t15 >= this->_t9);
					HX_STACK_LINE(7480)
					this->_Next = (  ((_t16)) ? int((int)7) : int((int)8) );
				}
				HX_STACK_LINE(7481)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(7483)
				{
					HX_STACK_LINE(7483)
					this->_latestPH = (int)777;
					HX_STACK_LINE(7483)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(7484)
				{
					HX_STACK_LINE(7484)
					this->_t17 = (this->_t15 - (int)1);
					HX_STACK_LINE(7484)
					this->_Next = (int)9;
				}
				HX_STACK_LINE(7485)
				this->_Phi = (int)10;
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(7487)
				{
					HX_STACK_LINE(7487)
					this->_latestPH = (int)777;
					HX_STACK_LINE(7487)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(7488)
				this->_Next = (int)12;
				HX_STACK_LINE(7489)
				this->_Phi = (int)11;
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(7491)
				{
					HX_STACK_LINE(7491)
					this->_latestPH = (int)777;
					HX_STACK_LINE(7491)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(7492)
				this->_t18 = (  (((this->_Phi == (int)8))) ? int(this->_t15) : int((  (((this->_Phi == (int)11))) ? int((int)0) : int((int)0) )) );
				HX_STACK_LINE(7493)
				{
					HX_STACK_LINE(7493)
					this->_latestPH = (int)797;
					HX_STACK_LINE(7493)
					this->_t19 = this->p_p->subSlice(this->_t18,this->_t0);
				}
				HX_STACK_LINE(7494)
				this->_latestPH = (int)797;
				HX_STACK_LINE(7495)
				this->_SF2 = ::tardis::Go_utf8_DecodeRune_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t19);
				HX_STACK_LINE(7496)
				this->_Next = (int)-2;
				HX_STACK_LINE(7497)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-2: {
				HX_STACK_LINE(7499)
				{
					HX_STACK_LINE(7499)
					this->_latestPH = (int)797;
					HX_STACK_LINE(7499)
					this->_latestBlock = (int)-2;
				}
				HX_STACK_LINE(7500)
				this->_t20 = this->_SF2->res();
				HX_STACK_LINE(7502)
				{
					HX_STACK_LINE(7502)
					int _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(7502)
					bool _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(7502)
					this->_t21 = this->_t20->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(7502)
					this->_t22 = this->_t20->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(7502)
					this->_latestPH = (int)798;
					HX_STACK_LINE(7502)
					_t23 = (this->_t18 + this->_t22);
					HX_STACK_LINE(7502)
					_t24 = (_t23 != this->_t0);
					HX_STACK_LINE(7502)
					this->_Next = (  ((_t24)) ? int((int)13) : int((int)14) );
				}
				HX_STACK_LINE(7503)
				this->_Phi = (int)12;
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(7505)
				{
					HX_STACK_LINE(7505)
					this->_latestPH = (int)797;
					HX_STACK_LINE(7505)
					this->_latestBlock = (int)13;
				}
				HX_STACK_LINE(7506)
				this->_latestPH = (int)799;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",7507);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(7507)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(7508)
				this->_incomplete = false;
				HX_STACK_LINE(7509)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7510)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(7513)
				{
					HX_STACK_LINE(7513)
					this->_latestPH = (int)799;
					HX_STACK_LINE(7513)
					this->_latestBlock = (int)14;
				}
				HX_STACK_LINE(7514)
				this->_latestPH = (int)801;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::Go_utf8_DecodeLastRune_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",7515);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t21,false);
							__result->Add(HX_CSTRING("r1") , __this->_t22,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(7515)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(7516)
				this->_incomplete = false;
				HX_STACK_LINE(7517)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7518)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(7520)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7418)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,run,return )

Dynamic Go_utf8_DecodeLastRune_obj::res( ){
	HX_STACK_PUSH("Go_utf8_DecodeLastRune::res","tardis/Go.hx",7374);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7374)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRune_obj,res,return )

Dynamic Go_utf8_DecodeLastRune_obj::callFromHaxe( ::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_DecodeLastRune::callFromHaxe","tardis/Go.hx",7404);
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(7405)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7405)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7406)
	::tardis::Go_utf8_DecodeLastRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeLastRune >::cast(::tardis::Go_utf8_DecodeLastRune_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7407)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7407)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7408)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_DecodeLastRune_obj,callFromHaxe,return )

Dynamic Go_utf8_DecodeLastRune_obj::callFromRT( int _gr,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_DecodeLastRune::callFromRT","tardis/Go.hx",7410);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(7411)
	::tardis::Go_utf8_DecodeLastRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeLastRune >::cast(::tardis::Go_utf8_DecodeLastRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7412)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7412)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7412)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7412)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7412)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7413)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_DecodeLastRune_obj,callFromRT,return )

::tardis::Go_utf8_DecodeLastRune Go_utf8_DecodeLastRune_obj::call( int gr,Dynamic _bds,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_DecodeLastRune::call","tardis/Go.hx",7416);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(7416)
	return ::tardis::Go_utf8_DecodeLastRune_obj::__new(gr,_bds,p_p);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_DecodeLastRune_obj,call,return )


Go_utf8_DecodeLastRune_obj::Go_utf8_DecodeLastRune_obj()
{
}

void Go_utf8_DecodeLastRune_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_DecodeLastRune);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t24,"_t24");
	HX_MARK_MEMBER_NAME(_t23,"_t23");
	HX_MARK_MEMBER_NAME(_t22,"_t22");
	HX_MARK_MEMBER_NAME(_t21,"_t21");
	HX_MARK_MEMBER_NAME(_t20,"_t20");
	HX_MARK_MEMBER_NAME(_SF2,"_SF2");
	HX_MARK_MEMBER_NAME(_t19,"_t19");
	HX_MARK_MEMBER_NAME(_t18,"_t18");
	HX_MARK_MEMBER_NAME(_t17,"_t17");
	HX_MARK_MEMBER_NAME(_t16,"_t16");
	HX_MARK_MEMBER_NAME(_t15,"_t15");
	HX_MARK_MEMBER_NAME(_t14,"_t14");
	HX_MARK_MEMBER_NAME(_t13,"_t13");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_t12,"_t12");
	HX_MARK_MEMBER_NAME(_t11,"_t11");
	HX_MARK_MEMBER_NAME(_t10,"_t10");
	HX_MARK_MEMBER_NAME(_t9,"_t9");
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
	HX_MARK_MEMBER_NAME(p_p,"p_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_DecodeLastRune_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t24,"_t24");
	HX_VISIT_MEMBER_NAME(_t23,"_t23");
	HX_VISIT_MEMBER_NAME(_t22,"_t22");
	HX_VISIT_MEMBER_NAME(_t21,"_t21");
	HX_VISIT_MEMBER_NAME(_t20,"_t20");
	HX_VISIT_MEMBER_NAME(_SF2,"_SF2");
	HX_VISIT_MEMBER_NAME(_t19,"_t19");
	HX_VISIT_MEMBER_NAME(_t18,"_t18");
	HX_VISIT_MEMBER_NAME(_t17,"_t17");
	HX_VISIT_MEMBER_NAME(_t16,"_t16");
	HX_VISIT_MEMBER_NAME(_t15,"_t15");
	HX_VISIT_MEMBER_NAME(_t14,"_t14");
	HX_VISIT_MEMBER_NAME(_t13,"_t13");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_t12,"_t12");
	HX_VISIT_MEMBER_NAME(_t11,"_t11");
	HX_VISIT_MEMBER_NAME(_t10,"_t10");
	HX_VISIT_MEMBER_NAME(_t9,"_t9");
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
	HX_VISIT_MEMBER_NAME(p_p,"p_p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_DecodeLastRune_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t9") ) { return _t9; }
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
		if (HX_FIELD_EQ(inName,"_t24") ) { return _t24; }
		if (HX_FIELD_EQ(inName,"_t23") ) { return _t23; }
		if (HX_FIELD_EQ(inName,"_t22") ) { return _t22; }
		if (HX_FIELD_EQ(inName,"_t21") ) { return _t21; }
		if (HX_FIELD_EQ(inName,"_t20") ) { return _t20; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { return _SF2; }
		if (HX_FIELD_EQ(inName,"_t19") ) { return _t19; }
		if (HX_FIELD_EQ(inName,"_t18") ) { return _t18; }
		if (HX_FIELD_EQ(inName,"_t17") ) { return _t17; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
		if (HX_FIELD_EQ(inName,"_t15") ) { return _t15; }
		if (HX_FIELD_EQ(inName,"_t14") ) { return _t14; }
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_t12") ) { return _t12; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn9") ) { return SubFn9_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn8") ) { return SubFn8_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn7") ) { return SubFn7_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn6") ) { return SubFn6_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn5") ) { return SubFn5_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn4") ) { return SubFn4_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn3") ) { return SubFn3_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn2") ) { return SubFn2_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn1") ) { return SubFn1_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn0") ) { return SubFn0_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SubFn12") ) { return SubFn12_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn11") ) { return SubFn11_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn10") ) { return SubFn10_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_utf8_DecodeLastRune_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_p") ) { p_p=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { _SF2=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_DecodeLastRune_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t24"));
	outFields->push(HX_CSTRING("_t23"));
	outFields->push(HX_CSTRING("_t22"));
	outFields->push(HX_CSTRING("_t21"));
	outFields->push(HX_CSTRING("_t20"));
	outFields->push(HX_CSTRING("_SF2"));
	outFields->push(HX_CSTRING("_t19"));
	outFields->push(HX_CSTRING("_t18"));
	outFields->push(HX_CSTRING("_t17"));
	outFields->push(HX_CSTRING("_t16"));
	outFields->push(HX_CSTRING("_t15"));
	outFields->push(HX_CSTRING("_t14"));
	outFields->push(HX_CSTRING("_t13"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_t12"));
	outFields->push(HX_CSTRING("_t11"));
	outFields->push(HX_CSTRING("_t10"));
	outFields->push(HX_CSTRING("_t9"));
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
	outFields->push(HX_CSTRING("p_p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn12"),
	HX_CSTRING("SubFn11"),
	HX_CSTRING("SubFn10"),
	HX_CSTRING("SubFn9"),
	HX_CSTRING("SubFn8"),
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
	HX_CSTRING("_t24"),
	HX_CSTRING("_t23"),
	HX_CSTRING("_t22"),
	HX_CSTRING("_t21"),
	HX_CSTRING("_t20"),
	HX_CSTRING("_SF2"),
	HX_CSTRING("_t19"),
	HX_CSTRING("_t18"),
	HX_CSTRING("_t17"),
	HX_CSTRING("_t16"),
	HX_CSTRING("_t15"),
	HX_CSTRING("_t14"),
	HX_CSTRING("_t13"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("_t12"),
	HX_CSTRING("_t11"),
	HX_CSTRING("_t10"),
	HX_CSTRING("_t9"),
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
	HX_CSTRING("p_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_DecodeLastRune_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_DecodeLastRune_obj::__mClass,"__mClass");
};

Class Go_utf8_DecodeLastRune_obj::__mClass;

void Go_utf8_DecodeLastRune_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_DecodeLastRune"), hx::TCanCast< Go_utf8_DecodeLastRune_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_DecodeLastRune_obj::__boot()
{
}

} // end namespace tardis
