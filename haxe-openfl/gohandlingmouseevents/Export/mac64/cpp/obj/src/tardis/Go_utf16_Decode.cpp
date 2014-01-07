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
#ifndef INCLUDED_tardis_Go_utf16_Decode
#include <tardis/Go_utf16_Decode.h>
#endif
#ifndef INCLUDED_tardis_Go_utf16_DecodeRune
#include <tardis/Go_utf16_DecodeRune.h>
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

Void Go_utf16_Decode_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_s)
{
HX_STACK_PUSH("Go_utf16_Decode::new","tardis/Go.hx",2712);
{
	HX_STACK_LINE(2767)
	this->_Next = (int)0;
	HX_STACK_LINE(2766)
	this->_Phi = (int)0;
	HX_STACK_LINE(2765)
	this->_t42 = false;
	HX_STACK_LINE(2764)
	this->_t41 = false;
	HX_STACK_LINE(2763)
	this->_t40 = (int)0;
	HX_STACK_LINE(2762)
	this->_t39 = (int)0;
	HX_STACK_LINE(2761)
	this->_t38 = null();
	HX_STACK_LINE(2760)
	this->_t37 = false;
	HX_STACK_LINE(2759)
	this->_t36 = false;
	HX_STACK_LINE(2758)
	this->_t35 = (int)0;
	HX_STACK_LINE(2757)
	this->_t34 = (int)0;
	HX_STACK_LINE(2756)
	this->_t33 = false;
	HX_STACK_LINE(2755)
	this->_t32 = (int)0;
	HX_STACK_LINE(2754)
	this->_t31 = null();
	HX_STACK_LINE(2753)
	this->_t30 = (int)0;
	HX_STACK_LINE(2752)
	this->_t29 = false;
	HX_STACK_LINE(2751)
	this->_t28 = false;
	HX_STACK_LINE(2750)
	this->_t27 = (int)0;
	HX_STACK_LINE(2749)
	this->_t26 = null();
	HX_STACK_LINE(2748)
	this->_t25 = (int)0;
	HX_STACK_LINE(2747)
	this->_t24 = false;
	HX_STACK_LINE(2746)
	this->_t23 = (int)0;
	HX_STACK_LINE(2745)
	this->_t22 = null();
	HX_STACK_LINE(2744)
	this->_t21 = (int)0;
	HX_STACK_LINE(2743)
	this->_t20 = (int)0;
	HX_STACK_LINE(2742)
	this->_t19 = (int)0;
	HX_STACK_LINE(2740)
	this->_t18 = (int)0;
	HX_STACK_LINE(2739)
	this->_t17 = (int)0;
	HX_STACK_LINE(2738)
	this->_t16 = null();
	HX_STACK_LINE(2737)
	this->_t15 = (int)0;
	HX_STACK_LINE(2736)
	this->_t14 = (int)0;
	HX_STACK_LINE(2735)
	this->_t13 = null();
	HX_STACK_LINE(2734)
	this->_t12 = (int)0;
	HX_STACK_LINE(2733)
	this->_t11 = (int)0;
	HX_STACK_LINE(2732)
	this->_t10 = (int)0;
	HX_STACK_LINE(2731)
	this->_t9 = false;
	HX_STACK_LINE(2730)
	this->_t8 = (int)0;
	HX_STACK_LINE(2729)
	this->_t7 = (int)0;
	HX_STACK_LINE(2728)
	this->_t6 = (int)0;
	HX_STACK_LINE(2727)
	this->_t5 = null();
	HX_STACK_LINE(2726)
	this->_t4 = false;
	HX_STACK_LINE(2725)
	this->_t3 = (int)0;
	HX_STACK_LINE(2724)
	this->_t2 = null();
	HX_STACK_LINE(2723)
	this->_t1 = null();
	HX_STACK_LINE(2722)
	this->_t0 = (int)0;
	HX_STACK_LINE(2715)
	super::__construct(gr,(int)511,HX_CSTRING("Go_utf16_Decode"));
	HX_STACK_LINE(2716)
	this->_bds = _bds;
	HX_STACK_LINE(2717)
	this->p_s = p_s;
	HX_STACK_LINE(2718)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf16_Decode_obj::~Go_utf16_Decode_obj() { }

Dynamic Go_utf16_Decode_obj::__CreateEmpty() { return  new Go_utf16_Decode_obj; }
hx::ObjectPtr< Go_utf16_Decode_obj > Go_utf16_Decode_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_s)
{  hx::ObjectPtr< Go_utf16_Decode_obj > result = new Go_utf16_Decode_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf16_Decode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf16_Decode_obj > result = new Go_utf16_Decode_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf16_Decode_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf16_Decode_obj::SubFn16( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn16","tardis/Go.hx",3003);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3003)
		this->_Next = (  ((this->_t42)) ? int((int)6) : int((int)13) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn16,(void))

Void Go_utf16_Decode_obj::SubFn15( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn15","tardis/Go.hx",2998);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2999)
		this->_latestPH = (int)522;
		HX_STACK_LINE(3000)
		this->_t41 = (::tardis::Force_obj::uintCompare(this->_t3,(int)57344) < (int)0);
		HX_STACK_LINE(3001)
		this->_Next = (int)15;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn15,(void))

Void Go_utf16_Decode_obj::SubFn14( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn14","tardis/Go.hx",2987);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2988)
		::tardis::Pointer _t38;		HX_STACK_VAR(_t38,"_t38");
		HX_STACK_LINE(2989)
		int _t39;		HX_STACK_VAR(_t39,"_t39");
		HX_STACK_LINE(2990)
		this->_latestPH = (int)528;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2991);
				{
					HX_STACK_LINE(2991)
					::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2991)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2991)
		if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(2991)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2992)
		_t38 = this->_t1->addr(this->_t6);
		HX_STACK_LINE(2993)
		_t39 = this->_t3;
		HX_STACK_LINE(2994)
		_t38->store(_t39);
		HX_STACK_LINE(2995)
		this->_t40 = (this->_t6 + (int)1);
		HX_STACK_LINE(2996)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn14,(void))

