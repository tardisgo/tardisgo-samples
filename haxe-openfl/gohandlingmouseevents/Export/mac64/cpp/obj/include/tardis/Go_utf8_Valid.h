#ifndef INCLUDED_tardis_Go_utf8_Valid
#define INCLUDED_tardis_Go_utf8_Valid

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_Valid)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_Valid_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_Valid_obj OBJ_;
		Go_utf8_Valid_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_p);

	public:
		static hx::ObjectPtr< Go_utf8_Valid_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_Valid_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_Valid_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_Valid"); }

		virtual Void SubFn6( );
		Dynamic SubFn6_dyn();

		virtual Void SubFn5( );
		Dynamic SubFn5_dyn();

		virtual Void SubFn4( );
		Dynamic SubFn4_dyn();

		virtual Void SubFn3( );
		Dynamic SubFn3_dyn();

		virtual Void SubFn2( );
		Dynamic SubFn2_dyn();

		virtual Void SubFn1( );
		Dynamic SubFn1_dyn();

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		int _Phi;
		int _t12;
		bool _t11;
		int _t10;
		Dynamic _t8;
		::tardis::StackFrame _SF1;
		::tardis::Slice _t7;
		int _t6;
		bool _t5;
		int _t4;
		int _t3;
		bool _t2;
		int _t1;
		::tardis::Pointer _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		bool _res;
		::tardis::Slice p_p;
		static bool callFromHaxe( ::tardis::Slice p_p);
		static Dynamic callFromHaxe_dyn();

		static bool callFromRT( int _gr,::tardis::Slice p_p);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_Valid call( int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_Valid */ 
