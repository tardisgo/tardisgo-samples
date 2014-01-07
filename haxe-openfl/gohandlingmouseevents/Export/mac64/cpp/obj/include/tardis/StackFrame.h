#ifndef INCLUDED_tardis_StackFrame
#define INCLUDED_tardis_StackFrame

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS1(tardis,StackFrame)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  StackFrame_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef StackFrame_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Dynamic res( )=0;
		Dynamic res_dyn();
virtual ::tardis::StackFrame run( )=0;
		Dynamic run_dyn();
};

#define DELEGATE_tardis_StackFrame \
virtual Dynamic res( ) { return mDelegate->res();}  \
virtual Dynamic res_dyn() { return mDelegate->res_dyn();}  \
virtual ::tardis::StackFrame run( ) { return mDelegate->run();}  \
virtual Dynamic run_dyn() { return mDelegate->run_dyn();}  \


template<typename IMPL>
class StackFrame_delegate_ : public StackFrame_obj
{
	protected:
		IMPL *mDelegate;
	public:
		StackFrame_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_tardis_StackFrame
};

} // end namespace tardis

#endif /* INCLUDED_tardis_StackFrame */ 
