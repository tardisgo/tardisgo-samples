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
#ifndef INCLUDED_tardis_Int64
#include <tardis/Int64.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
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
#ifndef INCLUDED_tardis__Go_Go_utf8_decodeRuneInStringInternal
#include <tardis/_Go/Go_utf8_decodeRuneInStringInternal.h>
#endif
namespace tardis{
namespace _Go{

Void Go_utf8_decodeRuneInStringInternal_obj::__construct(int gr,Dynamic _bds,::String p_s)
{
HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::new","tardis/Go.hx",5887);
{
	HX_STACK_LINE(5954)
	this->_Next = (int)0;
	HX_STACK_LINE(5953)
	this->_t56 = false;
	HX_STACK_LINE(5952)
	this->_t55 = false;
	HX_STACK_LINE(5951)
	this->_t54 = (int)0;
	HX_STACK_LINE(5950)
	this->_t53 = (int)0;
	HX_STACK_LINE(5949)
	this->_t52 = (int)0;
	HX_STACK_LINE(5948)
	this->_t51 = (int)0;
	HX_STACK_LINE(5947)
	this->_t50 = (int)0;
	HX_STACK_LINE(5946)
	this->_t49 = (int)0;
	HX_STACK_LINE(5945)
	this->_t48 = (int)0;
	HX_STACK_LINE(5944)
	this->_t47 = (int)0;
	HX_STACK_LINE(5943)
	this->_t46 = (int)0;
	HX_STACK_LINE(5942)
	this->_t45 = (int)0;
	HX_STACK_LINE(5941)
	this->_t44 = (int)0;
	HX_STACK_LINE(5940)
	this->_t43 = (int)0;
	HX_STACK_LINE(5939)
	this->_t42 = (int)0;
	HX_STACK_LINE(5938)
	this->_t41 = (int)0;
	HX_STACK_LINE(5937)
	this->_t40 = false;
	HX_STACK_LINE(5936)
	this->_t39 = false;
	HX_STACK_LINE(5935)
	this->_t38 = false;
	HX_STACK_LINE(5934)
	this->_t37 = (int)0;
	HX_STACK_LINE(5933)
	this->_t36 = false;
	HX_STACK_LINE(5932)
	this->_t35 = false;
	HX_STACK_LINE(5931)
	this->_t34 = false;
	HX_STACK_LINE(5930)
	this->_t33 = false;
	HX_STACK_LINE(5929)
	this->_t32 = (int)0;
	HX_STACK_LINE(5928)
	this->_t31 = (int)0;
	HX_STACK_LINE(5927)
	this->_t30 = (int)0;
	HX_STACK_LINE(5926)
	this->_t29 = (int)0;
	HX_STACK_LINE(5925)
	this->_t28 = (int)0;
	HX_STACK_LINE(5924)
	this->_t27 = (int)0;
	HX_STACK_LINE(5923)
	this->_t26 = (int)0;
	HX_STACK_LINE(5922)
	this->_t25 = (int)0;
	HX_STACK_LINE(5921)
	this->_t24 = (int)0;
	HX_STACK_LINE(5920)
	this->_t23 = (int)0;
	HX_STACK_LINE(5919)
	this->_t22 = false;
	HX_STACK_LINE(5918)
	this->_t21 = false;
	HX_STACK_LINE(5917)
	this->_t20 = false;
	HX_STACK_LINE(5916)
	this->_t19 = (int)0;
	HX_STACK_LINE(5915)
	this->_t18 = false;
	HX_STACK_LINE(5914)
	this->_t17 = false;
	HX_STACK_LINE(5913)
	this->_t16 = (int)0;
	HX_STACK_LINE(5912)
	this->_t15 = (int)0;
	HX_STACK_LINE(5911)
	this->_t14 = (int)0;
	HX_STACK_LINE(5910)
	this->_t13 = (int)0;
	HX_STACK_LINE(5909)
	this->_t12 = (int)0;
	HX_STACK_LINE(5908)
	this->_t11 = (int)0;
	HX_STACK_LINE(5907)
	this->_t10 = false;
	HX_STACK_LINE(5906)
	this->_t9 = false;
	HX_STACK_LINE(5905)
	this->_t8 = false;
	HX_STACK_LINE(5904)
	this->_t7 = (int)0;
	HX_STACK_LINE(5903)
	this->_t6 = false;
	HX_STACK_LINE(5902)
	this->_t5 = false;
	HX_STACK_LINE(5901)
	this->_t4 = (int)0;
	HX_STACK_LINE(5900)
	this->_t3 = false;
	HX_STACK_LINE(5899)
	this->_t2 = (int)0;
	HX_STACK_LINE(5898)
	this->_t1 = false;
	HX_STACK_LINE(5897)
	this->_t0 = (int)0;
	HX_STACK_LINE(5890)
	super::__construct(gr,(int)656,HX_CSTRING("Go_utf8_decodeRuneInStringInternal"));
	HX_STACK_LINE(5891)
	this->_bds = _bds;
	HX_STACK_LINE(5892)
	this->p_s = p_s;
	HX_STACK_LINE(5893)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_decodeRuneInStringInternal_obj::~Go_utf8_decodeRuneInStringInternal_obj() { }

Dynamic Go_utf8_decodeRuneInStringInternal_obj::__CreateEmpty() { return  new Go_utf8_decodeRuneInStringInternal_obj; }
hx::ObjectPtr< Go_utf8_decodeRuneInStringInternal_obj > Go_utf8_decodeRuneInStringInternal_obj::__new(int gr,Dynamic _bds,::String p_s)
{  hx::ObjectPtr< Go_utf8_decodeRuneInStringInternal_obj > result = new Go_utf8_decodeRuneInStringInternal_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf8_decodeRuneInStringInternal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_decodeRuneInStringInternal_obj > result = new Go_utf8_decodeRuneInStringInternal_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_decodeRuneInStringInternal_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn21( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn21","tardis/Go.hx",6387);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6388)
		bool _t56;		HX_STACK_VAR(_t56,"_t56");
		HX_STACK_LINE(6389)
		_t56 = ((int)1114111 < this->_t54);
		HX_STACK_LINE(6390)
		this->_Next = (  ((_t56)) ? int((int)35) : int((int)36) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn21,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn20( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn20","tardis/Go.hx",6353);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6354)
		int _t41;		HX_STACK_VAR(_t41,"_t41");
		HX_STACK_LINE(6355)
		int _t42;		HX_STACK_VAR(_t42,"_t42");
		HX_STACK_LINE(6356)
		int _t43;		HX_STACK_VAR(_t43,"_t43");
		HX_STACK_LINE(6357)
		int _t44;		HX_STACK_VAR(_t44,"_t44");
		HX_STACK_LINE(6358)
		int _t45;		HX_STACK_VAR(_t45,"_t45");
		HX_STACK_LINE(6359)
		int _t46;		HX_STACK_VAR(_t46,"_t46");
		HX_STACK_LINE(6360)
		int _t47;		HX_STACK_VAR(_t47,"_t47");
		HX_STACK_LINE(6361)
		int _t48;		HX_STACK_VAR(_t48,"_t48");
		HX_STACK_LINE(6362)
		int _t49;		HX_STACK_VAR(_t49,"_t49");
		HX_STACK_LINE(6363)
		int _t50;		HX_STACK_VAR(_t50,"_t50");
		HX_STACK_LINE(6364)
		int _t51;		HX_STACK_VAR(_t51,"_t51");
		HX_STACK_LINE(6365)
		int _t52;		HX_STACK_VAR(_t52,"_t52");
		HX_STACK_LINE(6366)
		int _t53;		HX_STACK_VAR(_t53,"_t53");
		HX_STACK_LINE(6367)
		bool _t55;		HX_STACK_VAR(_t55,"_t55");
		HX_STACK_LINE(6368)
		this->_latestPH = (int)723;
		HX_STACK_LINE(6369)
		_t41 = (int((int(this->_t2) & int((int)7))) & int((int)255));
		HX_STACK_LINE(6370)
		_t42 = _t41;
		HX_STACK_LINE(6371)
		_t43 = (int(_t42) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)18))));
		HX_STACK_LINE(6372)
		_t44 = (int((int(this->_t7) & int((int)63))) & int((int)255));
		HX_STACK_LINE(6373)
		_t45 = _t44;
		HX_STACK_LINE(6374)
		_t46 = (int(_t45) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
		HX_STACK_LINE(6375)
		_t47 = ::tardis::Force_obj::toInt32((int(_t43) | int(_t46)));
		HX_STACK_LINE(6376)
		_t48 = (int((int(this->_t19) & int((int)63))) & int((int)255));
		HX_STACK_LINE(6377)
		_t49 = _t48;
		HX_STACK_LINE(6378)
		_t50 = (int(_t49) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(6379)
		_t51 = ::tardis::Force_obj::toInt32((int(_t47) | int(_t50)));
		HX_STACK_LINE(6380)
		_t52 = (int((int(this->_t37) & int((int)63))) & int((int)255));
		HX_STACK_LINE(6381)
		_t53 = _t52;
		HX_STACK_LINE(6382)
		this->_t54 = ::tardis::Force_obj::toInt32((int(_t51) | int(_t53)));
		HX_STACK_LINE(6383)
		this->_latestPH = (int)724;
		HX_STACK_LINE(6384)
		_t55 = (this->_t54 <= (int)65535);
		HX_STACK_LINE(6385)
		this->_Next = (  ((_t55)) ? int((int)35) : int((int)37) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn20,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn19( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn19","tardis/Go.hx",6347);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6348)
		bool _t40;		HX_STACK_VAR(_t40,"_t40");
		HX_STACK_LINE(6349)
		this->_latestPH = (int)717;
		HX_STACK_LINE(6350)
		_t40 = (::tardis::Force_obj::uintCompare((int)192,this->_t37) <= (int)0);
		HX_STACK_LINE(6351)
		this->_Next = (  ((_t40)) ? int((int)30) : int((int)31) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn19,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn18( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn18","tardis/Go.hx",6341);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6342)
		bool _t39;		HX_STACK_VAR(_t39,"_t39");
		HX_STACK_LINE(6343)
		this->_latestPH = (int)722;
		HX_STACK_LINE(6344)
		_t39 = (::tardis::Force_obj::uintCompare(this->_t2,(int)248) < (int)0);
		HX_STACK_LINE(6345)
		this->_Next = (  ((_t39)) ? int((int)33) : int((int)34) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn18,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn17( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn17","tardis/Go.hx",6333);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6334)
		bool _t38;		HX_STACK_VAR(_t38,"_t38");
		HX_STACK_LINE(6335)
		this->_latestPH = (int)716;
		HX_STACK_LINE(6336)
		this->_t37 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)3);
		HX_STACK_LINE(6337)
		this->_latestPH = (int)717;
		HX_STACK_LINE(6338)
		_t38 = (::tardis::Force_obj::uintCompare(this->_t37,(int)128) < (int)0);
		HX_STACK_LINE(6339)
		this->_Next = (  ((_t38)) ? int((int)30) : int((int)32) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn17,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn16( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn16","tardis/Go.hx",6328);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6329)
		bool _t36;		HX_STACK_VAR(_t36,"_t36");
		HX_STACK_LINE(6330)
		_t36 = (this->_t32 <= (int)57343);
		HX_STACK_LINE(6331)
		this->_Next = (  ((_t36)) ? int((int)25) : int((int)26) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn16,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn15( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn15","tardis/Go.hx",6322);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6323)
		bool _t35;		HX_STACK_VAR(_t35,"_t35");
		HX_STACK_LINE(6324)
		this->_latestPH = (int)706;
		HX_STACK_LINE(6325)
		_t35 = ((int)55296 <= this->_t32);
		HX_STACK_LINE(6326)
		this->_Next = (  ((_t35)) ? int((int)27) : int((int)26) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn15,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn14( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn14","tardis/Go.hx",6316);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6317)
		bool _t34;		HX_STACK_VAR(_t34,"_t34");
		HX_STACK_LINE(6318)
		this->_latestPH = (int)713;
		HX_STACK_LINE(6319)
		_t34 = (this->_t0 < (int)4);
		HX_STACK_LINE(6320)
		this->_Next = (  ((_t34)) ? int((int)28) : int((int)29) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn14,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn13( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn13","tardis/Go.hx",6290);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6291)
		int _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(6292)
		int _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(6293)
		int _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(6294)
		int _t26;		HX_STACK_VAR(_t26,"_t26");
		HX_STACK_LINE(6295)
		int _t27;		HX_STACK_VAR(_t27,"_t27");
		HX_STACK_LINE(6296)
		int _t28;		HX_STACK_VAR(_t28,"_t28");
		HX_STACK_LINE(6297)
		int _t29;		HX_STACK_VAR(_t29,"_t29");
		HX_STACK_LINE(6298)
		int _t30;		HX_STACK_VAR(_t30,"_t30");
		HX_STACK_LINE(6299)
		int _t31;		HX_STACK_VAR(_t31,"_t31");
		HX_STACK_LINE(6300)
		bool _t33;		HX_STACK_VAR(_t33,"_t33");
		HX_STACK_LINE(6301)
		this->_latestPH = (int)702;
		HX_STACK_LINE(6302)
		_t23 = (int((int(this->_t2) & int((int)15))) & int((int)255));
		HX_STACK_LINE(6303)
		_t24 = _t23;
		HX_STACK_LINE(6304)
		_t25 = (int(_t24) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
		HX_STACK_LINE(6305)
		_t26 = (int((int(this->_t7) & int((int)63))) & int((int)255));
		HX_STACK_LINE(6306)
		_t27 = _t26;
		HX_STACK_LINE(6307)
		_t28 = (int(_t27) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(6308)
		_t29 = ::tardis::Force_obj::toInt32((int(_t25) | int(_t28)));
		HX_STACK_LINE(6309)
		_t30 = (int((int(this->_t19) & int((int)63))) & int((int)255));
		HX_STACK_LINE(6310)
		_t31 = _t30;
		HX_STACK_LINE(6311)
		this->_t32 = ::tardis::Force_obj::toInt32((int(_t29) | int(_t31)));
		HX_STACK_LINE(6312)
		this->_latestPH = (int)703;
		HX_STACK_LINE(6313)
		_t33 = (this->_t32 <= (int)2047);
		HX_STACK_LINE(6314)
		this->_Next = (  ((_t33)) ? int((int)23) : int((int)24) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn13,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn12( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn12","tardis/Go.hx",6284);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6285)
		bool _t22;		HX_STACK_VAR(_t22,"_t22");
		HX_STACK_LINE(6286)
		this->_latestPH = (int)696;
		HX_STACK_LINE(6287)
		_t22 = (::tardis::Force_obj::uintCompare((int)192,this->_t19) <= (int)0);
		HX_STACK_LINE(6288)
		this->_Next = (  ((_t22)) ? int((int)18) : int((int)19) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn12,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn11( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn11","tardis/Go.hx",6278);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6279)
		bool _t21;		HX_STACK_VAR(_t21,"_t21");
		HX_STACK_LINE(6280)
		this->_latestPH = (int)701;
		HX_STACK_LINE(6281)
		_t21 = (::tardis::Force_obj::uintCompare(this->_t2,(int)240) < (int)0);
		HX_STACK_LINE(6282)
		this->_Next = (  ((_t21)) ? int((int)21) : int((int)22) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn11,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn10( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn10","tardis/Go.hx",6270);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6271)
		bool _t20;		HX_STACK_VAR(_t20,"_t20");
		HX_STACK_LINE(6272)
		this->_latestPH = (int)695;
		HX_STACK_LINE(6273)
		this->_t19 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)2);
		HX_STACK_LINE(6274)
		this->_latestPH = (int)696;
		HX_STACK_LINE(6275)
		_t20 = (::tardis::Force_obj::uintCompare(this->_t19,(int)128) < (int)0);
		HX_STACK_LINE(6276)
		this->_Next = (  ((_t20)) ? int((int)18) : int((int)20) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn10,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn9","tardis/Go.hx",6264);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6265)
		bool _t18;		HX_STACK_VAR(_t18,"_t18");
		HX_STACK_LINE(6266)
		this->_latestPH = (int)692;
		HX_STACK_LINE(6267)
		_t18 = (this->_t0 < (int)3);
		HX_STACK_LINE(6268)
		this->_Next = (  ((_t18)) ? int((int)16) : int((int)17) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn9,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn8","tardis/Go.hx",6246);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6247)
		int _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(6248)
		int _t12;		HX_STACK_VAR(_t12,"_t12");
		HX_STACK_LINE(6249)
		int _t13;		HX_STACK_VAR(_t13,"_t13");
		HX_STACK_LINE(6250)
		int _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(6251)
		int _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(6252)
		bool _t17;		HX_STACK_VAR(_t17,"_t17");
		HX_STACK_LINE(6253)
		this->_latestPH = (int)684;
		HX_STACK_LINE(6254)
		_t11 = (int((int(this->_t2) & int((int)31))) & int((int)255));
		HX_STACK_LINE(6255)
		_t12 = _t11;
		HX_STACK_LINE(6256)
		_t13 = (int(_t12) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(6257)
		_t14 = (int((int(this->_t7) & int((int)63))) & int((int)255));
		HX_STACK_LINE(6258)
		_t15 = _t14;
		HX_STACK_LINE(6259)
		this->_t16 = ::tardis::Force_obj::toInt32((int(_t13) | int(_t15)));
		HX_STACK_LINE(6260)
		this->_latestPH = (int)685;
		HX_STACK_LINE(6261)
		_t17 = (this->_t16 <= (int)127);
		HX_STACK_LINE(6262)
		this->_Next = (  ((_t17)) ? int((int)14) : int((int)15) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn8,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn7","tardis/Go.hx",6240);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6241)
		bool _t10;		HX_STACK_VAR(_t10,"_t10");
		HX_STACK_LINE(6242)
		this->_latestPH = (int)678;
		HX_STACK_LINE(6243)
		_t10 = (::tardis::Force_obj::uintCompare((int)192,this->_t7) <= (int)0);
		HX_STACK_LINE(6244)
		this->_Next = (  ((_t10)) ? int((int)9) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn7,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn6","tardis/Go.hx",6234);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6235)
		bool _t9;		HX_STACK_VAR(_t9,"_t9");
		HX_STACK_LINE(6236)
		this->_latestPH = (int)683;
		HX_STACK_LINE(6237)
		_t9 = (::tardis::Force_obj::uintCompare(this->_t2,(int)224) < (int)0);
		HX_STACK_LINE(6238)
		this->_Next = (  ((_t9)) ? int((int)12) : int((int)13) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn6,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn5","tardis/Go.hx",6226);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6227)
		bool _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(6228)
		this->_latestPH = (int)677;
		HX_STACK_LINE(6229)
		this->_t7 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)1);
		HX_STACK_LINE(6230)
		this->_latestPH = (int)678;
		HX_STACK_LINE(6231)
		_t8 = (::tardis::Force_obj::uintCompare(this->_t7,(int)128) < (int)0);
		HX_STACK_LINE(6232)
		this->_Next = (  ((_t8)) ? int((int)9) : int((int)11) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn5,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn4","tardis/Go.hx",6220);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6221)
		bool _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(6222)
		this->_latestPH = (int)674;
		HX_STACK_LINE(6223)
		_t6 = (this->_t0 < (int)2);
		HX_STACK_LINE(6224)
		this->_Next = (  ((_t6)) ? int((int)7) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn4,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn3","tardis/Go.hx",6214);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6215)
		bool _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(6216)
		this->_latestPH = (int)669;
		HX_STACK_LINE(6217)
		_t5 = (::tardis::Force_obj::uintCompare(this->_t2,(int)192) < (int)0);
		HX_STACK_LINE(6218)
		this->_Next = (  ((_t5)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn3,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn2","tardis/Go.hx",6210);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6211)
		this->_latestPH = (int)665;
		HX_STACK_LINE(6212)
		this->_t4 = this->_t2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn2,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn1","tardis/Go.hx",6202);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6203)
		bool _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(6204)
		this->_latestPH = (int)661;
		HX_STACK_LINE(6205)
		this->_t2 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)0);
		HX_STACK_LINE(6206)
		this->_latestPH = (int)664;
		HX_STACK_LINE(6207)
		_t3 = (::tardis::Force_obj::uintCompare(this->_t2,(int)128) < (int)0);
		HX_STACK_LINE(6208)
		this->_Next = (  ((_t3)) ? int((int)3) : int((int)4) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn1,(void))

Void Go_utf8_decodeRuneInStringInternal_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::SubFn0","tardis/Go.hx",6194);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6195)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(6196)
		this->_latestPH = (int)657;
		HX_STACK_LINE(6197)
		this->_t0 = ::tardis::Force_obj::toUTF8length(this->_goroutine,this->p_s);
		HX_STACK_LINE(6198)
		this->_latestPH = (int)658;
		HX_STACK_LINE(6199)
		_t1 = (this->_t0 < (int)1);
		HX_STACK_LINE(6200)
		this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_decodeRuneInStringInternal_obj::run( ){
	HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::run","tardis/Go.hx",5969);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5969)
	while((true)){
		HX_STACK_LINE(5971)
		::tardis::_Go::Go_utf8_decodeRuneInStringInternal _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5971)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5973)
				{
					HX_STACK_LINE(5973)
					this->_latestPH = (int)656;
					HX_STACK_LINE(5973)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5974)
				{
					HX_STACK_LINE(5974)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(5974)
					this->_latestPH = (int)657;
					HX_STACK_LINE(5974)
					this->_t0 = ::tardis::Force_obj::toUTF8length(this->_goroutine,this->p_s);
					HX_STACK_LINE(5974)
					this->_latestPH = (int)658;
					HX_STACK_LINE(5974)
					_t1 = (this->_t0 < (int)1);
					HX_STACK_LINE(5974)
					this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(5977)
				{
					HX_STACK_LINE(5977)
					this->_latestPH = (int)656;
					HX_STACK_LINE(5977)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(5978)
				this->_latestPH = (int)659;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",5979);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)0,false);
							__result->Add(HX_CSTRING("r2") , true,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(5979)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(5980)
				this->_incomplete = false;
				HX_STACK_LINE(5981)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5982)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(5985)
				{
					HX_STACK_LINE(5985)
					this->_latestPH = (int)659;
					HX_STACK_LINE(5985)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(5986)
				{
					HX_STACK_LINE(5986)
					bool _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(5986)
					this->_latestPH = (int)661;
					HX_STACK_LINE(5986)
					this->_t2 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)0);
					HX_STACK_LINE(5986)
					this->_latestPH = (int)664;
					HX_STACK_LINE(5986)
					_t3 = (::tardis::Force_obj::uintCompare(this->_t2,(int)128) < (int)0);
					HX_STACK_LINE(5986)
					this->_Next = (  ((_t3)) ? int((int)3) : int((int)4) );
				}
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(5989)
				{
					HX_STACK_LINE(5989)
					this->_latestPH = (int)659;
					HX_STACK_LINE(5989)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(5990)
				{
					HX_STACK_LINE(5990)
					this->_latestPH = (int)665;
					HX_STACK_LINE(5990)
					this->_t4 = this->_t2;
				}
				HX_STACK_LINE(5991)
				this->_latestPH = (int)665;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",5992);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t4,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(5992)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(5993)
				this->_incomplete = false;
				HX_STACK_LINE(5994)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5995)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(5998)
				{
					HX_STACK_LINE(5998)
					this->_latestPH = (int)665;
					HX_STACK_LINE(5998)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(5999)
				{
					HX_STACK_LINE(5999)
					bool _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(5999)
					this->_latestPH = (int)669;
					HX_STACK_LINE(5999)
					_t5 = (::tardis::Force_obj::uintCompare(this->_t2,(int)192) < (int)0);
					HX_STACK_LINE(5999)
					this->_Next = (  ((_t5)) ? int((int)5) : int((int)6) );
				}
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(6002)
				{
					HX_STACK_LINE(6002)
					this->_latestPH = (int)665;
					HX_STACK_LINE(6002)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(6003)
				this->_latestPH = (int)670;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6004);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6004)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6005)
				this->_incomplete = false;
				HX_STACK_LINE(6006)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6007)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(6010)
				{
					HX_STACK_LINE(6010)
					this->_latestPH = (int)670;
					HX_STACK_LINE(6010)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(6011)
				{
					HX_STACK_LINE(6011)
					bool _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(6011)
					this->_latestPH = (int)674;
					HX_STACK_LINE(6011)
					_t6 = (this->_t0 < (int)2);
					HX_STACK_LINE(6011)
					this->_Next = (  ((_t6)) ? int((int)7) : int((int)8) );
				}
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(6014)
				{
					HX_STACK_LINE(6014)
					this->_latestPH = (int)670;
					HX_STACK_LINE(6014)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(6015)
				this->_latestPH = (int)675;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6016);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , true,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6016)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6017)
				this->_incomplete = false;
				HX_STACK_LINE(6018)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6019)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(6022)
				{
					HX_STACK_LINE(6022)
					this->_latestPH = (int)675;
					HX_STACK_LINE(6022)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(6023)
				{
					HX_STACK_LINE(6023)
					bool _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(6023)
					this->_latestPH = (int)677;
					HX_STACK_LINE(6023)
					this->_t7 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)1);
					HX_STACK_LINE(6023)
					this->_latestPH = (int)678;
					HX_STACK_LINE(6023)
					_t8 = (::tardis::Force_obj::uintCompare(this->_t7,(int)128) < (int)0);
					HX_STACK_LINE(6023)
					this->_Next = (  ((_t8)) ? int((int)9) : int((int)11) );
				}
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(6026)
				{
					HX_STACK_LINE(6026)
					this->_latestPH = (int)675;
					HX_STACK_LINE(6026)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(6027)
				this->_latestPH = (int)679;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6028);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6028)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6029)
				this->_incomplete = false;
				HX_STACK_LINE(6030)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6031)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(6034)
				{
					HX_STACK_LINE(6034)
					this->_latestPH = (int)679;
					HX_STACK_LINE(6034)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(6035)
				{
					HX_STACK_LINE(6035)
					bool _t9;		HX_STACK_VAR(_t9,"_t9");
					HX_STACK_LINE(6035)
					this->_latestPH = (int)683;
					HX_STACK_LINE(6035)
					_t9 = (::tardis::Force_obj::uintCompare(this->_t2,(int)224) < (int)0);
					HX_STACK_LINE(6035)
					this->_Next = (  ((_t9)) ? int((int)12) : int((int)13) );
				}
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(6038)
				{
					HX_STACK_LINE(6038)
					this->_latestPH = (int)679;
					HX_STACK_LINE(6038)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(6039)
				{
					HX_STACK_LINE(6039)
					bool _t10;		HX_STACK_VAR(_t10,"_t10");
					HX_STACK_LINE(6039)
					this->_latestPH = (int)678;
					HX_STACK_LINE(6039)
					_t10 = (::tardis::Force_obj::uintCompare((int)192,this->_t7) <= (int)0);
					HX_STACK_LINE(6039)
					this->_Next = (  ((_t10)) ? int((int)9) : int((int)10) );
				}
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(6042)
				{
					HX_STACK_LINE(6042)
					this->_latestPH = (int)679;
					HX_STACK_LINE(6042)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(6043)
				{
					HX_STACK_LINE(6043)
					int _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(6043)
					int _t12;		HX_STACK_VAR(_t12,"_t12");
					HX_STACK_LINE(6043)
					int _t13;		HX_STACK_VAR(_t13,"_t13");
					HX_STACK_LINE(6043)
					int _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(6043)
					int _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(6043)
					bool _t17;		HX_STACK_VAR(_t17,"_t17");
					HX_STACK_LINE(6043)
					this->_latestPH = (int)684;
					HX_STACK_LINE(6043)
					_t11 = (int((int(this->_t2) & int((int)31))) & int((int)255));
					HX_STACK_LINE(6043)
					_t12 = _t11;
					HX_STACK_LINE(6043)
					_t13 = (int(_t12) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(6043)
					_t14 = (int((int(this->_t7) & int((int)63))) & int((int)255));
					HX_STACK_LINE(6043)
					_t15 = _t14;
					HX_STACK_LINE(6043)
					this->_t16 = ::tardis::Force_obj::toInt32((int(_t13) | int(_t15)));
					HX_STACK_LINE(6043)
					this->_latestPH = (int)685;
					HX_STACK_LINE(6043)
					_t17 = (this->_t16 <= (int)127);
					HX_STACK_LINE(6043)
					this->_Next = (  ((_t17)) ? int((int)14) : int((int)15) );
				}
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(6046)
				{
					HX_STACK_LINE(6046)
					this->_latestPH = (int)679;
					HX_STACK_LINE(6046)
					this->_latestBlock = (int)13;
				}
				HX_STACK_LINE(6047)
				{
					HX_STACK_LINE(6047)
					bool _t18;		HX_STACK_VAR(_t18,"_t18");
					HX_STACK_LINE(6047)
					this->_latestPH = (int)692;
					HX_STACK_LINE(6047)
					_t18 = (this->_t0 < (int)3);
					HX_STACK_LINE(6047)
					this->_Next = (  ((_t18)) ? int((int)16) : int((int)17) );
				}
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(6050)
				{
					HX_STACK_LINE(6050)
					this->_latestPH = (int)679;
					HX_STACK_LINE(6050)
					this->_latestBlock = (int)14;
				}
				HX_STACK_LINE(6051)
				this->_latestPH = (int)686;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6052);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6052)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6053)
				this->_incomplete = false;
				HX_STACK_LINE(6054)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6055)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)15: {
				HX_STACK_LINE(6058)
				{
					HX_STACK_LINE(6058)
					this->_latestPH = (int)686;
					HX_STACK_LINE(6058)
					this->_latestBlock = (int)15;
				}
				HX_STACK_LINE(6059)
				this->_latestPH = (int)688;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6060);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t16,false);
							__result->Add(HX_CSTRING("r1") , (int)2,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6060)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(6061)
				this->_incomplete = false;
				HX_STACK_LINE(6062)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6063)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)16: {
				HX_STACK_LINE(6066)
				{
					HX_STACK_LINE(6066)
					this->_latestPH = (int)688;
					HX_STACK_LINE(6066)
					this->_latestBlock = (int)16;
				}
				HX_STACK_LINE(6067)
				this->_latestPH = (int)693;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6068);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , true,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6068)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6069)
				this->_incomplete = false;
				HX_STACK_LINE(6070)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6071)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)17: {
				HX_STACK_LINE(6074)
				{
					HX_STACK_LINE(6074)
					this->_latestPH = (int)693;
					HX_STACK_LINE(6074)
					this->_latestBlock = (int)17;
				}
				HX_STACK_LINE(6075)
				{
					HX_STACK_LINE(6075)
					bool _t20;		HX_STACK_VAR(_t20,"_t20");
					HX_STACK_LINE(6075)
					this->_latestPH = (int)695;
					HX_STACK_LINE(6075)
					this->_t19 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)2);
					HX_STACK_LINE(6075)
					this->_latestPH = (int)696;
					HX_STACK_LINE(6075)
					_t20 = (::tardis::Force_obj::uintCompare(this->_t19,(int)128) < (int)0);
					HX_STACK_LINE(6075)
					this->_Next = (  ((_t20)) ? int((int)18) : int((int)20) );
				}
			}
			;break;
			case (int)18: {
				HX_STACK_LINE(6078)
				{
					HX_STACK_LINE(6078)
					this->_latestPH = (int)693;
					HX_STACK_LINE(6078)
					this->_latestBlock = (int)18;
				}
				HX_STACK_LINE(6079)
				this->_latestPH = (int)697;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6080);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6080)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6081)
				this->_incomplete = false;
				HX_STACK_LINE(6082)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6083)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)19: {
				HX_STACK_LINE(6086)
				{
					HX_STACK_LINE(6086)
					this->_latestPH = (int)697;
					HX_STACK_LINE(6086)
					this->_latestBlock = (int)19;
				}
				HX_STACK_LINE(6087)
				{
					HX_STACK_LINE(6087)
					bool _t21;		HX_STACK_VAR(_t21,"_t21");
					HX_STACK_LINE(6087)
					this->_latestPH = (int)701;
					HX_STACK_LINE(6087)
					_t21 = (::tardis::Force_obj::uintCompare(this->_t2,(int)240) < (int)0);
					HX_STACK_LINE(6087)
					this->_Next = (  ((_t21)) ? int((int)21) : int((int)22) );
				}
			}
			;break;
			case (int)20: {
				HX_STACK_LINE(6090)
				{
					HX_STACK_LINE(6090)
					this->_latestPH = (int)697;
					HX_STACK_LINE(6090)
					this->_latestBlock = (int)20;
				}
				HX_STACK_LINE(6091)
				{
					HX_STACK_LINE(6091)
					bool _t22;		HX_STACK_VAR(_t22,"_t22");
					HX_STACK_LINE(6091)
					this->_latestPH = (int)696;
					HX_STACK_LINE(6091)
					_t22 = (::tardis::Force_obj::uintCompare((int)192,this->_t19) <= (int)0);
					HX_STACK_LINE(6091)
					this->_Next = (  ((_t22)) ? int((int)18) : int((int)19) );
				}
			}
			;break;
			case (int)21: {
				HX_STACK_LINE(6094)
				{
					HX_STACK_LINE(6094)
					this->_latestPH = (int)697;
					HX_STACK_LINE(6094)
					this->_latestBlock = (int)21;
				}
				HX_STACK_LINE(6095)
				{
					HX_STACK_LINE(6095)
					int _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(6095)
					int _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(6095)
					int _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(6095)
					int _t26;		HX_STACK_VAR(_t26,"_t26");
					HX_STACK_LINE(6095)
					int _t27;		HX_STACK_VAR(_t27,"_t27");
					HX_STACK_LINE(6095)
					int _t28;		HX_STACK_VAR(_t28,"_t28");
					HX_STACK_LINE(6095)
					int _t29;		HX_STACK_VAR(_t29,"_t29");
					HX_STACK_LINE(6095)
					int _t30;		HX_STACK_VAR(_t30,"_t30");
					HX_STACK_LINE(6095)
					int _t31;		HX_STACK_VAR(_t31,"_t31");
					HX_STACK_LINE(6095)
					bool _t33;		HX_STACK_VAR(_t33,"_t33");
					HX_STACK_LINE(6095)
					this->_latestPH = (int)702;
					HX_STACK_LINE(6095)
					_t23 = (int((int(this->_t2) & int((int)15))) & int((int)255));
					HX_STACK_LINE(6095)
					_t24 = _t23;
					HX_STACK_LINE(6095)
					_t25 = (int(_t24) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
					HX_STACK_LINE(6095)
					_t26 = (int((int(this->_t7) & int((int)63))) & int((int)255));
					HX_STACK_LINE(6095)
					_t27 = _t26;
					HX_STACK_LINE(6095)
					_t28 = (int(_t27) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(6095)
					_t29 = ::tardis::Force_obj::toInt32((int(_t25) | int(_t28)));
					HX_STACK_LINE(6095)
					_t30 = (int((int(this->_t19) & int((int)63))) & int((int)255));
					HX_STACK_LINE(6095)
					_t31 = _t30;
					HX_STACK_LINE(6095)
					this->_t32 = ::tardis::Force_obj::toInt32((int(_t29) | int(_t31)));
					HX_STACK_LINE(6095)
					this->_latestPH = (int)703;
					HX_STACK_LINE(6095)
					_t33 = (this->_t32 <= (int)2047);
					HX_STACK_LINE(6095)
					this->_Next = (  ((_t33)) ? int((int)23) : int((int)24) );
				}
			}
			;break;
			case (int)22: {
				HX_STACK_LINE(6098)
				{
					HX_STACK_LINE(6098)
					this->_latestPH = (int)697;
					HX_STACK_LINE(6098)
					this->_latestBlock = (int)22;
				}
				HX_STACK_LINE(6099)
				{
					HX_STACK_LINE(6099)
					bool _t34;		HX_STACK_VAR(_t34,"_t34");
					HX_STACK_LINE(6099)
					this->_latestPH = (int)713;
					HX_STACK_LINE(6099)
					_t34 = (this->_t0 < (int)4);
					HX_STACK_LINE(6099)
					this->_Next = (  ((_t34)) ? int((int)28) : int((int)29) );
				}
			}
			;break;
			case (int)23: {
				HX_STACK_LINE(6102)
				{
					HX_STACK_LINE(6102)
					this->_latestPH = (int)697;
					HX_STACK_LINE(6102)
					this->_latestBlock = (int)23;
				}
				HX_STACK_LINE(6103)
				this->_latestPH = (int)704;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6104);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6104)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6105)
				this->_incomplete = false;
				HX_STACK_LINE(6106)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6107)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)24: {
				HX_STACK_LINE(6110)
				{
					HX_STACK_LINE(6110)
					this->_latestPH = (int)704;
					HX_STACK_LINE(6110)
					this->_latestBlock = (int)24;
				}
				HX_STACK_LINE(6111)
				{
					HX_STACK_LINE(6111)
					bool _t35;		HX_STACK_VAR(_t35,"_t35");
					HX_STACK_LINE(6111)
					this->_latestPH = (int)706;
					HX_STACK_LINE(6111)
					_t35 = ((int)55296 <= this->_t32);
					HX_STACK_LINE(6111)
					this->_Next = (  ((_t35)) ? int((int)27) : int((int)26) );
				}
			}
			;break;
			case (int)25: {
				HX_STACK_LINE(6114)
				{
					HX_STACK_LINE(6114)
					this->_latestPH = (int)704;
					HX_STACK_LINE(6114)
					this->_latestBlock = (int)25;
				}
				HX_STACK_LINE(6115)
				this->_latestPH = (int)707;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6116);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6116)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6117)
				this->_incomplete = false;
				HX_STACK_LINE(6118)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6119)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)26: {
				HX_STACK_LINE(6122)
				{
					HX_STACK_LINE(6122)
					this->_latestPH = (int)707;
					HX_STACK_LINE(6122)
					this->_latestBlock = (int)26;
				}
				HX_STACK_LINE(6123)
				this->_latestPH = (int)709;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6124);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t32,false);
							__result->Add(HX_CSTRING("r1") , (int)3,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6124)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(6125)
				this->_incomplete = false;
				HX_STACK_LINE(6126)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6127)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)27: {
				HX_STACK_LINE(6130)
				{
					HX_STACK_LINE(6130)
					this->_latestPH = (int)709;
					HX_STACK_LINE(6130)
					this->_latestBlock = (int)27;
				}
				HX_STACK_LINE(6131)
				{
					HX_STACK_LINE(6131)
					bool _t36;		HX_STACK_VAR(_t36,"_t36");
					HX_STACK_LINE(6131)
					_t36 = (this->_t32 <= (int)57343);
					HX_STACK_LINE(6131)
					this->_Next = (  ((_t36)) ? int((int)25) : int((int)26) );
				}
			}
			;break;
			case (int)28: {
				HX_STACK_LINE(6134)
				{
					HX_STACK_LINE(6134)
					this->_latestPH = (int)709;
					HX_STACK_LINE(6134)
					this->_latestBlock = (int)28;
				}
				HX_STACK_LINE(6135)
				this->_latestPH = (int)714;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6136);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , true,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6136)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6137)
				this->_incomplete = false;
				HX_STACK_LINE(6138)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6139)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)29: {
				HX_STACK_LINE(6142)
				{
					HX_STACK_LINE(6142)
					this->_latestPH = (int)714;
					HX_STACK_LINE(6142)
					this->_latestBlock = (int)29;
				}
				HX_STACK_LINE(6143)
				{
					HX_STACK_LINE(6143)
					bool _t38;		HX_STACK_VAR(_t38,"_t38");
					HX_STACK_LINE(6143)
					this->_latestPH = (int)716;
					HX_STACK_LINE(6143)
					this->_t37 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt((int)3);
					HX_STACK_LINE(6143)
					this->_latestPH = (int)717;
					HX_STACK_LINE(6143)
					_t38 = (::tardis::Force_obj::uintCompare(this->_t37,(int)128) < (int)0);
					HX_STACK_LINE(6143)
					this->_Next = (  ((_t38)) ? int((int)30) : int((int)32) );
				}
			}
			;break;
			case (int)30: {
				HX_STACK_LINE(6146)
				{
					HX_STACK_LINE(6146)
					this->_latestPH = (int)714;
					HX_STACK_LINE(6146)
					this->_latestBlock = (int)30;
				}
				HX_STACK_LINE(6147)
				this->_latestPH = (int)718;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6148);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6148)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6149)
				this->_incomplete = false;
				HX_STACK_LINE(6150)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6151)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)31: {
				HX_STACK_LINE(6154)
				{
					HX_STACK_LINE(6154)
					this->_latestPH = (int)718;
					HX_STACK_LINE(6154)
					this->_latestBlock = (int)31;
				}
				HX_STACK_LINE(6155)
				{
					HX_STACK_LINE(6155)
					bool _t39;		HX_STACK_VAR(_t39,"_t39");
					HX_STACK_LINE(6155)
					this->_latestPH = (int)722;
					HX_STACK_LINE(6155)
					_t39 = (::tardis::Force_obj::uintCompare(this->_t2,(int)248) < (int)0);
					HX_STACK_LINE(6155)
					this->_Next = (  ((_t39)) ? int((int)33) : int((int)34) );
				}
			}
			;break;
			case (int)32: {
				HX_STACK_LINE(6158)
				{
					HX_STACK_LINE(6158)
					this->_latestPH = (int)718;
					HX_STACK_LINE(6158)
					this->_latestBlock = (int)32;
				}
				HX_STACK_LINE(6159)
				{
					HX_STACK_LINE(6159)
					bool _t40;		HX_STACK_VAR(_t40,"_t40");
					HX_STACK_LINE(6159)
					this->_latestPH = (int)717;
					HX_STACK_LINE(6159)
					_t40 = (::tardis::Force_obj::uintCompare((int)192,this->_t37) <= (int)0);
					HX_STACK_LINE(6159)
					this->_Next = (  ((_t40)) ? int((int)30) : int((int)31) );
				}
			}
			;break;
			case (int)33: {
				HX_STACK_LINE(6162)
				{
					HX_STACK_LINE(6162)
					this->_latestPH = (int)718;
					HX_STACK_LINE(6162)
					this->_latestBlock = (int)33;
				}
				HX_STACK_LINE(6163)
				{
					HX_STACK_LINE(6163)
					int _t41;		HX_STACK_VAR(_t41,"_t41");
					HX_STACK_LINE(6163)
					int _t42;		HX_STACK_VAR(_t42,"_t42");
					HX_STACK_LINE(6163)
					int _t43;		HX_STACK_VAR(_t43,"_t43");
					HX_STACK_LINE(6163)
					int _t44;		HX_STACK_VAR(_t44,"_t44");
					HX_STACK_LINE(6163)
					int _t45;		HX_STACK_VAR(_t45,"_t45");
					HX_STACK_LINE(6163)
					int _t46;		HX_STACK_VAR(_t46,"_t46");
					HX_STACK_LINE(6163)
					int _t47;		HX_STACK_VAR(_t47,"_t47");
					HX_STACK_LINE(6163)
					int _t48;		HX_STACK_VAR(_t48,"_t48");
					HX_STACK_LINE(6163)
					int _t49;		HX_STACK_VAR(_t49,"_t49");
					HX_STACK_LINE(6163)
					int _t50;		HX_STACK_VAR(_t50,"_t50");
					HX_STACK_LINE(6163)
					int _t51;		HX_STACK_VAR(_t51,"_t51");
					HX_STACK_LINE(6163)
					int _t52;		HX_STACK_VAR(_t52,"_t52");
					HX_STACK_LINE(6163)
					int _t53;		HX_STACK_VAR(_t53,"_t53");
					HX_STACK_LINE(6163)
					bool _t55;		HX_STACK_VAR(_t55,"_t55");
					HX_STACK_LINE(6163)
					this->_latestPH = (int)723;
					HX_STACK_LINE(6163)
					_t41 = (int((int(this->_t2) & int((int)7))) & int((int)255));
					HX_STACK_LINE(6163)
					_t42 = _t41;
					HX_STACK_LINE(6163)
					_t43 = (int(_t42) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)18))));
					HX_STACK_LINE(6163)
					_t44 = (int((int(this->_t7) & int((int)63))) & int((int)255));
					HX_STACK_LINE(6163)
					_t45 = _t44;
					HX_STACK_LINE(6163)
					_t46 = (int(_t45) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
					HX_STACK_LINE(6163)
					_t47 = ::tardis::Force_obj::toInt32((int(_t43) | int(_t46)));
					HX_STACK_LINE(6163)
					_t48 = (int((int(this->_t19) & int((int)63))) & int((int)255));
					HX_STACK_LINE(6163)
					_t49 = _t48;
					HX_STACK_LINE(6163)
					_t50 = (int(_t49) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(6163)
					_t51 = ::tardis::Force_obj::toInt32((int(_t47) | int(_t50)));
					HX_STACK_LINE(6163)
					_t52 = (int((int(this->_t37) & int((int)63))) & int((int)255));
					HX_STACK_LINE(6163)
					_t53 = _t52;
					HX_STACK_LINE(6163)
					this->_t54 = ::tardis::Force_obj::toInt32((int(_t51) | int(_t53)));
					HX_STACK_LINE(6163)
					this->_latestPH = (int)724;
					HX_STACK_LINE(6163)
					_t55 = (this->_t54 <= (int)65535);
					HX_STACK_LINE(6163)
					this->_Next = (  ((_t55)) ? int((int)35) : int((int)37) );
				}
			}
			;break;
			case (int)34: {
				HX_STACK_LINE(6166)
				{
					HX_STACK_LINE(6166)
					this->_latestPH = (int)718;
					HX_STACK_LINE(6166)
					this->_latestBlock = (int)34;
				}
				HX_STACK_LINE(6167)
				this->_latestPH = (int)731;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6168);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6168)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6169)
				this->_incomplete = false;
				HX_STACK_LINE(6170)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6171)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)35: {
				HX_STACK_LINE(6174)
				{
					HX_STACK_LINE(6174)
					this->_latestPH = (int)731;
					HX_STACK_LINE(6174)
					this->_latestBlock = (int)35;
				}
				HX_STACK_LINE(6175)
				this->_latestPH = (int)725;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6176);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6176)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(6177)
				this->_incomplete = false;
				HX_STACK_LINE(6178)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6179)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)36: {
				HX_STACK_LINE(6182)
				{
					HX_STACK_LINE(6182)
					this->_latestPH = (int)725;
					HX_STACK_LINE(6182)
					this->_latestBlock = (int)36;
				}
				HX_STACK_LINE(6183)
				this->_latestPH = (int)727;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",6184);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t54,false);
							__result->Add(HX_CSTRING("r1") , (int)4,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(6184)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(6185)
				this->_incomplete = false;
				HX_STACK_LINE(6186)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6187)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)37: {
				HX_STACK_LINE(6190)
				{
					HX_STACK_LINE(6190)
					this->_latestPH = (int)727;
					HX_STACK_LINE(6190)
					this->_latestBlock = (int)37;
				}
				HX_STACK_LINE(6191)
				{
					HX_STACK_LINE(6191)
					bool _t56;		HX_STACK_VAR(_t56,"_t56");
					HX_STACK_LINE(6191)
					_t56 = ((int)1114111 < this->_t54);
					HX_STACK_LINE(6191)
					this->_Next = (  ((_t56)) ? int((int)35) : int((int)36) );
				}
			}
			;break;
			default: {
				HX_STACK_LINE(6193)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5969)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,run,return )

