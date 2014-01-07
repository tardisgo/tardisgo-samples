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
#ifndef INCLUDED_tardis_Go_haxegoruntime_Rune2Raw
#include <tardis/Go_haxegoruntime_Rune2Raw.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_Runes2Raw
#include <tardis/Go_haxegoruntime_Runes2Raw.h>
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

Void Go_haxegoruntime_Rune2Raw_obj::__construct(int gr,Dynamic _bds,int p_oneRune)
{
HX_STACK_PUSH("Go_haxegoruntime_Rune2Raw::new","tardis/Go.hx",8189);
{
	HX_STACK_LINE(8203)
	this->_Next = (int)0;
	HX_STACK_LINE(8202)
	this->_t2 = null();
	HX_STACK_LINE(8200)
	this->_t1 = null();
	HX_STACK_LINE(8199)
	this->_t0 = null();
	HX_STACK_LINE(8192)
	super::__construct(gr,(int)144,HX_CSTRING("Go_haxegoruntime_Rune2Raw"));
	HX_STACK_LINE(8193)
	this->_bds = _bds;
	HX_STACK_LINE(8194)
	this->p_oneRune = p_oneRune;
	HX_STACK_LINE(8195)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_Rune2Raw_obj::~Go_haxegoruntime_Rune2Raw_obj() { }

Dynamic Go_haxegoruntime_Rune2Raw_obj::__CreateEmpty() { return  new Go_haxegoruntime_Rune2Raw_obj; }
hx::ObjectPtr< Go_haxegoruntime_Rune2Raw_obj > Go_haxegoruntime_Rune2Raw_obj::__new(int gr,Dynamic _bds,int p_oneRune)
{  hx::ObjectPtr< Go_haxegoruntime_Rune2Raw_obj > result = new Go_haxegoruntime_Rune2Raw_obj();
	result->__construct(gr,_bds,p_oneRune);
	return result;}

Dynamic Go_haxegoruntime_Rune2Raw_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_Rune2Raw_obj > result = new Go_haxegoruntime_Rune2Raw_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_Rune2Raw_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_Rune2Raw_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Rune2Raw::SubFn0","tardis/Go.hx",8238);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8239)
		::tardis::Pointer _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(8240)
		this->_latestPH = (int)145;
		struct _Function_1_1{
			inline static Array< int > Block( ){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",8241);
				{
					HX_STACK_LINE(8241)
					Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(8241)
					{
						HX_STACK_LINE(8241)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(8241)
						while(((_g < (int)1))){
							HX_STACK_LINE(8241)
							int _i = (_g)++;		HX_STACK_VAR(_i,"_i");
							HX_STACK_LINE(8241)
							_v[_i] = (int)0;
						}
					}
					HX_STACK_LINE(8241)
					return _v;
				}
				return null();
			}
		};
		HX_STACK_LINE(8241)
		this->_t0 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_1_1::Block()),(int)0,(int)1);
		HX_STACK_LINE(8242)
		this->_latestPH = (int)146;
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_Rune2Raw_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",8243);
				{
					HX_STACK_LINE(8243)
					::tardis::Slice _this = __this->_t0;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(8243)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(8243)
		if ((((int)0 >= _Function_1_2::Block(this)))){
			HX_STACK_LINE(8243)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(8244)
		_t1 = this->_t0->addr((int)0);
		HX_STACK_LINE(8245)
		_t1->store(this->p_oneRune);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Rune2Raw_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_Rune2Raw_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_Rune2Raw::run","tardis/Go.hx",8218);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8218)
	while((true)){
		HX_STACK_LINE(8220)
		::tardis::Go_haxegoruntime_Rune2Raw _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(8220)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(8222)
				{
					HX_STACK_LINE(8222)
					this->_latestPH = (int)144;
					HX_STACK_LINE(8222)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(8223)
				{
					HX_STACK_LINE(8223)
					::tardis::Pointer _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(8223)
					this->_latestPH = (int)145;
					struct _Function_4_1{
						inline static Array< int > Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",8223);
							{
								HX_STACK_LINE(8223)
								Array< int > _v = Array_obj< int >::__new();		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(8223)
								{
									HX_STACK_LINE(8223)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(8223)
									while(((_g1 < (int)1))){
										HX_STACK_LINE(8223)
										int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
										HX_STACK_LINE(8223)
										_v[_i] = (int)0;
									}
								}
								HX_STACK_LINE(8223)
								return _v;
							}
							return null();
						}
					};
					HX_STACK_LINE(8223)
					this->_t0 = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(_Function_4_1::Block()),(int)0,(int)1);
					HX_STACK_LINE(8223)
					this->_latestPH = (int)146;
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_Rune2Raw_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",8223);
							{
								HX_STACK_LINE(8223)
								::tardis::Slice _this = __this->_t0;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(8223)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(8223)
					if ((((int)0 >= _Function_4_2::Block(this)))){
						HX_STACK_LINE(8223)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(8223)
					_t1 = this->_t0->addr((int)0);
					HX_STACK_LINE(8223)
					_t1->store(this->p_oneRune);
				}
				HX_STACK_LINE(8224)
				this->_latestPH = (int)147;
				HX_STACK_LINE(8225)
				this->_SF1 = ::tardis::Go_haxegoruntime_Runes2Raw_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t0);
				HX_STACK_LINE(8226)
				this->_Next = (int)-1;
				HX_STACK_LINE(8227)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(8229)
				{
					HX_STACK_LINE(8229)
					this->_latestPH = (int)147;
					HX_STACK_LINE(8229)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(8230)
				this->_t2 = this->_SF1->res();
				HX_STACK_LINE(8232)
				this->_res = this->_t2;
				HX_STACK_LINE(8233)
				this->_incomplete = false;
				HX_STACK_LINE(8234)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(8235)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(8237)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(8218)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Rune2Raw_obj,run,return )

Dynamic Go_haxegoruntime_Rune2Raw_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_Rune2Raw::res","tardis/Go.hx",8198);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8198)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Rune2Raw_obj,res,return )

::tardis::Slice Go_haxegoruntime_Rune2Raw_obj::callFromHaxe( int p_oneRune){
	HX_STACK_PUSH("Go_haxegoruntime_Rune2Raw::callFromHaxe","tardis/Go.hx",8204);
	HX_STACK_ARG(p_oneRune,"p_oneRune");
	HX_STACK_LINE(8205)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(8205)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(8206)
	::tardis::Go_haxegoruntime_Rune2Raw _sf = hx::TCast< ::tardis::Go_haxegoruntime_Rune2Raw >::cast(::tardis::Go_haxegoruntime_Rune2Raw_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_oneRune)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8207)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8207)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(8208)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_Rune2Raw_obj,callFromHaxe,return )

::tardis::Slice Go_haxegoruntime_Rune2Raw_obj::callFromRT( int _gr,int p_oneRune){
	HX_STACK_PUSH("Go_haxegoruntime_Rune2Raw::callFromRT","tardis/Go.hx",8210);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_oneRune,"p_oneRune");
	HX_STACK_LINE(8211)
	::tardis::Go_haxegoruntime_Rune2Raw _sf = hx::TCast< ::tardis::Go_haxegoruntime_Rune2Raw >::cast(::tardis::Go_haxegoruntime_Rune2Raw_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_oneRune)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8212)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8212)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(8212)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(8212)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(8212)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(8213)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_Rune2Raw_obj,callFromRT,return )

