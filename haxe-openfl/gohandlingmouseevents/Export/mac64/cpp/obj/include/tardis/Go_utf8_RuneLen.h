#ifndef INCLUDED_tardis_Go_utf8_RuneLen
#define INCLUDED_tardis_Go_utf8_RuneLen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_RuneLen)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_RuneLen_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_RuneLen_obj OBJ_;
		Go_utf8_RuneLen_obj();
		Void __construct(int gr,Dynamic _bds,int p_r);

	public:
		static hx::ObjectPtr< Go_utf8_RuneLen_obj > __new(int gr,Dynamic _bds,int p_r);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_RuneLen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_RuneLen_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_RuneLen"); }

		virtual Void SubFn7( );
		Dynamic SubFn7_dyn();

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
		bool _t7;
		bool _t6;
		bool _t5;
		bool _t4;
		bool _t3;
		bool _t2;
		bool _t1;
		bool _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		int _res;
		int p_r;
		static int callFromHaxe( int p_r);
		static Dynamic callFromHaxe_dyn();

		static int callFromRT( int _gr,int p_r);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_RuneLen call( int gr,Dynamic _bds,int p_r);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_RuneLen */ 
