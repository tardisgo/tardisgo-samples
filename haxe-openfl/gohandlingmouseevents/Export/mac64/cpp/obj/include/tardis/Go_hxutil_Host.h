#ifndef INCLUDED_tardis_Go_hxutil_Host
#define INCLUDED_tardis_Go_hxutil_Host

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_hxutil_Host)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_hxutil_Host_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_hxutil_Host_obj OBJ_;
		Go_hxutil_Host_obj();
		Void __construct(int gr,Dynamic _bds);

	public:
		static hx::ObjectPtr< Go_hxutil_Host_obj > __new(int gr,Dynamic _bds);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_hxutil_Host_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_hxutil_Host_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_hxutil_Host"); }

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::String _res;
		static ::String callFromHaxe( );
		static Dynamic callFromHaxe_dyn();

		static ::String callFromRT( int _gr);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_hxutil_Host call( int gr,Dynamic _bds);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_hxutil_Host */ 
