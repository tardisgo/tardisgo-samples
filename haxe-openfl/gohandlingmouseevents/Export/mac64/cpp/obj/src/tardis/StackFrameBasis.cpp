#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif
namespace tardis{

Void StackFrameBasis_obj::__construct(int gr,int ph,::String name)
{
HX_STACK_PUSH("StackFrameBasis::new","tardis/Go.hx",1203);
{
	HX_STACK_LINE(1207)
	this->_latestBlock = (int)0;
	HX_STACK_LINE(1206)
	this->_latestPH = (int)0;
	HX_STACK_LINE(1205)
	this->_incomplete = true;
	HX_STACK_LINE(1215)
	this->_goroutine = gr;
	HX_STACK_LINE(1216)
	this->_functionPH = ph;
	HX_STACK_LINE(1217)
	this->_functionName = name;
	HX_STACK_LINE(1218)
	this->_deferStack = ::List_obj::__new();
}
;
	return null();
}

StackFrameBasis_obj::~StackFrameBasis_obj() { }

Dynamic StackFrameBasis_obj::__CreateEmpty() { return  new StackFrameBasis_obj; }
hx::ObjectPtr< StackFrameBasis_obj > StackFrameBasis_obj::__new(int gr,int ph,::String name)
{  hx::ObjectPtr< StackFrameBasis_obj > result = new StackFrameBasis_obj();
	result->__construct(gr,ph,name);
	return result;}

Dynamic StackFrameBasis_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StackFrameBasis_obj > result = new StackFrameBasis_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void StackFrameBasis_obj::runDefers( ){
{
		HX_STACK_PUSH("StackFrameBasis::runDefers","tardis/Go.hx",1238);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1238)
		while((!(this->_deferStack->isEmpty()))){
			HX_STACK_LINE(1240)
			::tardis::Scheduler_obj::push(this->_goroutine,this->_deferStack->pop());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StackFrameBasis_obj,runDefers,(void))

Void StackFrameBasis_obj::defer( ::tardis::StackFrame fn){
{
		HX_STACK_PUSH("StackFrameBasis::defer","tardis/Go.hx",1233);
		HX_STACK_THIS(this);
		HX_STACK_ARG(fn,"fn");
		HX_STACK_LINE(1233)
		this->_deferStack->add(fn);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StackFrameBasis_obj,defer,(void))

Void StackFrameBasis_obj::setPH( int ph){
{
		HX_STACK_PUSH("StackFrameBasis::setPH","tardis/Go.hx",1228);
		HX_STACK_THIS(this);
		HX_STACK_ARG(ph,"ph");
		HX_STACK_LINE(1228)
		this->_latestPH = ph;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StackFrameBasis_obj,setPH,(void))

Void StackFrameBasis_obj::setLatest( int ph,int blk){
{
		HX_STACK_PUSH("StackFrameBasis::setLatest","tardis/Go.hx",1222);
		HX_STACK_THIS(this);
		HX_STACK_ARG(ph,"ph");
		HX_STACK_ARG(blk,"blk");
		HX_STACK_LINE(1223)
		this->_latestPH = ph;
		HX_STACK_LINE(1224)
		this->_latestBlock = blk;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StackFrameBasis_obj,setLatest,(void))


StackFrameBasis_obj::StackFrameBasis_obj()
{
}

void StackFrameBasis_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StackFrameBasis);
	HX_MARK_MEMBER_NAME(_deferStack,"_deferStack");
	HX_MARK_MEMBER_NAME(_bds,"_bds");
	HX_MARK_MEMBER_NAME(_goroutine,"_goroutine");
	HX_MARK_MEMBER_NAME(_functionName,"_functionName");
	HX_MARK_MEMBER_NAME(_functionPH,"_functionPH");
	HX_MARK_MEMBER_NAME(_latestBlock,"_latestBlock");
	HX_MARK_MEMBER_NAME(_latestPH,"_latestPH");
	HX_MARK_MEMBER_NAME(_incomplete,"_incomplete");
	HX_MARK_END_CLASS();
}

void StackFrameBasis_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_deferStack,"_deferStack");
	HX_VISIT_MEMBER_NAME(_bds,"_bds");
	HX_VISIT_MEMBER_NAME(_goroutine,"_goroutine");
	HX_VISIT_MEMBER_NAME(_functionName,"_functionName");
	HX_VISIT_MEMBER_NAME(_functionPH,"_functionPH");
	HX_VISIT_MEMBER_NAME(_latestBlock,"_latestBlock");
	HX_VISIT_MEMBER_NAME(_latestPH,"_latestPH");
	HX_VISIT_MEMBER_NAME(_incomplete,"_incomplete");
}

Dynamic StackFrameBasis_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_bds") ) { return _bds; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"defer") ) { return defer_dyn(); }
		if (HX_FIELD_EQ(inName,"setPH") ) { return setPH_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"runDefers") ) { return runDefers_dyn(); }
		if (HX_FIELD_EQ(inName,"setLatest") ) { return setLatest_dyn(); }
		if (HX_FIELD_EQ(inName,"_latestPH") ) { return _latestPH; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_goroutine") ) { return _goroutine; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_deferStack") ) { return _deferStack; }
		if (HX_FIELD_EQ(inName,"_functionPH") ) { return _functionPH; }
		if (HX_FIELD_EQ(inName,"_incomplete") ) { return _incomplete; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_latestBlock") ) { return _latestBlock; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_functionName") ) { return _functionName; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StackFrameBasis_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_bds") ) { _bds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_latestPH") ) { _latestPH=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_goroutine") ) { _goroutine=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_deferStack") ) { _deferStack=inValue.Cast< ::List >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_functionPH") ) { _functionPH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_incomplete") ) { _incomplete=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_latestBlock") ) { _latestBlock=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_functionName") ) { _functionName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StackFrameBasis_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_deferStack"));
	outFields->push(HX_CSTRING("_bds"));
	outFields->push(HX_CSTRING("_goroutine"));
	outFields->push(HX_CSTRING("_functionName"));
	outFields->push(HX_CSTRING("_functionPH"));
	outFields->push(HX_CSTRING("_latestBlock"));
	outFields->push(HX_CSTRING("_latestPH"));
	outFields->push(HX_CSTRING("_incomplete"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("runDefers"),
	HX_CSTRING("defer"),
	HX_CSTRING("setPH"),
	HX_CSTRING("setLatest"),
	HX_CSTRING("_deferStack"),
	HX_CSTRING("_bds"),
	HX_CSTRING("_goroutine"),
	HX_CSTRING("_functionName"),
	HX_CSTRING("_functionPH"),
	HX_CSTRING("_latestBlock"),
	HX_CSTRING("_latestPH"),
	HX_CSTRING("_incomplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StackFrameBasis_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StackFrameBasis_obj::__mClass,"__mClass");
};

Class StackFrameBasis_obj::__mClass;

void StackFrameBasis_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.StackFrameBasis"), hx::TCanCast< StackFrameBasis_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StackFrameBasis_obj::__boot()
{
}

} // end namespace tardis
