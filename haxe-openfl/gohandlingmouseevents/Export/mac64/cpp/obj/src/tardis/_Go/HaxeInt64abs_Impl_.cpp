#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_tardis_Int64
#include <tardis/Int64.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis__Go_HaxeInt64abs_Impl_
#include <tardis/_Go/HaxeInt64abs_Impl_.h>
#endif
namespace tardis{
namespace _Go{

Void HaxeInt64abs_Impl__obj::__construct()
{
	return null();
}

HaxeInt64abs_Impl__obj::~HaxeInt64abs_Impl__obj() { }

Dynamic HaxeInt64abs_Impl__obj::__CreateEmpty() { return  new HaxeInt64abs_Impl__obj; }
hx::ObjectPtr< HaxeInt64abs_Impl__obj > HaxeInt64abs_Impl__obj::__new()
{  hx::ObjectPtr< HaxeInt64abs_Impl__obj > result = new HaxeInt64abs_Impl__obj();
	result->__construct();
	return result;}

Dynamic HaxeInt64abs_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HaxeInt64abs_Impl__obj > result = new HaxeInt64abs_Impl__obj();
	result->__construct();
	return result;}

::tardis::Int64 HaxeInt64abs_Impl__obj::_new( ::tardis::Int64 v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::_new","tardis/Go.hx",638);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(638)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,_new,return )

int HaxeInt64abs_Impl__obj::toInt( ::tardis::Int64 v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::toInt","tardis/Go.hx",640);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(640)
	return ::tardis::Int64_obj::getLow(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,toInt,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::ofInt( int v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::ofInt","tardis/Go.hx",647);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(647)
	return ::tardis::Int64_obj::__new((int(v) >> int((int)31)),v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,ofInt,return )

Float HaxeInt64abs_Impl__obj::toFloat( ::tardis::Int64 vp){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::toFloat","tardis/Go.hx",650);
	HX_STACK_ARG(vp,"vp");
	HX_STACK_LINE(652)
	::tardis::Int64 v = vp;		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(653)
	bool isNegVal = false;		HX_STACK_VAR(isNegVal,"isNegVal");
	HX_STACK_LINE(654)
	if (((v->high < (int)0))){
		struct _Function_2_1{
			inline static int Block( ::tardis::Int64 &v){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",655);
				{
					HX_STACK_LINE(655)
					::tardis::Int64 y = ::tardis::Int64_obj::__new((int)-2147483648,(int)0);		HX_STACK_VAR(y,"y");
					struct _Function_3_1{
						inline static int Block( ::tardis::Int64 &v,::tardis::Int64 &y){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",655);
							{
								HX_STACK_LINE(655)
								int v1 = (v->high - y->high);		HX_STACK_VAR(v1,"v1");
								HX_STACK_LINE(655)
								return (  (((v1 != (int)0))) ? int(v1) : int(::tardis::Int64_obj::uicompare(v->low,y->low)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(655)
					return _Function_3_1::Block(v,y);
				}
				return null();
			}
		};
		HX_STACK_LINE(655)
		if (((_Function_2_1::Block(v) == (int)0))){
			HX_STACK_LINE(655)
			return -9223372036854775808.0;
		}
		HX_STACK_LINE(656)
		isNegVal = true;
		struct _Function_2_2{
			inline static ::tardis::Int64 Block( ::tardis::Int64 &v){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",657);
				{
					HX_STACK_LINE(657)
					int high = ~(int)(v->high);		HX_STACK_VAR(high,"high");
					HX_STACK_LINE(657)
					int low = -(v->low);		HX_STACK_VAR(low,"low");
					HX_STACK_LINE(657)
					if (((low == (int)0))){
						HX_STACK_LINE(657)
						(high)++;
					}
					HX_STACK_LINE(657)
					return ::tardis::Int64_obj::__new(high,low);
				}
				return null();
			}
		};
		HX_STACK_LINE(657)
		v = _Function_2_2::Block(v);
	}
	HX_STACK_LINE(659)
	Float ret = 0.0;		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(660)
	Float multiplier = 1.0;		HX_STACK_VAR(multiplier,"multiplier");
	HX_STACK_LINE(661)
	::tardis::Int64 one = ::tardis::Int64_obj::__new((int)0,(int)1);		HX_STACK_VAR(one,"one");
	HX_STACK_LINE(662)
	{
		HX_STACK_LINE(662)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(662)
		while(((_g < (int)63))){
			HX_STACK_LINE(662)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			struct _Function_3_1{
				inline static bool Block( ::tardis::Int64 &v,::tardis::Int64 &one){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",663);
					{
						HX_STACK_LINE(663)
						::tardis::Int64 v1 = ::tardis::Int64_obj::__new((int(v->high) & int(one->high)),(int(v->low) & int(one->low)));		HX_STACK_VAR(v1,"v1");
						HX_STACK_LINE(663)
						return (((int(v1->high) | int(v1->low))) == (int)0);
					}
					return null();
				}
			};
			HX_STACK_LINE(663)
			if ((!(_Function_3_1::Block(v,one)))){
				HX_STACK_LINE(664)
				hx::AddEq(ret,multiplier);
			}
			HX_STACK_LINE(665)
			hx::MultEq(multiplier,2.0);
			HX_STACK_LINE(666)
			v = ::tardis::Int64_obj::__new(hx::UShr(v->high,(int)1),(int(hx::UShr(v->low,(int)1)) | int((int(v->high) << int((int)31)))));
		}
	}
	HX_STACK_LINE(668)
	if ((isNegVal)){
		HX_STACK_LINE(668)
		return -(ret);
	}
	HX_STACK_LINE(669)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,toFloat,return )

Float HaxeInt64abs_Impl__obj::toUFloat( ::tardis::Int64 vp){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::toUFloat","tardis/Go.hx",671);
	HX_STACK_ARG(vp,"vp");
	HX_STACK_LINE(673)
	::tardis::Int64 v = vp;		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(674)
	Float ret = 0.0;		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(675)
	Float multiplier = 1.0;		HX_STACK_VAR(multiplier,"multiplier");
	HX_STACK_LINE(676)
	::tardis::Int64 one = ::tardis::Int64_obj::__new((int)0,(int)1);		HX_STACK_VAR(one,"one");
	HX_STACK_LINE(677)
	{
		HX_STACK_LINE(677)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(677)
		while(((_g < (int)64))){
			HX_STACK_LINE(677)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			struct _Function_3_1{
				inline static bool Block( ::tardis::Int64 &v,::tardis::Int64 &one){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",678);
					{
						HX_STACK_LINE(678)
						::tardis::Int64 v1 = ::tardis::Int64_obj::__new((int(v->high) & int(one->high)),(int(v->low) & int(one->low)));		HX_STACK_VAR(v1,"v1");
						HX_STACK_LINE(678)
						return (((int(v1->high) | int(v1->low))) == (int)0);
					}
					return null();
				}
			};
			HX_STACK_LINE(678)
			if ((!(_Function_3_1::Block(v,one)))){
				HX_STACK_LINE(679)
				hx::AddEq(ret,multiplier);
			}
			HX_STACK_LINE(680)
			hx::MultEq(multiplier,2.0);
			HX_STACK_LINE(681)
			v = ::tardis::Int64_obj::__new(hx::UShr(v->high,(int)1),(int(hx::UShr(v->low,(int)1)) | int((int(v->high) << int((int)31)))));
		}
	}
	HX_STACK_LINE(683)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,toUFloat,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::ofFloat( Float v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::ofFloat","tardis/Go.hx",685);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(687)
	if (((v == 0.0))){
		HX_STACK_LINE(687)
		return ::tardis::Int64_obj::__new((int)0,(int)0);
	}
	HX_STACK_LINE(688)
	if ((::Math_obj::isNaN(v))){
		HX_STACK_LINE(688)
		return ::tardis::Int64_obj::__new((int)-2147483648,(int)0);
	}
	HX_STACK_LINE(689)
	bool isNegVal = false;		HX_STACK_VAR(isNegVal,"isNegVal");
	HX_STACK_LINE(690)
	if (((v < 0.0))){
		HX_STACK_LINE(691)
		isNegVal = true;
		HX_STACK_LINE(692)
		v = -(v);
	}
	HX_STACK_LINE(694)
	if (((v < 2147483647.0))){
		HX_STACK_LINE(694)
		if ((isNegVal)){
			struct _Function_3_1{
				inline static ::tardis::Int64 Block( Float &v){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",695);
					{
						struct _Function_4_1{
							inline static ::tardis::Int64 Block( Float &v){
								HX_STACK_PUSH("*::closure","tardis/Go.hx",695);
								{
									HX_STACK_LINE(695)
									int x = ::Math_obj::ceil(v);		HX_STACK_VAR(x,"x");
									HX_STACK_LINE(695)
									return ::tardis::Int64_obj::__new((int(x) >> int((int)31)),x);
								}
								return null();
							}
						};
						HX_STACK_LINE(695)
						::tardis::Int64 a = _Function_4_1::Block(v);		HX_STACK_VAR(a,"a");
						HX_STACK_LINE(695)
						int high = ~(int)(a->high);		HX_STACK_VAR(high,"high");
						HX_STACK_LINE(695)
						int low = -(a->low);		HX_STACK_VAR(low,"low");
						HX_STACK_LINE(695)
						if (((low == (int)0))){
							HX_STACK_LINE(695)
							(high)++;
						}
						HX_STACK_LINE(695)
						return ::tardis::Int64_obj::__new(high,low);
					}
					return null();
				}
			};
			HX_STACK_LINE(695)
			return _Function_3_1::Block(v);
		}
		else{
			struct _Function_3_1{
				inline static ::tardis::Int64 Block( Float &v){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",696);
					{
						HX_STACK_LINE(696)
						int x = ::Math_obj::floor(v);		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(696)
						return ::tardis::Int64_obj::__new((int(x) >> int((int)31)),x);
					}
					return null();
				}
			};
			HX_STACK_LINE(696)
			return _Function_3_1::Block(v);
		}
	}
	HX_STACK_LINE(698)
	if (((v > 9223372036854775807.0))){
		HX_STACK_LINE(698)
		if ((isNegVal)){
			HX_STACK_LINE(699)
			return ::tardis::Int64_obj::__new((int)-2147483648,(int)0);
		}
		else{
			HX_STACK_LINE(700)
			return ::tardis::Int64_obj::__new((int)2147483647,(int)-1);
		}
	}
	HX_STACK_LINE(702)
	Float f32 = 4294967296.0;		HX_STACK_VAR(f32,"f32");
	HX_STACK_LINE(703)
	Float f16 = 65536.0;		HX_STACK_VAR(f16,"f16");
	HX_STACK_LINE(704)
	int high = ::Math_obj::floor((Float(v) / Float(f32)));		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(705)
	Float lowFloat = ::Math_obj::ffloor((v - (high * f32)));		HX_STACK_VAR(lowFloat,"lowFloat");
	HX_STACK_LINE(706)
	int lowTop16 = ::Math_obj::floor((Float(lowFloat) / Float(f16)));		HX_STACK_VAR(lowTop16,"lowTop16");
	HX_STACK_LINE(707)
	int lowBot16 = ::Math_obj::floor((lowFloat - (lowTop16 * f16)));		HX_STACK_VAR(lowBot16,"lowBot16");
	HX_STACK_LINE(708)
	::tardis::Int64 res = ::tardis::Int64_obj::__new(high,lowBot16);		HX_STACK_VAR(res,"res");
	struct _Function_1_1{
		inline static ::tardis::Int64 Block( ::tardis::Int64 &res,int &lowTop16){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",709);
			{
				struct _Function_2_1{
					inline static ::tardis::Int64 Block( int &lowTop16){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",709);
						{
							HX_STACK_LINE(709)
							int a_high = (int)0;		HX_STACK_VAR(a_high,"a_high");
							int a_low = lowTop16;		HX_STACK_VAR(a_low,"a_low");
							HX_STACK_LINE(709)
							return ::tardis::Int64_obj::__new((int((int(a_high) << int((int)16))) | int(hx::UShr(a_low,(int)16))),(int(a_low) << int((int)16)));
						}
						return null();
					}
				};
				HX_STACK_LINE(709)
				::tardis::Int64 b = _Function_2_1::Block(lowTop16);		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(709)
				return ::tardis::Int64_obj::__new((int(res->high) | int(b->high)),(int(res->low) | int(b->low)));
			}
			return null();
		}
	};
	HX_STACK_LINE(709)
	res = _Function_1_1::Block(res,lowTop16);
	HX_STACK_LINE(710)
	if ((isNegVal)){
		struct _Function_2_1{
			inline static ::tardis::Int64 Block( ::tardis::Int64 &res){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",710);
				{
					HX_STACK_LINE(710)
					int high1 = ~(int)(res->high);		HX_STACK_VAR(high1,"high1");
					HX_STACK_LINE(710)
					int low = -(res->low);		HX_STACK_VAR(low,"low");
					HX_STACK_LINE(710)
					if (((low == (int)0))){
						HX_STACK_LINE(710)
						(high1)++;
					}
					HX_STACK_LINE(710)
					return ::tardis::Int64_obj::__new(high1,low);
				}
				return null();
			}
		};
		HX_STACK_LINE(710)
		return _Function_2_1::Block(res);
	}
	HX_STACK_LINE(711)
	return res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,ofFloat,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::ofUFloat( Float v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::ofUFloat","tardis/Go.hx",713);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(715)
	if (((v <= 0.0))){
		HX_STACK_LINE(715)
		return ::tardis::Int64_obj::__new((int)0,(int)0);
	}
	HX_STACK_LINE(716)
	if ((::Math_obj::isNaN(v))){
		HX_STACK_LINE(716)
		return ::tardis::Int64_obj::__new((int)-2147483648,(int)0);
	}
	HX_STACK_LINE(717)
	if (((v < 2147483647.0))){
		struct _Function_2_1{
			inline static ::tardis::Int64 Block( Float &v){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",718);
				{
					HX_STACK_LINE(718)
					int v1 = ::Math_obj::floor(v);		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(718)
					return ::tardis::Int64_obj::__new((int(v1) >> int((int)31)),v1);
				}
				return null();
			}
		};
		HX_STACK_LINE(717)
		return _Function_2_1::Block(v);
	}
	HX_STACK_LINE(720)
	if (((v > 18446744073709551615.0))){
		HX_STACK_LINE(720)
		return ::tardis::Int64_obj::__new((int)-1,(int)-1);
	}
	HX_STACK_LINE(723)
	Float f32 = 4294967296.0;		HX_STACK_VAR(f32,"f32");
	HX_STACK_LINE(724)
	Float f16 = 65536.0;		HX_STACK_VAR(f16,"f16");
	HX_STACK_LINE(725)
	int high = ::Math_obj::floor((Float(v) / Float(f32)));		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(726)
	Float lowFloat = ::Math_obj::ffloor((v - (high * f32)));		HX_STACK_VAR(lowFloat,"lowFloat");
	HX_STACK_LINE(727)
	int lowTop16 = ::Math_obj::floor((Float(lowFloat) / Float(f16)));		HX_STACK_VAR(lowTop16,"lowTop16");
	HX_STACK_LINE(728)
	int lowBot16 = ::Math_obj::floor((lowFloat - (lowTop16 * f16)));		HX_STACK_VAR(lowBot16,"lowBot16");
	HX_STACK_LINE(729)
	::tardis::Int64 res = ::tardis::Int64_obj::__new(high,lowBot16);		HX_STACK_VAR(res,"res");
	struct _Function_1_1{
		inline static ::tardis::Int64 Block( ::tardis::Int64 &res,int &lowTop16){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",730);
			{
				struct _Function_2_1{
					inline static ::tardis::Int64 Block( int &lowTop16){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",730);
						{
							HX_STACK_LINE(730)
							int a_high = (int)0;		HX_STACK_VAR(a_high,"a_high");
							int a_low = lowTop16;		HX_STACK_VAR(a_low,"a_low");
							HX_STACK_LINE(730)
							return ::tardis::Int64_obj::__new((int((int(a_high) << int((int)16))) | int(hx::UShr(a_low,(int)16))),(int(a_low) << int((int)16)));
						}
						return null();
					}
				};
				HX_STACK_LINE(730)
				::tardis::Int64 b = _Function_2_1::Block(lowTop16);		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(730)
				return ::tardis::Int64_obj::__new((int(res->high) | int(b->high)),(int(res->low) | int(b->low)));
			}
			return null();
		}
	};
	HX_STACK_LINE(730)
	res = _Function_1_1::Block(res,lowTop16);
	HX_STACK_LINE(731)
	return res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,ofUFloat,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::make( int h,int l){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::make","tardis/Go.hx",733);
	HX_STACK_ARG(h,"h");
	HX_STACK_ARG(l,"l");
	HX_STACK_LINE(733)
	return ::tardis::Int64_obj::__new(h,l);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,make,return )

::String HaxeInt64abs_Impl__obj::toString( ::tardis::Int64 v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::toString","tardis/Go.hx",736);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(736)
	return v->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,toString,return )

::String HaxeInt64abs_Impl__obj::toStr( ::tardis::Int64 v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::toStr","tardis/Go.hx",739);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(739)
	return v->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,toStr,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::neg( ::tardis::Int64 v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::neg","tardis/Go.hx",742);
	HX_STACK_ARG(v,"v");
	struct _Function_1_1{
		inline static ::tardis::Int64 Block( ::tardis::Int64 &v){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",743);
			{
				HX_STACK_LINE(743)
				int high = ~(int)(v->high);		HX_STACK_VAR(high,"high");
				HX_STACK_LINE(743)
				int low = -(v->low);		HX_STACK_VAR(low,"low");
				HX_STACK_LINE(743)
				if (((low == (int)0))){
					HX_STACK_LINE(743)
					(high)++;
				}
				HX_STACK_LINE(743)
				return ::tardis::Int64_obj::__new(high,low);
			}
			return null();
		}
	};
	HX_STACK_LINE(742)
	return _Function_1_1::Block(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,neg,return )

bool HaxeInt64abs_Impl__obj::isZero( ::tardis::Int64 v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::isZero","tardis/Go.hx",745);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(745)
	return (((int(v->high) | int(v->low))) == (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,isZero,return )

bool HaxeInt64abs_Impl__obj::isNeg( ::tardis::Int64 v){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::isNeg","tardis/Go.hx",748);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(748)
	return (v->high < (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeInt64abs_Impl__obj,isNeg,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::add( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::add","tardis/Go.hx",751);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(751)
	return ::tardis::Int64_obj::add(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,add,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::_and( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::and","tardis/Go.hx",754);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(754)
	return ::tardis::Int64_obj::__new((int(x->high) & int(y->high)),(int(x->low) & int(y->low)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,_and,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::checkDiv( ::tardis::Int64 x,::tardis::Int64 y,bool isSigned){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::checkDiv","tardis/Go.hx",757);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(isSigned,"isSigned");
	HX_STACK_LINE(758)
	if (((((int(y->high) | int(y->low))) == (int)0))){
		HX_STACK_LINE(759)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("attempt to divide 64-bit value by 0"));
	}
	struct _Function_1_1{
		inline static int Block( ::tardis::Int64 &y){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",760);
			{
				HX_STACK_LINE(760)
				int b_high = (int)-1;		HX_STACK_VAR(b_high,"b_high");
				int b_low = (int)-1;		HX_STACK_VAR(b_low,"b_low");
				HX_STACK_LINE(760)
				int v = (y->high - b_high);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(760)
				return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(y->low,b_low)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static int Block( ::tardis::Int64 &x){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",760);
			{
				HX_STACK_LINE(760)
				int b_high = (int)-2147483648;		HX_STACK_VAR(b_high,"b_high");
				int b_low = (int)0;		HX_STACK_VAR(b_low,"b_low");
				HX_STACK_LINE(760)
				int v = (x->high - b_high);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(760)
				return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(x->low,b_low)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(760)
	if (((bool((bool(isSigned) && bool((_Function_1_1::Block(y) == (int)0)))) && bool((_Function_1_2::Block(x) == (int)0))))){
		HX_STACK_LINE(761)
		y = ::tardis::Int64_obj::__new((int)0,(int)1);
	}
	HX_STACK_LINE(765)
	return y;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(HaxeInt64abs_Impl__obj,checkDiv,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::div( ::tardis::Int64 x,::tardis::Int64 y,bool isSigned){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::div","tardis/Go.hx",767);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(isSigned,"isSigned");
	HX_STACK_LINE(768)
	y = ::tardis::_Go::HaxeInt64abs_Impl__obj::checkDiv(x,y,isSigned);
	struct _Function_1_1{
		inline static int Block( ::tardis::Int64 &y){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",769);
			{
				HX_STACK_LINE(769)
				int b_high = (int)0;		HX_STACK_VAR(b_high,"b_high");
				int b_low = (int)1;		HX_STACK_VAR(b_low,"b_low");
				HX_STACK_LINE(769)
				int v = (y->high - b_high);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(769)
				return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(y->low,b_low)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(769)
	if (((_Function_1_1::Block(y) == (int)0))){
		HX_STACK_LINE(769)
		return x;
	}
	HX_STACK_LINE(770)
	return ::tardis::Int64_obj::div(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(HaxeInt64abs_Impl__obj,div,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::mod( ::tardis::Int64 x,::tardis::Int64 y,bool isSigned){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::mod","tardis/Go.hx",772);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(isSigned,"isSigned");
	HX_STACK_LINE(773)
	y = ::tardis::_Go::HaxeInt64abs_Impl__obj::checkDiv(x,y,isSigned);
	struct _Function_1_1{
		inline static int Block( ::tardis::Int64 &y){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",774);
			{
				HX_STACK_LINE(774)
				int b_high = (int)0;		HX_STACK_VAR(b_high,"b_high");
				int b_low = (int)1;		HX_STACK_VAR(b_low,"b_low");
				HX_STACK_LINE(774)
				int v = (y->high - b_high);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(774)
				return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(y->low,b_low)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(774)
	if (((_Function_1_1::Block(y) == (int)0))){
		HX_STACK_LINE(774)
		return ::tardis::Int64_obj::__new((int)0,(int)0);
	}
	HX_STACK_LINE(775)
	return ::tardis::Int64_obj::mod(x,::tardis::_Go::HaxeInt64abs_Impl__obj::checkDiv(x,y,isSigned));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(HaxeInt64abs_Impl__obj,mod,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::mul( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::mul","tardis/Go.hx",777);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(777)
	return ::tardis::Int64_obj::mul(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,mul,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::_or( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::or","tardis/Go.hx",780);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(780)
	return ::tardis::Int64_obj::__new((int(x->high) | int(y->high)),(int(x->low) | int(y->low)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,_or,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::shl( ::tardis::Int64 x,int y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::shl","tardis/Go.hx",783);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(783)
	return (  (((((int(y) & int((int)63))) == (int)0))) ? ::tardis::Int64(x) : ::tardis::Int64((  (((((int(y) & int((int)63))) < (int)32))) ? ::tardis::Int64(::tardis::Int64_obj::__new((int((int(x->high) << int(y))) | int(hx::UShr(x->low,((int)32 - ((int(y) & int((int)63))))))),(int(x->low) << int(y)))) : ::tardis::Int64(::tardis::Int64_obj::__new((int(x->low) << int((y - (int)32))),(int)0)) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,shl,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::ushr( ::tardis::Int64 x,int y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::ushr","tardis/Go.hx",786);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(786)
	return (  (((((int(y) & int((int)63))) == (int)0))) ? ::tardis::Int64(x) : ::tardis::Int64((  (((((int(y) & int((int)63))) < (int)32))) ? ::tardis::Int64(::tardis::Int64_obj::__new(hx::UShr(x->high,y),(int(hx::UShr(x->low,y)) | int((int(x->high) << int(((int)32 - ((int(y) & int((int)63)))))))))) : ::tardis::Int64(::tardis::Int64_obj::__new((int)0,hx::UShr(x->high,(y - (int)32)))) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,ushr,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::sub( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::sub","tardis/Go.hx",789);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(789)
	return ::tardis::Int64_obj::sub(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,sub,return )

::tardis::Int64 HaxeInt64abs_Impl__obj::_xor( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::xor","tardis/Go.hx",792);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(792)
	return ::tardis::Int64_obj::__new((int(x->high) ^ int(y->high)),(int(x->low) ^ int(y->low)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,_xor,return )

int HaxeInt64abs_Impl__obj::compare( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::compare","tardis/Go.hx",795);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	struct _Function_1_1{
		inline static int Block( ::tardis::Int64 &x,::tardis::Int64 &y){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",796);
			{
				HX_STACK_LINE(796)
				int v = (x->high - y->high);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(796)
				return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(x->low,y->low)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(795)
	return _Function_1_1::Block(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,compare,return )

int HaxeInt64abs_Impl__obj::ucompare( ::tardis::Int64 x,::tardis::Int64 y){
	HX_STACK_PUSH("HaxeInt64abs_Impl_::ucompare","tardis/Go.hx",798);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	struct _Function_1_1{
		inline static int Block( ::tardis::Int64 &x,::tardis::Int64 &y){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",825);
			{
				HX_STACK_LINE(825)
				int v = ::tardis::Int64_obj::uicompare(x->high,y->high);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(825)
				return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(x->low,y->low)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(798)
	return _Function_1_1::Block(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeInt64abs_Impl__obj,ucompare,return )


HaxeInt64abs_Impl__obj::HaxeInt64abs_Impl__obj()
{
}

void HaxeInt64abs_Impl__obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HaxeInt64abs_Impl_);
	HX_MARK_END_CLASS();
}

void HaxeInt64abs_Impl__obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic HaxeInt64abs_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"or") ) { return _or_dyn(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"neg") ) { return neg_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"and") ) { return _and_dyn(); }
		if (HX_FIELD_EQ(inName,"div") ) { return div_dyn(); }
		if (HX_FIELD_EQ(inName,"mod") ) { return mod_dyn(); }
		if (HX_FIELD_EQ(inName,"mul") ) { return mul_dyn(); }
		if (HX_FIELD_EQ(inName,"shl") ) { return shl_dyn(); }
		if (HX_FIELD_EQ(inName,"sub") ) { return sub_dyn(); }
		if (HX_FIELD_EQ(inName,"xor") ) { return _xor_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"make") ) { return make_dyn(); }
		if (HX_FIELD_EQ(inName,"ushr") ) { return ushr_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"toInt") ) { return toInt_dyn(); }
		if (HX_FIELD_EQ(inName,"ofInt") ) { return ofInt_dyn(); }
		if (HX_FIELD_EQ(inName,"toStr") ) { return toStr_dyn(); }
		if (HX_FIELD_EQ(inName,"isNeg") ) { return isNeg_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isZero") ) { return isZero_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"toFloat") ) { return toFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"ofFloat") ) { return ofFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"compare") ) { return compare_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toUFloat") ) { return toUFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"ofUFloat") ) { return ofUFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"checkDiv") ) { return checkDiv_dyn(); }
		if (HX_FIELD_EQ(inName,"ucompare") ) { return ucompare_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HaxeInt64abs_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void HaxeInt64abs_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_new"),
	HX_CSTRING("toInt"),
	HX_CSTRING("ofInt"),
	HX_CSTRING("toFloat"),
	HX_CSTRING("toUFloat"),
	HX_CSTRING("ofFloat"),
	HX_CSTRING("ofUFloat"),
	HX_CSTRING("make"),
	HX_CSTRING("toString"),
	HX_CSTRING("toStr"),
	HX_CSTRING("neg"),
	HX_CSTRING("isZero"),
	HX_CSTRING("isNeg"),
	HX_CSTRING("add"),
	HX_CSTRING("and"),
	HX_CSTRING("checkDiv"),
	HX_CSTRING("div"),
	HX_CSTRING("mod"),
	HX_CSTRING("mul"),
	HX_CSTRING("or"),
	HX_CSTRING("shl"),
	HX_CSTRING("ushr"),
	HX_CSTRING("sub"),
	HX_CSTRING("xor"),
	HX_CSTRING("compare"),
	HX_CSTRING("ucompare"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HaxeInt64abs_Impl__obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HaxeInt64abs_Impl__obj::__mClass,"__mClass");
};

Class HaxeInt64abs_Impl__obj::__mClass;

void HaxeInt64abs_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.HaxeInt64abs_Impl_"), hx::TCanCast< HaxeInt64abs_Impl__obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HaxeInt64abs_Impl__obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
