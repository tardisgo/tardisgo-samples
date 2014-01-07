#ifndef INCLUDED_tardis_Go_utf8_FullRuneInString
#define INCLUDED_tardis_Go_utf8_FullRuneInString

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_FullRuneInString)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_FullRuneInString_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_FullRuneInString_obj OBJ_;
		Go_utf8_FullRuneInString_obj();
		Void __construct(int gr,Dynamic _bds,::String p_s);

	public:
		static hx::ObjectPtr< Go_utf8_FullRuneInString_obj > __new(int gr,Dynamic _bds,::String p_s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_FullRuneInString_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_FullRuneInString_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_FullRuneInString"); }

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
		::String p_s;
		static bool callFromHaxe( ::String p_s);
		static Dynamic callFromHaxe_dyn();

		static bool callFromRT( int _gr,::String p_s);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_FullRuneInString call( int gr,Dynamic _bds,::String p_s);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_FullRuneInString */ 
