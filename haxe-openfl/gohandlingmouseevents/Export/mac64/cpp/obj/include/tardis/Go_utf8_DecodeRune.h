#ifndef INCLUDED_tardis_Go_utf8_DecodeRune
#define INCLUDED_tardis_Go_utf8_DecodeRune

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_DecodeRune)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_DecodeRune_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_DecodeRune_obj OBJ_;
		Go_utf8_DecodeRune_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_p);

	public:
		static hx::ObjectPtr< Go_utf8_DecodeRune_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_DecodeRune_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_DecodeRune_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_DecodeRune"); }

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		int _t2;
		int _t1;
		Dynamic _t0;
		::tardis::StackFrame _SF1;
		virtual Dynamic res( );
		Dynamic res_dyn();

		Dynamic _res;
		::tardis::Slice p_p;
		static Dynamic callFromHaxe( ::tardis::Slice p_p);
		static Dynamic callFromHaxe_dyn();

		static Dynamic callFromRT( int _gr,::tardis::Slice p_p);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_DecodeRune call( int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_DecodeRune */ 