Dynamic Go_utf8_decodeRuneInStringInternal_obj::res( ){
	HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::res","tardis/Go.hx",5896);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5896)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInStringInternal_obj,res,return )

Dynamic Go_utf8_decodeRuneInStringInternal_obj::callFromHaxe( ::String p_s){
	HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::callFromHaxe","tardis/Go.hx",5955);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(5956)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5956)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5957)
	::tardis::_Go::Go_utf8_decodeRuneInStringInternal _sf = hx::TCast< ::tardis::_Go::Go_utf8_decodeRuneInStringInternal >::cast(::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5958)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5958)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5959)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_decodeRuneInStringInternal_obj,callFromHaxe,return )

Dynamic Go_utf8_decodeRuneInStringInternal_obj::callFromRT( int _gr,::String p_s){
	HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::callFromRT","tardis/Go.hx",5961);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(5962)
	::tardis::_Go::Go_utf8_decodeRuneInStringInternal _sf = hx::TCast< ::tardis::_Go::Go_utf8_decodeRuneInStringInternal >::cast(::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5963)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5963)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5963)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5963)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5963)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5964)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_decodeRuneInStringInternal_obj,callFromRT,return )

::tardis::_Go::Go_utf8_decodeRuneInStringInternal Go_utf8_decodeRuneInStringInternal_obj::call( int gr,Dynamic _bds,::String p_s){
	HX_STACK_PUSH("Go_utf8_decodeRuneInStringInternal::call","tardis/Go.hx",5967);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(5967)
	return ::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_decodeRuneInStringInternal_obj,call,return )


