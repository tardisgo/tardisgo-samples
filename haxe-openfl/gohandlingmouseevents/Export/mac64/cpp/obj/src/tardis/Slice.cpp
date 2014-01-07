#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
namespace tardis{

Void Slice_obj::__construct(::tardis::Pointer fromArray,int low,int high)
{
HX_STACK_PUSH("Slice::new","tardis/Go.hx",340);
{
	HX_STACK_LINE(341)
	this->baseArray = fromArray;
	HX_STACK_LINE(342)
	if (((this->baseArray == null()))){
		HX_STACK_LINE(343)
		this->start = (int)0;
		HX_STACK_LINE(344)
		this->end = (int)0;
	}
	else{
		HX_STACK_LINE(346)
		if (((high == (int)-1))){
			HX_STACK_LINE(346)
			high = this->baseArray->ref()->__Field(HX_CSTRING("length"),true);
		}
		HX_STACK_LINE(347)
		if (((low < (int)0))){
			HX_STACK_LINE(347)
			::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("new Slice() low bound -ve"));
		}
		HX_STACK_LINE(348)
		if (((high > this->baseArray->ref()->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(348)
			::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("new Slice() high bound exceeds underlying array length"));
		}
		HX_STACK_LINE(349)
		if (((low > high))){
			HX_STACK_LINE(349)
			::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("new Slice() low bound exceeds high bound"));
		}
		HX_STACK_LINE(350)
		this->start = low;
		HX_STACK_LINE(351)
		this->end = high;
	}
}
;
	return null();
}

Slice_obj::~Slice_obj() { }

Dynamic Slice_obj::__CreateEmpty() { return  new Slice_obj; }
hx::ObjectPtr< Slice_obj > Slice_obj::__new(::tardis::Pointer fromArray,int low,int high)
{  hx::ObjectPtr< Slice_obj > result = new Slice_obj();
	result->__construct(fromArray,low,high);
	return result;}

Dynamic Slice_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Slice_obj > result = new Slice_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String Slice_obj::toString( ){
	HX_STACK_PUSH("Slice::toString","tardis/Go.hx",384);
	HX_STACK_THIS(this);
	HX_STACK_LINE(385)
	::String ret = ((((HX_CSTRING("Slice{") + this->start) + HX_CSTRING(",")) + this->end) + HX_CSTRING(",["));		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(386)
	if (((this->baseArray != null()))){
		HX_STACK_LINE(387)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->baseArray->ref()->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(387)
		while(((_g1 < _g))){
			HX_STACK_LINE(387)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(388)
			if (((i != (int)0))){
				HX_STACK_LINE(388)
				hx::AddEq(ret,HX_CSTRING(","));
			}
			HX_STACK_LINE(389)
			hx::AddEq(ret,this->baseArray->ref()->__GetItem(i));
		}
	}
	HX_STACK_LINE(391)
	return (ret + HX_CSTRING("]}"));
}


HX_DEFINE_DYNAMIC_FUNC0(Slice_obj,toString,return )

::tardis::Pointer Slice_obj::addr( Dynamic dynIdx){
	HX_STACK_PUSH("Slice::addr","tardis/Go.hx",378);
	HX_STACK_THIS(this);
	HX_STACK_ARG(dynIdx,"dynIdx");
	struct _Function_1_1{
		inline static int Block( Dynamic &dynIdx){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",379);
			{
				HX_STACK_LINE(379)
				Dynamic v = dynIdx;		HX_STACK_VAR(v,"v");
				struct _Function_2_1{
					inline static int Block( Dynamic &v){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",379);
						{
							HX_STACK_LINE(379)
							v = v->__Field(HX_CSTRING("val"),true);
							struct _Function_3_1{
								inline static int Block( Dynamic &v){
									HX_STACK_PUSH("*::closure","tardis/Go.hx",379);
									{
										HX_STACK_LINE(379)
										::tardis::Int64 v1 = v;		HX_STACK_VAR(v1,"v1");
										HX_STACK_LINE(379)
										return ::tardis::Int64_obj::getLow(v1);
									}
									return null();
								}
							};
							HX_STACK_LINE(379)
							return (  ((!(::Reflect_obj::isObject(v)))) ? int(v) : int(_Function_3_1::Block(v)) );
						}
						return null();
					}
				};
				struct _Function_2_2{
					inline static int Block( Dynamic &v){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",379);
						{
							HX_STACK_LINE(379)
							::tardis::Int64 v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(379)
							return ::tardis::Int64_obj::getLow(v1);
						}
						return null();
					}
				};
				HX_STACK_LINE(379)
				return (  ((!(::Reflect_obj::isObject(v)))) ? int(v) : int((  ((::Std_obj::is(v,hx::ClassOf< ::tardis::Interface >()))) ? int(_Function_2_1::Block(v)) : int(_Function_2_2::Block(v)) )) );
			}
			return null();
		}
	};
	HX_STACK_LINE(379)
	int idx = _Function_1_1::Block(dynIdx);		HX_STACK_VAR(idx,"idx");
	HX_STACK_LINE(380)
	if (((bool((idx < (int)0)) || bool((idx >= (this->end - this->start)))))){
		HX_STACK_LINE(380)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Slice index out of range for addr()"));
	}
	HX_STACK_LINE(381)
	if (((this->baseArray == null()))){
		HX_STACK_LINE(381)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Slice base array is null"));
	}
	HX_STACK_LINE(382)
	return this->baseArray->addr((idx + this->start));
}