Void Go_utf16_Decode_obj::SubFn13( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn13","tardis/Go.hx",2982);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2983)
		bool _t37;		HX_STACK_VAR(_t37,"_t37");
		HX_STACK_LINE(2984)
		_t37 = (::tardis::Force_obj::uintCompare(this->_t3,(int)56320) < (int)0);
		HX_STACK_LINE(2985)
		this->_Next = (  ((_t37)) ? int((int)11) : int((int)9) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn13,(void))

Void Go_utf16_Decode_obj::SubFn12( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn12","tardis/Go.hx",2972);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2973)
		int _t34;		HX_STACK_VAR(_t34,"_t34");
		HX_STACK_LINE(2974)
		int _t35;		HX_STACK_VAR(_t35,"_t35");
		HX_STACK_LINE(2975)
		bool _t36;		HX_STACK_VAR(_t36,"_t36");
		HX_STACK_LINE(2976)
		this->_latestPH = (int)516;
		HX_STACK_LINE(2977)
		_t34 = (this->_t7 + (int)1);
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2978);
				{
					HX_STACK_LINE(2978)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(2978)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(2978)
		_t35 = _Function_1_1::Block(this);
		HX_STACK_LINE(2979)
		_t36 = (_t34 < _t35);
		HX_STACK_LINE(2980)
		this->_Next = (  ((_t36)) ? int((int)10) : int((int)9) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn12,(void))

Void Go_utf16_Decode_obj::SubFn11( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn11","tardis/Go.hx",2960);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2961)
		int _t30;		HX_STACK_VAR(_t30,"_t30");
		HX_STACK_LINE(2962)
		::tardis::Pointer _t31;		HX_STACK_VAR(_t31,"_t31");
		HX_STACK_LINE(2963)
		int _t32;		HX_STACK_VAR(_t32,"_t32");
		HX_STACK_LINE(2964)
		bool _t33;		HX_STACK_VAR(_t33,"_t33");
		HX_STACK_LINE(2965)
		_t30 = (this->_t7 + (int)1);
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2966);
				{
					HX_STACK_LINE(2966)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2966)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2966)
		if (((bool((_t30 < (int)0)) || bool((_t30 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(2966)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2967)
		_t31 = this->p_s->addr(_t30);
		HX_STACK_LINE(2968)
		_t32 = (int(_t31->ref()) | int((int)0));
		HX_STACK_LINE(2969)
		_t33 = (::tardis::Force_obj::uintCompare((int)56320,_t32) <= (int)0);
		HX_STACK_LINE(2970)
		this->_Next = (  ((_t33)) ? int((int)8) : int((int)9) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn11,(void))

Void Go_utf16_Decode_obj::SubFn10( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn10","tardis/Go.hx",2957);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2957)
		this->_Next = (  ((this->_t29)) ? int((int)5) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn10,(void))

Void Go_utf16_Decode_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn9","tardis/Go.hx",2945);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2946)
		int _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(2947)
		::tardis::Pointer _t26;		HX_STACK_VAR(_t26,"_t26");
		HX_STACK_LINE(2948)
		int _t27;		HX_STACK_VAR(_t27,"_t27");
		HX_STACK_LINE(2949)
		this->_latestPH = (int)517;
		HX_STACK_LINE(2950)
		_t25 = (this->_t7 + (int)1);
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2951);
				{
					HX_STACK_LINE(2951)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2951)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2951)
		if (((bool((_t25 < (int)0)) || bool((_t25 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(2951)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2952)
		_t26 = this->p_s->addr(_t25);
		HX_STACK_LINE(2953)
		_t27 = (int(_t26->ref()) | int((int)0));
		HX_STACK_LINE(2954)
		this->_t28 = (::tardis::Force_obj::uintCompare(_t27,(int)57344) < (int)0);
		HX_STACK_LINE(2955)
		this->_Next = (int)9;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn9,(void))

Void Go_utf16_Decode_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn8","tardis/Go.hx",2939);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2940)
		bool _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(2941)
		this->_latestPH = (int)522;
		HX_STACK_LINE(2942)
		_t24 = (::tardis::Force_obj::uintCompare((int)55296,this->_t3) <= (int)0);
		HX_STACK_LINE(2943)
		this->_Next = (  ((_t24)) ? int((int)14) : int((int)15) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn8,(void))

Void Go_utf16_Decode_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn7","tardis/Go.hx",2930);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2931)
		::tardis::Pointer _t22;		HX_STACK_VAR(_t22,"_t22");
		HX_STACK_LINE(2932)
		this->_latestPH = (int)524;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2933);
				{
					HX_STACK_LINE(2933)
					::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2933)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2933)
		if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(2933)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2934)
		_t22 = this->_t1->addr(this->_t6);
		HX_STACK_LINE(2935)
		_t22->store((int)65533);
		HX_STACK_LINE(2936)
		this->_t23 = (this->_t6 + (int)1);
		HX_STACK_LINE(2937)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn7,(void))

Void Go_utf16_Decode_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn6","tardis/Go.hx",2924);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2925)
		this->_t13->store(this->_t19);
		HX_STACK_LINE(2926)
		this->_t20 = (this->_t7 + (int)1);
		HX_STACK_LINE(2927)
		this->_t21 = (this->_t6 + (int)1);
		HX_STACK_LINE(2928)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn6,(void))

Void Go_utf16_Decode_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn5","tardis/Go.hx",2910);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2911)
		int _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(2912)
		::tardis::Pointer _t16;		HX_STACK_VAR(_t16,"_t16");
		HX_STACK_LINE(2913)
		int _t17;		HX_STACK_VAR(_t17,"_t17");
		HX_STACK_LINE(2914)
		this->_latestPH = (int)519;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2915);
				{
					HX_STACK_LINE(2915)
					::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2915)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2915)
		if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(2915)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2916)
		this->_t13 = this->_t1->addr(this->_t6);
		HX_STACK_LINE(2917)
		this->_t14 = this->_t3;
		HX_STACK_LINE(2918)
		_t15 = (this->_t7 + (int)1);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2919);
				{
					HX_STACK_LINE(2919)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2919)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2919)
		if (((bool((_t15 < (int)0)) || bool((_t15 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(2919)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2920)
		_t16 = this->p_s->addr(_t15);
		HX_STACK_LINE(2921)
		_t17 = (int(_t16->ref()) | int((int)0));
		HX_STACK_LINE(2922)
		this->_t18 = _t17;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn5,(void))

Void Go_utf16_Decode_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn4","tardis/Go.hx",2906);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2907)
		this->_t12 = (this->_t11 + (int)1);
		HX_STACK_LINE(2908)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn4,(void))

Void Go_utf16_Decode_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn3","tardis/Go.hx",2898);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2899)
		int _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(2900)
		bool _t9;		HX_STACK_VAR(_t9,"_t9");
		HX_STACK_LINE(2901)
		this->_latestPH = (int)514;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2902);
				{
					HX_STACK_LINE(2902)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(2902)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(2902)
		_t8 = _Function_1_1::Block(this);
		HX_STACK_LINE(2903)
		_t9 = (this->_t7 < _t8);
		HX_STACK_LINE(2904)
		this->_Next = (  ((_t9)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn3,(void))

Void Go_utf16_Decode_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn2","tardis/Go.hx",2894);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2895)
		this->_latestPH = (int)532;
		HX_STACK_LINE(2896)
		this->_t5 = this->_t1->subSlice((int)0,this->_t6);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn2,(void))

Void Go_utf16_Decode_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn1","tardis/Go.hx",2883);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2884)
		::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(2885)
		bool _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(2886)
		this->_latestPH = (int)515;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2887);
				{
					HX_STACK_LINE(2887)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2887)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2887)
		if (((bool((this->_t7 < (int)0)) || bool((this->_t7 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(2887)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2888)
		_t2 = this->p_s->addr(this->_t7);
		HX_STACK_LINE(2889)
		this->_t3 = (int(_t2->ref()) | int((int)0));
		HX_STACK_LINE(2890)
		this->_latestPH = (int)516;
		HX_STACK_LINE(2891)
		_t4 = (::tardis::Force_obj::uintCompare((int)55296,this->_t3) <= (int)0);
		HX_STACK_LINE(2892)
		this->_Next = (  ((_t4)) ? int((int)12) : int((int)9) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn1,(void))

Void Go_utf16_Decode_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf16_Decode::SubFn0","tardis/Go.hx",2876);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2877)
		int _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(2878)
		this->_latestPH = (int)512;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2879);
				{
					HX_STACK_LINE(2879)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(2879)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(2879)
		_t0 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static Array< int > Block( int &_t0){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2880);
				{
					HX_STACK_LINE(2880)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(2880)
					{
						HX_STACK_LINE(2880)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(2880)
						while(((_g < _t0))){
							HX_STACK_LINE(2880)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(2880)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(2880)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(2880)
		this->_t1 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_2::Block(_t0)),(int)0,_t0);
		HX_STACK_LINE(2881)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,SubFn0,(void))

::tardis::StackFrame Go_utf16_Decode_obj::run( ){
	HX_STACK_PUSH("Go_utf16_Decode::run","tardis/Go.hx",2782);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2782)
	while((true)){
		HX_STACK_LINE(2784)
		::tardis::Go_utf16_Decode _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2784)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(2786)
				{
					HX_STACK_LINE(2786)
					this->_latestPH = (int)511;
					HX_STACK_LINE(2786)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(2787)
				{
					HX_STACK_LINE(2787)
					int _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(2787)
					this->_latestPH = (int)512;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2787);
							{
								HX_STACK_LINE(2787)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(2787)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(2787)
					_t0 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static Array< int > Block( int &_t0){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2787);
							{
								HX_STACK_LINE(2787)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(2787)
								{
									HX_STACK_LINE(2787)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(2787)
									while(((_g1 < _t0))){
										HX_STACK_LINE(2787)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(2787)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(2787)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(2787)
					this->_t1 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_2::Block(_t0)),(int)0,_t0);
					HX_STACK_LINE(2787)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(2788)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(2790)
				{
					HX_STACK_LINE(2790)
					this->_latestPH = (int)511;
					HX_STACK_LINE(2790)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(2791)
				{
					HX_STACK_LINE(2791)
					::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(2791)
					bool _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(2791)
					this->_latestPH = (int)515;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2791);
							{
								HX_STACK_LINE(2791)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(2791)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(2791)
					if (((bool((this->_t7 < (int)0)) || bool((this->_t7 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(2791)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(2791)
					_t2 = this->p_s->addr(this->_t7);
					HX_STACK_LINE(2791)
					this->_t3 = (int(_t2->ref()) | int((int)0));
					HX_STACK_LINE(2791)
					this->_latestPH = (int)516;
					HX_STACK_LINE(2791)
					_t4 = (::tardis::Force_obj::uintCompare((int)55296,this->_t3) <= (int)0);
					HX_STACK_LINE(2791)
					this->_Next = (  ((_t4)) ? int((int)12) : int((int)9) );
				}
				HX_STACK_LINE(2792)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(2794)
				{
					HX_STACK_LINE(2794)
					this->_latestPH = (int)511;
					HX_STACK_LINE(2794)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(2795)
				{
					HX_STACK_LINE(2795)
					this->_latestPH = (int)532;
					HX_STACK_LINE(2795)
					this->_t5 = this->_t1->subSlice((int)0,this->_t6);
				}
				HX_STACK_LINE(2796)
				this->_latestPH = (int)532;
				HX_STACK_LINE(2797)
				this->_res = this->_t5;
				HX_STACK_LINE(2798)
				this->_incomplete = false;
				HX_STACK_LINE(2799)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2800)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(2803)
				{
					HX_STACK_LINE(2803)
					this->_latestPH = (int)532;
					HX_STACK_LINE(2803)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(2804)
				this->_latestPH = (int)513;
				HX_STACK_LINE(2805)
				this->_t6 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)4))) ? int(this->_t10) : int((int)0) )) );
				HX_STACK_LINE(2806)
				this->_latestPH = (int)514;
				HX_STACK_LINE(2807)
				this->_t7 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)4))) ? int(this->_t12) : int((int)0) )) );
				HX_STACK_LINE(2808)
				{
					HX_STACK_LINE(2808)
					int _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(2808)
					bool _t9;		HX_STACK_VAR(_t9,"_t9");
					HX_STACK_LINE(2808)
					this->_latestPH = (int)514;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2808);
							{
								HX_STACK_LINE(2808)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(2808)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(2808)
					_t8 = _Function_4_1::Block(this);
					HX_STACK_LINE(2808)
					_t9 = (this->_t7 < _t8);
					HX_STACK_LINE(2808)
					this->_Next = (  ((_t9)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(2809)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(2811)
				{
					HX_STACK_LINE(2811)
					this->_latestPH = (int)514;
					HX_STACK_LINE(2811)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(2812)
				this->_latestPH = (int)513;
				HX_STACK_LINE(2813)
				this->_t10 = (  (((this->_Phi == (int)5))) ? int(this->_t21) : int((  (((this->_Phi == (int)6))) ? int(this->_t23) : int((  (((this->_Phi == (int)13))) ? int(this->_t40) : int((int)0) )) )) );
				HX_STACK_LINE(2814)
				this->_latestPH = (int)514;
				HX_STACK_LINE(2815)
				this->_t11 = (  (((this->_Phi == (int)5))) ? int(this->_t20) : int((  (((this->_Phi == (int)6))) ? int(this->_t7) : int((  (((this->_Phi == (int)13))) ? int(this->_t7) : int((int)0) )) )) );
				HX_STACK_LINE(2816)
				{
					HX_STACK_LINE(2816)
					this->_t12 = (this->_t11 + (int)1);
					HX_STACK_LINE(2816)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(2817)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(2819)
				{
					HX_STACK_LINE(2819)
					this->_latestPH = (int)514;
					HX_STACK_LINE(2819)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(2820)
				{
					HX_STACK_LINE(2820)
					int _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(2820)
					::tardis::Pointer _t16;		HX_STACK_VAR(_t16,"_t16");
					HX_STACK_LINE(2820)
					int _t17;		HX_STACK_VAR(_t17,"_t17");
					HX_STACK_LINE(2820)
					this->_latestPH = (int)519;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2820);
							{
								HX_STACK_LINE(2820)
								::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(2820)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(2820)
					if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(2820)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(2820)
					this->_t13 = this->_t1->addr(this->_t6);
					HX_STACK_LINE(2820)
					this->_t14 = this->_t3;
					HX_STACK_LINE(2820)
					_t15 = (this->_t7 + (int)1);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2820);
							{
								HX_STACK_LINE(2820)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(2820)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(2820)
					if (((bool((_t15 < (int)0)) || bool((_t15 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(2820)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(2820)
					_t16 = this->p_s->addr(_t15);
					HX_STACK_LINE(2820)
					_t17 = (int(_t16->ref()) | int((int)0));
					HX_STACK_LINE(2820)
					this->_t18 = _t17;
				}
				HX_STACK_LINE(2821)
				this->_latestPH = (int)519;
				HX_STACK_LINE(2822)
				this->_SF1 = ::tardis::Go_utf16_DecodeRune_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t14,this->_t18);
				HX_STACK_LINE(2823)
				this->_Next = (int)-1;
				HX_STACK_LINE(2824)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(2826)
				{
					HX_STACK_LINE(2826)
					this->_latestPH = (int)519;
					HX_STACK_LINE(2826)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(2827)
				this->_t19 = this->_SF1->res();
				HX_STACK_LINE(2829)
				{
					HX_STACK_LINE(2829)
					this->_t13->store(this->_t19);
					HX_STACK_LINE(2829)
					this->_t20 = (this->_t7 + (int)1);
					HX_STACK_LINE(2829)
					this->_t21 = (this->_t6 + (int)1);
					HX_STACK_LINE(2829)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(2830)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(2832)
				{
					HX_STACK_LINE(2832)
					this->_latestPH = (int)519;
					HX_STACK_LINE(2832)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(2833)
				{
					HX_STACK_LINE(2833)
					::tardis::Pointer _t22;		HX_STACK_VAR(_t22,"_t22");
					HX_STACK_LINE(2833)
					this->_latestPH = (int)524;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2833);
							{
								HX_STACK_LINE(2833)
								::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(2833)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(2833)
					if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(2833)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(2833)
					_t22 = this->_t1->addr(this->_t6);
					HX_STACK_LINE(2833)
					_t22->store((int)65533);
					HX_STACK_LINE(2833)
					this->_t23 = (this->_t6 + (int)1);
					HX_STACK_LINE(2833)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(2834)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(2836)
				{
					HX_STACK_LINE(2836)
					this->_latestPH = (int)519;
					HX_STACK_LINE(2836)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(2837)
				{
					HX_STACK_LINE(2837)
					bool _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(2837)
					this->_latestPH = (int)522;
					HX_STACK_LINE(2837)
					_t24 = (::tardis::Force_obj::uintCompare((int)55296,this->_t3) <= (int)0);
					HX_STACK_LINE(2837)
					this->_Next = (  ((_t24)) ? int((int)14) : int((int)15) );
				}
				HX_STACK_LINE(2838)
				this->_Phi = (int)7;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(2840)
				{
					HX_STACK_LINE(2840)
					this->_latestPH = (int)519;
					HX_STACK_LINE(2840)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(2841)
				{
					HX_STACK_LINE(2841)
					int _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(2841)
					::tardis::Pointer _t26;		HX_STACK_VAR(_t26,"_t26");
					HX_STACK_LINE(2841)
					int _t27;		HX_STACK_VAR(_t27,"_t27");
					HX_STACK_LINE(2841)
					this->_latestPH = (int)517;
					HX_STACK_LINE(2841)
					_t25 = (this->_t7 + (int)1);
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2841);
							{
								HX_STACK_LINE(2841)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(2841)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(2841)
					if (((bool((_t25 < (int)0)) || bool((_t25 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(2841)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(2841)
					_t26 = this->p_s->addr(_t25);
					HX_STACK_LINE(2841)
					_t27 = (int(_t26->ref()) | int((int)0));
					HX_STACK_LINE(2841)
					this->_t28 = (::tardis::Force_obj::uintCompare(_t27,(int)57344) < (int)0);
					HX_STACK_LINE(2841)
					this->_Next = (int)9;
				}
				HX_STACK_LINE(2842)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(2844)
				{
					HX_STACK_LINE(2844)
					this->_latestPH = (int)519;
					HX_STACK_LINE(2844)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(2845)
				this->_latestPH = (int)517;
				HX_STACK_LINE(2846)
				this->_t29 = (  (((this->_Phi == (int)1))) ? bool(false) : bool((  (((this->_Phi == (int)12))) ? bool(false) : bool((  (((this->_Phi == (int)11))) ? bool(false) : bool((  (((this->_Phi == (int)10))) ? bool(false) : bool((  (((this->_Phi == (int)8))) ? bool(this->_t28) : bool(false) )) )) )) )) );
				HX_STACK_LINE(2847)
				this->_Next = (  ((this->_t29)) ? int((int)5) : int((int)7) );
				HX_STACK_LINE(2848)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(2850)
				{
					HX_STACK_LINE(2850)
					this->_latestPH = (int)517;
					HX_STACK_LINE(2850)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(2851)
				{
					HX_STACK_LINE(2851)
					int _t30;		HX_STACK_VAR(_t30,"_t30");
					HX_STACK_LINE(2851)
					::tardis::Pointer _t31;		HX_STACK_VAR(_t31,"_t31");
					HX_STACK_LINE(2851)
					int _t32;		HX_STACK_VAR(_t32,"_t32");
					HX_STACK_LINE(2851)
					bool _t33;		HX_STACK_VAR(_t33,"_t33");
					HX_STACK_LINE(2851)
					_t30 = (this->_t7 + (int)1);
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2851);
							{
								HX_STACK_LINE(2851)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(2851)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(2851)
					if (((bool((_t30 < (int)0)) || bool((_t30 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(2851)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(2851)
					_t31 = this->p_s->addr(_t30);
					HX_STACK_LINE(2851)
					_t32 = (int(_t31->ref()) | int((int)0));
					HX_STACK_LINE(2851)
					_t33 = (::tardis::Force_obj::uintCompare((int)56320,_t32) <= (int)0);
					HX_STACK_LINE(2851)
					this->_Next = (  ((_t33)) ? int((int)8) : int((int)9) );
				}
				HX_STACK_LINE(2852)
				this->_Phi = (int)10;
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(2854)
				{
					HX_STACK_LINE(2854)
					this->_latestPH = (int)517;
					HX_STACK_LINE(2854)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(2855)
				{
					HX_STACK_LINE(2855)
					int _t34;		HX_STACK_VAR(_t34,"_t34");
					HX_STACK_LINE(2855)
					int _t35;		HX_STACK_VAR(_t35,"_t35");
					HX_STACK_LINE(2855)
					bool _t36;		HX_STACK_VAR(_t36,"_t36");
					HX_STACK_LINE(2855)
					this->_latestPH = (int)516;
					HX_STACK_LINE(2855)
					_t34 = (this->_t7 + (int)1);
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2855);
							{
								HX_STACK_LINE(2855)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(2855)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(2855)
					_t35 = _Function_4_1::Block(this);
					HX_STACK_LINE(2855)
					_t36 = (_t34 < _t35);
					HX_STACK_LINE(2855)
					this->_Next = (  ((_t36)) ? int((int)10) : int((int)9) );
				}
				HX_STACK_LINE(2856)
				this->_Phi = (int)11;
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(2858)
				{
					HX_STACK_LINE(2858)
					this->_latestPH = (int)517;
					HX_STACK_LINE(2858)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(2859)
				{
					HX_STACK_LINE(2859)
					bool _t37;		HX_STACK_VAR(_t37,"_t37");
					HX_STACK_LINE(2859)
					_t37 = (::tardis::Force_obj::uintCompare(this->_t3,(int)56320) < (int)0);
					HX_STACK_LINE(2859)
					this->_Next = (  ((_t37)) ? int((int)11) : int((int)9) );
				}
				HX_STACK_LINE(2860)
				this->_Phi = (int)12;
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(2862)
				{
					HX_STACK_LINE(2862)
					this->_latestPH = (int)517;
					HX_STACK_LINE(2862)
					this->_latestBlock = (int)13;
				}
				HX_STACK_LINE(2863)
				{
					HX_STACK_LINE(2863)
					::tardis::Pointer _t38;		HX_STACK_VAR(_t38,"_t38");
					HX_STACK_LINE(2863)
					int _t39;		HX_STACK_VAR(_t39,"_t39");
					HX_STACK_LINE(2863)
					this->_latestPH = (int)528;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Decode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",2863);
							{
								HX_STACK_LINE(2863)
								::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(2863)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(2863)
					if (((bool((this->_t6 < (int)0)) || bool((this->_t6 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(2863)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(2863)
					_t38 = this->_t1->addr(this->_t6);
					HX_STACK_LINE(2863)
					_t39 = this->_t3;
					HX_STACK_LINE(2863)
					_t38->store(_t39);
					HX_STACK_LINE(2863)
					this->_t40 = (this->_t6 + (int)1);
					HX_STACK_LINE(2863)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(2864)
				this->_Phi = (int)13;
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(2866)
				{
					HX_STACK_LINE(2866)
					this->_latestPH = (int)517;
					HX_STACK_LINE(2866)
					this->_latestBlock = (int)14;
				}
				HX_STACK_LINE(2867)
				{
					HX_STACK_LINE(2867)
					this->_latestPH = (int)522;
					HX_STACK_LINE(2867)
					this->_t41 = (::tardis::Force_obj::uintCompare(this->_t3,(int)57344) < (int)0);
					HX_STACK_LINE(2867)
					this->_Next = (int)15;
				}
				HX_STACK_LINE(2868)
				this->_Phi = (int)14;
			}
			;break;
			case (int)15: {
				HX_STACK_LINE(2870)
				{
					HX_STACK_LINE(2870)
					this->_latestPH = (int)517;
					HX_STACK_LINE(2870)
					this->_latestBlock = (int)15;
				}
				HX_STACK_LINE(2871)
				this->_latestPH = (int)522;
				HX_STACK_LINE(2872)
				this->_t42 = (  (((this->_Phi == (int)7))) ? bool(false) : bool((  (((this->_Phi == (int)14))) ? bool(this->_t41) : bool(false) )) );
				HX_STACK_LINE(2873)
				this->_Next = (  ((this->_t42)) ? int((int)6) : int((int)13) );
				HX_STACK_LINE(2874)
				this->_Phi = (int)15;
			}
			;break;
			default: {
				HX_STACK_LINE(2875)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(2782)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,run,return )

Dynamic Go_utf16_Decode_obj::res( ){
	HX_STACK_PUSH("Go_utf16_Decode::res","tardis/Go.hx",2721);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2721)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Decode_obj,res,return )

::tardis::Slice Go_utf16_Decode_obj::callFromHaxe( ::tardis::Slice p_s){
	HX_STACK_PUSH("Go_utf16_Decode::callFromHaxe","tardis/Go.hx",2768);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(2769)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(2769)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(2770)
	::tardis::Go_utf16_Decode _sf = hx::TCast< ::tardis::Go_utf16_Decode >::cast(::tardis::Go_utf16_Decode_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2771)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2771)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(2772)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf16_Decode_obj,callFromHaxe,return )

::tardis::Slice Go_utf16_Decode_obj::callFromRT( int _gr,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_utf16_Decode::callFromRT","tardis/Go.hx",2774);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(2775)
	::tardis::Go_utf16_Decode _sf = hx::TCast< ::tardis::Go_utf16_Decode >::cast(::tardis::Go_utf16_Decode_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2776)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2776)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(2776)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(2776)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(2776)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(2777)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf16_Decode_obj,callFromRT,return )

::tardis::Go_utf16_Decode Go_utf16_Decode_obj::call( int gr,Dynamic _bds,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_utf16_Decode::call","tardis/Go.hx",2780);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(2780)
	return ::tardis::Go_utf16_Decode_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf16_Decode_obj,call,return )


Go_utf16_Decode_obj::Go_utf16_Decode_obj()
{
}

void Go_utf16_Decode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf16_Decode);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t42,"_t42");
	HX_MARK_MEMBER_NAME(_t41,"_t41");
	HX_MARK_MEMBER_NAME(_t40,"_t40");
	HX_MARK_MEMBER_NAME(_t39,"_t39");
	HX_MARK_MEMBER_NAME(_t38,"_t38");
	HX_MARK_MEMBER_NAME(_t37,"_t37");
	HX_MARK_MEMBER_NAME(_t36,"_t36");
	HX_MARK_MEMBER_NAME(_t35,"_t35");
	HX_MARK_MEMBER_NAME(_t34,"_t34");
	HX_MARK_MEMBER_NAME(_t33,"_t33");
	HX_MARK_MEMBER_NAME(_t32,"_t32");
	HX_MARK_MEMBER_NAME(_t31,"_t31");
	HX_MARK_MEMBER_NAME(_t30,"_t30");
	HX_MARK_MEMBER_NAME(_t29,"_t29");
	HX_MARK_MEMBER_NAME(_t28,"_t28");
	HX_MARK_MEMBER_NAME(_t27,"_t27");
	HX_MARK_MEMBER_NAME(_t26,"_t26");
	HX_MARK_MEMBER_NAME(_t25,"_t25");
	HX_MARK_MEMBER_NAME(_t24,"_t24");
	HX_MARK_MEMBER_NAME(_t23,"_t23");
	HX_MARK_MEMBER_NAME(_t22,"_t22");
	HX_MARK_MEMBER_NAME(_t21,"_t21");
	HX_MARK_MEMBER_NAME(_t20,"_t20");
	HX_MARK_MEMBER_NAME(_t19,"_t19");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_t18,"_t18");
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

void Go_utf16_Decode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t42,"_t42");
	HX_VISIT_MEMBER_NAME(_t41,"_t41");
	HX_VISIT_MEMBER_NAME(_t40,"_t40");
	HX_VISIT_MEMBER_NAME(_t39,"_t39");
	HX_VISIT_MEMBER_NAME(_t38,"_t38");
	HX_VISIT_MEMBER_NAME(_t37,"_t37");
	HX_VISIT_MEMBER_NAME(_t36,"_t36");
	HX_VISIT_MEMBER_NAME(_t35,"_t35");
	HX_VISIT_MEMBER_NAME(_t34,"_t34");
	HX_VISIT_MEMBER_NAME(_t33,"_t33");
	HX_VISIT_MEMBER_NAME(_t32,"_t32");
	HX_VISIT_MEMBER_NAME(_t31,"_t31");
	HX_VISIT_MEMBER_NAME(_t30,"_t30");
	HX_VISIT_MEMBER_NAME(_t29,"_t29");
	HX_VISIT_MEMBER_NAME(_t28,"_t28");
	HX_VISIT_MEMBER_NAME(_t27,"_t27");
	HX_VISIT_MEMBER_NAME(_t26,"_t26");
	HX_VISIT_MEMBER_NAME(_t25,"_t25");
	HX_VISIT_MEMBER_NAME(_t24,"_t24");
	HX_VISIT_MEMBER_NAME(_t23,"_t23");
	HX_VISIT_MEMBER_NAME(_t22,"_t22");
	HX_VISIT_MEMBER_NAME(_t21,"_t21");
	HX_VISIT_MEMBER_NAME(_t20,"_t20");
	HX_VISIT_MEMBER_NAME(_t19,"_t19");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_t18,"_t18");
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

Dynamic Go_utf16_Decode_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_t42") ) { return _t42; }
		if (HX_FIELD_EQ(inName,"_t41") ) { return _t41; }
		if (HX_FIELD_EQ(inName,"_t40") ) { return _t40; }
		if (HX_FIELD_EQ(inName,"_t39") ) { return _t39; }
		if (HX_FIELD_EQ(inName,"_t38") ) { return _t38; }
		if (HX_FIELD_EQ(inName,"_t37") ) { return _t37; }
		if (HX_FIELD_EQ(inName,"_t36") ) { return _t36; }
		if (HX_FIELD_EQ(inName,"_t35") ) { return _t35; }
		if (HX_FIELD_EQ(inName,"_t34") ) { return _t34; }
		if (HX_FIELD_EQ(inName,"_t33") ) { return _t33; }
		if (HX_FIELD_EQ(inName,"_t32") ) { return _t32; }
		if (HX_FIELD_EQ(inName,"_t31") ) { return _t31; }
		if (HX_FIELD_EQ(inName,"_t30") ) { return _t30; }
		if (HX_FIELD_EQ(inName,"_t29") ) { return _t29; }
		if (HX_FIELD_EQ(inName,"_t28") ) { return _t28; }
		if (HX_FIELD_EQ(inName,"_t27") ) { return _t27; }
		if (HX_FIELD_EQ(inName,"_t26") ) { return _t26; }
		if (HX_FIELD_EQ(inName,"_t25") ) { return _t25; }
		if (HX_FIELD_EQ(inName,"_t24") ) { return _t24; }
		if (HX_FIELD_EQ(inName,"_t23") ) { return _t23; }
		if (HX_FIELD_EQ(inName,"_t22") ) { return _t22; }
		if (HX_FIELD_EQ(inName,"_t21") ) { return _t21; }
		if (HX_FIELD_EQ(inName,"_t20") ) { return _t20; }
		if (HX_FIELD_EQ(inName,"_t19") ) { return _t19; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_t18") ) { return _t18; }
		if (HX_FIELD_EQ(inName,"_t17") ) { return _t17; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
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
		if (HX_FIELD_EQ(inName,"SubFn16") ) { return SubFn16_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn15") ) { return SubFn15_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn14") ) { return SubFn14_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn13") ) { return SubFn13_dyn(); }
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

Dynamic Go_utf16_Decode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t42") ) { _t42=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t41") ) { _t41=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t40") ) { _t40=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t39") ) { _t39=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t38") ) { _t38=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t37") ) { _t37=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t36") ) { _t36=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t35") ) { _t35=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t34") ) { _t34=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t33") ) { _t33=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t32") ) { _t32=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t31") ) { _t31=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t30") ) { _t30=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t29") ) { _t29=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t28") ) { _t28=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t27") ) { _t27=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t26") ) { _t26=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf16_Decode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t42"));
	outFields->push(HX_CSTRING("_t41"));
	outFields->push(HX_CSTRING("_t40"));
	outFields->push(HX_CSTRING("_t39"));
	outFields->push(HX_CSTRING("_t38"));
	outFields->push(HX_CSTRING("_t37"));
	outFields->push(HX_CSTRING("_t36"));
	outFields->push(HX_CSTRING("_t35"));
	outFields->push(HX_CSTRING("_t34"));
	outFields->push(HX_CSTRING("_t33"));
	outFields->push(HX_CSTRING("_t32"));
	outFields->push(HX_CSTRING("_t31"));
	outFields->push(HX_CSTRING("_t30"));
	outFields->push(HX_CSTRING("_t29"));
	outFields->push(HX_CSTRING("_t28"));
	outFields->push(HX_CSTRING("_t27"));
	outFields->push(HX_CSTRING("_t26"));
	outFields->push(HX_CSTRING("_t25"));
	outFields->push(HX_CSTRING("_t24"));
	outFields->push(HX_CSTRING("_t23"));
	outFields->push(HX_CSTRING("_t22"));
	outFields->push(HX_CSTRING("_t21"));
	outFields->push(HX_CSTRING("_t20"));
	outFields->push(HX_CSTRING("_t19"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_t18"));
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
	HX_CSTRING("SubFn16"),
	HX_CSTRING("SubFn15"),
	HX_CSTRING("SubFn14"),
	HX_CSTRING("SubFn13"),
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
	HX_CSTRING("_t42"),
	HX_CSTRING("_t41"),
	HX_CSTRING("_t40"),
	HX_CSTRING("_t39"),
	HX_CSTRING("_t38"),
	HX_CSTRING("_t37"),
	HX_CSTRING("_t36"),
	HX_CSTRING("_t35"),
	HX_CSTRING("_t34"),
	HX_CSTRING("_t33"),
	HX_CSTRING("_t32"),
	HX_CSTRING("_t31"),
	HX_CSTRING("_t30"),
	HX_CSTRING("_t29"),
	HX_CSTRING("_t28"),
	HX_CSTRING("_t27"),
	HX_CSTRING("_t26"),
	HX_CSTRING("_t25"),
	HX_CSTRING("_t24"),
	HX_CSTRING("_t23"),
	HX_CSTRING("_t22"),
	HX_CSTRING("_t21"),
	HX_CSTRING("_t20"),
	HX_CSTRING("_t19"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("_t18"),
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
	HX_MARK_MEMBER_NAME(Go_utf16_Decode_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf16_Decode_obj::__mClass,"__mClass");
};

Class Go_utf16_Decode_obj::__mClass;

void Go_utf16_Decode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf16_Decode"), hx::TCanCast< Go_utf16_Decode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf16_Decode_obj::__boot()
{
}

} // end namespace tardis
