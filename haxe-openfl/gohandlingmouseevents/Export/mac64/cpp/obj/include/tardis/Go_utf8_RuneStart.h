#ifndef INCLUDED_tardis_Go_utf8_RuneStart
#define INCLUDED_tardis_Go_utf8_RuneStart

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_RuneStart)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_RuneStart_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_RuneStart_obj OBJ_;
		Go_utf8_RuneStart_obj();
		Void __construct(int gr,Dynamic _bds,int p_b);

	public:
		static hx::ObjectPtr< Go_utf8_RuneStart_obj > __new(int gr,Dynamic _bds,int p_b);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_RuneStart_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_RuneStart_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_RuneStart"); }

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		bool _t1;
		int _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		bool _res;
		int p_b;
		static bool callFromHaxe( int p_b);
		static Dynamic callFromHaxe_dyn();

		static bool callFromRT( int _gr,int p_b);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_RuneStart call( int gr,Dynamic _bds,int p_b);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_RuneStart */ 
