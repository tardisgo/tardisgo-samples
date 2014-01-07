#include <hxcpp.h>

#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
namespace cpp{
namespace vm{

Void Thread_obj::__construct(Dynamic h)
{
HX_STACK_PUSH("Thread::new","/usr/lib/haxe/std/cpp/vm/Thread.hx",30);
{
	HX_STACK_LINE(30)
	this->handle = h;
}
;
	return null();
}

Thread_obj::~Thread_obj() { }

Dynamic Thread_obj::__CreateEmpty() { return  new Thread_obj; }
hx::ObjectPtr< Thread_obj > Thread_obj::__new(Dynamic h)
{  hx::ObjectPtr< Thread_obj > result = new Thread_obj();
	result->__construct(h);
	return result;}

Dynamic Thread_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Thread_obj > result = new Thread_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Thread_obj::sendMessage( Dynamic msg){
{
		HX_STACK_PUSH("Thread::sendMessage","/usr/lib/haxe/std/cpp/vm/Thread.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(msg,"msg");
		HX_STACK_LINE(37)
		::__hxcpp_thread_send(this->handle,msg);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,sendMessage,(void))

::cpp::vm::Thread Thread_obj::current( ){
	HX_STACK_PUSH("Thread::current","/usr/lib/haxe/std/cpp/vm/Thread.hx",45);
	HX_STACK_LINE(45)
	return ::cpp::vm::Thread_obj::__new(::__hxcpp_thread_current());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Thread_obj,current,return )

::cpp::vm::Thread Thread_obj::create( Dynamic callb){
	HX_STACK_PUSH("Thread::create","/usr/lib/haxe/std/cpp/vm/Thread.hx",52);
	HX_STACK_ARG(callb,"callb");
	HX_STACK_LINE(52)
	return ::cpp::vm::Thread_obj::__new(::__hxcpp_thread_create(callb));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,create,return )

Dynamic Thread_obj::readMessage( bool block){
	HX_STACK_PUSH("Thread::readMessage","/usr/lib/haxe/std/cpp/vm/Thread.hx",61);
	HX_STACK_ARG(block,"block");
	HX_STACK_LINE(61)
	return ::__hxcpp_thread_read_message(block);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,readMessage,return )


Thread_obj::Thread_obj()
{
}

void Thread_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Thread);
	HX_MARK_MEMBER_NAME(handle,"handle");
	HX_MARK_END_CLASS();
}

void Thread_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(handle,"handle");
}

Dynamic Thread_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"handle") ) { return handle; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return current_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"readMessage") ) { return readMessage_dyn(); }
		if (HX_FIELD_EQ(inName,"sendMessage") ) { return sendMessage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Thread_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"handle") ) { handle=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Thread_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("handle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("current"),
	HX_CSTRING("create"),
	HX_CSTRING("readMessage"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sendMessage"),
	HX_CSTRING("handle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Thread_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Thread_obj::__mClass,"__mClass");
};

Class Thread_obj::__mClass;

void Thread_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.vm.Thread"), hx::TCanCast< Thread_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Thread_obj::__boot()
{
}

} // end namespace cpp
} // end namespace vm
