#include <hxcpp.h>

#ifndef INCLUDED_tardis_Int64
#include <tardis/Int64.h>
#endif
namespace tardis{

Void Int64_obj::__construct(int high,int low)
{
HX_STACK_PUSH("Int64::new","tardis/Go.hx",954);
{
	HX_STACK_LINE(955)
	this->high = high;
	HX_STACK_LINE(956)
	this->low = low;
}
;
	return null();
}

Int64_obj::~Int64_obj() { }

Dynamic Int64_obj::__CreateEmpty() { return  new Int64_obj; }
hx::ObjectPtr< Int64_obj > Int64_obj::__new(int high,int low)
{  hx::ObjectPtr< Int64_obj > result = new Int64_obj();
	result->__construct(high,low);
	return result;}

Dynamic Int64_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Int64_obj > result = new Int64_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String Int64_obj::toString( ){
	HX_STACK_PUSH("Int64::toString","tardis/Go.hx",1005);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1006)
	if (((((int(this->high) | int(this->low))) == (int)0))){
		HX_STACK_LINE(1007)
		return HX_CSTRING("0");
	}
	HX_STACK_LINE(1008)
	::String str = HX_CSTRING("");		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(1009)
	bool neg = false;		HX_STACK_VAR(neg,"neg");
	HX_STACK_LINE(1010)
	::tardis::Int64 i = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1011)
	if (((i->high < (int)0))){
		HX_STACK_LINE(1012)
		neg = true;
		struct _Function_2_1{
			inline static ::tardis::Int64 Block( ::tardis::Int64 &i){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1013);
				{
					HX_STACK_LINE(1013)
					int high = ~(int)(i->high);		HX_STACK_VAR(high,"high");
					HX_STACK_LINE(1013)
					int low = -(i->low);		HX_STACK_VAR(low,"low");
					HX_STACK_LINE(1013)
					if (((low == (int)0))){
						HX_STACK_LINE(1013)
						(high)++;
					}
					HX_STACK_LINE(1013)
					return ::tardis::Int64_obj::__new(high,low);
				}
				return null();
			}
		};
		HX_STACK_LINE(1013)
		i = _Function_2_1::Block(i);
	}
	HX_STACK_LINE(1015)
	::tardis::Int64 ten = ::tardis::Int64_obj::__new((int)0,(int)10);		HX_STACK_VAR(ten,"ten");
	HX_STACK_LINE(1016)
	while((!(((((int(i->high) | int(i->low))) == (int)0))))){
		HX_STACK_LINE(1017)
		Dynamic r = ::tardis::Int64_obj::divMod(i,ten);		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(1018)
		str = (r->__Field(HX_CSTRING("modulus"),true)->__Field(HX_CSTRING("low"),true) + str);
		HX_STACK_LINE(1019)
		i = r->__Field(HX_CSTRING("quotient"),true);
	}
	HX_STACK_LINE(1021)
	if ((neg)){
		HX_STACK_LINE(1021)
		str = (HX_CSTRING("-") + str);
	}
	HX_STACK_LINE(1022)
	return str;
}


HX_DEFINE_DYNAMIC_FUNC0(Int64_obj,toString,return )

int Int64_obj::ushr32( int v,int n){
	HX_STACK_PUSH("Int64::ushr32","tardis/Go.hx",976);
	HX_STACK_ARG(v,"v");
	HX_STACK_ARG(n,"n");
	HX_STACK_LINE(976)
	return hx::UShr(v,n);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,ushr32,return )

::tardis::Int64 Int64_obj::make( int high,int low){
	HX_STACK_PUSH("Int64::make","tardis/Go.hx",1025);
	HX_STACK_ARG(high,"high");
	HX_STACK_ARG(low,"low");
	HX_STACK_LINE(1025)
	return ::tardis::Int64_obj::__new(high,low);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,make,return )

