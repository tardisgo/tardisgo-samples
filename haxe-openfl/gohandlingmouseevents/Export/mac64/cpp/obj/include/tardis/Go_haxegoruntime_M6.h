#ifndef INCLUDED_tardis_Go_haxegoruntime_M6
#define INCLUDED_tardis_Go_haxegoruntime_M6

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_M6)
HX_DECLARE_CLASS1(tardis,Interface)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_M6_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_M6_obj OBJ_;
		Go_haxegoruntime_M6_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_M6_obj > __new(int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_M6_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_M6_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_M6"); }

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		::tardis::Interface _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Interface _res;
		::tardis::Interface p_a6;
		::tardis::Interface p_a5;
		::tardis::Interface p_a4;
		::tardis::Interface p_a3;
		::tardis::Interface p_a2;
		::tardis::Interface p_a1;
		::String p_meth;
		::String p_typ;
		::tardis::Interface p_rx;
		static ::tardis::Interface callFromHaxe( ::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Interface callFromRT( int _gr,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_M6 call( int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_M6 */ 
