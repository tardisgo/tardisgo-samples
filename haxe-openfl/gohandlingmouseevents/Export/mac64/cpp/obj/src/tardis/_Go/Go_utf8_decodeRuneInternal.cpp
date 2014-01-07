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
#ifndef INCLUDED_tardis__Go_Go_utf8_decodeRuneInternal
#include <tardis/_Go/Go_utf8_decodeRuneInternal.h>
#endif
namespace tardis{
namespace _Go{

Void Go_utf8_decodeRuneInternal_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_p)
{
HX_STACK_PUSH("Go_utf8_decodeRuneInternal::new","tardis/Go.hx",4441);
{
	HX_STACK_LINE(4512)
	this->_Next = (int)0;
	HX_STACK_LINE(4511)
	this->_t60 = false;
	HX_STACK_LINE(4510)
	this->_t59 = false;
	HX_STACK_LINE(4509)
	this->_t58 = (int)0;
	HX_STACK_LINE(4508)
	this->_t57 = (int)0;
	HX_STACK_LINE(4507)
	this->_t56 = (int)0;
	HX_STACK_LINE(4506)
	this->_t55 = (int)0;
	HX_STACK_LINE(4505)
	this->_t54 = (int)0;
	HX_STACK_LINE(4504)
	this->_t53 = (int)0;
	HX_STACK_LINE(4503)
	this->_t52 = (int)0;
	HX_STACK_LINE(4502)
	this->_t51 = (int)0;
	HX_STACK_LINE(4501)
	this->_t50 = (int)0;
	HX_STACK_LINE(4500)
	this->_t49 = (int)0;
	HX_STACK_LINE(4499)
	this->_t48 = (int)0;
	HX_STACK_LINE(4498)
	this->_t47 = (int)0;
	HX_STACK_LINE(4497)
	this->_t46 = (int)0;
	HX_STACK_LINE(4496)
	this->_t45 = (int)0;
	HX_STACK_LINE(4495)
	this->_t44 = false;
	HX_STACK_LINE(4494)
	this->_t43 = false;
	HX_STACK_LINE(4493)
	this->_t42 = false;
	HX_STACK_LINE(4492)
	this->_t41 = (int)0;
	HX_STACK_LINE(4491)
	this->_t40 = null();
	HX_STACK_LINE(4490)
	this->_t39 = false;
	HX_STACK_LINE(4489)
	this->_t38 = false;
	HX_STACK_LINE(4488)
	this->_t37 = false;
	HX_STACK_LINE(4487)
	this->_t36 = false;
	HX_STACK_LINE(4486)
	this->_t35 = (int)0;
	HX_STACK_LINE(4485)
	this->_t34 = (int)0;
	HX_STACK_LINE(4484)
	this->_t33 = (int)0;
	HX_STACK_LINE(4483)
	this->_t32 = (int)0;
	HX_STACK_LINE(4482)
	this->_t31 = (int)0;
	HX_STACK_LINE(4481)
	this->_t30 = (int)0;
	HX_STACK_LINE(4480)
	this->_t29 = (int)0;
	HX_STACK_LINE(4479)
	this->_t28 = (int)0;
	HX_STACK_LINE(4478)
	this->_t27 = (int)0;
	HX_STACK_LINE(4477)
	this->_t26 = (int)0;
	HX_STACK_LINE(4476)
	this->_t25 = false;
	HX_STACK_LINE(4475)
	this->_t24 = false;
	HX_STACK_LINE(4474)
	this->_t23 = false;
	HX_STACK_LINE(4473)
	this->_t22 = (int)0;
	HX_STACK_LINE(4472)
	this->_t21 = null();
	HX_STACK_LINE(4471)
	this->_t20 = false;
	HX_STACK_LINE(4470)
	this->_t19 = false;
	HX_STACK_LINE(4469)
	this->_t18 = (int)0;
	HX_STACK_LINE(4468)
	this->_t17 = (int)0;
	HX_STACK_LINE(4467)
	this->_t16 = (int)0;
	HX_STACK_LINE(4466)
	this->_t15 = (int)0;
	HX_STACK_LINE(4465)
	this->_t14 = (int)0;
	HX_STACK_LINE(4464)
	this->_t13 = (int)0;
	HX_STACK_LINE(4463)
	this->_t12 = false;
	HX_STACK_LINE(4462)
	this->_t11 = false;
	HX_STACK_LINE(4461)
	this->_t10 = false;
	HX_STACK_LINE(4460)
	this->_t9 = (int)0;
	HX_STACK_LINE(4459)
	this->_t8 = null();
	HX_STACK_LINE(4458)
	this->_t7 = false;
	HX_STACK_LINE(4457)
	this->_t6 = false;
	HX_STACK_LINE(4456)
	this->_t5 = (int)0;
	HX_STACK_LINE(4455)
	this->_t4 = false;
	HX_STACK_LINE(4454)
	this->_t3 = (int)0;
	HX_STACK_LINE(4453)
	this->_t2 = null();
	HX_STACK_LINE(4452)
	this->_t1 = false;
	HX_STACK_LINE(4451)
	this->_t0 = (int)0;
	HX_STACK_LINE(4444)
	super::__construct(gr,(int)578,HX_CSTRING("Go_utf8_decodeRuneInternal"));
	HX_STACK_LINE(4445)
	this->_bds = _bds;
	HX_STACK_LINE(4446)
	this->p_p = p_p;
	HX_STACK_LINE(4447)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_decodeRuneInternal_obj::~Go_utf8_decodeRuneInternal_obj() { }

Dynamic Go_utf8_decodeRuneInternal_obj::__CreateEmpty() { return  new Go_utf8_decodeRuneInternal_obj; }
hx::ObjectPtr< Go_utf8_decodeRuneInternal_obj > Go_utf8_decodeRuneInternal_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_p)
{  hx::ObjectPtr< Go_utf8_decodeRuneInternal_obj > result = new Go_utf8_decodeRuneInternal_obj();
	result->__construct(gr,_bds,p_p);
	return result;}

Dynamic Go_utf8_decodeRuneInternal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_decodeRuneInternal_obj > result = new Go_utf8_decodeRuneInternal_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_decodeRuneInternal_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_decodeRuneInternal_obj::SubFn21( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn21","tardis/Go.hx",4957);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4958)
		bool _t60;		HX_STACK_VAR(_t60,"_t60");
		HX_STACK_LINE(4959)
		_t60 = ((int)1114111 < this->_t58);
		HX_STACK_LINE(4960)
		this->_Next = (  ((_t60)) ? int((int)35) : int((int)36) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn21,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn20( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn20","tardis/Go.hx",4923);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4924)
		int _t45;		HX_STACK_VAR(_t45,"_t45");
		HX_STACK_LINE(4925)
		int _t46;		HX_STACK_VAR(_t46,"_t46");
		HX_STACK_LINE(4926)
		int _t47;		HX_STACK_VAR(_t47,"_t47");
		HX_STACK_LINE(4927)
		int _t48;		HX_STACK_VAR(_t48,"_t48");
		HX_STACK_LINE(4928)
		int _t49;		HX_STACK_VAR(_t49,"_t49");
		HX_STACK_LINE(4929)
		int _t50;		HX_STACK_VAR(_t50,"_t50");
		HX_STACK_LINE(4930)
		int _t51;		HX_STACK_VAR(_t51,"_t51");
		HX_STACK_LINE(4931)
		int _t52;		HX_STACK_VAR(_t52,"_t52");
		HX_STACK_LINE(4932)
		int _t53;		HX_STACK_VAR(_t53,"_t53");
		HX_STACK_LINE(4933)
		int _t54;		HX_STACK_VAR(_t54,"_t54");
		HX_STACK_LINE(4934)
		int _t55;		HX_STACK_VAR(_t55,"_t55");
		HX_STACK_LINE(4935)
		int _t56;		HX_STACK_VAR(_t56,"_t56");
		HX_STACK_LINE(4936)
		int _t57;		HX_STACK_VAR(_t57,"_t57");
		HX_STACK_LINE(4937)
		bool _t59;		HX_STACK_VAR(_t59,"_t59");
		HX_STACK_LINE(4938)
		this->_latestPH = (int)645;
		HX_STACK_LINE(4939)
		_t45 = (int((int(this->_t3) & int((int)7))) & int((int)255));
		HX_STACK_LINE(4940)
		_t46 = _t45;
		HX_STACK_LINE(4941)
		_t47 = (int(_t46) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)18))));
		HX_STACK_LINE(4942)
		_t48 = (int((int(this->_t9) & int((int)63))) & int((int)255));
		HX_STACK_LINE(4943)
		_t49 = _t48;
		HX_STACK_LINE(4944)
		_t50 = (int(_t49) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
		HX_STACK_LINE(4945)
		_t51 = ::tardis::Force_obj::toInt32((int(_t47) | int(_t50)));
		HX_STACK_LINE(4946)
		_t52 = (int((int(this->_t22) & int((int)63))) & int((int)255));
		HX_STACK_LINE(4947)
		_t53 = _t52;
		HX_STACK_LINE(4948)
		_t54 = (int(_t53) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(4949)
		_t55 = ::tardis::Force_obj::toInt32((int(_t51) | int(_t54)));
		HX_STACK_LINE(4950)
		_t56 = (int((int(this->_t41) & int((int)63))) & int((int)255));
		HX_STACK_LINE(4951)
		_t57 = _t56;
		HX_STACK_LINE(4952)
		this->_t58 = ::tardis::Force_obj::toInt32((int(_t55) | int(_t57)));
		HX_STACK_LINE(4953)
		this->_latestPH = (int)646;
		HX_STACK_LINE(4954)
		_t59 = (this->_t58 <= (int)65535);
		HX_STACK_LINE(4955)
		this->_Next = (  ((_t59)) ? int((int)35) : int((int)37) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn20,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn19( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn19","tardis/Go.hx",4917);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4918)
		bool _t44;		HX_STACK_VAR(_t44,"_t44");
		HX_STACK_LINE(4919)
		this->_latestPH = (int)639;
		HX_STACK_LINE(4920)
		_t44 = (::tardis::Force_obj::uintCompare((int)192,this->_t41) <= (int)0);
		HX_STACK_LINE(4921)
		this->_Next = (  ((_t44)) ? int((int)30) : int((int)31) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn19,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn18( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn18","tardis/Go.hx",4911);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4912)
		bool _t43;		HX_STACK_VAR(_t43,"_t43");
		HX_STACK_LINE(4913)
		this->_latestPH = (int)644;
		HX_STACK_LINE(4914)
		_t43 = (::tardis::Force_obj::uintCompare(this->_t3,(int)248) < (int)0);
		HX_STACK_LINE(4915)
		this->_Next = (  ((_t43)) ? int((int)33) : int((int)34) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn18,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn17( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn17","tardis/Go.hx",4900);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4901)
		::tardis::Pointer _t40;		HX_STACK_VAR(_t40,"_t40");
		HX_STACK_LINE(4902)
		bool _t42;		HX_STACK_VAR(_t42,"_t42");
		HX_STACK_LINE(4903)
		this->_latestPH = (int)638;
		struct _Function_1_1{
			inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4904);
				{
					HX_STACK_LINE(4904)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4904)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4904)
		if ((((int)3 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(4904)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4905)
		_t40 = this->p_p->addr((int)3);
		HX_STACK_LINE(4906)
		this->_t41 = (int(_t40->ref()) | int((int)0));
		HX_STACK_LINE(4907)
		this->_latestPH = (int)639;
		HX_STACK_LINE(4908)
		_t42 = (::tardis::Force_obj::uintCompare(this->_t41,(int)128) < (int)0);
		HX_STACK_LINE(4909)
		this->_Next = (  ((_t42)) ? int((int)30) : int((int)32) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn17,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn16( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn16","tardis/Go.hx",4895);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4896)
		bool _t39;		HX_STACK_VAR(_t39,"_t39");
		HX_STACK_LINE(4897)
		_t39 = (this->_t35 <= (int)57343);
		HX_STACK_LINE(4898)
		this->_Next = (  ((_t39)) ? int((int)25) : int((int)26) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn16,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn15( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn15","tardis/Go.hx",4889);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4890)
		bool _t38;		HX_STACK_VAR(_t38,"_t38");
		HX_STACK_LINE(4891)
		this->_latestPH = (int)628;
		HX_STACK_LINE(4892)
		_t38 = ((int)55296 <= this->_t35);
		HX_STACK_LINE(4893)
		this->_Next = (  ((_t38)) ? int((int)27) : int((int)26) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn15,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn14( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn14","tardis/Go.hx",4883);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4884)
		bool _t37;		HX_STACK_VAR(_t37,"_t37");
		HX_STACK_LINE(4885)
		this->_latestPH = (int)635;
		HX_STACK_LINE(4886)
		_t37 = (this->_t0 < (int)4);
		HX_STACK_LINE(4887)
		this->_Next = (  ((_t37)) ? int((int)28) : int((int)29) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn14,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn13( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn13","tardis/Go.hx",4857);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4858)
		int _t26;		HX_STACK_VAR(_t26,"_t26");
		HX_STACK_LINE(4859)
		int _t27;		HX_STACK_VAR(_t27,"_t27");
		HX_STACK_LINE(4860)
		int _t28;		HX_STACK_VAR(_t28,"_t28");
		HX_STACK_LINE(4861)
		int _t29;		HX_STACK_VAR(_t29,"_t29");
		HX_STACK_LINE(4862)
		int _t30;		HX_STACK_VAR(_t30,"_t30");
		HX_STACK_LINE(4863)
		int _t31;		HX_STACK_VAR(_t31,"_t31");
		HX_STACK_LINE(4864)
		int _t32;		HX_STACK_VAR(_t32,"_t32");
		HX_STACK_LINE(4865)
		int _t33;		HX_STACK_VAR(_t33,"_t33");
		HX_STACK_LINE(4866)
		int _t34;		HX_STACK_VAR(_t34,"_t34");
		HX_STACK_LINE(4867)
		bool _t36;		HX_STACK_VAR(_t36,"_t36");
		HX_STACK_LINE(4868)
		this->_latestPH = (int)624;
		HX_STACK_LINE(4869)
		_t26 = (int((int(this->_t3) & int((int)15))) & int((int)255));
		HX_STACK_LINE(4870)
		_t27 = _t26;
		HX_STACK_LINE(4871)
		_t28 = (int(_t27) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
		HX_STACK_LINE(4872)
		_t29 = (int((int(this->_t9) & int((int)63))) & int((int)255));
		HX_STACK_LINE(4873)
		_t30 = _t29;
		HX_STACK_LINE(4874)
		_t31 = (int(_t30) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(4875)
		_t32 = ::tardis::Force_obj::toInt32((int(_t28) | int(_t31)));
		HX_STACK_LINE(4876)
		_t33 = (int((int(this->_t22) & int((int)63))) & int((int)255));
		HX_STACK_LINE(4877)
		_t34 = _t33;
		HX_STACK_LINE(4878)
		this->_t35 = ::tardis::Force_obj::toInt32((int(_t32) | int(_t34)));
		HX_STACK_LINE(4879)
		this->_latestPH = (int)625;
		HX_STACK_LINE(4880)
		_t36 = (this->_t35 <= (int)2047);
		HX_STACK_LINE(4881)
		this->_Next = (  ((_t36)) ? int((int)23) : int((int)24) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn13,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn12( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn12","tardis/Go.hx",4851);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4852)
		bool _t25;		HX_STACK_VAR(_t25,"_t25");
		HX_STACK_LINE(4853)
		this->_latestPH = (int)618;
		HX_STACK_LINE(4854)
		_t25 = (::tardis::Force_obj::uintCompare((int)192,this->_t22) <= (int)0);
		HX_STACK_LINE(4855)
		this->_Next = (  ((_t25)) ? int((int)18) : int((int)19) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn12,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn11( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn11","tardis/Go.hx",4845);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4846)
		bool _t24;		HX_STACK_VAR(_t24,"_t24");
		HX_STACK_LINE(4847)
		this->_latestPH = (int)623;
		HX_STACK_LINE(4848)
		_t24 = (::tardis::Force_obj::uintCompare(this->_t3,(int)240) < (int)0);
		HX_STACK_LINE(4849)
		this->_Next = (  ((_t24)) ? int((int)21) : int((int)22) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn11,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn10( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn10","tardis/Go.hx",4834);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4835)
		::tardis::Pointer _t21;		HX_STACK_VAR(_t21,"_t21");
		HX_STACK_LINE(4836)
		bool _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(4837)
		this->_latestPH = (int)617;
		struct _Function_1_1{
			inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4838);
				{
					HX_STACK_LINE(4838)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4838)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4838)
		if ((((int)2 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(4838)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4839)
		_t21 = this->p_p->addr((int)2);
		HX_STACK_LINE(4840)
		this->_t22 = (int(_t21->ref()) | int((int)0));
		HX_STACK_LINE(4841)
		this->_latestPH = (int)618;
		HX_STACK_LINE(4842)
		_t23 = (::tardis::Force_obj::uintCompare(this->_t22,(int)128) < (int)0);
		HX_STACK_LINE(4843)
		this->_Next = (  ((_t23)) ? int((int)18) : int((int)20) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn10,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn9","tardis/Go.hx",4828);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4829)
		bool _t20;		HX_STACK_VAR(_t20,"_t20");
		HX_STACK_LINE(4830)
		this->_latestPH = (int)614;
		HX_STACK_LINE(4831)
		_t20 = (this->_t0 < (int)3);
		HX_STACK_LINE(4832)
		this->_Next = (  ((_t20)) ? int((int)16) : int((int)17) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn9,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn8","tardis/Go.hx",4810);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4811)
		int _t13;		HX_STACK_VAR(_t13,"_t13");
		HX_STACK_LINE(4812)
		int _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(4813)
		int _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(4814)
		int _t16;		HX_STACK_VAR(_t16,"_t16");
		HX_STACK_LINE(4815)
		int _t17;		HX_STACK_VAR(_t17,"_t17");
		HX_STACK_LINE(4816)
		bool _t19;		HX_STACK_VAR(_t19,"_t19");
		HX_STACK_LINE(4817)
		this->_latestPH = (int)606;
		HX_STACK_LINE(4818)
		_t13 = (int((int(this->_t3) & int((int)31))) & int((int)255));
		HX_STACK_LINE(4819)
		_t14 = _t13;
		HX_STACK_LINE(4820)
		_t15 = (int(_t14) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
		HX_STACK_LINE(4821)
		_t16 = (int((int(this->_t9) & int((int)63))) & int((int)255));
		HX_STACK_LINE(4822)
		_t17 = _t16;
		HX_STACK_LINE(4823)
		this->_t18 = ::tardis::Force_obj::toInt32((int(_t15) | int(_t17)));
		HX_STACK_LINE(4824)
		this->_latestPH = (int)607;
		HX_STACK_LINE(4825)
		_t19 = (this->_t18 <= (int)127);
		HX_STACK_LINE(4826)
		this->_Next = (  ((_t19)) ? int((int)14) : int((int)15) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn8,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn7","tardis/Go.hx",4804);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4805)
		bool _t12;		HX_STACK_VAR(_t12,"_t12");
		HX_STACK_LINE(4806)
		this->_latestPH = (int)600;
		HX_STACK_LINE(4807)
		_t12 = (::tardis::Force_obj::uintCompare((int)192,this->_t9) <= (int)0);
		HX_STACK_LINE(4808)
		this->_Next = (  ((_t12)) ? int((int)9) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn7,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn6","tardis/Go.hx",4798);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4799)
		bool _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(4800)
		this->_latestPH = (int)605;
		HX_STACK_LINE(4801)
		_t11 = (::tardis::Force_obj::uintCompare(this->_t3,(int)224) < (int)0);
		HX_STACK_LINE(4802)
		this->_Next = (  ((_t11)) ? int((int)12) : int((int)13) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn6,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn5","tardis/Go.hx",4787);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4788)
		::tardis::Pointer _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(4789)
		bool _t10;		HX_STACK_VAR(_t10,"_t10");
		HX_STACK_LINE(4790)
		this->_latestPH = (int)599;
		struct _Function_1_1{
			inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4791);
				{
					HX_STACK_LINE(4791)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4791)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4791)
		if ((((int)1 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(4791)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4792)
		_t8 = this->p_p->addr((int)1);
		HX_STACK_LINE(4793)
		this->_t9 = (int(_t8->ref()) | int((int)0));
		HX_STACK_LINE(4794)
		this->_latestPH = (int)600;
		HX_STACK_LINE(4795)
		_t10 = (::tardis::Force_obj::uintCompare(this->_t9,(int)128) < (int)0);
		HX_STACK_LINE(4796)
		this->_Next = (  ((_t10)) ? int((int)9) : int((int)11) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn5,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn4","tardis/Go.hx",4781);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4782)
		bool _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(4783)
		this->_latestPH = (int)596;
		HX_STACK_LINE(4784)
		_t7 = (this->_t0 < (int)2);
		HX_STACK_LINE(4785)
		this->_Next = (  ((_t7)) ? int((int)7) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn4,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn3","tardis/Go.hx",4775);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4776)
		bool _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(4777)
		this->_latestPH = (int)591;
		HX_STACK_LINE(4778)
		_t6 = (::tardis::Force_obj::uintCompare(this->_t3,(int)192) < (int)0);
		HX_STACK_LINE(4779)
		this->_Next = (  ((_t6)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn3,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn2","tardis/Go.hx",4771);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4772)
		this->_latestPH = (int)587;
		HX_STACK_LINE(4773)
		this->_t5 = this->_t3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn2,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn1","tardis/Go.hx",4760);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4761)
		::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(4762)
		bool _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(4763)
		this->_latestPH = (int)583;
		struct _Function_1_1{
			inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4764);
				{
					HX_STACK_LINE(4764)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(4764)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(4764)
		if ((((int)0 >= _Function_1_1::Block(this)))){
			HX_STACK_LINE(4764)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(4765)
		_t2 = this->p_p->addr((int)0);
		HX_STACK_LINE(4766)
		this->_t3 = (int(_t2->ref()) | int((int)0));
		HX_STACK_LINE(4767)
		this->_latestPH = (int)586;
		HX_STACK_LINE(4768)
		_t4 = (::tardis::Force_obj::uintCompare(this->_t3,(int)128) < (int)0);
		HX_STACK_LINE(4769)
		this->_Next = (  ((_t4)) ? int((int)3) : int((int)4) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn1,(void))

Void Go_utf8_decodeRuneInternal_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_decodeRuneInternal::SubFn0","tardis/Go.hx",4752);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4753)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(4754)
		this->_latestPH = (int)579;
		struct _Function_1_1{
			inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",4755);
				{
					HX_STACK_LINE(4755)
					::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(4755)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(4755)
		this->_t0 = _Function_1_1::Block(this);
		HX_STACK_LINE(4756)
		this->_latestPH = (int)580;
		HX_STACK_LINE(4757)
		_t1 = (this->_t0 < (int)1);
		HX_STACK_LINE(4758)
		this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_decodeRuneInternal_obj::run( ){
	HX_STACK_PUSH("Go_utf8_decodeRuneInternal::run","tardis/Go.hx",4527);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4527)
	while((true)){
		HX_STACK_LINE(4529)
		::tardis::_Go::Go_utf8_decodeRuneInternal _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(4529)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(4531)
				{
					HX_STACK_LINE(4531)
					this->_latestPH = (int)578;
					HX_STACK_LINE(4531)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(4532)
				{
					HX_STACK_LINE(4532)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(4532)
					this->_latestPH = (int)579;
					struct _Function_4_1{
						inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4532);
							{
								HX_STACK_LINE(4532)
								::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(4532)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(4532)
					this->_t0 = _Function_4_1::Block(this);
					HX_STACK_LINE(4532)
					this->_latestPH = (int)580;
					HX_STACK_LINE(4532)
					_t1 = (this->_t0 < (int)1);
					HX_STACK_LINE(4532)
					this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(4535)
				{
					HX_STACK_LINE(4535)
					this->_latestPH = (int)578;
					HX_STACK_LINE(4535)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(4536)
				this->_latestPH = (int)581;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4537);
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
				HX_STACK_LINE(4537)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4538)
				this->_incomplete = false;
				HX_STACK_LINE(4539)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4540)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(4543)
				{
					HX_STACK_LINE(4543)
					this->_latestPH = (int)581;
					HX_STACK_LINE(4543)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(4544)
				{
					HX_STACK_LINE(4544)
					::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(4544)
					bool _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(4544)
					this->_latestPH = (int)583;
					struct _Function_4_1{
						inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4544);
							{
								HX_STACK_LINE(4544)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4544)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4544)
					if ((((int)0 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(4544)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4544)
					_t2 = this->p_p->addr((int)0);
					HX_STACK_LINE(4544)
					this->_t3 = (int(_t2->ref()) | int((int)0));
					HX_STACK_LINE(4544)
					this->_latestPH = (int)586;
					HX_STACK_LINE(4544)
					_t4 = (::tardis::Force_obj::uintCompare(this->_t3,(int)128) < (int)0);
					HX_STACK_LINE(4544)
					this->_Next = (  ((_t4)) ? int((int)3) : int((int)4) );
				}
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(4547)
				{
					HX_STACK_LINE(4547)
					this->_latestPH = (int)581;
					HX_STACK_LINE(4547)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(4548)
				{
					HX_STACK_LINE(4548)
					this->_latestPH = (int)587;
					HX_STACK_LINE(4548)
					this->_t5 = this->_t3;
				}
				HX_STACK_LINE(4549)
				this->_latestPH = (int)587;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4550);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t5,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(4550)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(4551)
				this->_incomplete = false;
				HX_STACK_LINE(4552)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4553)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(4556)
				{
					HX_STACK_LINE(4556)
					this->_latestPH = (int)587;
					HX_STACK_LINE(4556)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(4557)
				{
					HX_STACK_LINE(4557)
					bool _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(4557)
					this->_latestPH = (int)591;
					HX_STACK_LINE(4557)
					_t6 = (::tardis::Force_obj::uintCompare(this->_t3,(int)192) < (int)0);
					HX_STACK_LINE(4557)
					this->_Next = (  ((_t6)) ? int((int)5) : int((int)6) );
				}
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(4560)
				{
					HX_STACK_LINE(4560)
					this->_latestPH = (int)587;
					HX_STACK_LINE(4560)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(4561)
				this->_latestPH = (int)592;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4562);
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
				HX_STACK_LINE(4562)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4563)
				this->_incomplete = false;
				HX_STACK_LINE(4564)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4565)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(4568)
				{
					HX_STACK_LINE(4568)
					this->_latestPH = (int)592;
					HX_STACK_LINE(4568)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(4569)
				{
					HX_STACK_LINE(4569)
					bool _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(4569)
					this->_latestPH = (int)596;
					HX_STACK_LINE(4569)
					_t7 = (this->_t0 < (int)2);
					HX_STACK_LINE(4569)
					this->_Next = (  ((_t7)) ? int((int)7) : int((int)8) );
				}
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(4572)
				{
					HX_STACK_LINE(4572)
					this->_latestPH = (int)592;
					HX_STACK_LINE(4572)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(4573)
				this->_latestPH = (int)597;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4574);
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
				HX_STACK_LINE(4574)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4575)
				this->_incomplete = false;
				HX_STACK_LINE(4576)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4577)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(4580)
				{
					HX_STACK_LINE(4580)
					this->_latestPH = (int)597;
					HX_STACK_LINE(4580)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(4581)
				{
					HX_STACK_LINE(4581)
					::tardis::Pointer _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(4581)
					bool _t10;		HX_STACK_VAR(_t10,"_t10");
					HX_STACK_LINE(4581)
					this->_latestPH = (int)599;
					struct _Function_4_1{
						inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4581);
							{
								HX_STACK_LINE(4581)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4581)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4581)
					if ((((int)1 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(4581)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4581)
					_t8 = this->p_p->addr((int)1);
					HX_STACK_LINE(4581)
					this->_t9 = (int(_t8->ref()) | int((int)0));
					HX_STACK_LINE(4581)
					this->_latestPH = (int)600;
					HX_STACK_LINE(4581)
					_t10 = (::tardis::Force_obj::uintCompare(this->_t9,(int)128) < (int)0);
					HX_STACK_LINE(4581)
					this->_Next = (  ((_t10)) ? int((int)9) : int((int)11) );
				}
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(4584)
				{
					HX_STACK_LINE(4584)
					this->_latestPH = (int)597;
					HX_STACK_LINE(4584)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(4585)
				this->_latestPH = (int)601;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4586);
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
				HX_STACK_LINE(4586)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4587)
				this->_incomplete = false;
				HX_STACK_LINE(4588)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4589)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(4592)
				{
					HX_STACK_LINE(4592)
					this->_latestPH = (int)601;
					HX_STACK_LINE(4592)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(4593)
				{
					HX_STACK_LINE(4593)
					bool _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(4593)
					this->_latestPH = (int)605;
					HX_STACK_LINE(4593)
					_t11 = (::tardis::Force_obj::uintCompare(this->_t3,(int)224) < (int)0);
					HX_STACK_LINE(4593)
					this->_Next = (  ((_t11)) ? int((int)12) : int((int)13) );
				}
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(4596)
				{
					HX_STACK_LINE(4596)
					this->_latestPH = (int)601;
					HX_STACK_LINE(4596)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(4597)
				{
					HX_STACK_LINE(4597)
					bool _t12;		HX_STACK_VAR(_t12,"_t12");
					HX_STACK_LINE(4597)
					this->_latestPH = (int)600;
					HX_STACK_LINE(4597)
					_t12 = (::tardis::Force_obj::uintCompare((int)192,this->_t9) <= (int)0);
					HX_STACK_LINE(4597)
					this->_Next = (  ((_t12)) ? int((int)9) : int((int)10) );
				}
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(4600)
				{
					HX_STACK_LINE(4600)
					this->_latestPH = (int)601;
					HX_STACK_LINE(4600)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(4601)
				{
					HX_STACK_LINE(4601)
					int _t13;		HX_STACK_VAR(_t13,"_t13");
					HX_STACK_LINE(4601)
					int _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(4601)
					int _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(4601)
					int _t16;		HX_STACK_VAR(_t16,"_t16");
					HX_STACK_LINE(4601)
					int _t17;		HX_STACK_VAR(_t17,"_t17");
					HX_STACK_LINE(4601)
					bool _t19;		HX_STACK_VAR(_t19,"_t19");
					HX_STACK_LINE(4601)
					this->_latestPH = (int)606;
					HX_STACK_LINE(4601)
					_t13 = (int((int(this->_t3) & int((int)31))) & int((int)255));
					HX_STACK_LINE(4601)
					_t14 = _t13;
					HX_STACK_LINE(4601)
					_t15 = (int(_t14) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(4601)
					_t16 = (int((int(this->_t9) & int((int)63))) & int((int)255));
					HX_STACK_LINE(4601)
					_t17 = _t16;
					HX_STACK_LINE(4601)
					this->_t18 = ::tardis::Force_obj::toInt32((int(_t15) | int(_t17)));
					HX_STACK_LINE(4601)
					this->_latestPH = (int)607;
					HX_STACK_LINE(4601)
					_t19 = (this->_t18 <= (int)127);
					HX_STACK_LINE(4601)
					this->_Next = (  ((_t19)) ? int((int)14) : int((int)15) );
				}
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(4604)
				{
					HX_STACK_LINE(4604)
					this->_latestPH = (int)601;
					HX_STACK_LINE(4604)
					this->_latestBlock = (int)13;
				}
				HX_STACK_LINE(4605)
				{
					HX_STACK_LINE(4605)
					bool _t20;		HX_STACK_VAR(_t20,"_t20");
					HX_STACK_LINE(4605)
					this->_latestPH = (int)614;
					HX_STACK_LINE(4605)
					_t20 = (this->_t0 < (int)3);
					HX_STACK_LINE(4605)
					this->_Next = (  ((_t20)) ? int((int)16) : int((int)17) );
				}
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(4608)
				{
					HX_STACK_LINE(4608)
					this->_latestPH = (int)601;
					HX_STACK_LINE(4608)
					this->_latestBlock = (int)14;
				}
				HX_STACK_LINE(4609)
				this->_latestPH = (int)608;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4610);
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
				HX_STACK_LINE(4610)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4611)
				this->_incomplete = false;
				HX_STACK_LINE(4612)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4613)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)15: {
				HX_STACK_LINE(4616)
				{
					HX_STACK_LINE(4616)
					this->_latestPH = (int)608;
					HX_STACK_LINE(4616)
					this->_latestBlock = (int)15;
				}
				HX_STACK_LINE(4617)
				this->_latestPH = (int)610;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4618);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t18,false);
							__result->Add(HX_CSTRING("r1") , (int)2,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(4618)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(4619)
				this->_incomplete = false;
				HX_STACK_LINE(4620)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4621)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)16: {
				HX_STACK_LINE(4624)
				{
					HX_STACK_LINE(4624)
					this->_latestPH = (int)610;
					HX_STACK_LINE(4624)
					this->_latestBlock = (int)16;
				}
				HX_STACK_LINE(4625)
				this->_latestPH = (int)615;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4626);
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
				HX_STACK_LINE(4626)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4627)
				this->_incomplete = false;
				HX_STACK_LINE(4628)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4629)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)17: {
				HX_STACK_LINE(4632)
				{
					HX_STACK_LINE(4632)
					this->_latestPH = (int)615;
					HX_STACK_LINE(4632)
					this->_latestBlock = (int)17;
				}
				HX_STACK_LINE(4633)
				{
					HX_STACK_LINE(4633)
					::tardis::Pointer _t21;		HX_STACK_VAR(_t21,"_t21");
					HX_STACK_LINE(4633)
					bool _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(4633)
					this->_latestPH = (int)617;
					struct _Function_4_1{
						inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4633);
							{
								HX_STACK_LINE(4633)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4633)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4633)
					if ((((int)2 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(4633)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4633)
					_t21 = this->p_p->addr((int)2);
					HX_STACK_LINE(4633)
					this->_t22 = (int(_t21->ref()) | int((int)0));
					HX_STACK_LINE(4633)
					this->_latestPH = (int)618;
					HX_STACK_LINE(4633)
					_t23 = (::tardis::Force_obj::uintCompare(this->_t22,(int)128) < (int)0);
					HX_STACK_LINE(4633)
					this->_Next = (  ((_t23)) ? int((int)18) : int((int)20) );
				}
			}
			;break;
			case (int)18: {
				HX_STACK_LINE(4636)
				{
					HX_STACK_LINE(4636)
					this->_latestPH = (int)615;
					HX_STACK_LINE(4636)
					this->_latestBlock = (int)18;
				}
				HX_STACK_LINE(4637)
				this->_latestPH = (int)619;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4638);
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
				HX_STACK_LINE(4638)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4639)
				this->_incomplete = false;
				HX_STACK_LINE(4640)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4641)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)19: {
				HX_STACK_LINE(4644)
				{
					HX_STACK_LINE(4644)
					this->_latestPH = (int)619;
					HX_STACK_LINE(4644)
					this->_latestBlock = (int)19;
				}
				HX_STACK_LINE(4645)
				{
					HX_STACK_LINE(4645)
					bool _t24;		HX_STACK_VAR(_t24,"_t24");
					HX_STACK_LINE(4645)
					this->_latestPH = (int)623;
					HX_STACK_LINE(4645)
					_t24 = (::tardis::Force_obj::uintCompare(this->_t3,(int)240) < (int)0);
					HX_STACK_LINE(4645)
					this->_Next = (  ((_t24)) ? int((int)21) : int((int)22) );
				}
			}
			;break;
			case (int)20: {
				HX_STACK_LINE(4648)
				{
					HX_STACK_LINE(4648)
					this->_latestPH = (int)619;
					HX_STACK_LINE(4648)
					this->_latestBlock = (int)20;
				}
				HX_STACK_LINE(4649)
				{
					HX_STACK_LINE(4649)
					bool _t25;		HX_STACK_VAR(_t25,"_t25");
					HX_STACK_LINE(4649)
					this->_latestPH = (int)618;
					HX_STACK_LINE(4649)
					_t25 = (::tardis::Force_obj::uintCompare((int)192,this->_t22) <= (int)0);
					HX_STACK_LINE(4649)
					this->_Next = (  ((_t25)) ? int((int)18) : int((int)19) );
				}
			}
			;break;
			case (int)21: {
				HX_STACK_LINE(4652)
				{
					HX_STACK_LINE(4652)
					this->_latestPH = (int)619;
					HX_STACK_LINE(4652)
					this->_latestBlock = (int)21;
				}
				HX_STACK_LINE(4653)
				{
					HX_STACK_LINE(4653)
					int _t26;		HX_STACK_VAR(_t26,"_t26");
					HX_STACK_LINE(4653)
					int _t27;		HX_STACK_VAR(_t27,"_t27");
					HX_STACK_LINE(4653)
					int _t28;		HX_STACK_VAR(_t28,"_t28");
					HX_STACK_LINE(4653)
					int _t29;		HX_STACK_VAR(_t29,"_t29");
					HX_STACK_LINE(4653)
					int _t30;		HX_STACK_VAR(_t30,"_t30");
					HX_STACK_LINE(4653)
					int _t31;		HX_STACK_VAR(_t31,"_t31");
					HX_STACK_LINE(4653)
					int _t32;		HX_STACK_VAR(_t32,"_t32");
					HX_STACK_LINE(4653)
					int _t33;		HX_STACK_VAR(_t33,"_t33");
					HX_STACK_LINE(4653)
					int _t34;		HX_STACK_VAR(_t34,"_t34");
					HX_STACK_LINE(4653)
					bool _t36;		HX_STACK_VAR(_t36,"_t36");
					HX_STACK_LINE(4653)
					this->_latestPH = (int)624;
					HX_STACK_LINE(4653)
					_t26 = (int((int(this->_t3) & int((int)15))) & int((int)255));
					HX_STACK_LINE(4653)
					_t27 = _t26;
					HX_STACK_LINE(4653)
					_t28 = (int(_t27) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
					HX_STACK_LINE(4653)
					_t29 = (int((int(this->_t9) & int((int)63))) & int((int)255));
					HX_STACK_LINE(4653)
					_t30 = _t29;
					HX_STACK_LINE(4653)
					_t31 = (int(_t30) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(4653)
					_t32 = ::tardis::Force_obj::toInt32((int(_t28) | int(_t31)));
					HX_STACK_LINE(4653)
					_t33 = (int((int(this->_t22) & int((int)63))) & int((int)255));
					HX_STACK_LINE(4653)
					_t34 = _t33;
					HX_STACK_LINE(4653)
					this->_t35 = ::tardis::Force_obj::toInt32((int(_t32) | int(_t34)));
					HX_STACK_LINE(4653)
					this->_latestPH = (int)625;
					HX_STACK_LINE(4653)
					_t36 = (this->_t35 <= (int)2047);
					HX_STACK_LINE(4653)
					this->_Next = (  ((_t36)) ? int((int)23) : int((int)24) );
				}
			}
			;break;
			case (int)22: {
				HX_STACK_LINE(4656)
				{
					HX_STACK_LINE(4656)
					this->_latestPH = (int)619;
					HX_STACK_LINE(4656)
					this->_latestBlock = (int)22;
				}
				HX_STACK_LINE(4657)
				{
					HX_STACK_LINE(4657)
					bool _t37;		HX_STACK_VAR(_t37,"_t37");
					HX_STACK_LINE(4657)
					this->_latestPH = (int)635;
					HX_STACK_LINE(4657)
					_t37 = (this->_t0 < (int)4);
					HX_STACK_LINE(4657)
					this->_Next = (  ((_t37)) ? int((int)28) : int((int)29) );
				}
			}
			;break;
			case (int)23: {
				HX_STACK_LINE(4660)
				{
					HX_STACK_LINE(4660)
					this->_latestPH = (int)619;
					HX_STACK_LINE(4660)
					this->_latestBlock = (int)23;
				}
				HX_STACK_LINE(4661)
				this->_latestPH = (int)626;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4662);
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
				HX_STACK_LINE(4662)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4663)
				this->_incomplete = false;
				HX_STACK_LINE(4664)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4665)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)24: {
				HX_STACK_LINE(4668)
				{
					HX_STACK_LINE(4668)
					this->_latestPH = (int)626;
					HX_STACK_LINE(4668)
					this->_latestBlock = (int)24;
				}
				HX_STACK_LINE(4669)
				{
					HX_STACK_LINE(4669)
					bool _t38;		HX_STACK_VAR(_t38,"_t38");
					HX_STACK_LINE(4669)
					this->_latestPH = (int)628;
					HX_STACK_LINE(4669)
					_t38 = ((int)55296 <= this->_t35);
					HX_STACK_LINE(4669)
					this->_Next = (  ((_t38)) ? int((int)27) : int((int)26) );
				}
			}
			;break;
			case (int)25: {
				HX_STACK_LINE(4672)
				{
					HX_STACK_LINE(4672)
					this->_latestPH = (int)626;
					HX_STACK_LINE(4672)
					this->_latestBlock = (int)25;
				}
				HX_STACK_LINE(4673)
				this->_latestPH = (int)629;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4674);
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
				HX_STACK_LINE(4674)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4675)
				this->_incomplete = false;
				HX_STACK_LINE(4676)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4677)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)26: {
				HX_STACK_LINE(4680)
				{
					HX_STACK_LINE(4680)
					this->_latestPH = (int)629;
					HX_STACK_LINE(4680)
					this->_latestBlock = (int)26;
				}
				HX_STACK_LINE(4681)
				this->_latestPH = (int)631;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4682);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t35,false);
							__result->Add(HX_CSTRING("r1") , (int)3,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(4682)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(4683)
				this->_incomplete = false;
				HX_STACK_LINE(4684)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4685)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)27: {
				HX_STACK_LINE(4688)
				{
					HX_STACK_LINE(4688)
					this->_latestPH = (int)631;
					HX_STACK_LINE(4688)
					this->_latestBlock = (int)27;
				}
				HX_STACK_LINE(4689)
				{
					HX_STACK_LINE(4689)
					bool _t39;		HX_STACK_VAR(_t39,"_t39");
					HX_STACK_LINE(4689)
					_t39 = (this->_t35 <= (int)57343);
					HX_STACK_LINE(4689)
					this->_Next = (  ((_t39)) ? int((int)25) : int((int)26) );
				}
			}
			;break;
			case (int)28: {
				HX_STACK_LINE(4692)
				{
					HX_STACK_LINE(4692)
					this->_latestPH = (int)631;
					HX_STACK_LINE(4692)
					this->_latestBlock = (int)28;
				}
				HX_STACK_LINE(4693)
				this->_latestPH = (int)636;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4694);
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
				HX_STACK_LINE(4694)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4695)
				this->_incomplete = false;
				HX_STACK_LINE(4696)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4697)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)29: {
				HX_STACK_LINE(4700)
				{
					HX_STACK_LINE(4700)
					this->_latestPH = (int)636;
					HX_STACK_LINE(4700)
					this->_latestBlock = (int)29;
				}
				HX_STACK_LINE(4701)
				{
					HX_STACK_LINE(4701)
					::tardis::Pointer _t40;		HX_STACK_VAR(_t40,"_t40");
					HX_STACK_LINE(4701)
					bool _t42;		HX_STACK_VAR(_t42,"_t42");
					HX_STACK_LINE(4701)
					this->_latestPH = (int)638;
					struct _Function_4_1{
						inline static int Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",4701);
							{
								HX_STACK_LINE(4701)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(4701)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(4701)
					if ((((int)3 >= _Function_4_1::Block(this)))){
						HX_STACK_LINE(4701)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(4701)
					_t40 = this->p_p->addr((int)3);
					HX_STACK_LINE(4701)
					this->_t41 = (int(_t40->ref()) | int((int)0));
					HX_STACK_LINE(4701)
					this->_latestPH = (int)639;
					HX_STACK_LINE(4701)
					_t42 = (::tardis::Force_obj::uintCompare(this->_t41,(int)128) < (int)0);
					HX_STACK_LINE(4701)
					this->_Next = (  ((_t42)) ? int((int)30) : int((int)32) );
				}
			}
			;break;
			case (int)30: {
				HX_STACK_LINE(4704)
				{
					HX_STACK_LINE(4704)
					this->_latestPH = (int)636;
					HX_STACK_LINE(4704)
					this->_latestBlock = (int)30;
				}
				HX_STACK_LINE(4705)
				this->_latestPH = (int)640;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4706);
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
				HX_STACK_LINE(4706)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4707)
				this->_incomplete = false;
				HX_STACK_LINE(4708)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4709)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)31: {
				HX_STACK_LINE(4712)
				{
					HX_STACK_LINE(4712)
					this->_latestPH = (int)640;
					HX_STACK_LINE(4712)
					this->_latestBlock = (int)31;
				}
				HX_STACK_LINE(4713)
				{
					HX_STACK_LINE(4713)
					bool _t43;		HX_STACK_VAR(_t43,"_t43");
					HX_STACK_LINE(4713)
					this->_latestPH = (int)644;
					HX_STACK_LINE(4713)
					_t43 = (::tardis::Force_obj::uintCompare(this->_t3,(int)248) < (int)0);
					HX_STACK_LINE(4713)
					this->_Next = (  ((_t43)) ? int((int)33) : int((int)34) );
				}
			}
			;break;
			case (int)32: {
				HX_STACK_LINE(4716)
				{
					HX_STACK_LINE(4716)
					this->_latestPH = (int)640;
					HX_STACK_LINE(4716)
					this->_latestBlock = (int)32;
				}
				HX_STACK_LINE(4717)
				{
					HX_STACK_LINE(4717)
					bool _t44;		HX_STACK_VAR(_t44,"_t44");
					HX_STACK_LINE(4717)
					this->_latestPH = (int)639;
					HX_STACK_LINE(4717)
					_t44 = (::tardis::Force_obj::uintCompare((int)192,this->_t41) <= (int)0);
					HX_STACK_LINE(4717)
					this->_Next = (  ((_t44)) ? int((int)30) : int((int)31) );
				}
			}
			;break;
			case (int)33: {
				HX_STACK_LINE(4720)
				{
					HX_STACK_LINE(4720)
					this->_latestPH = (int)640;
					HX_STACK_LINE(4720)
					this->_latestBlock = (int)33;
				}
				HX_STACK_LINE(4721)
				{
					HX_STACK_LINE(4721)
					int _t45;		HX_STACK_VAR(_t45,"_t45");
					HX_STACK_LINE(4721)
					int _t46;		HX_STACK_VAR(_t46,"_t46");
					HX_STACK_LINE(4721)
					int _t47;		HX_STACK_VAR(_t47,"_t47");
					HX_STACK_LINE(4721)
					int _t48;		HX_STACK_VAR(_t48,"_t48");
					HX_STACK_LINE(4721)
					int _t49;		HX_STACK_VAR(_t49,"_t49");
					HX_STACK_LINE(4721)
					int _t50;		HX_STACK_VAR(_t50,"_t50");
					HX_STACK_LINE(4721)
					int _t51;		HX_STACK_VAR(_t51,"_t51");
					HX_STACK_LINE(4721)
					int _t52;		HX_STACK_VAR(_t52,"_t52");
					HX_STACK_LINE(4721)
					int _t53;		HX_STACK_VAR(_t53,"_t53");
					HX_STACK_LINE(4721)
					int _t54;		HX_STACK_VAR(_t54,"_t54");
					HX_STACK_LINE(4721)
					int _t55;		HX_STACK_VAR(_t55,"_t55");
					HX_STACK_LINE(4721)
					int _t56;		HX_STACK_VAR(_t56,"_t56");
					HX_STACK_LINE(4721)
					int _t57;		HX_STACK_VAR(_t57,"_t57");
					HX_STACK_LINE(4721)
					bool _t59;		HX_STACK_VAR(_t59,"_t59");
					HX_STACK_LINE(4721)
					this->_latestPH = (int)645;
					HX_STACK_LINE(4721)
					_t45 = (int((int(this->_t3) & int((int)7))) & int((int)255));
					HX_STACK_LINE(4721)
					_t46 = _t45;
					HX_STACK_LINE(4721)
					_t47 = (int(_t46) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)18))));
					HX_STACK_LINE(4721)
					_t48 = (int((int(this->_t9) & int((int)63))) & int((int)255));
					HX_STACK_LINE(4721)
					_t49 = _t48;
					HX_STACK_LINE(4721)
					_t50 = (int(_t49) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)12))));
					HX_STACK_LINE(4721)
					_t51 = ::tardis::Force_obj::toInt32((int(_t47) | int(_t50)));
					HX_STACK_LINE(4721)
					_t52 = (int((int(this->_t22) & int((int)63))) & int((int)255));
					HX_STACK_LINE(4721)
					_t53 = _t52;
					HX_STACK_LINE(4721)
					_t54 = (int(_t53) << int(::tardis::Int64_obj::getLow(::tardis::Int64_obj::__new((int)0,(int)6))));
					HX_STACK_LINE(4721)
					_t55 = ::tardis::Force_obj::toInt32((int(_t51) | int(_t54)));
					HX_STACK_LINE(4721)
					_t56 = (int((int(this->_t41) & int((int)63))) & int((int)255));
					HX_STACK_LINE(4721)
					_t57 = _t56;
					HX_STACK_LINE(4721)
					this->_t58 = ::tardis::Force_obj::toInt32((int(_t55) | int(_t57)));
					HX_STACK_LINE(4721)
					this->_latestPH = (int)646;
					HX_STACK_LINE(4721)
					_t59 = (this->_t58 <= (int)65535);
					HX_STACK_LINE(4721)
					this->_Next = (  ((_t59)) ? int((int)35) : int((int)37) );
				}
			}
			;break;
			case (int)34: {
				HX_STACK_LINE(4724)
				{
					HX_STACK_LINE(4724)
					this->_latestPH = (int)640;
					HX_STACK_LINE(4724)
					this->_latestBlock = (int)34;
				}
				HX_STACK_LINE(4725)
				this->_latestPH = (int)653;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4726);
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
				HX_STACK_LINE(4726)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4727)
				this->_incomplete = false;
				HX_STACK_LINE(4728)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4729)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)35: {
				HX_STACK_LINE(4732)
				{
					HX_STACK_LINE(4732)
					this->_latestPH = (int)653;
					HX_STACK_LINE(4732)
					this->_latestBlock = (int)35;
				}
				HX_STACK_LINE(4733)
				this->_latestPH = (int)647;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4734);
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
				HX_STACK_LINE(4734)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(4735)
				this->_incomplete = false;
				HX_STACK_LINE(4736)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4737)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)36: {
				HX_STACK_LINE(4740)
				{
					HX_STACK_LINE(4740)
					this->_latestPH = (int)647;
					HX_STACK_LINE(4740)
					this->_latestBlock = (int)36;
				}
				HX_STACK_LINE(4741)
				this->_latestPH = (int)649;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::_Go::Go_utf8_decodeRuneInternal_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",4742);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t58,false);
							__result->Add(HX_CSTRING("r1") , (int)4,false);
							__result->Add(HX_CSTRING("r2") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(4742)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(4743)
				this->_incomplete = false;
				HX_STACK_LINE(4744)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4745)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)37: {
				HX_STACK_LINE(4748)
				{
					HX_STACK_LINE(4748)
					this->_latestPH = (int)649;
					HX_STACK_LINE(4748)
					this->_latestBlock = (int)37;
				}
				HX_STACK_LINE(4749)
				{
					HX_STACK_LINE(4749)
					bool _t60;		HX_STACK_VAR(_t60,"_t60");
					HX_STACK_LINE(4749)
					_t60 = ((int)1114111 < this->_t58);
					HX_STACK_LINE(4749)
					this->_Next = (  ((_t60)) ? int((int)35) : int((int)36) );
				}
			}
			;break;
			default: {
				HX_STACK_LINE(4751)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(4527)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,run,return )

Dynamic Go_utf8_decodeRuneInternal_obj::res( ){
	HX_STACK_PUSH("Go_utf8_decodeRuneInternal::res","tardis/Go.hx",4450);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4450)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_decodeRuneInternal_obj,res,return )

Dynamic Go_utf8_decodeRuneInternal_obj::callFromHaxe( ::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_decodeRuneInternal::callFromHaxe","tardis/Go.hx",4513);
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(4514)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(4514)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(4515)
	::tardis::_Go::Go_utf8_decodeRuneInternal _sf = hx::TCast< ::tardis::_Go::Go_utf8_decodeRuneInternal >::cast(::tardis::_Go::Go_utf8_decodeRuneInternal_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4516)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4516)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(4517)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_decodeRuneInternal_obj,callFromHaxe,return )

Dynamic Go_utf8_decodeRuneInternal_obj::callFromRT( int _gr,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_decodeRuneInternal::callFromRT","tardis/Go.hx",4519);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(4520)
	::tardis::_Go::Go_utf8_decodeRuneInternal _sf = hx::TCast< ::tardis::_Go::Go_utf8_decodeRuneInternal >::cast(::tardis::_Go::Go_utf8_decodeRuneInternal_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4521)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4521)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(4521)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(4521)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(4521)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(4522)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_decodeRuneInternal_obj,callFromRT,return )

::tardis::_Go::Go_utf8_decodeRuneInternal Go_utf8_decodeRuneInternal_obj::call( int gr,Dynamic _bds,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_decodeRuneInternal::call","tardis/Go.hx",4525);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(4525)
	return ::tardis::_Go::Go_utf8_decodeRuneInternal_obj::__new(gr,_bds,p_p);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_decodeRuneInternal_obj,call,return )


Go_utf8_decodeRuneInternal_obj::Go_utf8_decodeRuneInternal_obj()
{
}

void Go_utf8_decodeRuneInternal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_decodeRuneInternal);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t60,"_t60");
	HX_MARK_MEMBER_NAME(_t59,"_t59");
	HX_MARK_MEMBER_NAME(_t58,"_t58");
	HX_MARK_MEMBER_NAME(_t57,"_t57");
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
	HX_MARK_MEMBER_NAME(p_p,"p_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_decodeRuneInternal_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t60,"_t60");
	HX_VISIT_MEMBER_NAME(_t59,"_t59");
	HX_VISIT_MEMBER_NAME(_t58,"_t58");
	HX_VISIT_MEMBER_NAME(_t57,"_t57");
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
	HX_VISIT_MEMBER_NAME(p_p,"p_p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_decodeRuneInternal_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_p") ) { return p_p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_t60") ) { return _t60; }
		if (HX_FIELD_EQ(inName,"_t59") ) { return _t59; }
		if (HX_FIELD_EQ(inName,"_t58") ) { return _t58; }
		if (HX_FIELD_EQ(inName,"_t57") ) { return _t57; }
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

Dynamic Go_utf8_decodeRuneInternal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_p") ) { p_p=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_t60") ) { _t60=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t59") ) { _t59=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t58") ) { _t58=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t57") ) { _t57=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t56") ) { _t56=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t55") ) { _t55=inValue.Cast< int >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"_t44") ) { _t44=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t43") ) { _t43=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t42") ) { _t42=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t41") ) { _t41=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t40") ) { _t40=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t39") ) { _t39=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t38") ) { _t38=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t37") ) { _t37=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t36") ) { _t36=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t35") ) { _t35=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t34") ) { _t34=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t33") ) { _t33=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t32") ) { _t32=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t31") ) { _t31=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t30") ) { _t30=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t29") ) { _t29=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t28") ) { _t28=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t27") ) { _t27=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t26") ) { _t26=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t25") ) { _t25=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t24") ) { _t24=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_decodeRuneInternal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t60"));
	outFields->push(HX_CSTRING("_t59"));
	outFields->push(HX_CSTRING("_t58"));
	outFields->push(HX_CSTRING("_t57"));
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
	outFields->push(HX_CSTRING("p_p"));
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
	HX_CSTRING("_t60"),
	HX_CSTRING("_t59"),
	HX_CSTRING("_t58"),
	HX_CSTRING("_t57"),
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
	HX_CSTRING("p_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_decodeRuneInternal_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_decodeRuneInternal_obj::__mClass,"__mClass");
};

Class Go_utf8_decodeRuneInternal_obj::__mClass;

void Go_utf8_decodeRuneInternal_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_utf8_decodeRuneInternal"), hx::TCanCast< Go_utf8_decodeRuneInternal_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_decodeRuneInternal_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
