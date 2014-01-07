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
#ifndef INCLUDED_tardis_Go_haxegoruntime_UTF8toRunes
#include <tardis/Go_haxegoruntime_UTF8toRunes.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_DecodeRune
#include <tardis/Go_utf8_DecodeRune.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_RuneCount
#include <tardis/Go_utf8_RuneCount.h>
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

Void Go_haxegoruntime_UTF8toRunes_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_s)
{
HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::new","tardis/Go.hx",3344);
{
	HX_STACK_LINE(3383)
	this->_Next = (int)0;
	HX_STACK_LINE(3382)
	this->_Phi = (int)0;
	HX_STACK_LINE(3381)
	this->_t25 = false;
	HX_STACK_LINE(3380)
	this->_t24 = (int)0;
	HX_STACK_LINE(3379)
	this->_t23 = (int)0;
	HX_STACK_LINE(3378)
	this->_t22 = (int)0;
	HX_STACK_LINE(3377)
	this->_t21 = (int)0;
	HX_STACK_LINE(3376)
	this->_t20 = (int)0;
	HX_STACK_LINE(3375)
	this->_t19 = null();
	HX_STACK_LINE(3374)
	this->_t18 = (int)0;
	HX_STACK_LINE(3373)
	this->_t17 = (int)0;
	HX_STACK_LINE(3372)
	this->_t16 = null();
	HX_STACK_LINE(3370)
	this->_t15 = (int)0;
	HX_STACK_LINE(3369)
	this->_t14 = (int)0;
	HX_STACK_LINE(3368)
	this->_t13 = null();
	HX_STACK_LINE(3367)
	this->_t12 = (int)0;
	HX_STACK_LINE(3366)
	this->_t11 = null();
	HX_STACK_LINE(3365)
	this->_t10 = false;
	HX_STACK_LINE(3364)
	this->_t9 = (int)0;
	HX_STACK_LINE(3363)
	this->_t8 = false;
	HX_STACK_LINE(3362)
	this->_t7 = (int)0;
	HX_STACK_LINE(3361)
	this->_t6 = (int)0;
	HX_STACK_LINE(3360)
	this->_t5 = (int)0;
	HX_STACK_LINE(3359)
	this->_t4 = null();
	HX_STACK_LINE(3358)
	this->_t3 = (int)0;
	HX_STACK_LINE(3357)
	this->_t2 = (int)0;
	HX_STACK_LINE(3356)
	this->_t1 = null();
	HX_STACK_LINE(3355)
	this->_t0 = (int)0;
	HX_STACK_LINE(3347)
	super::__construct(gr,(int)69,HX_CSTRING("Go_haxegoruntime_UTF8toRunes"));
	HX_STACK_LINE(3348)
	this->_bds = _bds;
	HX_STACK_LINE(3349)
	this->p_s = p_s;
	HX_STACK_LINE(3350)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_UTF8toRunes_obj::~Go_haxegoruntime_UTF8toRunes_obj() { }

Dynamic Go_haxegoruntime_UTF8toRunes_obj::__CreateEmpty() { return  new Go_haxegoruntime_UTF8toRunes_obj; }
hx::ObjectPtr< Go_haxegoruntime_UTF8toRunes_obj > Go_haxegoruntime_UTF8toRunes_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_s)
{  hx::ObjectPtr< Go_haxegoruntime_UTF8toRunes_obj > result = new Go_haxegoruntime_UTF8toRunes_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_haxegoruntime_UTF8toRunes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_UTF8toRunes_obj > result = new Go_haxegoruntime_UTF8toRunes_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_UTF8toRunes_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_UTF8toRunes_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::SubFn6","tardis/Go.hx",3517);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3518)
		int _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(3519)
		int _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(3520)
		bool _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(3521)
		this->_latestPH = (int)74;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3522);
				{
					HX_STACK_LINE(3522)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3522)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(3522)
		_t23 = _Function_1_1::Block(this);
		HX_STACK_LINE(3523)
		_t24 = (_t23 - this->_t5);
		HX_STACK_LINE(3524)
		_t25 = (this->_t22 < _t24);
		HX_STACK_LINE(3525)
		this->_Next = (  ((_t25)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,SubFn6,(void))

Void Go_haxegoruntime_UTF8toRunes_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::SubFn5","tardis/Go.hx",3505);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3506)
		::tardis::Pointer _t19;		HX_STACK_VAR(_t19,"_t19");
		HX_STACK_LINE(3507)
		this->_t17 = this->_t16->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(3508)
		this->_t18 = this->_t16->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(3509)
		this->_latestPH = (int)78;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3510);
				{
					HX_STACK_LINE(3510)
					::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(3510)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(3510)
		if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(3510)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(3511)
		_t19 = this->_t1->addr(this->_t6);
		HX_STACK_LINE(3512)
		_t19->store(this->_t17);
		HX_STACK_LINE(3513)
		this->_t20 = (this->_t5 + this->_t18);
		HX_STACK_LINE(3514)
		this->_t21 = (this->_t6 + (int)1);
		HX_STACK_LINE(3515)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,SubFn5,(void))

Void Go_haxegoruntime_UTF8toRunes_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::SubFn4","tardis/Go.hx",3489);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3490)
		::tardis::Pointer _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(3491)
		int _t12;		HX_STACK_VAR(_t12,"_t12");
		HX_STACK_LINE(3492)
		::tardis::Pointer _t13;		HX_STACK_VAR(_t13,"_t13");
		HX_STACK_LINE(3493)
		int _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(3494)
		this->_latestPH = (int)75;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3495);
				{
					HX_STACK_LINE(3495)
					::tardis::Slice _this = __this->_t4;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(3495)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(3495)
		if (((bool((this->_t22 < (int)0)) || bool((this->_t22 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(3495)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(3496)
		_t11 = this->_t4->addr(this->_t22);
		HX_STACK_LINE(3497)
		_t12 = (this->_t5 + this->_t22);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3498);
				{
					HX_STACK_LINE(3498)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(3498)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(3498)
		if (((bool((_t12 < (int)0)) || bool((_t12 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(3498)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(3499)
		_t13 = this->p_s->addr(_t12);
		HX_STACK_LINE(3500)
		_t14 = (int(_t13->ref()) | int((int)0));
		HX_STACK_LINE(3501)
		_t11->store(_t14);
		HX_STACK_LINE(3502)
		this->_t15 = (this->_t22 + (int)1);
		HX_STACK_LINE(3503)
		this->_Next = (int)7;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,SubFn4,(void))

Void Go_haxegoruntime_UTF8toRunes_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::SubFn3","tardis/Go.hx",3482);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3483)
		int _t9;		HX_STACK_VAR(_t9,"_t9");
		HX_STACK_LINE(3484)
		bool _t10;		HX_STACK_VAR(_t10,"_t10");
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3485);
				{
					HX_STACK_LINE(3485)
					::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3485)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(3485)
		_t9 = _Function_1_1::Block(this);
		HX_STACK_LINE(3486)
		_t10 = (this->_t6 < _t9);
		HX_STACK_LINE(3487)
		this->_Next = (  ((_t10)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,SubFn3,(void))

Void Go_haxegoruntime_UTF8toRunes_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::SubFn2","tardis/Go.hx",3474);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3475)
		int _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(3476)
		bool _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(3477)
		this->_latestPH = (int)72;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3478);
				{
					HX_STACK_LINE(3478)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3478)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(3478)
		_t7 = _Function_1_1::Block(this);
		HX_STACK_LINE(3479)
		_t8 = (this->_t5 < _t7);
		HX_STACK_LINE(3480)
		this->_Next = (  ((_t8)) ? int((int)4) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,SubFn2,(void))

Void Go_haxegoruntime_UTF8toRunes_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::SubFn1","tardis/Go.hx",3465);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3466)
		int _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(3467)
		int _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(3468)
		this->_latestPH = (int)73;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3469);
				{
					HX_STACK_LINE(3469)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3469)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(3469)
		_t2 = _Function_1_1::Block(this);
		HX_STACK_LINE(3470)
		_t3 = (_t2 - this->_t5);
		struct _Function_1_2{
			inline static Array< int > Block( int &_t3){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3471);
				{
					HX_STACK_LINE(3471)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3471)
					{
						HX_STACK_LINE(3471)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(3471)
						while(((_g < _t3))){
							HX_STACK_LINE(3471)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(3471)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(3471)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(3471)
		this->_t4 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_2::Block(_t3)),(int)0,_t3);
		HX_STACK_LINE(3472)
		this->_Next = (int)7;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,SubFn1,(void))

Void Go_haxegoruntime_UTF8toRunes_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::SubFn0","tardis/Go.hx",3460);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3461)
		this->_latestPH = (int)70;
		struct _Function_1_1{
			inline static Array< int > Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3462);
				{
					HX_STACK_LINE(3462)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3462)
					{
						HX_STACK_LINE(3462)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						int _g = __this->_t0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(3462)
						while(((_g1 < _g))){
							HX_STACK_LINE(3462)
							int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(3462)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(3462)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(3462)
		this->_t1 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_1::Block(this)),(int)0,this->_t0);
		HX_STACK_LINE(3463)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_UTF8toRunes_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::run","tardis/Go.hx",3398);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3398)
	while((true)){
		HX_STACK_LINE(3400)
		::tardis::Go_haxegoruntime_UTF8toRunes _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3400)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3402)
				{
					HX_STACK_LINE(3402)
					this->_latestPH = (int)69;
					HX_STACK_LINE(3402)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3403)
				this->_latestPH = (int)70;
				HX_STACK_LINE(3404)
				this->_SF1 = ::tardis::Go_utf8_RuneCount_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_s);
				HX_STACK_LINE(3405)
				this->_Next = (int)-1;
				HX_STACK_LINE(3406)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(3408)
				{
					HX_STACK_LINE(3408)
					this->_latestPH = (int)70;
					HX_STACK_LINE(3408)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(3409)
				this->_t0 = this->_SF1->res();
				HX_STACK_LINE(3411)
				{
					HX_STACK_LINE(3411)
					this->_latestPH = (int)70;
					struct _Function_4_1{
						inline static Array< int > Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3411);
							{
								HX_STACK_LINE(3411)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3411)
								{
									HX_STACK_LINE(3411)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									int _g2 = __this->_t0;		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(3411)
									while(((_g1 < _g2))){
										HX_STACK_LINE(3411)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(3411)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(3411)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(3411)
					this->_t1 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_1::Block(this)),(int)0,this->_t0);
					HX_STACK_LINE(3411)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(3412)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(3414)
				{
					HX_STACK_LINE(3414)
					this->_latestPH = (int)70;
					HX_STACK_LINE(3414)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(3415)
				{
					HX_STACK_LINE(3415)
					int _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(3415)
					int _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(3415)
					this->_latestPH = (int)73;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3415);
							{
								HX_STACK_LINE(3415)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3415)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(3415)
					_t2 = _Function_4_1::Block(this);
					HX_STACK_LINE(3415)
					_t3 = (_t2 - this->_t5);
					struct _Function_4_2{
						inline static Array< int > Block( int &_t3){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3415);
							{
								HX_STACK_LINE(3415)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3415)
								{
									HX_STACK_LINE(3415)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(3415)
									while(((_g1 < _t3))){
										HX_STACK_LINE(3415)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(3415)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(3415)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(3415)
					this->_t4 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_2::Block(_t3)),(int)0,_t3);
					HX_STACK_LINE(3415)
					this->_Next = (int)7;
				}
				HX_STACK_LINE(3416)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(3418)
				{
					HX_STACK_LINE(3418)
					this->_latestPH = (int)70;
					HX_STACK_LINE(3418)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(3419)
				this->_latestPH = (int)81;
				HX_STACK_LINE(3420)
				this->_res = this->_t1;
				HX_STACK_LINE(3421)
				this->_incomplete = false;
				HX_STACK_LINE(3422)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3423)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(3426)
				{
					HX_STACK_LINE(3426)
					this->_latestPH = (int)81;
					HX_STACK_LINE(3426)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(3427)
				this->_latestPH = (int)71;
				HX_STACK_LINE(3428)
				this->_t5 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)6))) ? int(this->_t20) : int((int)0) )) );
				HX_STACK_LINE(3429)
				this->_latestPH = (int)72;
				HX_STACK_LINE(3430)
				this->_t6 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)6))) ? int(this->_t21) : int((int)0) )) );
				HX_STACK_LINE(3431)
				{
					HX_STACK_LINE(3431)
					int _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(3431)
					bool _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(3431)
					this->_latestPH = (int)72;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3431);
							{
								HX_STACK_LINE(3431)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3431)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(3431)
					_t7 = _Function_4_1::Block(this);
					HX_STACK_LINE(3431)
					_t8 = (this->_t5 < _t7);
					HX_STACK_LINE(3431)
					this->_Next = (  ((_t8)) ? int((int)4) : int((int)2) );
				}
				HX_STACK_LINE(3432)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(3434)
				{
					HX_STACK_LINE(3434)
					this->_latestPH = (int)72;
					HX_STACK_LINE(3434)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(3435)
				{
					HX_STACK_LINE(3435)
					int _t9;		HX_STACK_VAR(_t9,"_t9");
					HX_STACK_LINE(3435)
					bool _t10;		HX_STACK_VAR(_t10,"_t10");
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3435);
							{
								HX_STACK_LINE(3435)
								::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3435)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(3435)
					_t9 = _Function_4_1::Block(this);
					HX_STACK_LINE(3435)
					_t10 = (this->_t6 < _t9);
					HX_STACK_LINE(3435)
					this->_Next = (  ((_t10)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(3436)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(3438)
				{
					HX_STACK_LINE(3438)
					this->_latestPH = (int)72;
					HX_STACK_LINE(3438)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(3439)
				{
					HX_STACK_LINE(3439)
					::tardis::Pointer _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(3439)
					int _t12;		HX_STACK_VAR(_t12,"_t12");
					HX_STACK_LINE(3439)
					::tardis::Pointer _t13;		HX_STACK_VAR(_t13,"_t13");
					HX_STACK_LINE(3439)
					int _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(3439)
					this->_latestPH = (int)75;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3439);
							{
								HX_STACK_LINE(3439)
								::tardis::Slice _this = __this->_t4;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(3439)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(3439)
					if (((bool((this->_t22 < (int)0)) || bool((this->_t22 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(3439)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(3439)
					_t11 = this->_t4->addr(this->_t22);
					HX_STACK_LINE(3439)
					_t12 = (this->_t5 + this->_t22);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3439);
							{
								HX_STACK_LINE(3439)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(3439)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(3439)
					if (((bool((_t12 < (int)0)) || bool((_t12 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(3439)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(3439)
					_t13 = this->p_s->addr(_t12);
					HX_STACK_LINE(3439)
					_t14 = (int(_t13->ref()) | int((int)0));
					HX_STACK_LINE(3439)
					_t11->store(_t14);
					HX_STACK_LINE(3439)
					this->_t15 = (this->_t22 + (int)1);
					HX_STACK_LINE(3439)
					this->_Next = (int)7;
				}
				HX_STACK_LINE(3440)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(3442)
				{
					HX_STACK_LINE(3442)
					this->_latestPH = (int)72;
					HX_STACK_LINE(3442)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(3443)
				this->_latestPH = (int)77;
				HX_STACK_LINE(3444)
				this->_SF2 = ::tardis::Go_utf8_DecodeRune_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t4);
				HX_STACK_LINE(3445)
				this->_Next = (int)-2;
				HX_STACK_LINE(3446)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-2: {
				HX_STACK_LINE(3448)
				{
					HX_STACK_LINE(3448)
					this->_latestPH = (int)77;
					HX_STACK_LINE(3448)
					this->_latestBlock = (int)-2;
				}
				HX_STACK_LINE(3449)
				this->_t16 = this->_SF2->res();
				HX_STACK_LINE(3451)
				{
					HX_STACK_LINE(3451)
					::tardis::Pointer _t19;		HX_STACK_VAR(_t19,"_t19");
					HX_STACK_LINE(3451)
					this->_t17 = this->_t16->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(3451)
					this->_t18 = this->_t16->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(3451)
					this->_latestPH = (int)78;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3451);
							{
								HX_STACK_LINE(3451)
								::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(3451)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(3451)
					if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(3451)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(3451)
					_t19 = this->_t1->addr(this->_t6);
					HX_STACK_LINE(3451)
					_t19->store(this->_t17);
					HX_STACK_LINE(3451)
					this->_t20 = (this->_t5 + this->_t18);
					HX_STACK_LINE(3451)
					this->_t21 = (this->_t6 + (int)1);
					HX_STACK_LINE(3451)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(3452)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(3454)
				{
					HX_STACK_LINE(3454)
					this->_latestPH = (int)77;
					HX_STACK_LINE(3454)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(3455)
				this->_latestPH = (int)74;
				HX_STACK_LINE(3456)
				this->_t22 = (  (((this->_Phi == (int)1))) ? int((int)0) : int((  (((this->_Phi == (int)5))) ? int(this->_t15) : int((int)0) )) );
				HX_STACK_LINE(3457)
				{
					HX_STACK_LINE(3457)
					int _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(3457)
					int _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(3457)
					bool _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(3457)
					this->_latestPH = (int)74;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_UTF8toRunes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3457);
							{
								HX_STACK_LINE(3457)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3457)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(3457)
					_t23 = _Function_4_1::Block(this);
					HX_STACK_LINE(3457)
					_t24 = (_t23 - this->_t5);
					HX_STACK_LINE(3457)
					_t25 = (this->_t22 < _t24);
					HX_STACK_LINE(3457)
					this->_Next = (  ((_t25)) ? int((int)5) : int((int)6) );
				}
				HX_STACK_LINE(3458)
				this->_Phi = (int)7;
			}
			;break;
			default: {
				HX_STACK_LINE(3459)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3398)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,run,return )

Dynamic Go_haxegoruntime_UTF8toRunes_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::res","tardis/Go.hx",3353);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3353)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_UTF8toRunes_obj,res,return )

::tardis::Slice Go_haxegoruntime_UTF8toRunes_obj::callFromHaxe( ::tardis::Slice p_s){
	HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::callFromHaxe","tardis/Go.hx",3384);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(3385)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3385)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3386)
	::tardis::Go_haxegoruntime_UTF8toRunes _sf = hx::TCast< ::tardis::Go_haxegoruntime_UTF8toRunes >::cast(::tardis::Go_haxegoruntime_UTF8toRunes_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3387)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3387)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3388)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_UTF8toRunes_obj,callFromHaxe,return )

::tardis::Slice Go_haxegoruntime_UTF8toRunes_obj::callFromRT( int _gr,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::callFromRT","tardis/Go.hx",3390);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(3391)
	::tardis::Go_haxegoruntime_UTF8toRunes _sf = hx::TCast< ::tardis::Go_haxegoruntime_UTF8toRunes >::cast(::tardis::Go_haxegoruntime_UTF8toRunes_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3392)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3392)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3392)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3392)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3392)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3393)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_UTF8toRunes_obj,callFromRT,return )

::tardis::Go_haxegoruntime_UTF8toRunes Go_haxegoruntime_UTF8toRunes_obj::call( int gr,Dynamic _bds,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_haxegoruntime_UTF8toRunes::call","tardis/Go.hx",3396);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(3396)
	return ::tardis::Go_haxegoruntime_UTF8toRunes_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_UTF8toRunes_obj,call,return )


Go_haxegoruntime_UTF8toRunes_obj::Go_haxegoruntime_UTF8toRunes_obj()
{
}

void Go_haxegoruntime_UTF8toRunes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_UTF8toRunes);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t25,"_t25");
	HX_MARK_MEMBER_NAME(_t24,"_t24");
	HX_MARK_MEMBER_NAME(_t23,"_t23");
	HX_MARK_MEMBER_NAME(_t22,"_t22");
	HX_MARK_MEMBER_NAME(_t21,"_t21");
	HX_MARK_MEMBER_NAME(_t20,"_t20");
	HX_MARK_MEMBER_NAME(_t19,"_t19");
	HX_MARK_MEMBER_NAME(_t18,"_t18");
	HX_MARK_MEMBER_NAME(_t17,"_t17");
	HX_MARK_MEMBER_NAME(_t16,"_t16");
	HX_MARK_MEMBER_NAME(_SF2,"_SF2");
	HX_MARK_MEMBER_NAME(_t15,"_t15");
	HX_MARK_MEMBER_NAME(_t14,"_t14");
	HX_MARK_MEMBER_NAME(_t13,"_t13");
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
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_UTF8toRunes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t25,"_t25");
	HX_VISIT_MEMBER_NAME(_t24,"_t24");
	HX_VISIT_MEMBER_NAME(_t23,"_t23");
	HX_VISIT_MEMBER_NAME(_t22,"_t22");
	HX_VISIT_MEMBER_NAME(_t21,"_t21");
	HX_VISIT_MEMBER_NAME(_t20,"_t20");
	HX_VISIT_MEMBER_NAME(_t19,"_t19");
	HX_VISIT_MEMBER_NAME(_t18,"_t18");
	HX_VISIT_MEMBER_NAME(_t17,"_t17");
	HX_VISIT_MEMBER_NAME(_t16,"_t16");
	HX_VISIT_MEMBER_NAME(_SF2,"_SF2");
	HX_VISIT_MEMBER_NAME(_t15,"_t15");
	HX_VISIT_MEMBER_NAME(_t14,"_t14");
	HX_VISIT_MEMBER_NAME(_t13,"_t13");
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
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_UTF8toRunes_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_s") ) { return p_s; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t25") ) { return _t25; }
		if (HX_FIELD_EQ(inName,"_t24") ) { return _t24; }
		if (HX_FIELD_EQ(inName,"_t23") ) { return _t23; }
		if (HX_FIELD_EQ(inName,"_t22") ) { return _t22; }
		if (HX_FIELD_EQ(inName,"_t21") ) { return _t21; }
		if (HX_FIELD_EQ(inName,"_t20") ) { return _t20; }
		if (HX_FIELD_EQ(inName,"_t19") ) { return _t19; }
		if (HX_FIELD_EQ(inName,"_t18") ) { return _t18; }
		if (HX_FIELD_EQ(inName,"_t17") ) { return _t17; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { return _SF2; }
		if (HX_FIELD_EQ(inName,"_t15") ) { return _t15; }
		if (HX_FIELD_EQ(inName,"_t14") ) { return _t14; }
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
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

Dynamic Go_haxegoruntime_UTF8toRunes_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { _SF2=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_UTF8toRunes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t25"));
	outFields->push(HX_CSTRING("_t24"));
	outFields->push(HX_CSTRING("_t23"));
	outFields->push(HX_CSTRING("_t22"));
	outFields->push(HX_CSTRING("_t21"));
	outFields->push(HX_CSTRING("_t20"));
	outFields->push(HX_CSTRING("_t19"));
	outFields->push(HX_CSTRING("_t18"));
	outFields->push(HX_CSTRING("_t17"));
	outFields->push(HX_CSTRING("_t16"));
	outFields->push(HX_CSTRING("_SF2"));
	outFields->push(HX_CSTRING("_t15"));
	outFields->push(HX_CSTRING("_t14"));
	outFields->push(HX_CSTRING("_t13"));
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
	outFields->push(HX_CSTRING("_SF1"));
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
	HX_CSTRING("_t25"),
	HX_CSTRING("_t24"),
	HX_CSTRING("_t23"),
	HX_CSTRING("_t22"),
	HX_CSTRING("_t21"),
	HX_CSTRING("_t20"),
	HX_CSTRING("_t19"),
	HX_CSTRING("_t18"),
	HX_CSTRING("_t17"),
	HX_CSTRING("_t16"),
	HX_CSTRING("_SF2"),
	HX_CSTRING("_t15"),
	HX_CSTRING("_t14"),
	HX_CSTRING("_t13"),
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
	HX_CSTRING("_SF1"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_UTF8toRunes_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_UTF8toRunes_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_UTF8toRunes_obj::__mClass;

void Go_haxegoruntime_UTF8toRunes_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_UTF8toRunes"), hx::TCanCast< Go_haxegoruntime_UTF8toRunes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_UTF8toRunes_obj::__boot()
{
}

} // end namespace tardis
