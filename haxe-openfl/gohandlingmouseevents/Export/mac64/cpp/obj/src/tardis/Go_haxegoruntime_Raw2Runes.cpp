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
#ifndef INCLUDED_tardis_Go_haxegoruntime_Raw2Runes
#include <tardis/Go_haxegoruntime_Raw2Runes.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_UTF16toRunes
#include <tardis/Go_haxegoruntime_UTF16toRunes.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_UTF8toRunes
#include <tardis/Go_haxegoruntime_UTF8toRunes.h>
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

Void Go_haxegoruntime_Raw2Runes_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_s)
{
HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::new","tardis/Go.hx",4230);
{
	HX_STACK_LINE(4271)
	this->_Next = (int)0;
	HX_STACK_LINE(4270)
	this->_Phi = (int)0;
	HX_STACK_LINE(4269)
	this->_t27 = null();
	HX_STACK_LINE(4267)
	this->_t26 = (int)0;
	HX_STACK_LINE(4266)
	this->_t25 = (int)0;
	HX_STACK_LINE(4265)
	this->_t24 = null();
	HX_STACK_LINE(4264)
	this->_t23 = null();
	HX_STACK_LINE(4263)
	this->_t22 = false;
	HX_STACK_LINE(4262)
	this->_t21 = (int)0;
	HX_STACK_LINE(4261)
	this->_t20 = (int)0;
	HX_STACK_LINE(4260)
	this->_t19 = null();
	HX_STACK_LINE(4259)
	this->_t18 = null();
	HX_STACK_LINE(4257)
	this->_t16 = null();
	HX_STACK_LINE(4255)
	this->_t15 = (int)0;
	HX_STACK_LINE(4254)
	this->_t14 = (int)0;
	HX_STACK_LINE(4253)
	this->_t13 = null();
	HX_STACK_LINE(4252)
	this->_t12 = null();
	HX_STACK_LINE(4251)
	this->_t11 = false;
	HX_STACK_LINE(4250)
	this->_t10 = (int)0;
	HX_STACK_LINE(4249)
	this->_t9 = (int)0;
	HX_STACK_LINE(4248)
	this->_t8 = false;
	HX_STACK_LINE(4247)
	this->_t7 = (int)0;
	HX_STACK_LINE(4246)
	this->_t6 = null();
	HX_STACK_LINE(4245)
	this->_t5 = (int)0;
	HX_STACK_LINE(4244)
	this->_t4 = (int)0;
	HX_STACK_LINE(4243)
	this->_t3 = null();
	HX_STACK_LINE(4242)
	this->_t2 = (int)0;
	HX_STACK_LINE(4241)
	this->_t1 = false;
	HX_STACK_LINE(4240)
	this->_t0 = (int)0;
	HX_STACK_LINE(4233)
	super::__construct(gr,(int)85,HX_CSTRING("Go_haxegoruntime_Raw2Runes"));
	HX_STACK_LINE(4234)
	this->_bds = _bds;
	HX_STACK_LINE(4235)
	this->p_s = p_s;
	HX_STACK_LINE(4236)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_Raw2Runes_obj::~Go_haxegoruntime_Raw2Runes_obj() { }

Dynamic Go_haxegoruntime_Raw2Runes_obj::__CreateEmpty() { return  new Go_haxegoruntime_Raw2Runes_obj; }
hx::ObjectPtr< Go_haxegoruntime_Raw2Runes_obj > Go_haxegoruntime_Raw2Runes_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_s)
{  hx::ObjectPtr< Go_haxegoruntime_Raw2Runes_obj > result = new Go_haxegoruntime_Raw2Runes_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_haxegoruntime_Raw2Runes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_Raw2Runes_obj > result = new Go_haxegoruntime_Raw2Runes_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_Raw2Runes_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_Raw2Runes_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn8","tardis/Go.hx",4425);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4426)
		::tardis::Pointer _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(4427)
		::tardis::Pointer _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(4428)
		int _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(4429)
		int _t26;		HX_STACK_VAR(_t26,"_t26");
		HX_STACK_LINE(4430)
		this->_latestPH = (int)96;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4431);
				{
					HX_STACK_LINE(4431)
					::tardis::Slice _this = __this->_t6;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4431)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4431)
		if (((bool((this->_t21 < (int)0)) || bool((this->_t21 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(4431)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4432)
		_t23 = this->_t6->addr(this->_t21);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4433);
				{
					HX_STACK_LINE(4433)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4433)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4433)
		if (((bool((this->_t21 < (int)0)) || bool((this->_t21 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(4433)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4434)
		_t24 = this->p_s->addr(this->_t21);
		HX_STACK_LINE(4435)
		_t25 = (int(_t24->ref()) | int((int)0));
		HX_STACK_LINE(4436)
		_t26 = _t25;
		HX_STACK_LINE(4437)
		_t23->store(_t26);
		HX_STACK_LINE(4438)
		this->_Next = (int)8;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn8,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn7","tardis/Go.hx",4419);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4420)
		bool _t22;		HX_STACK_VAR(_t22,"_t22");
		HX_STACK_LINE(4421)
		this->_t21 = (this->_t20 + (int)1);
		HX_STACK_LINE(4422)
		_t22 = (this->_t21 < this->_t7);
		HX_STACK_LINE(4423)
		this->_Next = (  ((_t22)) ? int((int)9) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn7,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn6","tardis/Go.hx",4413);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4414)
		::tardis::Pointer _t18;		HX_STACK_VAR(_t18,"_t18");
		HX_STACK_LINE(4415)
		this->_latestPH = (int)103;
		struct _Function_1_1{
			inline static Array< int > Block( ){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4416);
				{
					HX_STACK_LINE(4416)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4416)
					{
						HX_STACK_LINE(4416)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(4416)
						while(((_g < (int)0))){
							HX_STACK_LINE(4416)
							int _vi = (_g)++;		HX_STACK_VAR(_vi,"_vi");
							HX_STACK_LINE(4416)
							_v[_vi] = (int)0;
						}
					}
					HX_STACK_LINE(4416)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(4416)
		_t18 = ::tardis::Pointer_obj::__new(_Function_1_1::Block());
		HX_STACK_LINE(4417)
		this->_t19 = ::tardis::Slice_obj::__new(_t18,(int)0,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn6,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn5","tardis/Go.hx",4398);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4399)
		::tardis::Pointer _t12;		HX_STACK_VAR(_t12,"_t12");
		HX_STACK_LINE(4400)
		::tardis::Pointer _t13;		HX_STACK_VAR(_t13,"_t13");
		HX_STACK_LINE(4401)
		int _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(4402)
		int _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(4403)
		this->_latestPH = (int)90;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4404);
				{
					HX_STACK_LINE(4404)
					::tardis::Slice _this = __this->_t3;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4404)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4404)
		if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(4404)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4405)
		_t12 = this->_t3->addr(this->_t10);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4406);
				{
					HX_STACK_LINE(4406)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4406)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4406)
		if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(4406)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4407)
		_t13 = this->p_s->addr(this->_t10);
		HX_STACK_LINE(4408)
		_t14 = (int(_t13->ref()) | int((int)0));
		HX_STACK_LINE(4409)
		_t15 = _t14;
		HX_STACK_LINE(4410)
		_t12->store(_t15);
		HX_STACK_LINE(4411)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn5,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn4","tardis/Go.hx",4392);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4393)
		bool _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(4394)
		this->_t10 = (this->_t9 + (int)1);
		HX_STACK_LINE(4395)
		_t11 = (this->_t10 < this->_t4);
		HX_STACK_LINE(4396)
		this->_Next = (  ((_t11)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn4,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn3","tardis/Go.hx",4387);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4388)
		bool _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(4389)
		_t8 = (::tardis::Force_obj::uintCompare(this->_t0,(int)3) == (int)0);
		HX_STACK_LINE(4390)
		this->_Next = (  ((_t8)) ? int((int)2) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn3,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn2","tardis/Go.hx",4379);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4380)
		int _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(4381)
		this->_latestPH = (int)94;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4382);
				{
					HX_STACK_LINE(4382)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4382)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(4382)
		_t5 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static Array< int > Block( int &_t5){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4383);
				{
					HX_STACK_LINE(4383)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4383)
					{
						HX_STACK_LINE(4383)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(4383)
						while(((_g < _t5))){
							HX_STACK_LINE(4383)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(4383)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(4383)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(4383)
		this->_t6 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_2::Block(_t5)),(int)0,_t5);
		struct _Function_1_3{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4384);
				{
					HX_STACK_LINE(4384)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4384)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(4384)
		this->_t7 = _Function_1_3::Block(this);
		HX_STACK_LINE(4385)
		this->_Next = (int)8;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn2,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn1","tardis/Go.hx",4371);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4372)
		int _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(4373)
		this->_latestPH = (int)88;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4374);
				{
					HX_STACK_LINE(4374)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4374)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(4374)
		_t2 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static Array< int > Block( int &_t2){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4375);
				{
					HX_STACK_LINE(4375)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4375)
					{
						HX_STACK_LINE(4375)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(4375)
						while(((_g < _t2))){
							HX_STACK_LINE(4375)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(4375)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(4375)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(4375)
		this->_t3 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_2::Block(_t2)),(int)0,_t2);
		struct _Function_1_3{
			inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4376);
				{
					HX_STACK_LINE(4376)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4376)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(4376)
		this->_t4 = _Function_1_3::Block(this);
		HX_STACK_LINE(4377)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn1,(void))

Void Go_haxegoruntime_Raw2Runes_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::SubFn0","tardis/Go.hx",4365);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4366)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(4367)
		this->_t0 = (int(::tardis::Go_obj::haxegoruntime_ZiLen->ref()) | int((int)0));
		HX_STACK_LINE(4368)
		_t1 = (::tardis::Force_obj::uintCompare(this->_t0,(int)1) == (int)0);
		HX_STACK_LINE(4369)
		this->_Next = (  ((_t1)) ? int((int)1) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_Raw2Runes_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::run","tardis/Go.hx",4286);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4286)
	while((true)){
		HX_STACK_LINE(4288)
		::tardis::Go_haxegoruntime_Raw2Runes _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(4288)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(4290)
				{
					HX_STACK_LINE(4290)
					this->_latestPH = (int)85;
					HX_STACK_LINE(4290)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(4291)
				{
					HX_STACK_LINE(4291)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(4291)
					this->_t0 = (int(::tardis::Go_obj::haxegoruntime_ZiLen->ref()) | int((int)0));
					HX_STACK_LINE(4291)
					_t1 = (::tardis::Force_obj::uintCompare(this->_t0,(int)1) == (int)0);
					HX_STACK_LINE(4291)
					this->_Next = (  ((_t1)) ? int((int)1) : int((int)3) );
				}
				HX_STACK_LINE(4292)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(4294)
				{
					HX_STACK_LINE(4294)
					this->_latestPH = (int)85;
					HX_STACK_LINE(4294)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(4295)
				{
					HX_STACK_LINE(4295)
					int _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(4295)
					this->_latestPH = (int)88;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4295);
							{
								HX_STACK_LINE(4295)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4295)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(4295)
					_t2 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static Array< int > Block( int &_t2){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4295);
							{
								HX_STACK_LINE(4295)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4295)
								{
									HX_STACK_LINE(4295)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(4295)
									while(((_g1 < _t2))){
										HX_STACK_LINE(4295)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(4295)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(4295)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(4295)
					this->_t3 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_2::Block(_t2)),(int)0,_t2);
					struct _Function_4_3{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4295);
							{
								HX_STACK_LINE(4295)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4295)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(4295)
					this->_t4 = _Function_4_3::Block(this);
					HX_STACK_LINE(4295)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(4296)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(4298)
				{
					HX_STACK_LINE(4298)
					this->_latestPH = (int)85;
					HX_STACK_LINE(4298)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(4299)
				{
					HX_STACK_LINE(4299)
					int _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(4299)
					this->_latestPH = (int)94;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4299);
							{
								HX_STACK_LINE(4299)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4299)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(4299)
					_t5 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static Array< int > Block( int &_t5){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4299);
							{
								HX_STACK_LINE(4299)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4299)
								{
									HX_STACK_LINE(4299)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(4299)
									while(((_g1 < _t5))){
										HX_STACK_LINE(4299)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(4299)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(4299)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(4299)
					this->_t6 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_2::Block(_t5)),(int)0,_t5);
					struct _Function_4_3{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4299);
							{
								HX_STACK_LINE(4299)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4299)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(4299)
					this->_t7 = _Function_4_3::Block(this);
					HX_STACK_LINE(4299)
					this->_Next = (int)8;
				}
				HX_STACK_LINE(4300)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(4302)
				{
					HX_STACK_LINE(4302)
					this->_latestPH = (int)85;
					HX_STACK_LINE(4302)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(4303)
				{
					HX_STACK_LINE(4303)
					bool _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(4303)
					_t8 = (::tardis::Force_obj::uintCompare(this->_t0,(int)3) == (int)0);
					HX_STACK_LINE(4303)
					this->_Next = (  ((_t8)) ? int((int)2) : int((int)7) );
				}
				HX_STACK_LINE(4304)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(4306)
				{
					HX_STACK_LINE(4306)
					this->_latestPH = (int)85;
					HX_STACK_LINE(4306)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(4307)
				this->_t9 = (  (((this->_Phi == (int)1))) ? int((int)-1) : int((  (((this->_Phi == (int)5))) ? int(this->_t10) : int((int)0) )) );
				HX_STACK_LINE(4308)
				{
					HX_STACK_LINE(4308)
					bool _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(4308)
					this->_t10 = (this->_t9 + (int)1);
					HX_STACK_LINE(4308)
					_t11 = (this->_t10 < this->_t4);
					HX_STACK_LINE(4308)
					this->_Next = (  ((_t11)) ? int((int)5) : int((int)6) );
				}
				HX_STACK_LINE(4309)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(4311)
				{
					HX_STACK_LINE(4311)
					this->_latestPH = (int)85;
					HX_STACK_LINE(4311)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(4312)
				{
					HX_STACK_LINE(4312)
					::tardis::Pointer _t12;		HX_STACK_VAR(_t12,"_t12");
					HX_STACK_LINE(4312)
					::tardis::Pointer _t13;		HX_STACK_VAR(_t13,"_t13");
					HX_STACK_LINE(4312)
					int _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(4312)
					int _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(4312)
					this->_latestPH = (int)90;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4312);
							{
								HX_STACK_LINE(4312)
								::tardis::Slice _this = __this->_t3;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4312)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4312)
					if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(4312)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4312)
					_t12 = this->_t3->addr(this->_t10);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4312);
							{
								HX_STACK_LINE(4312)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4312)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4312)
					if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(4312)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4312)
					_t13 = this->p_s->addr(this->_t10);
					HX_STACK_LINE(4312)
					_t14 = (int(_t13->ref()) | int((int)0));
					HX_STACK_LINE(4312)
					_t15 = _t14;
					HX_STACK_LINE(4312)
					_t12->store(_t15);
					HX_STACK_LINE(4312)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(4313)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(4315)
				{
					HX_STACK_LINE(4315)
					this->_latestPH = (int)85;
					HX_STACK_LINE(4315)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(4316)
				this->_latestPH = (int)92;
				HX_STACK_LINE(4317)
				this->_SF1 = ::tardis::Go_haxegoruntime_UTF16toRunes_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t3);
				HX_STACK_LINE(4318)
				this->_Next = (int)-1;
				HX_STACK_LINE(4319)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(4321)
				{
					HX_STACK_LINE(4321)
					this->_latestPH = (int)92;
					HX_STACK_LINE(4321)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(4322)
				this->_t16 = this->_SF1->res();
				HX_STACK_LINE(4324)
				this->_res = this->_t16;
				HX_STACK_LINE(4325)
				this->_incomplete = false;
				HX_STACK_LINE(4326)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4327)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(4330)
				{
					HX_STACK_LINE(4330)
					this->_latestPH = (int)92;
					HX_STACK_LINE(4330)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(4331)
				this->_latestPH = (int)101;
				HX_STACK_LINE(4332)
				hx::Throw (HX_CSTRING("goruntime.Runes2String() unrecognised encoding"));
				HX_STACK_LINE(4333)
				{
					HX_STACK_LINE(4333)
					::tardis::Pointer _t18;		HX_STACK_VAR(_t18,"_t18");
					HX_STACK_LINE(4333)
					this->_latestPH = (int)103;
					struct _Function_4_1{
						inline static Array< int > Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4333);
							{
								HX_STACK_LINE(4333)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4333)
								{
									HX_STACK_LINE(4333)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(4333)
									while(((_g1 < (int)0))){
										HX_STACK_LINE(4333)
										int _vi = (_g1)++;		HX_STACK_VAR(_vi,"_vi");
										HX_STACK_LINE(4333)
										_v[_vi] = (int)0;
									}
								}
								HX_STACK_LINE(4333)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(4333)
					_t18 = ::tardis::Pointer_obj::__new(_Function_4_1::Block());
					HX_STACK_LINE(4333)
					this->_t19 = ::tardis::Slice_obj::__new(_t18,(int)0,(int)-1);
				}
				HX_STACK_LINE(4334)
				this->_latestPH = (int)103;
				HX_STACK_LINE(4335)
				this->_res = this->_t19;
				HX_STACK_LINE(4336)
				this->_incomplete = false;
				HX_STACK_LINE(4337)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4338)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(4341)
				{
					HX_STACK_LINE(4341)
					this->_latestPH = (int)103;
					HX_STACK_LINE(4341)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(4342)
				this->_t20 = (  (((this->_Phi == (int)2))) ? int((int)-1) : int((  (((this->_Phi == (int)9))) ? int(this->_t21) : int((int)0) )) );
				HX_STACK_LINE(4343)
				{
					HX_STACK_LINE(4343)
					bool _t22;		HX_STACK_VAR(_t22,"_t22");
					HX_STACK_LINE(4343)
					this->_t21 = (this->_t20 + (int)1);
					HX_STACK_LINE(4343)
					_t22 = (this->_t21 < this->_t7);
					HX_STACK_LINE(4343)
					this->_Next = (  ((_t22)) ? int((int)9) : int((int)10) );
				}
				HX_STACK_LINE(4344)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(4346)
				{
					HX_STACK_LINE(4346)
					this->_latestPH = (int)103;
					HX_STACK_LINE(4346)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(4347)
				{
					HX_STACK_LINE(4347)
					::tardis::Pointer _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(4347)
					::tardis::Pointer _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(4347)
					int _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(4347)
					int _t26;		HX_STACK_VAR(_t26,"_t26");
					HX_STACK_LINE(4347)
					this->_latestPH = (int)96;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4347);
							{
								HX_STACK_LINE(4347)
								::tardis::Slice _this = __this->_t6;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4347)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4347)
					if (((bool((this->_t21 < (int)0)) || bool((this->_t21 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(4347)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4347)
					_t23 = this->_t6->addr(this->_t21);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_Raw2Runes_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4347);
							{
								HX_STACK_LINE(4347)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4347)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4347)
					if (((bool((this->_t21 < (int)0)) || bool((this->_t21 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(4347)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4347)
					_t24 = this->p_s->addr(this->_t21);
					HX_STACK_LINE(4347)
					_t25 = (int(_t24->ref()) | int((int)0));
					HX_STACK_LINE(4347)
					_t26 = _t25;
					HX_STACK_LINE(4347)
					_t23->store(_t26);
					HX_STACK_LINE(4347)
					this->_Next = (int)8;
				}
				HX_STACK_LINE(4348)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(4350)
				{
					HX_STACK_LINE(4350)
					this->_latestPH = (int)103;
					HX_STACK_LINE(4350)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(4351)
				this->_latestPH = (int)98;
				HX_STACK_LINE(4352)
				this->_SF3 = ::tardis::Go_haxegoruntime_UTF8toRunes_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t6);
				HX_STACK_LINE(4353)
				this->_Next = (int)-3;
				HX_STACK_LINE(4354)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-3: {
				HX_STACK_LINE(4356)
				{
					HX_STACK_LINE(4356)
					this->_latestPH = (int)98;
					HX_STACK_LINE(4356)
					this->_latestBlock = (int)-3;
				}
				HX_STACK_LINE(4357)
				this->_t27 = this->_SF3->res();
				HX_STACK_LINE(4359)
				this->_res = this->_t27;
				HX_STACK_LINE(4360)
				this->_incomplete = false;
				HX_STACK_LINE(4361)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4362)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(4364)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(4286)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,run,return )

Dynamic Go_haxegoruntime_Raw2Runes_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::res","tardis/Go.hx",4239);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4239)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Raw2Runes_obj,res,return )

::tardis::Slice Go_haxegoruntime_Raw2Runes_obj::callFromHaxe( ::tardis::Slice p_s){
	HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::callFromHaxe","tardis/Go.hx",4272);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(4273)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(4273)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(4274)
	::tardis::Go_haxegoruntime_Raw2Runes _sf = hx::TCast< ::tardis::Go_haxegoruntime_Raw2Runes >::cast(::tardis::Go_haxegoruntime_Raw2Runes_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4275)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4275)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(4276)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_Raw2Runes_obj,callFromHaxe,return )

::tardis::Slice Go_haxegoruntime_Raw2Runes_obj::callFromRT( int _gr,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::callFromRT","tardis/Go.hx",4278);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(4279)
	::tardis::Go_haxegoruntime_Raw2Runes _sf = hx::TCast< ::tardis::Go_haxegoruntime_Raw2Runes >::cast(::tardis::Go_haxegoruntime_Raw2Runes_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4280)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4280)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(4280)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(4280)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(4280)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(4281)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_Raw2Runes_obj,callFromRT,return )

::tardis::Go_haxegoruntime_Raw2Runes Go_haxegoruntime_Raw2Runes_obj::call( int gr,Dynamic _bds,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_haxegoruntime_Raw2Runes::call","tardis/Go.hx",4284);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(4284)
	return ::tardis::Go_haxegoruntime_Raw2Runes_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_Raw2Runes_obj,call,return )


Go_haxegoruntime_Raw2Runes_obj::Go_haxegoruntime_Raw2Runes_obj()
{
}

void Go_haxegoruntime_Raw2Runes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_Raw2Runes);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t27,"_t27");
	HX_MARK_MEMBER_NAME(_SF3,"_SF3");
	HX_MARK_MEMBER_NAME(_t26,"_t26");
	HX_MARK_MEMBER_NAME(_t25,"_t25");
	HX_MARK_MEMBER_NAME(_t24,"_t24");
	HX_MARK_MEMBER_NAME(_t23,"_t23");
	HX_MARK_MEMBER_NAME(_t22,"_t22");
	HX_MARK_MEMBER_NAME(_t21,"_t21");
	HX_MARK_MEMBER_NAME(_t20,"_t20");
	HX_MARK_MEMBER_NAME(_t19,"_t19");
	HX_MARK_MEMBER_NAME(_t18,"_t18");
	HX_MARK_MEMBER_NAME(_SF2,"_SF2");
	HX_MARK_MEMBER_NAME(_t16,"_t16");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
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
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_Raw2Runes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t27,"_t27");
	HX_VISIT_MEMBER_NAME(_SF3,"_SF3");
	HX_VISIT_MEMBER_NAME(_t26,"_t26");
	HX_VISIT_MEMBER_NAME(_t25,"_t25");
	HX_VISIT_MEMBER_NAME(_t24,"_t24");
	HX_VISIT_MEMBER_NAME(_t23,"_t23");
	HX_VISIT_MEMBER_NAME(_t22,"_t22");
	HX_VISIT_MEMBER_NAME(_t21,"_t21");
	HX_VISIT_MEMBER_NAME(_t20,"_t20");
	HX_VISIT_MEMBER_NAME(_t19,"_t19");
	HX_VISIT_MEMBER_NAME(_t18,"_t18");
	HX_VISIT_MEMBER_NAME(_SF2,"_SF2");
	HX_VISIT_MEMBER_NAME(_t16,"_t16");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
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
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_Raw2Runes_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_t27") ) { return _t27; }
		if (HX_FIELD_EQ(inName,"_SF3") ) { return _SF3; }
		if (HX_FIELD_EQ(inName,"_t26") ) { return _t26; }
		if (HX_FIELD_EQ(inName,"_t25") ) { return _t25; }
		if (HX_FIELD_EQ(inName,"_t24") ) { return _t24; }
		if (HX_FIELD_EQ(inName,"_t23") ) { return _t23; }
		if (HX_FIELD_EQ(inName,"_t22") ) { return _t22; }
		if (HX_FIELD_EQ(inName,"_t21") ) { return _t21; }
		if (HX_FIELD_EQ(inName,"_t20") ) { return _t20; }
		if (HX_FIELD_EQ(inName,"_t19") ) { return _t19; }
		if (HX_FIELD_EQ(inName,"_t18") ) { return _t18; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { return _SF2; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_t15") ) { return _t15; }
		if (HX_FIELD_EQ(inName,"_t14") ) { return _t14; }
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
		if (HX_FIELD_EQ(inName,"_t12") ) { return _t12; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
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
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_Raw2Runes_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t27") ) { _t27=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF3") ) { _SF3=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t26") ) { _t26=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { _SF2=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_Raw2Runes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t27"));
	outFields->push(HX_CSTRING("_SF3"));
	outFields->push(HX_CSTRING("_t26"));
	outFields->push(HX_CSTRING("_t25"));
	outFields->push(HX_CSTRING("_t24"));
	outFields->push(HX_CSTRING("_t23"));
	outFields->push(HX_CSTRING("_t22"));
	outFields->push(HX_CSTRING("_t21"));
	outFields->push(HX_CSTRING("_t20"));
	outFields->push(HX_CSTRING("_t19"));
	outFields->push(HX_CSTRING("_t18"));
	outFields->push(HX_CSTRING("_SF2"));
	outFields->push(HX_CSTRING("_t16"));
	outFields->push(HX_CSTRING("_SF1"));
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
	HX_CSTRING("_t27"),
	HX_CSTRING("_SF3"),
	HX_CSTRING("_t26"),
	HX_CSTRING("_t25"),
	HX_CSTRING("_t24"),
	HX_CSTRING("_t23"),
	HX_CSTRING("_t22"),
	HX_CSTRING("_t21"),
	HX_CSTRING("_t20"),
	HX_CSTRING("_t19"),
	HX_CSTRING("_t18"),
	HX_CSTRING("_SF2"),
	HX_CSTRING("_t16"),
	HX_CSTRING("_SF1"),
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
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_Raw2Runes_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_Raw2Runes_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_Raw2Runes_obj::__mClass;

void Go_haxegoruntime_Raw2Runes_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_Raw2Runes"), hx::TCanCast< Go_haxegoruntime_Raw2Runes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_Raw2Runes_obj::__boot()
{
}

} // end namespace tardis
