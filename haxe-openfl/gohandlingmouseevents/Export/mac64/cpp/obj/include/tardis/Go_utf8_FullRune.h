#ifndef INCLUDED_tardis_Go_utf8_FullRune
#define INCLUDED_tardis_Go_utf8_FullRune

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_FullRune)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_FullRune_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_FullRune_obj OBJ_;
		Go_utf8_FullRune_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_p);

	public:
		static hx::ObjectPtr< Go_utf8_FullRune_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_FullRune_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_FullRune_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_FullRune"); }

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		bool _t4;
		bool _t3;
		Dynamic _t0;
		::tardis::StackFrame _SF1;
		virtual Dynamic res( );
		Dynamic res_dyn();

		bool _res;
		::tardis::Slice p_p;
		static bool callFromHaxe( ::tardis::Slice p_p);
		static Dynamic callFromHaxe_dyn();

		static bool callFromRT( int _gr,::tardis::Slice p_p);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_FullRune call( int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_FullRune */ 
