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
#ifndef INCLUDED_tardis_Go_utf8_EncodeRune
#include <tardis/Go_utf8_EncodeRune.h>
#endif
#ifndef INCLUDED_tardis_Int64
#include <tardis/Int64.h>
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

Void Go_utf8_EncodeRune_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_p,int p_r)
{
HX_STACK_PUSH("Go_utf8_EncodeRune::new","tardis/Go.hx",1702);
{
	HX_STACK_LINE(1768)
	this->_Next = (int)0;
	HX_STACK_LINE(1767)
	this->_Phi = (int)0;
	HX_STACK_LINE(1766)
	this->_t52 = (int)0;
	HX_STACK_LINE(1765)
	this->_t51 = (int)0;
	HX_STACK_LINE(1764)
	this->_t50 = (int)0;
	HX_STACK_LINE(1763)
	this->_t49 = null();
	HX_STACK_LINE(1762)
	this->_t48 = (int)0;
	HX_STACK_LINE(1761)
	this->_t47 = (int)0;
	HX_STACK_LINE(1760)
	this->_t46 = (int)0;
	HX_STACK_LINE(1759)
	this->_t45 = (int)0;
	HX_STACK_LINE(1758)
	this->_t44 = null();
	HX_STACK_LINE(1757)
	this->_t43 = (int)0;
	HX_STACK_LINE(1756)
	this->_t42 = (int)0;
	HX_STACK_LINE(1755)
	this->_t41 = (int)0;
	HX_STACK_LINE(1754)
	this->_t40 = (int)0;
	HX_STACK_LINE(1753)
	this->_t39 = null();
	HX_STACK_LINE(1752)
	this->_t38 = (int)0;
	HX_STACK_LINE(1751)
	this->_t37 = (int)0;
	HX_STACK_LINE(1750)
	this->_t36 = (int)0;
	HX_STACK_LINE(1749)
	this->_t35 = null();
	HX_STACK_LINE(1748)
	this->_t34 = (int)0;
	HX_STACK_LINE(1747)
	this->_t33 = (int)0;
	HX_STACK_LINE(1746)
	this->_t32 = (int)0;
	HX_STACK_LINE(1745)
	this->_t31 = null();
	HX_STACK_LINE(1744)
	this->_t30 = (int)0;
	HX_STACK_LINE(1743)
	this->_t29 = (int)0;
	HX_STACK_LINE(1742)
	this->_t28 = (int)0;
	HX_STACK_LINE(1741)
	this->_t27 = (int)0;
	HX_STACK_LINE(1740)
	this->_t26 = null();
	HX_STACK_LINE(1739)
	this->_t25 = (int)0;
	HX_STACK_LINE(1738)
	this->_t24 = (int)0;
	HX_STACK_LINE(1737)
	this->_t23 = (int)0;
	HX_STACK_LINE(1736)
	this->_t22 = null();
	HX_STACK_LINE(1735)
	this->_t21 = false;
	HX_STACK_LINE(1734)
	this->_t20 = false;
	HX_STACK_LINE(1733)
	this->_t19 = (int)0;
	HX_STACK_LINE(1732)
	this->_t18 = (int)0;
	HX_STACK_LINE(1731)
	this->_t17 = false;
	HX_STACK_LINE(1730)
	this->_t16 = (int)0;
	HX_STACK_LINE(1729)
	this->_t15 = false;
	HX_STACK_LINE(1728)
	this->_t14 = (int)0;
	HX_STACK_LINE(1727)
	this->_t13 = (int)0;
	HX_STACK_LINE(1726)
	this->_t12 = (int)0;
	HX_STACK_LINE(1725)
	this->_t11 = (int)0;
	HX_STACK_LINE(1724)
	this->_t10 = null();
	HX_STACK_LINE(1723)
	this->_t9 = (int)0;
	HX_STACK_LINE(1722)
	this->_t8 = (int)0;
	HX_STACK_LINE(1721)
	this->_t7 = (int)0;
	HX_STACK_LINE(1720)
	this->_t6 = null();
	HX_STACK_LINE(1719)
	this->_t5 = false;
	HX_STACK_LINE(1718)
	this->_t4 = (int)0;
	HX_STACK_LINE(1717)
	this->_t3 = (int)0;
	HX_STACK_LINE(1716)
	this->_t2 = null();
	HX_STACK_LINE(1715)
	this->_t1 = false;
	HX_STACK_LINE(1714)
	this->_t0 = (int)0;
	HX_STACK_LINE(1706)
	super::__construct(gr,(int)863,HX_CSTRING("Go_utf8_EncodeRune"));
	HX_STACK_LINE(1707)
	this->_bds = _bds;
	HX_STACK_LINE(1708)
	this->p_p = p_p;
	HX_STACK_LINE(1709)
	this->p_r = p_r;
	HX_STACK_LINE(1710)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_EncodeRune_obj::~Go_utf8_EncodeRune_obj() { }

Dynamic Go_utf8_EncodeRune_obj::__CreateEmpty() { return  new Go_utf8_EncodeRune_obj; }
hx::ObjectPtr< Go_utf8_EncodeRune_obj > Go_utf8_EncodeRune_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_p,int p_r)
{  hx::ObjectPtr< Go_utf8_EncodeRune_obj > result = new Go_utf8_EncodeRune_obj();
	result->__construct(gr,_bds,p_p,p_r);
	return result;}

Dynamic Go_utf8_EncodeRune_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_EncodeRune_obj > result = new Go_utf8_EncodeRune_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Go_utf8_EncodeRune_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_EncodeRune_obj::SubFn11( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn11","tardis/Go.hx",1978);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1979)
		::tardis::Pointer _t35;		HX_STACK_VAR(_t35,"_t35");
		HX_STACK_LINE(1980)
		int _t36;		HX_STACK_VAR(_t36,"_t36");
		HX_STACK_LINE(1981)
		int _t37;		HX_STACK_VAR(_t37,"_t37");
		HX_STACK_LINE(1982)
		int _t38;		HX_STACK_VAR(_t38,"_t38");
		HX_STACK_LINE(1983)
		::tardis::Pointer _t39;		HX_STACK_VAR(_t39,"_t39");
		HX_STACK_LINE(1984)
		int _t40;		HX_STACK_VAR(_t40,"_t40");
		HX_STACK_LINE(1985)
		int _t41;		HX_STACK_VAR(_t41,"_t41");
		HX_STACK_LINE(1986)
		int _t42;		HX_STACK_VAR(_t42,"_t42");
		HX_STACK_LINE(1987)
		int _t43;		HX_STACK_VAR(_t43,"_t43");
		HX_STACK_LINE(1988)
		::tardis::Pointer _t44;		HX_STACK_VAR(_t44,"_t44");
		HX_STACK_LINE(1989)
		int _t45;		HX_STACK_VAR(_t45,"_t45");
		HX_STACK_LINE(1990)
		int _t46;		HX_STACK_VAR(_t46,"_t46");
		HX_STACK_LINE(1991)
		int _t47;		HX_STACK_VAR(_t47,"_t47");
		HX_STACK_LINE(1992)
		int _t48;		HX_STACK_VAR(_t48,"_t48");
		HX_STACK_LINE(1993)
		::tardis::Pointer _t49;		HX_STACK_VAR(_t49,"_t49");
		HX_STACK_LINE(1994)
		int _t50;		HX_STACK_VAR(_t50,"_t50");
		HX_STACK_LINE(1995)
		int _t51;		HX_STACK_VAR(_t51,"_t51");
		HX_STACK_LINE(1996)
		int _t52;		HX_STACK_VAR(_t52,"_t52");
		HX_STACK_LINE(1997)
		this->_latestPH = (int)891;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1998);
				{
					HX_STACK_LINE(1998)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1998)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1998)
		if ((((int)0 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(1998)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1999)
		_t35 = this->p_p->addr((int)0);
		HX_STACK_LINE(2000)
		_t36 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)18))));
		HX_STACK_LINE(2001)
		_t37 = _t36;
		HX_STACK_LINE(2002)
		_t38 = (int(((int((int)240) | int(_t37)))) & int((int)255));
		HX_STACK_LINE(2003)
		_t35->store(_t38);
		HX_STACK_LINE(2004)
		this->_latestPH = (int)892;
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2005);
				{
					HX_STACK_LINE(2005)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2005)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2005)
		if ((((int)1 >= _Function_1_2::Block(this)))){
			HX_STACK_LINE(2005)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2006)
		_t39 = this->p_p->addr((int)1);
		HX_STACK_LINE(2007)
		_t40 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
		HX_STACK_LINE(2008)
		_t41 = _t40;
		HX_STACK_LINE(2009)
		_t42 = (int((int(_t41) & int((int)63))) & int((int)255));
		HX_STACK_LINE(2010)
		_t43 = (int(((int((int)128) | int(_t42)))) & int((int)255));
		HX_STACK_LINE(2011)
		_t39->store(_t43);
		HX_STACK_LINE(2012)
		this->_latestPH = (int)893;
		struct _Function_1_3{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2013);
				{
					HX_STACK_LINE(2013)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2013)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2013)
		if ((((int)2 >= _Function_1_3::Block(this)))){
			HX_STACK_LINE(2013)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2014)
		_t44 = this->p_p->addr((int)2);
		HX_STACK_LINE(2015)
		_t45 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(2016)
		_t46 = _t45;
		HX_STACK_LINE(2017)
		_t47 = (int((int(_t46) & int((int)63))) & int((int)255));
		HX_STACK_LINE(2018)
		_t48 = (int(((int((int)128) | int(_t47)))) & int((int)255));
		HX_STACK_LINE(2019)
		_t44->store(_t48);
		HX_STACK_LINE(2020)
		this->_latestPH = (int)894;
		struct _Function_1_4{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",2021);
				{
					HX_STACK_LINE(2021)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2021)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(2021)
		if ((((int)3 >= _Function_1_4::Block(this)))){
			HX_STACK_LINE(2021)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(2022)
		_t49 = this->p_p->addr((int)3);
		HX_STACK_LINE(2023)
		_t50 = this->_t18;
		HX_STACK_LINE(2024)
		_t51 = (int((int(_t50) & int((int)63))) & int((int)255));
		HX_STACK_LINE(2025)
		_t52 = (int(((int((int)128) | int(_t51)))) & int((int)255));
		HX_STACK_LINE(2026)
		_t49->store(_t52);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn11,(void))

Void Go_utf8_EncodeRune_obj::SubFn10( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn10","tardis/Go.hx",1941);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1942)
		::tardis::Pointer _t22;		HX_STACK_VAR(_t22,"_t22");
		HX_STACK_LINE(1943)
		int _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(1944)
		int _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(1945)
		int _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(1946)
		::tardis::Pointer _t26;		HX_STACK_VAR(_t26,"_t26");
		HX_STACK_LINE(1947)
		int _t27;		HX_STACK_VAR(_t27,"_t27");
		HX_STACK_LINE(1948)
		int _t28;		HX_STACK_VAR(_t28,"_t28");
		HX_STACK_LINE(1949)
		int _t29;		HX_STACK_VAR(_t29,"_t29");
		HX_STACK_LINE(1950)
		int _t30;		HX_STACK_VAR(_t30,"_t30");
		HX_STACK_LINE(1951)
		::tardis::Pointer _t31;		HX_STACK_VAR(_t31,"_t31");
		HX_STACK_LINE(1952)
		int _t32;		HX_STACK_VAR(_t32,"_t32");
		HX_STACK_LINE(1953)
		int _t33;		HX_STACK_VAR(_t33,"_t33");
		HX_STACK_LINE(1954)
		int _t34;		HX_STACK_VAR(_t34,"_t34");
		HX_STACK_LINE(1955)
		this->_latestPH = (int)885;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1956);
				{
					HX_STACK_LINE(1956)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1956)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1956)
		if ((((int)0 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(1956)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1957)
		_t22 = this->p_p->addr((int)0);
		HX_STACK_LINE(1958)
		_t23 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
		HX_STACK_LINE(1959)
		_t24 = _t23;
		HX_STACK_LINE(1960)
		_t25 = (int(((int((int)224) | int(_t24)))) & int((int)255));
		HX_STACK_LINE(1961)
		_t22->store(_t25);
		HX_STACK_LINE(1962)
		this->_latestPH = (int)886;
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1963);
				{
					HX_STACK_LINE(1963)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1963)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1963)
		if ((((int)1 >= _Function_1_2::Block(this)))){
			HX_STACK_LINE(1963)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1964)
		_t26 = this->p_p->addr((int)1);
		HX_STACK_LINE(1965)
		_t27 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(1966)
		_t28 = _t27;
		HX_STACK_LINE(1967)
		_t29 = (int((int(_t28) & int((int)63))) & int((int)255));
		HX_STACK_LINE(1968)
		_t30 = (int(((int((int)128) | int(_t29)))) & int((int)255));
		HX_STACK_LINE(1969)
		_t26->store(_t30);
		HX_STACK_LINE(1970)
		this->_latestPH = (int)887;
		struct _Function_1_3{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1971);
				{
					HX_STACK_LINE(1971)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1971)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1971)
		if ((((int)2 >= _Function_1_3::Block(this)))){
			HX_STACK_LINE(1971)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1972)
		_t31 = this->p_p->addr((int)2);
		HX_STACK_LINE(1973)
		_t32 = this->_t18;
		HX_STACK_LINE(1974)
		_t33 = (int((int(_t32) & int((int)63))) & int((int)255));
		HX_STACK_LINE(1975)
		_t34 = (int(((int((int)128) | int(_t33)))) & int((int)255));
		HX_STACK_LINE(1976)
		_t31->store(_t34);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn10,(void))

