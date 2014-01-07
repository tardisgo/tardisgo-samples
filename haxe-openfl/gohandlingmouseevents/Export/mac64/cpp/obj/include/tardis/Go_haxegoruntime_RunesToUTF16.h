#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF16
#define INCLUDED_tardis_Go_haxegoruntime_RunesToUTF16

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_RunesToUTF16)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_RunesToUTF16_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_RunesToUTF16_obj OBJ_;
		Go_haxegoruntime_RunesToUTF16_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_r);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_RunesToUTF16_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_r);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_RunesToUTF16_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_RunesToUTF16_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_RunesToUTF16"); }

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		::tardis::Slice _t0;
		::tardis::StackFrame _SF1;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Slice _res;
		::tardis::Slice p_r;
		static ::tardis::Slice callFromHaxe( ::tardis::Slice p_r);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Slice callFromRT( int _gr,::tardis::Slice p_r);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_RunesToUTF16 call( int gr,Dynamic _bds,::tardis::Slice p_r);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_RunesToUTF16 */ 