Go_utf8_decodeRuneInStringInternal_obj::Go_utf8_decodeRuneInStringInternal_obj()
{
}

void Go_utf8_decodeRuneInStringInternal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_decodeRuneInStringInternal);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t56,"_t56");
	HX_MARK_MEMBER_NAME(_t55,"_t55");
	HX_MARK_MEMBER_NAME(_t54,"_t54");
	HX_MARK_MEMBER_NAME(_t53,"_t53");
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
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_decodeRuneInStringInternal_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t56,"_t56");
	HX_VISIT_MEMBER_NAME(_t55,"_t55");
	HX_VISIT_MEMBER_NAME(_t54,"_t54");
	HX_VISIT_MEMBER_NAME(_t53,"_t53");
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
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_decodeRuneInStringInternal_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_t56") ) { return _t56; }
		if (HX_FIELD_EQ(inName,"_t55") ) { return _t55; }
		if (HX_FIELD_EQ(inName,"_t54") ) { return _t54; }
		if (HX_FIELD_EQ(inName,"_t53") ) { return _t53; }
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
		if (HX_FIELD_EQ(inName,"SubFn21") ) { return SubFn21_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn20") ) { return SubFn20_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn19") ) { return SubFn19_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn18") ) { return SubFn18_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn17") ) { return SubFn17_dyn(); }
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