Void Go_utf8_EncodeRune_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn9","tardis/Go.hx",1935);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1936)
		bool _t21;		HX_STACK_VAR(_t21,"_t21");
		HX_STACK_LINE(1937)
		this->_latestPH = (int)880;
		HX_STACK_LINE(1938)
		_t21 = (this->_t16 <= (int)57343);
		HX_STACK_LINE(1939)
		this->_Next = (  ((_t21)) ? int((int)7) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn9,(void))

Void Go_utf8_EncodeRune_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn8","tardis/Go.hx",1927);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1928)
		int _t19;		HX_STACK_VAR(_t19,"_t19");
		HX_STACK_LINE(1929)
		bool _t20;		HX_STACK_VAR(_t20,"_t20");
		HX_STACK_LINE(1930)
		this->_latestPH = (int)884;
		HX_STACK_LINE(1931)
		_t19 = this->_t18;
		HX_STACK_LINE(1932)
		_t20 = (::tardis::Force_obj::uintCompare(_t19,(int)65535) <= (int)0);
		HX_STACK_LINE(1933)
		this->_Next = (  ((_t20)) ? int((int)10) : int((int)11) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn8,(void))

Void Go_utf8_EncodeRune_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn7","tardis/Go.hx",1924);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1924)
		this->_Next = (int)8;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn7,(void))

