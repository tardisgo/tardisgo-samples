#ifndef INCLUDED_tardis_Go_haxegoruntime_UTF16toRunes
#define INCLUDED_tardis_Go_haxegoruntime_UTF16toRunes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_UTF16toRunes)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_UTF16toRunes_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_UTF16toRunes_obj OBJ_;
		Go_haxegoruntime_UTF16toRunes_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_s);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_UTF16toRunes_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_UTF16toRunes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_UTF16toRunes_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_UTF16toRunes"); }

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		::tardis::Slice _t0;
		::tardis::StackFrame _SF1;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Slice _res;
		::tardis::Slice p_s;
		static ::tardis::Slice callFromHaxe( ::tardis::Slice p_s);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Slice callFromRT( int _gr,::tardis::Slice p_s);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_UTF16toRunes call( int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_UTF16toRunes */ 
