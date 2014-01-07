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
#ifndef INCLUDED_tardis_Go_utf16_Encode
#include <tardis/Go_utf16_Encode.h>
#endif
#ifndef INCLUDED_tardis_Go_utf16_EncodeRune
#include <tardis/Go_utf16_EncodeRune.h>
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

Void Go_utf16_Encode_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_s)
{
HX_STACK_PUSH("Go_utf16_Encode::new","tardis/Go.hx",1434);
{
	HX_STACK_LINE(1484)
	this->_Next = (int)0;
	HX_STACK_LINE(1483)
	this->_Phi = (int)0;
	HX_STACK_LINE(1482)
	this->_t37 = (int)0;
	HX_STACK_LINE(1481)
	this->_t36 = (int)0;
	HX_STACK_LINE(1480)
	this->_t35 = null();
	HX_STACK_LINE(1479)
	this->_t34 = (int)0;
	HX_STACK_LINE(1478)
	this->_t33 = (int)0;
	HX_STACK_LINE(1477)
	this->_t32 = null();
	HX_STACK_LINE(1476)
	this->_t31 = (int)0;
	HX_STACK_LINE(1475)
	this->_t30 = (int)0;
	HX_STACK_LINE(1474)
	this->_t29 = null();
	HX_STACK_LINE(1472)
	this->_t28 = false;
	HX_STACK_LINE(1471)
	this->_t27 = false;
	HX_STACK_LINE(1470)
	this->_t26 = false;
	HX_STACK_LINE(1469)
	this->_t25 = false;
	HX_STACK_LINE(1468)
	this->_t24 = false;
	HX_STACK_LINE(1467)
	this->_t23 = (int)0;
	HX_STACK_LINE(1466)
	this->_t22 = (int)0;
	HX_STACK_LINE(1465)
	this->_t21 = null();
	HX_STACK_LINE(1464)
	this->_t20 = (int)0;
	HX_STACK_LINE(1463)
	this->_t19 = null();
	HX_STACK_LINE(1462)
	this->_t18 = false;
	HX_STACK_LINE(1461)
	this->_t17 = (int)0;
	HX_STACK_LINE(1460)
	this->_t16 = null();
	HX_STACK_LINE(1459)
	this->_t15 = false;
	HX_STACK_LINE(1458)
	this->_t14 = (int)0;
	HX_STACK_LINE(1457)
	this->_t13 = (int)0;
	HX_STACK_LINE(1456)
	this->_t12 = (int)0;
	HX_STACK_LINE(1455)
	this->_t11 = (int)0;
	HX_STACK_LINE(1454)
	this->_t10 = (int)0;
	HX_STACK_LINE(1453)
	this->_t9 = null();
	HX_STACK_LINE(1452)
	this->_t8 = false;
	HX_STACK_LINE(1451)
	this->_t7 = (int)0;
	HX_STACK_LINE(1450)
	this->_t6 = null();
	HX_STACK_LINE(1449)
	this->_t5 = false;
	HX_STACK_LINE(1448)
	this->_t4 = (int)0;
	HX_STACK_LINE(1447)
	this->_t3 = (int)0;
	HX_STACK_LINE(1446)
	this->_t2 = (int)0;
	HX_STACK_LINE(1445)
	this->_t1 = (int)0;
	HX_STACK_LINE(1444)
	this->_t0 = (int)0;
	HX_STACK_LINE(1437)
	super::__construct(gr,(int)481,HX_CSTRING("Go_utf16_Encode"));
	HX_STACK_LINE(1438)
	this->_bds = _bds;
	HX_STACK_LINE(1439)
	this->p_s = p_s;
	HX_STACK_LINE(1440)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf16_Encode_obj::~Go_utf16_Encode_obj() { }

Dynamic Go_utf16_Encode_obj::__CreateEmpty() { return  new Go_utf16_Encode_obj; }
hx::ObjectPtr< Go_utf16_Encode_obj > Go_utf16_Encode_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_s)
{  hx::ObjectPtr< Go_utf16_Encode_obj > result = new Go_utf16_Encode_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf16_Encode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf16_Encode_obj > result = new Go_utf16_Encode_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf16_Encode_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf16_Encode_obj::SubFn15( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn15","tardis/Go.hx",1679);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1680)
		::tardis::Pointer _t32;		HX_STACK_VAR(_t32,"_t32");
		HX_STACK_LINE(1681)
		int _t33;		HX_STACK_VAR(_t33,"_t33");
		HX_STACK_LINE(1682)
		int _t34;		HX_STACK_VAR(_t34,"_t34");
		HX_STACK_LINE(1683)
		::tardis::Pointer _t35;		HX_STACK_VAR(_t35,"_t35");
		HX_STACK_LINE(1684)
		int _t36;		HX_STACK_VAR(_t36,"_t36");
		HX_STACK_LINE(1685)
		this->_t30 = this->_t29->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(1686)
		this->_t31 = this->_t29->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(1687)
		this->_latestPH = (int)501;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1688);
				{
					HX_STACK_LINE(1688)
					::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1688)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1688)
		if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(1688)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1689)
		_t32 = this->_t9->addr(this->_t12);
		HX_STACK_LINE(1690)
		_t33 = this->_t30;
		HX_STACK_LINE(1691)
		_t32->store(_t33);
		HX_STACK_LINE(1692)
		this->_latestPH = (int)502;
		HX_STACK_LINE(1693)
		_t34 = (this->_t12 + (int)1);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1694);
				{
					HX_STACK_LINE(1694)
					::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1694)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1694)
		if (((bool((_t34 < (int)0)) || bool((_t34 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(1694)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1695)
		_t35 = this->_t9->addr(_t34);
		HX_STACK_LINE(1696)
		_t36 = this->_t31;
		HX_STACK_LINE(1697)
		_t35->store(_t36);
		HX_STACK_LINE(1698)
		this->_t37 = (this->_t12 + (int)2);
		HX_STACK_LINE(1699)
		this->_Next = (int)5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn15,(void))

Void Go_utf16_Encode_obj::SubFn14( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn14","tardis/Go.hx",1673);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1674)
		bool _t28;		HX_STACK_VAR(_t28,"_t28");
		HX_STACK_LINE(1675)
		this->_latestPH = (int)496;
		HX_STACK_LINE(1676)
		_t28 = (this->_t17 < (int)65536);
		HX_STACK_LINE(1677)
		this->_Next = (  ((_t28)) ? int((int)9) : int((int)15) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn14,(void))

Void Go_utf16_Encode_obj::SubFn13( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn13","tardis/Go.hx",1670);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1670)
		this->_Next = (  ((this->_t27)) ? int((int)8) : int((int)11) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn13,(void))

Void Go_utf16_Encode_obj::SubFn12( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn12","tardis/Go.hx",1666);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1667)
		this->_t26 = (this->_t17 < (int)57344);
		HX_STACK_LINE(1668)
		this->_Next = (int)13;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn12,(void))

Void Go_utf16_Encode_obj::SubFn11( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn11","tardis/Go.hx",1661);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1662)
		bool _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(1663)
		_t25 = (this->_t17 > (int)1114111);
		HX_STACK_LINE(1664)
		this->_Next = (  ((_t25)) ? int((int)8) : int((int)14) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn11,(void))

Void Go_utf16_Encode_obj::SubFn10( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn10","tardis/Go.hx",1655);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1656)
		bool _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(1657)
		this->_latestPH = (int)493;
		HX_STACK_LINE(1658)
		_t24 = ((int)55296 <= this->_t17);
		HX_STACK_LINE(1659)
		this->_Next = (  ((_t24)) ? int((int)12) : int((int)13) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn10,(void))

Void Go_utf16_Encode_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn9","tardis/Go.hx",1644);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1645)
		::tardis::Pointer _t21;		HX_STACK_VAR(_t21,"_t21");
		HX_STACK_LINE(1646)
		int _t22;		HX_STACK_VAR(_t22,"_t22");
		HX_STACK_LINE(1647)
		this->_latestPH = (int)497;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1648);
				{
					HX_STACK_LINE(1648)
					::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1648)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1648)
		if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(1648)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1649)
		_t21 = this->_t9->addr(this->_t12);
		HX_STACK_LINE(1650)
		_t22 = this->_t20;
		HX_STACK_LINE(1651)
		_t21->store(_t22);
		HX_STACK_LINE(1652)
		this->_t23 = (this->_t12 + (int)1);
		HX_STACK_LINE(1653)
		this->_Next = (int)5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn9,(void))

Void Go_utf16_Encode_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn8","tardis/Go.hx",1641);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1641)
		this->_Next = (int)9;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn8,(void))

Void Go_utf16_Encode_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn7","tardis/Go.hx",1637);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1638)
		this->_latestPH = (int)506;
		HX_STACK_LINE(1639)
		this->_t19 = this->_t9->subSlice((int)0,this->_t12);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn7,(void))

Void Go_utf16_Encode_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn6","tardis/Go.hx",1627);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1628)
		::tardis::Pointer _t16;		HX_STACK_VAR(_t16,"_t16");
		HX_STACK_LINE(1629)
		bool _t18;		HX_STACK_VAR(_t18,"_t18");
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1630);
				{
					HX_STACK_LINE(1630)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1630)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1630)
		if (((bool((this->_t14 < (int)0)) || bool((this->_t14 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(1630)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1631)
		_t16 = this->p_s->addr(this->_t14);
		HX_STACK_LINE(1632)
		this->_t17 = (int(_t16->ref()) | int((int)0));
		HX_STACK_LINE(1633)
		this->_latestPH = (int)493;
		HX_STACK_LINE(1634)
		_t18 = (this->_t17 < (int)0);
		HX_STACK_LINE(1635)
		this->_Next = (  ((_t18)) ? int((int)8) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn6,(void))

Void Go_utf16_Encode_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn5","tardis/Go.hx",1621);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1622)
		bool _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(1623)
		this->_t14 = (this->_t13 + (int)1);
		HX_STACK_LINE(1624)
		_t15 = (this->_t14 < this->_t10);
		HX_STACK_LINE(1625)
		this->_Next = (  ((_t15)) ? int((int)6) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn5,(void))

Void Go_utf16_Encode_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn4","tardis/Go.hx",1617);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1618)
		this->_t11 = (this->_t2 + (int)1);
		HX_STACK_LINE(1619)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn4,(void))

Void Go_utf16_Encode_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn3","tardis/Go.hx",1611);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1612)
		this->_latestPH = (int)489;
		struct _Function_1_1{
			inline static Array< int > Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1613);
				{
					HX_STACK_LINE(1613)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(1613)
					{
						HX_STACK_LINE(1613)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						int _g = __this->_t2;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(1613)
						while(((_g1 < _g))){
							HX_STACK_LINE(1613)
							int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(1613)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(1613)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(1613)
		this->_t9 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_1::Block(this)),(int)0,this->_t2);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1614);
				{
					HX_STACK_LINE(1614)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(1614)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1614)
		this->_t10 = _Function_1_2::Block(this);
		HX_STACK_LINE(1615)
		this->_Next = (int)5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn3,(void))

Void Go_utf16_Encode_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn2","tardis/Go.hx",1601);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1602)
		::tardis::Pointer _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(1603)
		bool _t8;		HX_STACK_VAR(_t8,"_t8");
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1604);
				{
					HX_STACK_LINE(1604)
					::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1604)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(1604)
		if (((bool((this->_t4 < (int)0)) || bool((this->_t4 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(1604)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(1605)
		_t6 = this->p_s->addr(this->_t4);
		HX_STACK_LINE(1606)
		this->_t7 = (int(_t6->ref()) | int((int)0));
		HX_STACK_LINE(1607)
		this->_latestPH = (int)484;
		HX_STACK_LINE(1608)
		_t8 = (this->_t7 >= (int)65536);
		HX_STACK_LINE(1609)
		this->_Next = (  ((_t8)) ? int((int)4) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn2,(void))

Void Go_utf16_Encode_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn1","tardis/Go.hx",1595);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1596)
		bool _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(1597)
		this->_t4 = (this->_t3 + (int)1);
		HX_STACK_LINE(1598)
		_t5 = (this->_t4 < this->_t1);
		HX_STACK_LINE(1599)
		this->_Next = (  ((_t5)) ? int((int)2) : int((int)3) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn1,(void))

Void Go_utf16_Encode_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf16_Encode::SubFn0","tardis/Go.hx",1589);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1590)
		this->_latestPH = (int)482;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1591);
				{
					HX_STACK_LINE(1591)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(1591)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1591)
		this->_t0 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",1592);
				{
					HX_STACK_LINE(1592)
					::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(1592)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1592)
		this->_t1 = _Function_1_2::Block(this);
		HX_STACK_LINE(1593)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,SubFn0,(void))

::tardis::StackFrame Go_utf16_Encode_obj::run( ){
	HX_STACK_PUSH("Go_utf16_Encode::run","tardis/Go.hx",1499);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1499)
	while((true)){
		HX_STACK_LINE(1501)
		::tardis::Go_utf16_Encode _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1501)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(1503)
				{
					HX_STACK_LINE(1503)
					this->_latestPH = (int)481;
					HX_STACK_LINE(1503)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(1504)
				{
					HX_STACK_LINE(1504)
					this->_latestPH = (int)482;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1504);
							{
								HX_STACK_LINE(1504)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(1504)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(1504)
					this->_t0 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1504);
							{
								HX_STACK_LINE(1504)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(1504)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(1504)
					this->_t1 = _Function_4_2::Block(this);
					HX_STACK_LINE(1504)
					this->_Next = (int)1;
				}
				HX_STACK_LINE(1505)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(1507)
				{
					HX_STACK_LINE(1507)
					this->_latestPH = (int)481;
					HX_STACK_LINE(1507)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(1508)
				this->_latestPH = (int)482;
				HX_STACK_LINE(1509)
				this->_t2 = (  (((this->_Phi == (int)0))) ? int(this->_t0) : int((  (((this->_Phi == (int)2))) ? int(this->_t2) : int((  (((this->_Phi == (int)4))) ? int(this->_t11) : int((int)0) )) )) );
				HX_STACK_LINE(1510)
				this->_t3 = (  (((this->_Phi == (int)0))) ? int((int)-1) : int((  (((this->_Phi == (int)2))) ? int(this->_t4) : int((  (((this->_Phi == (int)4))) ? int(this->_t4) : int((int)0) )) )) );
				HX_STACK_LINE(1511)
				{
					HX_STACK_LINE(1511)
					bool _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(1511)
					this->_t4 = (this->_t3 + (int)1);
					HX_STACK_LINE(1511)
					_t5 = (this->_t4 < this->_t1);
					HX_STACK_LINE(1511)
					this->_Next = (  ((_t5)) ? int((int)2) : int((int)3) );
				}
				HX_STACK_LINE(1512)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(1514)
				{
					HX_STACK_LINE(1514)
					this->_latestPH = (int)482;
					HX_STACK_LINE(1514)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(1515)
				{
					HX_STACK_LINE(1515)
					::tardis::Pointer _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(1515)
					bool _t8;		HX_STACK_VAR(_t8,"_t8");
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1515);
							{
								HX_STACK_LINE(1515)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1515)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1515)
					if (((bool((this->_t4 < (int)0)) || bool((this->_t4 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(1515)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1515)
					_t6 = this->p_s->addr(this->_t4);
					HX_STACK_LINE(1515)
					this->_t7 = (int(_t6->ref()) | int((int)0));
					HX_STACK_LINE(1515)
					this->_latestPH = (int)484;
					HX_STACK_LINE(1515)
					_t8 = (this->_t7 >= (int)65536);
					HX_STACK_LINE(1515)
					this->_Next = (  ((_t8)) ? int((int)4) : int((int)1) );
				}
				HX_STACK_LINE(1516)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(1518)
				{
					HX_STACK_LINE(1518)
					this->_latestPH = (int)482;
					HX_STACK_LINE(1518)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(1519)
				{
					HX_STACK_LINE(1519)
					this->_latestPH = (int)489;
					struct _Function_4_1{
						inline static Array< int > Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1519);
							{
								HX_STACK_LINE(1519)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(1519)
								{
									HX_STACK_LINE(1519)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									int _g2 = __this->_t2;		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(1519)
									while(((_g1 < _g2))){
										HX_STACK_LINE(1519)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(1519)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(1519)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(1519)
					this->_t9 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_1::Block(this)),(int)0,this->_t2);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1519);
							{
								HX_STACK_LINE(1519)
								::tardis::Slice _v = __this->p_s;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(1519)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(1519)
					this->_t10 = _Function_4_2::Block(this);
					HX_STACK_LINE(1519)
					this->_Next = (int)5;
				}
				HX_STACK_LINE(1520)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(1522)
				{
					HX_STACK_LINE(1522)
					this->_latestPH = (int)482;
					HX_STACK_LINE(1522)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(1523)
				{
					HX_STACK_LINE(1523)
					this->_t11 = (this->_t2 + (int)1);
					HX_STACK_LINE(1523)
					this->_Next = (int)1;
				}
				HX_STACK_LINE(1524)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(1526)
				{
					HX_STACK_LINE(1526)
					this->_latestPH = (int)482;
					HX_STACK_LINE(1526)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(1527)
				this->_t12 = (  (((this->_Phi == (int)3))) ? int((int)0) : int((  (((this->_Phi == (int)9))) ? int(this->_t23) : int((  (((this->_Phi == (int)15))) ? int(this->_t37) : int((int)0) )) )) );
				HX_STACK_LINE(1528)
				this->_t13 = (  (((this->_Phi == (int)3))) ? int((int)-1) : int((  (((this->_Phi == (int)9))) ? int(this->_t14) : int((  (((this->_Phi == (int)15))) ? int(this->_t14) : int((int)0) )) )) );
				HX_STACK_LINE(1529)
				{
					HX_STACK_LINE(1529)
					bool _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(1529)
					this->_t14 = (this->_t13 + (int)1);
					HX_STACK_LINE(1529)
					_t15 = (this->_t14 < this->_t10);
					HX_STACK_LINE(1529)
					this->_Next = (  ((_t15)) ? int((int)6) : int((int)7) );
				}
				HX_STACK_LINE(1530)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(1532)
				{
					HX_STACK_LINE(1532)
					this->_latestPH = (int)482;
					HX_STACK_LINE(1532)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(1533)
				{
					HX_STACK_LINE(1533)
					::tardis::Pointer _t16;		HX_STACK_VAR(_t16,"_t16");
					HX_STACK_LINE(1533)
					bool _t18;		HX_STACK_VAR(_t18,"_t18");
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1533);
							{
								HX_STACK_LINE(1533)
								::tardis::Slice _this = __this->p_s;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1533)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1533)
					if (((bool((this->_t14 < (int)0)) || bool((this->_t14 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(1533)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1533)
					_t16 = this->p_s->addr(this->_t14);
					HX_STACK_LINE(1533)
					this->_t17 = (int(_t16->ref()) | int((int)0));
					HX_STACK_LINE(1533)
					this->_latestPH = (int)493;
					HX_STACK_LINE(1533)
					_t18 = (this->_t17 < (int)0);
					HX_STACK_LINE(1533)
					this->_Next = (  ((_t18)) ? int((int)8) : int((int)10) );
				}
				HX_STACK_LINE(1534)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(1536)
				{
					HX_STACK_LINE(1536)
					this->_latestPH = (int)482;
					HX_STACK_LINE(1536)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(1537)
				{
					HX_STACK_LINE(1537)
					this->_latestPH = (int)506;
					HX_STACK_LINE(1537)
					this->_t19 = this->_t9->subSlice((int)0,this->_t12);
				}
				HX_STACK_LINE(1538)
				this->_latestPH = (int)506;
				HX_STACK_LINE(1539)
				this->_res = this->_t19;
				HX_STACK_LINE(1540)
				this->_incomplete = false;
				HX_STACK_LINE(1541)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(1542)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(1545)
				{
					HX_STACK_LINE(1545)
					this->_latestPH = (int)506;
					HX_STACK_LINE(1545)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(1546)
				this->_Next = (int)9;
				HX_STACK_LINE(1547)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(1549)
				{
					HX_STACK_LINE(1549)
					this->_latestPH = (int)506;
					HX_STACK_LINE(1549)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(1550)
				this->_latestPH = (int)491;
				HX_STACK_LINE(1551)
				this->_t20 = (  (((this->_Phi == (int)8))) ? int((int)65533) : int((  (((this->_Phi == (int)14))) ? int(this->_t17) : int((int)0) )) );
				HX_STACK_LINE(1552)
				{
					HX_STACK_LINE(1552)
					::tardis::Pointer _t21;		HX_STACK_VAR(_t21,"_t21");
					HX_STACK_LINE(1552)
					int _t22;		HX_STACK_VAR(_t22,"_t22");
					HX_STACK_LINE(1552)
					this->_latestPH = (int)497;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1552);
							{
								HX_STACK_LINE(1552)
								::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1552)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1552)
					if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(1552)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1552)
					_t21 = this->_t9->addr(this->_t12);
					HX_STACK_LINE(1552)
					_t22 = this->_t20;
					HX_STACK_LINE(1552)
					_t21->store(_t22);
					HX_STACK_LINE(1552)
					this->_t23 = (this->_t12 + (int)1);
					HX_STACK_LINE(1552)
					this->_Next = (int)5;
				}
				HX_STACK_LINE(1553)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(1555)
				{
					HX_STACK_LINE(1555)
					this->_latestPH = (int)491;
					HX_STACK_LINE(1555)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(1556)
				{
					HX_STACK_LINE(1556)
					bool _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(1556)
					this->_latestPH = (int)493;
					HX_STACK_LINE(1556)
					_t24 = ((int)55296 <= this->_t17);
					HX_STACK_LINE(1556)
					this->_Next = (  ((_t24)) ? int((int)12) : int((int)13) );
				}
				HX_STACK_LINE(1557)
				this->_Phi = (int)10;
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(1559)
				{
					HX_STACK_LINE(1559)
					this->_latestPH = (int)491;
					HX_STACK_LINE(1559)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(1560)
				{
					HX_STACK_LINE(1560)
					bool _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(1560)
					_t25 = (this->_t17 > (int)1114111);
					HX_STACK_LINE(1560)
					this->_Next = (  ((_t25)) ? int((int)8) : int((int)14) );
				}
				HX_STACK_LINE(1561)
				this->_Phi = (int)11;
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(1563)
				{
					HX_STACK_LINE(1563)
					this->_latestPH = (int)491;
					HX_STACK_LINE(1563)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(1564)
				{
					HX_STACK_LINE(1564)
					this->_t26 = (this->_t17 < (int)57344);
					HX_STACK_LINE(1564)
					this->_Next = (int)13;
				}
				HX_STACK_LINE(1565)
				this->_Phi = (int)12;
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(1567)
				{
					HX_STACK_LINE(1567)
					this->_latestPH = (int)491;
					HX_STACK_LINE(1567)
					this->_latestBlock = (int)13;
				}
				HX_STACK_LINE(1568)
				this->_latestPH = (int)493;
				HX_STACK_LINE(1569)
				this->_t27 = (  (((this->_Phi == (int)10))) ? bool(false) : bool((  (((this->_Phi == (int)12))) ? bool(this->_t26) : bool(false) )) );
				HX_STACK_LINE(1570)
				this->_Next = (  ((this->_t27)) ? int((int)8) : int((int)11) );
				HX_STACK_LINE(1571)
				this->_Phi = (int)13;
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(1573)
				{
					HX_STACK_LINE(1573)
					this->_latestPH = (int)493;
					HX_STACK_LINE(1573)
					this->_latestBlock = (int)14;
				}
				HX_STACK_LINE(1574)
				{
					HX_STACK_LINE(1574)
					bool _t28;		HX_STACK_VAR(_t28,"_t28");
					HX_STACK_LINE(1574)
					this->_latestPH = (int)496;
					HX_STACK_LINE(1574)
					_t28 = (this->_t17 < (int)65536);
					HX_STACK_LINE(1574)
					this->_Next = (  ((_t28)) ? int((int)9) : int((int)15) );
				}
				HX_STACK_LINE(1575)
				this->_Phi = (int)14;
			}
			;break;
			case (int)15: {
				HX_STACK_LINE(1577)
				{
					HX_STACK_LINE(1577)
					this->_latestPH = (int)493;
					HX_STACK_LINE(1577)
					this->_latestBlock = (int)15;
				}
				HX_STACK_LINE(1578)
				this->_latestPH = (int)500;
				HX_STACK_LINE(1579)
				this->_SF1 = ::tardis::Go_utf16_EncodeRune_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t17);
				HX_STACK_LINE(1580)
				this->_Next = (int)-1;
				HX_STACK_LINE(1581)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(1583)
				{
					HX_STACK_LINE(1583)
					this->_latestPH = (int)500;
					HX_STACK_LINE(1583)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(1584)
				this->_t29 = this->_SF1->res();
				HX_STACK_LINE(1586)
				{
					HX_STACK_LINE(1586)
					::tardis::Pointer _t32;		HX_STACK_VAR(_t32,"_t32");
					HX_STACK_LINE(1586)
					int _t33;		HX_STACK_VAR(_t33,"_t33");
					HX_STACK_LINE(1586)
					int _t34;		HX_STACK_VAR(_t34,"_t34");
					HX_STACK_LINE(1586)
					::tardis::Pointer _t35;		HX_STACK_VAR(_t35,"_t35");
					HX_STACK_LINE(1586)
					int _t36;		HX_STACK_VAR(_t36,"_t36");
					HX_STACK_LINE(1586)
					this->_t30 = this->_t29->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(1586)
					this->_t31 = this->_t29->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(1586)
					this->_latestPH = (int)501;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1586);
							{
								HX_STACK_LINE(1586)
								::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1586)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1586)
					if (((bool((this->_t12 < (int)0)) || bool((this->_t12 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(1586)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1586)
					_t32 = this->_t9->addr(this->_t12);
					HX_STACK_LINE(1586)
					_t33 = this->_t30;
					HX_STACK_LINE(1586)
					_t32->store(_t33);
					HX_STACK_LINE(1586)
					this->_latestPH = (int)502;
					HX_STACK_LINE(1586)
					_t34 = (this->_t12 + (int)1);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_utf16_Encode_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",1586);
							{
								HX_STACK_LINE(1586)
								::tardis::Slice _this = __this->_t9;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(1586)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(1586)
					if (((bool((_t34 < (int)0)) || bool((_t34 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(1586)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(1586)
					_t35 = this->_t9->addr(_t34);
					HX_STACK_LINE(1586)
					_t36 = this->_t31;
					HX_STACK_LINE(1586)
					_t35->store(_t36);
					HX_STACK_LINE(1586)
					this->_t37 = (this->_t12 + (int)2);
					HX_STACK_LINE(1586)
					this->_Next = (int)5;
				}
				HX_STACK_LINE(1587)
				this->_Phi = (int)15;
			}
			;break;
			default: {
				HX_STACK_LINE(1588)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(1499)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,run,return )

Dynamic Go_utf16_Encode_obj::res( ){
	HX_STACK_PUSH("Go_utf16_Encode::res","tardis/Go.hx",1443);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1443)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_Encode_obj,res,return )

::tardis::Slice Go_utf16_Encode_obj::callFromHaxe( ::tardis::Slice p_s){
	HX_STACK_PUSH("Go_utf16_Encode::callFromHaxe","tardis/Go.hx",1485);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(1486)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(1486)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(1487)
	::tardis::Go_utf16_Encode _sf = hx::TCast< ::tardis::Go_utf16_Encode >::cast(::tardis::Go_utf16_Encode_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(1488)
	while((_sf->_incomplete)){
		HX_STACK_LINE(1488)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(1489)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf16_Encode_obj,callFromHaxe,return )

::tardis::Slice Go_utf16_Encode_obj::callFromRT( int _gr,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_utf16_Encode::callFromRT","tardis/Go.hx",1491);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(1492)
	::tardis::Go_utf16_Encode _sf = hx::TCast< ::tardis::Go_utf16_Encode >::cast(::tardis::Go_utf16_Encode_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(1493)
	while((_sf->_incomplete)){
		HX_STACK_LINE(1493)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(1493)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(1493)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(1493)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(1494)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf16_Encode_obj,callFromRT,return )

::tardis::Go_utf16_Encode Go_utf16_Encode_obj::call( int gr,Dynamic _bds,::tardis::Slice p_s){
	HX_STACK_PUSH("Go_utf16_Encode::call","tardis/Go.hx",1497);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(1497)
	return ::tardis::Go_utf16_Encode_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf16_Encode_obj,call,return )


Go_utf16_Encode_obj::Go_utf16_Encode_obj()
{
}

void Go_utf16_Encode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf16_Encode);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t37,"_t37");
	HX_MARK_MEMBER_NAME(_t36,"_t36");
	HX_MARK_MEMBER_NAME(_t35,"_t35");
	HX_MARK_MEMBER_NAME(_t34,"_t34");
	HX_MARK_MEMBER_NAME(_t33,"_t33");
	HX_MARK_MEMBER_NAME(_t32,"_t32");
	HX_MARK_MEMBER_NAME(_t31,"_t31");
	HX_MARK_MEMBER_NAME(_t30,"_t30");
	HX_MARK_MEMBER_NAME(_t29,"_t29");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
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
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf16_Encode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t37,"_t37");
	HX_VISIT_MEMBER_NAME(_t36,"_t36");
	HX_VISIT_MEMBER_NAME(_t35,"_t35");
	HX_VISIT_MEMBER_NAME(_t34,"_t34");
	HX_VISIT_MEMBER_NAME(_t33,"_t33");
	HX_VISIT_MEMBER_NAME(_t32,"_t32");
	HX_VISIT_MEMBER_NAME(_t31,"_t31");
	HX_VISIT_MEMBER_NAME(_t30,"_t30");
	HX_VISIT_MEMBER_NAME(_t29,"_t29");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
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
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf16_Encode_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_t37") ) { return _t37; }
		if (HX_FIELD_EQ(inName,"_t36") ) { return _t36; }
		if (HX_FIELD_EQ(inName,"_t35") ) { return _t35; }
		if (HX_FIELD_EQ(inName,"_t34") ) { return _t34; }
		if (HX_FIELD_EQ(inName,"_t33") ) { return _t33; }
		if (HX_FIELD_EQ(inName,"_t32") ) { return _t32; }
		if (HX_FIELD_EQ(inName,"_t31") ) { return _t31; }
		if (HX_FIELD_EQ(inName,"_t30") ) { return _t30; }
		if (HX_FIELD_EQ(inName,"_t29") ) { return _t29; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
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

Dynamic Go_utf16_Encode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t37") ) { _t37=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t36") ) { _t36=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t35") ) { _t35=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t34") ) { _t34=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t33") ) { _t33=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t32") ) { _t32=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t31") ) { _t31=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t30") ) { _t30=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t29") ) { _t29=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t28") ) { _t28=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t27") ) { _t27=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t26") ) { _t26=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< int >(); return inValue; }
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

void Go_utf16_Encode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t37"));
	outFields->push(HX_CSTRING("_t36"));
	outFields->push(HX_CSTRING("_t35"));
	outFields->push(HX_CSTRING("_t34"));
	outFields->push(HX_CSTRING("_t33"));
	outFields->push(HX_CSTRING("_t32"));
	outFields->push(HX_CSTRING("_t31"));
	outFields->push(HX_CSTRING("_t30"));
	outFields->push(HX_CSTRING("_t29"));
	outFields->push(HX_CSTRING("_SF1"));
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
	outFields->push(HX_CSTRING("p_s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
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
	HX_CSTRING("_t37"),
	HX_CSTRING("_t36"),
	HX_CSTRING("_t35"),
	HX_CSTRING("_t34"),
	HX_CSTRING("_t33"),
	HX_CSTRING("_t32"),
	HX_CSTRING("_t31"),
	HX_CSTRING("_t30"),
	HX_CSTRING("_t29"),
	HX_CSTRING("_SF1"),
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
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf16_Encode_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf16_Encode_obj::__mClass,"__mClass");
};

Class Go_utf16_Encode_obj::__mClass;

void Go_utf16_Encode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf16_Encode"), hx::TCanCast< Go_utf16_Encode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf16_Encode_obj::__boot()
{
}

} // end namespace tardis
