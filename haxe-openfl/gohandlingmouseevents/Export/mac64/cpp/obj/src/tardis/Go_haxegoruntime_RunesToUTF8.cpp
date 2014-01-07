#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Deep
#include <tardis/Deep.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF8
#include <tardis/Go_haxegoruntime_RunesToUTF8.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_EncodeRune
#include <tardis/Go_utf8_EncodeRune.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_RuneLen
#include <tardis/Go_utf8_RuneLen.h>
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

Void Go_haxegoruntime_RunesToUTF8_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_r)
{
HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::new","tardis/Go.hx",3801);
{
	HX_STACK_LINE(3827)
	this->_Next = (int)0;
	HX_STACK_LINE(3826)
	this->_Phi = (int)0;
	HX_STACK_LINE(3825)
	this->_t13 = null();
	HX_STACK_LINE(3823)
	this->_t11 = (int)0;
	HX_STACK_LINE(3822)
	this->_t10 = null();
	HX_STACK_LINE(3821)
	this->_t9 = null();
	HX_STACK_LINE(3820)
	this->_t8 = (int)0;
	HX_STACK_LINE(3818)
	this->_t7 = (int)0;
	HX_STACK_LINE(3817)
	this->_t6 = null();
	HX_STACK_LINE(3816)
	this->_t5 = false;
	HX_STACK_LINE(3815)
	this->_t4 = (int)0;
	HX_STACK_LINE(3814)
	this->_t3 = (int)0;
	HX_STACK_LINE(3813)
	this->_t2 = null();
	HX_STACK_LINE(3812)
	this->_t1 = (int)0;
	HX_STACK_LINE(3811)
	this->_t0 = null();
	HX_STACK_LINE(3804)
	super::__construct(gr,(int)109,HX_CSTRING("Go_haxegoruntime_RunesToUTF8"));
	HX_STACK_LINE(3805)
	this->_bds = _bds;
	HX_STACK_LINE(3806)
	this->p_r = p_r;
	HX_STACK_LINE(3807)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_RunesToUTF8_obj::~Go_haxegoruntime_RunesToUTF8_obj() { }

Dynamic Go_haxegoruntime_RunesToUTF8_obj::__CreateEmpty() { return  new Go_haxegoruntime_RunesToUTF8_obj; }
hx::ObjectPtr< Go_haxegoruntime_RunesToUTF8_obj > Go_haxegoruntime_RunesToUTF8_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_r)
{  hx::ObjectPtr< Go_haxegoruntime_RunesToUTF8_obj > result = new Go_haxegoruntime_RunesToUTF8_obj();
	result->__construct(gr,_bds,p_r);
	return result;}

Dynamic Go_haxegoruntime_RunesToUTF8_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_RunesToUTF8_obj > result = new Go_haxegoruntime_RunesToUTF8_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_RunesToUTF8_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_RunesToUTF8_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::SubFn4","tardis/Go.hx",3913);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3914)
		this->_latestPH = (int)115;
		struct _Function_1_1{
			inline static ::tardis::Slice Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
				{
					HX_STACK_LINE(3915)
					::tardis::Slice _v;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3915)
					if (((__this->_t2 == null()))){
						HX_STACK_LINE(3915)
						_v = __this->_t9;
					}
					else{
						struct _Function_3_1{
							inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
								HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
								{
									HX_STACK_LINE(3915)
									::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
									HX_STACK_LINE(3915)
									return (_this->end - _this->start);
								}
								return null();
							}
						};
						HX_STACK_LINE(3915)
						if (((_Function_3_1::Block(__this) == (int)0))){
							HX_STACK_LINE(3915)
							_v = __this->_t9;
						}
						else{
							HX_STACK_LINE(3915)
							if (((__this->_t9 == null()))){
								HX_STACK_LINE(3915)
								_v = __this->_t2;
							}
							else{
								struct _Function_5_1{
									inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
										{
											HX_STACK_LINE(3915)
											::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
											HX_STACK_LINE(3915)
											return (_this->end - _this->start);
										}
										return null();
									}
								};
								HX_STACK_LINE(3915)
								if (((_Function_5_1::Block(__this) == (int)0))){
									HX_STACK_LINE(3915)
									_v = __this->_t2;
								}
								else{
									struct _Function_6_1{
										inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
											HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
											{
												HX_STACK_LINE(3915)
												::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
												HX_STACK_LINE(3915)
												return (_this->end - _this->start);
											}
											return null();
										}
									};
									HX_STACK_LINE(3915)
									int l0 = _Function_6_1::Block(__this);		HX_STACK_VAR(l0,"l0");
									struct _Function_6_2{
										inline static Array< int > Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
											HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
											{
												HX_STACK_LINE(3915)
												Array< int > _v1 = Array_obj< int >::__new();		HX_STACK_VAR(_v1,"_v1");
												HX_STACK_LINE(3915)
												{
													struct _Function_8_1{
														inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
															HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
															{
																HX_STACK_LINE(3915)
																::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
																HX_STACK_LINE(3915)
																return (_this->end - _this->start);
															}
															return null();
														}
													};
													struct _Function_8_2{
														inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
															HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
															{
																HX_STACK_LINE(3915)
																::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
																HX_STACK_LINE(3915)
																return (_this->end - _this->start);
															}
															return null();
														}
													};
													HX_STACK_LINE(3915)
													int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
													int _g = (_Function_8_1::Block(__this) + _Function_8_2::Block(__this));		HX_STACK_VAR(_g,"_g");
													HX_STACK_LINE(3915)
													while(((_g1 < _g))){
														HX_STACK_LINE(3915)
														int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
														HX_STACK_LINE(3915)
														_v1[_i] = (int)0;
													}
												}
												HX_STACK_LINE(3915)
												return _v1;
											}
											return null();
										}
									};
									struct _Function_6_3{
										inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
											HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
											{
												HX_STACK_LINE(3915)
												::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
												HX_STACK_LINE(3915)
												return (_this->end - _this->start);
											}
											return null();
										}
									};
									struct _Function_6_4{
										inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
											HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
											{
												HX_STACK_LINE(3915)
												::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
												HX_STACK_LINE(3915)
												return (_this->end - _this->start);
											}
											return null();
										}
									};
									HX_STACK_LINE(3915)
									_v = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_6_2::Block(__this)),(int)0,(_Function_6_3::Block(__this) + _Function_6_4::Block(__this)));
									HX_STACK_LINE(3915)
									{
										HX_STACK_LINE(3915)
										int _g = (int)0;		HX_STACK_VAR(_g,"_g");
										HX_STACK_LINE(3915)
										while(((_g < l0))){
											HX_STACK_LINE(3915)
											int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
											HX_STACK_LINE(3915)
											_v->setAt(_i,::tardis::Deep_obj::copy(__this->_t2->getAt(_i)));
										}
									}
									HX_STACK_LINE(3915)
									{
										struct _Function_7_1{
											inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
												HX_STACK_PUSH("*::closure","tardis/Go.hx",3915);
												{
													HX_STACK_LINE(3915)
													::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
													HX_STACK_LINE(3915)
													return (_this->end - _this->start);
												}
												return null();
											}
										};
										HX_STACK_LINE(3915)
										int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
										int _g = _Function_7_1::Block(__this);		HX_STACK_VAR(_g,"_g");
										HX_STACK_LINE(3915)
										while(((_g1 < _g))){
											HX_STACK_LINE(3915)
											int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
											HX_STACK_LINE(3915)
											_v->setAt((_i + l0),::tardis::Deep_obj::copy(__this->_t9->getAt(_i)));
										}
									}
								}
							}
						}
					}
					HX_STACK_LINE(3915)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(3915)
		this->_t13 = _Function_1_1::Block(this);
		HX_STACK_LINE(3916)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF8_obj,SubFn4,(void))