Void Go_utf8_EncodeRune_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn6","tardis/Go.hx",1918);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1919)
		bool _t17;		HX_STACK_VAR(_t17,"_t17");
		HX_STACK_LINE(1920)
		this->_latestPH = (int)880;
		HX_STACK_LINE(1921)
		_t17 = ((int)55296 <= this->_t16);
		HX_STACK_LINE(1922)
		this->_Next = (  ((_t17)) ? int((int)9) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn6,(void))

Void Go_utf8_EncodeRune_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn5","tardis/Go.hx",1915);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1915)
		this->_Next = (int)6;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn5,(void))

Void Go_utf8_EncodeRune_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn4","tardis/Go.hx",1907);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1908)
		int _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(1909)
		bool _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(1910)
		this->_latestPH = (int)876;
		HX_STACK_LINE(1911)
		_t14 = this->p_r;
		HX_STACK_LINE(1912)
		_t15 = (::tardis::Force_obj::uintCompare(_t14,(int)1114111) > (int)0);
		HX_STACK_LINE(1913)
		this->_Next = (  ((_t15)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn4,(void))

Void Go_utf8_EncodeRune_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn3","tardis/Go.hx",1883);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1884)
		::tardis::Pointer _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(1885)
		int _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(1886)
		int _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(1887)
		int _t9;		HX_STACK_VAR(_t9,"_t9");
		HX_STACK_LINE(1888)
		::tardis::Pointer _t10;		HX_STACK_VAR(_t10,"_t10");
		HX_STACK_LINE(1889)
		int _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(1890)
		int _t12;		HX_STACK_VAR(_t12,"_t12");
		HX_STACK_LINE(1891)
		int _t13;		HX_STACK_VAR(_t13,"_t13");
		HX_STACK_LINE(1892)
		this->_latestPH = (int)871;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1893);
				{
					HX_STACK_LINE(1893)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1893)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1893)
		if ((((int)0 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(1893)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1894)
		_t6 = this->p_p->addr((int)0);
		HX_STACK_LINE(1895)
		_t7 = (int(this->p_r) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(1896)
		_t8 = _t7;
		HX_STACK_LINE(1897)
		_t9 = (int(((int((int)192) | int(_t8)))) & int((int)255));
		HX_STACK_LINE(1898)
		_t6->store(_t9);
		HX_STACK_LINE(1899)
		this->_latestPH = (int)872;
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1900);
				{
					HX_STACK_LINE(1900)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1900)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1900)
		if ((((int)1 >= _Function_1_2::Block(this)))){
			HX_STACK_LINE(1900)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1901)
		_t10 = this->p_p->addr((int)1);
		HX_STACK_LINE(1902)
		_t11 = this->p_r;
		HX_STACK_LINE(1903)
		_t12 = (int((int(_t11) & int((int)63))) & int((int)255));
		HX_STACK_LINE(1904)
		_t13 = (int(((int((int)128) | int(_t12)))) & int((int)255));
		HX_STACK_LINE(1905)
		_t10->store(_t13);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn3,(void))

