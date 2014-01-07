#ifndef INCLUDED_tardis_Go_haxegoruntime_FuncForPC
#define INCLUDED_tardis_Go_haxegoruntime_FuncForPC

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_FuncForPC)
HX_DECLARE_CLASS1(tardis,Interface)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_FuncForPC_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_FuncForPC_obj OBJ_;
		Go_haxegoruntime_FuncForPC_obj();
		Void __construct(int gr,Dynamic _bds,Dynamic p_pc);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_FuncForPC_obj > __new(int gr,Dynamic _bds,Dynamic p_pc);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_FuncForPC_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_FuncForPC_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_FuncForPC"); }

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		::tardis::Interface _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Pointer _res;
		Dynamic p_pc;
		static ::tardis::Pointer callFromHaxe( Dynamic p_pc);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Pointer callFromRT( int _gr,Dynamic p_pc);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_FuncForPC call( int gr,Dynamic _bds,Dynamic p_pc);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_FuncForPC */ 