::tardis::Int64 Int64_obj::ofInt( int x){
	HX_STACK_PUSH("Int64::ofInt","tardis/Go.hx",1029);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(1029)
	return ::tardis::Int64_obj::__new((int(x) >> int((int)31)),x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,ofInt,return )

int Int64_obj::toInt( ::tardis::Int64 x){
	HX_STACK_PUSH("Int64::toInt","tardis/Go.hx",1033);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(1034)
	if (((x->high != (int)0))){
		HX_STACK_LINE(1035)
		if (((x->high < (int)0))){
			struct _Function_3_1{
				inline static ::tardis::Int64 Block( ::tardis::Int64 &x){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",1036);
					{
						HX_STACK_LINE(1036)
						int high = ~(int)(x->high);		HX_STACK_VAR(high,"high");
						HX_STACK_LINE(1036)
						int low = -(x->low);		HX_STACK_VAR(low,"low");
						HX_STACK_LINE(1036)
						if (((low == (int)0))){
							HX_STACK_LINE(1036)
							(high)++;
						}
						HX_STACK_LINE(1036)
						return ::tardis::Int64_obj::__new(high,low);
					}
					return null();
				}
			};
			HX_STACK_LINE(1036)
			return -(::tardis::Int64_obj::toInt(_Function_3_1::Block(x)));
		}
		HX_STACK_LINE(1037)
		hx::Throw (HX_CSTRING("Overflow"));
	}
	HX_STACK_LINE(1039)
	return x->low;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,toInt,return )

int Int64_obj::getLow( ::tardis::Int64 x){
	HX_STACK_PUSH("Int64::getLow","tardis/Go.hx",1042);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(1042)
	return x->low;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,getLow,return )

int Int64_obj::getHigh( ::tardis::Int64 x){
	HX_STACK_PUSH("Int64::getHigh","tardis/Go.hx",1046);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(1046)
	return x->high;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,getHigh,return )

::tardis::Int64 Int64_obj::add( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::add","tardis/Go.hx",1050);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1051)
	int high = (a->high + b->high);		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(1052)
	int low = (a->low + b->low);		HX_STACK_VAR(low,"low");
	HX_STACK_LINE(1053)
	if (((::tardis::Int64_obj::uicompare(low,a->low) < (int)0))){
		HX_STACK_LINE(1054)
		(high)++;
	}
	HX_STACK_LINE(1055)
	return ::tardis::Int64_obj::__new(high,low);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,add,return )

::tardis::Int64 Int64_obj::sub( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::sub","tardis/Go.hx",1058);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1059)
	int high = (a->high - b->high);		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(1060)
	int low = (a->low - b->low);		HX_STACK_VAR(low,"low");
	HX_STACK_LINE(1061)
	if (((::tardis::Int64_obj::uicompare(a->low,b->low) < (int)0))){
		HX_STACK_LINE(1062)
		(high)--;
	}
	HX_STACK_LINE(1063)
	return ::tardis::Int64_obj::__new(high,low);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,sub,return )

::tardis::Int64 Int64_obj::mul( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::mul","tardis/Go.hx",1066);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1067)
	int mask = (int)65535;		HX_STACK_VAR(mask,"mask");
	HX_STACK_LINE(1068)
	int al = (int(a->low) & int(mask));		HX_STACK_VAR(al,"al");
	int ah = hx::UShr(a->low,(int)16);		HX_STACK_VAR(ah,"ah");
	HX_STACK_LINE(1069)
	int bl = (int(b->low) & int(mask));		HX_STACK_VAR(bl,"bl");
	int bh = hx::UShr(b->low,(int)16);		HX_STACK_VAR(bh,"bh");
	HX_STACK_LINE(1070)
	int p00 = (al * bl);		HX_STACK_VAR(p00,"p00");
	HX_STACK_LINE(1071)
	int p10 = (ah * bl);		HX_STACK_VAR(p10,"p10");
	HX_STACK_LINE(1072)
	int p01 = (al * bh);		HX_STACK_VAR(p01,"p01");
	HX_STACK_LINE(1073)
	int p11 = (ah * bh);		HX_STACK_VAR(p11,"p11");
	HX_STACK_LINE(1074)
	int low = p00;		HX_STACK_VAR(low,"low");
	HX_STACK_LINE(1075)
	int high = ((p11 + (hx::UShr(p01,(int)16))) + (hx::UShr(p10,(int)16)));		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(1076)
	p01 = (int(p01) << int((int)16));
	HX_STACK_LINE(1076)
	low = (low + p01);
	HX_STACK_LINE(1076)
	if (((::tardis::Int64_obj::uicompare(low,p01) < (int)0))){
		HX_STACK_LINE(1076)
		high = (high + (int)1);
	}
	HX_STACK_LINE(1077)
	p10 = (int(p10) << int((int)16));
	HX_STACK_LINE(1077)
	low = (low + p10);
	HX_STACK_LINE(1077)
	if (((::tardis::Int64_obj::uicompare(low,p10) < (int)0))){
		HX_STACK_LINE(1077)
		high = (high + (int)1);
	}
	HX_STACK_LINE(1078)
	high = (high + (a->low * b->high));
	HX_STACK_LINE(1079)
	high = (high + (a->high * b->low));
	HX_STACK_LINE(1080)
	return ::tardis::Int64_obj::__new(high,low);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,mul,return )

Dynamic Int64_obj::divMod( ::tardis::Int64 modulus,::tardis::Int64 divisor){
	HX_STACK_PUSH("Int64::divMod","tardis/Go.hx",1083);
	HX_STACK_ARG(modulus,"modulus");
	HX_STACK_ARG(divisor,"divisor");
	HX_STACK_LINE(1084)
	::tardis::Int64 quotient = ::tardis::Int64_obj::__new((int)0,(int)0);		HX_STACK_VAR(quotient,"quotient");
	HX_STACK_LINE(1085)
	int mask_high = (int)0;		HX_STACK_VAR(mask_high,"mask_high");
	int mask_low = (int)1;		HX_STACK_VAR(mask_low,"mask_low");
	HX_STACK_LINE(1086)
	divisor = ::tardis::Int64_obj::__new(divisor->high,divisor->low);
	HX_STACK_LINE(1087)
	while(((divisor->high >= (int)0))){
		struct _Function_2_1{
			inline static int Block( ::tardis::Int64 &divisor,::tardis::Int64 &modulus){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1088);
				{
					HX_STACK_LINE(1088)
					int v = ::tardis::Int64_obj::uicompare(divisor->high,modulus->high);		HX_STACK_VAR(v,"v");
					HX_STACK_LINE(1088)
					return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(divisor->low,modulus->low)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1088)
		int cmp = _Function_2_1::Block(divisor,modulus);		HX_STACK_VAR(cmp,"cmp");
		HX_STACK_LINE(1089)
		divisor->high = (int((int(divisor->high) << int((int)1))) | int(hx::UShr(divisor->low,(int)31)));
		HX_STACK_LINE(1090)
		divisor->low = (int(divisor->low) << int((int)1));
		HX_STACK_LINE(1091)
		mask_high = (int((int(mask_high) << int((int)1))) | int(hx::UShr(mask_low,(int)31)));
		HX_STACK_LINE(1092)
		mask_low = (int(mask_low) << int((int)1));
		HX_STACK_LINE(1093)
		if (((cmp >= (int)0))){
			HX_STACK_LINE(1093)
			break;
		}
	}
	HX_STACK_LINE(1095)
	while(((((int(mask_low) | int(mask_high))) != (int)0))){
		struct _Function_2_1{
			inline static int Block( ::tardis::Int64 &divisor,::tardis::Int64 &modulus){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1096);
				{
					HX_STACK_LINE(1096)
					int v = ::tardis::Int64_obj::uicompare(modulus->high,divisor->high);		HX_STACK_VAR(v,"v");
					HX_STACK_LINE(1096)
					return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(modulus->low,divisor->low)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1096)
		if (((_Function_2_1::Block(divisor,modulus) >= (int)0))){
			HX_STACK_LINE(1097)
			quotient->high = (int(quotient->high) | int(mask_high));
			HX_STACK_LINE(1098)
			quotient->low = (int(quotient->low) | int(mask_low));
			HX_STACK_LINE(1099)
			modulus = ::tardis::Int64_obj::sub(modulus,divisor);
		}
		HX_STACK_LINE(1101)
		mask_low = (int(hx::UShr(mask_low,(int)1)) | int((int(mask_high) << int((int)31))));
		HX_STACK_LINE(1102)
		mask_high = hx::UShr(mask_high,(int)1);
		HX_STACK_LINE(1104)
		divisor->low = (int(hx::UShr(divisor->low,(int)1)) | int((int(divisor->high) << int((int)31))));
		HX_STACK_LINE(1105)
		divisor->high = hx::UShr(divisor->high,(int)1);
	}
	struct _Function_1_1{
		inline static Dynamic Block( ::tardis::Int64 &quotient,::tardis::Int64 &modulus){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",1107);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("quotient") , quotient,false);
				__result->Add(HX_CSTRING("modulus") , modulus,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1107)
	return _Function_1_1::Block(quotient,modulus);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,divMod,return )

::tardis::Int64 Int64_obj::div( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::div","tardis/Go.hx",1110);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1111)
	if (((b->high == (int)0))){
		HX_STACK_LINE(1112)
		switch( (int)(b->low)){
			case (int)0: {
				HX_STACK_LINE(1113)
				hx::Throw (HX_CSTRING("divide by zero"));
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(1114)
				return ::tardis::Int64_obj::__new(a->high,a->low);
			}
			;break;
		}
	}
	HX_STACK_LINE(1116)
	bool sign = (bool(((bool((a->high < (int)0)) || bool((b->high < (int)0))))) && bool(!(((bool((a->high < (int)0)) && bool((b->high < (int)0)))))));		HX_STACK_VAR(sign,"sign");
	HX_STACK_LINE(1117)
	if (((a->high < (int)0))){
		struct _Function_2_1{
			inline static ::tardis::Int64 Block( ::tardis::Int64 &a){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1117);
				{
					HX_STACK_LINE(1117)
					int high = ~(int)(a->high);		HX_STACK_VAR(high,"high");
					HX_STACK_LINE(1117)
					int low = -(a->low);		HX_STACK_VAR(low,"low");
					HX_STACK_LINE(1117)
					if (((low == (int)0))){
						HX_STACK_LINE(1117)
						(high)++;
					}
					HX_STACK_LINE(1117)
					return ::tardis::Int64_obj::__new(high,low);
				}
				return null();
			}
		};
		HX_STACK_LINE(1117)
		a = _Function_2_1::Block(a);
	}
	HX_STACK_LINE(1118)
	if (((b->high < (int)0))){
		struct _Function_2_1{
			inline static ::tardis::Int64 Block( ::tardis::Int64 &b){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1118);
				{
					HX_STACK_LINE(1118)
					int high = ~(int)(b->high);		HX_STACK_VAR(high,"high");
					HX_STACK_LINE(1118)
					int low = -(b->low);		HX_STACK_VAR(low,"low");
					HX_STACK_LINE(1118)
					if (((low == (int)0))){
						HX_STACK_LINE(1118)
						(high)++;
					}
					HX_STACK_LINE(1118)
					return ::tardis::Int64_obj::__new(high,low);
				}
				return null();
			}
		};
		HX_STACK_LINE(1118)
		b = _Function_2_1::Block(b);
	}
	HX_STACK_LINE(1119)
	::tardis::Int64 q = ::tardis::Int64_obj::divMod(a,b)->__Field(HX_CSTRING("quotient"),true);		HX_STACK_VAR(q,"q");
	struct _Function_1_1{
		inline static ::tardis::Int64 Block( ::tardis::Int64 &q){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",1120);
			{
				HX_STACK_LINE(1120)
				int high = ~(int)(q->high);		HX_STACK_VAR(high,"high");
				HX_STACK_LINE(1120)
				int low = -(q->low);		HX_STACK_VAR(low,"low");
				HX_STACK_LINE(1120)
				if (((low == (int)0))){
					HX_STACK_LINE(1120)
					(high)++;
				}
				HX_STACK_LINE(1120)
				return ::tardis::Int64_obj::__new(high,low);
			}
			return null();
		}
	};
	HX_STACK_LINE(1120)
	return (  ((sign)) ? ::tardis::Int64(_Function_1_1::Block(q)) : ::tardis::Int64(q) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,div,return )

::tardis::Int64 Int64_obj::mod( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::mod","tardis/Go.hx",1123);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1124)
	if (((b->high == (int)0))){
		HX_STACK_LINE(1125)
		switch( (int)(b->low)){
			case (int)0: {
				HX_STACK_LINE(1126)
				hx::Throw (HX_CSTRING("modulus by zero"));
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(1127)
				return ::tardis::Int64_obj::__new((int)0,(int)0);
			}
			;break;
		}
	}
	HX_STACK_LINE(1129)
	bool sign = (a->high < (int)0);		HX_STACK_VAR(sign,"sign");
	HX_STACK_LINE(1130)
	if (((a->high < (int)0))){
		struct _Function_2_1{
			inline static ::tardis::Int64 Block( ::tardis::Int64 &a){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1130);
				{
					HX_STACK_LINE(1130)
					int high = ~(int)(a->high);		HX_STACK_VAR(high,"high");
					HX_STACK_LINE(1130)
					int low = -(a->low);		HX_STACK_VAR(low,"low");
					HX_STACK_LINE(1130)
					if (((low == (int)0))){
						HX_STACK_LINE(1130)
						(high)++;
					}
					HX_STACK_LINE(1130)
					return ::tardis::Int64_obj::__new(high,low);
				}
				return null();
			}
		};
		HX_STACK_LINE(1130)
		a = _Function_2_1::Block(a);
	}
	HX_STACK_LINE(1131)
	if (((b->high < (int)0))){
		struct _Function_2_1{
			inline static ::tardis::Int64 Block( ::tardis::Int64 &b){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1131);
				{
					HX_STACK_LINE(1131)
					int high = ~(int)(b->high);		HX_STACK_VAR(high,"high");
					HX_STACK_LINE(1131)
					int low = -(b->low);		HX_STACK_VAR(low,"low");
					HX_STACK_LINE(1131)
					if (((low == (int)0))){
						HX_STACK_LINE(1131)
						(high)++;
					}
					HX_STACK_LINE(1131)
					return ::tardis::Int64_obj::__new(high,low);
				}
				return null();
			}
		};
		HX_STACK_LINE(1131)
		b = _Function_2_1::Block(b);
	}
	HX_STACK_LINE(1132)
	::tardis::Int64 m = ::tardis::Int64_obj::divMod(a,b)->__Field(HX_CSTRING("modulus"),true);		HX_STACK_VAR(m,"m");
	struct _Function_1_1{
		inline static ::tardis::Int64 Block( ::tardis::Int64 &m){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",1133);
			{
				HX_STACK_LINE(1133)
				int high = ~(int)(m->high);		HX_STACK_VAR(high,"high");
				HX_STACK_LINE(1133)
				int low = -(m->low);		HX_STACK_VAR(low,"low");
				HX_STACK_LINE(1133)
				if (((low == (int)0))){
					HX_STACK_LINE(1133)
					(high)++;
				}
				HX_STACK_LINE(1133)
				return ::tardis::Int64_obj::__new(high,low);
			}
			return null();
		}
	};
	HX_STACK_LINE(1133)
	return (  ((sign)) ? ::tardis::Int64(_Function_1_1::Block(m)) : ::tardis::Int64(m) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,mod,return )

::tardis::Int64 Int64_obj::shl( ::tardis::Int64 a,int b){
	HX_STACK_PUSH("Int64::shl","tardis/Go.hx",1136);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1136)
	return (  (((((int(b) & int((int)63))) == (int)0))) ? ::tardis::Int64(a) : ::tardis::Int64((  (((((int(b) & int((int)63))) < (int)32))) ? ::tardis::Int64(::tardis::Int64_obj::__new((int((int(a->high) << int(b))) | int(hx::UShr(a->low,((int)32 - ((int(b) & int((int)63))))))),(int(a->low) << int(b)))) : ::tardis::Int64(::tardis::Int64_obj::__new((int(a->low) << int((b - (int)32))),(int)0)) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,shl,return )

::tardis::Int64 Int64_obj::shr( ::tardis::Int64 a,int b){
	HX_STACK_PUSH("Int64::shr","tardis/Go.hx",1140);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1140)
	return (  (((((int(b) & int((int)63))) == (int)0))) ? ::tardis::Int64(a) : ::tardis::Int64((  (((((int(b) & int((int)63))) < (int)32))) ? ::tardis::Int64(::tardis::Int64_obj::__new((int(a->high) >> int(b)),(int(hx::UShr(a->low,b)) | int((int(a->high) << int(((int)32 - ((int(b) & int((int)63)))))))))) : ::tardis::Int64(::tardis::Int64_obj::__new((int(a->high) >> int((int)31)),(int(a->high) >> int((b - (int)32))))) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,shr,return )

::tardis::Int64 Int64_obj::ushr( ::tardis::Int64 a,int b){
	HX_STACK_PUSH("Int64::ushr","tardis/Go.hx",1144);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1144)
	return (  (((((int(b) & int((int)63))) == (int)0))) ? ::tardis::Int64(a) : ::tardis::Int64((  (((((int(b) & int((int)63))) < (int)32))) ? ::tardis::Int64(::tardis::Int64_obj::__new(hx::UShr(a->high,b),(int(hx::UShr(a->low,b)) | int((int(a->high) << int(((int)32 - ((int(b) & int((int)63)))))))))) : ::tardis::Int64(::tardis::Int64_obj::__new((int)0,hx::UShr(a->high,(b - (int)32)))) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,ushr,return )

::tardis::Int64 Int64_obj::_and( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::and","tardis/Go.hx",1148);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1148)
	return ::tardis::Int64_obj::__new((int(a->high) & int(b->high)),(int(a->low) & int(b->low)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,_and,return )

::tardis::Int64 Int64_obj::_or( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::or","tardis/Go.hx",1152);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1152)
	return ::tardis::Int64_obj::__new((int(a->high) | int(b->high)),(int(a->low) | int(b->low)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,_or,return )

::tardis::Int64 Int64_obj::_xor( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::xor","tardis/Go.hx",1156);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1156)
	return ::tardis::Int64_obj::__new((int(a->high) ^ int(b->high)),(int(a->low) ^ int(b->low)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,_xor,return )

::tardis::Int64 Int64_obj::neg( ::tardis::Int64 a){
	HX_STACK_PUSH("Int64::neg","tardis/Go.hx",1160);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(1161)
	int high = ~(int)(a->high);		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(1162)
	int low = -(a->low);		HX_STACK_VAR(low,"low");
	HX_STACK_LINE(1163)
	if (((low == (int)0))){
		HX_STACK_LINE(1164)
		(high)++;
	}
	HX_STACK_LINE(1165)
	return ::tardis::Int64_obj::__new(high,low);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,neg,return )

bool Int64_obj::isNeg( ::tardis::Int64 a){
	HX_STACK_PUSH("Int64::isNeg","tardis/Go.hx",1168);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(1168)
	return (a->high < (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,isNeg,return )

bool Int64_obj::isZero( ::tardis::Int64 a){
	HX_STACK_PUSH("Int64::isZero","tardis/Go.hx",1172);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(1172)
	return (((int(a->high) | int(a->low))) == (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,isZero,return )

int Int64_obj::uicompare( int a,int b){
	HX_STACK_PUSH("Int64::uicompare","tardis/Go.hx",1176);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	struct _Function_1_1{
		inline static int Block( int &b,int &a){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",1177);
			{
				HX_STACK_LINE(1177)
				return (  (((b < (int)0))) ? int((~(int)(b) - ~(int)(a))) : int((int)1) );
			}
			return null();
		}
	};
	HX_STACK_LINE(1176)
	return (  (((a < (int)0))) ? int(_Function_1_1::Block(b,a)) : int((  (((b < (int)0))) ? int((int)-1) : int((a - b)) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,uicompare,return )

int Int64_obj::compare( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::compare","tardis/Go.hx",1180);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1181)
	int v = (a->high - b->high);		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(1182)
	return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(a->low,b->low)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,compare,return )

int Int64_obj::ucompare( ::tardis::Int64 a,::tardis::Int64 b){
	HX_STACK_PUSH("Int64::ucompare","tardis/Go.hx",1188);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(1189)
	int v = ::tardis::Int64_obj::uicompare(a->high,b->high);		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(1190)
	return (  (((v != (int)0))) ? int(v) : int(::tardis::Int64_obj::uicompare(a->low,b->low)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,ucompare,return )

::String Int64_obj::toStr( ::tardis::Int64 a){
	HX_STACK_PUSH("Int64::toStr","tardis/Go.hx",1193);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(1193)
	return a->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Int64_obj,toStr,return )


Int64_obj::Int64_obj()
{
}

void Int64_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Int64);
	HX_MARK_MEMBER_NAME(low,"low");
	HX_MARK_MEMBER_NAME(high,"high");
	HX_MARK_END_CLASS();
}

void Int64_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(low,"low");
	HX_VISIT_MEMBER_NAME(high,"high");
}

Dynamic Int64_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"or") ) { return _or_dyn(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"sub") ) { return sub_dyn(); }
		if (HX_FIELD_EQ(inName,"mul") ) { return mul_dyn(); }
		if (HX_FIELD_EQ(inName,"div") ) { return div_dyn(); }
		if (HX_FIELD_EQ(inName,"mod") ) { return mod_dyn(); }
		if (HX_FIELD_EQ(inName,"shl") ) { return shl_dyn(); }
		if (HX_FIELD_EQ(inName,"shr") ) { return shr_dyn(); }
		if (HX_FIELD_EQ(inName,"and") ) { return _and_dyn(); }
		if (HX_FIELD_EQ(inName,"xor") ) { return _xor_dyn(); }
		if (HX_FIELD_EQ(inName,"neg") ) { return neg_dyn(); }
		if (HX_FIELD_EQ(inName,"low") ) { return low; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"make") ) { return make_dyn(); }
		if (HX_FIELD_EQ(inName,"ushr") ) { return ushr_dyn(); }
		if (HX_FIELD_EQ(inName,"high") ) { return high; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ofInt") ) { return ofInt_dyn(); }
		if (HX_FIELD_EQ(inName,"toInt") ) { return toInt_dyn(); }
		if (HX_FIELD_EQ(inName,"isNeg") ) { return isNeg_dyn(); }
		if (HX_FIELD_EQ(inName,"toStr") ) { return toStr_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ushr32") ) { return ushr32_dyn(); }
		if (HX_FIELD_EQ(inName,"getLow") ) { return getLow_dyn(); }
		if (HX_FIELD_EQ(inName,"divMod") ) { return divMod_dyn(); }
		if (HX_FIELD_EQ(inName,"isZero") ) { return isZero_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getHigh") ) { return getHigh_dyn(); }
		if (HX_FIELD_EQ(inName,"compare") ) { return compare_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ucompare") ) { return ucompare_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"uicompare") ) { return uicompare_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Int64_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"low") ) { low=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"high") ) { high=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Int64_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("low"));
	outFields->push(HX_CSTRING("high"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ushr32"),
	HX_CSTRING("make"),
	HX_CSTRING("ofInt"),
	HX_CSTRING("toInt"),
	HX_CSTRING("getLow"),
	HX_CSTRING("getHigh"),
	HX_CSTRING("add"),
	HX_CSTRING("sub"),
	HX_CSTRING("mul"),
	HX_CSTRING("divMod"),
	HX_CSTRING("div"),
	HX_CSTRING("mod"),
	HX_CSTRING("shl"),
	HX_CSTRING("shr"),
	HX_CSTRING("ushr"),
	HX_CSTRING("and"),
	HX_CSTRING("or"),
	HX_CSTRING("xor"),
	HX_CSTRING("neg"),
	HX_CSTRING("isNeg"),
	HX_CSTRING("isZero"),
	HX_CSTRING("uicompare"),
	HX_CSTRING("compare"),
	HX_CSTRING("ucompare"),
	HX_CSTRING("toStr"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("low"),
	HX_CSTRING("high"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Int64_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Int64_obj::__mClass,"__mClass");
};

Class Int64_obj::__mClass;

void Int64_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Int64"), hx::TCanCast< Int64_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Int64_obj::__boot()
{
}

} // end namespace tardis