Void Go_utf8_EncodeRune_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn2","tardis/Go.hx",1875);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1876)
		int _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(1877)
		bool _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(1878)
		this->_latestPH = (int)870;
		HX_STACK_LINE(1879)
		_t4 = this->p_r;
		HX_STACK_LINE(1880)
		_t5 = (::tardis::Force_obj::uintCompare(_t4,(int)2047) <= (int)0);
		HX_STACK_LINE(1881)
		this->_Next = (  ((_t5)) ? int((int)3) : int((int)4) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn2,(void))

Void Go_utf8_EncodeRune_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn1","tardis/Go.hx",1866);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1867)
		::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(1868)
		int _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(1869)
		this->_latestPH = (int)866;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1870);
				{
					HX_STACK_LINE(1870)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1870)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1870)
		if ((((int)0 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(1870)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1871)
		_t2 = this->p_p->addr((int)0);
		HX_STACK_LINE(1872)
		_t3 = this->p_r;
		HX_STACK_LINE(1873)
		_t2->store(_t3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn1,(void))

Void Go_utf8_EncodeRune_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_EncodeRune::SubFn0","tardis/Go.hx",1858);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1859)
		int _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(1860)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(1861)
		this->_latestPH = (int)865;
		HX_STACK_LINE(1862)
		_t0 = this->p_r;
		HX_STACK_LINE(1863)
		_t1 = (::tardis::Force_obj::uintCompare(_t0,(int)127) <= (int)0);
		HX_STACK_LINE(1864)
		this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_EncodeRune_obj::run( ){
	HX_STACK_PUSH("Go_utf8_EncodeRune::run","tardis/Go.hx",1783);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1783)
	while((true)){
		HX_STACK_LINE(1785)
		::tardis::Go_utf8_EncodeRune _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1785)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(1787)
				{
					HX_STACK_LINE(1787)
					this->_latestPH = (int)863;
					HX_STACK_LINE(1787)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(1788)
				{
					HX_STACK_LINE(1788)
					int _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(1788)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(1788)
					this->_latestPH = (int)865;
					HX_STACK_LINE(1788)
					_t0 = this->p_r;
					HX_STACK_LINE(1788)
					_t1 = (::tardis::Force_obj::uintCompare(_t0,(int)127) <= (int)0);
					HX_STACK_LINE(1788)
					this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(1789)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(1791)
				{
					HX_STACK_LINE(1791)
					this->_latestPH = (int)863;
					HX_STACK_LINE(1791)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(1792)
				{
					HX_STACK_LINE(1792)
					::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(1792)
					int _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(1792)
					this->_latestPH = (int)866;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1792);
							{
								HX_STACK_LINE(1792)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1792)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1792)
					if ((((int)0 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(1792)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1792)
					_t2 = this->p_p->addr((int)0);
					HX_STACK_LINE(1792)
					_t3 = this->p_r;
					HX_STACK_LINE(1792)
					_t2->store(_t3);
				}
				HX_STACK_LINE(1793)
				this->_latestPH = (int)867;
				HX_STACK_LINE(1794)
				this->_res = (int)1;
				HX_STACK_LINE(1795)
				this->_incomplete = false;
				HX_STACK_LINE(1796)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(1797)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(1800)
				{
					HX_STACK_LINE(1800)
					this->_latestPH = (int)867;
					HX_STACK_LINE(1800)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(1801)
				{
					HX_STACK_LINE(1801)
					int _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(1801)
					bool _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(1801)
					this->_latestPH = (int)870;
					HX_STACK_LINE(1801)
					_t4 = this->p_r;
					HX_STACK_LINE(1801)
					_t5 = (::tardis::Force_obj::uintCompare(_t4,(int)2047) <= (int)0);
					HX_STACK_LINE(1801)
					this->_Next = (  ((_t5)) ? int((int)3) : int((int)4) );
				}
				HX_STACK_LINE(1802)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(1804)
				{
					HX_STACK_LINE(1804)
					this->_latestPH = (int)867;
					HX_STACK_LINE(1804)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(1805)
				{
					HX_STACK_LINE(1805)
					::tardis::Pointer _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(1805)
					int _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(1805)
					int _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(1805)
					int _t9;		HX_STACK_VAR(_t9,"_t9");
					HX_STACK_LINE(1805)
					::tardis::Pointer _t10;		HX_STACK_VAR(_t10,"_t10");
					HX_STACK_LINE(1805)
					int _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(1805)
					int _t12;		HX_STACK_VAR(_t12,"_t12");
					HX_STACK_LINE(1805)
					int _t13;		HX_STACK_VAR(_t13,"_t13");
					HX_STACK_LINE(1805)
					this->_latestPH = (int)871;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1805);
							{
								HX_STACK_LINE(1805)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1805)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1805)
					if ((((int)0 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(1805)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1805)
					_t6 = this->p_p->addr((int)0);
					HX_STACK_LINE(1805)
					_t7 = (int(this->p_r) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(1805)
					_t8 = _t7;
					HX_STACK_LINE(1805)
					_t9 = (int(((int((int)192) | int(_t8)))) & int((int)255));
					HX_STACK_LINE(1805)
					_t6->store(_t9);
					HX_STACK_LINE(1805)
					this->_latestPH = (int)872;
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1805);
							{
								HX_STACK_LINE(1805)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1805)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1805)
					if ((((int)1 >= _Function_4_2::Block(this)))){
						HX_STACK_LINE(1805)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1805)
					_t10 = this->p_p->addr((int)1);
					HX_STACK_LINE(1805)
					_t11 = this->p_r;
					HX_STACK_LINE(1805)
					_t12 = (int((int(_t11) & int((int)63))) & int((int)255));
					HX_STACK_LINE(1805)
					_t13 = (int(((int((int)128) | int(_t12)))) & int((int)255));
					HX_STACK_LINE(1805)
					_t10->store(_t13);
				}
				HX_STACK_LINE(1806)
				this->_latestPH = (int)873;
				HX_STACK_LINE(1807)
				this->_res = (int)2;
				HX_STACK_LINE(1808)
				this->_incomplete = false;
				HX_STACK_LINE(1809)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(1810)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(1813)
				{
					HX_STACK_LINE(1813)
					this->_latestPH = (int)873;
					HX_STACK_LINE(1813)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(1814)
				{
					HX_STACK_LINE(1814)
					int _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(1814)
					bool _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(1814)
					this->_latestPH = (int)876;
					HX_STACK_LINE(1814)
					_t14 = this->p_r;
					HX_STACK_LINE(1814)
					_t15 = (::tardis::Force_obj::uintCompare(_t14,(int)1114111) > (int)0);
					HX_STACK_LINE(1814)
					this->_Next = (  ((_t15)) ? int((int)5) : int((int)6) );
				}
				HX_STACK_LINE(1815)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(1817)
				{
					HX_STACK_LINE(1817)
					this->_latestPH = (int)873;
					HX_STACK_LINE(1817)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(1818)
				this->_Next = (int)6;
				HX_STACK_LINE(1819)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(1821)
				{
					HX_STACK_LINE(1821)
					this->_latestPH = (int)873;
					HX_STACK_LINE(1821)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(1822)
				this->_latestPH = (int)863;
				HX_STACK_LINE(1823)
				this->_t16 = (  (((this->_Phi == (int)4))) ? int(this->p_r) : int((  (((this->_Phi == (int)5))) ? int((int)65533) : int((int)0) )) );
				HX_STACK_LINE(1824)
				{
					HX_STACK_LINE(1824)
					bool _t17;		HX_STACK_VAR(_t17,"_t17");
					HX_STACK_LINE(1824)
					this->_latestPH = (int)880;
					HX_STACK_LINE(1824)
					_t17 = ((int)55296 <= this->_t16);
					HX_STACK_LINE(1824)
					this->_Next = (  ((_t17)) ? int((int)9) : int((int)8) );
				}
				HX_STACK_LINE(1825)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(1827)
				{
					HX_STACK_LINE(1827)
					this->_latestPH = (int)863;
					HX_STACK_LINE(1827)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(1828)
				this->_Next = (int)8;
				HX_STACK_LINE(1829)
				this->_Phi = (int)7;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(1831)
				{
					HX_STACK_LINE(1831)
					this->_latestPH = (int)863;
					HX_STACK_LINE(1831)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(1832)
				this->_t18 = (  (((this->_Phi == (int)6))) ? int(this->_t16) : int((  (((this->_Phi == (int)9))) ? int(this->_t16) : int((  (((this->_Phi == (int)7))) ? int((int)65533) : int((int)0) )) )) );
				HX_STACK_LINE(1833)
				{
					HX_STACK_LINE(1833)
					int _t19;		HX_STACK_VAR(_t19,"_t19");
					HX_STACK_LINE(1833)
					bool _t20;		HX_STACK_VAR(_t20,"_t20");
					HX_STACK_LINE(1833)
					this->_latestPH = (int)884;
					HX_STACK_LINE(1833)
					_t19 = this->_t18;
					HX_STACK_LINE(1833)
					_t20 = (::tardis::Force_obj::uintCompare(_t19,(int)65535) <= (int)0);
					HX_STACK_LINE(1833)
					this->_Next = (  ((_t20)) ? int((int)10) : int((int)11) );
				}
				HX_STACK_LINE(1834)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(1836)
				{
					HX_STACK_LINE(1836)
					this->_latestPH = (int)863;
					HX_STACK_LINE(1836)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(1837)
				{
					HX_STACK_LINE(1837)
					bool _t21;		HX_STACK_VAR(_t21,"_t21");
					HX_STACK_LINE(1837)
					this->_latestPH = (int)880;
					HX_STACK_LINE(1837)
					_t21 = (this->_t16 <= (int)57343);
					HX_STACK_LINE(1837)
					this->_Next = (  ((_t21)) ? int((int)7) : int((int)8) );
				}
				HX_STACK_LINE(1838)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(1840)
				{
					HX_STACK_LINE(1840)
					this->_latestPH = (int)863;
					HX_STACK_LINE(1840)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(1841)
				{
					HX_STACK_LINE(1841)
					::tardis::Pointer _t22;		HX_STACK_VAR(_t22,"_t22");
					HX_STACK_LINE(1841)
					int _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(1841)
					int _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(1841)
					int _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(1841)
					::tardis::Pointer _t26;		HX_STACK_VAR(_t26,"_t26");
					HX_STACK_LINE(1841)
					int _t27;		HX_STACK_VAR(_t27,"_t27");
					HX_STACK_LINE(1841)
					int _t28;		HX_STACK_VAR(_t28,"_t28");
					HX_STACK_LINE(1841)
					int _t29;		HX_STACK_VAR(_t29,"_t29");
					HX_STACK_LINE(1841)
					int _t30;		HX_STACK_VAR(_t30,"_t30");
					HX_STACK_LINE(1841)
					::tardis::Pointer _t31;		HX_STACK_VAR(_t31,"_t31");
					HX_STACK_LINE(1841)
					int _t32;		HX_STACK_VAR(_t32,"_t32");
					HX_STACK_LINE(1841)
					int _t33;		HX_STACK_VAR(_t33,"_t33");
					HX_STACK_LINE(1841)
					int _t34;		HX_STACK_VAR(_t34,"_t34");
					HX_STACK_LINE(1841)
					this->_latestPH = (int)885;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1841);
							{
								HX_STACK_LINE(1841)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1841)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1841)
					if ((((int)0 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(1841)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1841)
					_t22 = this->p_p->addr((int)0);
					HX_STACK_LINE(1841)
					_t23 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
					HX_STACK_LINE(1841)
					_t24 = _t23;
					HX_STACK_LINE(1841)
					_t25 = (int(((int((int)224) | int(_t24)))) & int((int)255));
					HX_STACK_LINE(1841)
					_t22->store(_t25);
					HX_STACK_LINE(1841)
					this->_latestPH = (int)886;
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1841);
							{
								HX_STACK_LINE(1841)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1841)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1841)
					if ((((int)1 >= _Function_4_2::Block(this)))){
						HX_STACK_LINE(1841)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1841)
					_t26 = this->p_p->addr((int)1);
					HX_STACK_LINE(1841)
					_t27 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(1841)
					_t28 = _t27;
					HX_STACK_LINE(1841)
					_t29 = (int((int(_t28) & int((int)63))) & int((int)255));
					HX_STACK_LINE(1841)
					_t30 = (int(((int((int)128) | int(_t29)))) & int((int)255));
					HX_STACK_LINE(1841)
					_t26->store(_t30);
					HX_STACK_LINE(1841)
					this->_latestPH = (int)887;
					struct _Function_4_3{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1841);
							{
								HX_STACK_LINE(1841)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1841)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1841)
					if ((((int)2 >= _Function_4_3::Block(this)))){
						HX_STACK_LINE(1841)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1841)
					_t31 = this->p_p->addr((int)2);
					HX_STACK_LINE(1841)
					_t32 = this->_t18;
					HX_STACK_LINE(1841)
					_t33 = (int((int(_t32) & int((int)63))) & int((int)255));
					HX_STACK_LINE(1841)
					_t34 = (int(((int((int)128) | int(_t33)))) & int((int)255));
					HX_STACK_LINE(1841)
					_t31->store(_t34);
				}
				HX_STACK_LINE(1842)
				this->_latestPH = (int)888;
				HX_STACK_LINE(1843)
				this->_res = (int)3;
				HX_STACK_LINE(1844)
				this->_incomplete = false;
				HX_STACK_LINE(1845)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(1846)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(1849)
				{
					HX_STACK_LINE(1849)
					this->_latestPH = (int)888;
					HX_STACK_LINE(1849)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(1850)
				{
					HX_STACK_LINE(1850)
					::tardis::Pointer _t35;		HX_STACK_VAR(_t35,"_t35");
					HX_STACK_LINE(1850)
					int _t36;		HX_STACK_VAR(_t36,"_t36");
					HX_STACK_LINE(1850)
					int _t37;		HX_STACK_VAR(_t37,"_t37");
					HX_STACK_LINE(1850)
					int _t38;		HX_STACK_VAR(_t38,"_t38");
					HX_STACK_LINE(1850)
					::tardis::Pointer _t39;		HX_STACK_VAR(_t39,"_t39");
					HX_STACK_LINE(1850)
					int _t40;		HX_STACK_VAR(_t40,"_t40");
					HX_STACK_LINE(1850)
					int _t41;		HX_STACK_VAR(_t41,"_t41");
					HX_STACK_LINE(1850)
					int _t42;		HX_STACK_VAR(_t42,"_t42");
					HX_STACK_LINE(1850)
					int _t43;		HX_STACK_VAR(_t43,"_t43");
					HX_STACK_LINE(1850)
					::tardis::Pointer _t44;		HX_STACK_VAR(_t44,"_t44");
					HX_STACK_LINE(1850)
					int _t45;		HX_STACK_VAR(_t45,"_t45");
					HX_STACK_LINE(1850)
					int _t46;		HX_STACK_VAR(_t46,"_t46");
					HX_STACK_LINE(1850)
					int _t47;		HX_STACK_VAR(_t47,"_t47");
					HX_STACK_LINE(1850)
					int _t48;		HX_STACK_VAR(_t48,"_t48");
					HX_STACK_LINE(1850)
					::tardis::Pointer _t49;		HX_STACK_VAR(_t49,"_t49");
					HX_STACK_LINE(1850)
					int _t50;		HX_STACK_VAR(_t50,"_t50");
					HX_STACK_LINE(1850)
					int _t51;		HX_STACK_VAR(_t51,"_t51");
					HX_STACK_LINE(1850)
					int _t52;		HX_STACK_VAR(_t52,"_t52");
					HX_STACK_LINE(1850)
					this->_latestPH = (int)891;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1850);
							{
								HX_STACK_LINE(1850)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1850)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1850)
					if ((((int)0 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(1850)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1850)
					_t35 = this->p_p->addr((int)0);
					HX_STACK_LINE(1850)
					_t36 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)18))));
					HX_STACK_LINE(1850)
					_t37 = _t36;
					HX_STACK_LINE(1850)
					_t38 = (int(((int((int)240) | int(_t37)))) & int((int)255));
					HX_STACK_LINE(1850)
					_t35->store(_t38);
					HX_STACK_LINE(1850)
					this->_latestPH = (int)892;
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1850);
							{
								HX_STACK_LINE(1850)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1850)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1850)
					if ((((int)1 >= _Function_4_2::Block(this)))){
						HX_STACK_LINE(1850)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1850)
					_t39 = this->p_p->addr((int)1);
					HX_STACK_LINE(1850)
					_t40 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
					HX_STACK_LINE(1850)
					_t41 = _t40;
					HX_STACK_LINE(1850)
					_t42 = (int((int(_t41) & int((int)63))) & int((int)255));
					HX_STACK_LINE(1850)
					_t43 = (int(((int((int)128) | int(_t42)))) & int((int)255));
					HX_STACK_LINE(1850)
					_t39->store(_t43);
					HX_STACK_LINE(1850)
					this->_latestPH = (int)893;
					struct _Function_4_3{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1850);
							{
								HX_STACK_LINE(1850)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1850)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1850)
					if ((((int)2 >= _Function_4_3::Block(this)))){
						HX_STACK_LINE(1850)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1850)
					_t44 = this->p_p->addr((int)2);
					HX_STACK_LINE(1850)
					_t45 = (int(this->_t18) >> int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(1850)
					_t46 = _t45;
					HX_STACK_LINE(1850)
					_t47 = (int((int(_t46) & int((int)63))) & int((int)255));
					HX_STACK_LINE(1850)
					_t48 = (int(((int((int)128) | int(_t47)))) & int((int)255));
					HX_STACK_LINE(1850)
					_t44->store(_t48);
					HX_STACK_LINE(1850)
					this->_latestPH = (int)894;
					struct _Function_4_4{
						inline static int Block( ::tardis::Go_utf8_EncodeRune_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1850);
							{
								HX_STACK_LINE(1850)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1850)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1850)
					if ((((int)3 >= _Function_4_4::Block(this)))){
						HX_STACK_LINE(1850)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1850)
					_t49 = this->p_p->addr((int)3);
					HX_STACK_LINE(1850)
					_t50 = this->_t18;
					HX_STACK_LINE(1850)
					_t51 = (int((int(_t50) & int((int)63))) & int((int)255));
					HX_STACK_LINE(1850)
					_t52 = (int(((int((int)128) | int(_t51)))) & int((int)255));
					HX_STACK_LINE(1850)
					_t49->store(_t52);
				}
				HX_STACK_LINE(1851)
				this->_latestPH = (int)895;
				HX_STACK_LINE(1852)
				this->_res = (int)4;
				HX_STACK_LINE(1853)
				this->_incomplete = false;
				HX_STACK_LINE(1854)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(1855)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(1857)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(1783)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,run,return )

Dynamic Go_utf8_EncodeRune_obj::res( ){
	HX_STACK_PUSH("Go_utf8_EncodeRune::res","tardis/Go.hx",1713);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1713)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_EncodeRune_obj,res,return )

int Go_utf8_EncodeRune_obj::callFromHaxe( ::tardis::Slice p_p,int p_r){
	HX_STACK_PUSH("Go_utf8_EncodeRune::callFromHaxe","tardis/Go.hx",1769);
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(1770)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(1770)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(1771)
	::tardis::Go_utf8_EncodeRune _sf = hx::TCast< ::tardis::Go_utf8_EncodeRune >::cast(::tardis::Go_utf8_EncodeRune_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_p,p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(1772)
	while((_sf->_incomplete)){
		HX_STACK_LINE(1772)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(1773)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_EncodeRune_obj,callFromHaxe,return )

int Go_utf8_EncodeRune_obj::callFromRT( int _gr,::tardis::Slice p_p,int p_r){
	HX_STACK_PUSH("Go_utf8_EncodeRune::callFromRT","tardis/Go.hx",1775);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(1776)
	::tardis::Go_utf8_EncodeRune _sf = hx::TCast< ::tardis::Go_utf8_EncodeRune >::cast(::tardis::Go_utf8_EncodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p,p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(1777)
	while((_sf->_incomplete)){
		HX_STACK_LINE(1777)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(1777)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(1777)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(1777)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(1778)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_EncodeRune_obj,callFromRT,return )

::tardis::Go_utf8_EncodeRune Go_utf8_EncodeRune_obj::call( int gr,Dynamic _bds,::tardis::Slice p_p,int p_r){
	HX_STACK_PUSH("Go_utf8_EncodeRune::call","tardis/Go.hx",1781);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(1781)
	return ::tardis::Go_utf8_EncodeRune_obj::__new(gr,_bds,p_p,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Go_utf8_EncodeRune_obj,call,return )


Go_utf8_EncodeRune_obj::Go_utf8_EncodeRune_obj()
{
}

void Go_utf8_EncodeRune_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_EncodeRune);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t52,"_t52");
	HX_MARK_MEMBER_NAME(_t51,"_t51");
	HX_MARK_MEMBER_NAME(_t50,"_t50");
	HX_MARK_MEMBER_NAME(_t49,"_t49");
	HX_MARK_MEMBER_NAME(_t48,"_t48");
	HX_MARK_MEMBER_NAME(_t47,"_t47");
	HX_MARK_MEMBER_NAME(_t46,"_t46");
	HX_MARK_MEMBER_NAME(_t45,"_t45");
	HX_MARK_MEMBER_NAME(_t44,"_t44");
	HX_MARK_MEMBER_NAME(_t43,"_t43");
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
	HX_MARK_MEMBER_NAME(p_r,"p_r");
	HX_MARK_MEMBER_NAME(p_p,"p_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_EncodeRune_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t52,"_t52");
	HX_VISIT_MEMBER_NAME(_t51,"_t51");
	HX_VISIT_MEMBER_NAME(_t50,"_t50");
	HX_VISIT_MEMBER_NAME(_t49,"_t49");
	HX_VISIT_MEMBER_NAME(_t48,"_t48");
	HX_VISIT_MEMBER_NAME(_t47,"_t47");
	HX_VISIT_MEMBER_NAME(_t46,"_t46");
	HX_VISIT_MEMBER_NAME(_t45,"_t45");
	HX_VISIT_MEMBER_NAME(_t44,"_t44");
	HX_VISIT_MEMBER_NAME(_t43,"_t43");
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
	HX_VISIT_MEMBER_NAME(p_r,"p_r");
	HX_VISIT_MEMBER_NAME(p_p,"p_p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_EncodeRune_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_p") ) { return p_p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t52") ) { return _t52; }
		if (HX_FIELD_EQ(inName,"_t51") ) { return _t51; }
		if (HX_FIELD_EQ(inName,"_t50") ) { return _t50; }
		if (HX_FIELD_EQ(inName,"_t49") ) { return _t49; }
		if (HX_FIELD_EQ(inName,"_t48") ) { return _t48; }
		if (HX_FIELD_EQ(inName,"_t47") ) { return _t47; }
		if (HX_FIELD_EQ(inName,"_t46") ) { return _t46; }
		if (HX_FIELD_EQ(inName,"_t45") ) { return _t45; }
		if (HX_FIELD_EQ(inName,"_t44") ) { return _t44; }
		if (HX_FIELD_EQ(inName,"_t43") ) { return _t43; }
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

Dynamic Go_utf8_EncodeRune_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_p") ) { p_p=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t52") ) { _t52=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t51") ) { _t51=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t50") ) { _t50=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t49") ) { _t49=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t48") ) { _t48=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t47") ) { _t47=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t46") ) { _t46=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t45") ) { _t45=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t44") ) { _t44=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t43") ) { _t43=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t42") ) { _t42=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t41") ) { _t41=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t40") ) { _t40=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t39") ) { _t39=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t38") ) { _t38=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t37") ) { _t37=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t36") ) { _t36=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t35") ) { _t35=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t34") ) { _t34=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t33") ) { _t33=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t32") ) { _t32=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t31") ) { _t31=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t30") ) { _t30=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t29") ) { _t29=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t28") ) { _t28=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t27") ) { _t27=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t26") ) { _t26=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_EncodeRune_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t52"));
	outFields->push(HX_CSTRING("_t51"));
	outFields->push(HX_CSTRING("_t50"));
	outFields->push(HX_CSTRING("_t49"));
	outFields->push(HX_CSTRING("_t48"));
	outFields->push(HX_CSTRING("_t47"));
	outFields->push(HX_CSTRING("_t46"));
	outFields->push(HX_CSTRING("_t45"));
	outFields->push(HX_CSTRING("_t44"));
	outFields->push(HX_CSTRING("_t43"));
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
	outFields->push(HX_CSTRING("p_r"));
	outFields->push(HX_CSTRING("p_p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
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
	HX_CSTRING("_t52"),
	HX_CSTRING("_t51"),
	HX_CSTRING("_t50"),
	HX_CSTRING("_t49"),
	HX_CSTRING("_t48"),
	HX_CSTRING("_t47"),
	HX_CSTRING("_t46"),
	HX_CSTRING("_t45"),
	HX_CSTRING("_t44"),
	HX_CSTRING("_t43"),
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
	HX_CSTRING("p_r"),
	HX_CSTRING("p_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_EncodeRune_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_EncodeRune_obj::__mClass,"__mClass");
};

Class Go_utf8_EncodeRune_obj::__mClass;

void Go_utf8_EncodeRune_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_EncodeRune"), hx::TCanCast< Go_utf8_EncodeRune_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_EncodeRune_obj::__boot()
{
}

} // end namespace tardis
