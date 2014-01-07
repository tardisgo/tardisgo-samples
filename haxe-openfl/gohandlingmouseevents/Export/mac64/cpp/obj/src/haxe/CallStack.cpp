#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_CallStack
#include <haxe/CallStack.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
namespace haxe{

Void CallStack_obj::__construct()
{
	return null();
}

CallStack_obj::~CallStack_obj() { }

Dynamic CallStack_obj::__CreateEmpty() { return  new CallStack_obj; }
hx::ObjectPtr< CallStack_obj > CallStack_obj::__new()
{  hx::ObjectPtr< CallStack_obj > result = new CallStack_obj();
	result->__construct();
	return result;}

Dynamic CallStack_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CallStack_obj > result = new CallStack_obj();
	result->__construct();
	return result;}

Array< ::Dynamic > CallStack_obj::exceptionStack( ){
	Array< ::String > s = ::__hxcpp_get_exception_stack();
	return ::haxe::CallStack_obj::makeStack(s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(CallStack_obj,exceptionStack,return )

::String CallStack_obj::toString( Array< ::Dynamic > stack){
	HX_STACK_PUSH("CallStack::toString","/usr/lib/haxe/std/haxe/CallStack.hx",128);
	HX_STACK_ARG(stack,"stack");
	HX_STACK_LINE(129)
	::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(130)
	{
		HX_STACK_LINE(130)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(130)
		while(((_g < stack->length))){
			HX_STACK_LINE(130)
			::haxe::StackItem s = stack->__get(_g).StaticCast< ::haxe::StackItem >();		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(130)
			++(_g);
			HX_STACK_LINE(131)
			b->add(HX_CSTRING("\nCalled from "));
			HX_STACK_LINE(132)
			::haxe::CallStack_obj::itemToString(b,s);
		}
	}
	HX_STACK_LINE(134)
	return b->b->join(HX_CSTRING(""));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CallStack_obj,toString,return )

Void CallStack_obj::itemToString( ::StringBuf b,::haxe::StackItem s){
{
		HX_STACK_PUSH("CallStack::itemToString","/usr/lib/haxe/std/haxe/CallStack.hx",137);
		HX_STACK_ARG(b,"b");
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(137)
		{
			::haxe::StackItem _switch_1 = (s);
			switch((_switch_1)->GetIndex()){
				case 0: {
					HX_STACK_LINE(139)
					b->add(HX_CSTRING("a C function"));
				}
				;break;
				case 1: {
					::String m = _switch_1->__Param(0);
{
						HX_STACK_LINE(142)
						b->add(HX_CSTRING("module "));
						HX_STACK_LINE(143)
						b->add(m);
					}
				}
				;break;
				case 2: {
					int line = _switch_1->__Param(2);
					::String file = _switch_1->__Param(1);
					::haxe::StackItem s1 = _switch_1->__Param(0);
{
						HX_STACK_LINE(145)
						if (((s1 != null()))){
							HX_STACK_LINE(146)
							::haxe::CallStack_obj::itemToString(b,s1);
							HX_STACK_LINE(147)
							b->add(HX_CSTRING(" ("));
						}
						HX_STACK_LINE(149)
						b->add(file);
						HX_STACK_LINE(150)
						b->add(HX_CSTRING(" line "));
						HX_STACK_LINE(151)
						b->add(line);
						HX_STACK_LINE(152)
						if (((s1 != null()))){
							HX_STACK_LINE(152)
							b->add(HX_CSTRING(")"));
						}
					}
				}
				;break;
				case 3: {
					::String meth = _switch_1->__Param(1);
					::String cname = _switch_1->__Param(0);
{
						HX_STACK_LINE(154)
						b->add(cname);
						HX_STACK_LINE(155)
						b->add(HX_CSTRING("."));
						HX_STACK_LINE(156)
						b->add(meth);
					}
				}
				;break;
				case 4: {
					int n = _switch_1->__Param(0);
{
						HX_STACK_LINE(158)
						b->add(HX_CSTRING("local function #"));
						HX_STACK_LINE(159)
						b->add(n);
					}
				}
				;break;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CallStack_obj,itemToString,(void))

Array< ::Dynamic > CallStack_obj::makeStack( Array< ::String > s){
	Array< ::String > stack = s;
	Array< ::Dynamic > m = Array_obj< ::Dynamic >::__new();
	{
		int _g = (int)0;
		while(((_g < stack->length))){
			::String func = stack->__get(_g);
			++(_g);
			Array< ::String > words = func.split(HX_CSTRING("::"));
			if (((words->length == (int)0))){
				m->unshift(::haxe::StackItem_obj::CFunction);
			}
			else{
				if (((words->length == (int)2))){
					m->unshift(::haxe::StackItem_obj::Method(words->__get((int)0),words->__get((int)1)));
				}
				else{
					if (((words->length == (int)4))){
						m->unshift(::haxe::StackItem_obj::FilePos(::haxe::StackItem_obj::Method(words->__get((int)0),words->__get((int)1)),words->__get((int)2),::Std_obj::parseInt(words->__get((int)3))));
					}
				}
			}
		}
	}
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CallStack_obj,makeStack,return )


CallStack_obj::CallStack_obj()
{
}

void CallStack_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CallStack);
	HX_MARK_END_CLASS();
}

void CallStack_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic CallStack_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"makeStack") ) { return makeStack_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"itemToString") ) { return itemToString_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"exceptionStack") ) { return exceptionStack_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CallStack_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CallStack_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("exceptionStack"),
	HX_CSTRING("toString"),
	HX_CSTRING("itemToString"),
	HX_CSTRING("makeStack"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CallStack_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CallStack_obj::__mClass,"__mClass");
};

Class CallStack_obj::__mClass;

void CallStack_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.CallStack"), hx::TCanCast< CallStack_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CallStack_obj::__boot()
{
}

} // end namespace haxe