HX_DEFINE_DYNAMIC_FUNC1(Slice_obj,addr,return )

int Slice_obj::cap( ){
	HX_STACK_PUSH("Slice::cap","tardis/Go.hx",374);
	HX_STACK_THIS(this);
	HX_STACK_LINE(375)
	if (((this->baseArray == null()))){
		HX_STACK_LINE(375)
		return (int)0;
	}
	HX_STACK_LINE(376)
	return (hx::TCast< Int >::cast(this->baseArray->ref()->__Field(HX_CSTRING("length"),true)) - this->start);
}


HX_DEFINE_DYNAMIC_FUNC0(Slice_obj,cap,return )

int Slice_obj::len( ){
	HX_STACK_PUSH("Slice::len","tardis/Go.hx",371);
	HX_STACK_THIS(this);
	HX_STACK_LINE(371)
	return (this->end - this->start);
}


HX_DEFINE_DYNAMIC_FUNC0(Slice_obj,len,return )

Void Slice_obj::setAt( Dynamic dynIdx,Dynamic v){
{
		HX_STACK_PUSH("Slice::setAt","tardis/Go.hx",365);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dynIdx,"dynIdx");
		HX_STACK_ARG(v,"v");
		struct _Function_1_1{
			inline static int Block( Dynamic &dynIdx){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",366);
				{
					HX_STACK_LINE(366)
					Dynamic v1 = dynIdx;		HX_STACK_VAR(v1,"v1");
					struct _Function_2_1{
						inline static int Block( Dynamic &v1){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",366);
							{
								HX_STACK_LINE(366)
								v1 = v1->__Field(HX_CSTRING("val"),true);
								struct _Function_3_1{
									inline static int Block( Dynamic &v1){
										HX_STACK_PUSH("*::closure","tardis/Go.hx",366);
										{
											HX_STACK_LINE(366)
											::tardis::Int64 v2 = v1;		HX_STACK_VAR(v2,"v2");
											HX_STACK_LINE(366)
											return ::tardis::Int64_obj::getLow(v2);
										}
										return null();
									}
								};
								HX_STACK_LINE(366)
								return (  ((!(::Reflect_obj::isObject(v1)))) ? int(v1) : int(_Function_3_1::Block(v1)) );
							}
							return null();
						}
					};
					struct _Function_2_2{
						inline static int Block( Dynamic &v1){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",366);
							{
								HX_STACK_LINE(366)
								::tardis::Int64 v2 = v1;		HX_STACK_VAR(v2,"v2");
								HX_STACK_LINE(366)
								return ::tardis::Int64_obj::getLow(v2);
							}
							return null();
						}
					};
					HX_STACK_LINE(366)
					return (  ((!(::Reflect_obj::isObject(v1)))) ? int(v1) : int((  ((::Std_obj::is(v1,hx::ClassOf< ::tardis::Interface >()))) ? int(_Function_2_1::Block(v1)) : int(_Function_2_2::Block(v1)) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(366)
		int idx = _Function_1_1::Block(dynIdx);		HX_STACK_VAR(idx,"idx");
		HX_STACK_LINE(367)
		if (((bool((idx < (int)0)) || bool((idx >= (this->end - this->start)))))){
			HX_STACK_LINE(367)
			::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Slice index out of range for setAt()"));
		}
		HX_STACK_LINE(368)
		if (((this->baseArray == null()))){
			HX_STACK_LINE(368)
			::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Slice base array is null"));
		}
		HX_STACK_LINE(369)
		hx::IndexRef((this->baseArray->ref()).mPtr,(idx + this->start)) = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Slice_obj,setAt,(void))

Dynamic Slice_obj::getAt( Dynamic dynIdx){
	HX_STACK_PUSH("Slice::getAt","tardis/Go.hx",359);
	HX_STACK_THIS(this);
	HX_STACK_ARG(dynIdx,"dynIdx");
	struct _Function_1_1{
		inline static int Block( Dynamic &dynIdx){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",360);
			{
				HX_STACK_LINE(360)
				Dynamic v = dynIdx;		HX_STACK_VAR(v,"v");
				struct _Function_2_1{
					inline static int Block( Dynamic &v){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",360);
						{
							HX_STACK_LINE(360)
							v = v->__Field(HX_CSTRING("val"),true);
							struct _Function_3_1{
								inline static int Block( Dynamic &v){
									HX_STACK_PUSH("*::closure","tardis/Go.hx",360);
									{
										HX_STACK_LINE(360)
										::tardis::Int64 v1 = v;		HX_STACK_VAR(v1,"v1");
										HX_STACK_LINE(360)
										return ::tardis::Int64_obj::getLow(v1);
									}
									return null();
								}
							};
							HX_STACK_LINE(360)
							return (  ((!(::Reflect_obj::isObject(v)))) ? int(v) : int(_Function_3_1::Block(v)) );
						}
						return null();
					}
				};
				struct _Function_2_2{
					inline static int Block( Dynamic &v){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",360);
						{
							HX_STACK_LINE(360)
							::tardis::Int64 v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(360)
							return ::tardis::Int64_obj::getLow(v1);
						}
						return null();
					}
				};
				HX_STACK_LINE(360)
				return (  ((!(::Reflect_obj::isObject(v)))) ? int(v) : int((  ((::Std_obj::is(v,hx::ClassOf< ::tardis::Interface >()))) ? int(_Function_2_1::Block(v)) : int(_Function_2_2::Block(v)) )) );
			}
			return null();
		}
	};
	HX_STACK_LINE(360)
	int idx = _Function_1_1::Block(dynIdx);		HX_STACK_VAR(idx,"idx");
	HX_STACK_LINE(361)
	if (((bool((idx < (int)0)) || bool((idx >= (this->end - this->start)))))){
		HX_STACK_LINE(361)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Slice index out of range for getAt()"));
	}
	HX_STACK_LINE(362)
	if (((this->baseArray == null()))){
		HX_STACK_LINE(362)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Slice base array is null"));
	}
	HX_STACK_LINE(363)
	return this->baseArray->ref()->__GetItem((idx + this->start));
}


HX_DEFINE_DYNAMIC_FUNC1(Slice_obj,getAt,return )

::tardis::Slice Slice_obj::subSlice( int low,int high){
	HX_STACK_PUSH("Slice::subSlice","tardis/Go.hx",355);
	HX_STACK_THIS(this);
	HX_STACK_ARG(low,"low");
	HX_STACK_ARG(high,"high");
	HX_STACK_LINE(356)
	if (((high == (int)-1))){
		HX_STACK_LINE(356)
		high = (this->end - this->start);
	}
	HX_STACK_LINE(357)
	return ::tardis::Slice_obj::__new(this->baseArray,(low + this->start),(high + this->start));
}


HX_DEFINE_DYNAMIC_FUNC2(Slice_obj,subSlice,return )


Slice_obj::Slice_obj()
{
}

void Slice_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Slice);
	HX_MARK_MEMBER_NAME(end,"end");
	HX_MARK_MEMBER_NAME(start,"start");
	HX_MARK_MEMBER_NAME(baseArray,"baseArray");
	HX_MARK_END_CLASS();
}

void Slice_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(end,"end");
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(baseArray,"baseArray");
}

Dynamic Slice_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cap") ) { return cap_dyn(); }
		if (HX_FIELD_EQ(inName,"len") ) { return len_dyn(); }
		if (HX_FIELD_EQ(inName,"end") ) { return end; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"addr") ) { return addr_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"setAt") ) { return setAt_dyn(); }
		if (HX_FIELD_EQ(inName,"getAt") ) { return getAt_dyn(); }
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"subSlice") ) { return subSlice_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"baseArray") ) { return baseArray; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Slice_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { end=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"baseArray") ) { baseArray=inValue.Cast< ::tardis::Pointer >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Slice_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("end"));
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("baseArray"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("addr"),
	HX_CSTRING("cap"),
	HX_CSTRING("len"),
	HX_CSTRING("setAt"),
	HX_CSTRING("getAt"),
	HX_CSTRING("subSlice"),
	HX_CSTRING("end"),
	HX_CSTRING("start"),
	HX_CSTRING("baseArray"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Slice_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Slice_obj::__mClass,"__mClass");
};

Class Slice_obj::__mClass;

void Slice_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Slice"), hx::TCanCast< Slice_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Slice_obj::__boot()
{
}

} // end namespace tardis