::tardis::Go_haxegoruntime_Rune2Raw Go_haxegoruntime_Rune2Raw_obj::call( int gr,Dynamic _bds,int p_oneRune){
	HX_STACK_PUSH("Go_haxegoruntime_Rune2Raw::call","tardis/Go.hx",8216);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_oneRune,"p_oneRune");
	HX_STACK_LINE(8216)
	return ::tardis::Go_haxegoruntime_Rune2Raw_obj::__new(gr,_bds,p_oneRune);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_Rune2Raw_obj,call,return )


Go_haxegoruntime_Rune2Raw_obj::Go_haxegoruntime_Rune2Raw_obj()
{
}

void Go_haxegoruntime_Rune2Raw_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_Rune2Raw);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_oneRune,"p_oneRune");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_Rune2Raw_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_oneRune,"p_oneRune");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_Rune2Raw_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t2") ) { return _t2; }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn0") ) { return SubFn0_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"p_oneRune") ) { return p_oneRune; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_Rune2Raw_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"p_oneRune") ) { p_oneRune=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_Rune2Raw_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_oneRune"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_t2"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_oneRune"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_Rune2Raw_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_Rune2Raw_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_Rune2Raw_obj::__mClass;

void Go_haxegoruntime_Rune2Raw_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_Rune2Raw"), hx::TCanCast< Go_haxegoruntime_Rune2Raw_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_Rune2Raw_obj::__boot()
{
}

} // end namespace tardis