Dynamic Go_utf8_decodeRuneInStringInternal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_t56") ) { _t56=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t55") ) { _t55=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t54") ) { _t54=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t53") ) { _t53=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t52") ) { _t52=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t51") ) { _t51=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t50") ) { _t50=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t49") ) { _t49=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t48") ) { _t48=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t47") ) { _t47=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t46") ) { _t46=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t45") ) { _t45=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t44") ) { _t44=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t43") ) { _t43=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t42") ) { _t42=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t41") ) { _t41=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t40") ) { _t40=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t39") ) { _t39=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t38") ) { _t38=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t37") ) { _t37=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t36") ) { _t36=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t35") ) { _t35=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t34") ) { _t34=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t33") ) { _t33=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t32") ) { _t32=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t31") ) { _t31=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t30") ) { _t30=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t29") ) { _t29=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t28") ) { _t28=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t27") ) { _t27=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t26") ) { _t26=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_decodeRuneInStringInternal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t56"));
	outFields->push(HX_CSTRING("_t55"));
	outFields->push(HX_CSTRING("_t54"));
	outFields->push(HX_CSTRING("_t53"));
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
	outFields->push(HX_CSTRING("p_s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn21"),
	HX_CSTRING("SubFn20"),
	HX_CSTRING("SubFn19"),
	HX_CSTRING("SubFn18"),
	HX_CSTRING("SubFn17"),
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
	HX_CSTRING("_t56"),
	HX_CSTRING("_t55"),
	HX_CSTRING("_t54"),
	HX_CSTRING("_t53"),
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
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_decodeRuneInStringInternal_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_decodeRuneInStringInternal_obj::__mClass,"__mClass");
};

Class Go_utf8_decodeRuneInStringInternal_obj::__mClass;

void Go_utf8_decodeRuneInStringInternal_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_utf8_decodeRuneInStringInternal"), hx::TCanCast< Go_utf8_decodeRuneInStringInternal_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_decodeRuneInStringInternal_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
