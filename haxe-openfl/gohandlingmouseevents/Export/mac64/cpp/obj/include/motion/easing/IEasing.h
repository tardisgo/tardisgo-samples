#ifndef INCLUDED_motion_easing_IEasing
#define INCLUDED_motion_easing_IEasing

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(motion,easing,IEasing)
namespace motion{
namespace easing{


class HXCPP_CLASS_ATTRIBUTES  IEasing_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IEasing_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Float ease( Float t,Float b,Float c,Float d)=0;
		Dynamic ease_dyn();
virtual Float calculate( Float k)=0;
		Dynamic calculate_dyn();
};

#define DELEGATE_motion_easing_IEasing \
virtual Float ease( Float t,Float b,Float c,Float d) { return mDelegate->ease(t,b,c,d);}  \
virtual Dynamic ease_dyn() { return mDelegate->ease_dyn();}  \
virtual Float calculate( Float k) { return mDelegate->calculate(k);}  \
virtual Dynamic calculate_dyn() { return mDelegate->calculate_dyn();}  \


template<typename IMPL>
class IEasing_delegate_ : public IEasing_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IEasing_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_motion_easing_IEasing
};

} // end namespace motion
} // end namespace easing

#endif /* INCLUDED_motion_easing_IEasing */ 
