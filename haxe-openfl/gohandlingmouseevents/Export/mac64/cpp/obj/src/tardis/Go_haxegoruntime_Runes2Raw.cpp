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
#ifndef INCLUDED_tardis_Go_haxegoruntime_Runes2Raw
#include <tardis/Go_haxegoruntime_Runes2Raw.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF16
#include <tardis/Go_haxegoruntime_RunesToUTF16.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF8
#include <tardis/Go_haxegoruntime_RunesToUTF8.h>
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

Void Go_haxegoruntime_Runes2Raw_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_r)
{
HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::new","tardis/Go.hx",6573);
{
	HX_STACK_LINE(6614)
	this->_Next = (int)0;
	HX_STACK_LINE(6613)
	this->_Phi = (int)0;
	HX_STACK_LINE(6612)
	this->_t27 = (int)0;
	HX_STACK_LINE(6611)
	this->_t26 = (int)0;
	HX_STACK_LINE(6610)
	this->_t25 = null();
	HX_STACK_LINE(6609)
	this->_t24 = null();
	HX_STACK_LINE(6608)
	this->_t23 = false;
	HX_STACK_LINE(6607)
	this->_t22 = (int)0;
	HX_STACK_LINE(6606)
	this->_t21 = (int)0;
	HX_STACK_LINE(6605)
	this->_t20 = null();
	HX_STACK_LINE(6604)
	this->_t19 = null();
	HX_STACK_LINE(6602)
	this->_t17 = (int)0;
	HX_STACK_LINE(6601)
	this->_t16 = (int)0;
	HX_STACK_LINE(6600)
	this->_t15 = null();
	HX_STACK_LINE(6599)
	this->_t14 = null();
	HX_STACK_LINE(6598)
	this->_t13 = false;
	HX_STACK_LINE(6597)
	this->_t12 = (int)0;
	HX_STACK_LINE(6596)
	this->_t11 = (int)0;
	HX_STACK_LINE(6595)
	this->_t10 = false;
	HX_STACK_LINE(6594)
	this->_t9 = (int)0;
	HX_STACK_LINE(6593)
	this->_t8 = null();
	HX_STACK_LINE(6592)
	this->_t7 = (int)0;
	HX_STACK_LINE(6591)
	this->_t6 = null();
	HX_STACK_LINE(6589)
	this->_t5 = (int)0;
	HX_STACK_LINE(6588)
	this->_t4 = null();
	HX_STACK_LINE(6587)
	this->_t3 = (int)0;
	HX_STACK_LINE(6586)
	this->_t2 = null();
	HX_STACK_LINE(6584)
	this->_t1 = false;
	HX_STACK_LINE(6583)
	this->_t0 = (int)0;
	HX_STACK_LINE(6576)
	super::__construct(gr,(int)121,HX_CSTRING("Go_haxegoruntime_Runes2Raw"));
	HX_STACK_LINE(6577)
	this->_bds = _bds;
	HX_STACK_LINE(6578)
	this->p_r = p_r;
	HX_STACK_LINE(6579)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_Runes2Raw_obj::~Go_haxegoruntime_Runes2Raw_obj() { }

Dynamic Go_haxegoruntime_Runes2Raw_obj::__CreateEmpty() { return  new Go_haxegoruntime_Runes2Raw_obj; }
hx::ObjectPtr< Go_haxegoruntime_Runes2Raw_obj > Go_haxegoruntime_Runes2Raw_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_r)
{  hx::ObjectPtr< Go_haxegoruntime_Runes2Raw_obj > result = new Go_haxegoruntime_Runes2Raw_obj();
	result->__construct(gr,_bds,p_r);
	return result;}

Dynamic Go_haxegoruntime_Runes2Raw_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_Runes2Raw_obj > result = new Go_haxegoruntime_Runes2Raw_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_Runes2Raw_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_Runes2Raw_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn8","tardis/Go.hx",6770);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6771)
		::tardis::Pointer _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(6772)
		::tardis::Pointer _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(6773)
		int _t26;		HX_STACK_VAR(_t26,"_t26");
		HX_STACK_LINE(6774)
		int _t27;		HX_STACK_VAR(_t27,"_t27");
		HX_STACK_LINE(6775)
		this->_latestPH = (int)134;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6776);
				{
					HX_STACK_LINE(6776)
					::tardis::Slice _this = __this->_t8;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(6776)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(6776)
		if (((bool((this->_t22 < (int)0)) || bool((this->_t22 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(6776)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(6777)
		_t24 = this->_t8->addr(this->_t22);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6778);
				{
					HX_STACK_LINE(6778)
					::tardis::Slice _this = __this->_t6;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(6778)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(6778)
		if (((bool((this->_t22 < (int)0)) || bool((this->_t22 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(6778)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(6779)
		_t25 = this->_t6->addr(this->_t22);
		HX_STACK_LINE(6780)
		_t26 = (int(_t25->ref()) | int((int)0));
		HX_STACK_LINE(6781)
		_t27 = _t26;
		HX_STACK_LINE(6782)
		_t24->store(_t27);
		HX_STACK_LINE(6783)
		this->_Next = (int)8;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn8,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn7","tardis/Go.hx",6764);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6765)
		bool _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(6766)
		this->_t22 = (this->_t21 + (int)1);
		HX_STACK_LINE(6767)
		_t23 = (this->_t22 < this->_t9);
		HX_STACK_LINE(6768)
		this->_Next = (  ((_t23)) ? int((int)9) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn7,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn6","tardis/Go.hx",6758);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6759)
		::tardis::Pointer _t19;		HX_STACK_VAR(_t19,"_t19");
		HX_STACK_LINE(6760)
		this->_latestPH = (int)141;
		struct _Function_1_1{
			inline static Array< int > Block( ){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6761);
				{
					HX_STACK_LINE(6761)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6761)
					{
						HX_STACK_LINE(6761)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(6761)
						while(((_g < (int)0))){
							HX_STACK_LINE(6761)
							int _vi = (_g)++;		HX_STACK_VAR(_vi,"_vi");
							HX_STACK_LINE(6761)
							_v[_vi] = (int)0;
						}
					}
					HX_STACK_LINE(6761)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(6761)
		_t19 = ::tardis::Pointer_obj::__new(_Function_1_1::Block());
		HX_STACK_LINE(6762)
		this->_t20 = ::tardis::Slice_obj::__new(_t19,(int)0,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn6,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn5","tardis/Go.hx",6743);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6744)
		::tardis::Pointer _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(6745)
		::tardis::Pointer _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(6746)
		int _t16;		HX_STACK_VAR(_t16,"_t16");
		HX_STACK_LINE(6747)
		int _t17;		HX_STACK_VAR(_t17,"_t17");
		HX_STACK_LINE(6748)
		this->_latestPH = (int)127;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6749);
				{
					HX_STACK_LINE(6749)
					::tardis::Slice _this = __this->_t4;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(6749)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(6749)
		if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(6749)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(6750)
		_t14 = this->_t4->addr(this->_t12);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6751);
				{
					HX_STACK_LINE(6751)
					::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(6751)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(6751)
		if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(6751)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(6752)
		_t15 = this->_t2->addr(this->_t12);
		HX_STACK_LINE(6753)
		_t16 = (int(_t15->ref()) | int((int)0));
		HX_STACK_LINE(6754)
		_t17 = _t16;
		HX_STACK_LINE(6755)
		_t14->store(_t17);
		HX_STACK_LINE(6756)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn5,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn4","tardis/Go.hx",6737);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6738)
		bool _t13;		HX_STACK_VAR(_t13,"_t13");
		HX_STACK_LINE(6739)
		this->_t12 = (this->_t11 + (int)1);
		HX_STACK_LINE(6740)
		_t13 = (this->_t12 < this->_t5);
		HX_STACK_LINE(6741)
		this->_Next = (  ((_t13)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn4,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn3","tardis/Go.hx",6732);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6733)
		bool _t10;		HX_STACK_VAR(_t10,"_t10");
		HX_STACK_LINE(6734)
		_t10 = (::tardis::Force_obj::uintCompare(this->_t0,(int)3) == (int)0);
		HX_STACK_LINE(6735)
		this->_Next = (  ((_t10)) ? int((int)2) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn3,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn2","tardis/Go.hx",6724);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6725)
		int _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(6726)
		this->_latestPH = (int)132;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6727);
				{
					HX_STACK_LINE(6727)
					::tardis::Slice _v = __this->_t6;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6727)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(6727)
		_t7 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static Array< int > Block( int &_t7){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6728);
				{
					HX_STACK_LINE(6728)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6728)
					{
						HX_STACK_LINE(6728)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(6728)
						while(((_g < _t7))){
							HX_STACK_LINE(6728)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(6728)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(6728)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(6728)
		this->_t8 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_2::Block(_t7)),(int)0,_t7);
		struct _Function_1_3{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6729);
				{
					HX_STACK_LINE(6729)
					::tardis::Slice _v = __this->_t6;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6729)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(6729)
		this->_t9 = _Function_1_3::Block(this);
		HX_STACK_LINE(6730)
		this->_Next = (int)8;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn2,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn1","tardis/Go.hx",6716);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6717)
		int _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(6718)
		this->_latestPH = (int)125;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6719);
				{
					HX_STACK_LINE(6719)
					::tardis::Slice _v = __this->_t2;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6719)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(6719)
		_t3 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static Array< int > Block( int &_t3){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6720);
				{
					HX_STACK_LINE(6720)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6720)
					{
						HX_STACK_LINE(6720)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(6720)
						while(((_g < _t3))){
							HX_STACK_LINE(6720)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(6720)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(6720)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(6720)
		this->_t4 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_2::Block(_t3)),(int)0,_t3);
		struct _Function_1_3{
			inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",6721);
				{
					HX_STACK_LINE(6721)
					::tardis::Slice _v = __this->_t2;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(6721)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(6721)
		this->_t5 = _Function_1_3::Block(this);
		HX_STACK_LINE(6722)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn1,(void))

Void Go_haxegoruntime_Runes2Raw_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::SubFn0","tardis/Go.hx",6710);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6711)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(6712)
		this->_t0 = (int(::tardis::Go_obj::haxegoruntime_ZiLen->ref()) | int((int)0));
		HX_STACK_LINE(6713)
		_t1 = (::tardis::Force_obj::uintCompare(this->_t0,(int)1) == (int)0);
		HX_STACK_LINE(6714)
		this->_Next = (  ((_t1)) ? int((int)1) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_Runes2Raw_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::run","tardis/Go.hx",6629);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6629)
	while((true)){
		HX_STACK_LINE(6631)
		::tardis::Go_haxegoruntime_Runes2Raw _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(6631)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(6633)
				{
					HX_STACK_LINE(6633)
					this->_latestPH = (int)121;
					HX_STACK_LINE(6633)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(6634)
				{
					HX_STACK_LINE(6634)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(6634)
					this->_t0 = (int(::tardis::Go_obj::haxegoruntime_ZiLen->ref()) | int((int)0));
					HX_STACK_LINE(6634)
					_t1 = (::tardis::Force_obj::uintCompare(this->_t0,(int)1) == (int)0);
					HX_STACK_LINE(6634)
					this->_Next = (  ((_t1)) ? int((int)1) : int((int)3) );
				}
				HX_STACK_LINE(6635)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(6637)
				{
					HX_STACK_LINE(6637)
					this->_latestPH = (int)121;
					HX_STACK_LINE(6637)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(6638)
				this->_latestPH = (int)124;
				HX_STACK_LINE(6639)
				this->_SF1 = ::tardis::Go_haxegoruntime_RunesToUTF16_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_r);
				HX_STACK_LINE(6640)
				this->_Next = (int)-1;
				HX_STACK_LINE(6641)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(6643)
				{
					HX_STACK_LINE(6643)
					this->_latestPH = (int)124;
					HX_STACK_LINE(6643)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(6644)
				this->_t2 = this->_SF1->res();
				HX_STACK_LINE(6646)
				{
					HX_STACK_LINE(6646)
					int _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(6646)
					this->_latestPH = (int)125;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6646);
							{
								HX_STACK_LINE(6646)
								::tardis::Slice _v = __this->_t2;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6646)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(6646)
					_t3 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static Array< int > Block( int &_t3){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6646);
							{
								HX_STACK_LINE(6646)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6646)
								{
									HX_STACK_LINE(6646)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(6646)
									while(((_g1 < _t3))){
										HX_STACK_LINE(6646)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(6646)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(6646)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(6646)
					this->_t4 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_2::Block(_t3)),(int)0,_t3);
					struct _Function_4_3{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6646);
							{
								HX_STACK_LINE(6646)
								::tardis::Slice _v = __this->_t2;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6646)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(6646)
					this->_t5 = _Function_4_3::Block(this);
					HX_STACK_LINE(6646)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(6647)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(6649)
				{
					HX_STACK_LINE(6649)
					this->_latestPH = (int)124;
					HX_STACK_LINE(6649)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(6650)
				this->_latestPH = (int)131;
				HX_STACK_LINE(6651)
				this->_SF2 = ::tardis::Go_haxegoruntime_RunesToUTF8_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_r);
				HX_STACK_LINE(6652)
				this->_Next = (int)-2;
				HX_STACK_LINE(6653)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-2: {
				HX_STACK_LINE(6655)
				{
					HX_STACK_LINE(6655)
					this->_latestPH = (int)131;
					HX_STACK_LINE(6655)
					this->_latestBlock = (int)-2;
				}
				HX_STACK_LINE(6656)
				this->_t6 = this->_SF2->res();
				HX_STACK_LINE(6658)
				{
					HX_STACK_LINE(6658)
					int _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(6658)
					this->_latestPH = (int)132;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6658);
							{
								HX_STACK_LINE(6658)
								::tardis::Slice _v = __this->_t6;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6658)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(6658)
					_t7 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static Array< int > Block( int &_t7){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6658);
							{
								HX_STACK_LINE(6658)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6658)
								{
									HX_STACK_LINE(6658)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(6658)
									while(((_g1 < _t7))){
										HX_STACK_LINE(6658)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(6658)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(6658)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(6658)
					this->_t8 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_2::Block(_t7)),(int)0,_t7);
					struct _Function_4_3{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6658);
							{
								HX_STACK_LINE(6658)
								::tardis::Slice _v = __this->_t6;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6658)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(6658)
					this->_t9 = _Function_4_3::Block(this);
					HX_STACK_LINE(6658)
					this->_Next = (int)8;
				}
				HX_STACK_LINE(6659)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(6661)
				{
					HX_STACK_LINE(6661)
					this->_latestPH = (int)131;
					HX_STACK_LINE(6661)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(6662)
				{
					HX_STACK_LINE(6662)
					bool _t10;		HX_STACK_VAR(_t10,"_t10");
					HX_STACK_LINE(6662)
					_t10 = (::tardis::Force_obj::uintCompare(this->_t0,(int)3) == (int)0);
					HX_STACK_LINE(6662)
					this->_Next = (  ((_t10)) ? int((int)2) : int((int)7) );
				}
				HX_STACK_LINE(6663)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(6665)
				{
					HX_STACK_LINE(6665)
					this->_latestPH = (int)131;
					HX_STACK_LINE(6665)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(6666)
				this->_t11 = (  (((this->_Phi == (int)1))) ? int((int)-1) : int((  (((this->_Phi == (int)5))) ? int(this->_t12) : int((int)0) )) );
				HX_STACK_LINE(6667)
				{
					HX_STACK_LINE(6667)
					bool _t13;		HX_STACK_VAR(_t13,"_t13");
					HX_STACK_LINE(6667)
					this->_t12 = (this->_t11 + (int)1);
					HX_STACK_LINE(6667)
					_t13 = (this->_t12 < this->_t5);
					HX_STACK_LINE(6667)
					this->_Next = (  ((_t13)) ? int((int)5) : int((int)6) );
				}
				HX_STACK_LINE(6668)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(6670)
				{
					HX_STACK_LINE(6670)
					this->_latestPH = (int)131;
					HX_STACK_LINE(6670)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(6671)
				{
					HX_STACK_LINE(6671)
					::tardis::Pointer _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(6671)
					::tardis::Pointer _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(6671)
					int _t16;		HX_STACK_VAR(_t16,"_t16");
					HX_STACK_LINE(6671)
					int _t17;		HX_STACK_VAR(_t17,"_t17");
					HX_STACK_LINE(6671)
					this->_latestPH = (int)127;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6671);
							{
								HX_STACK_LINE(6671)
								::tardis::Slice _this = __this->_t4;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(6671)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(6671)
					if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(6671)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(6671)
					_t14 = this->_t4->addr(this->_t12);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6671);
							{
								HX_STACK_LINE(6671)
								::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(6671)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(6671)
					if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(6671)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(6671)
					_t15 = this->_t2->addr(this->_t12);
					HX_STACK_LINE(6671)
					_t16 = (int(_t15->ref()) | int((int)0));
					HX_STACK_LINE(6671)
					_t17 = _t16;
					HX_STACK_LINE(6671)
					_t14->store(_t17);
					HX_STACK_LINE(6671)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(6672)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(6674)
				{
					HX_STACK_LINE(6674)
					this->_latestPH = (int)131;
					HX_STACK_LINE(6674)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(6675)
				this->_latestPH = (int)129;
				HX_STACK_LINE(6676)
				this->_res = this->_t4;
				HX_STACK_LINE(6677)
				this->_incomplete = false;
				HX_STACK_LINE(6678)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6679)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(6682)
				{
					HX_STACK_LINE(6682)
					this->_latestPH = (int)129;
					HX_STACK_LINE(6682)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(6683)
				this->_latestPH = (int)139;
				HX_STACK_LINE(6684)
				hx::Throw (HX_CSTRING("goruntime.Runes2Raw() unrecognised encoding"));
				HX_STACK_LINE(6685)
				{
					HX_STACK_LINE(6685)
					::tardis::Pointer _t19;		HX_STACK_VAR(_t19,"_t19");
					HX_STACK_LINE(6685)
					this->_latestPH = (int)141;
					struct _Function_4_1{
						inline static Array< int > Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6685);
							{
								HX_STACK_LINE(6685)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(6685)
								{
									HX_STACK_LINE(6685)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(6685)
									while(((_g1 < (int)0))){
										HX_STACK_LINE(6685)
										int _vi = (_g1)++;		HX_STACK_VAR(_vi,"_vi");
										HX_STACK_LINE(6685)
										_v[_vi] = (int)0;
									}
								}
								HX_STACK_LINE(6685)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(6685)
					_t19 = ::tardis::Pointer_obj::__new(_Function_4_1::Block());
					HX_STACK_LINE(6685)
					this->_t20 = ::tardis::Slice_obj::__new(_t19,(int)0,(int)-1);
				}
				HX_STACK_LINE(6686)
				this->_latestPH = (int)141;
				HX_STACK_LINE(6687)
				this->_res = this->_t20;
				HX_STACK_LINE(6688)
				this->_incomplete = false;
				HX_STACK_LINE(6689)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6690)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(6693)
				{
					HX_STACK_LINE(6693)
					this->_latestPH = (int)141;
					HX_STACK_LINE(6693)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(6694)
				this->_t21 = (  (((this->_Phi == (int)2))) ? int((int)-1) : int((  (((this->_Phi == (int)9))) ? int(this->_t22) : int((int)0) )) );
				HX_STACK_LINE(6695)
				{
					HX_STACK_LINE(6695)
					bool _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(6695)
					this->_t22 = (this->_t21 + (int)1);
					HX_STACK_LINE(6695)
					_t23 = (this->_t22 < this->_t9);
					HX_STACK_LINE(6695)
					this->_Next = (  ((_t23)) ? int((int)9) : int((int)10) );
				}
				HX_STACK_LINE(6696)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(6698)
				{
					HX_STACK_LINE(6698)
					this->_latestPH = (int)141;
					HX_STACK_LINE(6698)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(6699)
				{
					HX_STACK_LINE(6699)
					::tardis::Pointer _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(6699)
					::tardis::Pointer _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(6699)
					int _t26;		HX_STACK_VAR(_t26,"_t26");
					HX_STACK_LINE(6699)
					int _t27;		HX_STACK_VAR(_t27,"_t27");
					HX_STACK_LINE(6699)
					this->_latestPH = (int)134;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6699);
							{
								HX_STACK_LINE(6699)
								::tardis::Slice _this = __this->_t8;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(6699)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(6699)
					if (((bool((this->_t22 < (int)0)) || bool((this->_t22 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(6699)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(6699)
					_t24 = this->_t8->addr(this->_t22);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_Runes2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",6699);
							{
								HX_STACK_LINE(6699)
								::tardis::Slice _this = __this->_t6;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(6699)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(6699)
					if (((bool((this->_t22 < (int)0)) || bool((this->_t22 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(6699)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(6699)
					_t25 = this->_t6->addr(this->_t22);
					HX_STACK_LINE(6699)
					_t26 = (int(_t25->ref()) | int((int)0));
					HX_STACK_LINE(6699)
					_t27 = _t26;
					HX_STACK_LINE(6699)
					_t24->store(_t27);
					HX_STACK_LINE(6699)
					this->_Next = (int)8;
				}
				HX_STACK_LINE(6700)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(6702)
				{
					HX_STACK_LINE(6702)
					this->_latestPH = (int)141;
					HX_STACK_LINE(6702)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(6703)
				this->_latestPH = (int)136;
				HX_STACK_LINE(6704)
				this->_res = this->_t8;
				HX_STACK_LINE(6705)
				this->_incomplete = false;
				HX_STACK_LINE(6706)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6707)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(6709)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(6629)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,run,return )

Dynamic Go_haxegoruntime_Runes2Raw_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::res","tardis/Go.hx",6582);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6582)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Runes2Raw_obj,res,return )

::tardis::Slice Go_haxegoruntime_Runes2Raw_obj::callFromHaxe( ::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::callFromHaxe","tardis/Go.hx",6615);
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(6616)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(6616)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(6617)
	::tardis::Go_haxegoruntime_Runes2Raw _sf = hx::TCast< ::tardis::Go_haxegoruntime_Runes2Raw >::cast(::tardis::Go_haxegoruntime_Runes2Raw_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(6618)
	while((_sf->_incomplete)){
		HX_STACK_LINE(6618)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(6619)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_Runes2Raw_obj,callFromHaxe,return )

::tardis::Slice Go_haxegoruntime_Runes2Raw_obj::callFromRT( int _gr,::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::callFromRT","tardis/Go.hx",6621);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(6622)
	::tardis::Go_haxegoruntime_Runes2Raw _sf = hx::TCast< ::tardis::Go_haxegoruntime_Runes2Raw >::cast(::tardis::Go_haxegoruntime_Runes2Raw_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(6623)
	while((_sf->_incomplete)){
		HX_STACK_LINE(6623)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(6623)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(6623)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(6623)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(6624)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_Runes2Raw_obj,callFromRT,return )

::tardis::Go_haxegoruntime_Runes2Raw Go_haxegoruntime_Runes2Raw_obj::call( int gr,Dynamic _bds,::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_Runes2Raw::call","tardis/Go.hx",6627);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(6627)
	return ::tardis::Go_haxegoruntime_Runes2Raw_obj::__new(gr,_bds,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_Runes2Raw_obj,call,return )


Go_haxegoruntime_Runes2Raw_obj::Go_haxegoruntime_Runes2Raw_obj()
{
}

void Go_haxegoruntime_Runes2Raw_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_Runes2Raw);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t27,"_t27");
	HX_MARK_MEMBER_NAME(_t26,"_t26");
	HX_MARK_MEMBER_NAME(_t25,"_t25");
	HX_MARK_MEMBER_NAME(_t24,"_t24");
	HX_MARK_MEMBER_NAME(_t23,"_t23");
	HX_MARK_MEMBER_NAME(_t22,"_t22");
	HX_MARK_MEMBER_NAME(_t21,"_t21");
	HX_MARK_MEMBER_NAME(_t20,"_t20");
	HX_MARK_MEMBER_NAME(_t19,"_t19");
	HX_MARK_MEMBER_NAME(_SF3,"_SF3");
	HX_MARK_MEMBER_NAME(_t17,"_t17");
	HX_MARK_MEMBER_NAME(_t16,"_t16");
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
	HX_MARK_MEMBER_NAME(_SF2,"_SF2");
	HX_MARK_MEMBER_NAME(_t5,"_t5");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_r,"p_r");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_Runes2Raw_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t27,"_t27");
	HX_VISIT_MEMBER_NAME(_t26,"_t26");
	HX_VISIT_MEMBER_NAME(_t25,"_t25");
	HX_VISIT_MEMBER_NAME(_t24,"_t24");
	HX_VISIT_MEMBER_NAME(_t23,"_t23");
	HX_VISIT_MEMBER_NAME(_t22,"_t22");
	HX_VISIT_MEMBER_NAME(_t21,"_t21");
	HX_VISIT_MEMBER_NAME(_t20,"_t20");
	HX_VISIT_MEMBER_NAME(_t19,"_t19");
	HX_VISIT_MEMBER_NAME(_SF3,"_SF3");
	HX_VISIT_MEMBER_NAME(_t17,"_t17");
	HX_VISIT_MEMBER_NAME(_t16,"_t16");
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
	HX_VISIT_MEMBER_NAME(_SF2,"_SF2");
	HX_VISIT_MEMBER_NAME(_t5,"_t5");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_r,"p_r");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_Runes2Raw_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_r") ) { return p_r; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t27") ) { return _t27; }
		if (HX_FIELD_EQ(inName,"_t26") ) { return _t26; }
		if (HX_FIELD_EQ(inName,"_t25") ) { return _t25; }
		if (HX_FIELD_EQ(inName,"_t24") ) { return _t24; }
		if (HX_FIELD_EQ(inName,"_t23") ) { return _t23; }
		if (HX_FIELD_EQ(inName,"_t22") ) { return _t22; }
		if (HX_FIELD_EQ(inName,"_t21") ) { return _t21; }
		if (HX_FIELD_EQ(inName,"_t20") ) { return _t20; }
		if (HX_FIELD_EQ(inName,"_t19") ) { return _t19; }
		if (HX_FIELD_EQ(inName,"_SF3") ) { return _SF3; }
		if (HX_FIELD_EQ(inName,"_t17") ) { return _t17; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
		if (HX_FIELD_EQ(inName,"_t15") ) { return _t15; }
		if (HX_FIELD_EQ(inName,"_t14") ) { return _t14; }
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
		if (HX_FIELD_EQ(inName,"_t12") ) { return _t12; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { return _SF2; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
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

Dynamic Go_haxegoruntime_Runes2Raw_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t27") ) { _t27=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t26") ) { _t26=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF3") ) { _SF3=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { _SF2=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_Runes2Raw_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t27"));
	outFields->push(HX_CSTRING("_t26"));
	outFields->push(HX_CSTRING("_t25"));
	outFields->push(HX_CSTRING("_t24"));
	outFields->push(HX_CSTRING("_t23"));
	outFields->push(HX_CSTRING("_t22"));
	outFields->push(HX_CSTRING("_t21"));
	outFields->push(HX_CSTRING("_t20"));
	outFields->push(HX_CSTRING("_t19"));
	outFields->push(HX_CSTRING("_SF3"));
	outFields->push(HX_CSTRING("_t17"));
	outFields->push(HX_CSTRING("_t16"));
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
	outFields->push(HX_CSTRING("_SF2"));
	outFields->push(HX_CSTRING("_t5"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_SF1"));
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
	HX_CSTRING("_t26"),
	HX_CSTRING("_t25"),
	HX_CSTRING("_t24"),
	HX_CSTRING("_t23"),
	HX_CSTRING("_t22"),
	HX_CSTRING("_t21"),
	HX_CSTRING("_t20"),
	HX_CSTRING("_t19"),
	HX_CSTRING("_SF3"),
	HX_CSTRING("_t17"),
	HX_CSTRING("_t16"),
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
	HX_CSTRING("_SF2"),
	HX_CSTRING("_t5"),
	HX_CSTRING("_t4"),
	HX_CSTRING("_t3"),
	HX_CSTRING("_t2"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_r"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_Runes2Raw_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_Runes2Raw_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_Runes2Raw_obj::__mClass;

void Go_haxegoruntime_Runes2Raw_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_Runes2Raw"), hx::TCanCast< Go_haxegoruntime_Runes2Raw_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_Runes2Raw_obj::__boot()
{
}

} // end namespace tardis