Void Go_haxegoruntime_RunesToUTF8_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::SubFn3","tardis/Go.hx",3905);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3906)
		::tardis::Pointer _t10;		HX_STACK_VAR(_t10,"_t10");
		struct _Function_1_1{
			inline static Array< int > Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3907);
				{
					HX_STACK_LINE(3907)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3907)
					{
						HX_STACK_LINE(3907)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						int _g = __this->_t8;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(3907)
						while(((_g1 < _g))){
							HX_STACK_LINE(3907)
							int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(3907)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(3907)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(3907)
		this->_t9 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_1::Block(this)),(int)0,this->_t8);
		HX_STACK_LINE(3908)
		this->_latestPH = (int)114;
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3909);
				{
					HX_STACK_LINE(3909)
					::tardis::Slice _this = __this->p_r;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(3909)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(3909)
		if (((bool((this->_t4 < (int)0)) || bool((this->_t4 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(3909)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(3910)
		_t10 = this->p_r->addr(this->_t4);
		HX_STACK_LINE(3911)
		this->_t11 = (int(_t10->ref()) | int((int)0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF8_obj,SubFn3,(void))

Void Go_haxegoruntime_RunesToUTF8_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::SubFn2","tardis/Go.hx",3898);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3899)
		::tardis::Pointer _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(3900)
		this->_latestPH = (int)113;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3901);
				{
					HX_STACK_LINE(3901)
					::tardis::Slice _this = __this->p_r;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(3901)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(3901)
		if (((bool((this->_t4 < (int)0)) || bool((this->_t4 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(3901)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(3902)
		_t6 = this->p_r->addr(this->_t4);
		HX_STACK_LINE(3903)
		this->_t7 = (int(_t6->ref()) | int((int)0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF8_obj,SubFn2,(void))

Void Go_haxegoruntime_RunesToUTF8_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::SubFn1","tardis/Go.hx",3892);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3893)
		bool _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(3894)
		this->_t4 = (this->_t3 + (int)1);
		HX_STACK_LINE(3895)
		_t5 = (this->_t4 < this->_t1);
		HX_STACK_LINE(3896)
		this->_Next = (  ((_t5)) ? int((int)2) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF8_obj,SubFn1,(void))

Void Go_haxegoruntime_RunesToUTF8_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::SubFn0","tardis/Go.hx",3886);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3887)
		this->_latestPH = (int)111;
		struct _Function_1_1{
			inline static Array< int > Block( ){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3888);
				{
					HX_STACK_LINE(3888)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3888)
					{
						HX_STACK_LINE(3888)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(3888)
						while(((_g < (int)0))){
							HX_STACK_LINE(3888)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(3888)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(3888)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(3888)
		this->_t0 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_1::Block()),(int)0,(int)0);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3889);
				{
					HX_STACK_LINE(3889)
					::tardis::Slice _v = __this->p_r;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3889)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(3889)
		this->_t1 = _Function_1_2::Block(this);
		HX_STACK_LINE(3890)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF8_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_RunesToUTF8_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::run","tardis/Go.hx",3842);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3842)
	while((true)){
		HX_STACK_LINE(3844)
		::tardis::Go_haxegoruntime_RunesToUTF8 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3844)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3846)
				{
					HX_STACK_LINE(3846)
					this->_latestPH = (int)109;
					HX_STACK_LINE(3846)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3847)
				{
					HX_STACK_LINE(3847)
					this->_latestPH = (int)111;
					struct _Function_4_1{
						inline static Array< int > Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3847);
							{
								HX_STACK_LINE(3847)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3847)
								{
									HX_STACK_LINE(3847)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(3847)
									while(((_g1 < (int)0))){
										HX_STACK_LINE(3847)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(3847)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(3847)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(3847)
					this->_t0 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_1::Block()),(int)0,(int)0);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3847);
							{
								HX_STACK_LINE(3847)
								::tardis::Slice _v = __this->p_r;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3847)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(3847)
					this->_t1 = _Function_4_2::Block(this);
					HX_STACK_LINE(3847)
					this->_Next = (int)1;
				}
				HX_STACK_LINE(3848)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(3850)
				{
					HX_STACK_LINE(3850)
					this->_latestPH = (int)109;
					HX_STACK_LINE(3850)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(3851)
				this->_latestPH = (int)110;
				HX_STACK_LINE(3852)
				this->_t2 = (  (((this->_Phi == (int)0))) ? ::tardis::Slice(this->_t0) : ::tardis::Slice((  (((this->_Phi == (int)2))) ? ::tardis::Slice(this->_t13) : ::tardis::Slice(::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(Array_obj< int >::__new()),(int)0,(int)0)) )) );
				HX_STACK_LINE(3853)
				this->_t3 = (  (((this->_Phi == (int)0))) ? int((int)-1) : int((  (((this->_Phi == (int)2))) ? int(this->_t4) : int((int)0) )) );
				HX_STACK_LINE(3854)
				{
					HX_STACK_LINE(3854)
					bool _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(3854)
					this->_t4 = (this->_t3 + (int)1);
					HX_STACK_LINE(3854)
					_t5 = (this->_t4 < this->_t1);
					HX_STACK_LINE(3854)
					this->_Next = (  ((_t5)) ? int((int)2) : int((int)3) );
				}
				HX_STACK_LINE(3855)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(3857)
				{
					HX_STACK_LINE(3857)
					this->_latestPH = (int)110;
					HX_STACK_LINE(3857)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(3858)
				{
					HX_STACK_LINE(3858)
					::tardis::Pointer _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(3858)
					this->_latestPH = (int)113;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3858);
							{
								HX_STACK_LINE(3858)
								::tardis::Slice _this = __this->p_r;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(3858)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(3858)
					if (((bool((this->_t4 < (int)0)) || bool((this->_t4 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(3858)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(3858)
					_t6 = this->p_r->addr(this->_t4);
					HX_STACK_LINE(3858)
					this->_t7 = (int(_t6->ref()) | int((int)0));
				}
				HX_STACK_LINE(3859)
				this->_latestPH = (int)113;
				HX_STACK_LINE(3860)
				this->_SF1 = ::tardis::Go_utf8_RuneLen_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t7);
				HX_STACK_LINE(3861)
				this->_Next = (int)-1;
				HX_STACK_LINE(3862)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(3864)
				{
					HX_STACK_LINE(3864)
					this->_latestPH = (int)113;
					HX_STACK_LINE(3864)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(3865)
				this->_t8 = this->_SF1->res();
				HX_STACK_LINE(3867)
				{
					HX_STACK_LINE(3867)
					::tardis::Pointer _t10;		HX_STACK_VAR(_t10,"_t10");
					struct _Function_4_1{
						inline static Array< int > Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3867);
							{
								HX_STACK_LINE(3867)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3867)
								{
									HX_STACK_LINE(3867)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									int _g2 = __this->_t8;		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(3867)
									while(((_g1 < _g2))){
										HX_STACK_LINE(3867)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(3867)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(3867)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(3867)
					this->_t9 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_1::Block(this)),(int)0,this->_t8);
					HX_STACK_LINE(3867)
					this->_latestPH = (int)114;
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3867);
							{
								HX_STACK_LINE(3867)
								::tardis::Slice _this = __this->p_r;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(3867)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(3867)
					if (((bool((this->_t4 < (int)0)) || bool((this->_t4 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(3867)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(3867)
					_t10 = this->p_r->addr(this->_t4);
					HX_STACK_LINE(3867)
					this->_t11 = (int(_t10->ref()) | int((int)0));
				}
				HX_STACK_LINE(3868)
				this->_latestPH = (int)114;
				HX_STACK_LINE(3869)
				::tardis::Go_utf8_EncodeRune_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t9,this->_t11);
				HX_STACK_LINE(3870)
				this->_Next = (int)-2;
				HX_STACK_LINE(3871)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-2: {
				HX_STACK_LINE(3873)
				{
					HX_STACK_LINE(3873)
					this->_latestPH = (int)114;
					HX_STACK_LINE(3873)
					this->_latestBlock = (int)-2;
				}
				HX_STACK_LINE(3875)
				{
					HX_STACK_LINE(3875)
					this->_latestPH = (int)115;
					struct _Function_4_1{
						inline static ::tardis::Slice Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
							{
								HX_STACK_LINE(3875)
								::tardis::Slice _v;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3875)
								if (((__this->_t2 == null()))){
									HX_STACK_LINE(3875)
									_v = __this->_t9;
								}
								else{
									struct _Function_6_1{
										inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
											HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
											{
												HX_STACK_LINE(3875)
												::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
												HX_STACK_LINE(3875)
												return (_this->end - _this->start);
											}
											return null();
										}
									};
									HX_STACK_LINE(3875)
									if (((_Function_6_1::Block(__this) == (int)0))){
										HX_STACK_LINE(3875)
										_v = __this->_t9;
									}
									else{
										HX_STACK_LINE(3875)
										if (((__this->_t9 == null()))){
											HX_STACK_LINE(3875)
											_v = __this->_t2;
										}
										else{
											struct _Function_8_1{
												inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
													HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
													{
														HX_STACK_LINE(3875)
														::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
														HX_STACK_LINE(3875)
														return (_this->end - _this->start);
													}
													return null();
												}
											};
											HX_STACK_LINE(3875)
											if (((_Function_8_1::Block(__this) == (int)0))){
												HX_STACK_LINE(3875)
												_v = __this->_t2;
											}
											else{
												struct _Function_9_1{
													inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
														HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
														{
															HX_STACK_LINE(3875)
															::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
															HX_STACK_LINE(3875)
															return (_this->end - _this->start);
														}
														return null();
													}
												};
												HX_STACK_LINE(3875)
												int l0 = _Function_9_1::Block(__this);		HX_STACK_VAR(l0,"l0");
												struct _Function_9_2{
													inline static Array< int > Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
														HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
														{
															HX_STACK_LINE(3875)
															Array< int > _v1 = Array_obj< int >::__new();		HX_STACK_VAR(_v1,"_v1");
															HX_STACK_LINE(3875)
															{
																struct _Function_11_1{
																	inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
																		HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
																		{
																			HX_STACK_LINE(3875)
																			::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
																			HX_STACK_LINE(3875)
																			return (_this->end - _this->start);
																		}
																		return null();
																	}
																};
																struct _Function_11_2{
																	inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
																		HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
																		{
																			HX_STACK_LINE(3875)
																			::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
																			HX_STACK_LINE(3875)
																			return (_this->end - _this->start);
																		}
																		return null();
																	}
																};
																HX_STACK_LINE(3875)
																int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
																int _g2 = (_Function_11_1::Block(__this) + _Function_11_2::Block(__this));		HX_STACK_VAR(_g2,"_g2");
																HX_STACK_LINE(3875)
																while(((_g1 < _g2))){
																	HX_STACK_LINE(3875)
																	int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
																	HX_STACK_LINE(3875)
																	_v1[_i] = (int)0;
																}
															}
															HX_STACK_LINE(3875)
															return _v1;
														}
														return null();
													}
												};
												struct _Function_9_3{
													inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
														HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
														{
															HX_STACK_LINE(3875)
															::tardis::Slice _this = __this->_t2;		HX_STACK_VAR(_this,"_this");
															HX_STACK_LINE(3875)
															return (_this->end - _this->start);
														}
														return null();
													}
												};
												struct _Function_9_4{
													inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
														HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
														{
															HX_STACK_LINE(3875)
															::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
															HX_STACK_LINE(3875)
															return (_this->end - _this->start);
														}
														return null();
													}
												};
												HX_STACK_LINE(3875)
												_v = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_9_2::Block(__this)),(int)0,(_Function_9_3::Block(__this) + _Function_9_4::Block(__this)));
												HX_STACK_LINE(3875)
												{
													HX_STACK_LINE(3875)
													int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
													HX_STACK_LINE(3875)
													while(((_g1 < l0))){
														HX_STACK_LINE(3875)
														int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
														HX_STACK_LINE(3875)
														_v->setAt(_i,::tardis::Deep_obj::copy(__this->_t2->getAt(_i)));
													}
												}
												HX_STACK_LINE(3875)
												{
													struct _Function_10_1{
														inline static int Block( ::tardis::Go_haxegoruntime_RunesToUTF8_obj *__this){
															HX_STACK_PUSH("*::closure","tardis/Go.hx",3875);
															{
																HX_STACK_LINE(3875)
																::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
																HX_STACK_LINE(3875)
																return (_this->end - _this->start);
															}
															return null();
														}
													};
													HX_STACK_LINE(3875)
													int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
													int _g2 = _Function_10_1::Block(__this);		HX_STACK_VAR(_g2,"_g2");
													HX_STACK_LINE(3875)
													while(((_g1 < _g2))){
														HX_STACK_LINE(3875)
														int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
														HX_STACK_LINE(3875)
														_v->setAt((_i + l0),::tardis::Deep_obj::copy(__this->_t9->getAt(_i)));
													}
												}
											}
										}
									}
								}
								HX_STACK_LINE(3875)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(3875)
					this->_t13 = _Function_4_1::Block(this);
					HX_STACK_LINE(3875)
					this->_Next = (int)1;
				}
				HX_STACK_LINE(3876)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(3878)
				{
					HX_STACK_LINE(3878)
					this->_latestPH = (int)114;
					HX_STACK_LINE(3878)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(3879)
				this->_latestPH = (int)117;
				HX_STACK_LINE(3880)
				this->_res = this->_t2;
				HX_STACK_LINE(3881)
				this->_incomplete = false;
				HX_STACK_LINE(3882)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3883)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3885)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3842)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF8_obj,run,return )

Dynamic Go_haxegoruntime_RunesToUTF8_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::res","tardis/Go.hx",3810);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3810)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF8_obj,res,return )

::tardis::Slice Go_haxegoruntime_RunesToUTF8_obj::callFromHaxe( ::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::callFromHaxe","tardis/Go.hx",3828);
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(3829)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3829)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3830)
	::tardis::Go_haxegoruntime_RunesToUTF8 _sf = hx::TCast< ::tardis::Go_haxegoruntime_RunesToUTF8 >::cast(::tardis::Go_haxegoruntime_RunesToUTF8_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3831)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3831)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3832)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_RunesToUTF8_obj,callFromHaxe,return )

::tardis::Slice Go_haxegoruntime_RunesToUTF8_obj::callFromRT( int _gr,::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::callFromRT","tardis/Go.hx",3834);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(3835)
	::tardis::Go_haxegoruntime_RunesToUTF8 _sf = hx::TCast< ::tardis::Go_haxegoruntime_RunesToUTF8 >::cast(::tardis::Go_haxegoruntime_RunesToUTF8_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3836)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3836)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3836)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3836)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3836)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3837)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_RunesToUTF8_obj,callFromRT,return )

::tardis::Go_haxegoruntime_RunesToUTF8 Go_haxegoruntime_RunesToUTF8_obj::call( int gr,Dynamic _bds,::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF8::call","tardis/Go.hx",3840);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(3840)
	return ::tardis::Go_haxegoruntime_RunesToUTF8_obj::__new(gr,_bds,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_RunesToUTF8_obj,call,return )


Go_haxegoruntime_RunesToUTF8_obj::Go_haxegoruntime_RunesToUTF8_obj()
{
}

void Go_haxegoruntime_RunesToUTF8_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_RunesToUTF8);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t13,"_t13");
	HX_MARK_MEMBER_NAME(_SF2,"_SF2");
	HX_MARK_MEMBER_NAME(_t11,"_t11");
	HX_MARK_MEMBER_NAME(_t10,"_t10");
	HX_MARK_MEMBER_NAME(_t9,"_t9");
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
	HX_MARK_MEMBER_NAME(p_r,"p_r");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_RunesToUTF8_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t13,"_t13");
	HX_VISIT_MEMBER_NAME(_SF2,"_SF2");
	HX_VISIT_MEMBER_NAME(_t11,"_t11");
	HX_VISIT_MEMBER_NAME(_t10,"_t10");
	HX_VISIT_MEMBER_NAME(_t9,"_t9");
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
	HX_VISIT_MEMBER_NAME(p_r,"p_r");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_RunesToUTF8_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { return _SF2; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
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

Dynamic Go_haxegoruntime_RunesToUTF8_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { _SF2=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_RunesToUTF8_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t13"));
	outFields->push(HX_CSTRING("_SF2"));
	outFields->push(HX_CSTRING("_t11"));
	outFields->push(HX_CSTRING("_t10"));
	outFields->push(HX_CSTRING("_t9"));
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
	HX_CSTRING("_t13"),
	HX_CSTRING("_SF2"),
	HX_CSTRING("_t11"),
	HX_CSTRING("_t10"),
	HX_CSTRING("_t9"),
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
	HX_CSTRING("p_r"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_RunesToUTF8_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_RunesToUTF8_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_RunesToUTF8_obj::__mClass;

void Go_haxegoruntime_RunesToUTF8_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_RunesToUTF8"), hx::TCanCast< Go_haxegoruntime_RunesToUTF8_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_RunesToUTF8_obj::__boot()
{
}

} // end namespace tardis
